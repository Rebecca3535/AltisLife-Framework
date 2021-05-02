/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_revived";

if (canSuspend) exitWith {
    [ULP_fnc_revived, _this] call ULP_fnc_directCall;
};

if !(_this params [
	["_medic", objNull, [objNull]]
]) exitWith {};

if ([_medic] call ULP_fnc_onDuty) then {
	["You were revied by an admin..."] call ULP_fnc_hint;
} else {
	[format ["You have been revived by %1", [_medic] call ULP_fnc_getName]] call ULP_fnc_hint;
};

player setVariable ["IncapacitatedWounds", nil, true];

player setUnconscious false;
unsetKiller(player);
unsetDowned(player);

player playMoveNow "amovppnemstpsraswrfldnon";

["RscIncapacitated"] call ULP_UI_fnc_destroyLayer;
uiNamespace setVariable ["IncapacitatedEffect", nil];
[] call ULP_fnc_wipeEffects;

ULP_Respawned = false;
ULP_CanRespawn = nil;

[] call ULP_fnc_syncPlayerInfo;