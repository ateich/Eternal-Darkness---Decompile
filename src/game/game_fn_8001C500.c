typedef unsigned int u32;

typedef struct Command {
    u32 words[8];
} Command;

extern void* fn_8016A694(void*, int);
extern u32 fn_800F5C54(void*);
extern Command lbl_803023E0;

void fn_8001C500(void* arg)
{
    lbl_803023E0.words[5] = fn_800F5C54(fn_8016A694(arg, 3));
    lbl_803023E0.words[6] = fn_800F5C54(fn_8016A694(arg, 4));
}
