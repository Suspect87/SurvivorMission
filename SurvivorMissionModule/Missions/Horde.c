class HordeMission extends SurvivorMissions
{
	//Mission related entities 
	ItemBase MissionObject;
	
	//Mission parameters
	int MsgDlyFinish = 300;					//seconds, message delay time after player has finished mission
	int HordeDensity = 60;					//infected, spawned in circle 
	
	//Mission containers
	ref array<string> InfectedTypes = new array<string>;
	
	bool IsExtended() return false;
	
	void HordeMission()
	{
		//Mission mission timeout
		m_MissionTimeout = 2700;			//seconds, mission duration time
		
		//Mission zones
		m_MissionZoneOuterRadius = 200.0;	//meters (!Do not set lower than 200m), mission activation distance
		m_MissionZoneInnerRadius = 3.0;		//meters (!Do not set outside of 1-5m), mission finishing distance to target object
				
		//Mission informant
		m_MissionInformant = "Dr. Legasov";
		
		//Set mission messages
		m_MissionMessage1 = "I got an emergency call from a heli pilot who crashed somewhere in the forests. He is injured but still alive. He was afraid that the infected will find him soon.";
		m_MissionMessage2 = "He made it to a house in the village near the crash site. He is well equiped and he think he will stay in the house over the night where he treats his open wounds.";
		m_MissionMessage3 = "The house is at the ** "+ m_MissionLocationDir +" side of "+ m_MissionLocation +" **\nBe careful there may be infected and other survivors who want his equipment!";
		

		//Infected types
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
	
	void ~HordeMission()
	{
		//Despawn all remaining mission objects
		if ( m_MissionObjects )
		{	
			Print("[SMM] Despawning "+ m_MissionObjects.Count() +" mission objects from old mission...");				
			for ( int i = 0; i < m_MissionObjects.Count(); i++ )
			{ 
				if ( !m_MissionObjects.Get(i) ) continue;
				else
				{
					//Delete Object serverside
					GetGame().ObjectDelete( m_MissionObjects.Get(i) );
				}		
			}
			m_MissionObjects.Clear();
		}
		
		//Despawn mission AI's
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
	
	void SpawnObjects()
	{				
		//Mission object is pilot bag
		MissionObject = ItemBase.Cast( GetGame().CreateObject("AliceBag_Camo", m_MissionPosition ) );
		MissionObject.SetPosition( m_MissionPosition + "0 0.2 0" );
		//MissionObject.PlaceOnSurface(); 
		
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
		
		m_MissionObjects.Insert( MissionObject );
		
		Print("[SMM] Survivor Mission "+ m_selectedMission +" :: "+ m_MissionName +" ...mission deployed!");
	}
	
	void SpawnAIs()
	{	
		//Spawn pilot
		DayZInfected InfectedPilot = DayZInfected.Cast( GetGame().CreateObject( "ZmbM_CommercialPilotOld_Olive" , m_MissionPosition , false , true ));
			InfectedPilot.SetPosition( m_MissionPosition );
		//InfectedPilot.PlaceOnSurface();
			InfectedPilot.GetInventory().CreateAttachment("ZSh3PilotHelmet_Green");
			InfectedPilot.GetInventory().CreateInInventory("M67Grenade");
			InfectedPilot.GetInventory().CreateInInventory("CanOpener");
			InfectedPilot.GetInventory().CreateInInventory("BandageDressing");
			InfectedPilot.GetInventory().CreateInInventory("PeachesCan");
			InfectedPilot.GetInventory().CreateInInventory("Canteen");
			InfectedPilot.GetInventory().CreateAttachment("UKAssVest_Olive");
			InfectedPilot.GetInventory().CreateInInventory("PersonalRadio");
			InfectedPilot.GetInventory().CreateInInventory("Battery9V");
			InfectedPilot.GetInventory().CreateInInventory("Battery9V");
			InfectedPilot.GetInventory().CreateInInventory("Battery9V");
			
		//Pilot is dead
		InfectedPilot.SetHealth("","",0);
		
		m_MissionAIs.Insert( InfectedPilot );
		
		//Spawn horde
		for ( int j = 0; j < HordeDensity; j++ )
		{
			//calc new spawn position
			float x = Math.RandomFloatInclusive( 3 , 30 );
			float y = Math.RandomFloatInclusive( 3 , 30 );	
			int Dice = Math.RandomIntInclusive( 0, 9);
			if ( Dice > 4 ) x *= -1.0;
			Dice = Math.RandomIntInclusive( 0, 9);
			if ( Dice < 5 ) y *= -1.0;
			vector NewPosVector = { x, 0, y };
			
			//Spawn infected
			m_MissionAIs.Insert( GetGame().CreateObject( InfectedTypes.GetRandomElement(), m_MissionPosition + NewPosVector, false, true ));	
		}
	}
	
	void ObjDespawn() 
	{	
		//nothing to despawn
	}
	
	void MissionFinal()
	{	//When player enters last mission target zone	

		//Finish mission
		m_RewardsSpawned = true;
		m_MsgNum = -1;
		m_MsgChkTime = m_MissionTime + MsgDlyFinish;			
	}
	
	void PlayerChecks( PlayerBase player ) {}
			
	bool DeployMission()
	{	//When first player enters the mission zone (primary/secondary)
		if ( m_MissionPosition && m_MissionPosition != "0 0 0" )
		{
			//Call spawners	
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( this.SpawnObjects );
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( this.SpawnAIs, 1000, false );
			return true;		
		}
		else 
		{
			Print("[SMM] ERROR : Mission position was rejected or doesn't exist. MissionPosition is NULL!");
			return false;
		}
	}
}

