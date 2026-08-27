typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern u8 lbl_80606334[];
extern void* lbl_8064D238;
extern int lbl_8064D18C;
extern const float lbl_80650A08;

extern void* fn_8018038C(void*, void*);
extern void fn_80185CA4(void*, void*, void*, void*);
extern void fn_80185E0C(void*, void*);
extern void fn_80185FD0(void);
extern void fn_8018666C(void);
extern void fn_801AAE68(float, int, int, int, Vec3*, int, int, int,
                       unsigned short, int);

void* fn_80185AE8(s16* position, void* second, u8* data)
{
    u8* result = fn_8018038C(lbl_8064D238, lbl_80606334);

    if (result != 0) {
        u8* config = data + 0x14;

        fn_80185CA4(result, position, second, data);
        fn_80185E0C(result, config);
        if ((config[4] & 0x10) != 0) {
            int volume;
            Vec3 source;
            s8 level = config[0];

            if (level <= 10)
                volume = 80;
            else if (level <= 20)
                volume = 100;
            else if (level <= 30)
                volume = 120;
            else
                volume = 127;

            source.x = position[0];
            source.y = position[1];
            source.z = position[2];
            fn_801AAE68(lbl_80650A08, 0x108, volume, 0, &source, 2, 2, 0,
                        (unsigned short)lbl_8064D18C, 0);
        }
        *(void (**)(void))(result + 0x14C) = fn_80185FD0;
        *(void (**)(void))(result + 0x148) = fn_8018666C;
        *(unsigned short*)(result + 0x22) = 4;
    }
    return result;
}
