Common_EventScript_PkmnCenterNurse::
	special CheckPokeCenterLocation
	load_speech_bubble 1
	msgbox Common_EventScript_PkmnCenterNurse_Text_0
	destroy_speech_bubble
	closemessage
	load_speech_bubble 1
	msgbox Common_EventScript_PkmnCenterNurse_Text_1, MSGBOX_YESNO
	destroy_speech_bubble
	switch VAR_RESULT
	case YES, Common_EventScript_PkmnCenterNurse_3
	case NO, Common_EventScript_PkmnCenterNurse_4
Common_EventScript_PkmnCenterNurse_1:
	msgbox Common_EventScript_PkmnCenterNurse_Text_5, MSGBOX_NPC
	end

Common_EventScript_PkmnCenterNurse_3:
	incrementgamestat GAME_STAT_USED_POKECENTER
	msgbox Common_EventScript_PkmnCenterNurse_Text_2, MSGBOX_NPC
	applymovement 1, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement 1, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	special HealPlayerParty
	goto_if_unset FLAG_POKERUS_EXPLAINED, Common_EventScript_PkmnCenterNurse_6
	msgbox Common_EventScript_PkmnCenterNurse_Text_4, MSGBOX_NPC
	applymovement 1, Common_Movement_NurseBow
	waitmovement 0
Common_EventScript_PkmnCenterNurse_5:
	goto Common_EventScript_PkmnCenterNurse_1

Common_EventScript_PkmnCenterNurse_4:
	goto Common_EventScript_PkmnCenterNurse_1

Common_EventScript_PkmnCenterNurse_6:
	specialvar VAR_RESULT, IsPokerusInParty
	compare VAR_RESULT, TRUE
	goto_if_eq Common_EventScript_PkmnCenterNurse_9
	goto Common_EventScript_PkmnCenterNurse_5

Common_EventScript_PkmnCenterNurse_9:
	msgbox Common_EventScript_PkmnCenterNurse_Text_3, MSGBOX_NPC
	setflag FLAG_POKERUS_EXPLAINED
	goto Common_EventScript_PkmnCenterNurse_5


Common_EventScript_PkmnCenterTerminal::
	checkitem ITEM_TERMINAL_PASS, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_PkmnCenterTerminal_2
Common_EventScript_PkmnCenterTerminal_1:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	msgbox Common_EventScript_PkmnCenterTerminal_Text_0
	waitmovement 0
	closemessage
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	msgbox Common_EventScript_PkmnCenterTerminal_Text_1
	closemessage
	end

Common_EventScript_PkmnCenterTerminal_2:
	goto Common_EventScript_PokemonCenterTerminal_NoTerminalPass
	goto Common_EventScript_PkmnCenterTerminal_1


Common_EventScript_PokemonCenterTerminal_NoTerminalPass::
	msgbox Common_EventScript_PokemonCenterTerminal_NoTerminalPass_Text_0
	closemessage
	end


Common_EventScript_PkmnCenterNurse_Text_0:
	.string "Welcome to {STR_VAR_1}'s\n"
	.string "POKéMON CENTER.$"

Common_EventScript_PkmnCenterNurse_Text_1:
	.string "Would you like to rest your POKEMON?$"

Common_EventScript_PkmnCenterNurse_Text_2:
	.string "Okay, I'll take your POKéMON\n"
	.string "for a few seconds.$"

Common_EventScript_PkmnCenterNurse_Text_3:
	.string "Your POKéMON may be infected with\n"
	.string "POKéRUS.\p"
	.string "Little is known about the POKéRUS\n"
	.string "except that they are microscopic life-\l"
	.string "forms that attach to POKéMON.\p"
	.string "While infected, POKéMON are said to\n"
	.string "grow exceptionally well.$"

Common_EventScript_PkmnCenterNurse_Text_4:
	.string "Thank you for waiting.\p"
	.string "We've restored your POKéMON\n"
	.string "to full health.$"

Common_EventScript_PkmnCenterNurse_Text_5:
	.string "Thanks you for visiting\n"
	.string "{STR_VAR_1}'s POKEMON CENTER!$"

Common_EventScript_PkmnCenterTerminal_Text_0:
	.string "{PLAYER} swiped the TERMINAL PASS…$"

Common_EventScript_PkmnCenterTerminal_Text_1:
	.string "Thank you for using {STR_VAR_1}'s\n"
	.string "POKéMON CENTER TERMINAL!$"

Common_EventScript_PokemonCenterTerminal_NoTerminalPass_Text_0:
	.string "You need a TERMINAL PASS to be able to\n"
	.string "operate the POKéMON CENTER TERMINAL…$"
