typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Event {
    struct Event* next;
    struct Event* prev;
    u32 time;
} Event;

typedef struct Channel {
    u8 pad00[0x1C];
    Event* head;
    u32 buffer_time[2];
    u32 buffer_value[2];
    u8 pad30;
    u8 active_buffer;
    u16 produced;
} Channel;

extern u8* lbl_8064D380;
extern float lbl_80650EB0;
extern float lbl_80650EB4;
extern float lbl_80650EB8;
extern void fn_801B3470(u8);
extern Event* fn_801B46C8(Event*, u8, Event**);
extern void fn_801B4654(Channel*, Event*);
extern void fn_801B4EF0(u8);
extern float fn_800F6318(float);
extern float fn_800F6264(float);
extern u32 fn_800F5C54(float);
extern float fn_801023C0(float);

int fn_801B4FB4(u8 owner, u32 elapsed)
{
    u32 channel_offset = owner * 0x38;
    Channel* channel = (Channel*)(lbl_8064D380 + 0x14E8 + channel_offset);
    Event* pending = 0;
    Event* event;

    for (;;) {
        event = channel->head;
        if (event != 0) {
            channel->head = event->next;
            if (channel->head != 0)
                channel->head->prev = 0;
        }

        if (event == 0) {
            u32 source;
            u32 sample;
            float phase;
            float rate;

            if (pending == 0)
                return 0;
            pending = 0;
            channel->active_buffer ^= 1;
            source = *(u32*)(*(u8**)(lbl_8064D380 + 0x118) + owner * 4 + 0x14);
            channel->buffer_value[channel->active_buffer] = source;
            channel->buffer_time[channel->active_buffer ^ 1] =
                channel->buffer_time[channel->active_buffer];

            if (*(u32*)(lbl_8064D380 + channel_offset + 0x14E8) != 0) {
                *(u32*)(lbl_8064D380 + channel_offset + 0x14EC) =
                    *(u32*)(lbl_8064D380 + channel_offset + 0x14E8);
                fn_801B3470(owner);
                sample = channel->buffer_time[0];
                rate = lbl_80650EB0 * (float)sample * (float)elapsed;
                rate *= lbl_80650EB4 * (float)channel->produced;
                phase = lbl_80650EB8 * rate;
                if (__fabs(phase) >= __fabs(lbl_80650EB8))
                    phase -= lbl_80650EB8 * fn_800F6264(fn_800F6318(phase / lbl_80650EB8));
                channel->buffer_value[channel->active_buffer] = fn_800F5C54(phase);
                channel->buffer_time[channel->active_buffer] = (u32)fn_801023C0(rate);
                channel->produced++;
                fn_801B4EF0(owner);
            }
        } else {
            event = fn_801B46C8(event, owner, &pending);
            if (event != 0)
                fn_801B4654(channel, event);
        }

        event = channel->head;
        if ((event != 0 ? event->time : 0) > channel->buffer_value[channel->active_buffer])
            return 1;
    }
}
