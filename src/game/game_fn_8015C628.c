extern int fn_800460FC(void);
extern unsigned char* fn_8015C28C(int);
extern unsigned char* fn_8015C3E0(int);
extern unsigned short fn_8015C470(int);

int fn_8015C628(int value)
{
    int count;
    int index;
    unsigned char* entry;
    unsigned short entry_count;
    int entry_index;

    count = fn_800460FC();
    if (value == -1)
        return 1;

    for (index = 0; index < count; index++) {
        unsigned char* slot = fn_8015C28C(index);
        if (*(signed char*)(slot + 0x8142) != 0 &&
            *(signed char*)(slot + 0x8143) != 0) {
            if (*(short*)(slot + 0x8140) == value)
                return 1;
            if (count == 2) {
                unsigned char* scan;
                entry = fn_8015C3E0(index);
                entry_count = fn_8015C470(index);
                scan = entry;
                for (entry_index = 0; entry_index < entry_count; entry_index++) {
                    if (value == *(int*)(scan + 0x28))
                        return 1;
                    scan += 0x5c;
                }
            }
        }
    }
    return 0;
}
