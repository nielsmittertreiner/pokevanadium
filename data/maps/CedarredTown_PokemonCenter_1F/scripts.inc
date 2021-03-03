CedarredTown_PokemonCenter_1F_MapScripts::
	.byte 0


CedarredTown_PokemonCenter_1F_EventScript_GameBoyKid::
	msgbox CedarredTown_PokemonCenter_1F_EventScript_GameBoyKid_Text_0, MSGBOX_NPC
	turnobject 3, DIR_SOUTH
	end


CedarredTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox CedarredTown_PokemonCenter_1F_EventScript_Youngster_Text_0, MSGBOX_NPC
	end


CedarredTown_PokemonCenter_1F_EventScript_GameBoyKid_Text_0:
	.string "Hey, stop distracting me.\p"
	.string "I'm playing POKéMON: VANADIUM VERSION!$"

CedarredTown_PokemonCenter_1F_EventScript_Youngster_Text_0:
	.string "I got wiped out in ACREN FOREST…\n"
	.string "That girl LADA is really strong!$"
