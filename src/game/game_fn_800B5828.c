typedef struct EventRequest {
    unsigned char pad_00[8];
    int status;
    unsigned char value;
} EventRequest;

extern int lbl_8064CA60;
extern void fn_800B25AC(void);
extern void fn_800B1974(int);
extern void fn_800B5F78(int, int);

void fn_800B5828(EventRequest* request)
{
    fn_800B25AC();
    lbl_8064CA60 = 20;
    if (request->status == 0) {
        fn_800B1974(1);
    } else {
        fn_800B5F78(request->value, request->status);
    }
}
