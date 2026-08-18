typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;

extern float lbl_80650568;
extern void fn_80181870(void*);

void fn_8014F320(u8* entry, u8 object_id, u16 value)
{
    float scale;

    fn_80181870(entry);
    entry[0] = object_id;
    entry[1] = 2;
    *(u16*)(entry + 4) = value;
    scale = lbl_80650568;
    *(u16*)(entry + 8) = 200;
    *(u16*)(entry + 0x20) = 8;
    *(u16*)(entry + 0x1C) = 1;
    *(s8*)(entry + 0x14) = -2;
    *(u16*)(entry + 0x1A) = 7;
    *(float*)(entry + 0x50) = scale;
}
