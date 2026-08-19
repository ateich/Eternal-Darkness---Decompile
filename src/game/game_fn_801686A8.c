#pragma use_lmw_stmw on

extern const char lbl_8024FAD0[];
extern const char lbl_8064BBCC;
extern const char lbl_8064BBD4;
extern volatile const double lbl_80650668;
extern void fn_80168598(void*, void*);
extern int fn_80167DC8(void*, void*);
extern int fn_80167D68(void*);
extern int fn_801689EC(void);
extern void fn_80168634(void*, int, const char*, void*);
extern double fn_8016804C(void*, void*, int);
extern void fn_80163BB4(void*, const char*, ...);

int fn_801686A8(void* object, void* input)
{
    const char* strings = lbl_8024FAD0;
    int byte;
    int native;
    int reverse;
    double value;

    fn_80168598(object, input);
    byte = fn_80167DC8(object, input);
    if (byte > 0x40) {
        fn_80163BB4(object, strings + 0xA0, fn_80167D68(input),
                    byte / 16, byte % 16, 4, 0);
    }
    if (byte < 0x40) {
        fn_80163BB4(object, strings + 0xE0, fn_80167D68(input),
                    byte / 16, byte % 16, 4, 0);
    }

    byte = fn_80167DC8(object, input);
    native = fn_801689EC();
    reverse = (unsigned int)((byte - native) | (native - byte)) >> 31;
    fn_80168634(object, 4, strings + 0x120, input);
    fn_80168634(object, 4, strings + 0x12C, input);
    fn_80168634(object, 4, strings + 0x13C, input);
    fn_80168634(object, 0x20, strings + 0x150, input);
    fn_80168634(object, 6, &lbl_8064BBCC, input);
    fn_80168634(object, 9, &lbl_8064BBD4, input);
    fn_80168634(object, 8, strings + 0x164, input);

    value = fn_8016804C(object, input, reverse);
    if ((int)value != (int)lbl_80650668) {
        fn_80163BB4(object, strings + 0x174, fn_80167D68(input),
                    value, lbl_80650668);
    }
    return reverse;
}
