typedef unsigned char u8;
typedef unsigned int u32;

typedef struct PoolEntry {
    u8 pad00[0x24];
    u32 fields[5];
    u8 pad38[0xBC];
} PoolEntry;

extern u8 lbl_8064D3A0;
extern PoolEntry* volatile lbl_8064D4AC;
extern u8 lbl_8064D4E5;
extern u8 lbl_8064D4E6;
extern u8 lbl_8064D4E7;

extern void fn_801B9C94(void);
extern void fn_801CE2F0(void);
extern void fn_801CE070(void);
extern void fn_801CE190(void);
extern void fn_801CE310(void);
extern void fn_801C7868(void);
extern void fn_801CC6CC(u8);
extern void fn_801B5228(u32);
extern void fn_801B7A7C(u32);
extern void fn_801C9E74(void);
extern void fn_801B941C(void);
extern void fn_801C36FC(void);

void fn_801CC468(void)
{
    u32 offset;
    u32 field_offset;
    u8 i;
    u8 j;

    if (lbl_8064D3A0 != 0) {
        fn_801B9C94();
        fn_801CE2F0();
        fn_801CE070();
        fn_801CE190();
        fn_801CE310();
        fn_801CE2F0();
        fn_801C7868();
        fn_801CE310();
        fn_801CE2F0();

        offset = 0;
        i = 0;
        lbl_8064D4E6 = (lbl_8064D4E6 + 1) % 3;
        lbl_8064D4E7 ^= 1;
        for (; i < lbl_8064D4E5; i++, offset += 0xF4) {
            field_offset = offset + 0x24;
            *(u32*)((u8*)lbl_8064D4AC + field_offset) = 0;
            *(u32*)((u8*)lbl_8064D4AC + field_offset + 4) = 0;
            *(u32*)((u8*)lbl_8064D4AC + field_offset + 8) = 0;
            *(u32*)((u8*)lbl_8064D4AC + field_offset + 12) = 0;
            *(u32*)((u8*)lbl_8064D4AC + field_offset + 16) = 0;
        }

        fn_801CE310();
        for (j = 0; j < 5; j++) {
            fn_801CE2F0();
            fn_801CC6CC(j);
            fn_801B5228(0x100);
            fn_801B7A7C(0x100);
            fn_801CE310();
        }
        fn_801CE2F0();
        fn_801CC6CC(0);
        fn_801C9E74();
        fn_801CE310();
        fn_801CE2F0();
        fn_801B941C();
        fn_801CE310();
        fn_801CE2F0();
        fn_801C36FC();
        fn_801CE310();
    }
}
