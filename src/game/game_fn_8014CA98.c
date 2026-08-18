extern float lbl_8023A728[3];
extern double lbl_806504F0;
extern void* fn_80156938(void*);
extern void* fn_80201BC8(void*);
extern short fn_801FE9DC(void*);
extern void fn_8012B690(void*, float*, float*);
extern void fn_801FDEB4(void*, float*);

/*
 * Honest NonMatching reconstruction. The transform setup and signed-angle
 * conversion are behavior-complete; retail retains a distinct runtime/owner
 * allocation and one additional conversion-scheduling instruction.
 */
void fn_8014CA98(void* first, void* second)
{
    float result[3];
    float value[3];
    void* owner;
    void* runtime;

    owner = fn_80201BC8(fn_80156938(second));
    runtime = fn_80156938(first);
    if (runtime != 0) {
        value[0] = lbl_8023A728[0];
        value[1] = lbl_8023A728[1];
        value[2] = lbl_8023A728[2];
        value[1] = (float)-fn_801FE9DC(runtime);
        fn_8012B690(owner, value, result);
        fn_801FDEB4(runtime, result);
    }
}
