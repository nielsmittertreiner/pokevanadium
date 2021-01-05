FirwealdCity_TournamentHallLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TOURNAMENT_HALL_STATE, 0, FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

FirwealdCity_TournamentHallLobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	setvar VAR_TOURNAMENT_HALL_STATE, 1
	release
	end


FirwealdCity_TournamentHallLobby_EventScript_Attendant::
	lock
	faceplayer
	release
	end


FirwealdCity_TournamentHallLobby_EventScript_Maniac::
	msgbox FirwealdCity_TournamentHallLobby_EventScript_Maniac_Text_0, MSGBOX_NPC
	end


FirwealdCity_TournamentHallLobby_EventScript_Beauty::
	msgbox FirwealdCity_TournamentHallLobby_EventScript_Beauty_Text_0, MSGBOX_NPC
	end


FirwealdCity_TournamentHallLobby_EventScript_Maniac_Text_0:
	.string "Competetive POKéMON battles\n"
	.string "are so cool!$"

FirwealdCity_TournamentHallLobby_EventScript_Beauty_Text_0:
	.string "I've heard PHYLLOS is a very strong\n"
	.string "TOURNAMENT MASTER.$"
