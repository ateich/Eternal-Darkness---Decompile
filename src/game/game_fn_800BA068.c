extern void *fn_802051BC(void *);
extern void *fn_80205158(void *);
extern void *fn_8020499C(void *);
extern int fn_801579EC(void *);
extern int fn_80201B5C(void *);
extern void *fn_802051E8(void *);
extern unsigned short fn_800B9D20(void *, void *, void *, void *, int);

#pragma use_lmw_stmw on

unsigned short fn_800BA068(void *output, void *arg, void *list, int last)
{
    unsigned short size = 0;
    void *node;
    void *item;
    void *type;

    if (list != 0) {
        node = fn_802051BC(list);
        while (node != 0) {
            item = fn_80205158(node);
            type = fn_8020499C(item);
            if (!fn_801579EC(item) && fn_80201B5C(type) != 79) {
                size += fn_800B9D20((char *)output + size, arg, item, type, last);
            }
            node = fn_802051E8(node);
        }
    }
    return size;
}
