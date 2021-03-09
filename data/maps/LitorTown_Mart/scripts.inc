LitorTown_Mart_MapScripts::
	.byte 0


LitorTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	load_speech_bubble 1
	message gText_HowMayIServeYou
	waitmessage
	pokemart LitorTown_Mart_Pokemart
	destroy_speech_bubble
	msgbox gText_PleaseComeAgain, MSGBOX_NPC
	release
	end


LitorTown_Mart_Pokemart:
    .2byte ITEM_POKE_BALL
    .2byte ITEM_GREAT_BALL
    .2byte ITEM_POTION
    .2byte ITEM_SUPER_POTION
    .2byte ITEM_REPEL
    .2byte ITEM_ANTIDOTE
    .2byte ITEM_PARALYZE_HEAL
    .2byte ITEM_AWAKENING
    .2byte ITEM_FLUFFY_TAIL
    .2byte ITEM_NONE
    release
    end

LitorTown_Mart_EventScript_Youngster::
	msgbox LitorTown_Mart_EventScript_Youngster_Text_0, MSGBOX_NPC
	end


LitorTown_Mart_EventScript_Youngster_Text_0:
	.string "Wow! Look at all the soda they\n"
	.string "sell here!\p"
	.string "It looks so delicious!$"
