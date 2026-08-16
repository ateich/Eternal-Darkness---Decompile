typedef struct Message {
    unsigned int first;
    unsigned int second;
    float time;
    unsigned char padC[4];
    unsigned int fourth;
    unsigned int fifth;
    unsigned int sixth;
    unsigned char byte;
    unsigned char pad1D[3];
} Message;

extern void *memcpy(void *, const void *, unsigned int);
extern void *fn_80201B54();
extern void *fn_80201AE4(void);
extern void *fn_801D71A4(unsigned int, void *, void *, unsigned char, void *, void *, unsigned int, float, void *);
extern void *fn_800CD6C0(void *, unsigned int, void *, unsigned char, unsigned int, signed short, void *, float, void *);
extern void fn_801D7C24(unsigned int, void *, float, unsigned int, int);
extern float lbl_8064F010;

unsigned short fn_800BB8AC(void *input, void *object)
{
    Message message;
    void *a;
    void *b;
    void *c;
    void *vector;
    void *owner;
    void *result;

    memcpy(&message, input, sizeof(message));
    if (message.time >= lbl_8064F010) {
        owner = fn_80201B54(object);
        vector = &message.fourth;
        result = fn_801D71A4(message.first, vector, owner, message.byte,
                            &a, &b, message.second, lbl_8064F010, &c);
        *(void **)b = fn_80201B54(fn_800CD6C0(owner, message.first, a,
                                              message.byte, message.second,
                                              *(signed short *)&message.padC[0],
                                              vector, message.time, c));
        fn_801D7C24(message.first, result, lbl_8064F010,
                    owner != fn_80201AE4(), 0);
    }
    return sizeof(message);
}
