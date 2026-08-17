typedef unsigned char u8;

extern void fn_801F5B60(void*, int, void*, void*);

void fn_8012B9C8(u8* owner, void* value)
{
    int count;
    int index;
    u8* entry;

    index = 0;
    entry = *(u8**)(owner + 0x60);
    count = *(int*)(owner + 0x5C);

    while (index < count) {
        fn_801F5B60(entry, index, owner + 0x58, value);
        index++;
        entry += 0x20;
    }
}
