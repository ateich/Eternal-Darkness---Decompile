typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Work {
    struct Work* next;
    struct Work* prev;
    u8 active;
    u8 owner;
    u8 data[0x185e];
} Work;

extern Work* lbl_8064D39C;
extern Work* lbl_8064D394;
extern u8* lbl_8064D380;
extern void fn_801B244C(Work*);
extern int fn_801B4FB4(u8, u32);
extern int fn_801B261C(void);
extern u8 fn_801B8574(u8);

void fn_801B5228(u32 elapsed)
{
    Work* work;
    Work* next;

    if (elapsed == 0)
        return;

    for (work = lbl_8064D39C; work != 0; work = next) {
        int busy;
        int pending;

        next = work->next;
        lbl_8064D380 = (u8*)work;
        (void)fn_801B8574(work->data[0xEA6]);
        busy = fn_801B4FB4(0, elapsed);
        pending = fn_801B261C();

        if (busy == 0 && pending == 0) {
            if (work->prev != 0)
                work->prev->next = next;
            else
                lbl_8064D39C = next;
            if (next != 0)
                next->prev = work->prev;

            fn_801B244C(work);
            work->active = 0;
            work->prev = 0;
            work->next = lbl_8064D394;
            if (lbl_8064D394 != 0)
                lbl_8064D394->prev = work;
            lbl_8064D394 = work;
        }
    }
}
