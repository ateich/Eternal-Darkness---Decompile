typedef signed short s16;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct StreamState StreamState;

typedef struct Operation {
    u32 word_0;
    u32 word_4;
} Operation;

extern u32 fn_801BE9D8(StreamState*, void*, u32);
extern void fn_801BEAA4(StreamState*, void*, u32, u32);

void fn_801BEB08(StreamState* state, Operation* operation, u8 opcode)
{
    s16 left;
    s16 right;
    StreamState* stream = state;
    Operation* op = operation;
    u8 code = opcode;
    int result;
    int clamped;
    void* destination_indirect;
    u32 destination_index;
    u32 operand_word;

    operand_word = op->word_4;
    left = fn_801BE9D8(stream, (void*)(op->word_0 >> 24), operand_word & 0xFF);
    if (code == 4) {
        right = op->word_4 >> 8;
    } else {
        right = fn_801BE9D8(stream, (void*)((op->word_4 >> 8) & 0xFF),
                            (op->word_4 >> 16) & 0xFF);
    }

    switch (code) {
    case 0:
    case 4:
        result = left + right;
        break;
    case 1:
        result = left - right;
        break;
    case 2:
        result = left * right;
        break;
    case 3:
        result = right != 0 ? left / right : 0;
        break;
    }

    destination_indirect = (void*)((op->word_0 >> 8) & 0xFF);
    destination_index = (op->word_0 >> 16) & 0xFF;
    if (result < -32768) {
        clamped = -32768;
    } else if (result > 32767) {
        clamped = 32767;
    } else {
        clamped = result;
    }
    fn_801BEAA4(stream, destination_indirect, destination_index, (s16)clamped);
}
