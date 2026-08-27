typedef signed short s16;
typedef unsigned char u8;

void fn_801895E8(u8* entry, void* context,
                 void (*callback)(void*, float, float, float, float, float))
{
    callback(context,
             (float)(*(s16*)(entry + 0xA) - entry[0x21]),
             (float)(*(s16*)(entry + 0xC) + entry[0x21]),
             (float)(*(s16*)(entry + 0xA) + entry[0x21]),
             (float)(*(s16*)(entry + 0xC) - entry[0x21]),
             (float)*(s16*)(entry + 0xE));
}
