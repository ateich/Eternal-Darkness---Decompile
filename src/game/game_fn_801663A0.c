typedef struct Node {
    char pad0[4];
    int value;
    int position;
} Node;

typedef struct State {
    char pad0[0x1C];
    short position;
    char pad1E[10];
    Node* node;
} State;

typedef struct Parser {
    char pad0[0x28];
    State* state;
} Parser;

extern void fn_8015EA7C(Parser*, const char*);
extern void fn_80163DA4(Parser*);
extern void fn_8015EE54(State*, int);
extern int fn_8015EAD0(State*);
extern void fn_8015F2B0(State*, void*, int);
extern const char lbl_8024F9D0[];

void fn_801663A0(Parser* parser)
{
    State* state = parser->state;
    int position = state->position;
    Node* node = state->node;

    if (node == 0) {
        fn_8015EA7C(parser, lbl_8024F9D0);
    }
    fn_80163DA4(parser);
    fn_8015EE54(state, position - node->position);
    fn_8015F2B0(state, &node->value, fn_8015EAD0(state));
    fn_8015EE54(state, node->position - position);
}
