class ShroomsMission extends SurvivorMissions
{
	//Mission related entities
	ItemBase MissionObject;
	Object MissionBuilding;

	//Mission parameters
	int ReqShroomsCount = 10;				//pieces, requested mushroom amount
	int ExtendedTimout = 1800;				//seconds, mission duration time for extended mission
	int MsgDlyFinish = 60;					//seconds, message delay time after player has finished mission
	
	//Mission containers
	ref array<vector> ExtendedPosList = new array<vector>;
	ref array<vector> Spawnpoints = new array<vector>;
	ref array<vector> InfectedSpawns = new array<vector>;
	ref array<string> InfectedTypes = new array<string>;
	
	//Mission variables 
	string SurvivorName;		
	string SurvivorExtName;
	
	bool IsExtended() return true;
	
	void ShroomsMission()
	{	
		//Select primary mission
		m_MissionExtended = true;
				
		//Mission timeout
		m_MissionTimeout = 2700;			//seconds, mission max duration time
		
		//Mission zones
		m_MissionZoneOuterRadius = 70.0;	//meters (!Do not set lower than 200m), mission activation distance
		m_MissionZoneInnerRadius = 30.0;	//meters (!Do not set outside of 1-5m), mission finishing distance to target object
				
		//Mission informant
		m_MissionInformant = "Dr. Legasov";
	
		//Mission person names
		TStringArray SurvivorNames = {"Yuri", "Michail", "Boris", "Valeri", "Anatoli", "Ivan", "Alexej", "Dimitrij", "Sergej", "Nikolai"};
		SurvivorName = SurvivorNames.GetRandomElement();
		TStringArray SurvivorExtNames = {"Dr. Tamarova", "Dr. Lorzinski", "Dr. Blosmanova", "Dr. Haidenau", "Dr. Gabarin", "Dr. Sloskova", "Dr. Belzin", "Dr. Homyuk", "Dr. Trademzyuk", "Dr. Jankarova"};
		SurvivorExtName = SurvivorExtNames.GetRandomElement();
		
		//Set mission messages for primary mission
		m_MissionMessage1 = SurvivorName +", a survivor i met a few days ago told me that there are some places around here with numerous occurrencies of a special mushroom. It's classification name is 'Psilocybe semilanceata'.";
		m_MissionMessage2 = "At the moment i am experimenting with the containing psychoactive substance Psilocybin on infected wild animals. The animals show interesting behaviors after 30 minutes of the oral intake. I can't say much about it yet, but for my experiments I need more mushrooms.";
		m_MissionMessage3 = SurvivorName +" said that he found some of those anywhere\n** "+ m_MissionLocationDir +" of "+ m_MissionLocation +" **\nI need "+ ReqShroomsCount +" more pieces of it. The mushrooms are very small. I recommend using a mushroom encyclopedia for possible occurrencies!";
		
		//Spawnpoints for MissionObject for secondary mission
		Spawnpoints.Insert("-20.2900 -6.6398 0.7559");
		Spawnpoints.Insert("-20.2568 -6.6398 5.2510");
		Spawnpoints.Insert("-15.2871 -6.6398 5.0928");
		Spawnpoints.Insert("-10.0518 -6.6401 8.1748");
		Spawnpoints.Insert("-8.4160 -6.6398 7.6533");
		Spawnpoints.Insert("-4.0557 -6.6398 7.9033");
				
		//Infected spawnpoints for secondary mission
		InfectedSpawns.Insert("-6.3779 -7.3111 1.6016");
		InfectedSpawns.Insert("-12.0635 -7.3111 -2.3115");
		InfectedSpawns.Insert("0.5469 -7.3111 -1.01953");
		InfectedSpawns.Insert("-2.1709 -7.3111 -0.9775");
		InfectedSpawns.Insert("-16.0303 -7.3111 -2.0146");
		InfectedSpawns.Insert("17.8955 -7.3067 4.6143");
		InfectedSpawns.Insert("17.6504 -3.5781 -0.2275");
		//...outside MissionBuilding 
		InfectedSpawns.Insert("-17.0156 -7.6364 -9.7158");
		InfectedSpawns.Insert("-7.4268 -7.6066 -11.7314");
		InfectedSpawns.Insert("0.8662 -7.6027 -9.7480");
		InfectedSpawns.Insert("10.6084 -7.6134 -8.6611");
		InfectedSpawns.Insert("18.0771 -7.5431 -9.1602");
		
		//Infected types for secondary mission position
		//Male												//Female
		InfectedTypes.Insert("ZmbM_CitizenASkinny_Brown");	InfectedTypes.Insert("ZmbF_JournalistNormal_White");
		InfectedTypes.Insert("ZmbM_priestPopSkinny");		InfectedTypes.Insert("ZmbF_Clerk_Normal_White");
		InfectedTypes.Insert("ZmbM_HermitSkinny_Beige");	InfectedTypes.Insert("ZmbF_CitizenANormal_Blue");
		InfectedTypes.Insert("ZmbM_CitizenBFat_Red");		InfectedTypes.Insert("ZmbF_CitizenBSkinny");
		InfectedTypes.Insert("ZmbM_FishermanOld_Green");	InfectedTypes.Insert("ZmbF_HikerSkinny_Grey");
		InfectedTypes.Insert("ZmbM_HunterOld_Autumn");		InfectedTypes.Insert("ZmbF_SurvivorNormal_Orange");
		InfectedTypes.Insert("ZmbM_CitizenBFat_Blue");		InfectedTypes.Insert("ZmbF_HikerSkinny_Green");
		InfectedTypes.Insert("ZmbM_MotobikerFat_Black");	InfectedTypes.Insert("ZmbF_JoggerSkinny_Green");
		InfectedTypes.Insert("ZmbM_JoggerSkinny_Red");		InfectedTypes.Insert("ZmbF_SkaterYoung_Striped");
		InfectedTypes.Insert("ZmbM_MechanicSkinny_Grey");	InfectedTypes.Insert("ZmbF_BlueCollarFat_Red");
		InfectedTypes.Insert("ZmbM_HandymanNormal_Green");	InfectedTypes.Insert("ZmbF_MechanicNormal_Beige");
		InfectedTypes.Insert("ZmbM_HeavyIndustryWorker");	InfectedTypes.Insert("ZmbF_PatientOld");
		InfectedTypes.Insert("ZmbM_Jacket_black");			InfectedTypes.Insert("ZmbF_ShortSkirt_beige");
		InfectedTypes.Insert("ZmbM_Jacket_stripes");		InfectedTypes.Insert("ZmbF_VillagerOld_Red");
		InfectedTypes.Insert("ZmbM_HikerSkinny_Blue");		InfectedTypes.Insert("ZmbF_JoggerSkinny_Red");
		InfectedTypes.Insert("ZmbM_HikerSkinny_Yellow");	InfectedTypes.Insert("ZmbF_MilkMaidOld_Beige");
		InfectedTypes.Insert("ZmbM_PolicemanFat");			InfectedTypes.Insert("ZmbF_VillagerOld_Green");
		InfectedTypes.Insert("ZmbM_PatrolNormal_Summer");	InfectedTypes.Insert("ZmbF_ShortSkirt_yellow");
		InfectedTypes.Insert("ZmbM_JoggerSkinny_Blue");		InfectedTypes.Insert("ZmbF_NurseFat");
		InfectedTypes.Insert("ZmbM_VillagerOld_White");		InfectedTypes.Insert("ZmbF_PoliceWomanNormal");
		InfectedTypes.Insert("ZmbM_SkaterYoung_Brown");		InfectedTypes.Insert("ZmbF_HikerSkinny_Blue");
		InfectedTypes.Insert("ZmbM_MechanicSkinny_Green");	InfectedTypes.Insert("ZmbF_ParamedicNormal_Green");
		InfectedTypes.Insert("ZmbM_DoctorFat");				InfectedTypes.Insert("ZmbF_JournalistNormal_Red");
		InfectedTypes.Insert("ZmbM_PatientSkinny");			InfectedTypes.Insert("ZmbF_SurvivorNormal_White");
		InfectedTypes.Insert("ZmbM_ClerkFat_Brown");		InfectedTypes.Insert("ZmbF_JoggerSkinny_Brown");
		InfectedTypes.Insert("ZmbM_ClerkFat_White");		InfectedTypes.Insert("ZmbF_MechanicNormal_Grey");
		InfectedTypes.Insert("ZmbM_Jacket_magenta");		InfectedTypes.Insert("ZmbF_BlueCollarFat_Green");
		InfectedTypes.Insert("ZmbM_PolicemanSpecForce");	InfectedTypes.Insert("ZmbF_DoctorSkinny");		
	}
	
