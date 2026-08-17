extern void* fn_80201B3C();
extern int fn_80201B64(void*);
extern void* fn_8015C910(void);
extern int fn_801D10B8(void);
extern int fn_8015C9F0(void);
extern int fn_80201B44();
extern int fn_801D9924(void*);
extern int lbl_8064C624;
extern int lbl_8064D18C;

int fn_80090204(void* object)
{
    void* linked = fn_80201B3C(object);
    int type = fn_80201B64(object);
    void* state = fn_8015C910();
    int result = 1;
    int active = fn_801D10B8();
    int count = fn_8015C9F0();
    int linked_type = fn_80201B64(linked);

    if (type == 8) {
        result = 0;
    } else if (linked_type == 8) {
        result = 0;
    } else if ((active != 0 && fn_801D9924(((void*)fn_80201B44())) == 0) ||
               state != 0 || lbl_8064C624 != 2 || count > 0 ||
               lbl_8064D18C == 0x53) {
        result = 0;
    }
    return result;
}
