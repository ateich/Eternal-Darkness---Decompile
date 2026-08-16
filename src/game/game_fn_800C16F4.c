extern void *fn_800BE938(void *, int);
extern void fn_800C63D8(void);
extern void *fn_80201B94(void *);
extern void *fn_80201B54(void *);
extern void *fn_80201BC8(void *);
extern void **fn_80201B8C(void *);
extern void fn_80201DD8(void *, void *);
extern void fn_801A74A8(void *, void *);
extern void fn_801A67C4(void *, void *);
extern unsigned long long fn_8020123C(int, void *, void *, int);

#pragma use_lmw_stmw on

void fn_800C16F4(void *object, void *event, int kind, int retry)
{
    void *found = fn_800BE938(object, kind);

    if (retry != 0 && found == 0) {
        fn_800C63D8();
        found = fn_800BE938(object, kind);
    }
    if (found != 0) {
        void *owner_data = fn_80201B94(object);
        void *found_id = fn_80201B54(found);
        void *object_id = fn_80201B54(object);
        fn_80201BC8(found);
        fn_80201DD8(owner_data, found_id);
        fn_801A74A8(event, found_id);
        {
            void **state = fn_80201B8C(found);
            if (state != 0 && state[35] != 0) {
                fn_801A67C4(event, ((void **)state[35])[45]);
                fn_8020123C(0x1D, object_id, found_id, 0);
            }
        }
    }
}
