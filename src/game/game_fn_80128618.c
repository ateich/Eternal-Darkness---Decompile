typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Owner {
    u8 pad0[0x44];
    u8 state[0x38];
    void* values[14];
    u8 padB4[0x3C];
    void* fallback_f0;
    u8 padF4[4];
    void* fallback_f8;
} Owner;

extern void fn_8012B290(Owner*, void*);
extern u32 fn_8011FE54(Owner*);
extern void fn_80129CE8(Owner*, void*, u32, int, int);

void fn_80128618(Owner* owner, void* value)
{
    int found = 0;
    int i;

    if (value != 0) {
        for (i = 0; i < 14; i++) {
            if (owner->values[i] == value) {
                found = 1;
                break;
            }
        }
        if (!found && owner->fallback_f8 == value) {
            found = 1;
        }
        if (!found && owner->fallback_f0 == value) {
            found = 1;
        }
        if (found) {
            fn_8012B290(owner, owner->state);
            fn_80129CE8(owner, owner->state, fn_8011FE54(owner), 0, 1);
        }
    }
}
