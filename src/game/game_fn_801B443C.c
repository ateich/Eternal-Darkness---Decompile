typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct ChannelEntry {
    u32 value0;
    u8 pad04[4];
    u16 type;
    u16 index;
} ChannelEntry;

typedef struct Channel {
    u8* base;
    ChannelEntry* current;
} Channel;

typedef struct Decoder {
    u32 position;
    u32 base;
    u8* current;
    u8 pad0C[12];
    u32 lower;
    u8 pad1C[8];
    u32 upper;
} Decoder;

typedef struct Result {
    u8 pad00[8];
    u32 value8;
    u8* source;
    Decoder* decoder;
    u8 type;
    u8 channel;
    u8 pad16[2];
} Result;

extern u8* lbl_8064D380;

Result* fn_801B443C(u8 channel_index)
{
    u8* state = lbl_8064D380;
    u8 index = channel_index;
    Channel* channel = (Channel*)(state + 0x124 + index * 8);
    Decoder* decoder = (Decoder*)(state + 0x364 + index * 0x2C);
    Result* result;

    if (channel->current == 0)
        goto no_result;

    result = (Result*)(state + 0xEE4 + index * 0x18);
    result->channel = channel_index;
    result->decoder = decoder;

retry:
    if (decoder->current == 0) {
direct:
        if (channel->current->type == 0xFFFF) {
            channel->current = 0;
            return 0;
        }
        if (channel->current->type == 0xFFFE) {
            u8* global_state = lbl_8064D380;
            u8* table = *(u8**)(global_state + 0x14E4);
            if (table == 0) {
                if (global_state[0x151E] == 0)
                    goto direct_result;
                channel->current = 0;
                return 0;
            }
            if (global_state[0x151E + table[index] * 0x38] != 0) {
                channel->current = 0;
                return 0;
            }
direct_result:
            result->type = 3;
            result->value8 = channel->current->value0;
            channel->current = (ChannelEntry*)(channel->base + channel->current->index * 12);
            return result;
        }
        result->type = 4;
        result->value8 = channel->current->value0;
        result->source = (u8*)channel->current;
        channel->current = (ChannelEntry*)((u8*)channel->current + 12);
        return result;
    }

    {
        u32 lower = decoder->lower;
        u32 upper = decoder->upper;
        u8* current = decoder->current;
        u32 position = *(u16*)current + decoder->position;
        if (position < lower) {
            if (position < upper) {
                if (current[2] == 0xFF && current[3] == 0xFF) {
                    decoder->current = 0;
                    goto direct;
                }
                result->source = current;
                decoder->position = position;
                current = decoder->current;
                if (current[2] & 0x80)
                    decoder->current = current + 4;
                else if ((current[2] | current[3]) == 0) {
                    decoder->current = current + 4;
                    goto retry;
                } else
                    decoder->current = current + 6;
                result->type = 0;
                result->value8 = position + decoder->base;
            } else
                goto upper_result;
        } else {
            if (lower < upper) {
                result->value8 = lower + decoder->base;
                result->type = 2;
            } else {
upper_result:
                result->value8 = upper + decoder->base;
                result->type = 1;
            }
        }
    }
    return result;

no_result:
    return 0;
}
