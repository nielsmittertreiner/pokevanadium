SunsetTown_PlayerHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SunsetTown_PlayerHouse_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SunsetTown_PlayerHouse_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_SUNSET_TOWN_STATE, 0, SunsetTown_PlayerHouse_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

SunsetTown_PlayerHouse_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	lock
	setvar VAR_LAST_TALKED, 1
	load_speech_bubble 217, 34
	msgbox SunsetTown_PlayerHouse_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0
	destroy_speech_bubble
	closemessage
	playse SE_EXIT
	addobject 1
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 32
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	applymovement 1, SunsetTown_PlayerHouse_2F_Movement_MomWalksIntoRoom
	waitmovement 0
	load_speech_bubble 137, 82
	msgbox SunsetTown_PlayerHouse_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1
	destroy_speech_bubble
	closemessage
	applymovement 1, SunsetTown_PlayerHouse_2F_Movement_MomWalksToStairs
	waitmovement 0
	load_speech_bubble 201, 50
	msgbox SunsetTown_PlayerHouse_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2
	destroy_speech_bubble
	closemessage
	applymovement 1, SunsetTown_PlayerHouse_2F_Movement_MomWalksOutOfRoom
	waitmovement 0
	playse SE_EXIT
	removeobject 1, MAP_SUNSET_TOWN_PLAYER_HOUSE_2F
	setvar VAR_SUNSET_TOWN_STATE, 1
	release
	end


SunsetTown_PlayerHouse_2F_EventScript_CheckPlayersPC::
	setvar VAR_0x8004, 1
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC
	special BedroomPC
	waitstate
	release
	end


SunsetTown_PlayerHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, 1
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end


SunsetTown_PlayerHouse_2F_Movement_MomWalksIntoRoom:
	walk_down
	walk_in_place_down
	delay_16
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SunsetTown_PlayerHouse_2F_Movement_MomWalksToStairs:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	face_down
	step_end

SunsetTown_PlayerHouse_2F_Movement_MomWalksOutOfRoom:
	walk_up
	walk_in_place_up
	step_end

SunsetTown_PlayerHouse_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
	.string "{PLAYER}!\n"
	.string "Are you awake yet?$"

SunsetTown_PlayerHouse_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1:
	.string "{PLAYER}, I want you to come\n"
	.string "downstairs in a minute\p"
	.string "I have something to show you!$"

SunsetTown_PlayerHouse_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2:
	.string "Oh, and don't forget to check\n"
	.string "the items in your PC…$"
