typedef struct Message {
    unsigned int first;
    unsigned int second;
    float time;
} Message;

extern void *memcpy(void *, const void *, unsigned int);
extern float lbl_8064F010;
extern int fn_80201B54();
#define FN_80201E78_RETURN void
#define FN_80201E78_PARAMETERS void *, void *
extern FN_80201E78_RETURN fn_80201E78(FN_80201E78_PARAMETERS);extern int fn_80201EB8();
extern void *fn_801E2E1C(unsigned int, void *, unsigned int);
extern void fn_801E3020(void *, unsigned int, void *, unsigned int, void *,
                       void *, void *, void *, void *, void *);
extern void *fn_800CD568(unsigned int, void *, unsigned int, void *, float,
                        void *, void *);

unsigned short fn_800BB6A0(void *input, void *object)
{
    Message message;
    unsigned int vector[3];
    void *a;
    void *b;
    void *c;
    void *d;
    void *owner;
    void *runtime;
    void *resource;
    void *result;

    memcpy(&message, input, sizeof(message));
    if (message.time >= lbl_8064F010) {
        owner = ((void *)fn_80201B54(object));
        fn_80201E78(vector, object);
        runtime = (void *)fn_80201EB8(object);
        resource = fn_801E2E1C(message.second, owner, message.first);
        fn_801E3020(runtime, message.second, vector, message.first, owner, &a,
                    &b, &c, &d, resource);
        result = fn_800CD568(message.first, owner, message.second, a,
                            message.time, d, resource);
        *(void **)b = ((void *)fn_80201B54(result));
        *(void **)c = *(void **)b;
    }
    return sizeof(message);
}
