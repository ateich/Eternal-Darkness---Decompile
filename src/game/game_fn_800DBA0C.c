extern void *fn_80201C24(void *);
extern void *fn_80157918(void *);
extern int fn_80200C38(void *);
extern void *fn_80201B44(void);
extern void fn_800DC250(void *, void *, void *, int);

void fn_800DBA0C(void *context, void *value)
{
    void *payload;
    int converted;

    payload = fn_80157918(fn_80201C24(context));
    if (value != 0) {
        converted = fn_80200C38(value);
    } else {
        converted = 0;
    }
    fn_800DC250(fn_80201B44(), context, payload, converted);
}
