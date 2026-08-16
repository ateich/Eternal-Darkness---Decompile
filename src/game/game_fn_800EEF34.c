typedef unsigned char u8;
typedef unsigned int u32;
typedef struct TRKEvent {
    u8 type;
    u8 pad[3];
    u32 id;
    int buffer;
} TRKEvent;
typedef struct TRKEventQueue {
    u32 mutex;
    int count;
    int next;
    TRKEvent events[2];
    u32 next_id;
} TRKEventQueue;

extern TRKEventQueue lbl_803285E0;
extern void fn_800F34C4(void *);
extern void fn_800F34BC(void *);
extern void fn_80003130(void *, const void *, u32);

int fn_800EEF34(const TRKEvent *event)
{
    int result = 0;
    int offset;

    fn_800F34C4(&lbl_803285E0);
    if (lbl_803285E0.count == 2) {
        result = 0x100;
    } else {
        offset = (lbl_803285E0.next + lbl_803285E0.count) % 2;
        fn_80003130(&lbl_803285E0.events[offset], event, 12);
        lbl_803285E0.events[offset].id = lbl_803285E0.next_id;
        lbl_803285E0.next_id++;
        if (lbl_803285E0.next_id < 0x100)
            lbl_803285E0.next_id = 0x100;
        lbl_803285E0.count++;
    }
    fn_800F34BC(&lbl_803285E0);
    return result;
}
