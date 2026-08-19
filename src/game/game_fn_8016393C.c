#pragma use_lmw_stmw on

extern void fn_80160FAC(void*, char*);
extern unsigned int fn_801639CC(unsigned int);
extern void* fn_8016B5CC(void*, void*, unsigned int, char*, int);
extern char lbl_8064BB28;

void* fn_8016393C(void* allocator, void* block, unsigned int count,
                  unsigned int increment, unsigned int element_size,
                  char* file, unsigned int limit)
{
    unsigned int new_count = count + increment;

    if (count >= limit - increment) {
        fn_80160FAC(allocator, file);
    }
    if (count >= (new_count ^ count) ||
        (count != 0 && new_count < 4)) {
        return block;
    }
    return fn_8016B5CC(allocator, block,
                       element_size * fn_801639CC(new_count),
                       &lbl_8064BB28, 0x7F);
}
