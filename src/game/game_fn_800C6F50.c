typedef unsigned char u8;
typedef unsigned int u32;

#pragma use_lmw_stmw on

extern int lbl_8064CB7C;

extern int fn_801A7934(void *);
extern u32 fn_801A78EC(void *);
extern u32 fn_801A7910(void *);
extern int fn_801A7490(void *);
extern void *fn_80201814();
extern int fn_80204180(void *, void *);

int fn_800C6F50(void *object, void *event)
{
    int type;
    int result = 0;
    u32 flags;
    u32 flags2;
    int first;
    int second;

    type = (u8)fn_801A7934(event);
    flags = fn_801A78EC(event);
    flags2 = fn_801A7910(event);
    first = ((flags & 0x40) != 0 || (flags2 & 0x400) != 0);
    second = (type != 0 || (flags2 & 0x100) != 0);

    if (second && first) {
        int owner = fn_801A7490(event);
        if (owner != 0) {
            void *runtime = fn_80201814((void *)owner);
            if (fn_80204180(object, runtime) > 500) {
                result = 1;
            }
        }
    } else if (lbl_8064CB7C != 0) {
        result = 1;
    }
    return result;
}
