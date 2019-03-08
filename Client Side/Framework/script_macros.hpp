/* System Wide Stuff */
#define SYSTEM_TAG "life"
#define ITEM_TAG format ["%1%2",SYSTEM_TAG,"item_"]
#define CASH life_cash
#define BANK life_atmbank
#define GANG_FUNDS group player getVariable ["gang_bank",0];

// Functions
#define LIFE(func) life_fnc_##func // Life Functions...
#define DB(func) SOCK_fnc_##func // Session Functions..
#define SPY(func) SPY_fnc_##func // Spyglass Functions..
#define FF(func) FF_fnc_##func // Custom "FreeFlight" Functions..

//RemoteExec Macros
#define RSERV 2 //Only server
#define RCLIENT -2 //Except server
#define RANY 0 //Global

// Directories
#define ICON(file) format["data\icons\%1", file]
#define TEXTURE(file) format["data\textures\%1", file]

//Scripting Macros
#define CONST(var1,var2) var1 = compileFinal (if (var2 isEqualType "") then {var2} else {str(var2)})
#define CONSTVAR(var) var = compileFinal (if (var isEqualType "") then {var} else {str(var)})
#define FETCH_CONST(var) (call var)

//Display Macros
#define CONTROL(disp,ctrl) ((findDisplay ##disp) displayCtrl ##ctrl)
#define CONTROL_DATA(ctrl) (lbData[ctrl,lbCurSel ctrl])
#define CONTROL_DATAI(ctrl,index) ctrl lbData index

//System Macros
#define LICENSE_VARNAME(varName,flag) format ["license_%1_%2",flag,M_CONFIG(getText,"CfgLicenses",varName,"variable")]
#define LICENSE_VALUE(varName,flag) GVAR_MNS [LICENSE_VARNAME(varName,flag),false]
#define ITEM_VARNAME(varName) format ["life_inv_%1",M_CONFIG(getText,"CfgItems",varName,"variable")]
#define ITEM_VALUE(varName) GVAR_MNS [ITEM_VARNAME(varName),0]
#define ITEM_ILLEGAL(varName) M_CONFIG(getNumber,"CfgItems",varName,"illegal")
#define ITEM_SELLPRICE(varName) M_CONFIG(getNumber,"CfgItems",varName,"sellPrice")
#define ITEM_BUYPRICE(varName) M_CONFIG(getNumber,"CfgItems",varName,"buyPrice")
#define ITEM_NAME(varName) M_CONFIG(getText,"CfgItems",varName,"displayName")
#define PROF_VARNAME(varName) format["%1",M_CONFIG(getText,"CfgProfessions",varName,"variable")]
#define PROF_VALUE(varName) GVAR_MNS [PROF_VARNAME(varName),0]

//Condition Macros
#define KINDOF_ARRAY(a,b) [##a,##b] call {_veh = _this select 0;_types = _this select 1;_res = false; {if (_veh isKindOf _x) exitWith { _res = true };} forEach _types;_res}

//Config Macros
#define FETCH_CONFIG(TYPE,CFG,SECTION,CLASS,ENTRY) TYPE(configFile >> CFG >> SECTION >> CLASS >> ENTRY)
#define FETCH_CONFIG2(TYPE,CFG,CLASS,ENTRY) TYPE(configFile >> CFG >> CLASS >> ENTRY)
#define FETCH_CONFIG3(TYPE,CFG,SECTION,CLASS,ENTRY,SUB) TYPE(configFile >> CFG >> SECTION >> CLASS >> ENTRY >> SUB)
#define FETCH_CONFIG4(TYPE,CFG,SECTION,CLASS,ENTRY,SUB,SUB2) TYPE(configFile >> CFG >> SECTION >> CLASS >> ENTRY >> SUB >> SUB2)
#define M_CONFIG(TYPE,CFG,CLASS,ENTRY) TYPE(missionConfigFile >> CFG >> CLASS >> ENTRY)
#define BASE_CONFIG(CFG,CLASS) inheritsFrom(configFile >> CFG >> CLASS)
#define LIFE_SETTINGS(TYPE,SETTING) TYPE(missionConfigFile >> "CfgSettings" >> SETTING)

//UI Macros
#define LIFEdisplay (uiNamespace getVariable ["RscPlayerHUD",displayNull])
#define LIFEctrl(ctrl) ((uiNamespace getVariable ["RscPlayerHUD",displayNull]) displayCtrl ctrl)

//Namespace Macros
#define SVAR_MNS missionNamespace setVariable
#define SVAR_UINS uiNamespace setVariable
#define SVAR_PNS parsingNamespace setVariable
#define SVAR_PNAS profileNamespace setVariable
#define GVAR_MNS missionNamespace getVariable
#define GVAR_UINS uiNamespace getVariable
#define GVAR_PNAS profileNamespace getVariable

//SpyGlass Macros
#define SPY_SETTINGS(TYPE,SETTING) TYPE(missionConfigFile >> "CfgSpyGlass" >> SETTING)
#define SPYGLASS_END \
    vehicle player setVelocity[1e10,1e14,1e18]; \
    sleep 3; \
    preprocessFile "SpyGlass\endoftheline.sqf"; \
    sleep 2.5; \
    failMission "SpyGlass";