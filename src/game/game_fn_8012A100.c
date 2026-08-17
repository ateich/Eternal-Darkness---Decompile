typedef unsigned char u8;

int fn_8012A100(u8* owner, int index)
{
    void** entries = *(void***)(owner + 0x288);
    void* entry = 0;
    if (entries != 0 && index < *(unsigned short*)(owner + 0x2D6) && index >= 0) {
        entry = entries[index];
    }
    return entry != 0;
}
