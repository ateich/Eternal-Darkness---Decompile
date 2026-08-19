typedef struct ParseResult {
    int value;
    int kind;
} ParseResult;

typedef struct OutputData {
    char padding_00[0x18];
    unsigned int* words;
} OutputData;

typedef struct Parser {
    char padding_00[0x28];
    OutputData** output;
    char padding_2C[8];
    void* context;
} Parser;

extern char lbl_8024F924[];
extern char lbl_8024F940[];
extern int fn_8015F9B0(OutputData**, int, int);
extern void fn_80163E94(Parser*, int);
extern void fn_801652B4(Parser*, ParseResult*);
extern int fn_80163F00(Parser*, int);
extern void fn_80163ED4(Parser*, int, char*);
extern void fn_80163F38(Parser*, int, int, void*);
extern void fn_8016203C(Parser*, int, int, char*);

void fn_8016536C(Parser* parser)
{
    OutputData** output = parser->output;
    void* context = parser->context;
    int index = fn_8015F9B0(output, 0x11, 0);
    ParseResult first;
    ParseResult second;
    int count;

    fn_80163E94(parser, 0x7B);
    fn_801652B4(parser, &first);
    count = first.value;
    if (fn_80163F00(parser, 0x3B)) {
        fn_801652B4(parser, &second);
        fn_80163ED4(parser, first.kind != second.kind, lbl_8024F924);
        count += second.value;
    }
    fn_80163F38(parser, 0x7D, 0x7B, context);
    fn_8016203C(parser, count, 0x3FFFFFF, lbl_8024F940);
    (*output)->words[index] = ((*output)->words[index] & 0x3F) | (count << 6);
}
