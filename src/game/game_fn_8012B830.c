typedef unsigned char u8;
typedef unsigned short u16;

int fn_8012B830(u8* owner, u16 id)
{
    int item_offset;
    int offset;
    u16 item;
    u8* entry;
    int result;
    int index;
    int count;

    result = -1;
    offset = 0;

    while (result == -1) {
        entry = *(u8**)(*(u8**)(owner + 0x3C) + 0xE4) + offset;
        item_offset = 0;
        count = *(u16*)(entry + 6);

        for (index = 0; index < count; index++) {
            item = *(u16*)(*(u8**)(entry + 8) + item_offset);
            if ((item & 0x8000) == 0 && id == item) {
                result = *(int*)entry;
                break;
            }
            item_offset += 2;
        }
        offset += 0x18;
    }
    return result;
}
