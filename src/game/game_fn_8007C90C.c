typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;

extern int fn_80201B54(void* object);
extern void* fn_8004918C(void);
extern void* fn_80201BC8(void* object);
extern void* fn_801294DC(void* owner, int kind, int flags, int mode);
extern int fn_80201B44(void);
extern void* fn_80201814(int id);
extern void* fn_801A7778(void* data);
extern void fn_80128C28(void* runtime, void* callback, u32 value);
extern void fn_80128C44(void* runtime, void* callback, u32 value);
extern u16 fn_80157994(void* object);
extern u16 fn_80157948(void* object);
extern void* fn_802053B0(void* object, void* value);
extern void* fn_80201C24(void* object);
extern void fn_80201D2C(void* object, int value);
extern void fn_80201D14(void* object, unsigned char value);
extern int fn_80129334(void* owner, int value, int* result, int start);
extern void fn_80157A28(void* object, u16 value);
extern u32 fn_80157C98(void* object, u32 clear, u32 set);
extern void fn_801287C4(void* queue, void* callback, u32 value, u32 kind);
extern int fn_80204810(void* object, int event);
extern void fn_8007CFB0(void);

s32 fn_8007C90C(void* object)
{
    int result = -1;
    void* created;
    int id;
    void* target;
    void* other;
    void* resource;
    void* current;

    id = fn_80201B54(object);
    fn_8004918C();
    resource = fn_80201BC8(object);
    created = fn_801294DC(resource, 10, 0, 6);
    if (created != 0) {
        current = fn_8004918C();
        fn_80201814(fn_80201B44());
        target = fn_801A7778(current);
        fn_80128C44(created, fn_80204810, (id << 8) | 7);
        if (fn_80157948(target) == fn_80157994(target) + 1) {
            fn_80128C28(created, fn_80204810, (id << 8) | 6);
        } else if ((other = fn_802053B0(object, target)) != 0) {
            if (fn_80157994(fn_80201C24(other)) != 1) {
                fn_80128C28(created, fn_80204810, (id << 8) | 0xB3);
            } else {
                fn_80128C28(created, fn_80204810, (id << 8) | 6);
            }
        }
        resource = fn_80201BC8(object);
        fn_80201D2C(object, 0x48);
        fn_80201D14(object, 1);
        if (fn_80129334(resource, 1, &result, -1) == -1) {
            fn_80157A28(target, fn_80157948(target));
            fn_80157C98(target, 0x20, 0);
            fn_80128C28(created, fn_80204810, (id << 8) | 6);
        } else {
            fn_801287C4(created, fn_8007CFB0, (u32)current, result);
        }
    }
    return 1;
}
