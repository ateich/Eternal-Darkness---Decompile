typedef unsigned char u8;
typedef signed char s8;

u8 fn_8018E26C(u8* state, u8* value)
{
    if (*value == state[1]) {
        switch (state[0]) {
        case 1:
            if (state[7] != 0) {
                state[0] = 7;
            } else {
                state[0] = 0;
            }
            break;
        case 2:
            if (state[3] == state[2]) {
                state[0] = 0;
            } else {
                int adjusted = state[2] - 30;
                state[2] = adjusted > 0 ? adjusted : 0;
                adjusted = state[3] - 30;
                state[3] = adjusted > 0 ? adjusted : 0;
                if ((s8)state[5] > 0) {
                    state[1] = state[3];
                } else {
                    state[1] = state[2];
                }
                state[5] = -state[5];
            }
            break;
        case 3: {
            u8 amount;
            int adjusted;
            if (state[3] == state[2]) {
                state[0] = 0;
            } else if (state[2] == 90) {
                state[0] = 1;
                ((s8*)state)[5] = -1;
                state[1] = 0;
            } else {
                amount = 30;
                if (state[2] <= 150) {
                    amount = 10;
                }
                adjusted = state[2] - amount;
                state[2] = adjusted > 0 ? adjusted : 0;
                adjusted = state[3] - amount;
                state[3] = adjusted > 0 ? adjusted : 0;
                if ((s8)state[5] > 0) {
                    state[1] = state[3];
                } else {
                    state[1] = state[2];
                }
                state[5] = -state[5];
                if (state[2] == 120) {
                    state[5] = (s8)state[5] >> 1;
                }
            }
            break;
        }
        case 4:
            if ((s8)state[5] > 0) {
                state[1] = state[3];
            } else {
                state[1] = state[2];
            }
            state[5] = -state[5];
            break;
        case 5:
            state[0] = 1;
            state[1] = state[4];
            state[5] = state[6];
            if ((s8)state[5] > 0) {
                if (state[1] <= *value) {
                    state[0] = 0;
                }
            } else if (state[1] >= *value) {
                state[0] = 0;
            }
            break;
        }
    }

    if (state[0] != 0) {
        if (state[7] != 0) {
            state[7]--;
            if (state[7] == 0) {
                *value = state[4];
                state[0] = 1;
            }
        } else {
            *value += state[5];
        }
    }
    return state[0];
}
