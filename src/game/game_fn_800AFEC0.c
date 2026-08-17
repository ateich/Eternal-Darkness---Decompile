typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned char lbl_8031F7C0[];
extern void* fn_80201B3C();
extern void *fn_80201BC8();
extern void* fn_8011F130(void);
extern float fn_8012B750(void*);
extern u32 fn_8011FB4C(void*);
extern void* memcpy(void*, const void*, unsigned int);
extern u32 fn_800E5050(void*);
extern u32 fn_801F4E38(void*);
extern u32 fn_80028D54(void*);
extern u32 fn_8016B1D0(void*);
extern u32 fn_801FABA4(void*, int);
extern u32 fn_801F668C(void*);
extern u32 fn_8012BA84(void*);
extern u32 fn_801E8FAC(void*);
extern u32 fn_801A8168(void*);
extern u32 fn_8011E918(void*);
extern u32 fn_801A9A00(void*);

int fn_800AFEC0(void)
{
    unsigned char* buffer = lbl_8031F7C0;
    void* current;
    void* object;
    void* source;
    float value;
    u32 word;

    current = fn_80201B3C();
    if (buffer != 0 && current != 0) {
        object = fn_80201BC8(current);
        source = fn_8011F130();
        value = fn_8012B750(object);
        word = fn_8011FB4C(object);
        memcpy(buffer, source, 12);
        memcpy(buffer + 12, &value, 4);
        memcpy(buffer + 16, &word, 4);
        object = (void*)(fn_800E5050(buffer + 20) + 20);
        object = (void*)((u32)object + fn_801F4E38(buffer + (u16)(u32)object));
        object = (void*)((u32)object + fn_80028D54(buffer + (u16)(u32)object));
        object = (void*)((u32)object + fn_8016B1D0(buffer + (u16)(u32)object));
        object = (void*)((u32)object + fn_801FABA4(buffer + (u16)(u32)object, 0));
        object = (void*)((u32)object + fn_801F668C(buffer + (u16)(u32)object));
        object = (void*)((u32)object + fn_8012BA84(buffer + (u16)(u32)object));
        object = (void*)((u32)object + fn_801E8FAC(buffer + (u16)(u32)object));
        object = (void*)((u32)object + fn_801A8168(buffer + (u16)(u32)object));
        object = (void*)((u32)object + fn_8011E918(buffer + (u16)(u32)object));
        fn_801A9A00(buffer + (u16)(u32)object);
        return 1;
    }
    return 0;
}
