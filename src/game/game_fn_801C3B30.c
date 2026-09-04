typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_801C38CC(u16, void*, u8, void*);

void fn_801C3B30(u16* ids, void* archive, u8 type, void* direct)
{
    while (*ids != 0xFFFF) {
        if (*ids & 0x8000) {
            u16 id = *ids & 0x3FFF;
            while (id <= ids[1]) {
                fn_801C38CC(id, archive, type, direct);
                id++;
            }
            ids += 2;
        } else {
            fn_801C38CC(*ids++, archive, type, direct);
        }
    }
}
