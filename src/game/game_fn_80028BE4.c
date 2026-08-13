typedef int s32;
typedef unsigned int u32;

extern s32 lbl_8064C6FC;
extern s32 lbl_8064D18C;

extern void* fn_80201B3C(void);
extern void *fn_80201B9C(void);
extern void* fn_80201BC0(void*);
extern int fn_80201EB8(void *);
extern int fn_80201B4C(void*);
extern void* fn_80155DB4(void*);
extern void* fn_80156930(void*);
extern void fn_801568B8(void*, void*);
extern unsigned int fn_80036D5C(void*);
extern void fn_80036DA4(void*, u32);
extern void fn_8002AC60(void);
extern void fn_8002B5B0(void);

void fn_80028BE4(void)
{
    switch (lbl_8064C6FC) {
    case 0:
        break;

    case 1: {
        void* head;
        void* item;
        void* actor;

        head = fn_80201B3C();
        item = fn_80201B9C();
        while (item != 0) {
            if (item != head && fn_80201EB8(item) == lbl_8064D18C &&
                (fn_80036D5C(item) & 0x04000000)) {
                actor = fn_80155DB4(item);
                if (actor != 0 &&
                    fn_80156930(actor) == (void*)fn_8002AC60) {
                    fn_801568B8(actor, (void*)fn_8002B5B0);
                }
            }
            item = fn_80201BC0(item);
        }
        lbl_8064C6FC = 0;
        break;
    }

    case 2: {
        void* head;
        void* item;

        head = fn_80201B3C();
        item = fn_80201B9C();
        while (item != 0) {
            if (item != head && fn_80201B4C(item) == 1 &&
                (fn_80036D5C(item) & 0x04000000)) {
                void* actor = fn_80155DB4(item);
                if (actor != 0) {
                    fn_801568B8(actor, (void*)fn_8002AC60);
                }
                fn_80036DA4(item, fn_80036D5C(item) & ~0x04000000);
            }
            item = fn_80201BC0(item);
        }
        lbl_8064C6FC = 0;
        break;
    }
    }
}
