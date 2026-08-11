typedef signed short s16;
typedef unsigned int u32;

typedef struct ObjectInfo {
    unsigned char pad[0x8C];
    void* data;
} ObjectInfo;

typedef struct ObjectData {
    unsigned char pad[0xE2];
    s16 channel1;
    s16 channel2;
    s16 channel3;
} ObjectData;

extern void* fn_80201B8C();
extern u32 fn_8020216C(void*);
extern int fn_80038308(void* object, int channel, short* value);
extern int fn_80038464(void*, int, s16*);
extern int fn_80201B54();
extern int fn_80201B44(void);
extern int fn_80070A6C(int);
extern void* fn_80201BC8();
extern void fn_80201D88(void*, s16);
extern void fn_80036C40(void*, int, s16);
extern int lbl_8064C594;

int fn_800389E0(void* object, int channel, s16 value, int propagate)
{
    void* current_object = object;
    int current_channel = channel;
    int do_propagate = propagate;
    int result = 0;
    ObjectInfo* info;
    u32 flags;
    s16 old_value = -1;
    s16 maximum;
    int object_id;
    int current_id;
    int got_maximum;

    if (current_object != 0 && (info = fn_80201B8C(current_object)) != 0 &&
        info->data != 0) {
        flags = fn_8020216C(current_object);
        fn_80038308(current_object, current_channel, &old_value);
        switch (current_channel) {
        case 0:
            result = !(flags & 0x800);
            break;
        case 3:
            result = !(flags & 0x20000);
            break;
        case 2:
            result = !(flags & 0x2000);
            if (lbl_8064C594 == 0) {
                result = 0;
            }
            break;
        case 1:
            result = !(flags & 0x1000);
            break;
        }

        object_id = fn_80201B54(current_object);
        current_id = fn_80201B44();
        if (current_id == object_id) {
            if (current_channel == 1) {
                result = 1;
            } else if (current_channel == 0 && fn_80070A6C(0x400) != 0) {
                result = 0;
            }
        }

        if (result != 0) {
            if (current_channel == 3) {
                fn_80201BC8(current_object);
                ((ObjectData*)info->data)->channel3 = value;
            } else if (result != 0) {
                maximum = 0;
                got_maximum = fn_80038464(current_object, current_channel,
                                           &maximum);
                value = 0 > value ? 0 : value;
                if (got_maximum != 0) {
                    value = (s16)(maximum < value ? maximum : value);
                }
                switch (current_channel) {
                case 0:
                    fn_80201BC8(current_object);
                    if (result != 0) {
                        fn_80201D88(current_object, value);
                    }
                    break;
                case 1:
                    if (result != 0) {
                        ((ObjectData*)info->data)->channel1 = value;
                    }
                    break;
                case 2:
                    if (result != 0) {
                        ((ObjectData*)info->data)->channel2 = value;
                    }
                    break;
                }
                if (do_propagate != 0) {
                    fn_80036C40(current_object, current_channel, old_value);
                }
            }
        }
    }
    return result;
}
