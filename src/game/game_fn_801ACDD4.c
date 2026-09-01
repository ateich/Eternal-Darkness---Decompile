typedef unsigned long u32;

typedef struct EffectNode {
    struct EffectNode* next;
    int state;
} EffectNode;

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);
extern EffectNode* lbl_8064D304;

int fn_801ACDD4(void)
{
    int found = 0;
    u32 level = OSDisableInterrupts();
    EffectNode* node = lbl_8064D304;

    while (node != 0) {
        if (node->state == 2) {
            found = 1;
            break;
        }
        node = node->next;
    }

    OSRestoreInterrupts(level);
    return found;
}
