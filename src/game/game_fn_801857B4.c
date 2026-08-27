typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Words3 {
    u32 x;
    u32 y;
    u32 z;
} Words3;

extern const Words3 lbl_8023B038;
extern const Words3 lbl_8023B044;
extern const volatile u32 lbl_806509F0;
extern void fn_801859FC(u8*, u8);

void fn_801857B4(u8* self)
{
    u8* object = self;
    u32 second_y;
    u32 second_x;
    u32 first_z;
    u32 first_y;
    u32 first_x;
    Words3 first;
    Words3 second;
    volatile u32 value = lbl_806509F0;

    first_x = lbl_8023B038.x;
    first_y = lbl_8023B038.y;
    first_z = lbl_8023B038.z;
    second_x = lbl_8023B044.x;
    second_y = lbl_8023B044.y;
    first.x = first_x;
    first.y = first_y;
    first.z = first_z;
    second.x = second_x;
    second.y = second_y;
    second.z = lbl_8023B044.z;

    object[0] = 31;
    object[1] = 255;
    object[2] = 250;
    object[3] = 254;
    *(u16*)(object + 4) = 82;
    *(u16*)(object + 6) = 130;
    *(u16*)(object + 8) = 5;
    *(u16*)(object + 0x1C) = 10;
    *(u16*)(object + 0x1E) = 0x800;
    *(u16*)(object + 0x20) = 4;

    fn_801859FC(object, object[0]);

    object[0x14] = 20;
    object[0x15] = 5;
    object[0x18] = 0;
    object[0x19] = 31;
    *(u32*)(object + 0x78) = value;
    *(Words3*)(object + 0x3C) = first;
    *(Words3*)(object + 0x48) = first;
    *(Words3*)(object + 0x30) = second;
}
