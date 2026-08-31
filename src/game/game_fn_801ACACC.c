typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int fn_801E82B4(u32, u32, void*);
extern int fn_801ACA40(u32, u32);

int fn_801ACACC(u16 id, u8 value, u32 object_id)
{
    u32 packed = id | ((u32)value << 16);
    return fn_801E82B4(object_id, packed, fn_801ACA40);
}
