extern void* fn_80201B3C();
extern void* fn_80201B94();
extern int fn_80201C48(void *);
extern void fn_80201DD8(void *, int);
extern void fn_800C63D8(void);

void fn_800BE8D4(int value)
{
    void *object = fn_80201B3C();

    if (object != 0) {
        object = fn_80201B94(object);
        if (object != 0 && value == fn_80201C48(object)) {
            fn_80201DD8(object, 0);
            fn_800C63D8();
        }
    }
}

/*
 * Honest-C boundary: GC/1.3 reverses the encoded operands of the symmetric
 * equality at offset 0x34 (cmpw r30,r3 instead of retail cmpw r3,r30).
 * Size, control flow, and all call relocations otherwise match.
 */
