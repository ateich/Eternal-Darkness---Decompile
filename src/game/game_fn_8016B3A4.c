typedef unsigned int u32;

extern void* lbl_8064D1CC;
extern void* fn_80138B90(void*, int, int);
extern void* fn_80024638(void*, void*, u32*);

void* fn_8016B3A4(void* value, int alternate)
{
    u32 size = 0;
    void* result;

    if (alternate != 0) {
        result = fn_80138B90(value, 3, 0);
    } else {
        result = fn_80024638(value, lbl_8064D1CC, &size);
    }

    lbl_8064D1CC = result;
    return (unsigned char*)result + ((size + 31) & ~31);
}
