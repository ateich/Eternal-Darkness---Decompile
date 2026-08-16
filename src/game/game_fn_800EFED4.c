typedef unsigned char u8;
typedef unsigned int u32;

typedef struct TRKEvent {
    u8 type;
    u8 pad[3];
    u32 id;
    int buffer;
} TRKEvent;

typedef struct TRKSerialState {
    int buffer_id;
    int unk4;
    u8 state;
    u8 pad9[3];
    int count;
} TRKSerialState;

extern TRKSerialState lbl_80329FC4;
extern void fn_800EEF1C(TRKEvent *, int);
extern int fn_800EEF34(const TRKEvent *);

void fn_800EFED4(int buffer)
{
    TRKEvent event;

    fn_800EEF1C(&event, 2);
    event.buffer = buffer;
    lbl_80329FC4.buffer_id = -1;
    fn_800EEF34(&event);
}
