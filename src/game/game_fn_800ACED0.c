typedef signed char s8;

extern void fn_8012B62C(void*, int, int);

void fn_800ACED0(void* object, int mode, s8* state)
{
    if (mode == state[0x43]) {
        return;
    }

    state[0x43] = mode;
    switch (mode) {
    case 1:
        fn_8012B62C(object, 15, 15);
        fn_8012B62C(object, 16, 16);
        fn_8012B62C(object, 2, 2);
        fn_8012B62C(object, 4, 4);
        fn_8012B62C(object, 78, 78);
        fn_8012B62C(object, 24, 24);
        break;
    case 2:
        fn_8012B62C(object, 15, 17);
        fn_8012B62C(object, 16, 16);
        fn_8012B62C(object, 2, 3);
        fn_8012B62C(object, 4, 5);
        fn_8012B62C(object, 78, 6);
        fn_8012B62C(object, 24, 24);
        break;
    }
}
