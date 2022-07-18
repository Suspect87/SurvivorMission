class HeadHuntMission extends SideMissions
{
	//math constants
	const float Pi = 3.14159265359;
	
	//Mission related entities 
	Object MissionBuilding;
	ItemBase MissionObject;
	
	//Mission parameters
	int ExtendedTimout = 900;				//seconds, mission duration time for extended mission
	int MsgDlyFinish = 60;					//seconds, message delay time after player has finished mission
	
	//Mission containers
	ref array<vector> ExtendedPosList = new array<vector>;
	ref map<string, ref Param3<string,string,vector>> Secondaries = new map<string, ref Param3<string,string,vector>>;	
	ref array<vector> Spawnpoints = new array<vector>;
	ref array<vector> InfectedSpawns = new array<vector>;
	ref array<string> InfectedTypes = new array<string>;
	ref Param3<string,string,vector> SecBuildInfo = new Param3<string,string,vector>;
		
	//Mission variables
	string SurvivorName;
	string SurvivorID;
	float SurvivorDir;
	string SurvivorCompDir;
	float SurvivorDist;
	string TargetCoords;
	
	string SecondaryLoc;
	vector SecondaryBldPos;
	vector SecondarySpawn;
	string SecondaryBuild;
	string SecondaryBldClass;
	string SecondaryBldMsgName;
	vector SecondaryBldSpawn;
	
	bool DocsFoundAtPrimary = false;
	bool PlayerNearSecondary = false;
	
	//Settings buffer values
	int MsgWaitTimeRst;

	
	bool IsExtended() return true;
	
	void HeadHuntMission()
	{		
		//Select primary mission
		m_MissionExtended = true;
		
		//Mission timeout
		m_MissionTimeout = 2700;			//seconds, primary mission duration time
		
		//Mission zones
		m_MissionZoneOuterRadius = 150.0;	//meters (!Do not set lower than 200m), mission activation distance
		m_MissionZoneInnerRadius = 2.0;		//meters (!Do not set outside of 1-5m), mission finishing distance to target object
				
		//Mission informant
		m_MissionInformant = "Dr. Legasov";
	
		//Mission person names
		TStringArray SurvivorNames = {"Yuri","Michail","Boris","Valeri","Anatoli","Ivan","Alexej","Dimitrij","Sergej","Nikolai","Vladimir"};
		StoryName = SurvivorNames.GetRandomElement();
		
		//Set mission messages for primary mission
		m_MissionMessage1 = StoryName +", a chemist who worked for the "+ m_MissionLocation +"'s hospital, told me that they was working on a solution to gain Anti-Gen's from the virus a few month's ago. They made several examples but the hospital was looted by the soviet military decontamination forces.";
		m_MissionMessage2 = "They probably have stolen all the Anti-Gen examples, but they didnt know about "+ StoryName +"'s documents he left behind anywhere on his desk in the hospital office rooms. Maybe we could gain Anti-Gen's again, once we have found those informations in the documents.";
		m_MissionMessage3 = "Could you find the documents in the "+ m_MissionLocation +"'s hospital for me? He has left a notice in the documents, where you have to bring it. I can't tell you about the destination on radio... too unsafe on this channel. Take care, meanwhile soviet forces know about these important informations too.";
				
		//Spawnpoints for MissionTarget in hospital
		Spawnpoints.Insert("-20.2900 -6.6398 0.7559");
		Spawnpoints.Insert("-20.2568 -6.6398 5.2510");
		Spawnpoints.Insert("-15.2871 -6.6398 5.0928");
		Spawnpoints.Insert("-10.0518 -6.6401 8.1748");
		Spawnpoints.Insert("-8.4160 -6.6398 7.6533");
		Spawnpoints.Insert("-4.0557 -6.6398 7.9033");
						
		//Infected spawnpoints for primary mission at hospital
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
										
		//parse Extended Mission parameter to get secondary info
		string SecondaryDescription[2];
		m_MissionSecondaryLoc.ParseString( SecondaryDescription );
		SecondaryLoc = SecondaryDescription[0];
		SecondaryBuild = SecondaryDescription[1];

		//get secondary building data
		SecBuildInfo = Secondaries.Get( SecondaryBuild );
		SecondaryBldClass = SecBuildInfo.param1;
		SecondaryBldMsgName = SecBuildInfo.param2;
		SecondaryBldSpawn = SecBuildInfo.param3;
		
		//Secondary building table for classname, message callname of building and modelvector of MissionObject spawn point
		Secondaries.Insert( "Hospital", 	new Param3<string,string,vector>( "Land_City_Hospital", 		"hospital", 				""));
		Secondaries.Insert( "Police", 		new Param3<string,string,vector>( "Land_Village_PoliceStation", "police station", 			""));
		Secondaries.Insert( "CityPolice", 	new Param3<string,string,vector>( "Land_City_PoliceStation", 	"police department", 		""));
		
		
		
		//Search for mission building at primary mission position	
		GetGame().GetObjectsAtPosition( m_MissionPosition , 1.0 , m_ObjectList , m_ObjectCargoList );
		for ( int i = 0 ; i < m_ObjectList.Count(); i++ )
		{ 
			Object FoundObject = m_ObjectList.Get(i);
			if ( FoundObject.GetType() == "Land_City_Hospital" )
			{	
				MissionBuilding = FoundObject;			 
				Print("[SMM] MissionBuilding is "+ MissionBuilding.GetType() +" at "+ m_MissionDescription[2] +" of "+ m_MissionDescription[1] +" @ "+ MissionBuilding.GetPosition() );
				break;
			}	
		}
		if ( !MissionBuilding ) Print("[SMM] Hospital couldn't be found. Mission rejected!");
		
		//predictivly search for mission building at secondary mission position 
		if ( SideMissionData.GetBuildingsAtLoc( SecBuildInfo.param1, SecondaryLoc, ExtendedPosList ))
		{
			SecondaryBldPos = ExtendedPosList.GetRandomElement();
			GetGame().GetObjectsAtPosition( SecondaryBldPos, 1.0 , m_ObjectList , m_ObjectCargoList );
			for ( int m=0; m < m_ObjectList.Count(); m++ )
			{ 
				Object FoundObject = m_ObjectList.Get(m);
				if ( FoundObject.GetType() == SecondaryBldClass )
				{	
					SecondarySpawn = FoundObject.ModelToWorld( SecondaryBldSpawn );			 
					break;
				}	
			}
		}
		else Print("[SMM] Can't get secondary MissionPosition in "+ SecondaryLoc +" from SideMissionData!");				
	}
	
	void ~HeadHuntMission()
	{	
		//Despawn all remaining mission objects
		if ( m_MissionObjects )
		{
			Print("[SMM] Despawning "+ m_MissionObjects.Count() +" mission objects from old mission...");		
			for ( int i = 0; i < m_MissionObjects.Count(); i++ )
			{				
				if ( !m_MissionObjects.Get(i))	continue;
				else
				{	
					if ( m_MissionObjects.Get(i).IsTransport() ) 
					{
						//Don't delete just add full damage to MissionCar
						m_MissionObjects.Get(i).SetHealth("","",0);
						continue;
					}
							
					GetGame().ObjectDelete( m_MissionObjects.Get(i) );
				}			
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
		
		//Reset changed settings by mission 
		if ( MsgWaitTimeRst )	MissionSettings.MsgWaitTime = MsgWaitTimeRst;
	}
		
	void SpawnRewards()
	{		
		//new MissionObject after deleting protector case
		MissionObject = ItemBase.Cast( GetGame().CreateObject( "SeaChest", m_MissionPosition ));
		
		//..loadout selection 
		
			
		Print("[SMM] Mission rewards spawned in reward container. Randomly selected loadout was "+selectedLoadout+"." );			
	}
	
	void SpawnObjects()
	{	
		if ( m_MissionExtended )
		{	
			//Get spawnpoint for MissionTarget
			m_MissionPosition = MissionBuilding.ModelToWorld( Spawnpoints.GetRandomElement());
	 		
			//Clean up MissionTarget spawnpoint
			GetGame().GetObjectsAtPosition( m_MissionPosition, 1.5, m_ObjectList, m_ObjectCargoList );
			
			if ( m_ObjectList.Count() > 0)
			{
				for ( int i=0; i < m_ObjectList.Count(); i++)
				{
					Object FoundObject = m_ObjectList.Get(i);
					if ( FoundObject.IsItemBase() )
					{
						Print("[SMM] BeforeSpawnCleanUp :: Object  " + FoundObject.ToString() + " at new mission position was deleted.");
						GetGame().ObjectDelete( FoundObject );
					}
				}
			}
			
			//spawn mission target at hospital 
			MissionTarget = GetGame().CreateObject("Paper", m_MissionPosition );
			
			Print("[SMM] Survivor Mission "+ m_selectedMission +" :: "+ m_MissionName +" ...primary mission deployed!");
		}
		else
		{
			//Clean up MissionTarget spawnpoint
			GetGame().GetObjectsAtPosition( m_MissionPosition, 1.5, m_ObjectList, m_ObjectCargoList );
			
			if ( m_ObjectList.Count() > 0)
			{
				for ( int i=0; i < m_ObjectList.Count(); i++)
				{
					Object FoundObject = m_ObjectList.Get(i);
					if ( FoundObject.IsItemBase() )
					{
						Print("[SMM] BeforeSpawnCleanUp :: Object  " + FoundObject.ToString() + " at new mission position was deleted.");
						GetGame().ObjectDelete( FoundObject );
					}
				}
			}
			
			//spawn mission object (protector case) in secondary builing
			MissionObject = GetGame().CreateObject("SmallProtectorCase", m_MissionPosition );
			
			Print("[SMM] Survivor Mission Extension "+ m_selectedMission +" :: "+ m_MissionName +" ...secondary mission deployed!");
		}
	}
	
	void SpawnAIs()
	{	

	}
	
	void ObjDespawn() 
	{	

	}
	
	void ExtendMission()
	{	//When player enters mission target zone at primary mission
				
		if ( !PlayerNearSecondary )
		{	//as long as player didn't enter secondary mission zone 
			
			//reset last changed values for holding mission primary 
			m_MissionExtended = true;
			m_ZoneIsTriggered = true;
			//MissionZoneTrigger.PlayerIsInList = true;
		}
		else
		{
			//Set messages for secondary mission
			m_MissionInformant = "Major Stolcic";
			m_MissionMessage1 = "The survivor with the stolen documents was spotted very close to ** "+ SecondaryLoc +" **. Prevent him from getting to the meeting point.";
			m_MissionMessage2 = "These documents are the property of the Soviet Army. Do not read them, it's top secret. Bring it back to me, i guarantee your safety... your money and a warm meal.";
			m_MissionMessage3 = "The survivor is probably meeting Legasov in the ** "+ SecondaryBldMsgName +" **. Hurry up and get the survivor bofore he hands out the documents.";
			
			//init Messenger for new messages
			m_MsgNum = 1;					//skip msg 0, begin with msg 1
			m_MsgChkTime = m_MissionTime;
			MsgCutoff = false;
			
			//increase mission MissionTimeout for secondary mission
			m_MissionTimeout = m_MissionTime + ExtendedTimout;  
			
			//deployment settings & init for secondary mission		
			m_MissionZoneOuterRadius = 400.0;
			m_MissionZoneInnerRadius = 2.0;

			//Get building position from building type and location 
			if ( SideMissionData.GetBuildingsAtLoc( SecBuildInfo.param1, SecondaryLoc, ExtendedPosList ))
			{
				//Get MissionPosition for MissionBuilding from secondary mission
				SecondaryBldPos = ExtendedPosList.GetRandomElement();
				GetGame().GetObjectsAtPosition( SecondaryBldPos, 1.0 , m_ObjectList , m_ObjectCargoList );
				for ( int m=0; m < m_ObjectList.Count(); m++ )
				{ 
					Object FoundObject = m_ObjectList.Get(m);
					if ( FoundObject.GetType() == SecondaryBldClass )
					{	
						MissionBuilding = FoundObject;			 
											
						//new MissionPosition is rewards spawnpoint
						m_MissionPosition = MissionBuilding.ModelToWorld( SecondaryBldSpawn );
						break;
					}	
				}
			}
			else Print("[SMM] Can't get secondary MissionPosition in "+ SecondaryLoc +" from SideMissionData!");
		}
	}
	
	void MissionFinal()
	{	//When player enters last mission target zone
		//do nothing		
	}
	
	void MessageTargetPlayer( PlayerBase player )
	{
		string message1 = "Dear "+ SurvivorName +",\nthese documents are really important. It has information about new methods to gain Anti-Gen's of that virus. It seems we can produce vaccine now. It has the highest priority.";
		string message2 = "\nMeet with Legasov just leave it in the ** "+ SecondaryBldMsgName +" of "+ SecondaryLoc +" **\nas fast as you can. There is a yellow Protector Case in the building. Put the documents in there! Good luck, stay safe and trust nobody!";
		string icon = "set:dayz_gui image:gear";
					
		NotificationSystem.SendNotificationToPlayerIdentityExtended( player.GetIdentity() , 25.0, "Secret Documents:", message1 + message2 +"\n\n"+ m_MissionCountdown + MissionSettings.Message3Ext , icon );
	}
	
	void MarkTargetSmoke()
	{
		//spawn & activate smokegrenade at target position
		Grenade_Base BoobyTrap = Grenade_Base.Cast( GetGame().CreateObject( "M18SmokeGrenade_Yellow" , TargetPos + "0 0 2" ));
		BoobyTrap.ActivateImmediate();	
	}
		
	void PlayerChecks( PlayerBase player )
	{
		
		
		//check if current player has mission target
		if ( MissionTarget )
		{
			if ( player.GetInventory().HasEntityInInventory( EntityAI.Cast( MissionTarget )))
			{
				//update mission target position 
				TargetPos = player.GetPosition();
				if ( m_MissionExtended ) m_MissionPosition = TargetPos;
							
				//log player who is carrying mission target
				SurvivorID = player.GetIdentity().GetPlainId();
				SurvivorName = player.GetIdentity().GetName(); // GetFullName();
				
				//get target player distance to secondary
				SurvivorDist = vector.Distance( TargetPos, SecondarySpawn );
				
				//Secondary zone check
				if ( SurvivorDist < m_MissionZoneOuterRadius ) PlayerNearSecondary = true;
				
				//if primary in hunting/finding mode refresh player position description
				if ( m_MissionExtended )
				{
					//calc relative direction of player to secondary mission position 
					vector PosDiff = TargetPos - SecondarySpawn;				//offsetting player position to secondary
					float x = PosDiff[0];
					float y = PosDiff[2];
					float angle = Math.Atan2(y,x) * 180 / Pi ;	//arctan of pos. diff. and transformation from radians to degrees 
					
					if ( x > 0 && y > 0 )	SurvivorDir = angle;			//quadrant I ...0° + angle
					if ( x < 0 && y > 0 )	SurvivorDir = 360 + angle;		//quadrant II ...360° + (-angle)
					if ( x < 0 && y < 0 )	SurvivorDir = 180 + angle;		//quadrant III ...180° + angle
					if ( x > 0 && y < 0 )	SurvivorDir = 180 + angle;		//quadrant IV ...180° + (-angle)
					
					//get target player relative compass direction from secondary mission position
					//360° / 8 = 45° ( angular range of relative compass direction for messages) north = angular section from (360° - 22.5°) to ( 0° + 22.5°)= 337.5° to 22.5° 
					//...more exact directions can be calculated like 'northnortheast' by increasing the denominator
					if ( SurvivorDir > 337.5 && SurvivorDir <= 22.5 ) 	SurvivorCompDir = "north";
					if ( SurvivorDir > 22.5 && SurvivorDir <= 67.5 ) 	SurvivorCompDir = "northeast";
					if ( SurvivorDir > 67.5 && SurvivorDir <= 112.5 ) 	SurvivorCompDir = "east";
					if ( SurvivorDir > 112.5 && SurvivorDir <= 157.5 ) 	SurvivorCompDir = "southeast";
					if ( SurvivorDir > 157.5 && SurvivorDir <= 202.5 ) 	SurvivorCompDir = "south";
					if ( SurvivorDir > 202.5 && SurvivorDir <= 247.5 ) 	SurvivorCompDir = "southwest";
					if ( SurvivorDir > 247.5 && SurvivorDir <= 292.5 ) 	SurvivorCompDir = "west";
					if ( SurvivorDir > 292.5 && SurvivorDir <= 337.5 ) 	SurvivorCompDir = "northwest";
					
					//refresh mission messages in hunting mode
					m_MissionInformant = "Major Stolcic";
					m_MissionMessage1 = "A survivor has stolen the documents. I command all to kill him on sight and bring the documents back, immediatly! I guarantee you 10.000 rubles.";
					m_MissionMessage2 = "The survivor is probably collaborating with Legasov and wants to give the information away to suspicious people. We will not tolerate that.";
					m_MissionMessage3 = "The survivor with the documents was last spotted\n** "+ Math.Round(SurvivorDist).ToString() +" km "+ SurvivorCompDir +" of "+ SecondaryLoc +" **";
				}
				
				//if player just picked up target
				if ( !TargetWasTaken )
				{
					TargetWasTaken = true;
					
					Print("[SMM] Mission target was taken by player "+ SurvivorName +", SteamID64: "+ SurvivorID );
					
					if ( !DocsFoundAtPrimary ) 
					{
						DocsFoundAtPrimary = true;
						m_MissionTimeout = m_MissionTime + 2700;
															
						//increase message loop speed, settings override
						MsgWaitTimeRst = MissionSettings.MsgWaitTime; //buffer settings
						MissionSettings.MsgWaitTime = 200; 			//override message intervall to 4 min (restore default settings when destructing class)					
					}
		
					//init Messenger for hunting mode
					m_MsgNum = 0;
					m_MsgChkTime = m_MissionTime;
					MsgCutoff = false;
											
					//show intel to player
					MessageTargetPlayer( player );
				}
			}
			
			//check if mission target was dropped 
			else if ( !Missiontarget.IsInventoryItem() && TargetWasTaken )
			{
				TargetWasTaken = false;
				Print("[SMM] Mission target was droped by player. Intel is marked with yellow smoke.");
				m_MissionTargetFound = false;
				
				if ( m_MissionExtended )
				{				
					//toggle mission messages if droped to find mode
					TargetCoords = TargetPos.Get(0).ToInt() +" / "+ TargetPos.Get(2).ToInt();
					m_MissionMessage1 = "It seems the survivor has lost the documents or his life. Somebody reported me the last known position of the survivor. Try to grab the documents before others will do.";
					m_MissionMessage2 = "They lies anywhere around there and is marked with yellow smoke. Read the notice where they have to be brought to.";
					m_MissionMessage3 = "Coordinates:\n**" + TargetCoords +"**\nI guarantee you get some expensive hardware if you can bring this intel to the noted location.";
				}
				//mark documents with yellow smoke 				
				MarkTargetSmoke();	
			}
		}
		else
		{
			//MissionTarget doesnt exist anymore/target+player left the server, create new one on last known player position
			if ( m_MissionActiv && TargetWasTaken )
			{
				TargetWasTaken = false;
				Print("[SMM] Mission target has left the server. Respawning intel and mark it with yellow smoke.");
				m_MissionTargetFound = false;
				
				//respawn mission target
				MissionTarget = GetGame().CreateObject( "Paper", TargetPos );
				
				if ( m_MissionExtended )
				{
					//toggle mission messages if droped to find mode
					TargetCoords = TargetPos.Get(0).ToInt() +" / "+ TargetPos.Get(2).ToInt();
					m_MissionMessage1 = "It seems a survivor has droped the documents or died. Somebody reported me the last known position of the survivor.";
					m_MissionMessage2 = "Try to get the documents before others will do, it lies anywhere around there and is marked with yellow smoke. Check the documents for where they have to be brought to.";
					m_MissionMessage3 = "Coordinates:\n**" + TargetCoords +"**\nI guarantee you get some expensive hardware if you can bring this intel to the noted location.";
				}
				
				//mark documents with yellow smoke 
				MarkTargetSmoke();
			}
		}
					
		//Check if MissionObject is brought to MissionPosition 
		if ( MissionObject && MissionObject.ClassName() == "SmallProtectorCase" && !m_MissionExtended )
		{

				
			if ( SurvivorDist < 3 )
			{
				if ( MissionObject.GetInventory().HasEntityInInventory( EntityAI.Cast( MissionTarget )))
				{
					Print("[SMM] Player with SteamID64: "+ SurvivorID +" has successfully saved the documents from getting into wrong hands.");
					//delete container first
					GetGame().ObjectDelete( MissionObject );
					//spawn rewards 
					SpawnRewards();
					m_RewardsSpawned = true;
					m_MsgNum = -1;
					m_MsgChkTime = m_MissionTime + MsgDlyFinish;

				} 		
			}
		}		
	}
	
	bool DeployMission()
	{	//When first player enters the mission zone (primary/secondary)
		//Get MissionBuilding at secondary mission position
		if ( !m_MissionExtended )
		{			
			GetGame().GetObjectsAtPosition( m_MissionPosition , 1.0 , m_ObjectList , m_ObjectCargoList );
			for ( int i=0; i < m_ObjectList.Count(); i++ )
			{ 
				Object FoundObject = m_ObjectList.Get(i);
				if ( FoundObject.GetType() == SecondaryBldClass )
				{			 
					MissionBuilding = FoundObject;
					Print("[SMM] MissionBuilding extended is "+ SecondaryBldClass +" @ "+ m_MissionPosition );
					
					//new MissionPosition is rewards spawnpoint
					m_MissionPosition = MissionBuilding.ModelToWorld( SecondaryBldSpawn );
					break;
				}	
			}
		}
		
		if ( MissionBuilding )
		{
			//Call spawners	
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( this.SpawnObjects );
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( this.SpawnAIs );
			return true;		
		}
		else 
		{
			Print("[SMM] ERROR : MissionBuilding can't be found!");
			if ( MissionSettings.DebugMode ) Print("[SMM] MissionBuilding is NULL!");
			return false;
		}
	}
}
