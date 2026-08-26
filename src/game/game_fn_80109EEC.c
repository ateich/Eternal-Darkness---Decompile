typedef signed short s16;

typedef struct Coordinates {
    s16 first;
    s16 second;
    s16 third;
    s16 fourth;
} Coordinates;

typedef struct CoordinateTable {
    Coordinates entries[4];
} CoordinateTable;

extern void* lbl_8064CCA0;
extern CoordinateTable lbl_8023A278;
extern int fn_801E8D24(void*);
extern void fn_80119224(int, int);
extern void fn_801A8974(int, int, int, int, int, int);

void fn_80109EEC(int arg)
{
    CoordinateTable values = lbl_8023A278;
    int index = fn_801E8D24(lbl_8064CCA0);
    Coordinates* selected = &values.entries[index];

    fn_80119224(0, arg);
    fn_801A8974(selected->first, selected->second, selected->third,
                selected->fourth, -1, 3);
}
