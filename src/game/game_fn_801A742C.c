typedef unsigned char u8;

typedef struct Data801A742C {
    u8 pad0[0xAC];
    unsigned short fieldAC;
} Data801A742C;

void fn_801A742C(Data801A742C* data, unsigned short value)
{
    data->fieldAC = value;
}
