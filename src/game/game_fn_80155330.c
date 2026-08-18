typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Work {
    u8 type;
    u8 kind;
    u8 pad02[2];
    u16 id;
    u8 pad06[0x1e];
    u8 value24[4];
    u8 mode;
    u8 pad29;
    u16 amount;
    u32 field2c;
    u8 field30[8];
    u32 source;
    u8 pad3c[0x4c];
    u32 list[2];
    u32 callback90;
    u32 owner94;
    u32 callback98;
    u32 field9c;
    u32 callbacka0;
    u32 fielda4;
    u8 pad_a8[0x14];
    u8 statebc;
    u8 padbd[3];
} Work;

extern void* lbl_802FC5BC[];
extern void fn_801487AC(void);
extern void fn_801556DC(void);
extern void* fn_80201814(void*);
extern void* fn_80155DB4(void*);
extern void* fn_80149E04(void);
extern void fn_80147E88(Work*);
extern void fn_801555D4(Work*, void*);
extern void fn_80149B0C(void*, int, int);
extern void fn_801A438C(Work*);
extern void fn_80149B60(void*, void*, int, int, int);
extern void fn_80179BC0(void*, u16*);
extern void fn_80148A98(Work*, void*);
extern void fn_80149B38(void*);
extern void fn_80184740(Work*);
extern int fn_801D3A24(int, int);
extern void* fn_80148300(void*, void*, void*);
extern void fn_801568B8(void*, void*);
extern void fn_801A4420(void*, void*, int);
extern void fn_80149EB8(void*);

void* fn_80155330(u8 type, void* source, int value, int parameter,
                  void* position, int amount)
{
    Work first;
    Work second;
    void* source_info = fn_80201814(source);
    void* owner = 0;
    void* first_object;
    void* second_object;
    void* result = 0;
    int count = 0x10;
    int i;

    if (source_info == 0)
        return 0;
    owner = fn_80155DB4(source_info);
    first_object = fn_80149E04();
    second_object = fn_80149E04();
    if (owner == 0 || first_object == 0 || second_object == 0)
        goto fail;

    fn_80147E88(&first);
    fn_801555D4(&first, first_object);
    if (type != 1)
        first.callbacka0 = (u32)fn_801556DC;
    fn_80149B0C(first_object, 0, parameter);
    fn_801A438C(&first);

    switch (type) {
    case 1:
        count = 0x10;
        fn_80149B60(source_info, &first.amount, 0x10, 1, 0);
        first.amount = 0x80;
        break;
    case 2:
        first.source = (u32)source;
        count = 6;
        break;
    case 3:
        count = 3;
        fn_80179BC0(position, &first.amount);
        first.amount = (u16)amount;
        break;
    }
    first.type = (u8)count;
    first.kind = 0x10;
    fn_80149B60(source_info, first.value24, 0, parameter, 0);
    first.mode = type;
    first.source = value;
    first.field2c = (u32)source;

    fn_80147E88(&second);
    fn_80148A98(&second, second_object);
    second.owner94 = 0;
    second.statebc = 4;
    *(u8*)second_object = first.type;
    fn_80149B38(second_object);
    fn_80184740(&second);
    second.kind = 0x10;
    second.type = 0x20;
    second.id = (u16)fn_801D3A24(value, 0x4e);
    second.pad_a8[0] = 7;
    second.field2c = ((u32*)lbl_802FC5BC)[3];
    ((u8*)&second.field2c)[3] = 0xe0;

    if (fn_80148300(owner, &first, first_object) == 0)
        goto fail;
    result = fn_80148300(owner, &second, second_object);
    if (result == 0) {
        fn_80149EB8(second_object);
        return 0;
    }
    fn_801568B8(result, fn_801487AC);
    for (i = 0; i < count; i++)
        fn_801A4420(*(void**)((u8*)first_object + 0x88),
                    *(void**)((u8*)second_object + 0x88 + i * 4), i);
    return *(void**)((u8*)first_object + 0x88);

fail:
    fn_80149EB8(first_object);
    fn_80149EB8(second_object);
    return 0;
}
