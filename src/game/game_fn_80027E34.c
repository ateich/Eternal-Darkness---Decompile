typedef int s32;
typedef unsigned int u32;

typedef struct CallbackData {
    s32 value0;
    char pad4[4];
    void* object;
    char padC[0xC];
    s32 value18;
} CallbackData;

typedef struct EventDescriptor {
    char pad0[0xC];
    CallbackData* data;
    char pad10[0x1C];
    s32 value2C;
} EventDescriptor;

extern CallbackData lbl_803039FC;
extern EventDescriptor lbl_8023E088;
extern u32 lbl_8064C6F8;
extern s32 lbl_8064C700;
extern s32 lbl_8064C704;

extern void* fn_80201814(void*);
extern void* fn_80155DB4(void*);
extern void fn_801568B8(void*, void (*)(void));
extern void fn_80205C98(void);
extern u32 fn_80144628(s32, EventDescriptor*, s32);
extern void fn_80144608(u32);
extern void fn_801446D4(u32, void (*)(CallbackData*, s32));
extern void fn_801446E4(u32, CallbackData*);
extern void fn_801446AC(u32, s32);
extern void fn_80045C68(s32);
extern void fn_80027D40(CallbackData*, s32);

void fn_80027E34(s32 value0, s32 value18, void* object)
{
    void* result = fn_80155DB4(fn_80201814(object));

    lbl_803039FC.object = object;
    lbl_803039FC.value0 = value0;
    lbl_803039FC.value18 = value18;
    lbl_8023E088.data = &lbl_803039FC;
    lbl_8023E088.value2C = value0;
    fn_801568B8(result, fn_80205C98);
    lbl_8064C6F8 = fn_80144628(3, &lbl_8023E088, 0);
    fn_80144608(lbl_8064C6F8);
    fn_801446D4(lbl_8064C6F8, fn_80027D40);
    fn_801446E4(lbl_8064C6F8, &lbl_803039FC);
    fn_801446AC(lbl_8064C6F8, 3);
    fn_80045C68(1);
    lbl_8064C704 = value18;
    lbl_8064C700 = -1;
}