	void ~ShroomsMission()
	{	
		//Despawn all remaining objects
		if ( m_MissionObjects )
		{	
			Print("[SMM] Despawning "+ m_MissionObjects.Count() +" mission objects from old mission...");		
			for ( int i = 0; i < m_MissionObjects.Count(); i++ )
			{
				if ( !m_MissionObjects.Get(i) ) continue;
				else GetGame().ObjectDelete( m_MissionObjects.Get(i) );		
			}
			m_MissionObjects.Clear();
		}
		
		//Delete mission AI's
		if ( m_MissionAIs )
		{
			if ( m_MissionAIs.Count() > 0 )
			{
				Print("[SMM] Despawning "+ m_MissionAIs.Count() +" mission AI's from old mission...");
				for ( int k = 0; k < m_MissionAIs.Count(); k++ )
				{
					GetGame().ObjectDelete( m_MissionAIs.Get(k) );
				}
				m_MissionAIs.Clear();			
			}
			else Print("[SMM] No mission AI's to despawn.");
		}
		
		//Delete PlayersInZone list & reset container takeaway
		if ( m_PlayersInZone )	m_PlayersInZone.Clear();
		if ( m_ContainerWasTaken ) m_ContainerWasTaken = false;
	}
	
	void SpawnContainer()
	{
		MissionObject =  ItemBase.Cast( GetGame().CreateObject( "SmallProtectorCase", m_MissionPosition ));
		m_MissionObjects.InsertAt( MissionObject, 0); 		
	}
	
