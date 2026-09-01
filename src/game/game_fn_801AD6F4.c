typedef struct EffectNode EffectNode;

extern EffectNode* fn_801ACE30(int);

EffectNode* fn_801AD6F4(int alternate)
{
    if (alternate != 0) {
        return fn_801ACE30(3);
    }
    return fn_801ACE30(4);
}
