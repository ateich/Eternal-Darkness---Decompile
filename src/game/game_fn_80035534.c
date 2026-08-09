typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

typedef struct SetupInfo {
    u8 pad_00[0x44];
    s16 value44;
    s16 value46;
    s16 value48;
    s16 value4A;
    u8 values4C[0x1E];
    u8 values6A[0x1E];
    u8 pad_88[0x41];
    u8 valueC9;
} SetupInfo;

typedef struct ChildObject {
    u32 value00;
    u32 value04;
    u32 value08;
    u32 value0C;
    u8 pad_10[0x10];
    u32 value20;
    u8 pad_24[0x88];
    u32 valueAC;
    u32 valueB0;
    u8 pad_B4[0x2C];
    u16 valueE0;
    u16 valueE2;
    u16 valueE4;
    u16 valueE6;
    u8 pad_E8[2];
    u8 valuesEA[0x1E];
    u8 values108[0x1E];
    u8 values126[0x1E];
    u8 pad_144[0x20];
    u8 value164;
    u8 pad_165;
    u8 value166;
    u8 pad_167[5];
} ChildObject;

extern void* memset(void*, int, u32);
extern void* memcpy(void*, const void*, u32);

void fn_80035534(register ChildObject* child, register SetupInfo* setup)
{
    memset(child, 0, sizeof(ChildObject));
    child->value20 = 0;
    child->value04 = 0;
    child->value08 = 0;
    child->value0C = 0;
    child->valueE0 = setup->value44;
    child->valueE6 = setup->value4A;
    child->valueE2 = setup->value46;
    child->valueE4 = setup->value48;
    child->value164 = setup->valueC9;
    child->value166 = 0;
    child->valueB0 = -1;
    child->valueAC = -1;
    memcpy(child->valuesEA, setup->values4C, 0x1E);
    memcpy(child->values108, setup->values4C, 0x1E);
    memcpy(child->values126, setup->values6A, 0x1E);
}
