typedef unsigned char u8;
typedef unsigned int u32;

extern void* fn_80128E30(void* object);
extern void* fn_8012A13C(void* object, int value);
extern void fn_80129DE0(void* object, void* source, int enabled, int value);
extern int fn_8012A1BC(void* object, int value);
extern void fn_80129FD0(void* object, int value, int unused);
extern void fn_80201A84(void* object);
extern void* fn_80201814(void);
extern int fn_80202160(void);
extern void fn_8011ECF8(void* object, void* source);

void fn_8011EBFC(void* object)
{
    void* source;
    u32 flags;
    int restore_flag;
    int limit;

    source = fn_80128E30(object);
    flags = *(u32*)((u8*)object + 596);
    restore_flag = flags & 4;

    if (flags & 0x1000) {
        *(void**)((u8*)source + 184) =
            fn_8012A13C(object, *(int*)((u8*)source + 240));
    }

    fn_80129DE0(object, source, 1, 0);

    if (*(int*)((u8*)object + 608) != 0) {
        limit = fn_8012A1BC(object, *(int*)((u8*)source + 240)) << 17;
        if (*(int*)((u8*)object + 608) > limit) {
            *(int*)((u8*)object + 608) = limit;
        }
        fn_80129FD0(object, *(int*)((u8*)object + 608), 0);
    }

    fn_80201A84(object);
    if (fn_80201814() != 0 && (u8)fn_80202160() != 0) {
        fn_8011ECF8(object, source);
    }

    if (restore_flag != 0) {
        *(u32*)((u8*)object + 596) |= 4;
        fn_8011ECF8(object, source);
    }
}
