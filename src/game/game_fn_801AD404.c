typedef unsigned char u8;
typedef struct EffectNode { struct EffectNode* next; int state, object_id, timer; u8 data[0xC]; u8 x, y; } EffectNode;
extern EffectNode* fn_801ACE30(int);
void fn_801AD404(u8 x, u8 y, int timer)
{
    EffectNode* node = fn_801ACE30(5);
    if (timer <= 0) timer = 1;
    if (node != 0) { node->timer = timer; node->x = x; node->y = y; }
}
