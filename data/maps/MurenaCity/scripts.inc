MurenaCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MurenaCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

MurenaCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_MURENA_CITY
	setflag FLAG_VISITED_MURENA_CITY
	return


MurenaCity_EventScript_ArtistTrader::
	lock
	faceplayer
	goto_if_set FLAG_MURENA_NPC_TRADE_COMPLETED, MurenaCity_EventScript_ArtistTrader_2
	setvar VAR_0x8008, INGAME_TRADE_SMEARGLE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	load_speech_bubble 9
	msgbox MurenaCity_EventScript_ArtistTrader_Text_1, MSGBOX_YESNO
	destroy_speech_bubble
	closemessage
	compare VAR_RESULT, NO
	goto_if_eq MurenaCity_EventScript_ArtistTrader_5
MurenaCity_EventScript_ArtistTrader_4:
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq MurenaCity_EventScript_ArtistTrader_8
MurenaCity_EventScript_ArtistTrader_7:
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne MurenaCity_EventScript_ArtistTrader_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname 0, VAR_0x8009
	load_speech_bubble 9
	msgbox MurenaCity_EventScript_ArtistTrader_Text_2
	destroy_speech_bubble
	closemessage
	setflag FLAG_MURENA_NPC_TRADE_COMPLETED
	release
	end

MurenaCity_EventScript_ArtistTrader_2:
	msgbox MurenaCity_EventScript_ArtistTrader_Text_0, MSGBOX_NPC
	end

MurenaCity_EventScript_ArtistTrader_5:
	goto MurenaCity_EventScript_ArtistTrader_Decline
	goto MurenaCity_EventScript_ArtistTrader_4

MurenaCity_EventScript_ArtistTrader_8:
	goto MurenaCity_EventScript_ArtistTrader_Decline
	goto MurenaCity_EventScript_ArtistTrader_7


MurenaCity_EventScript_ArtistTrader_Decline::
	load_speech_bubble 9
	msgbox MurenaCity_EventScript_ArtistTrader_Decline_Text_0
	destroy_speech_bubble
	closemessage
	release
	end


MurenaCity_EventScript_ArtistTrader_NotRequestedMon::
	bufferspeciesname 0, VAR_0x8009
	msgbox MurenaCity_EventScript_ArtistTrader_NotRequestedMon_Text_0, MSGBOX_NPC
	end


MurenaCity_EventScript_ArtistTrader_Text_0:
	.string "Jusqu'ici I am able to understand\n"
	.string "the ocean blue.$"

MurenaCity_EventScript_ArtistTrader_Text_1:
	.string "The ocean is a canvas…\p"
	.string "But to truly blend into it,\n"
	.string "that deep dark blue…\p"
	.string "Only one POKéMON knows the art…\n"
	.string "Can you bring me one.\p"
	.string "If you can find me a KECLEON,\n"
	.string "I will give you my SMEARGLE…$"

MurenaCity_EventScript_ArtistTrader_Text_2:
	.string "Magnificent…\n"
	.string "Such color I have never seen.$"

MurenaCity_EventScript_ArtistTrader_Decline_Text_0:
	.string "I see…\p"
	.string "I guess true culture is hard to\n"
	.string "come by in these parts…$"

MurenaCity_EventScript_ArtistTrader_NotRequestedMon_Text_0:
	.string "What?! I was offering you a\n"
	.string "{STR_VAR_1}, not a pair of glasses!$"
