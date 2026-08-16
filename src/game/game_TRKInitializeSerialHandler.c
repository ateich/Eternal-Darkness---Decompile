typedef unsigned char u8;

typedef struct TRKSerialState {
    int buffer_id;
    int unk4;
    u8 state;
    u8 pad9[3];
    int count;
} TRKSerialState;

extern TRKSerialState lbl_80329FC4;

int TRKInitializeSerialHandler(void)
{
    lbl_80329FC4.buffer_id = -1;
    lbl_80329FC4.state = 0;
    lbl_80329FC4.count = 0;
    return 0;
}
