typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef signed long long s64;

typedef struct RuntimeState {
    u32 first_handle;
    u32 second_handle;
    u32 third_handle;
    u8 pad_0C[8];
    s32 previous_value;
    s32 value;
    s32 previous_state;
    s32 state;
    s32 counter;
    s32 selection;
    u32 reserved_2C;
    u32 flags;
    u32 aux_handle;
    u32 sound_handle;
    u8 pad_3C[2];
    u8 mode;
} RuntimeState;

extern u8 lbl_80302400[];
extern s32 lbl_803003C8[];
extern u8 lbl_8030F540[];
extern s32 lbl_8064C654;
extern s32 lbl_8064C658;
extern void* lbl_8064C504;
extern s32 lbl_8064C644;
extern s32 lbl_8064C6B4[2];
extern s32 lbl_8064C6BC[2];
extern u32 lbl_8064C6C4;
extern s32 lbl_8064C6C8;
extern s32 lbl_8064C6D0;
extern u32 lbl_8064C2AC;
extern u32 lbl_8064C2B0;
extern u32 lbl_8064C650;
extern double lbl_8064DEC8;
extern float lbl_8064DED8;
extern float lbl_8064DEDC;

extern s32 fn_801A8C60(s32, s32, void*, void*);
extern void fn_80144C4C(void*);
extern void fn_80025A78(int);
extern void fn_8001DE84(int, int);
extern void fn_8001DFEC(s32, s32);
extern void fn_8001DA18(void);
extern void fn_8001DA7C(void);
extern s32 fn_8001DA04(void);
extern s32 fn_800B193C(void);
extern s32 fn_800B194C(void);
extern void fn_800B177C(int, void*);
extern void fn_800B689C(s32, s32);
extern void fn_800B65E4(s32);
extern s32 fn_802201FC(s32);
extern void fn_80020D70(void);
extern void fn_801E5FB0(void*);
#define fn_801E5FB0(a) fn_801E5FB0((void*)(a))

extern u32* fn_801E5D08(u32);
extern u32* fn_801E5D20(u32);
extern void* fn_801E6CA0(void*, int, int, int, int);
extern void fn_801E6F9C(u32, s32);
extern void fn_801EF5EC(void);
extern s32 fn_801AD72C(void);
extern void fn_801AD404(s32, s32, s32);
extern void fn_801AD490(void);
extern void fn_801AD4B4(s32, s32, s32, s32);
extern void fn_801A99B4(void);
extern int fn_801A98F4(int, int);
extern void fn_801A9964(u32);
extern void fn_8020F0F8(void*);
extern void fn_8020EF80(void*);
extern void fn_8020EFBC(void*);
extern s64 fn_8020F088(void*);
extern s32 fn_8020ED10(void);
extern void fn_8020ED80(s32);
extern void* fn_80218308(void);
extern s64 fn_800F5ECC(s64, s64);
extern float fn_800F6264(s64);

/* Convert time-base ticks using the bus clock, as in the retail call sequence. */
#define TIMER_MS() fn_800F6264(fn_800F5ECC(fn_8020F088(base + 0x60), \
    (*(volatile u32*)0x800000F8 / 4) / 1000))
extern void* fn_80144710(s32, s32, s32);
extern void fn_80052580(s32, s32, s32, s32, s32);
extern void fn_80042F34(void);
extern void fn_80042E94(void);

