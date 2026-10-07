typedef int s32;
typedef unsigned char u8;
typedef struct Entry80201814 Entry80201814;

extern Entry80201814 *fn_80201814(s32 id);
extern void *fn_80201BC8(void *object);
extern u8 *fn_801294DC(void *owner, int kind, int flags, int mode);

s32 fn_8003CB6C(void *unused, s32 id)
{
    fn_801294DC(fn_80201BC8(fn_80201814(id)), 0x28, 0x21, 0xA);
    return 1;
}
