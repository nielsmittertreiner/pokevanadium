LitorTown_Bar_MapScripts::
	.byte 0


LitorTown_Bar_EventScript_Barman::
	lock
	faceplayer
	load_speech_bubble 1
	message LitorTown_Bar_Text_WelcomeToMyBar
	waitmessage
	destroy_speech_bubble
	special SpawnCameraObject
	goto LitorTown_Bar_EventScript_SetUpShop
	end


LitorTown_Bar_EventScript_SetUpShop::
	call LitorTown_Bar_EventScript_SetUpShopCamera
	load_speech_bubble 1
	message LitorTown_Bar_Text_WhatDoYouFancy
	waitmessage
	goto LitorTown_Bar_EventScript_DrawShopMenu
	return


LitorTown_Bar_EventScript_SetUpShopCamera::
	applymovement OBJ_EVENT_ID_CAMERA, LitorTown_Bar_Movement_MoveCameraShopView
	waitmovement 0
	return


LitorTown_Bar_EventScript_ResetShopCamera::
	applymovement OBJ_EVENT_ID_CAMERA, LitorTown_Bar_Movement_ResetCameraShopView
	waitmovement 0
	return


LitorTown_Bar_EventScript_DrawShopMenu::
	showmoneybox 0, 0, 0
	multichoice 0, 4, MULTI_LITOR_BAR_SHOP, 0
	destroy_speech_bubble
	switch VAR_RESULT
	case 0, LitorTown_Bar_EventScript_DrawShopMenu_2
	case 1, LitorTown_Bar_EventScript_DrawShopMenu_3
	case 2, LitorTown_Bar_EventScript_DrawShopMenu_4
	case 3, LitorTown_Bar_EventScript_DrawShopMenu_5
	case MULTI_B_PRESSED, LitorTown_Bar_EventScript_DrawShopMenu_6
	return

LitorTown_Bar_EventScript_DrawShopMenu_2:
	goto LitorTown_Bar_EventScript_ChooseFreshWater
	return

LitorTown_Bar_EventScript_DrawShopMenu_3:
	goto LitorTown_Bar_EventScript_ChooseSodaPop
	return

LitorTown_Bar_EventScript_DrawShopMenu_4:
	goto LitorTown_Bar_EventScript_ChooseLemonade
	return

LitorTown_Bar_EventScript_DrawShopMenu_5:
	call LitorTown_Bar_EventScript_ResetShopCamera
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	return

LitorTown_Bar_EventScript_DrawShopMenu_6:
	call LitorTown_Bar_EventScript_ResetShopCamera
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	return


LitorTown_Bar_EventScript_ChooseFreshWater::
	call LitorTown_Bar_EventScript_ResetShopCamera
	load_speech_bubble 1
	msgbox LitorTown_Bar_EventScript_ChooseFreshWater_Text_0, MSGBOX_YESNO
	destroy_speech_bubble
	switch VAR_RESULT
	case YES, LitorTown_Bar_EventScript_ChooseFreshWater_2
	case NO, LitorTown_Bar_EventScript_ChooseFreshWater_3
	case MULTI_B_PRESSED, LitorTown_Bar_EventScript_ChooseFreshWater_4
	return

LitorTown_Bar_EventScript_ChooseFreshWater_2:
	goto LitorTown_Bar_EventScript_TryBuyFreshWater
	return

LitorTown_Bar_EventScript_ChooseFreshWater_3:
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	return

LitorTown_Bar_EventScript_ChooseFreshWater_4:
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	return


LitorTown_Bar_EventScript_ChooseSodaPop::
	call LitorTown_Bar_EventScript_ResetShopCamera
	msgbox LitorTown_Bar_EventScript_ChooseSodaPop_Text_0, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LitorTown_Bar_EventScript_ChooseSodaPop_2
	case NO, LitorTown_Bar_EventScript_ChooseSodaPop_3
	case MULTI_B_PRESSED, LitorTown_Bar_EventScript_ChooseSodaPop_4
	return

LitorTown_Bar_EventScript_ChooseSodaPop_2:
	goto LitorTown_Bar_EventScript_TryBuySodaPop
	return

LitorTown_Bar_EventScript_ChooseSodaPop_3:
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	return

LitorTown_Bar_EventScript_ChooseSodaPop_4:
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	return


LitorTown_Bar_EventScript_ChooseLemonade::
	call LitorTown_Bar_EventScript_ResetShopCamera
	msgbox LitorTown_Bar_EventScript_ChooseLemonade_Text_0, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LitorTown_Bar_EventScript_ChooseLemonade_2
	case NO, LitorTown_Bar_EventScript_ChooseLemonade_3
	case MULTI_B_PRESSED, LitorTown_Bar_EventScript_ChooseLemonade_4
	return

LitorTown_Bar_EventScript_ChooseLemonade_2:
	goto LitorTown_Bar_EventScript_TryBuyLemonade
	return

LitorTown_Bar_EventScript_ChooseLemonade_3:
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	return

LitorTown_Bar_EventScript_ChooseLemonade_4:
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	return