void fn_80020150(void)
{
    u8* base = lbl_80302400;
    u32* handle_data;
    RuntimeState* runtime = (RuntimeState*)(base + 0x1C);
    s32 elapsed;
    fn_801A8C60(240, 150, base + 0x5C, base + 0x58);

    if (runtime->previous_value == 255) {
        fn_80144C4C((void*)lbl_8064C658);
    }
    elapsed = ++runtime->counter;

    switch (runtime->mode) {
    case 29:
        if (runtime->previous_value == 255) {
            if (lbl_8064C6C8 != 0) fn_80025A78(1);
            fn_8001DE84(7, 4);
        }
        break;

    case 18:
        if (elapsed < 600 || lbl_8064C654 != 0) break;
        fn_801E5FB0(runtime->first_handle);
        fn_801E5FB0(runtime->second_handle);
        fn_801E5FB0(runtime->third_handle);
        runtime->first_handle = 0;
        runtime->second_handle = 0;
        runtime->third_handle = 0;
        runtime->counter = 0;
        runtime->mode = 19;
        runtime->first_handle = (u32)fn_801E6CA0(lbl_8064C504, 0, 35, 0, 1);
        handle_data = fn_801E5D08(runtime->first_handle);
        *handle_data = lbl_8064C2AC;
        fn_801EF5EC();
        break;

    case 19:
        lbl_8064C644 = 1;
        if (fn_801AD72C() != -1) break;
        fn_801E5FB0(runtime->first_handle);
        runtime->first_handle = 0;
        fn_8001DFEC(23, 0);
        fn_8001DA18();
        runtime->counter = 0;
        *(u8*)(base + 0x5C) = 0;
        break;

    case 1: {
        s32 limit;
        float now;
        if (((signed char*)lbl_8030F540)[0x1D9]) runtime->flags |= 1;
        if (runtime->previous_value != 255) break;
        if (!(runtime->flags & 2)) {
            runtime->flags |= 2;
            fn_8020F0F8(base + 0x60);
            fn_8020EF80(base + 0x60);
            break;
        }
        limit = 1000;
        now = TIMER_MS();
        if (runtime->flags & 1)
            limit = *(s32*)(base + 0x2CC + 1 * 4);
        if (now >= (float)limit) {
            fn_8001DFEC(24, 0);
            fn_8001DA18();
            runtime->counter = 0;
            *(u8*)(base + 0x5C) = 0;
        }
        break;
    }

    case 2: {
        s32 limit;
        float now;
        if (((signed char*)lbl_8030F540)[0x1D9]) runtime->flags |= 1;
        if (runtime->previous_value != 255) break;
        if (!(runtime->flags & 2)) {
            runtime->flags |= 2;
            fn_8020F0F8(base + 0x60);
            fn_8020EF80(base + 0x60);
            break;
        }
        limit = 500;
        now = TIMER_MS();
        if (runtime->flags & 1)
            limit = *(s32*)(base + 0x2CC + 2 * 4);
        if (now >= (float)limit) {
            fn_8001DFEC(26, 0);
            fn_8001DA18();
            runtime->counter = 0;
            *(u8*)(base + 0x5C) = 0;
        }
        break;
    }

    case 27:
        fn_8001DFEC(25, 0);
        runtime->counter = 0;
        *(u8*)(base + 0x5C) = 0;
        break;

    case 26:
        if (runtime->previous_value != 255) break;
        if (!(runtime->flags & 2)) {
            runtime->flags |= 2;
            fn_8020F0F8(base + 0x60);
            fn_8020EF80(base + 0x60);
            fn_8001DA18();
            if (!(runtime->flags & 1)) {
                fn_801AD404(100, 100, 1);
                fn_801AD4B4(96, 0, 0, 0);
            }
            break;
        }
        {
            s32 limit = (runtime->flags & 1)
                ? *(s32*)(base + 0x2D8) : 9820;
            float now;
            now = TIMER_MS();
            if (fn_801AD72C() == -1 && now >= (float)limit) {
                runtime->counter = 0;
                *(u8*)(base + 0x5C) = 200;
                fn_801AD404(0, 0, 10); fn_801A99B4();
                fn_801AD490(); fn_801A99B4();
                fn_801AD404(100, 100, 1); fn_801A99B4();
                fn_8001DFEC(27, 0); fn_8001DA18();
                if (!(runtime->flags & 0x10)) runtime->flags &= ~1u;
            }
        }
        break;

    case 8:
    case 30:
        if ((fn_800B193C() == 0 && fn_8001DA04() == 0) ||
            (fn_800B193C() && fn_800B194C() == 34)) {
            s32 i;
            for (i = 0; i <= 1; ++i) {
                s32 current = fn_802201FC(i);
                s32 old = lbl_8064C6B4[i];
                lbl_8064C6B4[i] = current;
                if (current && !old) {
                    if (fn_800B193C() && fn_800B194C() == 34)
                        lbl_8064C6C4 |= 2;
                    else {
                        fn_800B177C(2, fn_80020D70);
                        fn_800B689C(1, 1);
                        fn_800B65E4(i);
                        break;
                    }
                }
                if (!lbl_8064C6B4[i]) lbl_8064C6BC[i] = 0;
            }
        }
        break;

    case 3: {
        s32 ready;
        if (!(runtime->flags & 2)) {
            runtime->flags |= 2;
            fn_8020F0F8(base + 0x60);
            fn_8020EF80(base + 0x60);
        }
        ready = 0;
        if (runtime->counter <= 120)
            ready = lbl_8064C6D0 | (fn_8020ED10() == 1);
        if (lbl_8064C654 == 0 && fn_80218308() && ready && !lbl_8064C644) {
            runtime->first_handle = (u32)fn_801E6CA0(lbl_8064C504,0,32,0,1);
            runtime->second_handle = (u32)fn_801E6CA0(lbl_8064C504,0,33,0,1);
            runtime->third_handle = (u32)fn_801E6CA0(lbl_8064C504,0,34,0,1);
            handle_data = fn_801E5D08(runtime->first_handle);
            *handle_data = lbl_8064C2AC;
            handle_data = fn_801E5D08(runtime->second_handle);
            *handle_data = lbl_8064C2AC;
            handle_data = fn_801E5D08(runtime->third_handle);
            *handle_data = lbl_8064C2AC;
            handle_data = fn_801E5D08(runtime->second_handle);
            *handle_data = lbl_8064C2B0;
            *fn_801E5D20(runtime->second_handle) |= 0x60;
            fn_8001DFEC(18,0);
            runtime->selection = 1;
            break;
        }
        if (!fn_80218308()) fn_8020ED80(0);
        if (fn_801AD72C() == -1) {
            if (TIMER_MS() > lbl_8064DED8) {
                fn_801AD404(0,0,10); fn_801A99B4();
                fn_801AD490(); fn_801A99B4();
                fn_801AD404(100,100,1); fn_801A99B4();
                switch (runtime->value) {
                case 12:
                    runtime->counter = 0; *(u8*)(base + 0x5C) = 200;
                    fn_8001DE84(7,0); fn_8001DA18();
                    runtime->mode = 7; runtime->selection = 5;
                    runtime->sound_handle = fn_801A98F4(0x275,100);
                    break;
                default:
                    fn_8001DFEC(23,0); fn_8001DA18();
                    break;
                }
                runtime->counter = 0; *(u8*)(base + 0x5C) = 0;
            }
        }
        break;
    }

    case 23:
        if (runtime->previous_value == 255) {
            fn_8001DFEC(1, 0); fn_8001DA18();
            if (!(runtime->flags & 1))
                fn_80052580(0, 0, 0, 0, 0);
            runtime->previous_value = 0;
            runtime->counter = 0; *(u8*)(base + 0x5C) = 0;
        }
        break;

    case 24:
        if (runtime->previous_value == 255) {
            fn_8001DFEC(2, 0); fn_8001DA18();
            if (!(runtime->flags & 1))
                fn_80052580(0, 44, 0, 0, 0);
            runtime->counter = 0; *(u8*)(base + 0x5C) = 0;
        }
        break;

    case 28:
        if (runtime->previous_value == 255) {
            fn_8001DFEC(10,0); fn_8001DA7C();
        }
        break;

    case 25:
        if (runtime->previous_value == 255) {
            fn_8001DE84(7,0); fn_8001DA18();
            fn_8020F0F8(base+0x60); fn_8020EF80(base+0x60);
            fn_80042F34(); fn_80042E94();
            fn_8020F088(base + 0x60);
            if (!(runtime->flags & 1)) fn_80052580(0,1,0,0,0);
            else runtime->sound_handle = fn_801A98F4(0x275,100);
            runtime->counter = 0; runtime->selection = 5;
            *(u8*)(base + 0x5C) = 0;
        }
        break;

    case 4:
        if (runtime->previous_value == 255 && !(runtime->flags & 2)) {
            runtime->flags |= 2;
            fn_8020F0F8(base+0x60); fn_8020EF80(base+0x60);
        }
        break;

    case 253:
    case 254:
        if (elapsed >= 120) {
            u32 handle;
            fn_8001DE84(251,0);
            if (lbl_803003C8[0] == 1)
                handle = (u32)fn_801E6CA0(lbl_8064C504,0,62,0,1);
            else
                handle = (u32)fn_801E6CA0(lbl_8064C504,0,40,0,1);
            fn_801E6F9C(handle,0);
        }
        break;

    case 251:
    case 252:
        if (elapsed >= 1800) fn_80025A78(1);
        break;

    case 7: {
        float now;
        if (!(runtime->flags & 2)) {
            runtime->flags |= 2;
            fn_8020EF80(base+0x60); fn_8020F0F8(base+0x60);
        }
        now = TIMER_MS();
        if (fn_80144710(-1,0,0)) {
            fn_8020EFBC(base+0x60);
            fn_8020F0F8(base+0x60);
            fn_8020EF80(base+0x60);
        }
        if (now >= lbl_8064DEDC) {
            runtime->flags = 40;
            fn_8020EFBC(base+0x60);
            runtime->counter = 0; *(u8*)(base+0x5C)=200;
            fn_8001DFEC(23,0); fn_8001DA18();
            fn_801A9964(lbl_8064C650);
            if (runtime->sound_handle != (u32)-1) fn_801A9964(runtime->sound_handle);
            if (runtime->aux_handle != (u32)-1) fn_801A9964(runtime->aux_handle);
        }
        break;
    }
    }

    if ((runtime->flags & 1) && (runtime->flags & 8) && runtime->mode != 7) {
        fn_8001DFEC(27,0); fn_8001DA18();
        fn_8001DE84(7,0); fn_8001DA18();
        runtime->flags &= ~9u;
        runtime->sound_handle = fn_801A98F4(0x275,100);
        runtime->selection = 5;
        runtime->counter = 0;
        *(u8*)(base+0x5C)=0;
    }
}
