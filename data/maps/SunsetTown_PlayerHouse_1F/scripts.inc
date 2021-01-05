SunsetTown_PlayerHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_SUNSET_TOWN_STATE, 1, SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	lock
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	applymovement 2 Common_Movement_FaceUp
	waitmovement 0
	delay 32
	msgbox SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SunsetTown_PlayerHouse_1F_Movement_PlayerWalksToMom
	waitmovement 0
	turnobject 2, DIR_NORTH
	load_speech_bubble 2
	msgbox SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1
	destroy_speech_bubble
	setvar VAR_SUNSET_TOWN_STATE, 2
	release
	end


SunsetTown_PlayerHouse_1F_EventScript_OpenGift::
	lock
	removeobject 1, MAP_SUNSET_TOWN_PLAYER_HOUSE_1F
	playfanfare MUS_OBTAIN_ITEM
	msgbox SunsetTown_PlayerHouse_1F_EventScript_OpenGift_Text_0
	waitfanfare
	msgbox SunsetTown_PlayerHouse_1F_EventScript_OpenGift_Text_1
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement 2, SunsetTown_PlayerHouse_1F_Movement_MomWalksToPlayer
	waitmovement 0
	setvar VAR_LAST_TALKED, 2
	msgbox SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1, MSGBOX_NPC
	applymovement 2, SunsetTown_PlayerHouse_1F_Movement_MomWalksToTable
	waitmovement 0
	delay 32
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	turnobject 2, DIR_NORTH
	waitmovement 0
	msgbox SunsetTown_PlayerHouse_1F_EventScript_OpenGift_Text_2, MSGBOX_NPC
	turnobject 2, DIR_WEST
	setflag FLAG_SYS_B_DASH
	setvar VAR_SUNSET_TOWN_STATE, 3
	release
	end


SunsetTown_PlayerHouse_1F_EventScript_PreventWanderOff::
	lock
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	setvar VAR_LAST_TALKED, 2
	msgbox SunsetTown_PlayerHouse_1F_EventScript_PreventWanderOff_Text_0, MSGBOX_NPC
	switch VAR_FACING
	case DIR_NORTH, SunsetTown_PlayerHouse_1F_EventScript_PreventWanderOff_2
	case DIR_EAST, SunsetTown_PlayerHouse_1F_EventScript_PreventWanderOff_3
	return

SunsetTown_PlayerHouse_1F_EventScript_PreventWanderOff_2:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	return

SunsetTown_PlayerHouse_1F_EventScript_PreventWanderOff_3:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	return


SunsetTown_PlayerHouse_1F_Movement_PlayerWalksToMom:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

SunsetTown_PlayerHouse_1F_Movement_MomWalksToPlayer:
	walk_up
	walk_left
	step_end

SunsetTown_PlayerHouse_1F_Movement_MomWalksToTable:
	walk_right
	walk_down
	face_left
	step_end

SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
	.string "Come here, quickly!$"

SunsetTown_PlayerHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1:
	.string "Do you like the new RUNNING SHOES?\p"
	.string "You said you wanted these and they look\n"
	.string "very good on you!$"

SunsetTown_PlayerHouse_1F_EventScript_OpenGift_Text_0:
	.string "{PLAYER} zipped on the RUNNING SHOES!$"

SunsetTown_PlayerHouse_1F_EventScript_OpenGift_Text_1:
	.string "Press the B-BUTTON to put a zip in your\n"
	.string "step and race in the great outdoors.$"

SunsetTown_PlayerHouse_1F_EventScript_OpenGift_Text_2:
	.string "Oh, and I've heard that DAD\n"
	.string "had a letter for you too.\p"
	.string "You know you can always find him in\n"
	.string "his POKéMON LAB.$"

SunsetTown_PlayerHouse_1F_EventScript_PreventWanderOff_Text_0:
	.string "Aren't you gonna open your gift?$"
