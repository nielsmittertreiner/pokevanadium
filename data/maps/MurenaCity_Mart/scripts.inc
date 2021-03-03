MurenaCity_Mart_MapScripts::
	.byte 0


MurenaCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	load_speech_bubble 1
	message gText_HowMayIServeYou
	waitmessage
	pokemart MurenaCity_Mart_Pokemart
	destroy_speech_bubble
	msgbox gText_PleaseComeAgain, MSGBOX_NPC
	release
	end


MurenaCity_Mart_Pokemart:
    .2byte ITEM_POKE_BALL
    .2byte ITEM_GREAT_BALL
    .2byte ITEM_POTION
    .2byte ITEM_SUPER_POTION
    .2byte ITEM_ANTIDOTE
    .2byte ITEM_PARALYZE_HEAL
    .2byte ITEM_HARBOR_MAIL
    .2byte ITEM_NONE
    release
    end

MurenaCity_Mart_EventScript_Gentleman::
	msgbox MurenaCity_Mart_EventScript_Gentleman_Text_0, MSGBOX_NPC
	end


MurenaCity_Mart_EventScript_Gentleman_Text_0:
	.string "The people who work in these\n"
	.string "shops truly work very hard.\l"
	.string "The shelves are always stocked.$"
