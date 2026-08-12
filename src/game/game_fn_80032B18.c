typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
extern void *fn_80201B8C();

void fn_80032B18(void* object, s32 index, s32 mode, const u32* value)
{
    u8* state = fn_80201B8C(object);
    u8* records = *(u8**)(state + 0x7C);

    switch (mode) {
    case 0: {
        u8* record = records + index * 0x24;
        *(u32*)(record + 0x44) = *value;
        *(u32*)(record + 0x48) = *value;
        break;
    }
    }
}
