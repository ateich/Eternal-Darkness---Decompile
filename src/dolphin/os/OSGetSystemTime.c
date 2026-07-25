typedef int BOOL;
typedef unsigned long long OSTime;

extern BOOL OSDisableInterrupts(void);
extern void OSRestoreInterrupts(BOOL level);
extern OSTime OSGetTime(void);

/*
 * Natural C for this routine is:
 *
 *     OSTime __OSGetSystemTime(void) {
 *         BOOL enabled;
 *         OSTime time;
 *         enabled = OSDisableInterrupts();
 *         time = OSGetTime() + *(OSTime*)0x800030D8;
 *         OSRestoreInterrupts(enabled);
 *         return time;
 *     }
 *
 * That source reproduces every instruction and both 64-bit adds, but no
 * MWCC release we hold emits retail's exact prologue/frame combination.
 * The three traits below split cleanly at the 1.2.5n / 1.3 boundary:
 *
 *   GC/1.0 - GC/1.2.5n : mflr-first prologue, 24-byte frame, addi-form moves
 *   GC/1.3 - GC/3.0a5.2: stwu-first prologue, 32-byte frame, mr-form moves
 *
 * Retail is mflr-first (<= 1.2.5n) with a 32-byte frame and mr-form moves
 * (>= 1.3), so it was built by a revision between the two. See
 * reports/GEDE01/matching-cycle-2026-07-25.md for the full sweep. The body
 * is therefore written as transparent inline assembly, matching how the
 * adjacent __OSTimeToSystemTime input is already represented.
 */
asm OSTime __OSGetSystemTime(void)
{
    nofralloc
    mflr r0
    stw r0, 4(r1)
    stwu r1, -0x20(r1)
    stw r31, 0x1c(r1)
    stw r30, 0x18(r1)
    stw r29, 0x14(r1)
    bl OSDisableInterrupts
    mr r31, r3
    bl OSGetTime
    lis r6, 0x8000
    lwz r5, 0x30dc(r6)
    lwz r0, 0x30d8(r6)
    addc r29, r5, r4
    adde r30, r0, r3
    mr r3, r31
    bl OSRestoreInterrupts
    mr r4, r29
    mr r3, r30
    lwz r0, 0x24(r1)
    lwz r31, 0x1c(r1)
    lwz r30, 0x18(r1)
    lwz r29, 0x14(r1)
    addi r1, r1, 0x20
    mtlr r0
    blr
}
