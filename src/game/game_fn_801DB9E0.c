typedef unsigned char u8;
typedef unsigned int u32;

/* Dispatch level-dependent events. Keep case-local lifetimes for GC/1.3. */
extern int lbl_8064D18C;
extern void* lbl_8064C4E0;
extern int lbl_80300368[];
extern void* fn_80201B9C(void);
extern void* fn_80201BC0(void*);
extern int fn_80201B5C(void*);
extern void* fn_80201B8C(void*);
extern int fn_80201B54(void*);
extern void* fn_80201BC8(void*);
extern void* fn_80201C24(void*);
extern int fn_801DC20C(u32, u32, int);
extern void fn_8020123C(int, u32, u32, u32);
extern void fn_801E7974(void*, int);
extern void fn_801E79A0(void*, int);
extern int fn_801E79FC(void*, int);
extern u32 fn_802019EC(int, int);
extern void fn_801DB8A0(u32, int);
extern void* fn_80201814(void*);
extern int fn_80201EB8(void*);
extern int fn_800AD2DC(void*);
extern void fn_80175534(int);
extern void fn_8016ADF0(int, int, int);
extern int fn_8011E824(int);
extern void fn_8011DD8C(int, int);
extern void fn_80201D44(void*, int);
extern void fn_80201D24(void*, int);
extern void fn_802015A4(void*);
extern u8 fn_80157AB8(void*);
extern int fn_80200614(u32, int, int);
extern int fn_8011FB4C(void*);
extern u8 fn_80157918(void*);
extern int fn_80201AE4(void);
extern int fn_801586FC(int, int);
extern void* fn_80157924(void*);
extern int fn_8011EB04(void*);
extern int fn_8011EB1C(void*);
extern void fn_80047D6C(void);
extern void fn_8007C17C(void);
extern void fn_80199130(void*, int);
extern void fn_80199138(void*, u32);
extern void fn_8017FD6C(void);
extern void fn_802006D4(u32, u32, int, int, int);

#define U32_AT(p, o) (*(u32*)((u8*)(p) + (o)))
#define U8_AT(p, o) (*(u8*)((u8*)(p) + (o)))

