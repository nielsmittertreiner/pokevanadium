#ifndef GUARD_SPEECH_BUBBLE_H
#define GUARD_SPEECH_BUBBLE_H

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

void LoadTail(s16 x, s16 y);
void LoadTailFromObjectEventId(u32 id);
void DestroyTail(void);

#endif // GUARD_SPEECH_BUBBLE_H