class NorwegianBase
{
	//Base Settings
	int LootCycleTime = 30;			//minutes
	
	//Base entities
	Object Tower, Heliport, Barrack1, Barrack2, Barrack3, Barrack4, MainBuilding;
	Object HeliCrashNPR;
	
	//Base containers
	ref array<ref Param3<string,vector,vector>> BaseObjects = new array<ref Param3<string,vector,vector>>;
	ref array<Object> BaseObjectList = new array<Object>;
	ref array<vector> TowerSpawns = new array<vector>;
	ref array<vector> BarrackSpawns = new array<vector>;
	ref array<vector> MainSpawns = new array<vector>;
	
	//temporary containers 
	ref array<Object> ObjectList = new array<Object>; 
	ref array<CargoBase> ObjectCargoList = new array<CargoBase>;
	
	void NorwegianBase()
	{
		//important buildings (see Base entities)
		BaseObjects.Insert( new Param3<string,vector,vector>("land_seb_watchtower", "395.451996 7.630000 10856.000000", "0.000000 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("land_lub_heliport", "384.000000 6.590000 10856.099609", "-90.000000 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("land_Mil_Barracks_Round_Polar", "434.510010 7.000000 10851.599609", "0.000000 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("land_Mil_Barracks_Round_Polar", "434.506989 7.000000 10862.599609", "179.999985 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("land_Mil_Barracks_Round_Polar", "424.661011 6.000000 10873.400391", "-90.000000 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("land_Mil_Barracks_Round_Polar", "413.670990 6.000000 10873.400391", "90.000000 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("land_budova2_winter", "394.355988 7.000000 10871.900391", "-1.000000 0.000000 0.000000"));
		//Base environment
		BaseObjects.Insert( new Param3<string,vector,vector>("land_a2_terrain_upper_concrete", "429.000000 -1.400000 10781.000000", "-150.000000 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Pier_Crane_B", "433.000000 8.600000 10789.799805", "119.999992 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("land_a2_terrain_upper_concrete", "423.799988 -1.000000 10784.000000", "29.999998 0.000000 2.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Container_1Bo", "410.072998 0.600000 10797.200195", "29.999998 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Container_1Bo", "407.000000 0.640000 10791.900391", "29.999998 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Container_1Aoh", "441.447998 2.070000 10766.000000", "0.000000 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Container_1Aoh", "444.000000 2.080000 10771.500000", "39.000000 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Pipe_Big_Ground2", "431.000000 -2.000000 10786.000000", "-149.999985 90.000000 179.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Power_Pole_Conc1_Amp", "405.731354 5.974800 10798.482422", "0.000000 -0.000000 -0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Power_Pole_Conc4_Lamp_Amp", "436.496002 6.000000 10874.000000", "-45.000000 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_streambed_moss_short_arrow", "415.734039 0.826833 10798.259766", "134.999969 0.000000 -0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_streambed_sand_short_slanted_inv", "410.000000 0.500000 10761.000000", "-45.000000 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Pipe_Big_BuildL", "427.898987 -9.000000 10784.299805", "119.999992 0.000000 90.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Tank_Medium_Stairs", "444.500000 1.900000 10806.000000", "119.999992 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Tank_Medium_Stairs", "442.000000 1.900000 10807.500000", "119.999992 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Tank_Medium_Stairs", "439.602997 1.900000 10808.900391", "119.999992 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Tank_Medium_Stairs", "437.216003 1.900000 10810.500000", "119.999992 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Farm_Hopper", "427.200012 -5.800000 10779.799805", "-59.999996 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("land_misc_barel_fire_3", "437.593414 6.011433 10870.004883", "0.000000 -0.000000 -0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Roadblock_WoodenCrate", "436.366394 6.016503 10867.843750", "80.999969 -0.000000 -0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Shed_M4", "381.089996 5.100000 10862.200195", "0.000000 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Shed_M4", "377.437988 5.100000 10862.400391", "0.000000 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Dead_MassGrave", "428.415985 6.300000 10841.599609", "0.000000 -11.000000 -5.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Misc_cargo_cont_net1", "414.934753 5.753362 10856.251953", "0.000000 -0.000000 -0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Container_1Aoh", "370.899994 1.000000 10811.000000", "45.000000 1.000000 -10.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("bldr_prop_CamoNetShelter", "415.127014 4.800000 10855.799805", "0.000000 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Misc_cargo_cont_net1", "416.742004 5.753360 10856.599609", "105.000000 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Power_Pole_Conc4_Lamp_Amp", "399.000000 6.000000 10863.000000", "90.000000 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Power_Pole_Conc4_Lamp_Amp", "419.842010 6.000000 10863.599609", "90.000000 0.000000 0.000000"));
		BaseObjects.Insert( new Param3<string,vector,vector>("Land_Ruin_Shed_Closed", "379.000000 2.200000 10781.700195", "90.000000 0.000000 0.000000"));
				
		//MainBuilding spawnpoints
		MainSpawns.Insert("-5.39 -1.26 -5.46");
		MainSpawns.Insert("-7.63 -1.16 4.45");
		MainSpawns.Insert("-4.27 -0.74 5.11");
		MainSpawns.Insert("-2.29 -0.77 5.06");
		MainSpawns.Insert("-0.75 -0.77 1.12");
		MainSpawns.Insert("3.90 -1.93 5.01");
		MainSpawns.Insert("5.50 -1.81 4.8");
		MainSpawns.Insert("5.51 -1.81 6.01");
		
		//Barrack spawnpoints
		BarrackSpawns.Insert("1.41 -1.02 -3.04");
		BarrackSpawns.Insert("-1.69 -1.02 -3.08");
		BarrackSpawns.Insert("-2.19 -0.34 -0.18");
		BarrackSpawns.Insert("0.94 0.19 4.47");
		BarrackSpawns.Insert("0.87 0.19 -1.45");
		
		//Spawn Base 
		SpawnBaseObjects();
	}
	
	void SpawnBaseObjects()
	{
		//Spawn Base objects		
		for ( int i=0; i < BaseObjects.Count(); i++ )
		{
			Param3<string,vector,vector> BaseDef = BaseObjects.Get(i);
			string BaseType = BaseDef.param1;
			vector BasePos = BaseDef.param2;
			vector BaseOri = BaseDef.param3;
						
			Object BaseObject = GetGame().CreateObject( BaseType, BasePos, false, false, true );
			BaseObject.SetPosition( BasePos );
			BaseObject.SetOrientation( BaseOri );
			
			BaseObjectList.Insert( BaseObject );
		}
		
		Print("[SEM] STATICS: Norwegian Polar Research Base spawned in the western ice fields.");	
	}
	
	void SpawnCrashSite()
	{
		//Spawn wrecked Mi8 
		GetGame().GetObjectsAtPosition3D("845 -0.5 10850", 10.0, ObjectList, ObjectCargoList );
		for ( int i=0; i < ObjectList.Count(); i++ )
		{
			Object FoundObj = ObjectList.Get(i);
			if ( FoundObj.GetType() == "Wreck_UH1Y" )
			GetGame().ObjectDelete( FoundObj );
		}
		GetGame().CreateObject("land_wrecked_mi8_frozen", "845 3.3 10850" );
		//HeliCrashNPR = GetGame().CreateObject( "Wreck_UH1Y", "845 0 10850");
		//HeliCrashNPR.SetPosition("845 -0.5 10850");
	}
	
	void SpawnLoot()
	{
		Object LootEntity;
		vector spawnpoint;
		
		//Define and refresh important buildings
		Tower = BaseObjectList[0];
		Heliport = BaseObjectList[1];
		Barrack1 = BaseObjectList[2];
		Barrack2 = BaseObjectList[3];
		Barrack3 = BaseObjectList[4];
		Barrack4 = BaseObjectList[5];
		MainBuilding = BaseObjectList[6];
		
		//Spawn Canister at tower
		spawnpoint = "-3.65 6.27 2.73";
		if ( CheckSpawn( Tower.ModelToWorld( spawnpoint ) ))
		LootEntity = GetGame().CreateObject("CanisterGasoline", Tower.ModelToWorld( spawnpoint ) );
		
		//Spawn loot in barrack's
		for ( int i=2; i < 6; i++ )
		{
			Object Barrack = BaseObjectList[i];
			for ( int j=0; j < 3; j++ )
			{
				spawnpoint = Barrack.ModelToWorld( BarrackSpawns.GetRandomElement() );				
				if ( CheckSpawn( spawnpoint ))
				{
					LootEntity = GetGame().CreateObject( LootTable.GetRandomElement(), spawnpoint );
					EntityAI.Cast( LootEntity ).SetLifetime(3600);
				}
			}
		}
		
		//Spawn loot in main building
		for ( i=0; i < 4; i++ )
		{
			spawnpoint = MainBuilding.ModelToWorld( MainSpawns.GetRandomElement() );
			if ( CheckSpawn( spawnpoint ))
			{
				LootEntity = GetGame().CreateObject( LootTable.GetRandomElement(), spawnpoint );
				EntityAI.Cast( LootEntity ).SetLifetime(3600);
			}
		}
		
		//Spawn wood pile in main building
		vector WoodPilePos = "-7.67 -1.93 0.43";		
		if ( CheckSpawn( MainBuilding.ModelToWorld( WoodPilePos + "0 0.07 0.3" ) ))
		{
			for ( i=0; i < 4; i++ )
			{
				LootEntity = GetGame().CreateObject( "Firewood", MainBuilding.ModelToWorld( WoodPilePos ) );
				LootEntity.SetPosition( MainBuilding.ModelToWorld( WoodPilePos ) );
				LootEntity.SetDirection( MainBuilding.GetDirection() + "90 0 0" );
				WoodPilePos += "0 0 0.15";
				if ( i == 4 )
				WoodPilePos += "0 0.07 -0.68";
				if ( i == 8 )
				WoodPilePos += "0 0.07 -0.53";
			}	
		}
		
		Print("[SEM] STATICS: Loot spawned at Norwegian Polar Research Base.");	
	}
	
	bool CheckSpawn( vector spawnpoint )
	{
		GetGame().GetObjectsAtPosition3D( spawnpoint, 0.35, ObjectList, ObjectCargoList );
		
		if ( ObjectList.Count() > 0 )	return false;
		else return true;
	}
	
	ref TStringArray LootTable = {
		//food
		"dzn_Canteen","dzn_WaterBottle","dzn_SodaCan_Pipsi","dzn_SodaCan_Cola","dzn_SodaCan_Spite","dzn_BakedBeansCan","dzn_BakedBeansCan",
		"dzn_BakedBeansCan","dzn_PeachesCan","dzn_PeachesCan","dzn_PeachesCan","dzn_SardinesCan","dzn_SardinesCan","dzn_SardinesCan","dzn_SpaghettiCan",
		"dzn_SpaghettiCan","dzn_SpaghettiCan","dzn_TunaCan","dzn_TunaCan","dzn_TunaCan","dzn_Marmalade","dzn_Marmalade","dzn_Marmalade",
		//tools & equip
		"dzn_map_namalsk","Battery9V","CanOpener","Lockpick","NVGoggles","NVGHeadstrap","Matchbox","Hatchet","HuntingKnife","CombatKnife",
		"KitchenKnife","SparkPlug","Hacksaw","MetalWire","Spotlight","Headtorch_Grey","ElectronicRepairKit","WeaponCleaningKit","GP5GasMask",
		"GasMask","WeldingMask","LeatherSewingKit","SewingKit",
		//clothes 
		"dzn_gorka_up_winter","dzn_sumrak_up_coldw","dzn_yeger_up_coldw","dzn_yeger_up_woodl","dzn_tacticalshirt_olive_ru","dzn_tacticalshirt_tan_ru",
		"dzn_tacticalshirt_white_ru","dzn_gorka_pants_winter","dzn_sumrak_pants_coldw","dzn_yeger_pants_coldw","dzn_yeger_pants_woodl",
		"dzn_ukassvest_white","dzn_smershvest_white","dzn_smershvest_black","dzn_highcapacityvest_nac","dzn_bandana_wintercamopattern",
		"dzn_gorkahood_flat","dzn_gorkahood_autumn","dzn_gorkahood_pautrev","dzn_gorkahood_winter","dzn_sumrakhood_coldw","dzn_yegerhood_coldw",
		"dzn_yegerhood_woodl","dzn_milberet_red","dzn_milberet_blue","dzn_milberet_green","dzn_milberet_specnaz","dzn_BallisticHelmet_White",
		"dzn_GorkaHelmet_White","dzn_att_ghillie_winter","dzn_att_ghillie_tandark","dzn_ghilliebushragwinter","dzn_ghilliebushragtandark",
		"dzn_ghillietopwinter","dzn_ghillietoptandark","dzn_ghilliesuitwinter","dzn_ghilliesuittandark","dzn_ghilliehoodwinter",
		"dzn_ghilliehoodtandark","JungleBoots_Green","JungleBoots_Beige","JungleBoots_Black","JungleBoots_Brown","JungleBoots_Olive",
		"MilitaryBoots_Beige","MilitaryBoots_Brown","MilitaryBoots_Black","CombatBoots_Grey","CombatBoots_Green","CombatBoots_Black",
		"CombatBoots_Beige","TTSKOBoots","LeatherGloves_Brown","LeatherGloves_Black","LeatherGloves_Beige","TacticalGloves_Black",
		"TacticalGloves_Beige","TacticalGloves_Green","SmershVest","UKAssVest_Camo","UKAssVest_Black","UKAssVest_Khaki","UKAssVest_Olive",
		"HighCapacityVest_Black","HighCapacityVest_Olive","BDUPants","BDUJacket","TTSKOPants","TTsKOJacket_Camo","GorkaPants_Flat","GorkaPants_Autumn",
		"GorkaPants_PautRev","GorkaEJacket_Flat","GorkaEJacket_Autumn","GorkaEJacket_PautRev","MilitaryBelt","CivilianBelt",
		//bags
		"dzn_bagtortilla_white","dzn_assaultbag_winter","dzn_smershbackpack_white","dzn_smershbackpack_black","dzn_coyotebag_white",
		"dzn_alicebag_wintercamo","MountainBag_Red","MountainBag_Blue","MountainBag_Green","MountainBag_Orange","HuntingBag","AliceBag_Camo",
		"AliceBag_Black","AliceBag_Green","CoyoteBag_Brown","CoyoteBag_Green","AssaultBag_Black","AssaultBag_Ttsko","AssaultBag_Green","SmershBag",
		//weapon attachments 
		"ACOGOptic","PSO1Optic","PSO11Optic","HuntingOptic","KazuarOptic","KashtanOptic","M4_T3NRDSOptic","M68Optic","ReflexOptic",
		"FNP45_MRDSOptic","LongrangeOptic","PUScopeOptic","KobraOptic","MP5_RailHndgrd","MP5_Compensator","MP5_PlasticHndgrd",
		"MP5k_StockBttstck","M4_MPHndgrd","M4_MPBttstck","M4_RISHndgrd","M4_OEBttstck","M4_CQBBttstck","M4_Suppressor","M4_PlasticHndgrd",
		"AK_Bayonet","AK_WoodHndgrd","AK_Suppressor","AK_RailHndgrd","AK_WoodBttstck","AK_PlasticHndgrd","AK_FoldingBttstck","AK_PlasticBttstck",
		"AK74_Hndgrd","AKS74U_Bttstck","AK74_WoodBttstck",
		
		//ammo & mags 
		"Mag_MP5_30Rnd","Mag_MP5_15Rnd","Mag_STANAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_30Rnd","Mag_CMAG_20Rnd","Mag_CMAG_10Rnd","Mag_FAL_20Rnd",
		"Mag_AKM_30Rnd","Mag_AK74_30Rnd","Mag_AK101_30Rnd","Mag_AKM_Palm30Rnd","Mag_AKM_Drum75Rnd","Mag_CZ75_15Rnd","Mag_CZ61_20Rnd","Mag_CZ527_5rnd",
		"Mag_FNX45_15Rnd","Mag_VAL_20Rnd","Mag_VSS_10Rnd","Mag_SVD_10Rnd","Mag_UMP_25Rnd","Mag_1911_7Rnd","Mag_Glock_15Rnd",
		"Mag_Deagle_9rnd","Ammo_357","Ammo_9x39","Ammo_9x19","Ammo_45ACP","Ammo_762x54","Ammo_308Win","Ammo_545x39","Ammo_556x45",
		"Ammo_556x45Tracer","Ammo_308WinTracer","Ammo_762x54Tracer","Ammo_545x39Tracer","Ammo_762x39Tracer","AmmoBox_556x45_20Rnd",
		"AmmoBox_545x39_20Rnd","AmmoBox_762x54_20Rnd","AmmoBox_762x39_20Rnd","AmmoBox_357_20Rnd","AmmoBox_9x39_20Rnd","AmmoBox_9x19_25rnd",
		"AmmoBox_556x45_20Rnd","AmmoBox_556x45Tracer_20Rnd","AmmoBox_45ACP_25rnd","AmmoBox_308Win_20Rnd",
	}
}