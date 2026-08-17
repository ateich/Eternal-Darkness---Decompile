typedef unsigned char u8;

extern void* lbl_8064C4E4;
extern void* fn_8015C2FC(int);
extern u8* fn_8015C28C(int);

void* fn_8012AB2C(u8* owner)
{
    void* result = fn_8015C2FC(2);
    int i;

    if (owner != lbl_8064C4E4) {
        for (i = 2; i < 4; i++) {
            u8* entry = fn_8015C28C(i);
            if (entry != 0 && *(signed char*)(entry + 0x8142) != 0 &&
                *(signed char*)(entry + 0x8143) != 0 &&
                *(short*)(entry + 0x8140) == *(int*)(owner + 0x250)) {
                result = fn_8015C2FC(i);
                break;
            }
        }
        if (i == 4) {
            return 0;
        }
    }
    return result;
}
