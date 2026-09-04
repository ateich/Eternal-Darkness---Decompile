typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct ResourceEntry {
    volatile u32 next;
    u16 id;
    u16 pad06;
    u8 data[4];
} ResourceEntry;

extern void fn_801BC8F4(u16, void*);
extern void fn_801BCC04(u16, void*, u8, void*);
extern void fn_801BB5D0(u16, void*);
extern void fn_801BB7C0(u16, void*, u8, void*);
extern void fn_801BB944(u16, void*, u16);
extern void fn_801BBB8C(u16, void*, u8, void*);
extern void fn_801BBD58(u16, void*);
extern void fn_801BBF50(u16, void*, u8, void*);
extern void fn_801BC500(u16, void*, u8, void*);
extern void fn_801BC5D8(u16, void*, u8, void*);

void fn_801C38CC(u16 id, void* archive, u8 type, void* direct)
{
    ResourceEntry* entry;

    switch (type) {
    case 0:
        if (direct == 0) {
            if (archive == 0) {
                entry = 0;
            } else {
                entry = (ResourceEntry*)((u8*)archive + *(u32*)archive);
                while (entry->next != (u32)-1) {
                    if (entry->id != id)
                        goto advance0;
                    goto found0;
advance0:
                    entry = (ResourceEntry*)((u8*)entry + entry->next);
                }
                entry = 0;
            }
found0:
            if (entry != 0)
                fn_801BC8F4(id, entry->data);
            else
                fn_801BC8F4(id, 0);
        } else {
            fn_801BCC04(id, archive, type, direct);
        }
        break;
    case 1:
        if (direct == 0)
            fn_801BC500(id, archive, type, direct);
        else
            fn_801BC5D8(id, archive, type, direct);
        break;
    case 2:
        id |= 0x4000;
        if (direct == 0) {
            if (archive == 0) {
                entry = 0;
            } else {
                entry = (ResourceEntry*)((u8*)archive + *((u32*)archive + 2));
                while (entry->next != (u32)-1) {
                    if (entry->id != id)
                        goto advance2;
                    goto found2;
advance2:
                    entry = (ResourceEntry*)((u8*)entry + entry->next);
                }
                entry = 0;
            }
found2:
            if (entry != 0)
                fn_801BB5D0(id, entry->data);
            else
                fn_801BB5D0(id, 0);
        } else {
            fn_801BB7C0(id, archive, type, direct);
        }
        break;
    case 3:
        id |= 0x8000;
        if (direct == 0) {
            if (archive == 0) {
                entry = 0;
            } else {
                entry = (ResourceEntry*)((u8*)archive + *((u32*)archive + 3));
                while (entry->next != (u32)-1) {
                    if (entry->id != id)
                        goto advance3;
                    goto found3;
advance3:
                    entry = (ResourceEntry*)((u8*)entry + entry->next);
                }
                entry = 0;
            }
found3:
            if (entry != 0)
                fn_801BB944(id, entry->data + 4, *(u16*)entry->data);
            else
                fn_801BB944(id, 0, 0);
        } else {
            fn_801BBB8C(id, archive, type, direct);
        }
        break;
    case 4:
        if (direct == 0) {
            if (archive == 0) {
                entry = 0;
            } else {
                entry = (ResourceEntry*)((u8*)archive + *((u32*)archive + 1));
                while (entry->next != (u32)-1) {
                    if (entry->id != id)
                        goto advance4;
                    goto found4;
advance4:
                    entry = (ResourceEntry*)((u8*)entry + entry->next);
                }
                entry = 0;
            }
found4:
            if (entry != 0)
                fn_801BBD58(id, entry->data);
            else
                fn_801BBD58(id, 0);
        } else {
            fn_801BBF50(id, archive, type, direct);
        }
        break;
    }
}
