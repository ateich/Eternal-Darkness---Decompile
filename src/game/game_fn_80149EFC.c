extern void* lbl_8064D098;
extern void* lbl_8064D09C;
extern void* lbl_8064D0A0;
extern unsigned int lbl_8064D090;
extern char lbl_8024EFF8[];
extern void* fn_801FEA8C(unsigned int, int, const char*, int);
extern void* fn_8017CCD8(void*, unsigned int, unsigned short);
extern void fn_80149F9C(void);

void fn_80149EFC(unsigned short instance_count, unsigned short work_count)
{
    void* work;
    void* memory;

    memory = fn_801FEA8C(instance_count * 0x1338, 1, lbl_8024EFF8, 222);
    lbl_8064D09C = fn_8017CCD8(memory, 0x1338, instance_count);
    fn_80149F9C();
    work = fn_801FEA8C(work_count * 200, 1, lbl_8024EFF8, 226);
    memory = fn_8017CCD8(work, 200, work_count);
    lbl_8064D098 = memory;
    lbl_8064D0A0 = work;
    lbl_8064D090 = work_count;
}
