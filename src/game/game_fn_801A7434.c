typedef unsigned char u8;

typedef struct Data801A7434 {
    u8 pad0[0xAC];
    unsigned short fieldAC;
} Data801A7434;

unsigned short fn_801A7434(Data801A7434* data)
{
    return data->fieldAC;
}
