/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_administerBlood";

_this params [
	["_unit", objNull, [objNull]]
];

if (isNull _unit || { !(alive _unit) }) exitWith {};

if ((0 max (["BloodBag"] call ULP_fnc_hasItem)) < 1) exitWith { hint "You need a bloodbag to administer blood..."; };
if !(isDowned(_unit)) exitWith { hint "You can only administer blood to injured players"; };

private _name = [_unit] call ULP_fnc_getName;

private _time = 40;

if !([format["Administering Blood to %1", _name], _time, [_unit, _name], {
	!(isNull (_this select 0)) && { alive (_this select 0) } && { isDowned((_this select 0)) } && { (0 max (["BloodBag"] call ULP_fnc_hasItem)) > 0 } && 
	{ (player distance (_this select 0)) <= 5 }
}, {
	_this params [ "_unit", "_name" ];

	if (isNull _unit || { !(alive _unit) } || { !(isDowned(_unit)) } || { (0 max (["BloodBag"] call ULP_fnc_hasItem)) < 1 }) exitWith {
		hint "You either lost your bloodbag or the patient you were treating has died...";
	};

	["BloodBag", 1, true] call ULP_fnc_handleItem;
	hint format ["You have administered blood into %1", _name];

	[player] remoteExecCall ["ULP_fnc_receivedBlood", _unit];
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress) exitWith {
	hint "You can't administer blood while performing another action...";
};

closeDialog 0;