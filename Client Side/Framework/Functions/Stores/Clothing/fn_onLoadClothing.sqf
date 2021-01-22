/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onLoadClothing";

_this params [
	["_display", displayNull, [displayNull]]
];

if (isNull _display) exitWith {};

private _toolBox = _display displayCtrl 3102;
[_toolBox, 0] call ULP_fnc_switchCategory;
_toolBox ctrlSetEventHandler ["ToolboxSelChanged", "_this call ULP_fnc_switchCategory"];

(_display displayCtrl 3105) ctrlSetStructuredText parseText "<t size='0.8'>Select and start adding items to your cart to begin...</t>";

// Item Actions...
(_display displayCtrl 3103) ctrlSetEventHandler ["LBSelChanged", "_this call ULP_fnc_onItemClick"];
(_display displayCtrl 3106) ctrlSetEventHandler ["LBSelChanged", "_this call ULP_fnc_onTextureSwitch"];