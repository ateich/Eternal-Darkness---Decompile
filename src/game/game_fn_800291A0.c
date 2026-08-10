typedef int s32;
typedef unsigned int u32;

typedef struct Node {
    void* object;
    char unknown_04[0x18];
    u32 flags;
} Node;

typedef struct TypeInfo {
    char unknown_00[0x11C];
    void* value_11C;
} TypeInfo;

extern void* fn_80201BC8();
extern int fn_80201B4C(void*);
extern void fn_80202054(void*, s32);
extern void* fn_8011F950(void);
extern void* fn_8011EB04(void*);
extern Node* fn_8002A444(void*, void*);
extern void fn_8012B954(void*);
extern void fn_8011F938(void*, void*);
extern void* fn_8011FB6C(void*);
extern TypeInfo* fn_8015C28C(s32);
extern void fn_8011FBC4(void*, void*);
extern void fn_80139D88(void*, Node*);
extern void fn_8011FC38(void*, s32, s32);
extern void fn_8011F7E0(void*, s32);
extern s32 fn_8011FCEC(void*);
extern void* fn_801261F4(void*);
extern s32 fn_8015E4E8(void*);
extern void fn_8011EBFC(void*);
extern s32 fn_8012A100(void*, s32);
extern void* fn_8011EAB4(void*, s32);
extern void fn_801294DC(void*, s32, s32, s32);

void fn_800291A0(void* source)
{
    void* value;
    void* object;
    void* child;
    Node* node;

    object = fn_80201BC8();

    if (fn_8011F950() == 0) {
        value = (void*)fn_80201B4C(source);
        node = fn_8002A444(fn_8011EB04(object), value);

        fn_80202054(source, 1);
        if (node != 0) {
            child = node->object;

            if ((node->flags & 1) == 0) {
                node->flags |= 1;
                fn_8012B954(child);
            }

            fn_8011F938(object, child);
            if (fn_8011FB6C(object) == 0) {
                fn_8011FBC4(object, fn_8015C28C(2)->value_11C);
            }
            fn_80139D88(object, node);
            fn_8011FC38(object, 0, 1);
            fn_8011F7E0(object, 0);

            if (fn_8011FCEC(object) != -1) {
                if (fn_8015E4E8(fn_801261F4(object)) == 0) {
                    fn_8011EBFC(object);
                }
            } else if (fn_8012A100(object, 15) != 0) {
                if (fn_8015E4E8(fn_8011EAB4(object, 15)) == 0) {
                    fn_801294DC(object, 15, 0x21, 1);
                }
            } else if (fn_8012A100(object, 27) != 0 &&
                       fn_8015E4E8(fn_8011EAB4(object, 27)) == 0) {
                fn_801294DC(object, 27, 0x21, 1);
            }
        }
    }
}
