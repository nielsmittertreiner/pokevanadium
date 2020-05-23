#include "global.h"
#include "event_data.h"
#include "decompress.h"
#include "sprite.h"
#include "constants/event_objects.h"
#include "event_object_movement.h"

#define TAG_SPEECH_BUBBLE_TAIL 0x3333

#define IMAGE_HEIGHT 64
#define TEXTBOX_LEFT_X 70
#define TEXTBOX_RIGHT_X 170 
#define TEXTBOX_Y 120

struct Tail
{
    const u32 *gfx;
    const u16 *pal;
    u8 shape;
    u8 size;
};

static const u32 sTailGfx[] = INCBIN_U32("graphics/speech_bubble/speech_bubble_tail.4bpp.lz");
static const u16 sTailPal[] = INCBIN_U16("graphics/speech_bubble/speech_bubble_tail.gbapal");

static const struct Tail sTail = 
{
    sTailGfx, sTailPal, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64),
};

static EWRAM_DATA u8 sID = 0;

void LoadTail(void) {
    struct CompressedSpriteSheet sheet;
    struct SpritePalette palSheet;
    struct SpriteTemplate spriteTemp1;
    struct OamData oam = {0};
    
    s16 x2 = (s16)(VarGet(gSpecialVar_0x8005));
    s16 y2 = (s16)(VarGet(gSpecialVar_0x8006));
    s16 x1 = (x2 < 120) ? TEXTBOX_LEFT_X : TEXTBOX_RIGHT_X;

    if (GetSpriteTileStartByTag(TAG_SPEECH_BUBBLE_TAIL) == 0xFFFF)
    {
        const u8 *gfxPtr = (const u8*)(sTail.gfx);

        sheet.tag = TAG_SPEECH_BUBBLE_TAIL;
        sheet.data = sTail.gfx;
        sheet.size = (gfxPtr[3] << 16) | (gfxPtr[2] << 8) | gfxPtr[1];

        LoadCompressedSpriteSheet(&sheet);
    }

    if (IndexOfSpritePaletteTag(TAG_SPEECH_BUBBLE_TAIL) == 0xFF)
    {
        palSheet.tag = TAG_SPEECH_BUBBLE_TAIL;
        palSheet.data = sTail.pal;

        LoadSpritePalette(&palSheet);
    }


    oam.size = sTail.size;
    oam.shape = sTail.shape;
    oam.priority = 0;
    oam.affineMode = ST_OAM_AFFINE_DOUBLE;

    spriteTemp1 = gDummySpriteTemplate;
    spriteTemp1.oam = &oam;
    spriteTemp1.paletteTag = spriteTemp1.tileTag = TAG_SPEECH_BUBBLE_TAIL;

    // place sprite at the midpoint between the textbox point and input point
    sID = CreateSprite(&spriteTemp1, (x1 + x2) / 2, (TEXTBOX_Y + y2) / 2, 0); 

    InitSpriteAffineAnim(&gSprites[sID]);
    SetOamMatrix(gSprites[sID].oam.matrixNum, 
                 Q_8_8(1), 
                 Q_8_8(1.0 / ((float)(y2 - TEXTBOX_Y) / -(x2 - x1))), // calculate x shear factor
                 Q_8_8(0), 
                 Q_8_8(IMAGE_HEIGHT / (double)(TEXTBOX_Y - y2))); // calculate y scale factor
}

// gSpecialVar_0x8004 is the object event id
void LoadTailAuto(void) 
{
    struct ObjectEvent *objectEvent;
    struct Sprite *sprite;

    objectEvent = &gObjectEvents[GetObjectEventIdByLocalIdAndMap(VarGet(gSpecialVar_0x8004), gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup)];
    sprite = &gSprites[objectEvent->spriteId];

    gSpecialVar_0x8005 = sprite->pos1.x + sprite->pos2.x;
    gSpecialVar_0x8006 = sprite->pos1.y + sprite->pos2.y;

    LoadTail();
}

void DestroyTail(void)
{
    DestroySprite(&gSprites[sID]);
    FreeSpritePaletteByTag(TAG_SPEECH_BUBBLE_TAIL);
    FreeSpriteTilesByTag(TAG_SPEECH_BUBBLE_TAIL);
}