void fn_801DB9E0(u32 flags, int expected, u32 value, int* changed)
{
    void* event;
    for (event = fn_80201B9C(); event != 0; event = fn_80201BC0(event)) {
        switch (fn_80201B5C(event)) {
        case 0x19: {
            void* data;
            void* object;
            u32 id;

            data = (void*)U32_AT(fn_80201B8C(event), 0x2C);
            if ((int)U32_AT(data, 0x10) != lbl_8064D18C || !fn_801DC20C(flags, U32_AT(data, 0xC), expected)) break;
            id = fn_80201B54(event);
            fn_8020123C(0xC4, id, id, value);
            if (!(U8_AT(data, 0) & 4)) break;
            switch (lbl_8064D18C) {
            case 0x54: fn_801E7974(lbl_8064C4E0, 0x3F1); fn_80175534(0); break;
            case 0x55: fn_801E79A0(lbl_8064C4E0, 0x221); break;
            case 0x64:
                if (fn_801E79FC(lbl_8064C4E0, 0x269)) { fn_8016ADF0(0x3B6, -1, 1); fn_801E79A0(lbl_8064C4E0, 0x269); }
                break;
            case 0x66: fn_801E79A0(lbl_8064C4E0, 0x2C2); break;
            case 0x77:
                fn_801E79A0(lbl_8064C4E0, 0x3C5);
                if (fn_8011E824(2) == -2 && lbl_80300368[1] == 0x81E) fn_8011DD8C(2, 1);
                else if (fn_8011E824(4) == -2 && lbl_80300368[9] == 0x81E) fn_8011DD8C(4, 1);
                break;
            case 0x8B:
                if (fn_801E79FC(lbl_8064C4E0, 0x20B)) {
                    fn_801E79A0(lbl_8064C4E0, 0x20B); id = fn_802019EC(0x1C3, 0x8B); fn_801DB8A0(id, 0x43);
                    fn_801E79A0(lbl_8064C4E0, 0x1C3); *changed = 1;
                }
                break;
            case 0xAA: fn_801E79A0(lbl_8064C4E0, 0x1E6); break;
            case 0xAC:
                if (fn_801E79FC(lbl_8064C4E0, 0x1E5)) {
                    fn_801E79A0(lbl_8064C4E0, 0x1E5); object = fn_80201814((void*)fn_802019EC(0x7D2, 0xAC));
                    if (object != 0) { fn_80201D44(object, 5); fn_80201D24(object, 1); fn_802015A4(object); }
                }
                break;
            case 0x129:
                if (fn_801E79FC(lbl_8064C4E0, 0x20C)) {
                    fn_801E79A0(lbl_8064C4E0, 0x20C); id = fn_802019EC(0x1C5, 0x129); fn_801DB8A0(id, 0x44);
                    fn_801E79A0(lbl_8064C4E0, 0x1C5); *changed = 1;
                }
                break;
            case 0x12A:
                if (fn_801E79FC(lbl_8064C4E0, 0x20D)) {
                    fn_801E79A0(lbl_8064C4E0, 0x20D); id = fn_802019EC(0x1C4, 0x12A); fn_801DB8A0(id, 0x42);
                    fn_801E79A0(lbl_8064C4E0, 0x1C4); *changed = 1;
                }
                break;
            }
            break;
        }
        case 0x18: {
            void* data;
            u32 id;

            data = (void*)U32_AT(fn_80201B8C(event), 0x24);
            if (fn_80201EB8(fn_80201814((void*)U32_AT(data, 0xB4))) == lbl_8064D18C && fn_800AD2DC((void*)U32_AT(data, 0xB4)) && fn_801DC20C(flags, U32_AT(data, 0xB8), expected)) {
                id = fn_80201B54(event); fn_8020123C(0xC4, id, id, value);
            }
            break;
        }
        case 0x22: {
            void* data;
            u32 id;

            data = (void*)U32_AT(fn_80201B8C(event), 0x3C);
            if (fn_80201EB8(fn_80201814((void*)U32_AT(data, 0x14))) == lbl_8064D18C && fn_801DC20C(flags, U32_AT(data, 0x10), expected)) {
                id = fn_80201B54(event); fn_8020123C(0x5F, id, id, 0);
            }
            break;
        }
        case 0x31: {
            void* data;
            u32 id;

            data = (void*)U32_AT(fn_80201B8C(event), 0x34);
            if (fn_80201EB8(fn_80201814((void*)U32_AT(data, 0))) == lbl_8064D18C && fn_801DC20C(flags, U32_AT(data, 4), expected)) {
                id = fn_80201B54(event); fn_8020123C(0x39, id, id, 0);
            }
            break;
        }
        case 0x1A: {
            void* data;
            u32 id;

            data = fn_80201B8C(event);
            if (fn_801DC20C(flags, U32_AT((void*)U32_AT(data, 0x30), 8), expected)) { id = fn_80201B54(event); fn_8020123C(0x39, id, id, 0); }
            break;
        }
        case 0x32: {
            void* data;
            u32 id;
            int mask;

            mask = 0; data = fn_80201B8C(event);
            switch (U8_AT(data, 0x9F)) { case 3: mask |= 0x10000; break; case 6: mask |= 0x20000; break; case 4: mask |= 0x40000; break; }
            switch (U32_AT(data, 0x94)) { case 1: mask |= 1; break; case 2: mask |= 2; break; case 3: mask |= 4; break; case 4: mask |= 8; break; }
            if (fn_801DC20C(flags, mask, expected)) { id = fn_80201B54(event); fn_8020123C(8, id, id, 0); }
            break;
        }
        case 0x5B: {
            u32 id;
            void* data;
            int mask;
            int kind;
            void* object;
            void* actor_object;
            int found;
            void* action;
            id = fn_80201B54(event);
            mask = 0;
            data = fn_80201C24(event);
            kind = fn_80157AB8(data);
            object = fn_80201BC8(event);
            if (kind == 0 || !fn_80200614(id, -1, 0x4B) || object == 0 || fn_8011FB4C(object) != lbl_8064D18C) break;
            switch (fn_80157918(data)) { case 2: mask |= 0x10000; break; case 3: mask |= 0x20000; break; case 4: mask |= 0x40000; break; }
            switch (kind) { case 1: mask |= 1; break; case 2: mask |= 2; break; case 3: mask |= 4; break; case 4: mask |= 8; break; }
            if (!fn_801DC20C(flags, mask, expected)) break;
            actor_object = fn_80201BC8(event);
            found = fn_801586FC(id, fn_80201AE4());
            action = fn_80157924(data);
            if (action != 0) {
                if (found != 0) {
                    if (fn_8011EB04(actor_object) != 0x63 && fn_8011EB1C(actor_object) == 4) { fn_80047D6C(); fn_8007C17C(); }
                    fn_80199130(action, 1); fn_80199138(action, value);
                } else {
                    fn_8017FD6C();
                }
            }
            fn_802006D4(id, id, -1, 0x4B, 0); fn_8020123C(0x4B, id, id, 0);
            break;
        }
        case 0x57: {
            void* data;
            void* object;
            u32 id;

            data = fn_80201B8C(event);
            if (data != 0) {
                object = (void*)U32_AT(data, 0x28);
                if (object != 0 && fn_80201EB8(fn_80201814((void*)U32_AT(object, 8))) == lbl_8064D18C && fn_801DC20C(flags, U32_AT(object, 0xC), expected)) {
                    id = fn_80201B54(event); fn_8020123C(0xC4, id, id, value);
                }
            }
            break;
        }
        }
    }
}
