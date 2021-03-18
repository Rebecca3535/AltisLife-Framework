/*
** Author: Jack "Scarso" Farhall
** Description: Sends our target unit to prison...
*/
#include "..\..\script_macros.hpp"
scopeName "fn_imprison";

if (canSuspend) exitWith {
    [ULP_fnc_imprison, _this] call ULP_fnc_directCall;
};

_this params [
	["_unit", player, [objNull]],
	["_duraction", 5 * 60, [0]],
	["_arrester", objNull, [objNull]],
	["_update", true, [false]]
];

if (isNull _unit || { !(isPlayer _unit) } || { !([_unit] call ULP_fnc_canImprisoned) } || { _duraction <= 0 }) exitWith { false };
if !(local _unit) exitWith { _this remoteExecCall ["ULP_fnc_imprison", _unit]; false; };

private _prison = missionConfigFile >> "CfgPrison" >> worldName;
if !(isClass _prison) exitWith { false };

if (_duraction > getNumber (_prison >> "maxDuraction")) exitWith { false };

private _pos = getMarkerPos getText (_prison >> "marker");

_unit setPos _pos;
[_prison >> "PrisonLoadout"] call ULP_fnc_setCfgLoadout;

ULP_Imprisioned = true;
ULP_Prison_Time = time + _duraction;

["Convict"] call ULP_fnc_achieve;

["RscFiringDrillTime", "PLAIN", 3] call ULP_UI_fnc_createLayer;

// Recolour...
private _display = ["RscFiringDrillTime"] call ULP_UI_fnc_getLayer;
(_display displayCtrl 1100) ctrlSetBackgroundColor [0.1,0.1,0.1,0.85];

uiNamespace setVariable ["prison_timer", [[_unit, _pos], {
	_this params ["_unit", "_pos"];
	
	private _timeLeft = ULP_Prison_Time - time;
	missionNamespace setVariable["RscFiringDrillTime_current", parseText format["<img image='A3\Modules_F_Beta\data\FiringDrills\timer_ca'/> %1", [_timeLeft, "MM:SS"] call BIS_fnc_secondsToString]];
	
	if ((_unit distance _pos) > 100) then { [_unit, true] call ULP_fnc_release; };
	if (_timeLeft <= 0) then { [_unit] call ULP_fnc_release; };
}] call ULP_fnc_addEachFrame];

if (_update) then {
	[_unit, 7, _duraction] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];
};

if !(isNull _arrester) then {
	hint format["You've been arrested for %1 by %2", [_duration, "MM:SS"] call BIS_fnc_secondsToString, name _arrester];
};

true