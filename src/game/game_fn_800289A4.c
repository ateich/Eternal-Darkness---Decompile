typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;

extern s32 lbl_8064D18C;
extern s32 lbl_8064C6FC;
extern float lbl_8064DFF4;
extern float lbl_8064DFF8;

extern void* fn_80201B3C(void);
extern void* fn_80201B9C(void);
extern void* fn_80201BC0(void*);
extern int fn_80201EB8();
extern int fn_80201B4C(void*);
extern int fn_80201B5C(void*);
#define fn_80201B5C(a) fn_80201B5C((void*)(a))

extern int fn_80201B64(void*);
extern void* fn_80201BC8();
extern float fn_8011F6F0(void);
extern void fn_8011F778(void*, float);
extern s32 fn_801FBEF0(void*, s32, s32);
extern s32 fn_801FC034(void*, s32, s32, float);
extern void* fn_80155DB4(void*);
extern void* fn_80156930(void*);
extern void fn_8002AC60(void);
extern unsigned int fn_80036D5C(void*);
extern void fn_80036DA4(void*, u32);
extern void fn_80028BE4(void);

u16 fn_800289A4(s32 value, s32 flag, s32 finish)
{
    u16 count = 0;
    void* head;
    void* item;
    void* actor;
    s32 kind;
    s32 subtype;
    s32 hit;
    float saved;

    head = fn_80201B3C();
    item = fn_80201B9C();

    while (item != 0) {
        if (item != head && fn_80201EB8(item) == lbl_8064D18C) {
            kind = fn_80201B4C(item);
            subtype = fn_80201B5C(item);

            fn_80201B64(item);
            {
                register void* node = fn_80201BC8(item);
                if (kind == 1 && subtype != 0x25 && subtype != 0x40 &&
                    subtype != 0x45) {
                    saved = fn_8011F6F0();
                    if (subtype == 5) {
                        fn_8011F778(node, lbl_8064DFF8 + saved);
                    }
                    hit = fn_801FBEF0(node, value, flag);
                    if (subtype == 5) {
                        fn_8011F778(node, saved);
                    }
                    if (!hit) {
                        hit = fn_801FC034(node, value, flag, lbl_8064DFF4);
                    }
                    if (hit) {
                        actor = fn_80155DB4(item);
                        if (actor != 0 &&
                            fn_80156930(actor) == (void*)fn_8002AC60) {
                            fn_80036DA4(item,
                                       fn_80036D5C(item) | 0x04000000);
                            count++;
                        }
                    }
                }
            }
        }
        item = fn_80201BC0(item);
    }
    if (count != 0) {
        lbl_8064C6FC = 1;
    }
    if (finish != 0) {
        fn_80028BE4();
    }
    return count;
}