	void SpawnRewards()
	{
		//new MissionObject after deleting protector case
		MissionObject = ItemBase.Cast( GetGame().CreateObject( "MountainBag_Green", m_MissionPosition ));
		
		//Get random loadout 
		int selectedLoadout = Math.RandomIntInclusive(0,12);	//!Change randomization limit after adding new loadouts!
		
		//Spawn selected loadout items in mission object
		EntityAI weapon;
								
		if (selectedLoadout == 0)
		{
			weapon = MissionObject.GetInventory().CreateInInventory("TTC_M4Tac_Black");
				weapon.GetInventory().CreateAttachment("M4_MPBttstck");
				weapon.GetInventory().CreateAttachment("M4_Suppressor");
				weapon.GetInventory().CreateAttachment("ACOGOptic");
			MissionObject.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_556x45Tracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_556x45Tracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("HuntingKnife");
			MissionObject.GetInventory().CreateInInventory("BakedBeansCan");
			MissionObject.GetInventory().CreateInInventory("Canteen");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
			MissionObject.GetInventory().CreateInInventory("Collectable_SmartPhone_Blue");
		}
		if (selectedLoadout == 1)
		{
			weapon = MissionObject.GetInventory().CreateInInventory("SVD");
				weapon.GetInventory().CreateAttachment("PSO11Optic");
			MissionObject.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
			MissionObject.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
			MissionObject.GetInventory().CreateInInventory("Ammo_762x54");
			MissionObject.GetInventory().CreateInInventory("Ammo_762x54");
			MissionObject.GetInventory().CreateInInventory("CanOpener");
			MissionObject.GetInventory().CreateInInventory("PeachesCan");
			MissionObject.GetInventory().CreateInInventory("WaterBottle"); 
			MissionObject.GetInventory().CreateInInventory("Battery9V");
			MissionObject.GetInventory().CreateInInventory("Collectable_SmartPhone_Green");
		}
		if (selectedLoadout == 2)
		{
			weapon = MissionObject.GetInventory().CreateInInventory("TTCSR25_OD");
				weapon.GetInventory().CreateAttachment("TF_M4_FABDGLCoreBttstck");
				weapon.GetInventory().CreateAttachment("TTC_308Stanag");
				weapon.GetInventory().CreateAttachment("ACOGOptic");
			MissionObject.GetInventory().CreateInInventory("TTC_308Stanag");
			MissionObject.GetInventory().CreateInInventory("TTC_308Stanag");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_308WinTracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_308WinTracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("CanOpener");
			MissionObject.GetInventory().CreateInInventory("PeachesCan");
			MissionObject.GetInventory().CreateInInventory("Canteen");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
			MissionObject.GetInventory().CreateInInventory("Collectable_SmartPhone_Red");
		}
		if (selectedLoadout == 3)
		{
			weapon = MissionObject.GetInventory().CreateInInventory("TTC_FAL");
				weapon.GetInventory().CreateAttachment("TTC_FAL_Wood_Hndgrd");
				weapon.GetInventory().CreateAttachment("TTC_FAL_Wood_Bttstck");
				weapon.GetInventory().CreateAttachment("TTC_EotechVudu_Optic");
			MissionObject.GetInventory().CreateInInventory("TTC_FAL_Magazine");
			MissionObject.GetInventory().CreateInInventory("TTC_FAL_Magazine");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_308WinTracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_308WinTracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("MilitaryBelt");	
			MissionObject.GetInventory().CreateInInventory("M18SmokeGrenade_Yellow");	
			MissionObject.GetInventory().CreateInInventory("TacticalBaconCan");
			MissionObject.GetInventory().CreateInInventory("HuntingKnife");
			MissionObject.GetInventory().CreateInInventory("Collectable_GameBoy_Tetris");
		}	
		if (selectedLoadout == 4)
		{
			weapon = MissionObject.GetInventory().CreateInInventory("TTC_HK416Comp");
				weapon.GetInventory().CreateAttachment("TTC_Universal_Suppressor_TAVOR");
				weapon.GetInventory().CreateAttachment("TTC_DMR_556Pmag_30rnd");
			MissionObject.GetInventory().CreateInInventory("TTC_DMR_556Pmag_30rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_556x45Tracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_556x45Tracer_20Rnd");
			weapon = MissionObject.GetInventory().CreateInInventory("FNX45");
				weapon.GetInventory().CreateAttachment("PistolSuppressor");
				weapon.GetInventory().CreateAttachment("FNP45_MRDSOptic");
				weapon.GetInventory().CreateAttachment("TLRLight");
			MissionObject.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");
			MissionObject.GetInventory().CreateInInventory("Ammo_45ACP");
			MissionObject.GetInventory().CreateInInventory("WaterBottle");			
			MissionObject.GetInventory().CreateInInventory("Battery9V");
			MissionObject.GetInventory().CreateInInventory("Collectable_PocketWatch");
		}
		if (selectedLoadout == 5)
		{			
			weapon = MissionObject.GetInventory().CreateInInventory("TTC_XM2010");
				weapon.GetInventory().CreateAttachment("HuntingOptic");
				weapon.GetInventory().CreateAttachment("TTC_XM2010_10rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_308WinTracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_308WinTracer_20Rnd");
			weapon = MissionObject.GetInventory().CreateInInventory("TTC_44Magnum_Black");
			MissionObject.GetInventory().CreateInInventory("TTC_AmmoBox_44Mag");
			MissionObject.GetInventory().CreateInInventory("TTC_AmmoBox_44Mag");
			weapon = MissionObject.GetInventory().CreateInInventory("NVGHeadstrap");
				weapon.GetInventory().CreateInInventory("TF_NVGoggles_PNV10T");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
			MissionObject.GetInventory().CreateInInventory("WaterBottle");	
			MissionObject.GetInventory().CreateInInventory("SpaghettiCan");
			MissionObject.GetInventory().CreateInInventory("HuntingKnife");
			MissionObject.GetInventory().CreateInInventory("Collectable_SSD");
			MissionObject.GetInventory().CreateInInventory("M67Grenade");					
		}
		if (selectedLoadout == 6)
		{			
			weapon = MissionObject.GetInventory().CreateInInventory("TTC_Winchester1873");
				weapon.GetInventory().CreateAttachment("HuntingOptic");
			MissionObject.GetInventory().CreateInInventory("TTC_AmmoBox_4570_20Rnd");
			MissionObject.GetInventory().CreateInInventory("TTC_AmmoBox_4570_20Rnd");
			weapon = MissionObject.GetInventory().CreateInInventory("TTC_44Magnum_Black");
			MissionObject.GetInventory().CreateInInventory("TTC_AmmoBox_44Mag");
			MissionObject.GetInventory().CreateInInventory("TTC_AmmoBox_44Mag");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
			MissionObject.GetInventory().CreateInInventory("Cannabis");
			MissionObject.GetInventory().CreateInInventory("CannabisSeedsPack");
			MissionObject.GetInventory().CreateInInventory("WaterBottle");	
			MissionObject.GetInventory().CreateInInventory("TunaCan");
			MissionObject.GetInventory().CreateInInventory("RDG5Grenade");	
			MissionObject.GetInventory().CreateInInventory("Collectable_MemoryCard");
		}	
		if (selectedLoadout == 7)
		{			
			weapon = MissionObject.GetInventory().CreateInInventory("TTC_G3");
				weapon.GetInventory().CreateAttachment("TTC_G3_Optic");			
				weapon.GetInventory().CreateAttachment("TTC_G3_Magazine_20rnd");
			MissionObject.GetInventory().CreateInInventory("TTC_G3_Magazine_20rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_308WinTracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_308WinTracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
			MissionObject.GetInventory().CreateInInventory("GardenLime");
			MissionObject.GetInventory().CreateInInventory("CannabisSeedsPack");
			MissionObject.GetInventory().CreateInInventory("WaterBottle");	
			MissionObject.GetInventory().CreateInInventory("SardinesCan");
			MissionObject.GetInventory().CreateInInventory("M18SmokeGrenade_Green");
			MissionObject.GetInventory().CreateInInventory("Collectable_TetrisToy");
		}
		if (selectedLoadout == 8)
		{			
			weapon = MissionObject.GetInventory().CreateInInventory("TTC_AWM");
				weapon.GetInventory().CreateAttachment("TTC_EotechVudu_Tan_AK_Optic");
				weapon.GetInventory().CreateAttachment("TTC_AWM_Magazine_5rnd");			
			MissionObject.GetInventory().CreateInInventory("TTC_AWM_Magazine_5rnd");
			MissionObject.GetInventory().CreateInInventory("TTC_AmmoBox_338mm_10Rnd");
			MissionObject.GetInventory().CreateInInventory("WaterBottle");	
			MissionObject.GetInventory().CreateInInventory("SpaghettiCan");
			weapon = MissionObject.GetInventory().CreateInInventory("NVGHeadstrap");
				weapon.GetInventory().CreateInInventory("TF_NVGoggles_PVS15");
			MissionObject.GetInventory().CreateInInventory("M18SmokeGrenade_Red");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
			MissionObject.GetInventory().CreateInInventory("Collectable_RetroToy");				
		}
		if (selectedLoadout == 9)
		{			
			weapon = MissionObject.GetInventory().CreateInInventory("TF_AK101");
				weapon.GetInventory().CreateAttachment("TF_AK_AdapterBttstck");
				weapon.GetInventory().CreateAttachment("TTC_AKMod_bttstk");	
				weapon.GetInventory().CreateAttachment("TF_AK_ZenitB30B31Hndgrd_RIS");
				weapon.GetInventory().CreateAttachment("TF_AK_PBS1Suppressor");			
			MissionObject.GetInventory().CreateInInventory("TF_Mag_AK101_Plastic30Rnd");
			MissionObject.GetInventory().CreateInInventory("TF_Mag_AK101_Plastic30Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_556x45Tracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_556x45Tracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("Headtorch_Grey");
			MissionObject.GetInventory().CreateInInventory("Canteen");	
			MissionObject.GetInventory().CreateInInventory("TacticalBaconCan");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
			MissionObject.GetInventory().CreateInInventory("Battery9V");
			MissionObject.GetInventory().CreateInInventory("Collectable_Polaroid_Three");
		}
		if (selectedLoadout == 10)
		{			
			weapon = MissionObject.GetInventory().CreateInInventory("TTC_Beowulf");
				weapon.GetInventory().CreateAttachment("HuntingOptic");
				weapon.GetInventory().CreateAttachment("TTC_50Beo_mag");
			MissionObject.GetInventory().CreateInInventory("TTC_AmmoBox_50Beo_20rnd");
			MissionObject.GetInventory().CreateInInventory("TTC_AmmoBox_50Beo_20rnd");
			weapon = MissionObject.GetInventory().CreateInInventory("TTC_M9_Custom");
				weapon.GetInventory().CreateAttachment("TTC_Gold_Grip");
			MissionObject.GetInventory().CreateInInventory("TTC_Mag_M9_Custom_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_9x19_25rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_9x19_25rnd");
			MissionObject.GetInventory().CreateInInventory("Collectable_PokemonCard_SuperEnergy");
			MissionObject.GetInventory().CreateInInventory("WaterBottle");	
			MissionObject.GetInventory().CreateInInventory("SpaghettiCan");
			MissionObject.GetInventory().CreateInInventory("HuntingKnife");
			MissionObject.GetInventory().CreateInInventory("M67Grenade");
			MissionObject.GetInventory().CreateInInventory("Battery9V");			
		}
		if (selectedLoadout == 11)
		{			
			weapon = MissionObject.GetInventory().CreateInInventory("TTC_R700");
				weapon.GetInventory().CreateAttachment("HuntingOptic");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_308WinTracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_308WinTracer_20Rnd");
			weapon = MissionObject.GetInventory().CreateInInventory("TTC_44Magnum");
			MissionObject.GetInventory().CreateInInventory("TTC_AmmoBox_44Mag");
			MissionObject.GetInventory().CreateInInventory("TTC_AmmoBox_44Mag");
			MissionObject.GetInventory().CreateInInventory("Collectable_PokemonCard_Wartortle");
			MissionObject.GetInventory().CreateInInventory("WaterBottle");	
			MissionObject.GetInventory().CreateInInventory("SpaghettiCan");
			MissionObject.GetInventory().CreateInInventory("HuntingKnife");
			MissionObject.GetInventory().CreateInInventory("M67Grenade");
			MissionObject.GetInventory().CreateInInventory("Battery9V");			
		}
		if (selectedLoadout == 12)
		{			
			weapon = MissionObject.GetInventory().CreateInInventory("TF_SCAR_20_Shd");
				weapon.GetInventory().CreateAttachment("TF_SCAR_Mk20Bttstck_Shd");
				weapon.GetInventory().CreateAttachment("TF_Mag_SCAR_H_20Rnd_Shd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_308WinTracer_20Rnd");
			MissionObject.GetInventory().CreateInInventory("AmmoBox_308WinTracer_20Rnd");			
			weapon = MissionObject.GetInventory().CreateInInventory("NVGHeadstrap");
				weapon.GetInventory().CreateInInventory("TF_NVGoggles_PVS14");
			MissionObject.GetInventory().CreateInInventory("Collectable_Polaroid_Two");
			MissionObject.GetInventory().CreateInInventory("WaterBottle");	
			MissionObject.GetInventory().CreateInInventory("SpaghettiCan");
			MissionObject.GetInventory().CreateInInventory("HuntingKnife");
			MissionObject.GetInventory().CreateInInventory("M67Grenade");
			MissionObject.GetInventory().CreateInInventory("Battery9V");				
		}
					
		Print("[SMM] Mission rewards spawned in reward container. Randomly selected loadout was "+ selectedLoadout +"." );	
	}
	
	void SpawnObjects()
	{			
		if ( m_MissionExtended )
		{	
			//Spawn mushroom occurence		
			float OccurenceDist = 30 * 0.707 ;
			int MushroomsCount = Math.RandomIntInclusive( 50, 150);
			vector SpawnPos;
			bool ItemsAtGround = false; 
		 
			MissionObject = ItemBase.Cast( GetGame().CreateObject( "PsilocybeMushroom", m_MissionPosition ));
			if ( MissionObject ) Print("[SMM] Mushrooms occurence spawned around @ "+ MissionObject.GetPosition());
			
			m_MissionObjects.Insert( MissionObject );
			for ( int j = 1; j < MushroomsCount; j++ )
			{
				//calc new spawn position
				float x = Math.RandomFloatInclusive( 0.5 , OccurenceDist );
				float y = Math.RandomFloatInclusive( 0.5 , OccurenceDist );	
				int Dice = Math.RandomIntInclusive( 0, 9);
				if ( Dice > 4 ) x *= -1.0;
				Dice = Math.RandomIntInclusive( 0, 9);
				if ( Dice < 5 ) y *= -1.0;
				vector NewPosVector = { x, 0, y };
				SpawnPos = m_MissionPosition + NewPosVector;
				
				//check for items at ground
				GetGame().GetObjectsAtPosition( SpawnPos , 1.0 , m_ObjectList , m_ObjectCargoList );
				for ( int i = 0; i < m_ObjectList.Count(); i++ )
				{ 
					Object FoundObject = m_ObjectList.Get(i);
					if ( FoundObject.IsItemBase() || FoundObject.IsTree() || FoundObject.IsRock() || FoundObject.IsBush() ) 
					{
						ItemsAtGround = true;
						break;
					}
				}
				if ( ItemsAtGround )
				{
					ItemsAtGround = false;
					j--;
					continue;
				} 
			
				//spawn mushroom
				m_MissionObjects.Insert( GetGame().CreateObject( "PsilocybeMushroom", SpawnPos ));	
			}
				
			Print("[SMM] Survivor Mission "+ m_selectedMission +" :: "+ m_MissionName +" ...mission deployed!");
		}
		else
		{				
			if ( MissionBuilding )
			{
				//Cleanup position before spawning protector case
				GetGame().GetObjectsAtPosition( m_MissionPosition, 0.5, m_ObjectList, m_ObjectCargoList );
				for ( int k = 0; k < m_ObjectList.Count(); k++ )
				{
					FoundObject = m_ObjectList.Get(k);
					if ( FoundObject.IsItemBase() )
					GetGame().ObjectDelete( FoundObject );
				}
				
				//Spawn container
				GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( this.SpawnContainer, 1000 );
								
				Print("[SMM] Survivor Mission Extension "+ m_selectedMission +" :: "+ m_MissionName +" ...mission extended!");
			}
			else Print("[SMM] Extended MissionBuilding couldn't be found in "+ m_MissionDescription[3] +" ... Mission rejected!");
		}
	}
	
	void SpawnAIs()
	{	
		if ( m_MissionExtended )
		{
			//Spawn no AIs at primary mission
		}
		else
		{
			//Spawn infected
			string RandomInfected = InfectedTypes.GetRandomElement();
			vector InfectedPos;
			
			for ( int k = 0 ; k < InfectedSpawns.Count() ; k++ )
			{
	    	   	RandomInfected = InfectedTypes.GetRandomElement();
				InfectedPos = MissionBuilding.ModelToWorld( InfectedSpawns.Get(k) );
				m_MissionAIs.Insert( GetGame().CreateObject( RandomInfected, InfectedPos, false, true ) );
			}
		}
	}
	
	void ObjDespawn() 
	{	
		//Despawn all mission objects at mission timeout except those retains until next mission
		for ( int i = 0; i < m_MissionObjects.Count(); i++ )
		{
			//Exception: Psilo's will remain
			if ( m_MissionObjects.Get(i) && m_MissionObjects.Get(i).GetType() == "PsilocybeMushroom" )	continue;

			//Delete Object
			GetGame().ObjectDelete( m_MissionObjects.Get(i) );
			m_MissionObjects.Remove(i);
		}
	}
	
	void ExtendMission()
	{
		//Set new mission messages
		m_MissionMessage1 = "Allright survivor, if you have found "+ ReqShroomsCount +" of these mushrooms bring them to the following place. Hold on a second...";
		m_MissionMessage2 = "Bring them to the ** "+ m_MissionSecondaryLoc +" Hospital Office **\n"+ SurvivorExtName +" said she could extract the active substance for me. She has a small protector case on her desk in her former office.";
		m_MissionMessage3 = "Put all you have found in there. Be carefull, there might be bandits around which could intercepted our little radio talk here. Good luck!";
		
		//init Messenger for new messages
		m_MsgNum = 1;					//skip msg 0, begin with msg 1
		m_MsgChkTime = m_MissionTime;
		MsgCutoff = false;
		
		//increase mission MissionTimeout
		m_MissionTimeout = m_MissionTime + ExtendedTimout;  
		
		//deployment settings & init for extended mission
		m_MissionZoneOuterRadius = 90.0;
		m_MissionZoneInnerRadius = 2.0;
		
		//Get building position from building type and location
		if ( EventsWorldData.GetBuildingsAtLoc("Land_City_Hospital", m_MissionDescription[3], ExtendedPosList ))
		{			
			//Get MissionPosition for MissionBuilding from secondary mission
			m_MissionPosition = ExtendedPosList.GetRandomElement();						
			
		}
		else Print("[SMM] Can't find MissionBuilding City Hospital in "+ m_MissionDescription[3] +"!");
	}
	
	void MissionFinal()
	{	//When player enters last mission target zone
		//do nothing			
	}
	
	void PlayerChecks( PlayerBase player )
	{
		//Check if container gets taken from player
		if ( MissionSettings.Opt_DenyObjTakeaway && !m_MissionExtended )
		{
			if ( m_MissionObjects[0] && m_MissionObjects[0].ClassName() == "SmallProtectorCase" )
			{
				if ( player.GetInventory().HasEntityInInventory( EntityAI.Cast( m_MissionObjects[0] ) ) && !m_ContainerWasTaken )
				{
					m_ContainerWasTaken = true;
					Print("[SMM] Mission object container was taken by a player ...and will be deleted.");
					GetGame().ObjectDelete( m_MissionObjects[0] );
				}
			}
		}
		
		//Check if container has desired amount of mushrooms collected at primary mission position
		if ( MissionObject && MissionObject.ClassName() == "SmallProtectorCase" && !m_MissionExtended )
		{
			int CargoCount;
			int LastCount = 0;
			int FoundObjects = 0;
			
			CargoCount = MissionObject.GetInventory().CountInventory();
			
			if ( CargoCount != LastCount )
			{
				if ( CargoCount >= ReqShroomsCount )
				{	
					CargoBase CargoItems1 = MissionObject.GetInventory().GetCargo();		
					
					for ( int i = 0; i < CargoCount; i++ )
					{
						EntityAI CargoItem = CargoItems1.GetItem(i);
						if ( m_MissionObjects.Find( CargoItem ) > -1 ) FoundObjects++;
						else continue;					
						
						//When requested amount of mushrooms is present, despawn MissionObject & spawn rewards
						if ( FoundObjects >= ReqShroomsCount )
						{
							Print("[SMM] Player with SteamID64: "+ player.GetIdentity().GetPlainId() +" has successfully stored the requested amount of "+ ReqShroomsCount +" MissionObjects in the container.");
							//delete container first
							GetGame().ObjectDelete( MissionObject );
							//call rewards spawn one second later 
							GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( this.SpawnRewards, 1000 );
							m_RewardsSpawned = true;
							m_MsgNum = -1;
							m_MsgChkTime = m_MissionTime + MsgDlyFinish;
							break;
						} 
					}
					
					FoundObjects = 0;
				}
				
				LastCount = CargoCount;
			} 
		}		
	}
		
	void UpdateBots(float dt)
	{
		//No bots involved in this mission		
	}
	
	bool DeployMission()
	{	//When first player enters the mission zone (primary/secondary)
		//Get MissionBuilding at mission position
		if ( !m_MissionExtended && !MissionBuilding )
		{
			GetGame().GetObjectsAtPosition( m_MissionPosition , 1.0 , m_ObjectList , m_ObjectCargoList );
			for ( int m=0; m < m_ObjectList.Count(); m++ )
			{ 
				Object FoundObject = m_ObjectList.Get(m);
				if ( FoundObject.GetType() == "Land_City_Hospital" )
				{	
					MissionBuilding = FoundObject;			 
					Print("[SMM] MissionBuilding extended is "+ MissionBuilding.GetType() +" at "+ m_MissionDescription[3] +" @ "+ MissionBuilding.GetPosition() );
					
					//new MissionPosition is rewards spawnpoint
					m_MissionPosition = MissionBuilding.ModelToWorld( Spawnpoints.GetRandomElement() );
					break;
				}	
			}
		}	
			
		if ( (m_MissionPosition && m_MissionPosition != "0 0 0" && m_MissionExtended) || (MissionBuilding && !m_MissionExtended) )
		{
			//Call spawners	
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( this.SpawnObjects );
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( this.SpawnAIs );
			return true;		
		}
		else 
		{
			Print("[SMM] Mission position was rejected or MissionBuilding doesn't exist!");
			if ( MissionSettings.DebugMode && !MissionBuilding && !m_MissionExtended ) Print("[SMM] MissionBuilding is NULL!");
			return false;
		}
	}
}

