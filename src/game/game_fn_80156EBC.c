typedef struct Item {
    struct Item* prev;
} Item;

extern void fn_80156290(int);
extern Item* fn_80155EF4(void);
extern void fn_80156480(Item*, int, int);

void fn_80156EBC(void)
{
    Item* item;

    fn_80156290(0x50);
    item = fn_80155EF4()->prev;
    while (item != 0) {
        fn_80156480(item, 2, 0x50);
        item = item->prev;
    }
}
