typedef unsigned char u8;

extern u8* lbl_8064CFF8;
extern int fn_800467E8(void);
extern void* fn_80135968(void*);

int fn_8013864C(void* target, int start)
{
    int count = fn_800467E8();
    u8* slot = lbl_8064CFF8 + start * 0x2F8;
    int result = -1;

    for (; start < count; start++, slot += 0x2F8) {
        void* object = *(void**)slot;
        if (object != 0 && target == fn_80135968(object)) {
            result = start;
            break;
        }
    }
    return result;
}
