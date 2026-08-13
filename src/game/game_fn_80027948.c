typedef int s32;
typedef unsigned int u32;

typedef struct EventState {
    void* object;
    s32 final_arg;
    s32 target;
    s32 unused_c;
    s32 other;
    s32 flags;
    s32 message;
} EventState;

typedef struct CallbackState {
    char pad[0xC];
    EventState* event;
    char pad10[0x1C];
    void* object;
} CallbackState;

extern EventState lbl_803039E0;
extern CallbackState lbl_8023E030;
extern char lbl_8023E070[];
extern u32 lbl_8064C6F8;
extern s32 lbl_8064C700;
extern float lbl_8064DFE0;
extern void *fn_80201814();
extern void* fn_80201C2C(void*);
extern void *fn_80201BC8();
extern void* fn_80155DB4(void*);
extern void* fn_80201C24();
extern void fn_80204E0C(void*, void*);
extern s32 fn_801579F4(void*);
extern void* fn_80201B3C(void);
extern int fn_80201EB8();
extern void fn_8011FB54(void*, void*);
extern void fn_8011FA8C(void*, int, int);
extern void fn_8011FABC(void*, s32, s32);
extern void fn_80205680(void*, void*, s32);
extern void fn_8020104C(int, void *, void *, int, float);
#define fn_8020104C(a, b, c, d, e) fn_8020104C((a), (void *)(b), (void *)(c), (int)(d), (e))
extern void fn_80205C98(void);
extern void fn_80205CE4(void);
extern void fn_801568B8(void*, void*);
extern void fn_801568C0(void*, void (*)(void));
extern u32 fn_80144628(s32, CallbackState*, s32);
extern void fn_80144608(void);
extern void fn_80027854(void*, s32);
extern void fn_801446D4(u32, void (*)(void*, s32));
extern void fn_801446E4(u32, EventState*);
extern void fn_801446AC(u32, s32);
extern void fn_80045C68(s32);
extern void fn_801E7F3C(char*, ...);

void fn_80027948(void* object, s32 message, void* target, void* target_object,
                 s32 other, s32 flags, s32 final_arg)
{
    void* target_info;
    void* target_node;
    void* object_info;
    void* target_model;
    void* target_data;
    void* next_info;
    void* next_node;
    s32 count;

    lbl_8023E030.object = object;
    lbl_803039E0.object = object;
    lbl_803039E0.target = (s32)target_object;
    lbl_803039E0.final_arg = final_arg;
    lbl_803039E0.other = other;
    lbl_803039E0.flags = flags;

    target_info = fn_80201814(target);
    target_node = fn_80201C2C(target_info);
    object_info = fn_80201814(target_object);
    target_data = fn_80201BC8(object_info);
    target_model = fn_80155DB4(object_info);
    next_info = fn_80201C24(object_info);
    fn_80204E0C(object_info, target_node);
    count = fn_801579F4(next_info);
    next_node = fn_80201814((void*)count);
    if (count > 0) {
        fn_80204E0C(next_node, target_node);
    }

    fn_8011FB54(target_data, (void*)fn_80201EB8(fn_80201B3C()));
    fn_8011FA8C(target_data, 0x10100, 0);
    fn_8011FABC(target_data, 0, 0x40);
    if (count > 0) {
        void* node = fn_80201BC8(next_node);
        fn_8011FA8C(node, 0x10100, 0);
        fn_8011FABC(node, 0, 0x40);
    }

    fn_80205680(object_info, target, 0x1E);
    fn_8020104C(0x47, target, target_object, 0, lbl_8064DFE0);
    fn_801568B8(target_model, fn_80205C98);
    if (count > 0) {
        fn_801568B8(fn_80155DB4(next_node), fn_80205C98);
    }
    if (flags & 2) {
        fn_801568C0(target_model, fn_80205CE4);
    }

    lbl_8023E030.event = &lbl_803039E0;
    lbl_8064C6F8 = fn_80144628(2, &lbl_8023E030, 0);
    fn_80144608();
    fn_801446D4(lbl_8064C6F8, fn_80027854);
    fn_801446E4(lbl_8064C6F8, &lbl_803039E0);
    fn_801446AC(lbl_8064C6F8, 3);
    fn_80045C68(1);
    fn_801E7F3C(lbl_8023E070, message);
    lbl_8064C700 = -1;
    lbl_803039E0.message = message;
}
