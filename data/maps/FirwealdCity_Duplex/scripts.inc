FirwealdCity_Duplex_MapScripts::
	.byte 0


FirwealdCity_Duplex_EventScript_Man::
	msgbox FirwealdCity_Duplex_EventScript_Man_Text_0, MSGBOX_NPC
	end


FirwealdCity_Duplex_EventScript_Lass::
	msgbox FirwealdCity_Duplex_EventScript_Lass_Text_0, MSGBOX_NPC
	end


FirwealdCity_Duplex_EventScript_Wingull::
	lock
	faceplayer
	playmoncry SPECIES_WINGULL, 0
	waitmoncry
	release
	end


FirwealdCity_Duplex_EventScript_Man_Text_0:
	.string "Hrmph…\p"
	.string "I can hear that WINGULL of the\n"
	.string "girl nextdoor all day long.$"

FirwealdCity_Duplex_EventScript_Lass_Text_0:
	.string "Oh I love reading!\p"
	.string "I even have a book about WINGULL.$"
