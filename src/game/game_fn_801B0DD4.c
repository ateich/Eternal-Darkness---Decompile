typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int fn_8004A608(int, int, u8*, u8*, u8*, u32*);
extern int fn_8011F130(int);
extern void fn_801B05E8(int, u8, int, int, int, u8, int, int);

void fn_801B0DD4(int object)
{
    u8 byte2;
    u8 byte1;
    u8 byte0;
    u32 flags;
    int result;

    result = fn_8004A608(object, 75, &byte1, &byte0, &byte2, &flags);
    if ((u16)result != 0xFFFF && (flags & 0x10) != 0) {
        fn_801B05E8((u16)result, byte1, 3, 0, fn_8011F130(object), byte0, 0, 1);
    }
}
