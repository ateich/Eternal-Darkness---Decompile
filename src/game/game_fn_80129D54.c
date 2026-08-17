typedef unsigned char u8;
typedef struct Item { int packed; int kind; int value; } Item;

extern void fn_801287C4(void*, void*, unsigned short, int);
extern void fn_801A9FA4(void);

void fn_80129D54(void* owner, int count, Item* item)
{
    void* callback;
    Item* current = item;
    int i;
    callback = fn_801A9FA4;
    for (i = 0; i < count; current++, i++) {
        switch (current->kind) {
        case 0:
            fn_801287C4(owner, callback, (unsigned short)current->value,
                        current->packed >> 17);
            break;
        case 1:
            break;
        default:
            break;
        }
    }
}
