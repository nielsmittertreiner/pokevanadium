ForestTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ForestTunnel_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

ForestTunnel_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_unset FLAG_EVENT_CELEBI_ACTIVE, ForestTunnel_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

ForestTunnel_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	setmetatile 4, 1, METATILE_RusturfTunnel_EntranceCover, 1
	setmetatile 5, 1, METATILE_RusturfTunnel_EntranceCover, 1
	setmetatile 6, 1, METATILE_RusturfTunnel_EntranceCover, 1
	setmetatile 4, 2, METATILE_RusturfTunnel_EntranceCover, 1
	setmetatile 5, 2, METATILE_RusturfTunnel_EntranceCover, 1
	setmetatile 6, 2, METATILE_RusturfTunnel_EntranceCover, 1
	return

