Route401_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route401_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Route401_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_SUNSET_TOWN_STATE, 3
	goto_if_eq Route401_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

Route401_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setvar VAR_SUNSET_TOWN_FOLLOWER_STATE, 2
	return


Route401_EventScript_RouteSign::
	msgbox Route401_EventScript_RouteSign_Text_0, MSGBOX_SIGN
	end


Route401_EventScript_Boy::
	msgbox Route401_EventScript_Boy_Text_0, MSGBOX_NPC
	end


Route401_EventScript_Youngster::
	msgbox Route401_EventScript_Youngster_Text_0, MSGBOX_NPC
	end


Route401_EventScript_RouteSign_Text_0:
	.string "{LEFT_ARROW} SUNSET TOWN\n"
	.string "{RIGHT_ARROW} CEDARRED TOWN$"

Route401_EventScript_Boy_Text_0:
	.string "You should always be prepared to\n"
	.string "encounter wild POKéMON in the\l"
	.string "tall grass of ROUTE 401!$"

Route401_EventScript_Youngster_Text_0:
	.string "You can skip some tall grass by jumping\n"
	.string "over these ledges right here!\p"
	.string "Try it out yourself!$"
