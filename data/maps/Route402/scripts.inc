Route402_MapScripts::
	.byte 0


Route402_EventScript_RouteSign::
	msgbox Route402_EventScript_RouteSign_Text_0, MSGBOX_SIGN
	end


Route402_EventScript_Boy::
	msgbox Route402_EventScript_Boy_Text_0, MSGBOX_NPC
	end


Route402_EventScript_Triathlete::
	msgbox Route402_EventScript_Triathlete_Text_0, MSGBOX_NPC
	end


Route402_EventScript_Fisherman1::
	msgbox Route402_EventScript_Fisherman1_Text_0, MSGBOX_NPC
	end


Route402_EventScript_Fisherman2::
	goto_if_unset FLAG_TEMP_1, Route402_EventScript_Fisherman2_3
	msgbox Route402_EventScript_Fisherman2_Text_1, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end

Route402_EventScript_Fisherman2_3:
	playse SE_PIN
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Route402_EventScript_Fisherman2_Text_0, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end


Route402_EventScript_Timmy::
	trainerbattle_single TRAINER_ROUTE_402_TIMMY, Route402_Text_TimmyIntro, Route402_Text_TimmyDefeat
	msgbox Route402_Text_TimmyPostBattle, MSGBOX_NPC
	end


Route402_EventScript_Mimi::
	trainerbattle_double TRAINER_ROUTE_402_TWINS_MIMI_AND_MOMO, Route402_Text_MimiIntro, Route402_Text_MimiDefeat, Route402_Text_MimiNotEnoughMons
	msgbox Route402_Text_MimiPostBattle, MSGBOX_NPC
	end


Route402_EventScript_Momo::
	trainerbattle_double TRAINER_ROUTE_402_TWINS_MIMI_AND_MOMO, Route402_Text_MomoIntro, Route402_Text_MomoDefeat, Route402_Text_MomoNotEnoughMons
	msgbox Route402_Text_MomoPostBattle, MSGBOX_NPC
	end


Route402_EventScript_RouteSign_Text_0:
	.string "{UP_ARROW} FIRWEALD CITY\n"
	.string "{DOWN_ARROW} ACREN FOREST$"

Route402_EventScript_Boy_Text_0:
	.string "Sniff sniff...\n"
	.string "Why did my parents move to this area?\p"
	.string "I have allergies...\p"
	.string "Achoo!$"

Route402_EventScript_Triathlete_Text_0:
	.string "Every day I run along this small lake.\n"
	.string "The fresh air helps me run for longer!$"

Route402_EventScript_Fisherman1_Text_0:
	.string "I don't get a bite often with my OLD ROD…$"

Route402_EventScript_Fisherman2_Text_0:
	.string "Did I just catch a glimpse of a GYARADOS!$"

Route402_EventScript_Fisherman2_Text_1:
	.string "Did you just see that too?!$"
