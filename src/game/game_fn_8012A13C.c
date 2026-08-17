typedef unsigned char u8;

void* fn_8012A13C(u8* owner, int index)
{
    void** entries = *(void***)(owner + 0x288);
    void* entry = 0;
    if (entries != 0 && index < *(unsigned short*)(owner + 0x2D6) && index >= 0) {
        entry = entries[index];
    }
    if (entry == 0 && entries != 0 && *(unsigned short*)(owner + 0x2D6) > 15) {
        entry = entries[15];
    }
    if (entry == 0) {
        int count = *(unsigned short*)(owner + 0x2D6);
        while (count-- > 0) {
            entry = *entries;
            if (entry != 0) {
                break;
            }
            entries++;
        }
    }
    return entry;
}
