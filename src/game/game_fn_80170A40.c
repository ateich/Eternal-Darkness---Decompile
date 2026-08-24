typedef signed short s16;
typedef unsigned short u16;

typedef struct Entry {
    s16 id;
    u16 value2;
    u16 value4;
    u16 value6;
} Entry;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_8016A830(void*, double);
extern int lbl_8064D1BC;
extern Entry lbl_805FAA60[10];
extern const char lbl_80250198[];
extern const double lbl_806506D0;

int fn_80170A40(void* state)
{
    s16 id = lbl_8064D1BC;
    int i = 0;

    if (fn_8016A598(state) > 1) {
        fn_80163BB4(state, lbl_80250198, fn_8016A598(state));
        return 0;
    }

    if (fn_8016A598(state) > 0) {
        id = fn_8016A694(state, 2);
    }

    while (lbl_805FAA60[i].id != id && i < 10) {
        i++;
    }

    if (i >= 10) {
        fn_8016A830(state, lbl_806506D0);
    } else {
        fn_8016A830(state, (double)lbl_805FAA60[i].value2);
    }
    return 1;
}
