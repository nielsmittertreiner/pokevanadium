SunsetTown_ProfessorConiferLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_BLOCK_SUNSET_TOWN_NURSERY, SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setobjectxyperm 1, 2, 2
	setobjectxyperm 2, 3, 2
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_DOWN
	return

SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_SUNSET_TOWN_STATE, 1, SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
	setobjectxy 3, 12, 8
	return

SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_SUNSET_TOWN_STATE, 1, SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	lock
	applymovement 3, SunsetTown_ProfessorConiferLab_Movement_ConiferWalkToMachine
	applymovement OBJ_EVENT_ID_PLAYER, SunsetTown_ProfessorConiferLab_Movement_PlayerWalkToMachine
	waitmovement 0
	turnobject 3, DIR_EAST
	delay 16
	load_speech_bubble 3
	msgbox SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0
	destroy_speech_bubble
	closemessage
	addobject 3, MAP_SUNSET_TOWN
	setvar VAR_SUNSET_TOWN_STATE, 2
	warp MAP_SUNSET_TOWN, 0xFF, 15, 8
	waitstate
	end


SunsetTown_ProfessorConiferLab_EventScript_Conifer::
	compare VAR_ACREN_FOREST_STATE, 1
	goto_if_eq SunsetTown_ProfessorConiferLab_EventScript_Conifer_2
	msgbox SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_5, MSGBOX_NPC
	end

SunsetTown_ProfessorConiferLab_EventScript_Conifer_2:
	lock
	faceplayer
	playse SE_PIN
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	load_speech_bubble 3
	msgbox SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_0
	destroy_speech_bubble
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	msgbox SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_1
	waitfanfare
	closemessage
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_NATIONAL_DEX
	special SetUnlockedPokedexFlags
	special EnableNationalPokedex
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	setvar VAR_ACREN_FOREST_STATE, 2
	load_speech_bubble 3
	msgbox SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_2
	destroy_speech_bubble
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	msgbox SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_3
	waitfanfare
	closemessage
	setflag FLAG_SYS_B_DASH
	load_speech_bubble 3
	msgbox SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_4
	destroy_speech_bubble
	closemessage
	release
	end


SunsetTown_ProfessorConiferLab_EventScript_Scientist1::
	goto_if_set FLAG_BLOCK_SUNSET_TOWN_NURSERY, SunsetTown_ProfessorConiferLab_EventScript_Scientist1_3
	msgbox SunsetTown_ProfessorConiferLab_EventScript_Scientist1_Text_1, MSGBOX_NPC
	end

SunsetTown_ProfessorConiferLab_EventScript_Scientist1_3:
	msgbox SunsetTown_ProfessorConiferLab_EventScript_Scientist1_Text_0, MSGBOX_NPC
	end


SunsetTown_ProfessorConiferLab_EventScript_Scientist2::
	goto_if_set FLAG_BLOCK_SUNSET_TOWN_NURSERY, SunsetTown_ProfessorConiferLab_EventScript_Scientist2_3
	msgbox SunsetTown_ProfessorConiferLab_EventScript_Scientist2_Text_0, MSGBOX_NPC
	end

SunsetTown_ProfessorConiferLab_EventScript_Scientist2_3:
	msgbox SunsetTown_ProfessorConiferLab_EventScript_Scientist1_Text_0, MSGBOX_NPC
	end


SunsetTown_ProfessorConiferLab_Movement_ConiferWalkToMachine:
	face_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SunsetTown_ProfessorConiferLab_Movement_PlayerWalkToMachine:
	face_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SunsetTown_ProfessorConiferLab_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
	.string "I just got word of one of my aides.\n"
	.string "It's about a raid in the forest\l"
	.string "nearby CEDARRED TOWN.\p"
	.string "Supposedly the POKéMON who got\n"
	.string "rescued are being held safe in the\l"
	.string "LOGGERS CABIN in CEDARRED TOWN.\p"
	.string "We should take a look and see if all\n"
	.string "is okay there…$"

SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_0:
	.string "Hey there, {PLAYER}.\p"
	.string "… … … … … … … … …\n"
	.string "… … … … … … … … …\p"
	.string "Oh, I see!\n"
	.string "You don't have a POKéDEX yet.\p"
	.string "Luckily, I have one right here for you.\p"
	.string "Go ahead and take it, it's yours.$"

SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_1:
	.string "{PLAYER} received the POKéDEX from\n"
	.string "PROFESSOR CONIFER!$"

SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_2:
	.string "Now that you have a POKéDEX, I can\n"
	.string "register you as an official\l"
	.string "POKéMON TRAINER.\p"
	.string "Hold on a minute…\n"
	.string "Do you still have those old shoes?\l"
	.string "Well, I wanted to give you new ones\l"
	.string "anyway…$"

SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_3:
	.string "{PLAYER} received the RUNNING SHOES from\n"
	.string "PROFESSOR CONIFER!$"

SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_4:
	.string "I think you have some business\n"
	.string "to to now…$"

SunsetTown_ProfessorConiferLab_EventScript_Conifer_Text_5:
	.string "Hey there, {PLAYER}.\n"
	.string "I see you're finally going on an\l"
	.string "adventure now.\p"
	.string "I won't stop you!\p"
	.string "Have fun and take care of your POKéMON.$"

SunsetTown_ProfessorConiferLab_EventScript_Scientist1_Text_0:
	.string "Sorry, but we can't let you in the\n"
	.string "POKéMON NURSERY right now…$"

SunsetTown_ProfessorConiferLab_EventScript_Scientist1_Text_1:
	.string "Usually, I operate this big machine\n"
	.string "used for researching POKéMON.\p"
	.string "It's very interesting work to do!$"

SunsetTown_ProfessorConiferLab_EventScript_Scientist2_Text_0:
	.string "Working at PROFESSOR CONIFER's\n"
	.string "NURSERY is very exciting work.\p"
	.string "Learning about POKéMON is so fun.$"
