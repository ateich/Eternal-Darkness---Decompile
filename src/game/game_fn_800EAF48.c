typedef struct CallbackArgs {
    int value;
    int id;
} CallbackArgs;

extern void fn_8016B400(int, int, int);

void fn_800EAF48(CallbackArgs *args)
{
    if (args != 0) {
        fn_8016B400(args->id, args->value, 0);
    }
}
