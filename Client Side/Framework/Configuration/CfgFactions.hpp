class CfgFactions {
	defaultFaction = "Civilian";
	fallbackPay = 1000;

	class Police {
		displayName = "Altis Police Constabulary";
		pay = 15000;

		class Whitelisting {
			class Main {
				queryIndex = 18;
				payMulti = 0.1;
				required = 1;
			};
			class RTA { queryIndex = 19; };
			class NPAS { queryIndex = 20; };
			class SCO { queryIndex = 21; };
			class NCA { queryIndex = 22; };
			class MPU { queryIndex = 23; };
			class RPU { queryIndex = 24; };
			class AFO { queryIndex = 25; };
			class UC { queryIndex = 26; };
		};

		class DatabaseInfo {
			queryPrefix = "cop_";
			customQuery = ", cop_blacklisted, coplevel, rtalevel, npaslevel, scolevel, ncalevel, mpulevel, rpulevel, afolevel, uclevel";
			timeIndex = 0;
		};

		class Persistance {
			vehicles = false;
		};

		class Loadout {
			class Uniforms {
				class U_Rangemaster {};
			};
			class LinkedItems {
				hasMap = true;
				hasGPS = true;
				hasCompass = true;
				hasWatch = true;
				hasRadio = true;
			};
		};
	};

	class Medic {
		displayName = "National Health Service";
		pay = 16000;
		class Whitelisting {
			class Main {
				queryIndex = 18;
				payMulti = 0.15;
				required = 1;
			};
			class AA { queryIndex = 19; };
		};

		class DatabaseInfo {
			queryPrefix = "med_";
			customQuery = ", med_blacklisted, mediclevel, aalevel";
			timeIndex = 1;
		};

		class Persistance {
			vehicles = false;
		};

		class Loadout {
			class Uniforms {
				class U_Rangemaster {};
			};
			class LinkedItems {
				hasMap = true;
				hasGPS = true;
				hasCompass = true;
				hasWatch = true;
				hasRadio = true;
			};
		};
	};

	class Hato {
		displayName = "Highways Traffic Agency";
		pay = 14500;
		class Whitelisting {
			class Main {
				queryIndex = 18;
				payMulti = 0.5;
				required = 1;
			};
		};

		class DatabaseInfo {
			queryPrefix = "hato_";
			customQuery = ", hato_blacklisted, hatolevel";
			timeIndex = 1;
		};

		class Persistance {
			vehicles = false;
		};

		class Loadout {
			class Uniforms {
				class U_Rangemaster {};
			};
			class LinkedItems {
				hasMap = true;
				hasGPS = true;
				hasCompass = true;
				hasWatch = true;
				hasRadio = true;
			};
		};
	};

	class Civilian {
		displayName = "Civilian";
		pay = 7500;
		class Groups {};
		class Housing {};
		class DatabaseInfo {
			queryPrefix = "civ_";
			customQuery = ", arrested";
			timeIndex = 2;
		};

		class Persistance {
			vehicles = true;
		};
		
		class Loadout {
			class Uniforms {
				class U_C_Poor_1 {};
				class U_C_Poloshirt_blue {};
				class U_C_Man_casual_1_F {};
				class U_C_Man_casual_6_F {};
			};
			class LinkedItems {
				hasMap = true;
				hasGPS = false;
				hasCompass = true;
				hasWatch = true;
				hasRadio = false;
			};
		};
	};
};