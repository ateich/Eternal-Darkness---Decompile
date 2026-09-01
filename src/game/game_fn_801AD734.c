typedef struct EffectNode {
    unsigned char pad[0xC];
    int value;
} EffectNode;

extern EffectNode* fn_801ACE30(int);

EffectNode* fn_801AD734(int value)
{
    EffectNode* node = fn_801ACE30(8);
    if (node != 0) {
        node->value = value;
    }
    return node;
}
