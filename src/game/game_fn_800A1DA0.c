typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

/*
 * Honest NonMatching reconstruction: objdiff 96.016396%, target 244 bytes,
 * compiled 240 bytes. Remaining differences are halfword address formation
 * and the stack-slot order of MWCC's generated Vec3i argument copy.
 */

typedef struct Vec3i {
    int x;
    int y;
    int z;
} Vec3i;

typedef struct Object800A1DA0 {
    u8 pad000[0x264];
    u8* data;
    u8 pad268[0x37];
    s8 index;
    u16 timer;
} Object800A1DA0;

extern unsigned int fn_800FBFB0();
#define fn_800FBFB0() ((int)fn_800FBFB0())
extern void* fn_80201B3C();
#define FN_80201E78_RETURN void
#define FN_80201E78_PARAMETERS Vec3i*, void*
extern FN_80201E78_RETURN fn_80201E78(FN_80201E78_PARAMETERS);extern void fn_801AC9F4(u16, int, Vec3i, int);
extern void fn_800A2DBC(Object800A1DA0*);

int fn_800A1DA0(Object800A1DA0* object, u8 chance)
{
    Object800A1DA0* current = object;
    int result = 0;
    u8 threshold = chance;
    Vec3i position;
    u16 sound;
    void* source;

    if (threshold == 0xFF || current->timer == 0) {
        if (current->index >= 0) {
            u8 random = (u8)fn_800FBFB0();
            if (threshold != 0 && random <= threshold) {
                u8* entry = current->data + current->index * 2;
                u16 value = *(u16*)(entry + 8);
                if (value != 0) {
                    sound = value;
                    source = fn_80201B3C();
                    if (source != 0) {
                        fn_80201E78(&position, source);
                        fn_801AC9F4(sound, 100, position, 5);
                        fn_800A2DBC(current);
                        result = 1;
                    }
                }
            }
        }
    }
    return result;
}
