typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Link Link;
struct Link {
    Link* next;
    Link* prev;
    void* object;
};

typedef struct Owner Owner;
struct Owner {
    Owner* next;
    Owner* prev;
    u8 state;
    u8 type;
    u8 pad0A[2];
    u32 key;
    u8 pad10[0xE54];
    Link* lists[3];
    u8 padE70[0x6A];
    u8 flags;
    u8 padEDB[0x98D];
};

extern Owner lbl_8060D420[];
extern Owner* lbl_8064D398;
extern Owner* lbl_8064D39C;
extern void fn_801B244C(Owner*);
extern void fn_801C21E8(void*);

static inline int resolve_handle(u32 value)
{
    u32 key = value & 0x7FFFFFFF;
    Owner* first = lbl_8064D39C;
    Owner* second;

    while (first != 0) {
        if (first->key == key) {
            key = first->type;
            return key | (value & 0x80000000U);
        }
        first = first->next;
    }

    second = lbl_8064D398;
    while (second != 0) {
        if (second->key == key) {
            key = second->type;
            return key | (value & 0x80000000U);
        }
        second = second->next;
    }

    return -1;
}

void fn_801B35BC(u32 handle)
{
    Owner* owner;
    Owner* cursor;
    Link* link;
    u32 i;
    u32 id;

    id = resolve_handle(handle);

    if (id == -1) {
        return;
    }
    if ((id & 0x80000000) == 0) {
        owner = &lbl_8060D420[id];
        if (owner->state != 1) {
            return;
        }
        if (owner->prev != 0) {
            owner->prev->next = owner->next;
        } else {
            lbl_8064D39C = owner->next;
        }
        if (owner->next != 0) {
            owner->next->prev = owner->prev;
        }
        if ((owner->next = lbl_8064D398) != 0) {
            lbl_8064D398->prev = owner;
        }
        owner->prev = 0;
        lbl_8064D398 = owner;
        owner->state = 2;

        cursor = owner;
        for (i = 0; i < 2; i++) {
            link = cursor->lists[0];
            while (link != 0) {
                fn_801C21E8(link->object);
                link = link->next;
            }
            cursor = (Owner*)((u8*)cursor + 4);
        }
        link = owner->lists[2];
        while (link != 0) {
            fn_801C21E8(link->object);
            link = link->next;
        }
        fn_801B244C(owner);
    } else {
        owner = &lbl_8060D420[id & 0x7FFFFFFF];
        if (owner->state != 0) {
            u32 flags = owner->flags;
            flags |= 8;
            owner->flags = flags;
        }
    }
}
