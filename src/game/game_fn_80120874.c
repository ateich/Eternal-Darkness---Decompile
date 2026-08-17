typedef unsigned short u16;

extern unsigned lbl_8064CEBC[2];
extern unsigned lbl_8064D738;

void fn_80120874(void* object)
{
    void* owner = *(void**)((char*)object + 0x3C);
    unsigned count = *(u16*)((char*)owner + 0x1E);
    unsigned index = lbl_8064D738 ^ 1;
    unsigned size = (count * 4 + 31) & ~31u;
    lbl_8064CEBC[index] += size;
}
