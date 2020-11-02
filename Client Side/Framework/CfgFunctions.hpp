class ULP_Functions {
	tag = "ULP";

	class General {
		file = "Functions\General";
		class logIt {};
	};

	class Initalisation {
		file = "Functions\Initialisation";
		class initialisation {};
		class initEventHandlers {};
		class initVars {};
	};

	class Faction {
		file = "Functions\Faction";
		class setFaction {};
		class getFaction {};
		class isFaction {};
		class hasAccess {};
	};

	class Clothing {
		file = "Functions\Clothing";
		class setTextures {};
	};

	class Player {
		file = "Functions\Player";
		class loadGear {};
		class saveGear {};
	};

	class Paycheck {
		file = "Functions\Paycheck";
		class calcPaycheck {};
	};

	class Database {
		file = "Functions\Database";
		class sync {};
	};

	class DatabasePlayer {
		file = "Functions\Database\Player";
		class getPlayerInfo {};
		class setPlayerInfo {};
		class syncPlayerInfo {};
	};
};