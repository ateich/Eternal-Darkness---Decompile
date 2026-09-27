typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef int (*Callback)(void*);

typedef struct Child {
    u8 pad[0x14];
    u32 value;
} Child;

typedef struct Table {
    Callback callbacks[4];
    void* arguments[4];
    u16 values[4];
    u8 current;
    u8 previous;
    u8 first;
    u8 last;
} Table;

typedef struct State {
    u8 pad[0x40];
    Table table;
} State;

typedef struct FullWork {
    u8 pad[0xC];
    Child* child;
    u8 pad10[0x48];
    State state;
} FullWork;

extern void fn_8006C9C0(Child*);
extern void fn_8006C9E4(Child*, int);

int fn_80088E44(void* object)
{
    State* base;
    u8 current;
    u8 first;
    u8 last;
    int value;
    Child* child;
    Callback callback;
    void* argument;

    base = &((FullWork*)object)->state;
    child = ((FullWork*)object)->child;
    if (child != 0) {
        value = child->value >> 16;
        object = &base->table;
        fn_8006C9C0(child);
        current = ((Table*)object)->current;
        first = ((Table*)object)->first;
        last = ((Table*)object)->last;
        callback = ((Table*)object)->callbacks[current];
        argument = ((Table*)object)->arguments[current];
        if (value == ((Table*)object)->values[current] && current < 4 &&
            callback != 0 && argument != 0) {
            callback(argument);
            fn_8006C9E4(child, 0);
            base->table.previous = current;
            current++;
            if (current >= last) {
                current = first;
            }
        }
        base->table.current = current;
    }
    return 0;
}
