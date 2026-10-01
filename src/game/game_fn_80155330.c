typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Color;

typedef struct Work {
    u8 type;
    u8 kind;
    u8 pad02[2];
    s16 id;
    u8 pad06[0xe];
    u8 field14;
    u8 pad15[0xb];
    u8 mode;
    u8 pad21;
    u16 amount;
    u8 value24[4];
    u8 pad28[2];
    u16 field2a;
    Color color;
    u32 field30;
    void* field34;
    u8 pad38[0x50];
    u32 list[2];
    u32 callback90;
    u32 owner94;
    void (*callback98)(void);
    u32 field9c;
    u32 callbacka0;
    u32 fielda4;
    void* fielda8;
    u8 pad_ac[0x10];
    u8 statebc;
    u8 padbd[3];
} Work;

typedef struct Object {
    u8 type;
    u8 pad01[0x87];
    void* items[16];
} Object;

typedef struct Slot {
    Work work;
    Object* object;
} Slot;

extern Color lbl_802FC5BC[];
extern void fn_801487AC(void);
extern void fn_801556DC(void);
extern void* fn_80201814(void*);
extern void* fn_80155DB4(void*);
extern Object* fn_80149E04(void);
extern void fn_80147E88(Work*);
extern void fn_801555D4(Work*, void*);
extern void fn_80149B0C(void*, int, int);
extern void fn_801A438C(Work*);
extern void fn_80149B60(void*, void*, int, int, int);
extern void fn_80179BC0(void*, u16*);
extern void fn_80148A98(Work*, void*);
extern void fn_80149B38(void*);
extern void fn_80184740(Work*);
extern s16 fn_801D3A24(int, int);
extern void* fn_80148300(void*, void*, void*);
extern void fn_801568B8(void*, void*);
extern void fn_801A4420(void*, void*, int);
extern void fn_80149EB8(void*);

void* fn_80155330(u8 type, void* source, int value, int parameter,
                  void* position, int amount)
{
    Slot second;
    Slot first;
    void** element;
    int loop_count;
    void* source_info;
    Work* work;
    Work* next;
    void* result = 0;
    int count = 0x10;
    void* owner = 0;
    void* registered;
    Work* extra;
    int i;

    source_info = fn_80201814(source);
    if (source_info != 0) {
        owner = fn_80155DB4(source_info);
        first.object = fn_80149E04();
        second.object = fn_80149E04();
        if (owner != 0 && first.object != 0 && second.object != 0) {
            work = &first.work;
            fn_80147E88(work);
            fn_801555D4(work, first.object);
            if (type != 1) {
                work->callback98 = fn_801556DC;
            }
            fn_80149B0C(first.object, 0, parameter);
            fn_801A438C(work);

            switch (type) {
            case 1:
                count = 0x10;
                fn_80149B60(source_info, &work->field2a, 0x10, 1, 0);
                work->amount = 0x80;
                break;
            case 2:
                work->field34 = source;
                count = 6;
                break;
            case 3:
                count = 3;
                fn_80179BC0(position, &work->field2a);
                work->amount = (u16)amount;
                break;
            }
            work->type = (u8)count;
            work->kind = 0x10;
            fn_80149B60(source_info, work->value24, 0, parameter, 0);
            work->mode = type;
            work->field30 = value;
            work->fielda8 = source;
            extra = next = &second.work;
            fn_80147E88(extra);
            fn_80148A98(extra, second.object);
            extra->owner94 = 0;
            extra->statebc = 4;
            second.object->type = first.work.type;
            fn_80149B38(second.object);
            fn_80184740(extra);
            extra->kind = 0x10;
            extra->type = 0x20;
            extra->id = fn_801D3A24(value, 0x4e);
            extra->field14 = 7;
            extra->color = lbl_802FC5BC[3];
            extra->color.a = 0xe0;

            owner = fn_80148300(owner, &first.work, first.object);
            if (owner != 0) {
                registered = fn_80148300(owner, next, second.object);
                if (registered != 0) {
                    fn_801568B8(registered, fn_801487AC);
                    loop_count = count & 0xff;
                    result = first.object->items[0];
                    element = second.object->items;
                    for (i = 0; i < loop_count; i++) {
                        fn_801A4420(result, *element, i);
                        element++;
                    }
                } else {
                    fn_80149EB8(second.object);
                }
            } else {
                fn_80149EB8(first.object);
                fn_80149EB8(second.object);
            }
        } else {
            fn_80149EB8(first.object);
            fn_80149EB8(second.object);
        }
    }
    return result;
}
