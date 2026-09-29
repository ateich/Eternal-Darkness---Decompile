asm long long fn_800F623C(int high, unsigned int low, unsigned int shift)
{
    nofralloc
    subfic r8, r5, 32
    subic. r9, r5, 32
    srw r4, r4, r5
    slw r10, r3, r8
    or r4, r4, r10
    sraw r10, r3, r9
    ble done
    or r4, r4, r10
done:
    sraw r3, r3, r5
    blr
}
