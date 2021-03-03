MurenaCity_WailordFishingClub_MapScripts::
	.byte 0


MurenaCity_WailordFishingClub_EventScript_ChairmanSign::
	msgbox MurenaCity_WailordFishingClub_EventScript_ChairmanSign_Text_0, MSGBOX_SIGN
	end


MurenaCity_WailordFishingClub_EventScript_Chairman::
	msgbox MurenaCity_WailordFishingClub_EventScript_Chairman_Text_0, MSGBOX_NPC
	end


MurenaCity_WailordFishingClub_EventScript_Sailor::
	msgbox MurenaCity_WailordFishingClub_EventScript_Sailor_Text_0, MSGBOX_NPC
	end


MurenaCity_WailordFishingClub_EventScript_Fisherman::
	lock
	applymovement 3, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	load_speech_bubble 3
	msgbox MurenaCity_WailordFishingClub_EventScript_Fisherman_Text_0
	destroy_speech_bubble
	closemessage
	load_speech_bubble 4
	applymovement 4, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox MurenaCity_WailordFishingClub_EventScript_Fisherman_Text_1
	destroy_speech_bubble
	closemessage
	applymovement 3, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	load_speech_bubble 3
	msgbox MurenaCity_WailordFishingClub_EventScript_Fisherman_Text_2
	destroy_speech_bubble
	closemessage
	applymovement 4, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	load_speech_bubble 4
	msgbox MurenaCity_WailordFishingClub_EventScript_Fisherman_Text_3
	destroy_speech_bubble
	closemessage
	release
	end


MurenaCity_WailordFishingClub_EventScript_ChairmanSign_Text_0:
	.string "It's a portrait of the CHAIRMAN…$"

MurenaCity_WailordFishingClub_EventScript_Chairman_Text_0:
	.string "Hello there.\n"
	.string "I am the chairman of the\l"
	.string "WAILORD FISHING CLUB.\p"
	.string "Day and night, fishermen and\n"
	.string "sailors are searching for the\l"
	.string "almighty giant of the oceans!\p"
	.string "Hoping to find a WAILORD…$"

MurenaCity_WailordFishingClub_EventScript_Sailor_Text_0:
	.string "Every day I use my ship to\n"
	.string "search for the aquatic giant.\p"
	.string "The ship I use is a big fisherman's\n"
	.string "ship with lots of gear to haul\l"
	.string "the big guy in!$"

MurenaCity_WailordFishingClub_EventScript_Fisherman_Text_0:
	.string "So, has anyone even seen a\n"
	.string "WAILORD here?$"

MurenaCity_WailordFishingClub_EventScript_Fisherman_Text_1:
	.string "Well, yes of course…$"

MurenaCity_WailordFishingClub_EventScript_Fisherman_Text_2:
	.string "How big is it then?\n"
	.string "I suppose you would know.$"

MurenaCity_WailordFishingClub_EventScript_Fisherman_Text_3:
	.string "Oh uhm…\p"
	.string "It's just really big y'know.$"
