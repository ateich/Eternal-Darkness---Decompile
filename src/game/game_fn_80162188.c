extern char* lbl_8023A7F8[];
extern void fn_800FD40C(char*, char*);

void fn_80162188(int value, char* output)
{
    if (value < 0x100) {
        output[0] = value;
        output[1] = 0;
    } else {
        fn_800FD40C(output, lbl_8023A7F8[value - 0x101]);
    }
}
