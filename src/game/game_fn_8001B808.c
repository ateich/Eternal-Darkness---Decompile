typedef short s16;
typedef int s32;

typedef struct InitState {
    float first;
    float second;
    float third;
    s32 value_c;
    s32 value_10;
    s32 value_14;
    s32 value_18;
    s32 value_1c;
    s32 value_20;
    s32 value_24;
    s32 value_28;
    s32 value_2c;
} InitState;

typedef struct GlobalState {
    char pad[8];
    void* object;
} GlobalState;

extern InitState lbl_803021A8;
extern GlobalState lbl_80606328;

s32 fn_8001B808(void)
{
    lbl_803021A8.first = 250.0f;
    lbl_803021A8.second = 0.5f;
    lbl_803021A8.third = 0.5f;
    lbl_803021A8.value_c = 200;
    lbl_803021A8.value_10 = 250;
    lbl_803021A8.value_14 = 1;
    lbl_803021A8.value_18 = 2;
    lbl_803021A8.value_1c = 2;
    lbl_803021A8.value_20 = 0;
    lbl_803021A8.value_24 = *(s16*)((char*)lbl_80606328.object + 0xAC0);
    lbl_803021A8.value_28 = 2;
    lbl_803021A8.value_2c = 1;
    return 0;
}
