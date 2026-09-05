typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;
typedef unsigned long long u64;

typedef struct ExpressionOp {
    u8 selector;
    u8 flags;
    u8 pad[2];
    s32 scale;
} ExpressionOp;

typedef struct Expression {
    ExpressionOp ops[4];
    u16 result;
    u8 count;
} Expression;

extern s32 fn_801BEA3C(void*, int, u8);
extern u16 fn_801CAFAC(int, u8, u8);
extern u64 fn_800F6218(u32, u32, u32);
extern u32 lbl_8064ED40;
extern u32 lbl_8064ED44;

static s32 clamp_signed(s32 value)
{
    if (value < -0x2000)
        value = -0x2000;
    else if (value > 0x1FFF)
        value = 0x1FFF;
    return value;
}

u16 fn_801CB4F8(u8* state, Expression* expression, u8 channel, u8 layer)
{
    s32 accumulator = 0;
    u32 signed_mode;
    u32 i;

    for (i = 0; i < expression->count; i++) {
        ExpressionOp* op = &expression->ops[i];
        s32 value;

        if (op->flags & 0x10) {
            value = state != 0 ? (s16)fn_801BEA3C(state, 0, op->selector) : 0;
        } else if (op->selector == 0x80 || op->selector == 1 ||
                   op->selector == 0xA || (u8)(op->selector - 0xA0) <= 1 ||
                   op->selector == 0x83) {
            if (op->selector == 0xA0 || op->selector == 0xA1) {
                if (state != 0) {
                    value = *(s16*)(state + op->selector * 12 - 0x5BC);
                    state[op->selector + 0x134] = 1;
                    value <<= 1;
                } else {
                    value = 0;
                }
            } else {
                value = (u16)fn_801CAFAC(op->selector, channel, layer) - 0x2000;
            }
            value = (value * (op->scale >> 1)) >> 15;
            value = clamp_signed(value);

            switch (op->flags & 0xF) {
            case 0:
                accumulator = value + 0x2000;
                signed_mode = 1;
                break;
            case 1:
                if (signed_mode) {
                    accumulator = clamp_signed(accumulator + value - 0x2000) + 0x2000;
                } else {
                    accumulator += value;
                    if (accumulator > 0x3FFF)
                        accumulator = 0x3FFF;
                    else if (accumulator < 0)
                        accumulator = 0;
                }
                break;
            case 2:
                if (signed_mode)
                    value = ((accumulator - 0x2000) * value) >> 13;
                else {
                    value = (value * accumulator) >> 13;
                    signed_mode = 1;
                }
                accumulator = clamp_signed(value) + 0x2000;
                break;
            case 3:
                if (signed_mode)
                    accumulator = clamp_signed(accumulator - 0x2000 - value) + 0x2000;
                else {
                    accumulator -= value;
                    if (accumulator > 0x3FFF)
                        accumulator = 0x3FFF;
                    else if (accumulator < 0)
                        accumulator = 0;
                }
                break;
            }
        } else {
            u32 unsigned_value;

            switch (op->selector) {
            case 0xA2:
                unsigned_value = state != 0 ? state[0x12F] << 7 : 0;
                break;
            case 0xA3:
                unsigned_value = state != 0 ? *(u32*)(state + 0x158) >> 9 : 0;
                break;
            case 0xA4:
                if (state != 0) {
                    u64 delta = ((u64)lbl_8064ED40 << 32 | lbl_8064ED44) -
                                *(u64*)(state + 0x90);
                    unsigned_value = (u32)fn_800F6218((u32)(delta >> 32),
                                                       (u32)delta, 8);
                    if ((s32)unsigned_value > 0x3FFF)
                        unsigned_value = 0x3FFF;
                    state[0xA8] = 1;
                } else {
                    unsigned_value = 0;
                }
                break;
            default:
                unsigned_value = fn_801CAFAC(op->selector, channel, layer);
                break;
            }

            value = (unsigned_value * (op->scale >> 1)) >> 15;
            if (value > 0x3FFF)
                value = 0x3FFF;

            switch (op->flags & 0xF) {
            case 0:
                accumulator = value;
                signed_mode = 0;
                break;
            case 1:
                if (signed_mode)
                    accumulator = clamp_signed(accumulator + value - 0x2000) + 0x2000;
                else {
                    accumulator += value;
                    if ((u32)accumulator > 0x3FFF)
                        accumulator = 0x3FFF;
                }
                break;
            case 2:
                if (signed_mode) {
                    value = (value * (accumulator - 0x2000)) >> 14;
                    accumulator = clamp_signed(value) + 0x2000;
                } else {
                    u32 product = accumulator * value;
                    product >>= 14;
                    accumulator = product > 0x3FFF ? 0x3FFF : product;
                }
                break;
            case 3:
                if (signed_mode)
                    accumulator = clamp_signed(accumulator - 0x2000 - value) + 0x2000;
                else {
                    accumulator -= value;
                    if (accumulator > 0x3FFF)
                        accumulator = 0x3FFF;
                    else if (accumulator < 0)
                        accumulator = 0;
                }
                break;
            }
        }
    }
    expression->result = accumulator;
    return (u16)accumulator;
}
