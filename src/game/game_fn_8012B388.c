typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_8012B290(void*, void*);
extern void fn_80128C50(void*);
extern int fn_8012B070(void*);

void fn_8012B388(u8* owner)
{
    int offset;
    int index;

    offset = 0;
    for (index = 0; index < 8; index++, offset += 0x110) {
        u8* table = *(u8**)(owner + 0x40);
        if (index == *(u16*)(table + 0x880)) {
            fn_8012B290(owner, table + offset);
        } else {
            fn_80128C50(table + offset);
        }
    }
    fn_8012B070(owner);
}
