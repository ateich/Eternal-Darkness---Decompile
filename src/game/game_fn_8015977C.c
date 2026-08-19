typedef struct Request {
    int value;
    int source;
    int room;
    int effect;
    int flags;
} Request;

extern void fn_80159440(int, int);
extern void fn_80159630(Request*);

void fn_8015977C(int value, int source, int room, int effect, int flags)
{
    Request request;
    request.value = value;
    request.source = source;
    request.room = room;
    request.effect = effect;
    request.flags = flags;
    fn_80159440(value, flags);
    fn_80159630(&request);
}
