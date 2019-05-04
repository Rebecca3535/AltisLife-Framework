/*
	@File: fn_administerBlood.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Administers blood...
*/
#include "..\..\script_macros.hpp"
if !(params [["_unit", objNull, [objNull]]]) exitWith {};

if (isNull _unit) exitWith {};
if !(isDowned(_unit)) exitWith { hint "You can only administer blood to injured players..." };
if (player distance _unit > 5) exitWith { hint "You are not close enough to the injured player..." };
if (dialog) then { closeDialog 0 };

life_interrupted = false;
life_action_inUse = true;

//Setup our progress bar.
disableSerialization;

"progressBar" cutRsc ["life_progress","PLAIN"];
private _ui = uiNamespace getVariable "life_progress";
private _progress = _ui displayCtrl 38201;
private _pgText = _ui displayCtrl 38202;
private _upp = format ["Administering Blood to %1...", _unit getVariable ["realname", name _unit]];
_pgText ctrlSetText format ["%2 (1%1)...","%",_upp];
_progress progressSetPosition 0.01;
private _cP = 0.01;
private _badDistance = false;

for "_i" from 0 to 1 step 0 do {
	if (animationState player != "AinvPknlMstpSnonWnonDnon_medic_1") then {
		[player,"AinvPknlMstpSnonWnonDnon_medic_1",true] remoteExecCall ["life_fnc_animSync",RCLIENT];
		player switchMove "AinvPknlMstpSnonWnonDnon_medic_1";
		player playMoveNow "AinvPknlMstpSnonWnonDnon_medic_1";
	};

	uiSleep 0.27;

	_cP = _cP + 0.01;
	_progress progressSetPosition _cP;
	_pgText ctrlSetText format ["%3 (%1%2)...",round(_cP * 100),"%",_upp];

	if (_cP >= 1) exitWith {};
	
	// Checks...
	if (!alive player || isDowned(player) || !alive _unit || !(isDowned(_unit))) exitWith {};
	if (life_istazed || life_isknocked || (player getVariable ["restrained",false])) exitWith {};
	if (player getVariable ["restrained",false]) exitWith {};
	if (player distance _unit > 5) exitWith { _badDistance = true };
	if !(isNull objectParent player) exitWith {};
	if (life_interrupted) exitWith {};
};

"progressBar" cutText ["","PLAIN"];
player playActionNow "stop";
if (!alive player || isDowned(player) || !alive _unit || !(isDowned(_unit)) || life_istazed || life_isknocked) exitWith {life_action_inUse = false;};
if (life_interrupted || (player getVariable ["restrained",false])) exitWith {life_interrupted = false; titleText["Action Cancelled.","PLAIN"]; life_action_inUse = false;};
if (_badDistance) exitWith {titleText["You must remain within 5m to revive someone...","PLAIN"]; life_action_inUse = false;};
if !(isNull objectParent player) exitWith {titleText["You can't revive someone while inside a vehicle...","PLAIN"]; life_action_inUse = false;};

[false,"blood_bag",1] call LIFE(handleInv); // Take the blood bag...
life_action_inUse = false;

hint format["You've administered blood to %1", (_unit getVariable ["realname", name _unit])];

[player] remoteExecCall ["FF_fnc_bloodAdministered", _unit]; // Tell the injured person they've recieved some blood...