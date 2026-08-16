typedef unsigned short u16;

extern void *fn_80049220(void *);
extern void *fn_80049304(void *, void *);
extern void *fn_80201C24(void);
extern void *fn_8015790C(void *);
extern void *fn_802053B0(void *, void *);
extern int fn_80157994(void *);
extern int fn_80157948(void *);
extern void fn_8016B400(void *, int, int);

int fn_800C4E94(void *context)
{
    void *object;
    void *value;

    value = fn_80049220(context);
    if (fn_80049304(context, value) != 0) {
        object = fn_80201C24();
        if (fn_8015790C(object) != 0 && fn_802053B0(context, object) != 0) {
            if ((u16)fn_80157994(object) != (u16)fn_80157948(object)) {
                fn_8016B400(fn_8015790C(object), 1, 0);
                return 1;
            }
        }
    }
    return 0;
}
