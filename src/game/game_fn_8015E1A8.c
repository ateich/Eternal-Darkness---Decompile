typedef unsigned char u8;
typedef unsigned int u32;

typedef struct StreamState {
    short handle;
    u8 read_state;
    u8 state;
    u8 pad04[0xC];
    u32 ring_start;
    u32 ring_end;
    u32 cursor;
    u32 produced;
    u32 request;
    u32 consumed;
    u32 limit;
    u32 previous;
    u32 position;
    u32 bound;
    u32 source;
    u32 staging;
    u32 active;
    void* manager;
    int requested_id;
    u32 result;
    u32 bank;
} StreamState;

extern StreamState lbl_805BB1E0;
extern u32 lbl_806477A0[];
extern char lbl_8024F1D8[];
extern char lbl_8024F200[];
extern u8 lbl_8060A240[];
extern u8 lbl_805E28FC[];
extern void fn_80155BB0(const char*, const char*, ...);
extern u32 fn_801332F0(void*, int);
extern void fn_8015E0A0(u32);
extern void fn_8015B274(u32, u32, u32, u32, void*, u32, void*, u32);
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
extern void fn_80158E84(int);
extern int fn_8015E548(int);
extern void fn_8015C020(int);

u32 fn_8015E1A8(int id)
{
    u32 size;
    u32 old_staging;
    u32 buffer;
    int interrupts;

    if (lbl_805BB1E0.requested_id < id) {
        fn_80155BB0(lbl_8024F1D8, lbl_8024F200, id,
                    lbl_805BB1E0.requested_id);
        return 0;
    }
    if (lbl_805BB1E0.requested_id == id)
        return lbl_805BB1E0.result;

    lbl_805BB1E0.requested_id;
    lbl_805BB1E0.bank ^= 1;
    size = fn_801332F0(lbl_805BB1E0.manager, id);
    old_staging = lbl_805BB1E0.staging;
    buffer = lbl_806477A0[lbl_805BB1E0.bank];
    fn_8015E0A0(size);
    fn_8015B274(size, old_staging, buffer, 0x4B904, lbl_8060A240,
                0x400, lbl_805E28FC, 1);

    interrupts = OSDisableInterrupts();
    lbl_805BB1E0.requested_id = id;
    lbl_805BB1E0.result = buffer;
    old_staging = lbl_805BB1E0.result;
    id = lbl_805BB1E0.active;
    lbl_805BB1E0.active = lbl_805BB1E0.staging;
    lbl_805BB1E0.staging += size;
    lbl_805BB1E0.source += size;
    lbl_805BB1E0.cursor = (lbl_805BB1E0.cursor + 31) & ~31;
    lbl_805BB1E0.staging = (lbl_805BB1E0.staging + 31) & ~31;
    if (lbl_805BB1E0.staging >= lbl_805BB1E0.ring_end) {
        lbl_805BB1E0.staging = lbl_805BB1E0.ring_start +
                              lbl_805BB1E0.staging - lbl_805BB1E0.ring_end;
        lbl_805BB1E0.previous += lbl_805BB1E0.ring_end -
                                lbl_805BB1E0.ring_start;
    }
    lbl_805BB1E0.staging = (lbl_805BB1E0.staging + 31) & ~31;
    lbl_805BB1E0.source = (lbl_805BB1E0.source + 31) & ~31;
    fn_80158E84(1);
    if (lbl_805BB1E0.produced - lbl_805BB1E0.cursor > 0x5B160) {
        lbl_805BB1E0.read_state = 3;
        lbl_805BB1E0.state = 3;
    } else if (lbl_805BB1E0.produced != lbl_805BB1E0.cursor) {
        lbl_805BB1E0.read_state = 2;
        lbl_805BB1E0.state = 3;
    } else if (lbl_805BB1E0.state != 5) {
        lbl_805BB1E0.read_state = 1;
        lbl_805BB1E0.state = 4;
    }
    if (id != 0 && lbl_805BB1E0.produced < lbl_805BB1E0.limit) {
        if (lbl_805BB1E0.request > (u32)id) {
            lbl_805BB1E0.produced += (u32)id - lbl_805BB1E0.ring_start +
                                     lbl_805BB1E0.ring_end - lbl_805BB1E0.request;
            lbl_805BB1E0.request = id;
        } else {
            lbl_805BB1E0.produced += (u32)id - lbl_805BB1E0.request;
            lbl_805BB1E0.request = id;
        }
        if (lbl_805BB1E0.produced > lbl_805BB1E0.limit) {
            u32 excess = lbl_805BB1E0.produced - lbl_805BB1E0.limit;
            lbl_805BB1E0.produced -= excess;
            lbl_805BB1E0.request -= excess;
            if (lbl_805BB1E0.request < lbl_805BB1E0.ring_start)
                lbl_805BB1E0.request += lbl_805BB1E0.ring_end -
                                        lbl_805BB1E0.ring_start;
        }
    }
    OSRestoreInterrupts(interrupts);
    if (fn_8015E548(lbl_805BB1E0.read_state))
        fn_8015C020(0);
    return old_staging;
}
