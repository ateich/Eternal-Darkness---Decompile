typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct Object { u8 bytes[0x1000]; } Object;

extern int lbl_8064D18C;
extern void* fn_80201814(u32);
extern int fn_80201B64(void);
extern void* fn_80201BC8(void*);
extern int fn_800A0C0C(int);
extern void fn_801D88D4(u32, u32);
extern void fn_801FE22C(u32);
extern void fn_801B05B0(int, int);
extern void fn_801D884C(Object*);
extern s16 fn_801CEB2C(u32);
extern void fn_8017FF04(void*, int);
extern u16 fn_8017FEA4(void*);
extern void fn_8017FF14(void*, u16);
extern int fn_801911D0(void*);
extern void fn_801911F4(void*, int);
extern int fn_8012F674(void*, int, int);
extern void fn_80121104(void*, float);
extern void fn_80182430(void*, int);
extern void fn_80182440(void*, int);
extern void fn_80182428(void*, int);
extern u16 fn_801D3A34(u32, int);
extern void fn_80153A24(float*, int, int, u16, u16, u8*, u8*, int);
extern void fn_801FDF74(u32, u32);
extern void fn_8012C62C(void*, int, u32*, u32*, u32*, int);
extern void fn_8012F58C(void*, int, int, int, int, int);
extern u32 lbl_80651120;
extern u32 lbl_80651124;
extern u32 lbl_80651128;
extern u32 lbl_8065112C;
extern u32 lbl_80651130;
extern u32 lbl_80651134;
extern u32 lbl_80651138;
extern u32 lbl_8065113C;
extern u32 lbl_80651140;
extern u32 lbl_80651144;
extern u32 lbl_80651148;
extern u32 lbl_8065114C;

