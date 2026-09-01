typedef unsigned char u8;

typedef struct EffectNode {
    struct EffectNode* next;
    u8 data[0x1C];
} EffectNode;

extern EffectNode* lbl_8064D304;
extern void* memset(void*, int, unsigned long);

void fn_801ACF80(EffectNode* node)
{
    lbl_8064D304 = node->next;
    memset(node, 0, 0x20);
}
