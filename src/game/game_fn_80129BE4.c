typedef unsigned char u8;

extern u8* fn_80128E30(void*);
extern const float lbl_806501A8;

void fn_80129BE4(void* owner)
{
    u8* entry = fn_80128E30(owner);
    if (entry != 0) {
        unsigned int zero = 0;
        float value = lbl_806501A8;
        *(unsigned short*)(entry + 0xF8) = zero;
        *(float*)(entry + 0xBC) = value;
        *(float*)(entry + 0xC0) = value;
        *(int*)(entry + 0xF4) &= ~0x100;
    }
}
