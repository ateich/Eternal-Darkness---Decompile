typedef struct EventRequest {
    unsigned char pad_00[8];
    int status;
    unsigned char value;
} EventRequest;

extern unsigned char lbl_8064CA31;
extern int lbl_8064CA60;
extern void fn_800B25AC(void);
extern int fn_800B1944(void);
extern void fn_800B6840(int, int);
extern void fn_800B611C(int, int);
extern void fn_800B1974(int);

void fn_800B566C(EventRequest* request)
{
    lbl_8064CA31 = 0;
    fn_800B25AC();
    lbl_8064CA60 = 20;
    switch (fn_800B1944()) {
    case 0:
        if (request->status == 0) {
            fn_800B6840(request->value, request->status);
        } else {
            fn_800B611C(request->value, request->status);
        }
        break;
    case 1:
        if (request->status == 0) {
            fn_800B1974(1);
        } else {
            fn_800B611C(request->value, request->status);
        }
        break;
    case 2:
    case 3:
        if (request->status == 0) {
            fn_800B1974(1);
        } else {
            fn_800B611C(request->value, request->status);
        }
        break;
    }
}
