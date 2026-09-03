typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

#pragma pack(4)
typedef struct StreamState {
    u8 pad_00[0x90];
    u64 base_time;
    u64 current_time;
    u64 previous_time;
    u8 pad_A8[0x4C];
    u32 kind;
    u8 pad_F8[0x1C];
    u64 flags;
} StreamState;
#pragma pack()

typedef union CommandWord {
    u32 raw;
    struct {
        unsigned int pad0 : 7;
        unsigned int bit24 : 1;
        unsigned int pad1 : 7;
        unsigned int bit16 : 1;
        unsigned int pad2 : 7;
        unsigned int bit8 : 1;
        unsigned int pad3 : 8;
    } bits;
} CommandWord;

typedef struct StreamCommand {
    CommandWord flags;
    CommandWord value;
} StreamCommand;

extern u64 lbl_8064D448;
extern unsigned int fn_801CC6DC(unsigned int);
extern unsigned int fn_801CC2E4(void);
extern void fn_801CC408(unsigned int*);
extern void fn_801CC418(unsigned int*, StreamState*);
extern void fn_801C0844(StreamState*);
extern void fn_801C0ACC(StreamState*, int);

int fn_801BD398(StreamState* state, StreamCommand* command)
{
    unsigned int amount;
    unsigned int relative;

    if ((amount = command->value.raw >> 16) != 0) {

    if ((command->flags.raw >> 8) & 1) {
        if (state->flags & 8) {
            if (!(state->flags & 0x10000000000ULL)) {
                return 0;
            }
            state->flags |= 0x40000000000ULL;
        }
        state->flags |= 4;
    } else {
        state->flags &= ~4ULL;
    }

    if ((command->flags.raw >> 24) & 1) {
        if (!(state->flags & 0x20) && !fn_801CC6DC(state->kind & 0xFF)) {
            return 0;
        }
        state->flags |= 0x40000;
    } else {
        state->flags &= ~0x40000ULL;
    }

    if ((command->flags.raw >> 16) & 1) {
        amount = (unsigned short)fn_801CC2E4() % amount;
    }

    if (amount != 0xFFFF) {
        if (relative = (((command->value.raw >> 8) & 1) != 0)) {
            fn_801CC408(&amount);
        } else {
            fn_801CC418(&amount, state);
        }

        if (relative) {
            if (command->value.raw & 1) {
                state->current_time = state->base_time + amount;
            } else {
                state->current_time = lbl_8064D448 + amount;
            }
        } else if (command->value.raw & 1) {
            state->current_time = amount;
        } else {
            state->current_time = state->previous_time + amount;
        }

        if (state->current_time <= lbl_8064D448) {
            state->previous_time = state->current_time;
            state->current_time = 0;
        }
    } else {
        state->current_time = ~0ULL;
    }

    if (state->current_time != 0) {
        if (state->current_time != ~0ULL) {
            fn_801C0844(state);
        }
        fn_801C0ACC(state, 1);
        return 1;
    }
    }
    return 0;
}
