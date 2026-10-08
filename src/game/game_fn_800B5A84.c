typedef struct EventRequest {
    unsigned char pad_00[8];
    int status;
    unsigned char value;
} EventRequest;

extern int lbl_8064CA60;

extern int fn_800B6908(void);
extern void fn_800B25AC(void);
extern int fn_800B1944(void);
extern void fn_800B6840(int);
extern void fn_800B5F1C(int, int);
extern void fn_800B66F8(int);
extern void fn_800B6718(int);

void fn_800B5A84(EventRequest *request)
{
    fn_800B6908();
    fn_800B25AC();
    switch (fn_800B1944()) {
    case 0:
    case 1:
        if (request->status == 0) {
            fn_800B6840(request->value);
        } else {
            fn_800B5F1C(request->value, request->status);
        }
        break;
    case 2:
        if (request->status == 0) {
            fn_800B66F8(request->value);
        } else {
            fn_800B5F1C(request->value, request->status);
        }
        break;
    case 3:
        if (request->status == 0) {
            fn_800B6718(request->value);
        } else {
            fn_800B5F1C(request->value, request->status);
        }
        break;
    }
    lbl_8064CA60 = 20;
}
