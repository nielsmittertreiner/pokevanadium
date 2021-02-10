AcrenForest_IllegalCabin_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AcrenForest_IllegalCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

AcrenForest_IllegalCabin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ACREN_FOREST_STATE, 6, AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene
	.2byte 0


AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene::
	applymovement OBJ_EVENT_ID_PLAYER, AcrenForest_IllegalCabin_Movement_PlayerWalkForward
	waitmovement 0
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	delay 12
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	delay 12
	playse SE_PIN
	applymovement 3, Common_Movement_ExclamationMark
	delay 12
	playse SE_PIN
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, AcrenForest_IllegalCabin_Movement_Grunt1RunToPlayer
	delay 4
	applymovement 2, AcrenForest_IllegalCabin_Movement_Grunt2RunToPlayer
	delay 4
	applymovement 3, AcrenForest_IllegalCabin_Movement_Grunt3RunToPlayer
	delay 4
	applymovement 4, AcrenForest_IllegalCabin_Movement_Grunt4RunToPlayer
	delay 4
	waitmovement 0
	load_speech_bubble 1
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_0
	destroy_speech_bubble
	closemessage
	applymovement 1, Common_Movement_QuestionMark
	delay 60
	waitmovement 0
	load_speech_bubble 1
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_1
	destroy_speech_bubble
	closemessage
	applymovement 1, AcrenForest_IllegalCabin_Movement_Grunt1LookAround
	waitmovement 0
	load_speech_bubble 1
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_2
	destroy_speech_bubble
	closemessage
	delay 16
	addobject 5
	setobjectxy 5, 14, 8
	playse SE_EXIT
	delay 8
	applymovement 5, AcrenForest_IllegalCabin_Movement_PhyllosWalkForward
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	load_speech_bubble 5
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_3
	destroy_speech_bubble
	closemessage
	load_speech_bubble 1
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_4
	destroy_speech_bubble
	closemessage
	applymovement 5, Common_Movement_FaceLeft
	waitmovement 0
	load_speech_bubble 5
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_5
	destroy_speech_bubble
	closemessage
	applymovement 5, Common_Movement_FaceUp
	waitmovement 0
	load_speech_bubble 5
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_6
	destroy_speech_bubble
	closemessage
	applymovement 5, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	playse SE_BALL_THROW
	delay 12
	addobject 6
	setobjectxy 6, 13, 6
	delay 12
	playse SE_BALL_OPEN
	fadescreenspeed FADE_TO_WHITE, -1
	delay 12
	removeobject 6
	setobjectmovementtype 7, MOVEMENT_TYPE_FACE_LEFT
	addobject 7
	setobjectxy 7, 13, 6
	fadescreenspeed FADE_FROM_WHITE, -1
	playmoncry SPECIES_KECLEON, 0
	waitmoncry
	applymovement 7, Common_Movement_WalkFastestLeft
	fadescreenspeed FADE_TO_WHITE, -4
	waitmovement 0
	playse SE_M_RAZOR_WIND
	delay 16
	playse SE_M_RAZOR_WIND
	delay 16
	playse SE_M_RAZOR_WIND
	delay 16
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_7
	closemessage
	fadescreenspeed FADE_FROM_WHITE, 1
	applymovement 1, AcrenForest_IllegalCabin_Movement_GruntsFallBack
	applymovement 2, AcrenForest_IllegalCabin_Movement_GruntsFallBack
	waitmovement 0
	load_speech_bubble 1
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_8
	destroy_speech_bubble
	closemessage
	applymovement 1, AcrenForest_IllegalCabin_Movement_Grunt1RunOut
	delay 8
	applymovement 2, AcrenForest_IllegalCabin_Movement_Grunt2RunOut
	delay 4
	applymovement 3, AcrenForest_IllegalCabin_Movement_Grunt3RunOut
	delay 16
	applymovement 4, AcrenForest_IllegalCabin_Movement_Grunt4RunOut
	waitmovement 0
	removeobject 1
	removeobject 2
	removeobject 3
	removeobject 4
	load_speech_bubble 5
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_9
	destroy_speech_bubble
	closemessage
	addobject 6
	setobjectxy 6, 13, 6
	delay 16
	playse SE_BALL_OPEN
	fadescreenspeed FADE_TO_WHITE, -1
	delay 4
	removeobject 7
	fadescreenspeed FADE_FROM_WHITE, -1
	applymovement 5, AcrenForest_IllegalCabin_Movement_PhyllosPickUpPokeball
	delay 12
	removeobject 6
	waitmovement 0
	load_speech_bubble 5
	msgbox AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_10
	destroy_speech_bubble
	closemessage
	applymovement 5, Common_Movement_WalkDown2
	waitmovement 0
	playse SE_EXIT
	removeobject 5
	setvar VAR_ACREN_FOREST_STATE, 7
	setflag FLAG_HIDE_ACREN_FOREST_GRUNTS
	setflag FLAG_HIDE_ACREN_FOREST_LOGGERS
	setflag FLAG_HIDE_ACREN_FOREST_PHYLLOS
	clearflag FLAG_PHYLLOS_LEFT_TOURNAMENT_HALL_LOBBY
	release
	end