LitorTown_Bar_EventScript_TryBuyFreshWater::
	checkmoney 200, 0
	compare VAR_RESULT, FALSE
	goto_if_eq LitorTown_Bar_EventScript_TryBuyFreshWater_2
LitorTown_Bar_EventScript_TryBuyFreshWater_1:
	playse SE_SHOP
	removemoney 200, 0
	updatemoneybox 0, 0
	delay 30
	hidemoneybox
	giveitem ITEM_FRESH_WATER, 1
	closemessage
	goto LitorTown_Bar_EventScript_SetUpShop
	return

LitorTown_Bar_EventScript_TryBuyFreshWater_2:
	load_speech_bubble 1
	msgbox LitorTown_Bar_EventScript_TryBuyFreshWater_Text_0
	destroy_speech_bubble
	closemessage
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	goto LitorTown_Bar_EventScript_TryBuyFreshWater_1


LitorTown_Bar_EventScript_TryBuySodaPop::
	checkmoney 200, 0
	compare VAR_RESULT, FALSE
	goto_if_eq LitorTown_Bar_EventScript_TryBuySodaPop_2
LitorTown_Bar_EventScript_TryBuySodaPop_1:
	playse SE_SHOP
	removemoney 250, 0
	updatemoneybox 0, 0
	delay 30
	hidemoneybox
	giveitem ITEM_SODA_POP, 1
	closemessage
	goto LitorTown_Bar_EventScript_SetUpShop
	return

LitorTown_Bar_EventScript_TryBuySodaPop_2:
	load_speech_bubble 1
	msgbox LitorTown_Bar_EventScript_TryBuyFreshWater_Text_0
	destroy_speech_bubble
	closemessage
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	goto LitorTown_Bar_EventScript_TryBuySodaPop_1


LitorTown_Bar_EventScript_TryBuyLemonade::
	checkmoney 200, 0
	compare VAR_RESULT, FALSE
	goto_if_eq LitorTown_Bar_EventScript_TryBuyLemonade_2
LitorTown_Bar_EventScript_TryBuyLemonade_1:
	playse SE_SHOP
	removemoney 350, 0
	updatemoneybox 0, 0
	delay 30
	hidemoneybox
	giveitem ITEM_LEMONADE, 1
	closemessage
	goto LitorTown_Bar_EventScript_SetUpShop
	return

LitorTown_Bar_EventScript_TryBuyLemonade_2:
	load_speech_bubble 1
	msgbox LitorTown_Bar_EventScript_TryBuyFreshWater_Text_0
	destroy_speech_bubble
	closemessage
	goto LitorTown_Bar_EventScript_CancelBuyDrink
	goto LitorTown_Bar_EventScript_TryBuyLemonade_1


LitorTown_Bar_EventScript_CancelBuyDrink::
	load_speech_bubble 1
	msgbox LitorTown_Bar_EventScript_CancelBuyDrink_Text_0
	destroy_speech_bubble
	closemessage
	goto LitorTown_Bar_EventScript_ExitShop
	return


LitorTown_Bar_EventScript_ExitShop::
	hidemoneybox
	special RemoveCameraObject
	release
	end


LitorTown_Bar_EventScript_Lass::
	msgbox LitorTown_Bar_EventScript_Lass_Text_0, MSGBOX_NPC
	end


LitorTown_Bar_EventScript_Sailor::
	msgbox LitorTown_Bar_EventScript_Sailor_Text_0, MSGBOX_NPC
	end


LitorTown_Bar_EventScript_TuberM::
	msgbox LitorTown_Bar_EventScript_TuberM_Text_0, MSGBOX_NPC
	end


LitorTown_Bar_Movement_MoveCameraShopView:
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	step_end

LitorTown_Bar_Movement_ResetCameraShopView:
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	step_end

LitorTown_Bar_EventScript_ChooseFreshWater_Text_0:
	.string "Is one FRESH WATER your choice?$"

LitorTown_Bar_EventScript_ChooseSodaPop_Text_0:
	.string "Is one SODA POP your choice?$"

LitorTown_Bar_EventScript_ChooseLemonade_Text_0:
	.string "Is one LEMONADA your choice?$"

LitorTown_Bar_EventScript_TryBuyFreshWater_Text_0:
	.string "You don't seem to have enough money…$"

LitorTown_Bar_EventScript_CancelBuyDrink_Text_0:
	.string "Have a nice day!$"

LitorTown_Bar_EventScript_Lass_Text_0:
	.string "The barman makes his LEMONADE with\n"
	.string "fresh lemons!$"

LitorTown_Bar_EventScript_Sailor_Text_0:
	.string "This FRESH WATER is a lot better\n"
	.string "than a mouthful of salty sea water…$"

LitorTown_Bar_EventScript_TuberM_Text_0:
	.string "My mom told me I could have a SODA POP!\n"
	.string "Yay!$"

LitorTown_Bar_Text_WelcomeToMyBar::
	.string "Welcome to the LITOR BAR!\p"
	.string "Here, you can buy the best\n"
	.string "drinks of town!$"

LitorTown_Bar_Text_WhatDoYouFancy::
	.string "What refreshment do you fancy?$"
