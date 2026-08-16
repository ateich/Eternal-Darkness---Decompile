typedef struct DecimalRecord {
    unsigned char unused[2];
    short exponent;
    unsigned char length;
    char digits[1];
} DecimalRecord;

void fn_800FAFD4(DecimalRecord* value, int precision)
{
    int carry;
    signed char digit;
    char* cursor;
    char* tail;
    DecimalRecord* rounded;

    if (precision < 0) {
zero:
        value->exponent = 0;
        value->length = 1;
        value->digits[0] = '0';
        return;
    }

    if (precision >= value->length) {
        return;
    }

    rounded = (DecimalRecord*)((char*)value + precision);
    digit = rounded->digits[0] - '0';
    cursor = rounded->digits;
    if (digit == 5) {
        tail = (char*)value + value->length;
        tail += 5;
        while (--tail > cursor && *tail == '0') {
        }
        if (tail == cursor) {
            carry = cursor[-1] & 1;
        } else {
            carry = 1;
        }
    } else {
        carry = digit > 5;
    }

    do {
        digit = *--cursor + carry - '0';
        carry = digit > 9;
        if (!carry && digit != 0) {
            *cursor = digit + '0';
            break;
        }
        --precision;
    } while (precision != 0);

    if (carry) {
        ++value->exponent;
        value->length = 1;
        value->digits[0] = '1';
        return;
    }
    if (precision == 0) {
        goto zero;
    }
    value->length = precision;
}
