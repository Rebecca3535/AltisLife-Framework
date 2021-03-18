class CfgRobberies {
	personalTimeout = 3 * 60;
	
	class FuelStation {
		name = "Fuel Station";
		time = 5 * 60;
		timeout = 3 * 60;
		factions[] = { "Civilian" };
		reward[] = { 30000, 65000 };
		leveling[] = { { 5, 15 }, "Robbed Fuel Station", 100 };
		condition = "[[""Police""]] call ULP_fnc_onlineFaction < 3";
		onFail = "hint ""There must be at least 3 officers online to rob this store."";";
	};

	class RegionalBank {
		name = "Regional Bank";
		time = 10 * 60;
		timeout = 30 * 60;
		factions[] = { "Civilian" };
		reward[] = { 140000, 460000 };
		leveling[] = { { 5, 15 }, "Robbed Fuel Station", 100 };
		condition = "[[""Police""]] call ULP_fnc_onlineFaction < 5";
		onFail = "hint ""There must be at least 5 officers online to rob this store."";";
	};
};