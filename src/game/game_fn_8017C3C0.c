typedef unsigned char u8;
typedef unsigned int u32;

typedef struct GlobalState {
    u8 pad_00[0x28];
    int states[2];
} GlobalState;

typedef struct Request {
    int kind;
    int state;
    int result;
    u8 value;
    u8 data[7];
} Request;

extern GlobalState lbl_8064A580;
extern u8 lbl_8064A6C8[];
extern u32 lbl_8064D20C;
extern u32 fn_8017B854(void);
extern int fn_802219B4(u8, u8*, u32, u8*, int);
extern u32 fn_8021EB20(u8);

void fn_8017C3C0(Request* request)
{
    u32 value = request->value;

    if (lbl_8064A580.states[value] == 1) {
        request->result = fn_802219B4(request->value, request->data,
                                     fn_8017B854(),
                                     &lbl_8064A6C8[value * 20], 0);
        if (request->result >= 0) {
            (&lbl_8064D20C)[request->value] = fn_8021EB20(request->value);
            request->state = 1;
        }
    } else {
        request->state = 2;
        request->result = -3;
    }
}