AcrenForest_IllegalCabin_Movement_PlayerWalkForward:
	walk_up
	walk_up
	walk_up
	face_left
	step_end

AcrenForest_IllegalCabin_Movement_Grunt1RunToPlayer:
	walk_fast_right
	step_end

AcrenForest_IllegalCabin_Movement_Grunt2RunToPlayer:
	walk_fast_right
	step_end

AcrenForest_IllegalCabin_Movement_Grunt3RunToPlayer:
	walk_fast_left
	walk_fast_left
	walk_fast_down
	step_end

AcrenForest_IllegalCabin_Movement_Grunt4RunToPlayer:
	walk_fast_right
	walk_fast_down
	step_end

AcrenForest_IllegalCabin_Movement_Grunt1LookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	step_end

AcrenForest_IllegalCabin_Movement_PhyllosWalkForward:
	walk_up
	walk_up
	step_end

AcrenForest_IllegalCabin_Movement_GruntsFallBack:
	lock_facing_direction
	walk_in_place_fastest_right
	walk_in_place_fastest_right
	walk_fastest_left
	unlock_facing_direction
	step_end

AcrenForest_IllegalCabin_Movement_Grunt1RunOut:
	walk_fastest_down
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_down
	set_invisible
	step_end

AcrenForest_IllegalCabin_Movement_Grunt2RunOut:
	walk_fastest_down
	walk_fastest_down
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_down
	set_invisible
	step_end

AcrenForest_IllegalCabin_Movement_Grunt3RunOut:
	walk_fastest_down
	walk_fastest_left
	walk_fastest_down
	walk_fastest_down
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_down
	set_invisible
	step_end

AcrenForest_IllegalCabin_Movement_Grunt4RunOut:
	walk_fastest_down
	walk_fastest_left
	walk_fastest_down
	walk_fastest_down
	walk_fastest_left
	walk_fastest_down
	set_invisible
	step_end

AcrenForest_IllegalCabin_Movement_PhyllosPickUpPokeball:
	lock_facing_direction
	walk_left
	delay_8
	walk_right
	unlock_facing_direction
	face_up
	step_end

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_0:
	.string "How- how did you get in here!\n"
	.string "Didn't the guards stop you?!\p"
	.string "Hrmph… Fine then…\n"
	.string "I guess the BOSS will have to\l"
	.string "get you out then.$"

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_1:
	.string "Huh? Where's the BOSS gone?$"

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_2:
	.string "Oh no!\n"
	.string "He must have left early!\p"
	.string "Well then-$"

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_3:
	.string "It looks like you've made it…\n"
	.string "I'm not intruding I hope.$"

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_4:
	.string "It's PHYLLOS! The city's\n"
	.string "TOURNAMENT MASTER!$"

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_5:
	.string "I sure am, yes…$"

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_6:
	.string "Now, let's round these boys up\n"
	.string "shall we?…$"

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_7:
	.string "Aaaaahhhh!$"

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_8:
	.string "Everyone! Get out of here!\n"
	.string "Get back to base quickly!$"

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_9:
	.string "Return, KECLEON!$"

AcrenForest_IllegalCabin_EventScript_GruntPhyllosCutscene_Text_10:
	.string "Now that we have that done,\n"
	.string "I suppose you could visit and\l"
	.string "challenge me in FIRWEALD CITY.\p"
	.string "I'll be waiting for you.$"
