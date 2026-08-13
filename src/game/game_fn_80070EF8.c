extern void *fn_80201B9C();
extern void *fn_80204844(void *, int);
extern void *fn_8006D444(void);
extern int fn_8006BCE4(void *);
extern int fn_80201B54();
extern unsigned long long fn_8020123C();

void fn_80070EF8(void)
{
    void *object = fn_80204844(fn_80201B9C(), 0x20);
    if (object != 0) {
        int type = fn_8006BCE4(fn_8006D444());
        switch (type) {
        case 0x18:
        case 0x1F: {
            int owner = fn_80201B54(object);
            if (owner != 0) {
                fn_8020123C(0x52, 0, owner, 0);
            }
            break;
        }
        }
    }
}
