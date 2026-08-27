typedef signed short s16;
typedef unsigned short u16;
typedef unsigned char u8;

void fn_801896A0(u8* entry, void* context,
                 void (*callback)(void*, float, float, float, float, float))
{
    u16 radius = entry[0x21] + 0x50;

    callback(context,
             (float)(*(s16*)(entry + 0xA) - radius),
             (float)(*(s16*)(entry + 0xC) + radius),
             (float)(*(s16*)(entry + 0xA) + radius),
             (float)(*(s16*)(entry + 0xC) - radius),
             (float)*(s16*)(entry + 0xE));
}
