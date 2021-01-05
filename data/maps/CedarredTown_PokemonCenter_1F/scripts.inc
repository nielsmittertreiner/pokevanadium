CedarredTown_PokemonCenter_1F_MapScripts::
	.byte 0


CedarredTown_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	msgbox CedarredTown_PokemonCenter_1F_EventScript_Nurse_Text_0, MSGBOX_NPC
	load_speech_bubble 1
	msgbox CedarredTown_PokemonCenter_1F_EventScript_Nurse_Text_1, MSGBOX_YESNO
	destroy_speech_bubble
	switch VAR_RESULT
	case YES, CedarredTown_PokemonCenter_1F_EventScript_Nurse_3
	case NO, CedarredTown_PokemonCenter_1F_EventScript_Nurse_4
CedarredTown_PokemonCenter_1F_EventScript_Nurse_1:
	msgbox CedarredTown_PokemonCenter_1F_EventScript_Nurse_Text_5, MSGBOX_NPC
	end

CedarredTown_PokemonCenter_1F_EventScript_Nurse_3:
	incrementgamestat GAME_STAT_USED_POKECENTER
	msgbox CedarredTown_PokemonCenter_1F_EventScript_Nurse_Text_2, MSGBOX_NPC
	applymovement 1, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	special HealPlayerParty
	goto_if_unset FLAG_POKERUS_EXPLAINED, CedarredTown_PokemonCenter_1F_EventScript_Nurse_6
	msgbox CedarredTown_PokemonCenter_1F_EventScript_Nurse_Text_4, MSGBOX_NPC
	applymovement 1, Common_Movement_NurseBow
	waitmovement 0
CedarredTown_PokemonCenter_1F_EventScript_Nurse_5:
	goto CedarredTown_PokemonCenter_1F_EventScript_Nurse_1

CedarredTown_PokemonCenter_1F_EventScript_Nurse_4:
	goto CedarredTown_PokemonCenter_1F_EventScript_Nurse_1

CedarredTown_PokemonCenter_1F_EventScript_Nurse_6:
	specialvar VAR_RESULT, IsPokerusInParty
	compare VAR_RESULT, TRUE
	goto_if_eq CedarredTown_PokemonCenter_1F_EventScript_Nurse_9
	goto CedarredTown_PokemonCenter_1F_EventScript_Nurse_5

CedarredTown_PokemonCenter_1F_EventScript_Nurse_9:
	msgbox CedarredTown_PokemonCenter_1F_EventScript_Nurse_Text_3, MSGBOX_NPC
	setflag FLAG_POKERUS_EXPLAINED
	goto CedarredTown_PokemonCenter_1F_EventScript_Nurse_5


CedarredTown_PokemonCenter_1F_EventScript_HealingTerminal::
	lock
	goto_if_unset FLAG_BADGE03_GET, CedarredTown_PokemonCenter_1F_EventScript_HealingTerminal_3
	checkitem ITEM_TERMINAL_PASS, 1
	compare VAR_RESULT, FALSE
	goto_if_eq CedarredTown_PokemonCenter_1F_EventScript_HealingTerminal_7
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	msgbox CedarredTown_PokemonCenter_1F_EventScript_HealingTerminal_Text_2
	waitmovement 0
	closemessage
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	load_speech_bubble 1
	msgbox CedarredTown_PokemonCenter_1F_EventScript_HealingTerminal_Text_3
	destroy_speech_bubble
	closemessage
	applymovement 1, Common_Movement_NurseBow
	waitmovement 0
	release
	end

CedarredTown_PokemonCenter_1F_EventScript_HealingTerminal_3:
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	load_speech_bubble 1
	msgbox CedarredTown_PokemonCenter_1F_EventScript_HealingTerminal_Text_0
	destroy_speech_bubble
	closemessage
	applymovement 1, Common_Movement_NurseBow
	waitmovement 0
	release
	end

CedarredTown_PokemonCenter_1F_EventScript_HealingTerminal_7:
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	load_speech_bubble 1
	msgbox CedarredTown_PokemonCenter_1F_EventScript_HealingTerminal_Text_1
	destroy_speech_bubble
	closemessage
	applymovement 1, Common_Movement_NurseBow
	waitmovement 0
	release
	end


CedarredTown_PokemonCenter_1F_EventScript_GameBoyKid::
	msgbox CedarredTown_PokemonCenter_1F_EventScript_GameBoyKid_Text_0, MSGBOX_NPC
	turnobject 3, DIR_SOUTH
	end


CedarredTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox CedarredTown_PokemonCenter_1F_EventScript_Youngster_Text_0, MSGBOX_NPC
	end


CedarredTown_PokemonCenter_1F_EventScript_Nurse_Text_0:
	.string "Welcome to CEDARRED TOWN's\n"
	.string "POKéMON CENTER.$"

CedarredTown_PokemonCenter_1F_EventScript_Nurse_Text_1:
	.string "Would you like to rest your POKEMON?$"

CedarredTown_PokemonCenter_1F_EventScript_Nurse_Text_2:
	.string "Okay, I'll take your POKéMON\n"
	.string "for a few seconds.$"

CedarredTown_PokemonCenter_1F_EventScript_Nurse_Text_3:
	.string "Your POKéMON may be infected with\n"
	.string "POKéRUS.\p"
	.string "Little is known about the POKéRUS\n"
	.string "except that they are microscopic life-\l"
	.string "forms that attach to POKéMON.\p"
	.string "While infected, POKéMON are said to\n"
	.string "grow exceptionally well.$"

CedarredTown_PokemonCenter_1F_EventScript_Nurse_Text_4:
	.string "Thank you for waiting.\p"
	.string "We've restored your POKéMON\n"
	.string "to full health.$"

CedarredTown_PokemonCenter_1F_EventScript_Nurse_Text_5:
	.string "Thanks you for visiting\n"
	.string "CEDARRED TOWN's POKEMON CENTER!$"

CedarredTown_PokemonCenter_1F_EventScript_HealingTerminal_Text_0:
	.string "The POKéMON CENTER TERMINAL is\n"
	.string "still undergoing maintenance…\p"
	.string "I'm sorry for the inconvenience.$"

CedarredTown_PokemonCenter_1F_EventScript_HealingTerminal_Text_1:
	.string "You need a TERMINAL PASS to be able to\n"
	.string "operate the POKéMON CENTER TERMINAL…\p"
	.string "I'm sorry for the inconvenience.$"

CedarredTown_PokemonCenter_1F_EventScript_HealingTerminal_Text_2:
	.string "{PLAYER} swiped the TERMINAL PASS…$"

CedarredTown_PokemonCenter_1F_EventScript_HealingTerminal_Text_3:
	.string "Thank you for using our\n"
	.string "POKéMON CENTER TERMINAL!$"

CedarredTown_PokemonCenter_1F_EventScript_GameBoyKid_Text_0:
	.string "Hey, stop distracting me.\p"
	.string "I'm playing POKéMON: VANADIUM VERSION!$"

CedarredTown_PokemonCenter_1F_EventScript_Youngster_Text_0:
	.string "I got wiped out in ACREN FOREST…\n"
	.string "That girl LADA is really strong!$"
