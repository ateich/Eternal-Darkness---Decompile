typedef int s32;

typedef struct QueueEntry QueueEntry;
typedef void (*QueueCallback)(QueueEntry*);

struct QueueEntry {
    QueueCallback callback;
    unsigned char pad_04[0x28];
};

extern QueueEntry lbl_803026F8[10];
extern void* lbl_8064C4E8;
extern s32 lbl_8064C6F0;

extern s32 fn_801ED3F4(void*);
extern void* fn_8011E1B8(s32);
extern void fn_801A8D38(s32);

void fn_80026280(void)
{
    s32 i;
    s32 token;

    token = fn_801ED3F4(lbl_8064C4E8);
    if (fn_8011E1B8(1) == 0) {
        fn_801A8D38(6);
        for (i = 0; i < lbl_8064C6F0; i++) {
            lbl_803026F8[i].callback(&lbl_803026F8[i]);
        }
    }

    fn_801ED3F4((void*)token);
    lbl_8064C6F0 = 0;
}
