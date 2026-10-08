typedef unsigned char u8;
typedef signed short s16;

typedef struct InstanceList {
    u8 count;
    u8 pad[0x87];
    void *instances[1];
} InstanceList;

extern int fn_80147E64(s16);
extern void *fn_80156DA0(int, void *);
extern void fn_801568FC(void *, void (*)(void));
extern void fn_801568C0(void *, void (*)(void));
extern void fn_801568B8(void *, void (*)(void));
extern void fn_8015690C(void *, void (*)(void));
extern void fn_80156918(void *, void *);
extern void fn_80180374(void *, int);

extern void fn_80148650(void);
extern void fn_80148730(void);
extern void fn_8014883C(void);

void *fn_8014856C(void *data, InstanceList *list, s16 type, int value)
{
    char *current;
    void *object;
    int i;
    int count;

    object = fn_80156DA0(fn_80147E64(type), data);
    if (object != 0) {
        count = list->count;
        current = (char *)list;
        for (i = 0; i < count; current += 4, i++) {
            if (*(void **)(current + 0x88) != 0) {
                fn_80180374(*(void **)(current + 0x88),
                            (u8)(0 > value - 10 ? 0 : value - 10));
            }
        }

        fn_801568FC(object, fn_80148650);
        fn_801568C0(object, 0);
        fn_801568B8(object, fn_80148730);
        fn_8015690C(object, fn_8014883C);
        fn_80156918(object, list);
    }
    return object;
}
