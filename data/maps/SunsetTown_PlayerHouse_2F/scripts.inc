SunsetTown_PlayerHouse_2F_MapScripts::
	.byte 0


SunsetTown_PlayerHouse_2F_EventScript_CheckPlayersPC::
	setvar VAR_0x8004, 1
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC
	special BedroomPC
	waitstate
	release
	end


SunsetTown_PlayerHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, 1
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

