typedef unsigned short u16;

typedef struct Entry {
    void* data;
    unsigned int size;
} Entry;

extern int lbl_8064B9E0;
extern int lbl_8064B9E4;
extern unsigned char lbl_8064D068[];
extern unsigned char lbl_8064D070[];
extern void* lbl_8064A65C;
extern unsigned char lbl_805AE780[];

extern void* fn_8015D424(void*, int);
extern int fn_801399CC(short);
extern void fn_802136A4(void*);
extern void fn_80213394(void*, void*);
extern Entry* fn_80138950(void*, u16);
extern void fn_8015D7D4(int, void*, void*, unsigned int, void*);
extern void fn_8021345C(void*);
extern void fn_8015D44C(void);

void fn_801391D4(short id, int value)
{
    unsigned char temp[64];
    void* token = fn_8015D424(temp, 2);
    Entry* entry;

    fn_801399CC(id);
    fn_802136A4(lbl_8064D068);
    fn_80213394(lbl_805AE780 + 6, temp + 4);
    fn_802136A4(lbl_8064D070);
    entry = fn_80138950(lbl_8064A65C, (u16)value);
    fn_8015D7D4(0xEA5E40, temp + 4, entry->data, (entry->size + 31) & ~31, token);
    lbl_8064B9E0 = value;
    lbl_8064B9E4 = id;
    fn_8021345C(temp + 4);
    fn_8015D44C();
}
