typedef struct Item {
    struct Item* prev;
} Item;

extern void fn_80156290(int);
extern Item* fn_80155EF4(void);
extern void fn_80156480(Item*, int, int);

void fn_80156E50(int extended)
{
    Item* item;

    fn_80156290(0x230);
    item = fn_80155EF4()->prev;
    while (item != 0) {
        int flags = 0x30;
        if (extended != 0) {
            flags |= 0x800;
        }
        fn_80156480(item, 1, flags);
        item = item->prev;
    }
}
