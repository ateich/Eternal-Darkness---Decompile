typedef int s32;
typedef unsigned int u32;

extern s32 lbl_8064C664;
extern u32 lbl_8064C668;
extern s32 lbl_8064C66C;
extern s32 lbl_8064C5A4;
extern s32 lbl_8064C6A0;
extern s32 lbl_8064CBA4;
extern void* lbl_8064D68C;
extern void* lbl_8064D74C;
extern u32 lbl_806518F8;
extern char lbl_805B6FE0[];
extern char lbl_8023D020[];

extern void* fn_8015AA0C(void);
extern u32 fn_80024638(char*, void*, u32*);
extern void fn_8015DAB0(void);
extern void fn_800242B8(u32);
extern void fn_801EF530(void);
extern void fn_801EF580(void*);
extern void fn_801EB194(s32);
extern void* fn_8017BA24(void);
extern void fn_8004736C(s32);
extern void* memcpy(void*, const void*, u32);
extern void fn_800B1244(void*);
extern void fn_80042974(void);
extern void fn_800B0F54(void*);
extern void* fn_8015AB00(void*);
extern void fn_801EB9F0(void*);
extern void fn_801EBDDC(void*);
extern void fn_801EBA58(void*);
extern u32 fn_8012070C(void);
extern void fn_8015E918(char*, u32, u32, u32, u32);
extern void fn_8001D9FC(int);
extern void fn_801EF39C(s32);
extern void fn_801F348C(u32*, s32);

void fn_80024100(void)
{
    char* strings = lbl_8023D020;

    if (lbl_8064C664 < 2) {
        if (lbl_8064C668 == 0) {
            u32 result;
            void* resource = fn_8015AA0C();

            lbl_8064C668 = fn_80024638(strings + 0xA40, resource, &result);
            fn_8015DAB0();
        }

        fn_800242B8(lbl_8064C668);
        lbl_8064C664++;
        if (lbl_8064C664 >= 2) {
            if (lbl_8064C668 != 0) {
                fn_801EF530();
                fn_801EF580(lbl_8064D74C);
                fn_801EB194(1);
            }
            lbl_8064C668 = 0;
        }
    } else {
        void* object;
        void* data = fn_8017BA24();
        u32 value;

        fn_8004736C(0);
        memcpy(lbl_8064D68C, data, 0x4000);
        fn_800B1244(lbl_8064D68C);
        fn_80042974();
        fn_800B0F54(lbl_8064D68C);

        object = fn_8015AB00(*(void**)lbl_805B6FE0);
        if (object != 0) {
            fn_801EB9F0(object);
            fn_801EBDDC(object);
        }
        fn_801EBA58(lbl_8064D68C);

        if (lbl_8064C66C != 0) {
            if (lbl_8064CBA4 == 1) {
                fn_8015E918(strings + 0x8F8, 0xE72D60, 0x330E0,
                            fn_8012070C(), 0x330E0);
            } else {
                fn_8015E918(strings + 0x908, 0xE72D60, 0x330E0,
                            fn_8012070C(), 0x330E0);
            }
        }

        lbl_8064C6A0 = -1;
        lbl_8064C5A4 = 0;
        fn_8001D9FC(2);
        fn_801EF39C(3);
        value = lbl_806518F8;
        fn_801F348C(&value, 60);
        lbl_8064C664 = 0;
    }
}
