typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Data800A1F58 {
    u8 pad000[0x1A];
    u16 sounds[1];
} Data800A1F58;

typedef struct Object800A1F58 {
    u8 pad000[0x264];
    Data800A1F58* data;
    u8 pad268[0x20];
    u8 index;
    u8 pad289[3];
    int handle;
} Object800A1F58;

extern int fn_801B05E8(int, int, int, int, int, int, int, int);

void fn_800A1F58(Object800A1F58* object)
{
    int sound = object->data->sounds[object->index];
    if (sound != 0) {
        object->handle = fn_801B05E8(sound, 100, 4, 1, 0, 5, 0, 0);
    }
}
