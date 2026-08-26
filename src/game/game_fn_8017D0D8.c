typedef unsigned short u16;

typedef struct Manager {
    void* data;
    u16 count;
    u16 pad;
    unsigned int size;
    void* entries;
    void* current;
    void* first;
    void* last;
} Manager;

typedef struct BufferState {
    Manager* managers;
    void* entries;
    u16 manager_count;
    u16 entry_count;
} BufferState;

extern BufferState lbl_80606300;
extern BufferState lbl_8060630C;
extern void fn_8017D144(Manager*);
extern void fn_8017CF0C(void);

void fn_8017D0D8(void)
{
    int count;
    int i;
    Manager* manager;

    manager = lbl_80606300.managers;
    count = lbl_8060630C.manager_count;
    for (i = 0; i < count; i++) {
        fn_8017D144(manager);
        manager++;
    }
    fn_8017CF0C();
}
