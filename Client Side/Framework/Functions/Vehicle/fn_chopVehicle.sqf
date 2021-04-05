/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_chopVehicle";

if (canSuspend) exitWith {
    [ULP_fnc_chopVehicle, _this] call ULP_fnc_directCall;
};

_this params [
	["_trader", player, [objNull]],
	["_payMore", false, [true]],
	["_allowKeep", false, [true]]
];

private _near = ((_trader nearEntities [["Car", "Air", "Ship"], 15]) select {
	!([_x] call ULP_fnc_getVehicleOwner isEqualTo "") &&
	{ [player, _x] call ULP_fnc_isVehicleOwner })
});

if (_near isEqualTo []) exitWith {
	hint "There are no vehicles nearby to chop...";
};

[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), (_near apply { 
 ([typeOf _x] call ULP_fnc_vehicleCfg) params [  "", "", "_picture", "_name" ]; 
 [_picture, _name, _x call BIS_fnc_netId, 0];
}), ["Chop", "Cancel"], [_trader, _payMore, _allowKeep], {
	_this params [
		["_trader", player, [objNull]],
		["_payMore", false, [true]],
		["_allowKeep", false, [true]],
		["_display", displayNull, [displayNull]]
	];

	if (isNull _display) exitWith {};
	private _list = _display displayCtrl 4509;

	private _vehicle = (_list lbData (lbCurSel _list)) call BIS_fnc_objectFromNetId;
	if (isNull _vehicle) exitWith { hint "You didn't select a vehicle to chop..."; };

	private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
	if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith {};

	_cfg params [
		"", "_missionCfg", "_picture", "_name"
	];

	if !(isClass _missionCfg) exitWith {};

	private _time = getNumber (missionConfigFile >> "CfgVehicles" >> "chopTime");
	if (isNumber (_missionCfg >> "chopTime")) then {
		_time = _time + getNumber (_missionCfg >> "chopTime");
	};

	if !([format["Chopping %1", _name], _time, [_vehicle, _missionCfg, _name, _payMore, _allowKeep], {
		!(isNull (_this select 0)) && { alive (_this select 0) } && { (player distance (_this select 0)) <= 5 }
	}, {
		scopeName "_fnc_onChopped";
		_this params [ "_vehicle", "_cfg", "_name", "_payMore", "_allowKeep" ];

		if (isNull _vehicle || { !(alive _vehicle) }) exitWith {
			hint format["You failed to chop the %1 as it's been destroyed..."];
		};

		private _chopValue = getNumber (_cfg >> "buyPrice") * ([
			getNumber (missionConfigFile >> "CfgVehicles" >> "chopPerc"),
			getNumber (_cfg >> "chopPerc")
		] select (isNumber (_cfg >> "chopPerc")));

		if (_payMore) then {
			_chopValue = _chopValue * 1.1;
		};

		private _id = _vehicle getVariable ["vehicle_id", -1];
		private _owner = [_vehicle] call ULP_fnc_getVehicleOwner;
		deleteVehicle _vehicle;

		if (_id >= 0) then {
			if (_allowKeep && { [[player] call ULP_fnc_getFaction, "vehicles"] call ULP_fnc_factionPresistant }) then {
				private _chance = ([
					getNumber (missionConfigFile >> "CfgVehicles" >> "chopKeepChance"),
					getNumber (_cfg >> "chopKeepChance")
				] select (isNumber (_cfg >> "chopKeepChance")));
				
				if ((["UncertainPersonality", 0] call ULP_fnc_activatePerk) > _chance) then {
					[_owner, player, _id] remoteExecCall ["ULP_SRV_fnc_transferVehicle", RSERV];
					hint format["You've claimed %1 as your own vehicle, it is now in your garage.", _name];
					breakOut "_fnc_onChopped";
				};
			};

			[_id] remoteExecCall ["ULP_SRV_fnc_destroyVehicle", RSERV];
		};

		[_chopValue, false, format["Chopped %1", _name]] call ULP_fnc_addMoney;
		hint format["You've chopped %1 for %2%3", _name, "£", [_chopValue] call ULP_fnc_numberText];
	}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress) exitWith {
		hint "You can't chop a vehicle while performing another action...";
	};
}, false] call ULP_fnc_selectObject;