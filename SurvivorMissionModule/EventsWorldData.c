class EventsWorldData extends SurvivorMissions
{
	const string EWD_MAP_NAME = "namalsk";
	const string EWD_SCRIPT_VERSION = "0.85";
	static ref array<string> MissionEvents = new array<string>;
	static ref array<vector> MissionPositions = new array<vector>;
	static ref array<Object> ObjectList = new array<Object>; 
	static ref array<CargoBase> ObjectCargoList = new array<CargoBase>;
	
	//scripted bases
	static ref NorwegianBase NPR_Base;
	
	void EventsWorldData()
	{				
		//Mission event																		//Mission position (absolute or BuildingPos)
		//0
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_1");						MissionPositions.Insert("6641.171875 24.529381 11312.511719");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_2");						MissionPositions.Insert("6660.210449 24.606468 11040.176758");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_3");						MissionPositions.Insert("6680.977051 24.602228 11080.224609");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_4");						MissionPositions.Insert("6670.594238 24.601273 11060.179688");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_5");						MissionPositions.Insert("6665.111816 24.499474 11211.438477");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_6");						MissionPositions.Insert("6664.359863 24.501099 11234.007813");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_7");						MissionPositions.Insert("6663.600586 24.497719 11256.595703");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_8");						MissionPositions.Insert("6652.933105 24.529490 11331.767578");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_9");						MissionPositions.Insert("6664.727539 24.529390 11351.015625");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_10"); 						MissionPositions.Insert("6732.208008 24.279499 11186.910156");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_11"); 						MissionPositions.Insert("6742.559082 24.245390 11206.942383");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_12"); 						MissionPositions.Insert("6719.016113 24.499718 11288.617188");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_13"); 						MissionPositions.Insert("6719.223145 24.507141 11311.208008");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_14"); 						MissionPositions.Insert("6719.416992 24.526489 11333.776367");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_15"); 						MissionPositions.Insert("6727.691406 24.581602 11433.598633");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_16"); 						MissionPositions.Insert("6727.787109 24.597076 11478.770508");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_17"); 						MissionPositions.Insert("6727.750488 24.597443 11456.191406");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_18"); 						MissionPositions.Insert("6797.741211 24.714455 11095.954102");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_19"); 						MissionPositions.Insert("6777.988770 24.717682 11106.911133");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_20"); 						MissionPositions.Insert("6791.347168 24.499729 11304.131836");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_21"); 						MissionPositions.Insert("6786.659668 24.609819 11427.086914");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_22"); 						MissionPositions.Insert("6796.719238 24.609692 11447.305664");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_23"); 						MissionPositions.Insert("6776.604492 24.609659 11406.875000");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_24"); 						MissionPositions.Insert("6817.482422 24.720037 11085.003906");
		MissionEvents.Insert("Apartment Vorkuta central TenSmall_25"); 						MissionPositions.Insert("6801.603027 24.499689 11324.225586");
		//25
		MissionEvents.Insert("BearHunt Airfield north Vorkuta");							MissionPositions.Insert("6213 14 9783");
		MissionEvents.Insert("BearHunt Airfield south Vorkuta");							MissionPositions.Insert("6290 25 8909");
		MissionEvents.Insert("BearHunt Alakit south Vorkuta");								MissionPositions.Insert("5826 29 10572");
		MissionEvents.Insert("BearHunt Alakit northeast Vorkuta");							MissionPositions.Insert("5875 15 10894");		
		MissionEvents.Insert("BearHunt Brensk north Vorkuta");								MissionPositions.Insert("4331 8 4841");
		MissionEvents.Insert("BearHunt Brensk_Bridge south Vorkuta");						MissionPositions.Insert("4960 12 5967");
		MissionEvents.Insert("BearHunt Brensk_Cargo_Rail northwest Vorkuta");				MissionPositions.Insert("4677 144 6403");
		MissionEvents.Insert("BearHunt Jalovisko west Vorkuta");							MissionPositions.Insert("7898 39 10694");
		MissionEvents.Insert("BearHunt Jalovisko northwest Vorkuta");						MissionPositions.Insert("8070 71 11207");
		MissionEvents.Insert("BearHunt Jalovisko north Vorkuta");							MissionPositions.Insert("8220 15 10990");
		MissionEvents.Insert("BearHunt Jalovisko south Vorkuta");							MissionPositions.Insert("8100 17 10329");
		MissionEvents.Insert("BearHunt Ledjanaja_Barracks_BK-L02 southwest Vorkuta");		MissionPositions.Insert("3295 246 6606");
		MissionEvents.Insert("BearHunt Lubjansk_Harbor southwest Vorkuta");					MissionPositions.Insert("4298 6 10978");
		MissionEvents.Insert("BearHunt Lubjansk_Military_Base_BK-T07 west Vorkuta");		MissionPositions.Insert("4232 9 10751");
		MissionEvents.Insert("BearHunt Lubjansk_Military_Base_BK-T07 south Vorkuta");		MissionPositions.Insert("4393 6 10615");
		MissionEvents.Insert("BearHunt Lubjansk_Military_Base_BK-M06 southeast Vorkuta"); 	MissionPositions.Insert("5022 13 10688");
		MissionEvents.Insert("BearHunt Nemsk southwest Vorkuta");							MissionPositions.Insert("8946 12 10044");
		MissionEvents.Insert("BearHunt Nemsk north Vorkuta");								MissionPositions.Insert("9070 12 10276");
		MissionEvents.Insert("BearHunt Norinsk southwest Vorkuta");							MissionPositions.Insert("3671 53 7315");
		MissionEvents.Insert("BearHunt Vorkuta_Refugee_Camp south Vorkuta");				MissionPositions.Insert("7319 45 10387");
		MissionEvents.Insert("BearHunt Vorkuta_Refugee_Camp north Vorkuta");				MissionPositions.Insert("7400 15 10780");
		MissionEvents.Insert("BearHunt Vorkuta_Refugee_Camp west Vorkuta");					MissionPositions.Insert("7125 40 10574");
		MissionEvents.Insert("BearHunt Sebjan_Dam east Vorkuta");							MissionPositions.Insert("5852 18 9882");
		MissionEvents.Insert("BearHunt Seraja_Mountain south Vorkuta");						MissionPositions.Insert("4168 369 6512");
		MissionEvents.Insert("BearHunt Sebjan_Refugee_Camp northwest Vorkuta");				MissionPositions.Insert("5056 57 9037");
		MissionEvents.Insert("BearHunt Sebjan_Uranium_Mine east Vorkuta");					MissionPositions.Insert("5529 116 8165");
		MissionEvents.Insert("BearHunt Sebjan_Warehouses west Vorkuta");					MissionPositions.Insert("4574 41 8930");
		MissionEvents.Insert("BearHunt Tara_Factory north Vorkuta");						MissionPositions.Insert("7714 49 9113");
		MissionEvents.Insert("BearHunt Tara_Factory east Vorkuta");							MissionPositions.Insert("8025 19 8790");
		MissionEvents.Insert("BearHunt Tara_Mountain west Vorkuta");						MissionPositions.Insert("7125 191 7007");
		MissionEvents.Insert("BearHunt Tara_Mountain east Vorkuta");						MissionPositions.Insert("7382 220 7080");
		MissionEvents.Insert("BearHunt Tara_Sawmill north Vorkuta");						MissionPositions.Insert("6960 53 6056");
		//57
		MissionEvents.Insert("Camp Airfield_Factory south MedTent_1");						MissionPositions.Insert("6485 27 9100");
		MissionEvents.Insert("Camp Jalovisko northwest MedTent_1");							MissionPositions.Insert("8238 21 11101");
		MissionEvents.Insert("Camp Jalovisko northwest MedTent_1");							MissionPositions.Insert("8606 9 10940");		
		MissionEvents.Insert("Camp Lubjansk_Military_Base_BK-T07 north MedTent_1");			MissionPositions.Insert("4370 15 10901");
		MissionEvents.Insert("Camp Lubjansk_Military_Base_BK-T07 east MedTent_1");			MissionPositions.Insert("4497 18 10713");
		MissionEvents.Insert("Camp Lubjansk_Military_Base_BK-M06 northwest MedTent_1");		MissionPositions.Insert("4693 21 10923");	
		MissionEvents.Insert("Camp Nemsk_Lighthouse northwest MedTent_1");					MissionPositions.Insert("8882 15 10015");
		MissionEvents.Insert("Camp Norisnk_C130_crashsite north MedTent_1");				MissionPositions.Insert("3267 118 7762");	
		MissionEvents.Insert("Camp Sebjan_Dam southwest MedTent_1");						MissionPositions.Insert("5555 20 9764");
		MissionEvents.Insert("Camp Sebjan_Dam east MedTent_1");								MissionPositions.Insert("5845 13 9920");
		MissionEvents.Insert("Camp Sebjan_Factory north MedTent_1");						MissionPositions.Insert("5795 34 8933");
		MissionEvents.Insert("Camp Sebjan's_Factory ontheroof MedTent_1");					MissionPositions.Insert("5803 66 8644");
		MissionEvents.Insert("Camp Sebjan_Refugee_Camp southwest MedTent_1");				MissionPositions.Insert("5062 70 8816");
		MissionEvents.Insert("Camp Sebjan_Ruins central MedTent_1");						MissionPositions.Insert("5189 31 8543");	
		MissionEvents.Insert("Camp Tara_Factory southwest MedTent_1");						MissionPositions.Insert("7494 61 8629");
		MissionEvents.Insert("Camp Tara_Factory northwest MedTent_1");						MissionPositions.Insert("7403 29 8859");
		MissionEvents.Insert("Camp TaraMedCenter ontheroof MedTent_1");						MissionPositions.Insert("7290 99 7951");
		MissionEvents.Insert("Camp Westside_Outpost_BK-T12 west MedTent_1");				MissionPositions.Insert("3831 7 9240");
		//83
		MissionEvents.Insert("Horde Athena_Research_Institute central Industrial_1");		MissionPositions.Insert("4269.9 101 8063.8");
		MissionEvents.Insert("Horde Athena_Research_Institute central Industrial_2");		MissionPositions.Insert("4325 91 8082.6");
		MissionEvents.Insert("Horde Athena_Research_Institute central Industrial_3");		MissionPositions.Insert("4325.8 78.2 8127.5");
		MissionEvents.Insert("Horde Brensk central Residential_1");							MissionPositions.Insert("4295.3 4.9 4780.3");
		MissionEvents.Insert("Horde Brensk central Residential_2");							MissionPositions.Insert("4343.5 4.6 4792.4");
		MissionEvents.Insert("Horde Jalovisko west Residential_1");							MissionPositions.Insert("8089.7 18.6 10834.7");
		MissionEvents.Insert("Horde Jalovisko west Residential_2");							MissionPositions.Insert("8095.9 15.8 10863.8");
		MissionEvents.Insert("Horde Jalovisko west Residential_3");							MissionPositions.Insert("8126.1 20.5 10847.5");
		MissionEvents.Insert("Horde Jalovisko west Residential_4");							MissionPositions.Insert("8144.4 16 10867");
		MissionEvents.Insert("Horde Jalovisko west Residential_5");							MissionPositions.Insert("8150.6 15.5 10816.2");
		MissionEvents.Insert("Horde Jalovisko west Residential_6");							MissionPositions.Insert("8173.6 15.9 10885.4");		
		MissionEvents.Insert("Horde Lubjansk_Village central Residential_1");				MissionPositions.Insert("4507.2 16 10947.9");
		MissionEvents.Insert("Horde Lubjansk_Village central Residential_1");				MissionPositions.Insert("4507.2 16 10947.9");
		MissionEvents.Insert("Horde Lubjansk_Village central Residential_1");				MissionPositions.Insert("4507.2 16 10947.9");
		MissionEvents.Insert("Horde Lubjansk_Village central Residential_1");				MissionPositions.Insert("4507.2 16 10947.9");		
		MissionEvents.Insert("Horde Nemsk central Residential_1");							MissionPositions.Insert("9013.8 9.7 10119.1");
		MissionEvents.Insert("Horde Nemsk central Residential_2");							MissionPositions.Insert("9030 12.5 10101.6");
		MissionEvents.Insert("Horde Nemsk central Residential_3");							MissionPositions.Insert("9031.1 9.4 10115");
		MissionEvents.Insert("Horde Nemsk central Residential_4");							MissionPositions.Insert("9089.6 8.3 10090.5");	
		MissionEvents.Insert("Horde Sebjan_Ruins central Residential_1");					MissionPositions.Insert("5189.9 35 8560.4");
		MissionEvents.Insert("Horde Sebjan_Ruins central Residential_2");					MissionPositions.Insert("5196.4 35.9 8524.3");
		MissionEvents.Insert("Horde Sebjan_Ruins central Residential_3");					MissionPositions.Insert("5207.3 34.8 8548.2");
		MissionEvents.Insert("Horde Sebjan_Ruins central Residential_4");					MissionPositions.Insert("5228.9 35.5 8590.3");
		MissionEvents.Insert("Horde Sebjan_Ruins north Residential_5");						MissionPositions.Insert("5259 37.3 8607.9");
		MissionEvents.Insert("Horde Sebjan_Ruins north Residential_6");						MissionPositions.Insert("5271 38.5 8657.1");
		MissionEvents.Insert("Horde Sebjan_Warehouses central Residential_1");				MissionPositions.Insert("4702.2 23.6 8930.3");
		MissionEvents.Insert("Horde Sebjan_Warehouses central Residential_2");				MissionPositions.Insert("4692.9 27.7 8907.9");
		MissionEvents.Insert("Horde Tara_Mediacal_Center central store");					MissionPositions.Insert("7243.1 85.9 7942.3");
		MissionEvents.Insert("Horde Tara_Mediacal_Center central office_1");				MissionPositions.Insert("7299.6 90.2 7953.9");
		MissionEvents.Insert("Horde Tara_Mediacal_Center central office_2");				MissionPositions.Insert("7329.8 87.1 8000.3");
		//113
		MissionEvents.Insert("PlaneCrash Airfield south 179");								MissionPositions.Insert("6247.5 21.2 9226.1");
		MissionEvents.Insert("PlaneCrash Airfield north 359");								MissionPositions.Insert("6247.5 21.2 9226.1");
		MissionEvents.Insert("PlaneCrash Brensk east 55");									MissionPositions.Insert("4573.9 5.6 4815.7");
		MissionEvents.Insert("PlaneCrash Jalovisko northwest 290");							MissionPositions.Insert("7845.5 15.5 10993.5");
		MissionEvents.Insert("PlaneCrash Jalovisko southeast 129");							MissionPositions.Insert("8660.9 14.7 10591.1");
		MissionEvents.Insert("PlaneCrash Jalovisko southeast 198");							MissionPositions.Insert("8351.5 15.1 10300.3");
		MissionEvents.Insert("PlaneCrash Westice_Outpost_BK-T08 north 81");					MissionPositions.Insert("3828 2 10711.2");
		MissionEvents.Insert("PlaneCrash Westice_Outpost_BK-T08 west 45");					MissionPositions.Insert("3561.7 2 9812");
		MissionEvents.Insert("PlaneCrash Westice_Outpost_BK-T08 east 234");					MissionPositions.Insert("4515.7 9.2 9959.3");
		MissionEvents.Insert("PlaneCrash Lubjansk_Military_Base_BK-T07 southeast 5");		MissionPositions.Insert("4662.9 22.6 10598.5");
		MissionEvents.Insert("PlaneCrash Lubjansk_Military_Base_BK-M06 northeast 8");		MissionPositions.Insert("5003.3 10.2 11221.7");
		MissionEvents.Insert("PlaneCrash Sebjan_Dam west 266");								MissionPositions.Insert("5211.5 16.3 9898.9");
		MissionEvents.Insert("PlaneCrash Sebjan_Dam northeast 48");							MissionPositions.Insert("5845.5 24 10168.8");
		MissionEvents.Insert("PlaneCrash Sebjan_Factory northwest 219");					MissionPositions.Insert("5725.2 36.2 8871.4");
		MissionEvents.Insert("PlaneCrash Sebjan_Refugee_Camp northeast 83");				MissionPositions.Insert("5398.3 62.9 9090.4");
		MissionEvents.Insert("PlaneCrash Sebjan_Uranium_Mine east 238");					MissionPositions.Insert("5512 117.2 8263.4");
		MissionEvents.Insert("PlaneCrash Tara_Bridge northeast 183");						MissionPositions.Insert("6737.9 10.5 6134.8");
		MissionEvents.Insert("PlaneCrash Vorkuta_Beach north 265");							MissionPositions.Insert("6856.3 2 12783.3");
		MissionEvents.Insert("PlaneCrash Vorkuta_Beach south 198");							MissionPositions.Insert("6864.8 17.5 10545.5.3");
		//132
		MissionEvents.Insert("Shrooms Airfield west TaraMedCenter");						MissionPositions.Insert("6108 17 9345");
		MissionEvents.Insert("Shrooms Airfield_Factory south TaraMedCenter");				MissionPositions.Insert("6481 27 9098");
		MissionEvents.Insert("Shrooms Alakit north TaraMedCenter");							MissionPositions.Insert("5770 19 10856");
		MissionEvents.Insert("Shrooms Alakit northeast TaraMedCenter");						MissionPositions.Insert("5954 23 10847");
		MissionEvents.Insert("Shrooms Brensk west TaraMedCenter");							MissionPositions.Insert("4181 8 4821");
		MissionEvents.Insert("Shrooms Brensk north TaraMedCenter");							MissionPositions.Insert("4290 21 4906");
		MissionEvents.Insert("Shrooms Jalovisko southwest TaraMedCenter");					MissionPositions.Insert("7926 21 10461");
		MissionEvents.Insert("Shrooms Jalovisko north TaraMedCenter");						MissionPositions.Insert("8215 15 11013");
		MissionEvents.Insert("Shrooms Lubjansk_Village west TaraMedCenter");				MissionPositions.Insert("4297 11 11010");
		MissionEvents.Insert("Shrooms Lubjansk_Village east TaraMedCenter");				MissionPositions.Insert("4644 17 10972");		
		MissionEvents.Insert("Shrooms Sebjan_Factory northeast TaraMedCenter");				MissionPositions.Insert("5943 51 8802");
		MissionEvents.Insert("Shrooms Sebjan_Warehouses southwest TaraMedCenter");			MissionPositions.Insert("4596 27 8868");
		MissionEvents.Insert("Shrooms Sebjan_Uranium_Mine east TaraMedCenter");				MissionPositions.Insert("5381 99 8106");
		MissionEvents.Insert("Shrooms Tara_Sawmill north TaraMedCenter");					MissionPositions.Insert("7057 70 6047");
		MissionEvents.Insert("Shrooms Tara_Bridge_Pond near TaraMedCenter");				MissionPositions.Insert("6107 7 5752");
		MissionEvents.Insert("Shrooms Tara_Bridge_Pond north TaraMedCenter");				MissionPositions.Insert("6038 16 5993");
		MissionEvents.Insert("Shrooms Vorkuta_Refugee_Camp northwest TaraMedCenter");		MissionPositions.Insert("7242 40 10602");
		MissionEvents.Insert("Shrooms Vorkuta_Refugee_Camp southeast TaraMedCenter");		MissionPositions.Insert("7412 43 10386");
		//150
		
		// ***Add new mission events below this line	
		//example: MissionEvents.Insert("MyNewMissionType Location LocationDir additionalParam");	MissionPositions.Insert("6869.6 350.3 10277.7");
	}
	
	static void BuildInstance()
	{
		//check for mission type to instantiate mission
		if ( m_MissionType == "Apartment" )		m_MissionInstance = new ApartmentMission();
		if ( m_MissionType == "BearHunt" )		m_MissionInstance = new BearHuntMission();	
		if ( m_MissionType == "Camp" )			m_MissionInstance = new CampMission();
		if ( m_MissionType == "Horde" )			m_MissionInstance = new HordeMission();
		if ( m_MissionType == "PlaneCrash" )	m_MissionInstance = new PlaneCrashMission();			
		// if ( m_MissionType == "Shrooms" )		m_MissionInstance = new ShroomsMission();
		// ***Add new mission types below this line when new mission events were defined 
		//example: if ( ( m_MissionType == "MyNewMissionType" )		m_MissionInstance = new MyNewMission();
	}
		
	static bool GetBuildingsAtLoc( string MBuilding, string MLocation, out array<vector> BuildingPosList )
	{
		//Get positions of a unique mission building by the town/village name
		BuildingPosList = new array<vector>;
		
		if ( MBuilding == "Land_City_Hospital")
		{
			if ( MLocation == "TaraMedCenter")
			{
				BuildingPosList.Insert("7268.459473 91.946960 7994.121094");
				BuildingPosList.Insert("7304.512207 92.215172 7935.343262");
			}
			else return false;			//No match by location						
		}		
		else if ( MBuilding == "Land_City_School")
		{
			if ( MLocation == "Vorkuta")					BuildingPosList.Insert("6816.391113 20.800653 11227.292969");

			else return false;			//No match by location	
		}
		else return false;		//No match by building type. Keep this line after last building check!
		
		return true;
	}
	
	static void CheckEWD()
	{
		int ErrorCount = 0;
		
		for ( int i=0; i < MissionPositions.Count(); i++)
		{
			string Description[4];
			string EventName = MissionEvents.Get(i);
			vector Position = MissionPositions.Get(i);
			
			EventName.ParseString( Description );
			string Type = Description[0];
			string Location = Description[1];
			string LocDirection = Description[2];
			string Secondary = Description[3];
			
			//check for primary MissionBuilding, exclude missions with no primary MissionBuilding 
			if ( !PrimaryMissionCHK( Type, Position, i )) 
			{
				ErrorCount++;
				Print("[SEM] EWD Check additional mission Info : Type: "+ Type +" mission, location: "+ LocDirection +" of "+ Location +", Secondary mission:"+ Secondary );
			}
			//check for secondary MissionBuilding, exclude missions with no secondary MissionBuilding
			else if ( !SecondaryMissionCHK( Type, Secondary, i )) 
			{
				ErrorCount++;
				Print("[SEM] EWD Check additional mission Info : Type: "+ Type +" mission, location: "+ LocDirection +" of "+ Location +", Secondary mission:"+ Secondary );
			}						
		}
		if ( ErrorCount == 0 ) Print("[SEM] EWD check...OK");
		else Print("[SEM] EWD Check Summary: "+ ErrorCount +" missions have incorrect EventsWorldData. Check coordinates in debug mode!");	
	}
	
	static bool PrimaryMissionCHK( string type, vector position , int nr )
	{
		//List all mission types with no prim. MissionBuilding here!
		ref array<string> ExcludedTypes = new array<string>;
		ExcludedTypes.InsertArray( {"Camp","Shrooms","BearHunt","PlaneCrash","Horde"} );	
		string building;
		bool BuildingFound;
				
		for ( int i=0; i < ExcludedTypes.Count(); i++)	{ if ( type == ExcludedTypes.Get(i) ) return true;}
		
		//Add new mission type and building type for primary mission here!
		if ( type == "Apartment")					building = "Land_Tenement_Small";
		else if ( type == "CityMall")				building = "Land_City_Store";
		else if ( type == "FreePigs")				building = "Land_Farm_CowshedA";
		else if ( type == "Transport")				building = "Land_Garage_Row_Small";
		else if ( type == "UrbanMall")				building = "Land_City_Store_WithStairs";
		else 
		{
			Print("[SEM] EWD Check WARNING : Mission "+ nr +" - Mission type "+ type +" is undefined in EventsWorldData!");
			return false;
		}
				
		BuildingFound = false;
		
		GetGame().GetObjectsAtPosition( position, 1.0, ObjectList, ObjectCargoList);
		for ( int j=0; j < ObjectList.Count(); j++)
		{
			Object FoundObject = ObjectList.Get(j);
			if ( FoundObject.GetType() != building )
			continue;
			else 
			{
				BuildingFound = true;
				break;
			}						
		}
		if ( !BuildingFound ) 
		{
			Print("[SEM] EWD Check WARNING :: Mission "+ nr +" - Can't find "+ building +" @ "+ position );
			return false;		
		}
		else return true;		
	}	
	
	static bool SecondaryMissionCHK( string type, string location, int nr )
	{
		//List all mission types with no sec. MissionBuilding here!
		ref array<string> ExcludedTypes = new array<string>;
		ExcludedTypes.InsertArray( {"Apartment","Camp","PlaneCrash","Horde"} );
		
		ref array<vector> ExtendedPosList = new array<vector>;
		string building;
		bool BuildingFound;
		
		for ( int i=0; i < ExcludedTypes.Count(); i++)	{ if ( type == ExcludedTypes.Get(i) ) return true;}
		
		//Add new mission type and building type for secondary mission here!
		if ( type == "BearHunt")					building = "Land_City_School";
		else if ( type == "CityMall")				building = "Land_Village_PoliceStation";
		else if ( type == "FreePigs")				building = "Land_Misc_TrailRoof_Small";
		// else if ( type == "Shrooms")				building = "Land_City_Hospital";
		else if ( type == "Transport")				building = "Land_FuelStation_Build";
		else if ( type == "UrbanMall")				building = "Land_City_PoliceStation";
		else
		{
			Print("[SEM] EWD Check WARNING :: Mission "+ nr +" - Mission type "+ type +" is undefined in EventsWorldData!");
			return false;
		}
		
		if ( GetBuildingsAtLoc( building, location, ExtendedPosList ))
		{
			for ( int k=0; k < ExtendedPosList.Count(); k++)
			{
				BuildingFound = false;
				
				vector pos = ExtendedPosList.Get(k);
				
				GetGame().GetObjectsAtPosition( pos, 1.0, ObjectList, ObjectCargoList);
				for ( int j=0; j < ObjectList.Count(); j++)
				{
					Object FoundObject = ObjectList.Get(j);
					if ( FoundObject.GetType() != building )
					continue;
					else 
					{
						BuildingFound = true;
						break;
					}							
				}
				if ( !BuildingFound ) 
				{
					Print("[SEM] EWD Check WARNING :: Mission "+ nr +" - Can't check back "+ building +" at position: "+ pos );								
					return false;
				}
			}
			return true;			
		}
		else 
		{
			Print("[SEM] EWD Check WARNING :: Mission "+ nr +" - Can't check back "+ building +" at location: "+ location );
			return false;
		}
	}
	
	static void BuildStatics()
	{
		//Create Norwegian Polar Research Base & start loot cycle
		NPR_Base = new NorwegianBase();
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( NPR_Base.SpawnLoot, NPR_Base.LootCycleTime * 60000, true );
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( NPR_Base.SpawnCrashSite, 120000 );
	}
	
	static void ShowDebugInfo( PlayerBase player)
	{
		//Display as server message to player: if found, Modelvector & buildingtype else actual position of player
		Param1<string> Msg1;
		ref array<Object> OBJLST1 = new array<Object>;
		ref array<CargoBase> PROXYLST1 = new array<CargoBase>;
			
		GetGame().GetObjectsAtPosition( player.GetPosition() , 15.0 , OBJLST1 , PROXYLST1 );		
		for ( int j = 0 ; j < OBJLST1.Count(); j++ )
		{ 
			Object FoundObject = OBJLST1.Get(j);
			if (FoundObject.GetType() == "Land_Medical_Tent_Big") 
			{
				Msg1 = new Param1<string> ("Medical_Tent_Big, Pos.: " + FoundObject.GetPosition().ToString() + " Modelvector: " + (FoundObject.WorldToModel( player.GetPosition())).ToString());
				GetGame().RPCSingleParam( player, ERPCs.RPC_USER_ACTION_MESSAGE, Msg1, true, player.GetIdentity());
				break;
			}
			else if ( FoundObject.GetType().Contains("Land_") || FoundObject.GetType().Contains("land_") )
			{
				Msg1 = new Param1<string> ( FoundObject.GetType() +", Pos.: " + FoundObject.GetPosition().ToString() + " Modelvector: " + (FoundObject.WorldToModel( player.GetPosition())).ToString());
				GetGame().RPCSingleParam( player, ERPCs.RPC_USER_ACTION_MESSAGE, Msg1, true, player.GetIdentity());
				//break;
			}									
		}
		
		if ( j == OBJLST1.Count() )
		{
			Msg1 = new Param1<string> ("My position is: " + player.GetPosition().ToString() );
			GetGame().RPCSingleParam( player, ERPCs.RPC_USER_ACTION_MESSAGE, Msg1, true, player.GetIdentity());
			
			vector ori = player.GetOrientation();
			float heading = ori[0];
			if ( heading < 0 ) heading += 360;
			
			Msg1 = new Param1<string> ("Heading: "+ heading.ToString() +"°" );
			GetGame().RPCSingleParam( player, ERPCs.RPC_USER_ACTION_MESSAGE, Msg1, true, player.GetIdentity());			
			j = 0;
		}
		
		if ( MissionSettings.Opt_RPmode )
		{
			Msg1 = new Param1<string> ("Actual RP mission is " + m_actualRPMission +". "+ m_MissionDescription[0] +" mission "+ m_MissionDescription[2] +" of "+ m_MissionDescription[1] +", extended: "+ m_MissionDescription[3]);
			GetGame().RPCSingleParam( player, ERPCs.RPC_USER_ACTION_MESSAGE, Msg1, true, player.GetIdentity());
		}			
	}
	
	static void RCMapByBuilding( string MBuilding )
	{
		//Runs a raycast from the middle of the map and prints all buildings of desired type 
		ref array<Object> Objects = new array<Object>;
		ref array<CargoBase> ObjectCargos = new array<CargoBase>;
		float vertex;
		vector Center = "6400 0 6400";		//Namalsk terrain center position
				
		if ( Center[0] < Center[2] ) vertex = Center[2];
		else vertex = Center[0];
		
		Print("[SEM] DEBUG MODE: Map wide raycast for:  "+ MBuilding );	
		
		float Rad = vertex * 1.414214;
				
		Print("[SEM] Map: "+ GetGame().GetWorldName() +" Center: "+ Center +", Radius: "+ Rad ); 
		 
		GetGame().GetObjectsAtPosition( Center, Rad, Objects, ObjectCargos );
		for ( int i=0; i < Objects.Count(); i++ )
		{
			Object FoundObject = Objects.Get(i);
			if ( FoundObject && FoundObject.GetType() == MBuilding )
			{
				Print("[SEM] Found building "+ MBuilding +" @ "+ FoundObject.GetPosition().ToString() );
			}
		}
		Print("[SEM] DEBUG MODE: Map wide raycast END");		
	}

	//BotMission functions
	static vector GetMissionPosition() { return m_MissionPosition; }
	//static void AddExtMissionAI( notnull SurvivorBotBase MissionBot ) {	m_MissionAIs.Insert( Object.Cast( MissionBot ) ); }
}