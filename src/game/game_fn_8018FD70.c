typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Buffers {
    u8* vertices;
    void* colors;
    void* indices;
} Buffers;

typedef struct BufferSetup {
    u32 word0;
    u32 word4;
    u32 word8;
    u32 wordC;
} BufferSetup;

extern BufferSetup lbl_80607120;
extern void* lbl_8064D738;

extern void fn_8018D788(void*, void*, Buffers*, u16);
extern void fn_80190280(void*, void*, void*, void*);
extern void DCFlushRange(void*, unsigned long);
extern int fn_801ED57C(int);
extern void fn_8018D0D0(void*, void*, s16);
extern void fn_80188930(void*, void*, void*);

void fn_8018FD70(u8* self)
{
    BufferSetup setup;
    Buffers buffers;
    u8* object;
    int saved;
    int count;
    u8* vertex;

    object = self;
    setup = lbl_80607120;
    fn_8018D788(lbl_8064D738, object, &buffers, *(u16*)((u8*)&setup + 2));
    fn_80190280(object, buffers.vertices, buffers.indices, object + 0x10);

    count = object[1];
    vertex = buffers.vertices + (count << 1) * 6;
    for (; count < 64; count++) {
        *(u16*)(vertex + 4) = 1;
        *(u16*)(vertex + 10) = 1;
        vertex += 12;
    }

    DCFlushRange(buffers.vertices, *(u16*)((u8*)&setup + 0xA));
    DCFlushRange(buffers.colors, *(u16*)((u8*)&setup + 0xE));
    DCFlushRange(buffers.indices, *(u16*)((u8*)&setup + 0xC));
    saved = fn_801ED57C(0);
    fn_8018D0D0(object, object + 0x5C, *(s16*)(object + 0xE));
    fn_80188930(buffers.vertices, buffers.colors, buffers.indices);
    fn_801ED57C(saved);
}
