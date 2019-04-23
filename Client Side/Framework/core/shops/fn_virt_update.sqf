#include "..\..\script_macros.hpp"
/*
    File: fn_virt_update.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Update and fill the virtual shop menu.
*/
private ["_item_list","_gear_list","_shopItems","_name","_price"];
disableSerialization;

//Setup control vars.
_item_list = CONTROL(2400,2401);
_gear_list = CONTROL(2400,2402);

//Purge list
lbClear _item_list;
lbClear _gear_list;

if (!isClass(missionConfigFile >> "CfgShops" >> life_shop_type)) exitWith {closeDialog 0; hint "Config does not exist?";}; //Make sure the entry exists..
ctrlSetText[2403, (M_CONFIG(getText,"CfgShops",life_shop_type,"name"))];
_shopItems = M_CONFIG(getArray,"CfgShops",life_shop_type,"items");

{
    _displayName = M_CONFIG(getText,"CfgItems",_x,"displayName");
    _price = M_CONFIG(getNumber,"CfgItems",_x,"buyPrice");
    if (!(_price isEqualTo -1)) then {
        _item_list lbAdd format ["%1  (£%2)",_displayName,[_price] call life_fnc_numberText];
        _item_list lbSetData [(lbSize _item_list)-1,_x];
        _item_list lbSetValue [(lbSize _item_list)-1,_price];
        _icon = ICON(M_CONFIG(getText,"CfgItems",_x,"icon"));
        if (!(_icon isEqualTo "")) then {
            _item_list lbSetPicture [(lbSize _item_list)-1,_icon];
        };
    };
} forEach _shopItems;

{
    _name = M_CONFIG(getText,"CfgItems",_x,"displayName");
    _val = ITEM_VALUE(_x);

    if (_val > 0) then {
        _gear_list lbAdd format ["%2 [x%1]",_val,_name];
        _gear_list lbSetData [(lbSize _gear_list)-1,_x];
        _icon = ICON(M_CONFIG(getText,"CfgItems",_x,"icon"));
        if (!(_icon isEqualTo "")) then {
            _gear_list lbSetPicture [(lbSize _gear_list)-1,_icon];
        };
    };
} forEach _shopItems;
