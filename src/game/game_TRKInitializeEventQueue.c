typedef unsigned int u32;
typedef struct TRKEventQueue {
    u32 mutex;
    int count;
    int next;
    u32 events[6];
    u32 next_id;
} TRKEventQueue;

extern TRKEventQueue lbl_803285E0;
extern void fn_800F34CC(void *);
extern void fn_800F34C4(void *);
extern void fn_800F34BC(void *);

int TRKInitializeEventQueue(void)
{
    fn_800F34CC(&lbl_803285E0);
    fn_800F34C4(&lbl_803285E0);
    lbl_803285E0.count = 0;
    lbl_803285E0.next = 0;
    lbl_803285E0.next_id = 0x100;
    fn_800F34BC(&lbl_803285E0);
    return 0;
}
