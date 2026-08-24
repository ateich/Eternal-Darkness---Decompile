typedef struct ShortVector {
    short x;
    short y;
    short z;
} ShortVector;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_8016A970(void*, void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern ShortVector lbl_805FC2E8[];
extern const char lbl_8024FF00[];

int fn_80172EEC(void* state)
{
    int index;
    int x;
    int y;
    int z;
    ShortVector* vector;

    if (fn_8016A598(state) != 4) {
        fn_80163BB4(state, lbl_8024FF00, 4, fn_8016A598(state));
        return 0;
    }

    index = fn_8016A694(state, 1);
    x = fn_8016A694(state, 2);
    y = fn_8016A694(state, 3);
    z = fn_8016A694(state, 4);
    vector = &lbl_805FC2E8[index];
    vector->x = x;
    vector->y = y;
    vector->z = z;
    fn_8016A970(state, vector, 0);
    return 1;
}
