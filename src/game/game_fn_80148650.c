extern void *fn_80156938();
extern int fn_80156FF4(void *);
extern int fn_801800F8(void *);
extern int fn_80180114(void *);
extern int fn_8018E934(unsigned char *);

typedef struct InstanceList {
    unsigned char count;
    unsigned char pad1[3];
    unsigned short mask;
    unsigned short state;
    unsigned char pad8[0x80];
    void *instances[1];
} InstanceList;

int fn_80148650(void *object, void *unused, int enabled)
{
    unsigned char *current;
    int count;
    unsigned short current_bit;
    int bit;
    int result;
    int i;
    InstanceList *list;

    list = fn_80156938(object);
    result = 0;
    if (enabled == 0)
        return 0;

    count = list->count;
    bit = 1;
    i = 0;
    current = (unsigned char *)list;
    for (; i < count; current += 4, i++) {
        current_bit = bit;
        if ((list->mask & current_bit) != 0) {
            if (fn_801800F8(*(void **)(current + 0x88))) {
                fn_8018E934(*(unsigned char **)(current + 0x88));
                result = 2;
            }
            if (fn_80180114(*(void **)(current + 0x88)))
                list->mask &= ~current_bit;
        }
        bit = (current_bit & 0x7FFF) << 1;
    }

    if (list->state == 1 || list->mask == 0) {
        fn_80156FF4(object);
        result = 4;
    }
    return result;
}
