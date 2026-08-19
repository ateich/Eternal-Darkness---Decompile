typedef struct Item {
    struct Item* prev;
    struct Item* next;
    char pad08[0x08];
    void* field10;
    void* field14;
    char pad18[0x20];
    void* field38;
    int value;
    void* field40;
} Item;

extern Item* fn_80155E08(void);
extern Item* fn_80155EF4(void);
extern void fn_80155D64(void);
extern void fn_80155FE8(Item*);
extern void* fn_80155FD8(void);
extern void fn_801561B4(Item*);

Item* fn_80156DA0(int value)
{
    Item* item = fn_80155E08();
    Item* head = fn_80155EF4();

    fn_80155D64();
    if (item != 0 && head != 0) {
        Item* first = head->prev;

        fn_80155FE8(item);
        item->value = value;
        item->next = head;
        item->prev = first;
        head->prev = item;
        if (first != 0) {
            first->next = item;
        }
        item->field40 = fn_80155FD8();
        item->field38 = 0;
        item->field10 = 0;
        item->field14 = 0;
        fn_801561B4(item);
    }
    return item;
}
