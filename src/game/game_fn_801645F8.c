typedef struct Entry {
    int first;
    int second;
    int third;
} Entry;

typedef struct ParserState {
    char padding_00[0x20];
    short entry_count;
    char padding_22[0x0A];
    Entry entries[1];
} ParserState;

typedef struct Parser {
    char padding_00[0x28];
    ParserState* state;
} Parser;

extern char lbl_8024F83C[];
extern void fn_8016203C(Parser*, int, int, char*);

int fn_801645F8(Parser* parser, Entry* entry)
{
    ParserState* state = parser->state;
    int i;

    for (i = 0; i < state->entry_count; i++) {
        if (state->entries[i].first == entry->first &&
            state->entries[i].second == entry->second) {
            return i;
        }
    }

    fn_8016203C(parser, state->entry_count + 1, 32, lbl_8024F83C);
    state->entries[state->entry_count] = *entry;
    return state->entry_count++;
}
