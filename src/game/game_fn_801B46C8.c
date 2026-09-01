typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

typedef struct Event {
    u8 pad00[8];
    u32 value8;
    u8* source;
    void* decoder;
    u8 type;
    u8 channel;
} Event;

typedef struct DecodeState {
    u32 position;
    u32 base;
    u8* current;
    void* record;
    u8* lower_stream;
    u16 lower_delta;
    s16 lower_step;
    u32 lower;
    u8* upper_stream;
    u16 upper_delta;
    s16 upper_step;
    u32 upper;
    u8 selector;
} DecodeState;

typedef struct Dispatch {
    u8 pad00[8];
    u8* base;
    void* record;
    Event* event;
    u8 kind;
    u8 channel;
} Dispatch;

extern u8* lbl_8064D380;
extern u32 lbl_8064D388;
extern u8 lbl_8064D38C;
extern Event* fn_801B443C(u8);
extern u8* fn_801B4398(u8*, u16*, s16*);
extern void* fn_801B2528(u8*, int);
extern void fn_801CA7C0(int, int, int, int);
extern void fn_801CAD90(int, int, int, int);
extern void fn_801B2748(void);

/*
 * Event/message dispatcher for one of the 64 sequence channels.  The retail
 * routine also contains the complete controller-event jump table and voice
 * allocation path; the structured cases below preserve the recovered state
 * transitions while that large compiler-sensitive middle remains unmatched.
 */
Event* fn_801B46C8(Dispatch* dispatch, int owner)
{
    DecodeState* decoder;
    Event* event;
    u16 delta;

    switch (dispatch->kind) {
    case 4:
        decoder = (DecodeState*)(lbl_8064D380 + 0x364 + dispatch->channel * 0x2C);
        decoder->position = 0;
        decoder->base = *(u32*)dispatch->record;
        decoder->record = dispatch->record;
        decoder->lower_stream = fn_801B4398(*(u8**)((u8*)dispatch->record + 4) +
                                               *(u32*)(lbl_8064D380 + 0x118),
                                           &delta, &decoder->lower_step);
        decoder->lower = decoder->lower_stream ? delta : 0x7FFFFFFF;
        decoder->lower_delta = 0x2000;
        decoder->upper_stream = fn_801B4398(*(u8**)((u8*)dispatch->record + 8) +
                                               *(u32*)(lbl_8064D380 + 0x118),
                                           &delta, &decoder->upper_step);
        decoder->upper = decoder->upper_stream ? delta : 0x7FFFFFFF;
        decoder->upper_delta = 0;
        decoder->selector = *(u8*)(*(u8**)(lbl_8064D380 + 0x120) +
                                   *(u32*)(lbl_8064D380 + 0x118) + dispatch->channel);
        break;
    case 0:
        event = dispatch->event;
        if ((event->source[2] & 0x80) == 0) {
            if (event->source[3] == 1)
                fn_801CA7C0(0x82, event->decoder ? *(u8*)((u8*)event->decoder + 0x28) : 0,
                            (u8)lbl_8064D388, event->source[2] & 0x7F);
            else if ((event->source[3] & 0x80) != 0)
                fn_801CA7C0(event->source[3], event->decoder ? *(u8*)((u8*)event->decoder + 0x28) : 0,
                            (u8)lbl_8064D388, event->source[2] & 0x7F);
        } else {
            fn_801B2528(dispatch->base + *(u16*)(event->source + 4), owner);
        }
        break;
    case 2:
        decoder = (DecodeState*)dispatch->event;
        decoder->lower_delta += decoder->lower_step;
        if (decoder->lower_stream != 0) {
            decoder->lower_stream = fn_801B4398(decoder->lower_stream, &delta,
                                                &decoder->lower_step);
            decoder->lower = decoder->lower_stream ? decoder->lower + delta : 0x7FFFFFFF;
        }
        fn_801CAD90(0x80, decoder->selector, (u8)lbl_8064D388,
                    decoder->lower_delta);
        break;
    case 1:
        decoder = (DecodeState*)dispatch->event;
        decoder->upper_delta += decoder->upper_step;
        if (decoder->upper_stream != 0) {
            decoder->upper_stream = fn_801B4398(decoder->upper_stream, &delta,
                                                &decoder->upper_step);
            decoder->upper = decoder->upper_stream ? decoder->upper + delta : 0x7FFFFFFF;
        }
        fn_801CAD90(1, decoder->selector, (u8)lbl_8064D388,
                    decoder->upper_delta);
        break;
    case 3:
        *(u32*)dispatch->record |= 1;
        return 0;
    }
    return fn_801B443C(dispatch->channel);
}
