typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct EventRecord {
    void *object;
    int kind;
    u8 amount;
    u8 unk_09;
    u8 unk_0A;
    u8 aux;
    u16 value;
    u16 pad;
    u32 unk_10;
    u16 handle;
} EventRecord;

extern int lbl_8064D5A8;
extern int lbl_8064C2C8;

extern u32 fn_8004A608(void *, int, u8 *, u8 *, u16 *, int);
extern void *fn_8011F130(void *);
extern int fn_8011EB04(void *);
extern void fn_801AC9F4(u32, u8, void *, u8);
extern void fn_80201A84(void *);
extern void *fn_80201814(void);
extern void fn_80204028(void *, u16, int, EventRecord *);

void fn_801A977C(void *object, int kind)
{
    u8 amount;
    u8 aux;
    u16 value;
    u32 handle;
    void *context;
    void *dispatcher;
    EventRecord event;

    handle = fn_8004A608(object, kind, &amount, &aux, &value, 0);
    if (kind == 0x17) {
        int current = lbl_8064D5A8;
        if (current - 0x14 < lbl_8064C2C8) {
            amount = 0x14;
        }
        lbl_8064C2C8 = current;
    }

    if ((u16)handle != 0xFFFF && amount != 0) {
        context = fn_8011F130(object);
        fn_801AC9F4(handle, amount, context, aux);

        if (kind == 0x13 &&
            (fn_8011EB04(object) == 4 || fn_8011EB04(object) == 0x1D ||
             fn_8011EB04(object) == 0x1E)) {
            handle = fn_8004A608(object, 0x21, &amount, &aux, &value, 0);
            fn_801AC9F4(handle, amount, context, aux);
        }

        fn_80201A84(object);
        dispatcher = fn_80201814();
        if (dispatcher != 0) {
            event.object = object;
            event.kind = kind;
            event.amount = amount;
            event.unk_09 = 0;
            event.unk_0A = 0;
            event.aux = aux;
            event.value = value;
            event.unk_10 = 0;
            event.handle = (u16)handle;
            fn_80204028(dispatcher, value, 0, &event);
        }
    }
}
