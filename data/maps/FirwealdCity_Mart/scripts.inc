FirwealdCity_Mart_MapScripts::
	.byte 0


FirwealdCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	load_speech_bubble 1
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	destroy_speech_bubble
	msgbox gText_PleaseComeAgain, MSGBOX_NPC
	release
	end


FirwealdCity_Mart_EventScript_Fisherman::
	lock
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	faceplayer
	load_speech_bubble 2
	msgbox FirwealdCity_Mart_EventScript_Fisherman_Text_0, MSGBOX_DEFAULT
	destroy_speech_bubble
	closemessage
	compare VAR_FACING, DIR_NORTH
	goto_if_eq FirwealdCity_Mart_EventScript_Fisherman_2
FirwealdCity_Mart_EventScript_Fisherman_1:
	applymovement 2, FirwealdCity_Mart_Movement_FishermanWalkToEmployee
	waitmovement 0
	load_speech_bubble 2
	msgbox FirwealdCity_Mart_EventScript_Fisherman_Text_1, MSGBOX_DEFAULT
	destroy_speech_bubble
	closemessage
	turnobject 1, DIR_SOUTH
	applymovement 2, FirwealdCity_Mart_Movement_FishermanWalkToExit
	waitmovement 0
	playse SE_EXIT
	removeobject 2, MAP_FIRWEALD_CITY_MART
	clearflag FLAG_HIDE_FIRWEALD_CITY_FISHERMAN
	release
	end

FirwealdCity_Mart_EventScript_Fisherman_2:
	applymovement OBJ_EVENT_ID_PLAYER, FirwealdCity_Mart_Movement_PlayerWalkDownBackwards
	waitmovement 0
	goto FirwealdCity_Mart_EventScript_Fisherman_1


FirwealdCity_Mart_EventScript_Triathlete::
	msgbox FirwealdCity_Mart_EventScript_Triathlete_Text_0, MSGBOX_NPC
	end


FirwealdCity_Mart_Movement_FishermanWalkToEmployee:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	face_up
	step_end

FirwealdCity_Mart_Movement_PlayerWalkDownBackwards:
	lock_facing_direction
	walk_down
	step_end

FirwealdCity_Mart_Movement_FishermanWalkToExit:
	walk_down
	walk_down
	walk_down
	step_end

FirwealdCity_Mart_EventScript_Fisherman_Text_0:
	.string "Ah, there it is!\p"
	.string "Some high quality fishing bait.\p"
	.string "Now I hope I can catch that GOLDEEN!$"

FirwealdCity_Mart_EventScript_Fisherman_Text_1:
	.string "Thanks a lot!\n"
	.string "Have a nice day!$"

FirwealdCity_Mart_EventScript_Triathlete_Text_0:
	.string "I love the new POKENERGY drink\n"
	.string "that's being sold now!\p"
	.string "It tastes so good!$"
