typedef unsigned int u32;

typedef struct Request {
    int unused;
    int source;
    int room;
    int effect;
    u32 flags;
} Request;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern u32 lbl_8064C4E4;
extern int lbl_8064C4F4;
extern int lbl_8064C5C0;
extern int lbl_8064D18C;
extern float lbl_80650630;
extern float lbl_80650634;
extern char lbl_8063CD18[];

extern void* fn_8016BA38(int);
extern void* fn_80158ABC(int, int, float*);
extern void fn_80179DB0(Vec3*, void*);
extern void fn_801379E4(int, Vec3*, float);
extern void fn_8012B7A0(int, float);
extern void fn_800BC74C(int);
extern void fn_80045980(void);
extern void fn_800459A0(void);
extern void fn_80180C94(void);
extern void fn_80200EAC(int, int, int, float, int);
extern void fn_801FA01C(void*, int, int, int, int, int, int, int, int, int);
extern void fn_801F8598(void);
extern void fn_801FA410(int);
extern void fn_801FA354(void);
extern void fn_8016ADF0(short, int, int);

void fn_80159630(Request* request)
{
    int source = request->source;
    int room = request->room;
    int effect = request->effect;
    u32 flags = request->flags;
    float distance;
    Vec3 position;
    void* object;

    if (lbl_8064C4E4 != 0 && lbl_8064C5C0 == 0) {
        if (flags & 1) {
            object = fn_8016BA38(0);
        } else {
            object = fn_80158ABC(source, 2, &distance);
        }
        if (object != 0) {
            fn_80179DB0(&position, object);
            fn_801379E4(lbl_8064C4E4, &position, lbl_80650634);
            fn_8012B7A0(lbl_8064C4E4, distance);
        }
    }

    fn_800BC74C(0);
    fn_80045980();
    fn_800459A0();
    if (lbl_8064C4F4 == 0) {
        fn_80180C94();
        fn_80200EAC(62, 0, 0, lbl_80650630, lbl_8064D18C);
    }

    fn_801FA01C(lbl_8063CD18 + 0x110, room, 0, 0, 0, 0, 0, 1, 0, 1);
    fn_801F8598();
    fn_801FA410(2);
    fn_801FA354();
    if (effect > 0) {
        fn_8016ADF0((short)effect, -1, 1);
    }
    lbl_8064C5C0 = 0;
}
