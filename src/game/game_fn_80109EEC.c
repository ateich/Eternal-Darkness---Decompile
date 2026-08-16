typedef signed short s16;

typedef struct Coordinates {
    s16 first;
    s16 second;
    s16 third;
    s16 fourth;
} Coordinates;

extern void* lbl_8064CCA0;
extern int fn_801E8D24(void*);
extern void fn_80119224(int, int);
extern void fn_801A8974(int, int, int, int, int, int);

void fn_80109EEC(int arg)
{
    Coordinates values[4] = {
        {0x6564, 0x5F61, 0x695F, 0x5072},
        {0x6F6A, 0x6563, 0x7469, 0x6C65},
    };
    int index = fn_801E8D24(lbl_8064CCA0);
    Coordinates* selected = &values[index];

    fn_80119224(0, arg);
    fn_801A8974(selected->first, selected->second, selected->third,
                selected->fourth, -1, 3);
}
