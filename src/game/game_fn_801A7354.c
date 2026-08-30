typedef unsigned char u8;

typedef struct Data801A7354 {
    float values[6];
    u8 pad18[0x4C];
    int field64;
    u8 pad68[0xC];
    float field74;
    int field78;
    int field7C;
    int field80;
    int field84;
    u8 pad88[4];
    int field8C;
    int field90;
    int field94;
    int field98;
    int field9C;
    u8 padA0[4];
    int fieldA4;
    int fieldA8;
    short fieldAC;
    short fieldAE;
    short fieldB0;
    short fieldB2;
    short fieldB4;
    short fieldB6;
    u8 padB8[6];
    short fieldBE;
    u8 padC0[2];
    short fieldC2;
    short fieldC4;
    short fieldC6;
    u8 fieldC8;
    u8 fieldC9;
    u8 fieldCA;
    u8 padCB[9];
} Data801A7354;

extern void* memset(void*, int, unsigned int);
extern int lbl_8064D5A8;
extern int lbl_8064D18C;
extern const float lbl_80650DE0;
extern const float lbl_80650DE4;

void fn_801A7354(Data801A7354* data)
{
    int i;

    memset(data, 0, 0xD4);
    data->field78 = 0;
    data->field7C = 0;
    data->field80 = 0;
    data->field84 = -1;
    data->field8C = 0;
    data->field90 = 0;
    data->field94 = -1;
    data->field98 = 0;
    data->field9C = 0;
    for (i = 0; i < 6; i++) {
        data->values[i] = lbl_80650DE0;
    }
    data->fieldA4 = -1;
    data->fieldAC = 1;
    data->fieldAE = 0;
    data->fieldB0 = 0;
    data->fieldB2 = 0;
    data->fieldB4 = 0;
    data->fieldB6 = 0;
    data->fieldBE = 200;
    data->fieldA8 = 0;
    data->fieldC8 = 0;
    data->fieldC9 = 0;
    data->fieldCA = 0;
    data->fieldC2 = 320;
    data->fieldC4 = 0;
    data->field64 = lbl_8064D5A8;
    data->field74 = lbl_80650DE4;
    data->fieldC6 = lbl_8064D18C;
}
