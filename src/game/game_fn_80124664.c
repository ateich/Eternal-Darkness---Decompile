typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct Channel {
    float value, upper, lower, rise, fall, delta;
    s32 repeats, delay, timer;
    u32 flags;
} Channel;

typedef struct Table {
    u8 pad[0xC];
    u16 count;
    u8 padE[0x1A];
    u8* entries;
} Table;

typedef struct Owner {
    u8 pad[0x3C];
    Table* table;
    u8 pad40[0x25C];
    Channel* channels;
    u8 pad2A0[0x24];
    u32 active;
} Owner;

extern const float lbl_80650110;
extern const double lbl_80650178;

void fn_80124664(Owner* owner, s32 index, u32 flags, float value)
{
    s32 channel_offset = index * 0x28;
    Channel* channel;
    Table* table = owner->table;
    u16 count;
    channel = (Channel*)((u8*)owner->channels + channel_offset);
    count = table->count;

    if (!(channel->flags & 8) || (flags & 8)) {
        u32 one = 1;
        s32 entry_index = index * 8;
        u32 bit = one << index;
        u32 new_flags = flags | 5;
        u32 inverse = ~bit;
        s32 offset;
        s32 i;
        for (offset = 0, i = 0; i < count; i++) {
            u8* entry = table->entries + offset + 0x14;
            if (entry != 0 && *(u32*)(entry + entry_index) != 0xFFFFFFFF) {
                if (lbl_80650178 == value) {
                    channel->flags = 0;
                    owner->active &= inverse;
                } else {
                    channel->value = value;
                    owner->active |= bit;
                    channel->upper = value;
                    channel->lower = value;
                    channel->rise = lbl_80650110;
                    channel->fall = lbl_80650110;
                    channel->delta = lbl_80650110;
                    channel->repeats = 1;
                    channel->delay = 0;
                    channel->timer = 0;
                    channel->flags = new_flags;
                }
            }
            offset += 0x114;
        }
    }
}
