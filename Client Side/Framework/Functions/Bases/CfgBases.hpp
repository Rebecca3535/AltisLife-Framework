class CfgBases {
	// Bidding info...
	Day = "Friday";
	Restart[] = {20, 24};

	class NorthEast {
		displayName = "North East Base";
		position[] = {{12044.9, 10492.4, -0.303827}, 0};
		includeBidding = true;
		class Spawn {
			marker = "gang_base_1";
		};
	};

	class East : NorthEast {
		displayName = "East Base";
		position[] = {{12295.3,8872.94,0.00119019}, 289.015};
		class Spawn {
			marker = "gang_base_2";
		};
	};
};