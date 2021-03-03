CedarredTown_Mart_MapScripts::
	.byte 0


CedarredTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEMON_GET, CedarredTown_Mart_EventScript_Clerk_3
	load_speech_bubble 1
	message gText_HowMayIServeYou
	waitmessage
	pokemart CedarredTown_Mart_Pokemart
	destroy_speech_bubble
	msgbox gText_PleaseComeAgain, MSGBOX_NPC
	release
	end

CedarredTown_Mart_EventScript_Clerk_3:
	msgbox CedarredTown_Mart_EventScript_Clerk_Text_0, MSGBOX_NPC
	end


CedarredTown_Mart_Pokemart:
    .2byte ITEM_POKE_BALL
    .2byte ITEM_POTION
    .2byte ITEM_ANTIDOTE
    .2byte ITEM_PARALYZE_HEAL
    .2byte ITEM_AWAKENING
    .2byte ITEM_NONE
    release
    end

CedarredTown_Mart_EventScript_Gentleman::
	msgbox CedarredTown_Mart_EventScript_Gentleman_Text_0, MSGBOX_NPC
	end


CedarredTown_Mart_EventScript_Clerk_Text_0:
	.string "It's seems that you don't have\n"
	.string "any POKéMON…\p"
	.string "Come back when you have one.$"

CedarredTown_Mart_EventScript_Gentleman_Text_0:
	.string "Did you know CEDARRED TOWN is\n"
	.string "renowned in the far away region\l"
	.string "of SINNOH?\p"
	.string "It reminds me of SANDGEM TOWN in\n"
	.string "a way…$"
