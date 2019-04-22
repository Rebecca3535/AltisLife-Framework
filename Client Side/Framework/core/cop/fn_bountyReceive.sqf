#include "..\..\script_macros.hpp"
/*
    File: fn_bountyReceive.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Notifies the player he has received a bounty and gives him the cash.
*/
private ["_val","_total"];
_val = [_this,0,"",["",0]] call BIS_fnc_param;
_total = [_this,1,"",["",0]] call BIS_fnc_param;

if (_val == _total) then {
    titleText[format ["You have collected a bounty of £%1 for arresting a criminal.",[_val] call life_fnc_numberText],"PLAIN"];
} else {
    titleText[format [localize "You have collected a bounty of £%1 for killing a wanted criminal.",[_val] call life_fnc_numberText,[_total] call life_fnc_numberText],"PLAIN"];
};

BANK = BANK + _val;
[1] call SOCK_fnc_updatePartial;