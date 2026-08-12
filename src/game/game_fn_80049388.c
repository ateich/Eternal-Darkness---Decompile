typedef signed int s32;
extern int fn_80201B54();
extern void* fn_80158598(int object_id, int index);
extern s32 fn_80157E1C(void* object);
extern void* fn_80157FE0(void* object, s32 index, s32 value);
extern void *fn_80201814();

s32 fn_80049388(void* object, s32 index, s32 value)
{
    s32 result = 0;
    s32 object_id = fn_80201B54(object);
    void* entry = fn_80158598(object_id, 0);

    if (entry != 0 && fn_80157E1C(entry) > 0) {
        entry = fn_80158598(object_id, 0);
        result = (s32)fn_80201814(fn_80157FE0(entry, index, value));
    }
    return result;
}
