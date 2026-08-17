typedef unsigned char u8;
typedef unsigned int u32;

int fn_8012DC94(u8* owner, u32 index)
{
    void** entries = *(void***)(owner + 0x240);
    int result = 0;

    if (entries != 0 && entries[index] != 0) {
        result = 1;
    }
    return result;
}
