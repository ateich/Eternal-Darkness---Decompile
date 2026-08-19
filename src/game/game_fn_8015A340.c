/* Initial reconstruction of the streaming worker's permanent message loop. */
extern char lbl_805B6FFC[];
extern int fn_8020D318(void*, unsigned int*, int);
extern void fn_8015C020(int);

void fn_8015A340(void)
{
    unsigned int message;

    for (;;) {
        int handled = 0;
        fn_8020D318(lbl_805B6FFC, &message, 1);

        switch (message & 0xFFE00000) {
        case 0x80000000:
        case 0x08000000:
        case 0x40000000:
        case 0x10000000:
            handled = 1;
            break;
        }

        fn_8015C020(handled);
    }
}
