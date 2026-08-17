typedef struct State {
    unsigned char pad[0x248];
    int mode;
    unsigned char pad24C[8];
    unsigned int flags;
} State;

extern float lbl_80650114;
extern float lbl_80650118;
extern float lbl_80650124;
extern float lbl_80650128;
extern float lbl_8065012C;
extern int fn_8011EB04(State* state);

float fn_80123708(State* state, int alternate)
{
    float result = lbl_80650118;
    int kind = fn_8011EB04(state);
    int mode = state->mode;

    if ((state->flags & 0x8000) != 0) {
        if (alternate != 0) {
            return lbl_80650124;
        }
        return lbl_80650114;
    }

    if (mode <= 2) {
        switch (kind) {
        case 2:
        case 15:
        case 16:
            result = lbl_80650128;
            break;
        case 4:
        case 29:
        case 30:
            result = lbl_80650128;
            break;
        case 82:
        case 83:
        case 84:
            result = lbl_8065012C;
            break;
        }
    }

    return result;
}
