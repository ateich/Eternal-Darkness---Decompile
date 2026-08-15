typedef struct Message { unsigned int first; unsigned int second; float time; unsigned char byte; unsigned char pad[3]; } Message;
extern void *memcpy(void *, const void *, unsigned int);
extern void fn_800CD8C0(unsigned int, unsigned int, void *, unsigned char, int);
extern float lbl_8064F010;
unsigned short fn_800BBA84(void *input, void *object)
{
    Message message; memcpy(&message, input, sizeof(message));
    if (message.time > lbl_8064F010) fn_800CD8C0(message.first, message.second, object, message.byte, (int)message.time);
    return sizeof(message);
}
