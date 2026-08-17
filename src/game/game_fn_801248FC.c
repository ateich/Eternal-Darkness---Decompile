typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

typedef struct Channel {
    float value, upper, lower, rise, fall, delta;
    s32 repeats, delay, timer;
    u32 flags;
} Channel;

typedef struct Owner {
    u8 pad[0x29C];
    Channel* channels;
    u8 pad2A0[0x24];
    u32 active;
} Owner;

extern const float lbl_80650110;

void fn_801248FC(Owner* owner)
{
    s32 offset;
    s32 index;
    s32 count = 32;

    index = 0;
    offset = 0;

    while (count--) {
        Channel* channel = (Channel*)((u8*)owner->channels + offset);
        if (channel->flags & 1) {
            if (channel->timer > 0) {
                channel->timer--;
            } else {
                channel->value += channel->delta;
                if (channel->value >= channel->upper) {
                    if (channel->flags & 2) {
                        channel->delta = -channel->fall;
                    } else {
                        channel->delta = lbl_80650110;
                        channel->value = channel->upper;
                    }
                    channel->timer = channel->delay;
                } else if (channel->value <= channel->lower) {
                    if (channel->flags & 2) {
                        channel->delta = channel->rise;
                        if (!(channel->flags & 4)) {
                            channel->repeats--;
                        }
                    } else {
                        channel->delta = lbl_80650110;
                        channel->value = channel->lower;
                        if (lbl_80650110 == channel->value) {
                            channel->repeats--;
                        }
                    }
                    channel->timer = channel->delay;
                }
            }
            if (channel->repeats <= 0) {
                channel->flags = 0;
                owner->active &= ~(1 << index);
                channel->repeats = 0;
            }
        }
        offset += 0x28;
        index++;
    }
}
