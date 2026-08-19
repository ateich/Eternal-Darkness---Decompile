typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int lbl_8064D18C;
extern u32 lbl_80650008;
extern u16 lbl_8065000C;
extern void fn_80149E28(void*);
extern int fn_8015C9F0(void);
extern u32 fn_8015E780(void);
extern void* fn_801552AC(void*);
extern void *fn_80156938();
extern u32 fn_800FBFB0(void);
extern void fn_80179B08(void*, void*);
extern void fn_80154D24(void*, void*, void*);

void fn_80155158(void* work)
{
    char* data = (char*)work + 8;
    u32 random;
    u16 count;
    u16 selected;
    char a[8];
    char b[12];
    char c[12];

    if (*(int*)((char*)work + 0x1324) != lbl_8064D18C ||
        fn_8015C9F0() != 1 ||
        (*(u8*)(data + 0xBB) != 0 && *(u32*)(data + 0xB0) != fn_8015E780())) {
        fn_80149E28(work);
        return;
    }
    if (*(u8*)(data + 0xBA) == 0) {
        void* effect = fn_801552AC(data);
        if (effect == 0) {
            fn_80149E28(work);
            return;
        }
        *(void**)(data + 0x94) = fn_80156938(effect);
        *(u16*)(data + 0xB4) = (fn_800FBFB0() & 0xFFF) + 1000;
        *(u8*)(data + 0xBA) = 1;
    }
    count = *(u16*)(data + 0xB4);
    if (count == 0) {
        *(u32*)a = lbl_80650008;
        *(u16*)(a + 4) = lbl_8065000C;
        random = fn_800FBFB0();
        count = *(u16*)(data + 0x64);
        selected = *(u16*)(data + 0x24 + ((random % count) * 2));
        *(u32*)b = *(u32*)(*(char**)(data + 0x14) + selected * 24);
        *(u16*)(b + 4) = *(u16*)(*(char**)(data + 0x14) + selected * 24 + 4);
        fn_80179B08(b, c);
        fn_80154D24(c, a, data + 0x1C);
        *(u16*)(data + 0xB4) = (fn_800FBFB0() & 0x7FF) + 60;
    } else {
        *(u16*)(data + 0xB4) = count - 1;
    }
}
