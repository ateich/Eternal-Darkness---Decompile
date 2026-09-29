extern unsigned char lbl_8023B7D8[];
extern float lbl_80651460;
extern float lbl_80651464;
extern float lbl_8064D7A0;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct ObjectState {
    unsigned char prefix[0x550];
    unsigned char fields[0x30];
    float scalar;
    unsigned char padding584[0x14];
    Vec3 vector;
    unsigned char padding5A4[0x20];
    void* link;
    unsigned char padding5C8[0x98];
} ObjectState;
extern ObjectState lbl_8063C6B8[];

extern void fn_801F7034(void*, int);
extern void fn_801F8994(void*, const Vec3*, float);
extern void fn_801F8620(void);
extern void fn_801FA410(int);

/* Preserve the group address as a distinct expression before field access. */
static inline ObjectState* state_at(ObjectState* base, int index)
{
    return &base[index];
}

/* NonMatching: 268 bytes and the retail 0x30 frame/four saved registers.
 * GC/1.3 still folds group/field offsets, rematerializes the global base,
 * and assigns the second/third pointers to r28/r30 instead of r30/r28. */
void* fn_801F7AF8(void)
{
    ObjectState* base = lbl_8063C6B8;
    unsigned char* first;
    unsigned char* second;
    unsigned char* third;
    Vec3 values = *(Vec3*)lbl_8023B7D8;

    first = state_at(base, 1)->fields;
    fn_801F7034(first, 1);

    second = state_at(base, 0)->fields;
    fn_801F7034(second, 1);

    state_at(base, 1)->link = second;
    third = (unsigned char*)state_at(base, 2);
    state_at(base, 0)->vector = values;
    state_at(base, 1)->vector = values;

    fn_801F8994(first, (Vec3*)third, *(float*)(third + 0x34));
    fn_801F8994(second, (Vec3*)((unsigned char*)state_at(base, 2) + 0x88),
                *(float*)(third + 0x34));
    fn_801F8620();
    fn_801FA410(10);

    lbl_8064D7A0 = lbl_80651464;
    state_at(base, 1)->scalar = lbl_80651460;
    state_at(base, 0)->scalar = lbl_80651460;
    return first;
}
