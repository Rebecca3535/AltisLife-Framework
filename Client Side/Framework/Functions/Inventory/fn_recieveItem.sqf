/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_recieveItem";

_this params [
	["_unit", objNull, [objNull]],
	["_item", "", [""]],
	["_data", 1, [0, "", []]],
	["_return", false, [true]]
];

private _itemCfg = missionConfigFile >> "CfgVirtualItems" >> _item;
if (isNull _unit || { !(isClass _itemCfg) }) exitWith { false };

private _count = _data;
if !(_data isEqualType 0) then {
	_count = 1;
};

if (_count <= 0) exitWith { false };

if ([_item, _data, false, _return] call ULP_fnc_handleItem) exitWith {
	private _displayName = getText (_itemCfg >> "displayName");

	if ([getNumber (_itemCfg >> "Settings" >> "isScripted")] call ULP_fnc_bool) then {
		_displayName = format [_displayName, _data];
	};

	private _hint = format ["%1 has given you %2 %3s", [_unit, true] call ULP_fnc_getName, [_count] call ULP_fnc_numberText, _displayName];

	if (_return) then {
		_hint = format ["%1 has returned %2 %3s because they couldn't carry it", [_unit, true] call ULP_fnc_getName, [_count] call ULP_fnc_numberText, _displayName];
	};

	[_hint] call ULP_fnc_hint;
	true
};

// We couldn't carry it
[player, _item, _data, true] remoteExecCall ["ULP_fnc_recieveItem", _unit];
false