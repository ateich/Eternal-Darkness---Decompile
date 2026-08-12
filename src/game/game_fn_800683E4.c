typedef signed int s32;

extern void *fn_80201814(s32 object_id);
extern s32 fn_80201BC8(void *object);
extern void *fn_801294DC(s32 state, s32 kind, s32 value, s32 priority);
extern void fn_802006D4(s32 source, s32 target, s32 kind, s32 value, s32 extra);

s32 fn_800683E4(void *action, s32 object_id)
{
    fn_801294DC(fn_80201BC8(fn_80201814(object_id)), 0x2C, 0x25, 10);
    fn_802006D4(object_id, object_id, 0x22, 0x43, 0);
    fn_802006D4(object_id, object_id, 0x2E, 0x43, 0);
    return 1;
}
