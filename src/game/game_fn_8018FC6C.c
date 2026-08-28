typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct ShortCoord3 {
    s16 x;
    s16 y;
    s16 z;
} ShortCoord3;

typedef struct Buffers {
    void* vertices;
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
extern u8 lbl_8063C068[];

extern void fn_8018D788(void*, void*, Buffers*, u16);
extern void fn_80179B08(void*, Vec3*);
extern void fn_8017ACE0(void*, Vec3*, Vec3*);
extern void fn_80179B64(Vec3*, ShortCoord3*);
extern void fn_80190280(void*, void*, void*, ShortCoord3*);
extern void DCFlushRange(void*, unsigned long);
extern int fn_801ED57C(int);
extern void fn_8018D0D0(void*, void*, s16);
extern void fn_801887C4(void*, void*, void*);

void fn_8018FC6C(u8* self)
{
    Vec3 input;
    Vec3 transformed;
    BufferSetup setup;
    Buffers buffers;
    ShortCoord3 position;
    int saved;
    u8* object;

    object = self;
    setup = lbl_80607120;
    fn_8018D788(lbl_8064D738, object, &buffers, *(u16*)((u8*)&setup + 2));
    fn_80179B08(object + 0x10, &input);
    fn_8017ACE0(lbl_8063C068, &input, &transformed);
    fn_80179B64(&transformed, &position);
    fn_80190280(object, buffers.vertices, buffers.indices, &position);
    DCFlushRange(buffers.vertices, *(u16*)((u8*)&setup + 0xA));
    DCFlushRange(buffers.colors, *(u16*)((u8*)&setup + 0xE));
    DCFlushRange(buffers.indices, *(u16*)((u8*)&setup + 0xC));
    saved = fn_801ED57C(0);
    fn_8018D0D0(object, object + 0x5C, *(s16*)(object + 0xE));
    fn_801887C4(buffers.vertices, buffers.colors, buffers.indices);
    fn_801ED57C(saved);
}
