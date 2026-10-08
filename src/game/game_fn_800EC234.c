typedef unsigned char u8;
typedef unsigned short u16;

typedef struct DebugSource {
    u8 pad0[0x28];
    void* value;
    u8 pad2c[0x2C];
    u8 slot;
    u8 pad59[3];
} DebugSource;

typedef struct DebugVertex {
    unsigned int word;
    char text[52];
} DebugVertex;

typedef struct DebugBatch {
    u8 pad0[0x20];
    u16 count;
    u16 pad22;
    DebugSource* sources;
    DebugVertex* vertices;
    u8 pad2c[4];
    void* output;
} DebugBatch;

extern DebugBatch* fn_8015C390(int);
extern void fn_801ED468(int);
extern void fn_80226D28(int);
extern void fn_801ED118(void);
extern void fn_801EDA7C(void*, int, int, int);
extern void fn_801ECF50(int);
extern void fn_80140E70(void*, DebugVertex*, u8, int, u8);
extern void fn_800ED4BC(char*, int, const char*, ...);

extern char lbl_8024A59C[];
extern char lbl_802FC53C[];
extern char lbl_8064DC80[];

void fn_800EC234(int selector)
{
    DebugBatch* batch;
    DebugSource* source;
    DebugVertex* vertices;
    void* output;
    int i;

    batch = fn_8015C390(selector);
    source = batch->sources;
    vertices = batch->vertices;
    output = batch->output;
    fn_801ED468(0x1B);
    fn_80226D28(0);
    fn_801ED118();
    fn_801EDA7C(lbl_802FC53C, 0, 0x2BF, 0);
    fn_801ECF50(4);

    i = 0;
    while (i < batch->count) {
        DebugVertex* vertex = (DebugVertex*)((u8*)vertices + source->slot * 0x38);
        fn_80140E70(output, vertex, 8, 7, 0x80);
        fn_800ED4BC(vertex->text, 8, lbl_8024A59C, i, source,
                    lbl_8064DC80, source->value);
        i++;
        source++;
    }
}
