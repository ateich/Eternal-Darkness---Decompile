typedef unsigned char u8;

extern void fn_801F5C74(void*);

void fn_8012BA28(u8* owner)
{
    int count;
    int index;
    u8* entry;

    index = 0;
    entry = *(u8**)(owner + 0x60);
    count = *(int*)(owner + 0x5C);

    while (index < count) {
        fn_801F5C74(entry);
        index++;
        entry += 0x20;
    }
}
