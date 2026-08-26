typedef unsigned char u8;
typedef unsigned int u32;

extern u32 lbl_8064D21C;
extern u8* lbl_8064D220;

void* fn_8018095C(void* target)
{
    u32 count = lbl_8064D21C;
    u8* entry = lbl_8064D220;
    void* result = 0;
    u32 i;

    if (target != 0) {
        for (i = 0; i < count; i++, entry += 0x150) {
            if (*(void**)(entry + 0x34) == target) {
                result = entry;
                break;
            }
        }
    }
    return result;
}
