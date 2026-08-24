typedef struct ShortVector {
    short x;
    short y;
    short z;
} ShortVector;

extern int fn_8016A598(void*);
extern void* fn_8016A784(void*, int);
extern void fn_8016A970(void*, void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern ShortVector lbl_8064D1EC;
extern const char lbl_8024FF00[];
extern const char lbl_8025047C[];

int fn_80173104(void* state)
{
    ShortVector* first;
    ShortVector* second;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    first = fn_8016A784(state, 1);
    second = fn_8016A784(state, 2);
    if (first == 0 || second == 0) {
        fn_80163BB4(state, lbl_8025047C, first, second);
    }
    lbl_8064D1EC.x = first->x + second->x;
    lbl_8064D1EC.y = first->y + second->y;
    lbl_8064D1EC.z = first->z + second->z;
    fn_8016A970(state, &lbl_8064D1EC, 0);
    return 1;
}
