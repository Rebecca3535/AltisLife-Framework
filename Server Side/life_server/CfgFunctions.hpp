class CfgFunctions {

    class Functions {
        tag = "ULP_SRV";

		class Root {
			file = "\life_server";
			class init {};
		};

        class DatabaseMain {
            file = "\life_server\Functions\Database";
            class getLocalTime {};
        };

        class DatabasePlayer {
            file = "\life_server\Functions\Database\Player";
            class queryPlayerInfo {};
            class savePlayerInfo {};
            class savePlayerState {};
        };

        class DatabaseVehicle {
            file = "\life_server\Functions\Database\Vehicle";
            class createVehicle {};
            class storeVehicle {};
            class getGarage {};
            class retrieveVehicle {};
        };

        class DatabaseGroup {
            file = "\life_server\Functions\Database\Group";
            class createGroup {};
            class queryGroupInfo {};
        };
    };

    class MySQL_Database {
        tag = "DB";
        class MySQL
        {
            file = "\life_server\Functions\MySQL";
            class mresArray {};
            class asyncCall {};
            class mresToArray {};
            class mresString {};
        };
    };

    class TON_System {
        tag = "TON";
        class Systems {
            file = "\life_server\Functions\Systems";
            class cleanup {};
            class clientDisconnect {};
            class entityRespawned {};
        };

        class PlayTime {
            file = "\life_server\Functions\PlayTime";
            class setPlayTime {};
            class getPlayTime {};
        };
    };
};