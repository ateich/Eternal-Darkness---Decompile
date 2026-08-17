typedef unsigned int u32;

extern int fn_80049694(void *);
extern void *fn_80049220(void *, int);
extern void *fn_80049304(void *, void *);
extern void* fn_80201C24();
extern u32 fn_80157C80(void);
extern void *fn_802053B0(void *, void *);
extern int fn_8015790C(void *);

int fn_800C280C(void *context, void *object, u32 *result_id)
{
    void *entry;
    void *kind;
    int result = 0;

    if (fn_80049694(object) != 0) {
        kind = fn_80049220(context, 1);
        if (fn_80049304(context, kind) != 0) {
            entry = fn_80201C24();
            if ((fn_80157C80() & 0x20) != 0 &&
                fn_802053B0(context, entry) != 0) {
                result = 1;
                *result_id = fn_8015790C(entry);
                if (*result_id == 0) {
                    *result_id = 1582;
                }
            }
        }
    }
    return result;
}
