typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct Description {
    u8 pad[4];
    u16 *values;
} Description;

extern void *fn_80201BC8(void);
extern void *fn_80049220(void *, s32);
extern void *fn_80049304(void *, void *);
extern s32 fn_8011EB14(void *);
extern void *fn_80201C24(void *);
extern void fn_8004958C(void *, u16);
extern void fn_801387EC(s32);

void fn_8007D69C(void *object)
{
    void *target;
    s32 value;
    void *attached;
    void *part;

    target = fn_80201BC8();
    part = fn_80049220(object, 1);
    attached = fn_80049304(object, part);
    value = fn_8011EB14(target);
    if (attached != 0) {
        Description *description = fn_80201C24(attached);
        value = description->values[value + 0x1B];
        fn_8004958C(object, (u16)value);
    }
    fn_801387EC(value);
}
