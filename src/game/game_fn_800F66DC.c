extern void *OSGetArenaLo(void);
extern void *OSGetArenaHi(void);
extern void OSSetArenaLo(void *);
extern void *fn_8020AF08(void *, void *, int);
extern void fn_8020AF78(void *, void *);
extern void fn_8020AEF8(void);
extern void fn_8020AE7C(int, void *);

static int lbl_8064CC30;
static int unused;

void fn_800F66DC(void *block)
{
    void *arena_lo;
    void *arena_hi;

    if (!lbl_8064CC30) {
        arena_lo = OSGetArenaLo();
        arena_hi = OSGetArenaHi();
        arena_lo = fn_8020AF08(arena_lo, arena_hi, 1);
        OSSetArenaLo(arena_lo);
        arena_hi = (void *)((unsigned int)arena_hi & ~31);
        arena_lo = (void *)(((unsigned int)arena_lo + 31) & ~31);
        fn_8020AF78(arena_lo, arena_hi);
        fn_8020AEF8();
        OSSetArenaLo(arena_hi);
        lbl_8064CC30 = 1;
    }
    fn_8020AE7C(0, block);
}
