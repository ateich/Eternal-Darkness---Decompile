typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Job { u8 bytes[0x70]; } Job;

extern float lbl_806504D8;
extern float lbl_806504DC;
extern void fn_8014B768(void);
extern void fn_8014C7C0(void);
extern void fn_8014C87C(void);
extern void* fn_80201814(void*);
extern Job* fn_80149D98(void (*)(void));
extern void fn_80149D64(void);
extern void* fn_80201BC8(void*);
extern void fn_8011F6A4(void*, int, int, int, void*, int);
extern void fn_8014CBC0(void*);
extern void fn_801FE8DC(void*, void (*)(void), int, int, int, void (*)(void), float, float, float);
extern void fn_801E8328(int, void*);

void* fn_8014C68C(void* owner, int start, int finish, int* value,
                  int initial, int final, u16 count)
{
    int placement[7];
    void* runtime = fn_80201814(owner);
    Job* job = 0;
    u8* state;

    if (runtime != 0) {
        job = fn_80149D98(fn_8014B768);
        if (job != 0) {
            fn_80149D64();
            fn_8011F6A4(fn_80201BC8(runtime), start, finish, -1, placement, 1);
            state = job->bytes + 8;
            fn_8014CBC0(state);
            *(int*)(state + 4) = initial;
            *(int*)(state + 0x1C) = placement[2];
            *(int*)(state + 0x20) = placement[3];
            *(int*)(state + 0x24) = placement[4];
            *(int*)(state + 0x28) = *value;
            *(void (**)(void))(state + 0x48) = fn_8014C7C0;
            *(u8*)(state + 0x36) = 0xFF;
            *(int*)(state + 0x0C) = final;
            *(int*)(state + 0x10) = (final - initial) / count;
            *(u8*)(state + 0x38) = 4;
            *(void**)(state + 0x64) = owner;
            *(void (**)(void))(state + 0x68) = fn_8014C87C;
            *(int*)state = 0;
            fn_801FE8DC(state + 4, fn_8014C87C, 4,
                        (final - initial) / count, -1, fn_8014C7C0,
                        lbl_806504D8, lbl_806504D8, lbl_806504DC);
            fn_801E8328(19, state);
        }
    }
    return job;
}
