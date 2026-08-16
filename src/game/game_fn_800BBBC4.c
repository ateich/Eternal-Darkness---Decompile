typedef struct Message { unsigned int value; float time; } Message;
extern void *memcpy(void *, const void *, unsigned int); extern int fn_80201B54();
extern void fn_800CDAD8(unsigned int, void *, int, float);
extern float lbl_8064F010;
unsigned short fn_800BBBC4(void *input, void *object)
{
    Message message; memcpy(&message, input, sizeof(message));
    if (message.time >= lbl_8064F010) fn_800CDAD8(message.value, ((void *)fn_80201B54(object)), 0, message.time);
    return sizeof(message);
}
