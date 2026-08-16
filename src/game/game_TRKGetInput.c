typedef unsigned char u8;
typedef unsigned int u32;

typedef struct TRKEvent {
    u8 type;
    u8 pad[3];
    u32 id;
    int buffer;
} TRKEvent;

typedef struct TRKBuffer {
    u32 mutex;
    u32 in_use;
    u32 length;
    u32 position;
    u8 data[0x880];
} TRKBuffer;

typedef struct TRKSerialState {
    int buffer_id;
    int unk4;
    u8 state;
    u8 pad9[3];
    int count;
} TRKSerialState;

extern TRKSerialState lbl_80329FC4;
extern int fn_800EFFBC(void);
extern TRKBuffer *TRKGetBuffer(int);
extern int fn_800EFC6C(TRKBuffer *, u32);
extern int fn_800EF86C(TRKBuffer *, u8 *);
extern void fn_800EEF1C(TRKEvent *, int);
extern int fn_800EEF34(const TRKEvent *);
extern void fn_800EFCDC(int);

void TRKGetInput(void)
{
    TRKBuffer *buffer;
    int buffer_id;

    buffer_id = fn_800EFFBC();

    if (buffer_id != -1) {
        u8 command;

        buffer = TRKGetBuffer(buffer_id);
        fn_800EFC6C(buffer, 0);
        fn_800EF86C(buffer, &command);
        if (command < 0x80) {
            TRKEvent event;
            fn_800EEF1C(&event, 2);
            event.buffer = buffer_id;
            lbl_80329FC4.buffer_id = -1;
            fn_800EEF34(&event);
        } else {
            fn_800EFCDC(buffer_id);
        }
    }
}
