typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Object800A2FCC {
    u8 pad00[0xC];
    float value;
} Object800A2FCC;

extern float lbl_8064EE94;
extern int fn_801869DC(void*);
extern void fn_800A1B90(Object800A2FCC*, void*, void*);

int fn_800A2FCC(Object800A2FCC* object, void* resource, u16 expected,
                void* callback_arg, void* callback)
{
    int result = 0;

    if (resource != 0) {
        int value = fn_801869DC(resource);
        object->value = lbl_8064EE94 * (float)(u16)value;
        if (callback != 0) {
            fn_800A1B90(object, callback_arg, callback);
        }
        result = (u16)value == expected;
    }
    return result;
}
