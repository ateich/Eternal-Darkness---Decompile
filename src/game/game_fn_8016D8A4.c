extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_801EF36C(int);
extern int lbl_8064D6EC;

int fn_8016D8A4(void* state)
{
    int value;

    switch (fn_8016A598(state)) {
    case 2:
        fn_801EF36C((int)fn_8016A694(state, 2));
    case 1:
        value = (int)fn_8016A694(state, 1);
        break;
    }
    lbl_8064D6EC = value;
    return 0;
}
