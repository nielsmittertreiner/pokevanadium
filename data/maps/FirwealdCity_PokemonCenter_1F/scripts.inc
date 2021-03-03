FirwealdCity_PokemonCenter_1F_MapScripts::
	.byte 0


FirwealdCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	msgbox FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_0, MSGBOX_NPC
	load_speech_bubble 1
	msgbox FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_1, MSGBOX_YESNO
	destroy_speech_bubble
	switch VAR_RESULT
	case YES, FirwealdCity_PokemonCenter_1F_EventScript_Nurse_3
	case NO, FirwealdCity_PokemonCenter_1F_EventScript_Nurse_4
FirwealdCity_PokemonCenter_1F_EventScript_Nurse_1:
	msgbox FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_5, MSGBOX_NPC
	end

FirwealdCity_PokemonCenter_1F_EventScript_Nurse_3:
	incrementgamestat GAME_STAT_USED_POKECENTER
	msgbox FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_2, MSGBOX_NPC
	applymovement 1, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	special HealPlayerParty
	goto_if_unset FLAG_POKERUS_EXPLAINED, FirwealdCity_PokemonCenter_1F_EventScript_Nurse_6
	msgbox FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_4, MSGBOX_NPC
	applymovement 1, Common_Movement_NurseBow
	waitmovement 0
FirwealdCity_PokemonCenter_1F_EventScript_Nurse_5:
	goto FirwealdCity_PokemonCenter_1F_EventScript_Nurse_1

FirwealdCity_PokemonCenter_1F_EventScript_Nurse_4:
	goto FirwealdCity_PokemonCenter_1F_EventScript_Nurse_1

FirwealdCity_PokemonCenter_1F_EventScript_Nurse_6:
	specialvar VAR_RESULT, IsPokerusInParty
	compare VAR_RESULT, TRUE
	goto_if_eq FirwealdCity_PokemonCenter_1F_EventScript_Nurse_9
	goto FirwealdCity_PokemonCenter_1F_EventScript_Nurse_5

FirwealdCity_PokemonCenter_1F_EventScript_Nurse_9:
	msgbox FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_3, MSGBOX_NPC
	setflag FLAG_POKERUS_EXPLAINED
	goto FirwealdCity_PokemonCenter_1F_EventScript_Nurse_5


FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_0:
	.string "Welcome to CEDARRED TOWN's\n"
	.string "POKéMON CENTER.$"

FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_1:
	.string "Would you like to rest your POKEMON?$"

FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_2:
	.string "Okay, I'll take your POKéMON\n"
	.string "for a few seconds.$"

FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_3:
	.string "Your POKéMON may be infected with\n"
	.string "POKéRUS.\p"
	.string "Little is known about the POKéRUS\n"
	.string "except that they are microscopic life-\l"
	.string "forms that attach to POKéMON.\p"
	.string "While infected, POKéMON are said to\n"
	.string "grow exceptionally well.$"

FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_4:
	.string "Thank you for waiting.\p"
	.string "We've restored your POKéMON\n"
	.string "to full health.$"

FirwealdCity_PokemonCenter_1F_EventScript_Nurse_Text_5:
	.string "Thanks you for visiting\n"
	.string "CEDARRED TOWN's POKEMON CENTER!$"
