typedef signed int s32;

extern s32 fn_80201B54(void* object);
extern void* fn_80158598(s32 object_id, s32 index);
extern s32 fn_80157E1C(void* object);
extern void* fn_80157FE0(void* object, s32 index, s32 value);
extern s32 fn_80201814(void* object);

s32 fn_80049388(void* object, s32 index, s32 value)
{
    s32 result = 0;
    s32 object_id = fn_80201B54(object);
    void* entry = fn_80158598(object_id, 0);

    if (entry != 0 && fn_80157E1C(entry) > 0) {
        entry = fn_80158598(object_id, 0);
        result = fn_80201814(fn_80157FE0(entry, index, value));
    }
    return result;
}
