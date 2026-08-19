typedef struct Value {
    void* first;
    void* second;
    void* object;
} Value;

typedef struct Node {
    void* first;
    void* second;
    void* object;
    signed char countdown;
} Node;

extern void* fn_801FEA8C(int, int, const char*, int);
extern void* fn_8017CCD8(void*, int, int);
extern Value* fn_80155E08(void);
extern Node* fn_80155E68(void);
extern void fn_80156120(Value*);
extern const char lbl_8024F018[];

extern void* lbl_8064D0FC;
extern void* lbl_8064D0F8;
extern Value* lbl_8064D0F4;
extern Value* lbl_8064D0F0;
extern Node* lbl_8064D0EC;
extern Node* lbl_8064D0E8;
extern Node* lbl_8064D0E4;
extern Node* lbl_8064D0E0;
extern int lbl_8064D0DC;
extern int lbl_8064D0D8;
extern int lbl_8064D0D0;
extern int lbl_8064D0CC;
extern int lbl_8064D0C0;
extern int lbl_8064D0C4;

void fn_801569A0(int initialized)
{
    if (initialized == 0) {
        void* first = fn_801FEA8C(0x7ED8, 1, lbl_8024F018, 0x6D7);
        void* second = fn_801FEA8C(0x3CC0, 1, lbl_8024F018, 0x6D8);
        lbl_8064D0FC = fn_8017CCD8(first, 0x48, 0x1C3);
        lbl_8064D0F8 = fn_8017CCD8(second, 0x10, 0xD8);
    }

    lbl_8064D0DC = 0;
    lbl_8064D0F4 = fn_80155E08();
    lbl_8064D0EC = fn_80155E68();
    lbl_8064D0E4 = fn_80155E68();
    lbl_8064D0EC->first = 0;
    lbl_8064D0EC->second = 0;
    lbl_8064D0EC->object = lbl_8064D0F4;
    lbl_8064D0E4->first = 0;
    lbl_8064D0E4->second = 0;
    lbl_8064D0E4->object = 0;
    lbl_8064D0E4->countdown = -1;
    fn_80156120(lbl_8064D0F4);

    lbl_8064D0F0 = fn_80155E08();
    lbl_8064D0E8 = fn_80155E68();
    lbl_8064D0E0 = fn_80155E68();
    lbl_8064D0E8->first = 0;
    lbl_8064D0E8->second = 0;
    lbl_8064D0E8->object = lbl_8064D0F0;
    lbl_8064D0E0->first = 0;
    lbl_8064D0E0->second = 0;
    lbl_8064D0E0->object = 0;
    lbl_8064D0E0->countdown = -1;
    fn_80156120(lbl_8064D0F0);

    lbl_8064D0D8 = 0;
    lbl_8064D0D0 = 0;
    lbl_8064D0CC = 0;
    lbl_8064D0C0 = 0;
    lbl_8064D0C4 = 0;
}
