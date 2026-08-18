typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

extern float lbl_80650508;
extern float lbl_8065050C;
extern float lbl_80650510;

extern void fn_800CEA1C(int, int, Vec3*, Vec3*, int, u8, int*,
                       float, float, float);
extern void fn_80149E28(void);

void fn_8014DA68(void* state)
{
    Vec3 position;

    switch (*(u16*)((char*)state + 0x132C)) {
    case 400:
    case 500:
    case 600:
    case 700:
    case 800:
    case 900:
    case 1000:
    case 1100:
    case 1200:
    case 1300:
        position = *(Vec3*)((char*)state + 0x14);
        fn_800CEA1C(0x17, 3, &position, (Vec3*)((char*)state + 0x20), 3,
                    *(u8*)((char*)state + 0x2C),
                    (int*)((char*)state + 0x10), lbl_80650508,
                    lbl_8065050C, lbl_80650510);
        break;
    case 1301:
        fn_80149E28();
        break;
    }
}
