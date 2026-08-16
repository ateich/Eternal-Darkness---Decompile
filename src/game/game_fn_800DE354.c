typedef unsigned char u8;

extern void *fn_80201B9C();
extern void *fn_80201B8C();
extern int fn_80201B5C(void *);
extern int fn_80201B54();
extern void *fn_80201BC0(void *);

int fn_800DE354(void)
{
    void *node = fn_80201B9C();

    while (node != 0) {
        void *object = fn_80201B8C(node);
        int kind = fn_80201B5C(node);

        if (kind == 9 || kind == 48 || kind == 65 || kind == 73) {
            if (object != 0 && ((u8 *)object)[0x9F] == 8) {
                return fn_80201B54(node);
            }
        }
        node = fn_80201BC0(node);
    }
    return 0;
}
