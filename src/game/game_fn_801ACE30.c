typedef unsigned char u8;

typedef struct EffectNode {
    struct EffectNode* next;
    int state;
    u8 data[0x18];
} EffectNode;

extern EffectNode lbl_8060B22C[16];
extern EffectNode* lbl_8064D304;
extern void fn_801ACDC4(void);
extern void fn_801ACD8C(void);

EffectNode* fn_801ACE30(int state)
{
    EffectNode* result = 0;
    EffectNode* node = lbl_8060B22C;
    int i;

    for (i = 0; i < 16; i++, node++) {
        if (node->state == 0) {
            result = node;
            break;
        }
    }

    if (result != 0) {
        result->state = state;
        node = lbl_8064D304;
        if (node == 0) {
            lbl_8064D304 = result;
        } else {
            while (node->next != 0) {
                node = node->next;
            }
            node->next = result;
        }
    } else {
        fn_801ACDC4();
        fn_801ACD8C();
    }

    return result;
}
