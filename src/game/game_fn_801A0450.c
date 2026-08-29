typedef unsigned char u8;

extern u8 lbl_80607440[];
extern float lbl_80650CA8;
extern float lbl_80650CAC;
extern float lbl_80650CB0;
extern float lbl_80650CB4;
extern float lbl_80650CB8;
extern float lbl_80650CBC;
extern float lbl_80650CC0;
extern float lbl_80650CC4;
extern float lbl_80650CC8;
extern float lbl_80650CCC;
extern float lbl_80650CD0;
extern float lbl_80650CD4;
extern float lbl_80650CD8;
extern float lbl_80650CDC;
extern float lbl_80650CE0;
extern float lbl_80650CE4;
extern float lbl_80650CE8;
extern float lbl_80650CEC;
extern float lbl_80650CF0;
extern float lbl_80650CF4;
extern float lbl_80650CF8;
extern float lbl_80650CFC;
extern float lbl_80650D00;
extern float lbl_80650D04;

void fn_801A0450(void)
{
    int i;

    for (i = 0; i < 51; i++) {
        lbl_80607440[i * 4] = (u8)(lbl_80650CA8 + lbl_80650CAC * i / lbl_80650CB0);
        lbl_80607440[i * 4 + 1] = (u8)(lbl_80650CB4 + lbl_80650CB8 * i / lbl_80650CB0);
        lbl_80607440[i * 4 + 2] = (u8)(lbl_80650CBC + lbl_80650CC0 * i / lbl_80650CB0);
        lbl_80607440[i * 4 + 3] = (u8)(lbl_80650CC4 + lbl_80650CC8 * i / lbl_80650CB0);
    }

    for (i = 0; i < 153; i++) {
        lbl_80607440[0xCC + i * 4] = (u8)(lbl_80650CCC + lbl_80650CD0 * i / lbl_80650CD4);
        lbl_80607440[0xCD + i * 4] = (u8)(lbl_80650CD8 + lbl_80650CDC * i / lbl_80650CD4);
        lbl_80607440[0xCE + i * 4] = (u8)(lbl_80650CE0 * i / lbl_80650CD4);
        lbl_80607440[0xCF + i * 4] = (u8)(lbl_80650CE4 + lbl_80650CE8 * i / lbl_80650CD4);
    }

    for (i = 0; i < 51; i++) {
        lbl_80607440[0x330 + i * 4] = (u8)(lbl_80650CEC + lbl_80650CF0 * i / lbl_80650CB0);
        lbl_80607440[0x331 + i * 4] = (u8)(lbl_80650CF4 + lbl_80650CF8 * i / lbl_80650CB0);
        lbl_80607440[0x332 + i * 4] = (u8)(lbl_80650CE0 + lbl_80650CFC * i / lbl_80650CB0);
        lbl_80607440[0x333 + i * 4] = (u8)(lbl_80650D00 + lbl_80650D04 * i / lbl_80650CB0);
    }
}
