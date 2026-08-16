extern void *lbl_8064C4E0;
extern void *fn_80201B54(void *);
extern int fn_80201910(void *);
extern void fn_801E7974(void *, int);

void fn_800E7F70(void *object)
{
    int id = fn_80201910(fn_80201B54(object));
    fn_801E7974(lbl_8064C4E0, id);
}
