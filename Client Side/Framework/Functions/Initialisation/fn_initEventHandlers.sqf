/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_initEventHandlers";

player addEventHandler ["Fired", { _this call ULP_fnc_onFired }];
player addEventHandler ["Reloaded", { _this call ULP_fnc_onReloaded }];
player addEventHandler ["GetInMan", { _this call ULP_fnc_onGetIn }];
player addEventHandler ["GetOutMan", { _this call ULP_fnc_onGetOut }];
player addEventHandler ["Take", { _this call ULP_fnc_onTake }];
player addEventHandler ["Put", { _this call ULP_fnc_onPut }];
player addEventHandler ["InventoryOpened", { _this call ULP_fnc_InventoryOpened }];

["KeysGiven", {
	_this params [
		["_vehicle", objNull, [objNull]],
		["_giver", objNull, [objNull]]
	];

	if (isNull _vehicle) exitWith {};

	if (((ULP_Keys pushBackUnique _vehicle) > -1) && { !(isNull _giver) }) then {
		[format ["%1 has given you keys to %2...", name _giver, ([typeOf _vehicle] call ULP_fnc_vehicleCfg) param [3, "something"]]] call ULP_fnc_hint;
	};
}] call ULP_fnc_addEventHandler;

["HouseAdded", {
	_this params [
		["_house", objNull, [objNull]]
	];

	ULP_Houses pushBackUnique _house;
	
	private _name = _house getVariable ["building_name", ""];
	
	private _marker = createMarkerLocal [format["house_%1", _house call BIS_fnc_netId], position _house];
	_marker setMarkerTypeLocal "loc_Lighthouse";
	_marker setMarkerColorLocal (["ColorIndependent", "colorBLUFOR"] select ([_house, player, false] call ULP_fnc_isHouseOwner));

	if !(_name isEqualTo "") then {
		_marker setMarkerTextLocal _name;
	};

	_house setVariable ["building_marker", _marker];
}] call ULP_fnc_addEventHandler;

["HouseRemoved", {
	_this params [
		["_house", objNull, [objNull]]
	];

	if (_house in ULP_Houses) then { ULP_Houses deleteAt (ULP_Houses find _house); };
	
	private _marker = _house getVariable ["building_marker", ""];
	if !(_marker isEqualTo "") then {
		deleteMarkerLocal _marker;
	};
}] call ULP_fnc_addEventHandler;

["HouseRenamed", {
	_this params [
		["_house", objNull, [objNull]]
	];

	private _marker = _house getVariable ["building_marker", ""];
	if !(_marker isEqualTo "") then {
		private _name = _house getVariable ["building_name", ""];

		if !(_name isEqualTo (markerText _marker)) then {
			_marker setMarkerTextLocal _name;
		};
	};
}] call ULP_fnc_addEventHandler;

// Settings Events...
["OptionChanged", {
	_this params [
		"_option", "_category", "_newSetting", "_lastSetting"
	];

	switch (format["%1_%2", _category, _option]) do {
		case "General_NightLight": { if (hasInterface && { !(isNil "ULP_NightLight") }) then { ULP_NightLight setLightBrightness _newSetting; }; };
		case "HUD_SideChat": { 1 enableChannel ([_newSetting] call ULP_fnc_bool); };
		case "HUD_EnableHUD": {
			if (_newSetting isEqualTo 1) then {
				[] call ULP_UI_fnc_openHUD;
			} else {
				[(["RscHUD"] call ULP_UI_fnc_getLayer)] call ULP_UI_fnc_closeHUD;
			};
		};
		case "HUD_EnableXPBar": { [(_newSetting isEqualTo 1)] call ULP_UI_fnc_updateXpHud; };
		case "HUD_EnablePlayerTags": { [(_newSetting isEqualTo 1)] call ULP_fnc_playerTags };
		case "Indicators_EnableIndicators": { [(_newSetting isEqualTo 1)] call ULP_fnc_playerTags };
		case "Audio_EffectsFade": { if (ULP_FadeSound) then { 0 fadeSound _newSetting; }; };
		case "Audio_MusicFade": { if (ULP_FadeSound) then { 0 fadeMusic _newSetting; }; };
	};
}] call ULP_fnc_addEventHandler;

if ([player, ["Police", "Hato"]] call ULP_fnc_isFaction) then {
	["ClampFinePaid", {
		_this params [
			["_payer", "", [""]],
			["_vehicle", objNull, [objNull]],
			["_fine", 1, [0]]
		];

		private _cut = round (_fine / 2);

		if ([_cut, true, format["Vehicle Fine Paid"]] call ULP_fnc_addMoney) then {
			[
				format [
					"%1 has paid their fine for %2 of %3%4 and you've recieved %3%5 as a reward...",
					_payer,
					([typeOf _vehicle] call ULP_fnc_vehicleCfg) param [3, ""],
					"£", [_fine] call ULP_fnc_numberText, [_cut] call ULP_fnc_numberText
				]
			] call ULP_fnc_hint;
		};
	}] call ULP_fnc_addEventHandler;
};

["Blindfold", {
	_this params [
		["_unit", objNull, [objNull]]
	];

	if (isNull _unit) exitWith {};
	
	if (player getVariable ["blindfold", false]) then {
		cutText ["","BLACK IN"];
  		[format ["%1 has removed your blindfold...", [_unit] call ULP_fnc_getName]] call ULP_fnc_hint;
	} else {
		cutText ["","BLACK OUT"];
  		[format ["%1 has put a blindfold over your head...", [_unit] call ULP_fnc_getName]] call ULP_fnc_hint;
	};
}] call ULP_fnc_addEventHandler;