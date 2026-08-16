typedef struct Message {
    unsigned int value;
    unsigned int unused;
    float amount;
} Message;

extern void *memcpy(void *, const void *, unsigned int);
extern int fn_80201B44();
extern void fn_800CDE80(void *, unsigned int, float, int);

unsigned short fn_800BB3F8(void *input, unsigned int flags)
{
    Message message;

    memcpy(&message, input, sizeof(message));
    if (flags & 2) {
        fn_800CDE80(((void *)fn_80201B44()), message.value, message.amount, 0);
    }
    return sizeof(message);
}
