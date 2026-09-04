typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Command Command;
typedef struct CommandList CommandList;
typedef struct VoiceState VoiceState;

struct Command {
    u8 command;
    u8 pad01;
    u16 value;
};

struct CommandList {
    u8 count;
    u8 pad01[3];
    Command* commands;
};

struct VoiceState {
    char pad00[0xC];
    CommandList* command_list;
    u32 flags;
    char pad14[0x28];
    u32 handle;
    char pad40[0xC];
    float gain;
};

extern float lbl_80650FD0;
extern float lbl_80650FD4;
extern float lbl_80650FE4;
extern float lbl_80650FE8;

extern void fn_801B7E84(u32, u32, u32);
extern void fn_801B7F6C(u32, u32, u32);
extern u32 fn_800F5C54(float);

void fn_801C8CC0(VoiceState* state, float gain, float pan, float unused,
                 float surround, float pitch)
{
    u32 handle = state->handle;
    int value;
    u32 pitch_value;

    if ((state->flags & 0x00100000) != 0) {
        value = (int)(lbl_80650FD0 * (state->gain * gain));
        if ((u8)value > 0x7F) {
            value = 0x7F;
        }
        fn_801B7E84(handle, 7, value);
    } else {
        value = (int)(lbl_80650FD0 * gain);
        if ((u8)value > 0x7F) {
            value = 0x7F;
        }
        fn_801B7E84(handle, 7, value);
    }

    value = (int)(lbl_80650FE4 * (lbl_80650FD4 + pan));
    if ((u8)value > 0x7F) {
        value = 0x7F;
    }
    fn_801B7E84(handle, 10, value);

    value = (int)(lbl_80650FE4 * (lbl_80650FD4 - surround));
    if ((u8)value > 0x7F) {
        value = 0x7F;
    }
    fn_801B7E84(handle, 0x83, value);

    pitch = lbl_80650FE8 * pitch;
    pitch_value = fn_800F5C54(pitch);
    if (pitch_value > 0x3FFF) {
        pitch_value = 0x3FFF;
    } else {
        pitch_value = (u16)fn_800F5C54(pitch);
    }
    fn_801B7F6C(handle, 0x84, pitch_value);

    if (state->command_list != 0) {
        u32 i = 0;
        Command* command = state->command_list->commands;
        while ((u8)i < state->command_list->count) {
            if (command->command < 0x40 || command->command == 0x80 ||
                command->command == 0x84) {
                fn_801B7F6C(handle, command->command, command->value);
            } else {
                fn_801B7E84(handle, command->command, (u8)command->value);
            }
            command++;
            i++;
        }
    }
}
