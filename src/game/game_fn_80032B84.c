typedef unsigned char u8;
typedef int s32;

typedef struct Record {
    u8 pad[8];
    s32 field_8;
    s32 field_C;
    float field_10;
    u8 pad_14[0x10];
} Record;

typedef struct Records {
    u8 pad[0x28];
    u8 values[3];
    u8 pad_2B;
    Record records[1];
} Records;

extern u8* fn_80201B8C(void* object);
extern const double lbl_8064E038;

void fn_80032B84(void* object, s32 index, s32 mode, float value)
{
    u8* state = fn_80201B8C(object);
    Records* records = *(Records**)(state + 0x7C);

    switch (mode) {
    case 1:
        records->values[0] = (s32)value;
        break;
    case 2:
        records->values[1] = (s32)value;
        break;
    case 3:
        records->values[2] = (s32)value;
        break;
    case 4: {
        records->records[index].field_8 = (s32)value;
        break;
    }
    case 5: {
        records->records[index].field_C = (s32)value;
        break;
    }
    case 6: {
        s32 integer = (s32)value;
        records->records[index].field_10 = integer;
        break;
    }
    }
}
