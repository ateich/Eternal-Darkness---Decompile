typedef unsigned char u8;

typedef struct EventRequest {
    u8 pad_00[8];
    int status;
    u8 value;
} EventRequest;

typedef struct SaveSlot {
    u8 pad_00[0x20];
    int index;
    u8 rest[0x1B8 - 0x24];
} SaveSlot;

extern SaveSlot lbl_80320738;
extern SaveSlot lbl_80320978;
extern u8 lbl_8064CA31;
extern int lbl_8064CA34;
extern int lbl_8064CA60;
extern int lbl_8064CA6C;
extern int lbl_8064CE44;

extern void fn_800B25AC(void);
extern void fn_800B261C(int);
extern void fn_800B2548(int, int);
extern void fn_800B611C(int, int);
extern void fn_800B6960(int, int);
extern void fn_800B6A48(int);

void fn_800B5738(EventRequest *request)
{
    int index;

    lbl_8064CA31 = 0;
    fn_800B25AC();
    if (request->status == 0) {
        fn_800B261C(0);
        lbl_8064CA34 = 1;
        lbl_8064CA6C = 1;
        lbl_80320738 = lbl_80320978;
        index = lbl_80320738.index;
        fn_800B6960(index, 1);
        fn_800B6A48(index);
        fn_800B2548(3, request->value);
        if (lbl_8064CE44 & 1) {
            lbl_8064CE44 |= 8;
            fn_800B2548(0x60, request->value);
        }
    } else {
        fn_800B611C(request->value, request->status);
    }
    lbl_8064CA60 = 0x14;
}