void fn_801D8E40(Object* object)
{
    u32 flags;
    void* subject;
    void** effect;
    s16 count;
    int i;
    u16 timer;

    flags = *(u32*)(object->bytes + 4);
    subject = fn_80201814(*(u32*)(object->bytes + 0xC));
    if (*(int*)(object->bytes + 8) != lbl_8064D18C || (object->bytes[0xFF0] & 1) != 0) {
        if (*(u16*)(object->bytes + 0xFF4) == 0 && fn_800A0C0C(0) == 0)
            fn_801D88D4(flags, *(u32*)(object->bytes + 0xC));
        fn_801FE22C(*(u32*)(object->bytes + 0x44));
        if (*(int*)(object->bytes + 0x10) != -1)
            fn_801B05B0(*(int*)(object->bytes + 0x10), 10);
        fn_801D884C(object);
        return;
    }

    timer = *(u16*)(object->bytes + 0xFF4);
    if (subject != 0 && fn_80201B64() == 8) {
        if (timer > 30) {
            count = fn_801CEB2C(flags);
            if (timer > 110) {
                for (i = 0; i < count; i++) {
                    effect = (void**)(object->bytes + 0xA5C) + i;
                    if (*effect != 0) {
                        fn_8017FF04(*effect, -24);
                        fn_801911F4(*effect, fn_801911D0(*effect) & ~1);
                    }
                }
            } else {
                for (i = 0; i < count; i++) {
                    effect = (void**)(object->bytes + 0xA5C) + i;
                    if (*effect != 0)
                        fn_8017FF14(*effect, (u16)(fn_8017FEA4(*effect) - 1));
                }
            }
        }
        fn_801FE22C(*(u32*)(object->bytes + 0x44));
        if (*(int*)(object->bytes + 0x10) != -1)
            fn_801B05B0(*(int*)(object->bytes + 0x10), 10);
        fn_801D884C(object);
        return;
    }

    if (timer >= 130 && timer < 160) {
        subject = fn_80201BC8(subject);
        if ((fn_8012F674(subject, 15, 0) & 8) == 0)
            fn_80121104(subject, 1.0f + (float)(timer - 129) / 30.0f);
    }

    switch (timer) {
    case 0:
        if (fn_800A0C0C(0) == 0) {
            fn_801D88D4(flags, *(u32*)(object->bytes + 0xC));
        } else {
            fn_801FE22C(*(u32*)(object->bytes + 0x44));
            if (*(int*)(object->bytes + 0x10) != -1)
                fn_801B05B0(*(int*)(object->bytes + 0x10), 10);
            fn_801D884C(object);
        }
        break;
    case 32:
        count = fn_801CEB2C(flags);
        for (i = 0; i < count; i++) {
            effect = (void**)(object->bytes + 0xA5C) + i;
            if (*effect != 0) {
                fn_80182430(*effect, 8);
                fn_80182440(*effect, 3);
            }
        }
        {
            u16 a = fn_801D3A34(flags, 74);
            u16 b = fn_801D3A34(flags, 70);
            fn_80153A24((float*)(object->bytes + 0x38), count, 250, b, a,
                        object->bytes + 0xBC, object->bytes + 0x58C, 4);
        }
        break;
    case 36:
        count = fn_801CEB2C(flags);
        for (i = 0; i < count; i++) {
            effect = (void**)(object->bytes + 0xA5C) + i;
            if (*effect != 0) fn_80182430(*effect, 10);
        }
        break;
    case 44:
        count = fn_801CEB2C(flags);
        for (i = 0; i < count; i++) {
            effect = (void**)(object->bytes + 0xA5C) + i;
            if (*effect != 0) {
                fn_80182430(*effect, 14);
                fn_80182440(*effect, 7);
            }
        }
        break;
    case 54:
        count = fn_801CEB2C(flags);
        for (i = 0; i < count; i++) {
            effect = (void**)(object->bytes + 0xA5C) + i;
            if (*effect != 0) fn_80182430(*effect, 18);
        }
        break;
    case 70:
        count = fn_801CEB2C(flags);
        for (i = 0; i < count; i++) {
            effect = (void**)(object->bytes + 0xA5C) + i;
            if (*effect != 0) fn_80182430(*effect, 20);
        }
        break;
    case 82:
        count = fn_801CEB2C(flags);
        for (i = 0; i < count; i++) {
            effect = (void**)(object->bytes + 0xA5C) + i;
            if (*effect != 0) fn_80182430(*effect, 24);
        }
        break;
    case 100:
        count = fn_801CEB2C(flags);
        for (i = 0; i < count; i++) {
            effect = (void**)(object->bytes + 0xA5C) + i;
            if (*effect != 0) fn_80182428(*effect, 1);
        }
        break;
    case 140:
        fn_801FDF74(*(u32*)(object->bytes + 0x44), 0x7A120);
        break;
    case 150:
        subject = fn_80201814(*(u32*)(object->bytes + 0xC));
        if (subject != 0) {
            u32 a;
            u32 b;
            u32 c;

            subject = fn_80201BC8(subject);
            if (subject != 0 && (fn_8012F674(subject, 15, 0) & 8) == 0) {
                switch (flags & 0xF) {
                case 1:
                    a = lbl_80651120;
                    b = lbl_80651124;
                    c = lbl_80651128;
                    fn_8012C62C(subject, 15, &a, &b, &c, 2);
                    break;
                case 2:
                    a = lbl_8065112C;
                    b = lbl_80651130;
                    c = lbl_80651134;
                    fn_8012C62C(subject, 15, &a, &b, &c, 2);
                    break;
                case 4:
                    a = lbl_80651138;
                    b = lbl_8065113C;
                    c = lbl_80651140;
                    fn_8012C62C(subject, 15, &a, &b, &c, 2);
                    break;
                case 8:
                    a = lbl_80651144;
                    b = lbl_80651148;
                    c = lbl_8065114C;
                    fn_8012C62C(subject, 15, &a, &b, &c, 2);
                    break;
                }
                fn_8012F58C(subject, 15, 0, 0, 0, 4);
            }
        }
        break;
    case 160:
        if (*(void (**)(Object*, u32))(object->bytes + 0x28) != 0)
            (*(void (**)(Object*, u32))(object->bytes + 0x28))(object, *(u32*)(object->bytes + 0x2C));
        fn_801D884C(object);
        break;
    }
}
