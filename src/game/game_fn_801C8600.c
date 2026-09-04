typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Channel Channel;

struct Channel {
    Channel* next;
    u8 pad04[0x10];
    float scale;
    u8 pad18[4];
    u8 channel;
    u8 previous_channel;
    u8 pad1E[2];
    Channel* first;
    Channel* second;
    u32 flags;
    u8 pad2C[8];
    u8 values[4];
};

extern Channel* lbl_8064D4C8;
extern float lbl_80650FD0;

extern void fn_801B9310(u8, u8*);
extern void fn_801B9330(u8, u8*);

void fn_801C8600(void)
{
    Channel* item = lbl_8064D4C8;
    float constant = lbl_80650FD0;

    while (item != 0) {
        if ((item->flags & 0x80000000) == 0) {
            if (item->first->channel != 0xFF && item->second->channel != 0xFF) {
                u8 value0 = (u8)(constant * item->scale);
                u8 value1 = (u8)((float)item->channel * item->scale);
                item->values[1] = value1;
                item->values[2] = 0;
                item->values[0] = value0;
                if ((item->flags & 1) != 0) {
                    item->values[3] = item->second->channel;
                    fn_801B9310(item->first->channel, item->values);
                } else {
                    item->values[3] = item->first->channel;
                    fn_801B9310(item->second->channel, item->values);
                }
                item->flags |= 0x80000000;
            }
        } else {
            u8 first = item->first->channel;
            if (first == 0xFF || item->second->channel == 0xFF) {
                if ((first != 0xFF && first == item->previous_channel) ||
                    (item->second->channel != 0xFF && item->second->channel == item->previous_channel)) {
                    fn_801B9330(item->previous_channel, item->values);
                }
                item->flags &= 0x7FFFFFFF;
            } else {
                u8 value0 = (u8)(constant * item->scale);
                u8 value1 = (u8)((float)item->channel * item->scale);
                item->values[1] = value1;
                item->values[2] = 0;
                item->values[0] = value0;
            }
        }
        item = item->next;
    }
}
