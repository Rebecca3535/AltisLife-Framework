class CfgVehicles {
	sellPerc = 0.3;
	retrievalPerc = 0.15;

	class Base {
		conditions = "true";
		class Textures {};
	};

	class BaseTexture {
		displayName = "Default";
		buyPrice = 0;
		factions[] = { "Civilian" };
		textures[] = {};
		conditions = "true";
	};

	class Police : BaseTexture {
		factions[] = { "Police" };
		class Siren {
			SFX[] = { "Police_One" };
		};
	};

	// CARS --------------------------------------------------------------------------------------
	class C_Kart_01_Blu_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class C_Kart_01_Fuel_F : C_Kart_01_Blu_F{};
    class C_Kart_01_Red_F : C_Kart_01_Blu_F{};
    class C_Kart_01_Vrana_F : C_Kart_01_Blu_F{};
    class C_Kart_01_black_F : C_Kart_01_Blu_F{};
    class C_Kart_01_white_F : C_Kart_01_Blu_F{};
    class C_Kart_01_green_F : C_Kart_01_Blu_F{};
    class C_Kart_01_orange_F : C_Kart_01_Blu_F{};
    class C_Kart_01_yellow_F : C_Kart_01_Blu_F{};

	class C_Quadbike_01_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_black_co.paa" }; 
			};
			class White : BaseTexture { 
				displayName = "White";
				textures[] = { "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_white_co.paa" }; 
			};
			class Red : BaseTexture { 
				displayName = "Red";
				textures[] = { "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_red_co.paa" }; 
			};
			class Blue : BaseTexture { 
				displayName = "Blue";
				textures[] = { "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_blue_co.paa" }; 
			};
			class Tan : BaseTexture { 
				displayName = "Tan";
				textures[] = { "\A3\Soft_F\Quadbike_01\Data\Quadbike_01_co.paa" }; 
			};
		};
	};

	class C_Hatchback_01_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base09_co.paa" }; 
			};
			class BlackWhiteSport : BaseTexture {
				displayName = "Black/White Sport"; 
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport04_co.paa" }; 
			};
			class Grey : BaseTexture {
				displayName = "Grey"; 
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base08_co.paa" }; 
			};
			class White : BaseTexture { 
				displayName = "White";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base07_co.paa" }; 
			};
			class Beige : BaseTexture { 
				displayName = "Beige";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base01_co.paa" }; 
			};
			class BeigeSport : BaseTexture { 
				displayName = "Beige Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport05_co.paa" }; 
			};
			class RedSport : BaseTexture { 
				displayName = "Red Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport01_co.paa" }; 
			};
			class Blue : BaseTexture { 
				displayName = "Blue";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base03_co.paa" }; 
			};
			class BlueSport : BaseTexture { 
				displayName = "Blue Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE04_CO.paa" }; 
			};
			class DarkBlue : BaseTexture { 
				displayName = "Dark Blue";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base04_co.paa" }; 
			};
			class DarkBlueSport : BaseTexture { 
				displayName = "Dark Blue Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport02_co.paa" }; 
			};
			class Green : BaseTexture { 
				displayName = "Green";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base02_co.paa" }; 
			};
			class GreenSport : BaseTexture { 
				displayName = "Green Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE02_CO.paa" }; 
			};
			class Yellow : BaseTexture { 
				displayName = "Yellow";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base06_co.paa" }; 
			};
			class OrangeSport : BaseTexture { 
				displayName = "Orange Sport";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport03_co.paa" }; 
			};
			class PoliceWhite : BaseTexture { 
				displayName = "General Response";
				factions[] = { "Police" };
				textures[] = { "data\textures\vehicles\land\police\police_hatchback_white.paa" }; 
			};
			class PoliceBlack : BaseTexture { 
				displayName = "Armed Response";
				factions[] = { "Police" };
				conditions = "[""Police_SFO"", 1] call ULP_fnc_hasAccess";
				textures[] = { "data\textures\vehicles\land\police\police_hatchback_black.paa" }; 
			};
			class Medic : BaseTexture { 
				displayName = "Incident Response";
				factions[] = { "Medic" };
				textures[] = { "data\textures\vehicles\land\medic\medic_hatchback.paa" }; 
			};
		};
	};

	class C_Hatchback_01_sport_F : C_Hatchback_01_F { buyPrice = 0; };

	class C_Offroad_01_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class White : BaseTexture {
				displayName = "White"; 
				textures[] = { 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE02_CO.paa", 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE02_CO.paa" 
				}; 
			};
			class Red : BaseTexture { 
				displayName = "Red";
				textures[] = { 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_co.paa", 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_co.paa" 
				}; 
			};
			class DarkRed : BaseTexture { 
				displayName = "DarkRed";
				textures[] = { 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE04_CO.paa", 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE04_CO.paa" 
				}; 
			};
			class Blue : BaseTexture { 
				displayName = "Blue";
				textures[] = { 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE03_CO.paa", 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE03_CO.paa" 
				}; 
			};
			class BlueWhite : BaseTexture { 
				displayName = "Blue/White";
				textures[] = { 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE05_CO.paa", 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE05_CO.paa" 
				}; 
			};
			class PoliceWhite : BaseTexture { 
				displayName = "General Response";
				factions[] = { "Police" };
				textures[] = { 
					"data\textures\Police\Vehicles\police_offroad_white.paa",
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_co.paa",
					"#(rgb,8,8,3)color(0.97,0.97,0.97,1)" 
				}; 
			};
		};
	};
	class B_G_Offroad_01_armed_F : C_Offroad_01_F { buyPrice = 0; };
	class B_GEN_Offroad_01_gen_F : C_Offroad_01_F {};

	class C_Offroad_01_covered_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = {
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_ext_blk_co.paa",
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_ext_blk_co.paa",
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_cover_blk_co.paa"
				}; 
			};
			class Green : BaseTexture { 
				displayName = "Green";
				textures[] = { 
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_ext_grn_co.paa",
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_ext_grn_co.paa",
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_cover_grn_co.paa"
				}; 
			};
		};
	};
	class C_Offroad_01_comms_F : C_Offroad_01_covered_F { buyPrice = 0; };

	class C_Offroad_01_repair_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
	};

	class C_Offroad_02_unarmed_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_black_co.paa" }; 
			};
			class White : BaseTexture { 
				displayName = "White";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_white_co.paa" }; 
			};
			class Red : BaseTexture { 
				displayName = "Red";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_red_co.paa" }; 
			};
			class Blue : BaseTexture { 
				displayName = "Blue";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_blue_co.paa" }; 
			};
			class Orange : BaseTexture { 
				displayName = "Orange";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_orange_co.paa" }; 
			};
		};
	};
	class I_C_Offroad_02_LMG_F : C_Offroad_02_unarmed_F { buyPrice = 0; };

	class C_SUV_01_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_02_co.paa" }; 
			};
			class Silver : BaseTexture { 
				displayName = "Silver";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_03_co.paa" }; 
			};
			class Red : BaseTexture { 
				displayName = "Red";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_co.paa" }; 
			};
			class Orange : BaseTexture { 
				displayName = "Orange";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_04_co.paa" }; 
			};
			class PoliceWhite : Police { 
				displayName = "General Response";
				factions[] = { "Police" };
				textures[] = { "data\textures\vehicles\land\police\whitesuv.paa" };
			};
			class PoliceBlack : PoliceWhite { 
				displayName = "Armed Response";
				factions[] = { "Police" };
				conditions = "[""Police_SFO"", 1] call ULP_fnc_hasAccess";
				textures[] = { "data\textures\vehicles\land\police\blacksuv.paa" }; 
			};
			class PoliceANPR : PoliceWhite { 
				displayName = "Interceptor";
				factions[] = { "Police" };
				conditions = "[""Police_SFO"", 1] call ULP_fnc_hasAccess";
				textures[] = { "data\textures\vehicles\land\police\anprsuv.paa" }; 
			};
			class PoliceUnmarked : PoliceWhite {
				displayName = "Unmarked"; 
				factions[] = { "Police" };
				conditions = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SFO"", 3] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_02_co.paa" }; 
			};
			class Medic : BaseTexture { 
				displayName = "General Response";
				factions[] = { "Medic" };
				textures[] = { "data\textures\vehicles\land\medic\medic_suv.paa" }; 
			};
		};
	};

	class C_Van_02_transport_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_black_CO.paa" }; 
			};
			class White : BaseTexture { 
				displayName = "White";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_white_CO.paa" }; 
			};
			class Red : BaseTexture { 
				displayName = "Red";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_Red_CO.paa" }; 
			};
			class Orange : BaseTexture { 
				displayName = "Orange";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_Orange_CO.paa" }; 
			};
			class Press : BaseTexture { 
				displayName = "Press";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_AAN_CO.paa" }; 
			};
			class Police : BaseTexture { 
				displayName = "Public Order";
				factions[] = { "Police" };
				textures[] = { "data\textures\vehicles\land\police\police_van.paa" }; 
			};
			class PoliceUnmarked : BaseTexture {
				displayName = "Unmarked"; 
				factions[] = { "Police" };
				conditions = "[""Police_Main"", 10] call ULP_fnc_hasAccess || { [""Police_SFO"", 3] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_black_CO.paa" }; 
			};
			class Medic : BaseTexture { 
				displayName = "Ambulance";
				factions[] = { "Medic" };
				textures[] = { "data\textures\vehicles\land\medic\medic_van.paa" }; 
			};
		};
	};
	class B_GEN_Van_02_transport_F : C_Van_02_transport_F {};
	class C_Van_02_medevac_F : C_Van_02_transport_F {};
	class C_Van_02_vehicle_F : C_Van_02_transport_F {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class B_GEN_Van_02_vehicle_F : C_Van_02_vehicle_F {};
	class C_Van_02_service_F : C_Van_02_vehicle_F {};

	class B_CTRG_LSV_01_light_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { 
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_01_black_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_02_black_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_03_black_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_adds_black_co.paa" 
				}; 
			};
			class Sand : BaseTexture { 
				displayName = "Sand";
				textures[] = { 
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_01_sand_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_02_sand_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_03_sand_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_adds_sand_co.paa"
				}; 
			};
			class Olive : BaseTexture { 
				displayName = "Olive";
				textures[] = { 
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_01_olive_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_02_olive_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_03_olive_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_adds_olive_co.paa"
				}; 
			};
			class Blue : BaseTexture { 
				displayName = "Blue";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_blue_co.paa" }; 
			};
			class Orange : BaseTexture { 
				displayName = "Orange";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_orange_co.paa" }; 
			};
			class Police : BaseTexture { 
				displayName = "Police";
				factions[] = { "Police" };
				textures[] = { "data\textures\vehicles\land\police\police_prowler.paa" }; 
			};
		};
	};
	class B_T_LSV_01_unarmed_black_F : B_CTRG_LSV_01_light_F { buyPrice = 0; };

	class O_LSV_02_unarmed_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class White : BaseTexture { 
				displayName = "White";
				textures[] = { 
					"#(rgb,8,8,3)color(0.97,0.97,0.97,1)", 
					"\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa" 
				}; 
			};
			class Red : BaseTexture { 
				displayName = "Red";
				textures[] = { 
					"#(rgb,8,8,3)color(0.9,0.03,0.03,1)",
					"\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa" 
				}; 
			};
			class Orange : BaseTexture { 
				displayName = "Orange";
				textures[] = { 
					"#(rgb,8,8,3)color(1,0.2,0.03,1)",
					"\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa"
				}; 
			};
			class Teal : BaseTexture { 
				displayName = "Teal";
				textures[] = { 
					"#(rgb,8,8,3)color(0.05,0.67,737,1)",
					"\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa"
				}; 
			};
			class Green : BaseTexture { 
				displayName = "Green";
				textures[] = { 
					"#(rgb,8,8,3)color(0.03,0.9,0.03,1)",
					"\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa" 
				}; 
			};
			class Emerald : BaseTexture { 
				displayName = "Emerald";
				textures[] = { 
					"#(rgb,8,8,3)color(0.03,1,0.6,1)", 
					"\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa"
				}; 
			};
			class Lime : BaseTexture { 
				displayName = "Lime";
				textures[] = { 
					"#(rgb,8,8,3)color(0.1,0.6,0.03,1)",
					"\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa"
				}; 
			};
			class Pink : BaseTexture { 
				displayName = "Pink";
				textures[] = { 
					"#(rgb,8,8,3)color(0.97,0.03,0.5,1)",
					"\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_02_ghex_CO.paa"
				}; 
			};
			class Police : BaseTexture { 
				displayName = "Police";
				factions[] = { "Police" };
				textures[] = { "data\textures\vehicles\land\police\police_qilin.paa" }; 
			};
		};
	};

	class B_MRAP_01_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Police : BaseTexture {
				displayName = "Police"; 
				factions[] = { "Police" };
				textures[] = {
					"data\textures\vehicles\land\police\police_hunter1.paa",
					"data\textures\vehicles\land\police\police_hunter2.paa"
				}; 
			};
		};
	};

	class O_MRAP_02_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class White : BaseTexture { 
				displayName = "White";
				textures[] = { 
					"#(rgb,8,8,3)color(0.97,0.97,0.97,1)", 
					"#(rgb,8,8,3)color(0.97,0.97,0.97,1)" 
				}; 
			};
			class Red : BaseTexture { 
				displayName = "Red";
				textures[] = { 
					"#(rgb,8,8,3)color(0.9,0.03,0.03,1)",
					"#(rgb,8,8,3)color(0.9,0.03,0.03,1)"
				}; 
			};
			class Orange : BaseTexture { 
				displayName = "Orange";
				textures[] = { 
					"#(rgb,8,8,3)color(1,0.2,0.03,1)",
					"#(rgb,8,8,3)color(1,0.2,0.03,1)"
				}; 
			};
			class Teal : BaseTexture { 
				displayName = "Teal";
				textures[] = { 
					"#(rgb,8,8,3)color(0.05,0.67,737,1)",
					"#(rgb,8,8,3)color(0.05,0.67,737,1)"
				}; 
			};
			class Green : BaseTexture { 
				displayName = "Green";
				textures[] = { 
					"#(rgb,8,8,3)color(0.03,0.9,0.03,1)",
					"#(rgb,8,8,3)color(0.03,0.9,0.03,1)"
				}; 
			};
			class Emerald : BaseTexture { 
				displayName = "Emerald";
				textures[] = { 
					"#(rgb,8,8,3)color(0.03,1,0.6,1)", 
					"#(rgb,8,8,3)color(0.03,1,0.6,1)"
				}; 
			};
			class Lime : BaseTexture { 
				displayName = "Lime";
				textures[] = { 
					"#(rgb,8,8,3)color(0.1,0.6,0.03,1)",
					"#(rgb,8,8,3)color(0.1,0.6,0.03,1)"
				}; 
			};
			class Pink : BaseTexture { 
				displayName = "Pink";
				textures[] = { 
					"#(rgb,8,8,3)color(0.97,0.03,0.5,1)",
					"#(rgb,8,8,3)color(0.97,0.03,0.5,1)"
				}; 
			};
		};
	};

	class I_MRAP_03_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
	};

	// TRUCKS --------------------------------------------------------------------------------------
	class C_Tractor_01_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Red : BaseTexture {
				displayName = "Red"; 
				textures[] = { "\a3\soft_f_enoch\tractor_01\data\tractor_01_2_red_co.paa" }; 
			};
			class Blue : BaseTexture { 
				displayName = "Blue";
				textures[] = { "\a3\soft_f_enoch\tractor_01\data\tractor_01_2_blue_co.paa" }; 
			};
			class Green : BaseTexture { 
				displayName = "Green";
				textures[] = { "\a3\soft_f_enoch\tractor_01\data\tractor_01_2_green_co.paa" }; 
			};
		};
	};

	class C_Van_01_transport_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_black_co.paa" }; 
			};
			class White : BaseTexture { 
				displayName = "White";
				textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_co.paa" }; 
			};
			class Red : BaseTexture { 
				displayName = "Red";
				textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_red_co.paa" }; 
			};
			class Brown : BaseTexture { 
				displayName = "Brown";
				textures[] = { "\a3\soft_f_exp\van_01\data\van_01_ext_brn_co.paa" }; 
			};
			class Olive : BaseTexture { 
				displayName = "Olive";
				textures[] = { "\a3\soft_f_exp\van_01\data\van_01_ext_oli_co.paa" }; 
			};
		};
	};
	class C_Van_01_box_F : C_Van_01_transport_F {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class C_Van_01_fuel_F : C_Van_01_transport_F {
		buyPrice = 0;
		virtualSpace = 0;
	};

	class I_Truck_02_transport_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Orange : BaseTexture {
				displayName = "Orange"; 
				textures[] = { 
					"\A3\Soft_F_Beta\Truck_02\data\truck_02_kab_co.paa", 
					"\a3\soft_f_beta\Truck_02\data\truck_02_kuz_co.paa"
				 }; 
			};
			class Blue : BaseTexture { 
				displayName = "Blue";
				textures[] = { 
					"\a3\soft_f_beta\truck_02\data\truck_02_kab_blue_co.paa",
					"\a3\soft_f_beta\truck_02\data\truck_02_kuz_co.paa",
					"\a3\soft_f_beta\truck_02\data\truck_02_int_co.paa"
				};
			}; 
		};
	};
	class I_Truck_02_covered_F : I_Truck_02_transport_F {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class I_Truck_02_fuel_F : I_Truck_02_transport_F {
		buyPrice = 0;
		virtualSpace = 0;
	};

	class O_Truck_03_transport_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class BrownHex : BaseTexture {
				displayName = "Brown Hex"; 
				textures[] = { 
					"\a3\soft_f_epc\truck_03\data\truck_03_ext01_co.paa",
					"\a3\soft_f_epc\truck_03\data\truck_03_ext02_co.paa",
					"\a3\soft_f_epc\truck_03\data\truck_03_cargo_co.paa"
				 }; 
			};
			class GreenHex : BaseTexture { 
				displayName = "Green Hex";
				textures[] = { 
					"\a3\soft_f_exp\truck_03\data\truck_03_ext01_ghex_co.paa",
					"\a3\soft_f_exp\truck_03\data\truck_03_ext02_ghex_co.paa",
					"\a3\soft_f_exp\truck_03\data\truck_03_cargo_ghex_co.paa"
				};
			}; 
		};
	};
	class O_Truck_03_covered_F : O_Truck_03_transport_F {
			buyPrice = 0;
			virtualSpace = 0;
		};
	class O_Truck_03_ammo_F : O_Truck_03_transport_F {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class O_Truck_03_fuel_F : O_Truck_03_transport_F {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class O_Truck_03_device_F : O_Truck_03_transport_F {
		buyPrice = 0;
		virtualSpace = 0;
	};

	class B_Truck_01_mover_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Sand : BaseTexture {
				displayName = "Sand"; 
				textures[] = { 
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
					"\a3\soft_f_enoch\truck_01\data\truck_01_ammo_co.paa",
					"\a3\soft_f_enoch\truck_01\data\truck_01_cargo_co.paa"
				 }; 
			};
			class Olive : BaseTexture { 
				displayName = "Olive";
				textures[] = { 
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
					"\a3\soft_f_enoch\truck_01\data\truck_01_ammo_pacific_co.paa",
					"\a3\soft_f_enoch\truck_01\data\truck_01_cargo_pacific_co.paa"
				};
			}; 
		};
	};
	class B_Truck_01_flatbed_F : B_Truck_01_mover_F {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class B_Truck_01_cargo_F : B_Truck_01_mover_F {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class B_Truck_01_transport_F : B_Truck_01_mover_F {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class B_Truck_01_covered_F : B_Truck_01_mover_F {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class B_Truck_01_ammo_F : B_Truck_01_mover_F {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class B_T_Truck_01_fuel_F : B_Truck_01_mover_F {
		buyPrice = 0;
		virtualSpace = 0;
	};

	class B_Truck_01_box_F {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Sand : BaseTexture {
				displayName = "Sand"; 
				textures[] = { 
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
					"\a3\soft_f_gamma\truck_01\data\truck_01_mprimer_co.paa",
					"\a3\structures_f\data\metal\containers\containers_02_set_co.paa"
				 }; 
			};
			class Olive : BaseTexture { 
				displayName = "Olive";
				textures[] = { 
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ammo_olive_co.paa",
					"\a3\structures_f\data\metal\containers\containers_02_set_co.paa"
				};
			}; 
			class Ridge : BaseTexture { 
				displayName = "Ridge";
				textures[] = { 
					"data\textures\vehicles\land\civilian\ridge_hemtt_1.paa",
					"data\textures\vehicles\land\civilian\ridge_hemtt_2.paa",
					"data\textures\vehicles\land\civilian\ridge_hemtt_3.paa",
					"data\textures\vehicles\land\civilian\ridge_hemtt_4.paa"
				};
			}; 
		};
	};

	// BOATS --------------------------------------------------------------------------------------
	class C_Scooter_Transport_01_F {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { 
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_black_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_black_co.paa"
				 }; 
			};
			class White : BaseTexture { 
				displayName = "White";
				textures[] = { 
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_White_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_White_co.paa"
				};
			}; 
			class Grey : BaseTexture { 
				displayName = "Grey";
				textures[] = { 
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_Grey_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_Grey_co.paa"
				};
			}; 
			class Red : BaseTexture { 
				displayName = "Red";
				textures[] = { 
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_Red_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_Red_co.paa"
				};
			}; 
			class Blue : BaseTexture { 
				displayName = "Blue";
				textures[] = { 
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_blue_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_blue_co.paa"
				};
			}; 
			class Green : BaseTexture { 
				displayName = "Green";
				textures[] = { 
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_Green_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_Green_co.paa"
				};
			}; 
			class Yellow : BaseTexture { 
				displayName = "Yellow";
				textures[] = { 
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_Yellow_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_Yellow_co.paa"
				};
			}; 
		};
	};

	class C_Rubberboat : Base {
		buyPrice = 0;
		virtualSpace = 0;
	};

	class C_Boat_Civil_01_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Police : BaseTexture {
				displayName = "Police"; 
				factions[] = { "Police" };
				textures[] = { "data\textures\vehicles\sea\police\police_motorboat.paa" }; 
			};
		};
	};
	class C_Boat_Civil_01_police_F : C_Boat_Civil_01_F {};

	class C_Boat_Transport_02_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Police : BaseTexture {
				displayName = "Police"; 
				factions[] = { "Police" };
				textures[] = { "data\textures\vehicles\sea\police\police_rhib.paa" }; 
			};
		};
	};

	class B_Boat_Armed_01_minigun_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Police : BaseTexture {
				displayName = "Police"; 
				factions[] = { "Police" };
				textures[] = { "data\textures\vehicles\sea\police\police_speedboat.paa" }; 
			};
		};
	};

	class B_SDV_01_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
	};

	// HELICOPTERS --------------------------------------------------------------------------------------
	class B_UAV_01_F : Base {
		buyPrice = 0;
		virtualSpace = 0;
	};
	
	class C_Heli_Light_01_civil_F {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class TotalRed : BaseTexture {
				displayName = "Total Red"; 
				textures[] = { "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_co.paa" }; 
			};
			class TotalBlue : BaseTexture { 
				displayName = "Total Blue";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_blue_co.paa" };
			}; 
			class Sheriff : BaseTexture { 
				displayName = "Sheriff";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sheriff_co.paa" };
			}; 
			class Blueline : BaseTexture { 
				displayName = "Blueline";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_blueline_co.paa" };
			}; 
			class Elliptical : BaseTexture { 
				displayName = "Elliptical";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_elliptical_co.paa" };
			}; 
			class Furious : BaseTexture { 
				displayName = "Furious";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_furious_co.paa" };
			}; 
			class JeansBlue : BaseTexture { 
				displayName = "Jeans Blue";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_jeans_co.paa" };
			}; 
			class SpeedyRedline : BaseTexture { 
				displayName = "Speedy Redline";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_speedy_co.paa" };
			}; 
			class Sunset : BaseTexture { 
				displayName = "Sunset";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sunset_co.paa" };
			}; 
			class Vrana : BaseTexture { 
				displayName = "Vrana";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_vrana_co.paa" };
			}; 
			class WavesBlue : BaseTexture { 
				displayName = "Waves Blue";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wave_co.paa" };
			}; 
			class Shadow : BaseTexture { 
				displayName = "Shadow";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\Heli_Light_01_ext_shadow_co.paa" };
			}; 
			class GrayWatcher : BaseTexture { 
				displayName = "Gray Watcher";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\Heli_Light_01_ext_graywatcher_co.paa" };
			}; 
			class Wasp : BaseTexture { 
				displayName = "Wasp";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wasp_co.paa" };
			}; 
			class Police : BaseTexture {
				displayName = "Police"; 
				factions[] = { "Police" };
				textures[] = { "data\textures\vehicles\air\police\police_littlebird.paa" }; 
			};
			class Medic : BaseTexture {
				displayName = "Medic"; 
				factions[] = { "Medic" };
				textures[] = { "data\textures\vehicles\air\medic\medic_littlebird.paa" }; 
			};
		};
	};

	class O_Heli_Light_02_unarmed_F {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { "\a3\air_f\Heli_Light_02\Data\heli_light_02_ext_CO.paa" }; 
			};
			class BlackWhite : BaseTexture {
				displayName = "Black / White"; 
				textures[] = { "\a3\air_f_heli\heli_light_02\data\heli_light_02_ext_opfor_v2_co.paa" }; 
			};
			class WhiteBlue : BaseTexture { 
				displayName = "White / Blue";
				textures[] = { "\a3\air_f\Heli_Light_02\Data\heli_light_02_ext_civilian_co.paa" };
			}; 
			class Police : BaseTexture {
				displayName = "Police"; 
				factions[] = { "Police" };
				textures[] = { "data\textures\vehicles\air\police\police_orca.paa" }; 
			};
			class Medic : BaseTexture {
				displayName = "Medic"; 
				factions[] = { "Medic" };
				textures[] = { "data\textures\vehicles\air\medic\medic_orca.paa" }; 
			};
		};
	};

	class I_Heli_light_03_unarmed_F {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { "#(rgb,8,8,3)color(0.03,0.03,0.03,1)" }; 
			};
			class Green : BaseTexture {
				displayName = "Green"; 
				textures[] = { "\a3\air_f_epb\Heli_Light_03\data\Heli_Light_03_base_CO.paa" }; 
			};
			class WhiteBlue : BaseTexture { 
				displayName = "White / Blue";
				textures[] = { "\a3\air_f\Heli_Light_02\Data\heli_light_02_ext_civilian_co.paa" };
			}; 
			class Police : BaseTexture {
				displayName = "Police"; 
				factions[] = { "Police" };
				textures[] = { "data\textures\vehicles\air\police\police_hellcat.paa" }; 
			};
		};
	};
	class I_Heli_light_03_F : I_Heli_light_03_unarmed_F {};

	class B_Heli_Transport_01_F {
		buyPrice = 0;
		virtualSpace = 0;
	};

	class I_Heli_Transport_02_F {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Ion : BaseTexture {
				displayName = "Ion"; 
				textures[] = { 
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_1_ion_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_2_ion_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_3_ion_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\heli_transport_02_int_02_co.paa"
				 }; 
			};
			class Dahoman : BaseTexture {
				displayName = "Dahoman"; 
				textures[] = { 
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_1_dahoman_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_2_dahoman_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_3_dahoman_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\heli_transport_02_int_02_co.paa" 
				}; 
			};
		};
	};

	class O_Heli_Transport_04_black_F {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class O_Heli_Transport_04_bench_black_F {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class O_Heli_Transport_04_covered_black_F {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class O_Heli_Transport_04_box_black_F {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class O_Heli_Transport_04_ammo_black_F {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class O_Heli_Transport_04_fuel_black_F {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class O_Heli_Transport_04_medevac_black_F {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Medic : BaseTexture {
				displayName = "Medic"; 
				factions[] = { "Medic" };
				textures[] = { 
					"data\textures\vehicles\air\medic\medic_taru1.paa", 
					"data\textures\vehicles\air\medic\medic_taru2.paa", 
					"data\textures\vehicles\air\medic\medic_taru3.paa", 
					"data\textures\vehicles\air\medic\medic_taru4.paa"
				}; 
			};
		};
	};

	class B_Heli_Transport_03_unarmed_F {
		buyPrice = 0;
		virtualSpace = 0;
		class Textures {
			class Black : BaseTexture {
				displayName = "Black"; 
				textures[] = { 
					"\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext01_black_co.paa",
					"\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext02_black_co.paa"
				 }; 
			};
			class Olive : BaseTexture {
				displayName = "Olive"; 
				textures[] = { 
					"\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext01_co.paa",
					"\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext02_co.paa"
				}; 
			};
			class Medic : BaseTexture {
				displayName = "Medic"; 
				factions[] = { "Medic" };
				textures[] = { 
					"data\textures\vehicles\air\medic\medic_huron1.paa", 
					"data\textures\vehicles\air\medic\medic_huron2.paa"
				}; 
			};
		};
	};

	// PLANES --------------------------------------------------------------------------------------
	class C_Plane_Civil_01_F {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class C_Plane_Civil_01_racing_F : C_Plane_Civil_01_F {};

	class B_T_VTOL_01_infantry_F {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class B_T_VTOL_01_vehicle_F {
		buyPrice = 0;
		virtualSpace = 0;
	};

	class O_T_VTOL_02_infantry_F {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class O_T_VTOL_02_vehicle_F {
		buyPrice = 0;
		virtualSpace = 0;
	};

	class I_Plane_Fighter_03_CAS_F {
		buyPrice = 0;
		virtualSpace = 0;
	};
	class I_Plane_Fighter_04_F { buyPrice = 0; };
	class B_Plane_CAS_01_F { buyPrice = 0; };
	class B_Plane_Fighter_01_F { buyPrice = 0; };
	class B_Plane_Fighter_01_Stealth_F { buyPrice = 0; };
	class O_Plane_CAS_02_F { buyPrice = 0; };
	class O_Plane_Fighter_02_F { buyPrice = 0; };
	class O_Plane_Fighter_02_Stealth_F { buyPrice = 0; };

	// Sounds...
	
	class Police_One {
		sound = "Police_One";
	};
};