TentacoolSkewer_EventScript_ItemUseTentacoolSkewer::
	specialvar VAR_RESULT, IsPlayerInMurenaCity
	compare VAR_RESULT, TRUE
	goto_if_eq TentacoolSkewer_EventScript_ItemUseTentacoolSkewer_2
	special TentacoolSkewerIncreaseFriendship
	msgbox TentacoolSkewer_EventScript_ItemUseTentacoolSkewer_Text_1
	closemessage
	end

TentacoolSkewer_EventScript_ItemUseTentacoolSkewer_2:
	fadescreenspeed FADE_TO_WHITE, -1
	fadescreenspeed FADE_FROM_WHITE, -1
	special SpawnMurenaCityWingullObject
	delay 24
	msgbox TentacoolSkewer_EventScript_ItemUseTentacoolSkewer_Text_0
	closemessage
	playmoncry SPECIES_WINGULL, 1
	waitmoncry
	delay 10
	setwildbattle SPECIES_WINGULL, 15, ITEM_TENTACOOL_SKEWER
	dowildbattle
	fadescreen FADE_TO_BLACK
	removeobject 16
	fadescreen FADE_FROM_BLACK
	end


TentacoolSkewer_EventScript_ItemUseTentacoolSkewer_Text_0:
	.string "A WINGULL swooped to snatch your\n"
	.string "TENTACOOL SKEWER!$"

TentacoolSkewer_EventScript_ItemUseTentacoolSkewer_Text_1:
	.string "The TENTACOOL SKEWER tasted just\n"
	.string "like heaven!\p"
	.string "Your POKéMON feel delighted.$"
