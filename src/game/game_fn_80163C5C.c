extern char lbl_8024F738[];
extern char lbl_8064BB4C;
extern char lbl_8064BB50;

extern int strlen(const char*);
extern unsigned long fn_800FD0C8(const char*, const char*);
extern char* fn_800FD3C8(char*, const char*, unsigned long);
extern char* fn_800FD40C(char*, const char*);
extern int fn_800F9D4C(char*, const char*, ...);

void fn_80163C5C(char* output, signed char* source, int size)
{
    char* strings = lbl_8024F738;
    int length;

    if (*source == '=') {
        fn_800FD3C8(output, (char*)source + 1, size);
        output[size - 1] = 0;
    } else if (*source == '@') {
        source++;
        length = strlen((char*)source);
        if (length > size - 13) {
            source += length - (size - 13);
            fn_800F9D4C(output, strings + 0x24, source);
        } else {
            fn_800F9D4C(output, strings + 0x34, source);
        }
    } else {
        length = fn_800FD0C8((char*)source, &lbl_8064BB4C);
        if ((unsigned long)length > (unsigned long)(size - 17)) {
            length = size - 17;
        }
        if (source[length] != 0) {
            fn_800FD40C(output, strings + 0x44);
            output += strlen(output);
            fn_800FD3C8(output, (char*)source, length);
            fn_800FD40C(output + length, &lbl_8064BB50);
        } else {
            fn_800F9D4C(output, strings + 0x50, source);
        }
    }
}
