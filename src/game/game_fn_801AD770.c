typedef unsigned char u8;
typedef unsigned short u16;

typedef struct EffectNode {
    unsigned char pad[0x1A];
    u16 value;
    u8 first;
    u8 second;
} EffectNode;

extern EffectNode* fn_801ACE30(int);

EffectNode* fn_801AD770(u16 value, u8 setting)
{
    EffectNode* node = fn_801ACE30(9);
    if (node != 0) {
        node->value = value;
        node->first = setting;
        node->second = setting;
    }
    return node;
}
