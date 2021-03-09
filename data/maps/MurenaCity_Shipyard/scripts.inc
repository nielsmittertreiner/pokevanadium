MurenaCity_Shipyard_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MurenaCity_Shipyard_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MurenaCity_Shipyard_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MurenaCity_Shipyard_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

MurenaCity_Shipyard_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_MURENA_CITY
	call FishermanFerry_EventScript_UpdateFerryLocation
	return

MurenaCity_Shipyard_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_FISHERMAN_FERRY_STATE, 3, MurenaCity_Shipyard_EventScript_SetUpObjects
	.2byte 0

MurenaCity_Shipyard_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_FISHERMAN_FERRY_STATE, 4, MurenaCity_Shipyard_EventScript_FinishSailToMurena
	.2byte 0


MurenaCity_Shipyard_EventScript_SetUpObjects::
	setvar VAR_FISHERMAN_FERRY_STATE, 4
	clearflag FLAG_HIDE_MURENA_CITY_SHIPYARD_FISHERMAN
	clearflag FLAG_HIDE_MURENA_CITY_SHIPYARD_BOAT
	clearflag FLAG_HIDE_MURENA_CITY_BOAT
	addobject 2
	addobject 1
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_MURENA_CITY_SHIPYARD
	turnobject 2, DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end


MurenaCity_Shipyard_EventScript_FinishSailToMurena::
	setvar VAR_FISHERMAN_FERRY_STATE, 0
	load_speech_bubble 2
	msgbox MurenaCity_Shipyard_EventScript_FinishSailToMurena_Text_0
	destroy_speech_bubble
	closemessage
	release
	end


MurenaCity_Shipyard_EventScript_Fisherman::
	lock
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 9
	goto_if_eq MurenaCity_Shipyard_EventScript_Fisherman_2
MurenaCity_Shipyard_EventScript_Fisherman_1:
	load_speech_bubble 2
	msgbox MurenaCity_Shipyard_EventScript_Fisherman_Text_0, MSGBOX_YESNO
	destroy_speech_bubble
	closemessage
	switch VAR_RESULT
	case YES, MurenaCity_Shipyard_EventScript_Fisherman_5
	case NO, MurenaCity_Shipyard_EventScript_Fisherman_6
	case MULTI_B_PRESSED, MurenaCity_Shipyard_EventScript_Fisherman_7
	return

MurenaCity_Shipyard_EventScript_Fisherman_2:
	applymovement OBJ_EVENT_ID_PLAYER, MurenaCity_Shipyard_Movement_PlayerWalkToFisherman
	waitmovement 0
	goto MurenaCity_Shipyard_EventScript_Fisherman_1

MurenaCity_Shipyard_EventScript_Fisherman_5:
	load_speech_bubble 2
	msgbox MurenaCity_Shipyard_EventScript_Fisherman_Text_1
	destroy_speech_bubble
	closemessage
	goto MurenaCity_Shipyard_EventScript_SailToLitorTown
	return

MurenaCity_Shipyard_EventScript_Fisherman_6:
	goto MurenaCity_Shipyard_EventScript_CancelFerrySelect
	return

MurenaCity_Shipyard_EventScript_Fisherman_7:
	goto MurenaCity_Shipyard_EventScript_CancelFerrySelect
	return


MurenaCity_Shipyard_EventScript_CancelFerrySelect::
	load_speech_bubble 2
	msgbox MurenaCity_Shipyard_EventScript_CancelFerrySelect_Text_0
	destroy_speech_bubble
	closemessage
	release
	end


MurenaCity_Shipyard_EventScript_SailToLitorTown::
	call FishermanFerry_EventScript_BackupFerryLocation
	setobjectpriority 2, MAP_MURENA_CITY_SHIPYARD, 0
	setobjectpriority OBJ_EVENT_ID_PLAYER, MAP_MURENA_CITY_SHIPYARD, 0
	applymovement 2, MurenaCity_Shipyard_Movement_FishermanBoardBoat
	waitmovement 0
	removeobject 2
	applymovement OBJ_EVENT_ID_PLAYER, MurenaCity_Shipyard_Movement_PlayerBoardBoat
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_MURENA_CITY_SHIPYARD
	delay 24
	applymovement 1, MurenaCity_Shipyard_Movement_BoatExitShipyard
	waitmovement 0
	setvar VAR_FISHERMAN_FERRY_STATE, 1
	warpsilent MAP_MURENA_CITY, 0xFF, 32, 26
	waitstate
	end


MurenaCity_Shipyard_EventScript_Man::
	msgbox MurenaCity_Shipyard_EventScript_Man_Text_0, MSGBOX_NPC
	applymovement 3, Common_Movement_FaceUp
	waitmovement 0
	end


MurenaCity_Shipyard_Movement_PlayerWalkToFisherman:
	walk_down
	walk_left
	face_up
	step_end

MurenaCity_Shipyard_Movement_FishermanBoardBoat:
	disable_jump_landing_ground_effect
	face_left
	delay_16
	jump_left
	enable_jump_landing_ground_effect
	step_end

MurenaCity_Shipyard_Movement_PlayerBoardBoat:
	disable_jump_landing_ground_effect
	walk_up
	face_left
	delay_16
	walk_in_place_fastest_left
	walk_in_place_fastest_left
	walk_in_place_fastest_left
	jump_left
	enable_jump_landing_ground_effect
	step_end

MurenaCity_Shipyard_Movement_BoatExitShipyard:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MurenaCity_Shipyard_EventScript_FinishSailToMurena_Text_0:
	.string "Ahoy! We've hit the docks of MURENA!\n"
	.string "Just come back to me if you need a ride!$"

MurenaCity_Shipyard_EventScript_Fisherman_Text_0:
	.string "Hey there {PLAYER}!\n"
	.string "So…\p"
	.string "Wanna head to LITOR TOWN?$"

MurenaCity_Shipyard_EventScript_Fisherman_Text_1:
	.string "Alright!\n"
	.string "We're headed to LITOR TOWN!$"

MurenaCity_Shipyard_EventScript_CancelFerrySelect_Text_0:
	.string "Tell me whenever you need me\n"
	.string "and my trusty boat.$"

MurenaCity_Shipyard_EventScript_Man_Text_0:
	.string "Hey there!\n"
	.string "Every day I check the sonar sensors\l"
	.string "for any detections.\p"
	.string "If there's too much rubble, no ships\n"
	.string "are allowed to leave.$"
