typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Work {
    u8 type;
    u8 kind;
    u8 pad02[2];
    u16 id;
    u8 pad06[0xe];
    u8 field14;
    u8 pad15[0xb];
    u8 mode;
    u8 pad21;
    u16 amount;
    u8 value24[4];
    u8 pad28[2];
    u16 field2a;
    u32 field2c;
    u32 field30;
    u32 field34;
    u8 pad38[0x50];
    u32 list[2];
    u32 callback90;
    u32 owner94;
    u32 callback98;
    u32 field9c;
    u32 callbacka0;
    u32 fielda4;
    u32 fielda8;
    u8 pad_ac[0x10];
    u8 statebc;
    u8 padbd[3];
} Work;

typedef struct WorkLocals {
    Work first;
    void* first_object;
    Work second;
    void* second_object;
} WorkLocals;

extern void* lbl_802FC5BC[];
extern void fn_801487AC(void);
extern void fn_801556DC(void);
extern void *fn_80201814();
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
    WorkLocals local;
    Work* work;
    Work* next;
    void* source_info;
    void* result = 0;
    int count = 0x10;
    void* owner = 0;
    void* registered;
    int i;
    void** element;
    u8 loop_count;

    source_info = fn_80201814(source);
    if (source_info == 0)
        goto done;
    owner = fn_80155DB4(source_info);
    local.first_object = fn_80149E04();
    local.second_object = fn_80149E04();
    if (owner == 0 || local.first_object == 0 || local.second_object == 0)
        goto allocation_fail;

    work = &local.first;
    fn_80147E88(work);
    fn_801555D4(work, local.first_object);
    if (type != 1)
        work->callback98 = (u32)fn_801556DC;
    fn_80149B0C(local.first_object, 0, parameter);
    fn_801A438C(work);

    switch (type) {
    case 1:
        count = 0x10;
        fn_80149B60(source_info, &work->field2a, 0x10, 1, 0);
        work->amount = 0x80;
        break;
    case 2:
        work->field34 = (u32)source;
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
    work->fielda8 = (u32)source;
    next = &local.second;
    fn_80147E88(work = next);
    fn_80148A98(work, local.second_object);
    work->owner94 = 0;
    work->statebc = 4;
    *(u8*)local.second_object = local.first.type;
    fn_80149B38(local.second_object);
    fn_80184740(work);
    work->kind = 0x10;
    work->type = 0x20;
    work->id = (u16)fn_801D3A24(value, 0x4e);
    work->field14 = 7;
    work->field2c = ((u32*)lbl_802FC5BC)[3];
    ((u8*)&work->field2c)[3] = 0xe0;

    owner = fn_80148300(owner, &local.first, local.first_object);
    if (owner == 0)
        goto registration_fail;
    registered = fn_80148300(owner, next, local.second_object);
    if (registered == 0)
        goto second_fail;
    fn_801568B8(registered, fn_801487AC);
    loop_count = (u8)count;
    result = *(void**)((u8*)local.first_object + 0x88);
    element = (void**)((u8*)local.second_object + 0x88);
    for (i = 0; i < loop_count; i++) {
        fn_801A4420(result, *element, i);
        element++;
    }
    goto done;

second_fail:
    fn_80149EB8(local.second_object);
    goto done;
registration_fail:
    fn_80149EB8(local.first_object);
    fn_80149EB8(local.second_object);
    goto done;
allocation_fail:
    fn_80149EB8(local.first_object);
    fn_80149EB8(local.second_object);
done:
    return result;
}
