typedef int s32;

extern s32 fn_80200C10(void*);
extern int fn_80200C38(void*);
extern int fn_80201B54();
extern void fn_80201D2C(void*, s32);
extern void fn_80201D14(void*, s32);
extern int fn_801E8328();
extern void fn_80201D34(void*, s32);
extern void fn_80201D1C(void*, s32);
extern void* fn_80155DB4(void*);
extern void fn_80156F78(void*, s32);
extern void fn_80156904(void*, s32);
extern void fn_80156F80(void*, s32);

s32 fn_800326C0(void* object, s32 action, void* event, s32* completed)
{
    s32 event_id = fn_80200C10(event);

    fn_80201B54(object);
    if (action == 0) {
        if (event_id == 1) {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        }

        if (event_id == 0x39) {
            fn_801E8328(2, object);
            fn_80201D34(object, 0);
            fn_80201D1C(object, 1);
            return 1;
        }

        if (event_id == 0x9C) {
            void* state = fn_80155DB4(object);
            fn_80156F78(state, fn_80200C38(event));
            return 1;
        }

        if (event_id == 0xC7) {
            void* state = fn_80155DB4(object);
            fn_80156904(state, fn_80200C38(event));
            return 1;
        }

        if (event_id == 0xC8) {
            void* state = fn_80155DB4(object);
            fn_80156F80(state, fn_80200C38(event));
            return 1;
        }

        if (event_id == 0xF0) {
            s32 value = fn_80200C38(event);
            fn_80201D34(object, value);
            fn_80201D1C(object, 1);
            if (completed != 0) {
                *completed = 1;
            }
            return 1;
        }
    } else if (action != 1) {
        return 0;
    }

    return 0;
}
