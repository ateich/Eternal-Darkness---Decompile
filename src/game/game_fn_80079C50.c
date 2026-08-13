typedef struct CycleWork {
    struct {
        int first;
        int second;
    } slots[6];
    int index;
    int pad34;
    void *active;
} CycleWork;

extern void *fn_80200C38(int value);
extern int fn_80201B54();
extern unsigned long long fn_8020123C();
extern void *fn_80201814();

void fn_80079C50(void *object, int unused, int value, CycleWork *work)
{
    void **wrapper = fn_80200C38(value);
    void *owner = (void *)fn_80201B54(object);
    int resource = (int)wrapper[8];

    fn_8020123C(0x7A, owner, work->active, 0);
    work->active = 0;

    if (resource != 0 && fn_80201814((void *)resource)) {
        work->index++;
        if (work->index >= 6) {
            work->index = 0;
        }
        if (work->slots[work->index].first == 0 &&
            work->slots[work->index].second == 0) {
            work->index = 0;
        }
    }
}
