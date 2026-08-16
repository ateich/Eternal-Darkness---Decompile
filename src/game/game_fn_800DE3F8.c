typedef unsigned char u8;

extern void *fn_80201B9C(void);
extern void *fn_80201B8C(void *);
extern int fn_80201B54(void *);
extern void *fn_80201BC0(void *);

int fn_800DE3F8(void)
{
    void *node = fn_80201B9C();

    while (node != 0) {
        void *object = fn_80201B8C(node);

        if (object != 0 && ((u8 *)object)[0x9F] == 26) {
            return fn_80201B54(node);
        }
        node = fn_80201BC0(node);
    }
    return 0;
}
