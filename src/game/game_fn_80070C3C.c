extern void *fn_80201B9C(void);
extern int fn_80201B5C(void *);
extern void *fn_80155DB4(void *);
extern int fn_80201B54();
extern unsigned long long fn_8020123C();
extern void fn_80156FF4(void *);
extern void *fn_80201BC0(void *);

void fn_80070C3C(void)
{
    void *object = fn_80201B9C();

    while (object != 0) {
        if (fn_80201B5C(object) == 3) {
            void *resource = fn_80155DB4(object);
            void *owner = (void *)fn_80201B54(object);
            fn_8020123C(0x39, 0, owner, 0);
            if (resource != 0) {
                fn_80156FF4(resource);
            }
        }
        object = fn_80201BC0(object);
    }
}
