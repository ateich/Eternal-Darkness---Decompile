typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Data800A1FC0 {
    u8 pad000[0x18];
    u16 sound;
} Data800A1FC0;

typedef struct Object800A1FC0 {
    u8 pad000[0x264];
    Data800A1FC0* data;
} Object800A1FC0;

extern void fn_801B05E8(int, int, int, int, int, int, int, int);

void fn_800A1FC0(Object800A1FC0* object)
{
    int sound = object->data->sound;
    if (sound != 0) {
        fn_801B05E8(sound, 100, 4, 1, 0, 5, 0, 0);
    }
}
