asm void fn_801A2AB4(void* matrix, void* input, void* output, int count)
{
    nofralloc
    stwu r1, -0x40(r1)
    stfd f14, 0x8(r1)
    subi r11, r6, 1
    stfd f15, 0x10(r1)
    srwi r11, r11, 1
    stfd f16, 0x18(r1)
    stfd f17, 0x20(r1)
    stfd f18, 0x28(r1)
    mtctr r11
    psq_l f0, 0(r3), 0, 0
    subi r4, r4, 4
    psq_l f1, 8(r3), 1, 0
    subi r5, r5, 2
    psq_l f6, 0x24(r3), 0, 0
    psq_lu f8, 4(r4), 0, 5
    psq_l f7, 0x2c(r3), 1, 0
    psq_lu f9, 4(r4), 0, 5
    ps_madds0 f11, f0, f8, f6
    psq_l f2, 0xc(r3), 0, 0
    ps_madds0 f12, f1, f8, f7
    psq_l f3, 0x14(r3), 1, 0
    ps_madds1 f13, f0, f9, f6
    psq_lu f10, 4(r4), 0, 5
    ps_madds1 f14, f1, f9, f7
    psq_l f5, 0x20(r3), 1, 0
    ps_madds1 f11, f2, f8, f11
    ps_madds1 f12, f3, f8, f12
    psq_l f4, 0x18(r3), 0, 0
    psq_lu f8, 4(r4), 0, 5
    ps_madds0 f13, f2, f10, f13
    ps_madds0 f14, f3, f10, f14
    ps_madds0 f15, f4, f9, f11
    ps_madds0 f16, f5, f9, f12
    psq_lu f9, 4(r4), 0, 5
    ps_madds1 f17, f4, f10, f13
    ps_madds1 f18, f5, f10, f14
    psq_lu f10, 4(r4), 0, 5
loop:
    ps_madds0 f11, f0, f8, f6
    psq_stu f15, 2(r5), 0, 5
    ps_madds0 f12, f1, f8, f7
    psq_stu f16, 4(r5), 1, 5
    ps_madds1 f13, f0, f9, f6
    psq_stu f17, 2(r5), 0, 5
    ps_madds1 f14, f1, f9, f7
    psq_stu f18, 4(r5), 1, 5
    ps_madds1 f11, f2, f8, f11
    ps_madds1 f12, f3, f8, f12
    psq_lu f8, 4(r4), 0, 5
    ps_madds0 f13, f2, f10, f13
    ps_madds0 f14, f3, f10, f14
    ps_madds0 f15, f4, f9, f11
    ps_madds0 f16, f5, f9, f12
    psq_lu f9, 4(r4), 0, 5
    ps_madds1 f17, f4, f10, f13
    ps_madds1 f18, f5, f10, f14
    psq_lu f10, 4(r4), 0, 5
    bdnz loop
    psq_stu f15, 2(r5), 0, 5
    psq_stu f16, 4(r5), 1, 5
    clrlwi. r11, r6, 31
    bne done_store
    psq_stu f17, 2(r5), 0, 5
    psq_stu f18, 4(r5), 1, 5
done_store:
    lfd f14, 0x8(r1)
    lfd f15, 0x10(r1)
    lfd f16, 0x18(r1)
    lfd f17, 0x20(r1)
    lfd f18, 0x28(r1)
    addi r1, r1, 0x40
    blr
}
