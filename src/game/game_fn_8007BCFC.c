typedef unsigned short u16;
typedef struct State {
    void *value;
    u16 id;
    unsigned char kind;
    unsigned char pad;
} State;
extern volatile State lbl_8064C8DC;

void fn_8007BCFC(u16 id, unsigned char kind)
{
    lbl_8064C8DC.value = 0;
    lbl_8064C8DC.id = id;
    lbl_8064C8DC.kind = kind;
}
