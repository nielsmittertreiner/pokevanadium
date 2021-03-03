MurenaCity_Shipyard_MapScripts::
	.byte 0


MurenaCity_Shipyard_EventScript_Fisherman::
	return


MurenaCity_Shipyard_EventScript_Man::
	msgbox MurenaCity_Shipyard_EventScript_Man_Text_0, MSGBOX_NPC
	applymovement 3, Common_Movement_FaceUp
	waitmovement 0
	end


MurenaCity_Shipyard_EventScript_Man_Text_0:
	.string "Hey there!\n"
	.string "Every day I check the sonar sensors\l"
	.string "for any detections.\p"
	.string "If there's too much rubble, no ships\n"
	.string "are allowed to leave.$"
