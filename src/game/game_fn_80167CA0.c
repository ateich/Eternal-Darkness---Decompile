typedef struct Parser {
    char pad0[0x48];
    void* rows;
    int max_row;
    char pad50[0x10];
    int nblocks;
} Parser;

#pragma use_lmw_stmw on

extern void* fn_8016393C(Parser*, void*, int, int, int, void*, int);
extern void fn_80167C28(Parser*, int);
extern char lbl_8064BBC4;

void fn_80167CA0(Parser* parser)
{
    int i;

    parser->rows = fn_8016393C(parser, parser->rows, 0, 6, 64,
                               &lbl_8064BBC4, 0x7FFFFFFD);
    parser->nblocks += 384;
    parser->max_row = 5;

    for (i = 0; i <= parser->max_row; i++) {
        fn_80167C28(parser, i);
    }
}
