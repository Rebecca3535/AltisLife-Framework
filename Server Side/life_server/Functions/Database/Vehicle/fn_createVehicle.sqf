/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_createVehicle";

_this params [
	["_steamid", "", [""]],
	["_name", "", [""]],
	["_faction", "", [""]],
	["_class", "", [""]],
	["_spawn", [[0, 0, 0], 0], [[]]],
	["_texture", "", [""]]
];

if (_steamid isEqualTo "" || { _name isEqualTo "" } || { !(isClass (missionConfigFile >> "CfgFactions" >> _faction))}) exitWith {};

(_class call BIS_fnc_objectType) params ["", "_type"];

// Get ID...
private _query = [format["SELECT MAX(id) FROM vehicles"], 2] call DB_fnc_asyncCall;

if (_query isEqualTo "" || { _query isEqualTo [] }) exitWith {
	// TODO...
};

// Insert...
[format[
	"INSERT INTO vehicles (pid, faction, classname, type, texture) VALUES ('%1', '%2', '%3', '%4', '%5');", 
	_steamid, _faction, _class, _type, _texture
], 1] call DB_fnc_asyncCall;

_query params [
	"_id"
];

_id = _id + 1;

[_class, _spawn, _texture, _id] remoteExecCall ["ULP_fnc_createVehicle", remoteExecutedOwner];