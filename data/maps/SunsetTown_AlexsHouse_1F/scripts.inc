SunsetTown_AlexsHouse_1F_MapScripts::
	.byte 0


SunsetTown_AlexsHouse_1F_EventScript_Woman::
	msgbox SunsetTown_AlexsHouse_1F_EventScript_Woman_Text_0, MSGBOX_NPC
	end


SunsetTown_AlexsHouse_1F_EventScript_Item_Ball::
	msgbox SunsetTown_AlexsHouse_1F_EventScript_Item_Ball_Text_0
	closemessage
	end


SunsetTown_AlexsHouse_1F_EventScript_Woman_Text_0:
	.string "Hi there {PLAYER}, you and ALEX\n"
	.string "have become quite close friends\l"
	.string "since you both were young.\p"
	.string "It's good to see you again!$"

SunsetTown_AlexsHouse_1F_EventScript_Item_Ball_Text_0:
	.string "It's a POKéBALL from ALEX's MOM.\n"
	.string "What could be inside…$"
