typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

typedef struct TypeDescriptor {
    void* name;
    s32 kind;
    s16 type;
    u8 pad0A[4];
    s16 action;
    u8 pad10[8];
} TypeDescriptor;

typedef struct ObjectDescriptor {
    void* name;
    s32 kind;
    u8 pad08[0x12];
    s8 type;
    u8 pad1B;
    s16 action;
    u8 pad1E[0xA];
} ObjectDescriptor;

extern TypeDescriptor lbl_802417D0[];
extern ObjectDescriptor lbl_80241DE8[];
extern void* lbl_8024E388[];

extern void fn_801E7974(void*, s32);

void fn_80054A04(s32 type)
{
    s32 object_type;
    s32 i;
    s32 j;

    for (i = 0; i < 65; i++) {
        s32 action = lbl_802417D0[i].action;

        if (action != -1) {
            u8 descriptor_type = lbl_802417D0[i].type;

            if (descriptor_type == 0xFF) {
                descriptor_type = 1;
            }
            if (descriptor_type == (u8)type) {
                fn_801E7974(lbl_8024E388[descriptor_type - 1], action);
            }
        }
    }

    {
        void** resources;

        j = 0;
        resources = lbl_8024E388;
        object_type = (u8)type - 1;

        for (; j < 173; j++) {
            s32 action = lbl_80241DE8[j].action;

            if (action != -1) {
                s8 descriptor_type = lbl_80241DE8[j].type;

                if (descriptor_type == object_type || descriptor_type == -1) {
                    fn_801E7974(resources[(s8)(descriptor_type > 0 ? descriptor_type : 0)],
                                action);
                }
            }
        }
    }
}
