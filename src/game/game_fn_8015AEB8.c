typedef signed char s8;
typedef unsigned char u8;

typedef struct Object {
    u8 pad[0x28];
    int id;
} Object;

typedef struct State {
    u8 pad[0x8140];
    short id;
    s8 active;
    s8 pending;
} State;

typedef struct Globals {
    int primary;
    int current;
    int pad;
    State* states[4];
} Globals;

extern Globals lbl_805B6FE0;
extern Object* fn_8015AD70(int);
extern void fn_8015AD40(int);

void fn_8015AEB8(int index)
{
    Object* object = fn_8015AD70(index);

    if (object != 0 && lbl_805B6FE0.current != -1 &&
        object->id != lbl_805B6FE0.states[lbl_805B6FE0.current]->id &&
        (lbl_805B6FE0.states[lbl_805B6FE0.current]->active == 1 ||
         lbl_805B6FE0.states[lbl_805B6FE0.current]->id == -1)) {
        lbl_805B6FE0.states[lbl_805B6FE0.current]->id = object->id;
        lbl_805B6FE0.states[lbl_805B6FE0.current]->active = 0;
        lbl_805B6FE0.states[lbl_805B6FE0.current]->pending = 0;
        fn_8015AD40(0);
    }
}
