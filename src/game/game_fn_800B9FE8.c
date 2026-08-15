extern void *fn_802051BC(void *);
extern void *fn_80205158(void *);
extern void *fn_8020499C(void *);
extern int fn_80201B5C(void *);
extern void *fn_802051E8(void *);

unsigned short fn_800B9FE8(void *list)
{
    unsigned short count = 0;
    void *node;

    if (list != 0) {
        node = fn_802051BC(list);
        while (node != 0) {
            if (fn_80201B5C(fn_8020499C(fn_80205158(node))) != 79) {
                count++;
            }
            node = fn_802051E8(node);
        }
    }
    return count;
}
