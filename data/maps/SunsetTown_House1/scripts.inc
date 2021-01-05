SunsetTown_House1_MapScripts::
	.byte 0


SunsetTown_House1_EventScript_Woman::
	msgbox SunsetTown_House1_EventScript_Woman_Text_0, MSGBOX_NPC
	turnobject 1, DIR_NORTH
	end


SunsetTown_House1_EventScript_Woman_Text_0:
	.string "I love cooking!\n"
	.string "I'm in my kitchen all day.$"
