typedef struct Message {
    unsigned int value;
    signed short count;
    unsigned short pad;
} Message;

extern void *memcpy(void *, const void *, unsigned int);
extern int fn_80201B54();
#define FN_80201E78_RETURN void
#define FN_80201E78_PARAMETERS void *, void *
extern FN_80201E78_RETURN fn_80201E78(FN_80201E78_PARAMETERS);extern int fn_80201EB8();
extern void *fn_801D9FE4(unsigned int, int);
extern void *fn_801DA3B0(void *, unsigned int, void *, void *, void *, int,
                        void *, void *, void *, void *);
extern void *fn_800CD458(void *, unsigned int, int, void *, void *, void *,
                        void *);
extern void fn_8020104C(int, void*, void*, int, float);
extern const float lbl_8064F0C4;

unsigned short fn_800BB4C4(void *input, void *object)
{
    Message message;
    unsigned int vector[3];
    void *a;
    void *b;
    void *c;
    void *d;
    void *owner;
    void *runtime;
    void *result;

    memcpy(&message, input, sizeof(message));
    if (message.count > 0) {
        owner = ((void *)fn_80201B54(object));
        fn_80201E78(vector, object);
        runtime = (void *)fn_80201EB8(object);
        result = fn_801D9FE4(message.value, message.count);
        result = fn_801DA3B0(runtime, message.value, vector, result, owner, 0,
                            &a, &b, &d, &c);
        result = fn_800CD458(owner, message.value, message.count, a, b, d,
                            result);
        * (void **)c = ((void *)fn_80201B54(result));
        fn_8020104C(0x5c, *(void **)c, *(void **)c, 0, lbl_8064F0C4);
    }
    return sizeof(message);
}
