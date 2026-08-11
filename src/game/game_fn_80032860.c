typedef int s32;

extern s32 fn_80200C10(void*);
extern s32 fn_80200C20(void*);
extern int fn_80201B54();
extern int fn_80201B44(void);
extern void fn_80201D2C(void*, s32);
extern void fn_80201D14(void*, s32);

s32 fn_80032860(void* object, s32 action, void* event, s32* completed)
{
    s32 event_id = fn_80200C10(event);
    fn_80201B54(object);

    if (action == 0) {
        if (event_id == 1) {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        }

        if (event_id == 0x3B) {
            if (completed != 0) {
                *completed = fn_80200C20(event) == fn_80201B44();
            }
            return 1;
        }
    } else if (action != 1) {
        return 0;
    }

    return 0;
}
