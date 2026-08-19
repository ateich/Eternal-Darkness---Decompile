typedef struct Item {
    struct Item* next;
} Item;

extern void fn_80156290(int);
extern Item* fn_80155EF4(void);
extern int fn_80156480(Item*, int, int);

int fn_80156F10(void)
{
    Item* item;
    int result = 0;

    fn_80156290(0x180);
    item = fn_80155EF4()->next;
    while (item != 0) {
        result |= fn_80156480(item, 0, 0x180);
        item = item->next;
    }
    return result;
}
