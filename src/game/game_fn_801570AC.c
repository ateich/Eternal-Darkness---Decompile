extern void* fn_80156B1C(void*);
extern void fn_801571C4(void*);

void fn_801570AC(void* object)
{
    int i;

    for (i = 0; i < 12; i++) {
        fn_801571C4(fn_80156B1C(object));
    }
}
