typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct SoundState {
    u8 pad00[8];
    int sounds[2];
    int sounds_b[2];
    int sounds_c[2];
    int sounds_d[2];
    void* object;
    u32 flags;
    u8 pad30[4];
    s8 index_a;
    s8 index_b;
    s8 index_c;
    s8 index_d;
} SoundState;

extern void* fn_80200C38(void** node);
extern int fn_801B05E8(int, u8, u8, u8, Vec3*, u8, int, int);
extern int lbl_8064C4F0;

int fn_80096348(void* object, void* resource, void* unused,
                SoundState* state, void** event)
{
    int id = (int)fn_80200C38(event);
    int next;

    state->flags &= ~2U;
    switch (id) {
    case -1:
        lbl_8064C4F0 = fn_801B05E8(state->sounds[state->index_a],
                                  75, 4, 1, 0, 5, 0, 0);
        if (!(state->flags & 0x10)) {
            state->sounds[state->index_a] = 0;
        }
        next = state->index_a + 1;
        state->index_a = next >= 2 ? 0 : next;
        next = state->index_a;
        state->index_a = state->sounds[next] ? next : 0;
        break;
    case -4:
        lbl_8064C4F0 = fn_801B05E8(state->sounds_d[state->index_d],
                                  75, 1, 1, 0, 5, 0, 0);
        if (!(state->flags & 0x10)) {
            state->sounds_d[state->index_d] = 0;
        }
        next = state->index_d + 1;
        state->index_d = next >= 2 ? 0 : next;
        next = state->index_d;
        state->index_d = state->sounds_d[next] ? next : 0;
        break;
    case -2:
        lbl_8064C4F0 = fn_801B05E8(state->sounds[state->index_b],
                                  75, 1, 1, 0, 5, 0, 0);
        if (!(state->flags & 0x10)) {
            state->sounds_b[state->index_b] = 0;
        }
        next = state->index_b + 1;
        state->index_b = next >= 2 ? 0 : next;
        next = state->index_b;
        state->index_b = state->sounds_b[next] ? next : 0;
        break;
    case -3:
        lbl_8064C4F0 = fn_801B05E8(state->sounds[state->index_c],
                                  75, 1, 1, 0, 5, 0, 0);
        if (!(state->flags & 0x10)) {
            state->sounds_c[state->index_c] = 0;
        }
        next = state->index_c + 1;
        state->index_c = next >= 2 ? 0 : next;
        next = state->index_c;
        state->index_c = state->sounds_c[next] ? next : 0;
        break;
    default:
        lbl_8064C4F0 = fn_801B05E8(id, 75, 1, 1, 0, 5, 0, 0);
        break;
    }
    return 1;
}
