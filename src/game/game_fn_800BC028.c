extern int fn_800AF7E4(int, int *);
extern void fn_800B261C(int);
extern void fn_8017B31C(void *);
extern int fn_8017AF90(int);
extern int fn_8017B0C8(int);
extern void fn_800B5E90(int, int);
extern void fn_800B2548(int, int);
extern void fn_800B19A4(void);

int fn_800BC028(int object)
{
    int value;
    int result = fn_800AF7E4(object, &value);

    switch (result) {
    case 1:
    {
        int new_value;
        fn_800B261C(1);
        fn_8017B31C(fn_800B19A4);
        new_value = fn_8017AF90(object);
        value = new_value;
        if (new_value == 0 || new_value == -6) {
            new_value = fn_8017B0C8(object);
            value = new_value;
            if (new_value == 0) {
                return 1;
            }
            fn_800B5E90(object, new_value);
        } else {
            fn_800B5E90(object, new_value);
        }
        break;
    }
    case -2:
        fn_800B2548(0x28, object);
        break;
    case -1:
        fn_800B5E90(object, value);
        break;
    }
    return 0;
}
