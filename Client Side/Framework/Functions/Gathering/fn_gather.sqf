/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_gather";

_this params [
	["_zone", configNull, [configNull]]
];

if (isNull _zone || { !([player] call ULP_fnc_getFaction in getArray (_zone >> "factions")) }) exitWith { false };

private _reqItems = getArray (_zone >> "reqItems");
{
	if ([_x] call ULP_fnc_hasItem isEqualTo -1) exitWith {
		hint format["This zone requires these items to gather: %1...", _reqItems];
		false breakOut "fn_gather";
	};

	nil
} count _reqItems;

private _reqLicenses = getArray (_zone >> "reqLicenses");
{
	if !([_x] call ULP_fnc_hasLicense) exitWith {
		hint format["You need these licenses to gather here: %1...", _reqLicenses];
		false breakOut "fn_gather";
	};

	nil
} count _reqLicenses;

private _resources = getArray (_zone >> "items");
if (_resources isEqualTo []) exitWith { false };

private _items = _resources apply { _x select 0 };
private _weights = _resources apply { (_x select 1) / 100 };

private _item = missionConfigFile >> "CfgVirtualItems" >> (_items selectRandomWeighted _weights);
if !(isClass _item) exitWith {};

ULP_CarryInfo params ["_carryWeight", "_maxWeight"];

private _total = floor ((_maxWeight - _carryWeight) / getNumber(_item >> "weight"));
if (_total isEqualTo 0) exitWith {
	hint "Your inventory is full";
	false
};

private _title = ["Gathering", getText (_zone >> "actionTitle")] select (isText (_zone >> "actionTitle"));

[format["%1 %2(s)", _title, getText(_item >> "displayName")], getNumber(_zone >> "gatherTime") * _total, [_item, _total], { true }, {
	_this params [ "_item", "_total" ];

	[configName _item, _total] call ULP_fnc_handleItem;

	hint format["You've gathered %1 %2(s)", _total, getText(_item >> "displayName")];
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;

true