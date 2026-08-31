typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

extern void* lbl_8064C4E4;
extern float lbl_80650E90;
extern u32 lbl_8064D18C;
extern void* fn_80201814(u32);
extern void* fn_80201BC8(void*);
extern Vec3* fn_8011F130(void*);
extern int fn_801AAE68(u16, u8, u8, float, Vec3*, signed char, u8, u8, u16,
                      unsigned int);

int fn_801ACA40(u32 object_id, u32 packed)
{
    void* object = fn_80201814(object_id);
    Vec3* position;

    if (object != 0) {
        object = fn_80201BC8(object);
    } else {
        object = lbl_8064C4E4;
    }
    if (object != 0) {
        position = fn_8011F130(object);
        fn_801AAE68((u16)packed, (u8)((packed & 0x00FF0000) >> 16), 0,
                    lbl_80650E90, position, 2, 2, 0,
                    (u16)lbl_8064D18C, 0);
    }
    return 1;
}
