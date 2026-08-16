extern void *fn_80128E30(void *);
extern void fn_801296E8(void *, unsigned int);

void fn_800C9AD4(void *context, void *object)
{
    void *component = fn_80128E30(object);

    if (component != 0) {
        fn_801296E8(component, 0x10000);
    }
}
