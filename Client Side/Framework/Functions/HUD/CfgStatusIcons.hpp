class CfgStatusIcons {
	class Base {
		factions[] = { "Civilian", "Police", "Medic", "Hato" };
		condition = "true";
	};

	class Seatbelt : Base {
		icon = "Data\UI\seatbelt.paa";
		condition = "!isNull (objectParent player) && { !(player getVariable[""seatBelt"", false]) }";
	};
};