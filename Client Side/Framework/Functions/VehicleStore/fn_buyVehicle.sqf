/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_buyVehicle";

if (canSuspend) exitWith {
    [ULP_fnc_buyVehicle, _this] call ULP_fnc_directCall;
};

_this params [
	"_button"
];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

private _texList = _display displayCtrl 3408;

private _vehInfo = _display getVariable ["selected", []];
if (_vehInfo isEqualTo []) exitWith {};

_vehInfo params [
	"", "_missionCfg", "_picture", "_name"
];

private _buyPrice = getNumber(_missionCfg >> "buyPrice");
private _plate = false;
private _texture = _texList lbData (lbCurSel _texList);

private _spawns = _display getVariable ["spawns", []];

_spawns = _spawns apply {
	if (_x isEqualType []) exitWith { [_x] };
	[markerPos _x, markerDir _x]
};

private _spawn = {
	if (((_x select 0) nearEntities [["Car", "Ship", "Air"], 8]) isEqualTo []) exitWith { _x };
} forEach _spawns;

if (isNil "_spawn") exitWith {
	hint "There are no available spawn points...";
};

if ([_buyPrice, false, format ["Purchased %1", _name]] call ULP_fnc_removeMoney) exitWith {
	private _faction = [player] call ULP_fnc_getFaction;

	if ([_faction, "vehicles"] call ULP_fnc_factionPresistant) then {
		["VehicleBought", {
			_this params [
				["_params", [], [[]]],
				["_limitReached", false, [true]],
				["_price", 0, [0]],
				["_limit", 0, [0]]
			];

			if (_limitReached) exitWith {
				([_params select 0] call ULP_fnc_vehicleCfg) params [
					"", "", "", ["_name", "Unknown", [""]], "", "", "", "", ""
				];

				hint ([
					format ["Your purchase was unable to be made as you've reached the max garagable limit for %1 of %2", _name, [_limit] call ULP_fnc_numberText],
					format ["You've been refunded %1%2 for %3 as you've reached the max garagable limit of %4...", 
						"£", 
						[_price] call ULP_fnc_numberText, 
						_name, 
						[_limit] call ULP_fnc_numberText
					]
				] select (_price > 0));
			};

			_params call ULP_fnc_createVehicle;
		}, true] call ULP_fnc_addEventHandler;

		[_buyPrice, getPlayerUID player, profileName, _faction, configName _missionCfg, _spawn, _texture] remoteExecCall ["ULP_SRV_fnc_createVehicle", RSERV];
	} else {
		[configName _missionCfg, _spawn, _texture] call ULP_fnc_createVehicle;
	};

	["BuyVehicle"] call ULP_fnc_achieve;
	closeDialog 0;
};

hint format["You can't afford to pay for this vehicle. You need £%1.", [_buyPrice] call ULP_fnc_numberText];