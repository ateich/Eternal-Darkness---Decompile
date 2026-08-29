typedef unsigned char u8;
typedef unsigned short u16;

extern void* lbl_8064D238;
extern char lbl_80606334[];

void* fn_8018038C(void* owner, const char* name);
void fn_80196784(void* object, void* arg, int value, int mode);
void fn_80196918(void* object, int mode);
void fn_80196DE4(void);
void fn_80197910(void);

void* fn_801966E0(void* arg, int value, int mode)
{
    char* name = lbl_80606334;
    u8* object = fn_8018038C(lbl_8064D238, name);

    if (object) {
        fn_80196784(object, arg, value, mode);
        fn_80196918(object, mode);
        *(void (**)(void))(object + 0x14c) = fn_80196DE4;
        *(void (**)(void))(object + 0x148) = fn_80197910;
        *(u16*)(object + 0x22) = 4;
    }
    return object;
}
