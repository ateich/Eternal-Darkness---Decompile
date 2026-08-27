typedef unsigned char u8;
typedef signed int s32;

extern s32 lbl_8064B810;
extern s32 lbl_8064B814;
extern s32 lbl_8064D18C;

extern s32 fn_8015E4E8(void);
extern s32 fn_8015C628(void*);
extern void fn_801ED3F4(void*);
extern void* fn_80201ADC(void);
extern s32 fn_80201BC8(void);
extern s32 fn_80047178(void);
extern s32 fn_8012FA54(s32, s32);
extern s32 fn_80201EB8(void*);

typedef struct Object {
    u8 pad0[3];
    u8 flags;
    u8 pad4[0x34];
    void* field_38;
    u8 pad3c[0x2c];
    void* field_68;
    u8 pad6c[0xdc];
    void (*callback)(struct Object*);
} Object;

void fn_8018812C(Object* self)
{
    if (self->callback != 0 && lbl_8064B810 != 0 && lbl_8064B814 != 0) {
        if (fn_8015E4E8() != 0) {
            if ((self->flags & 0x80) == 0) {
                return;
            }
            if (self->field_68 != 0) {
                fn_801ED3F4(self->field_68);
            }
            self->callback(self);
        } else {
            if ((self->flags & 1) == 0 && fn_8015C628(self->field_38) == 0) {
                return;
            }
            {
            s32 transformed = 0;
            void* context;
            s32 active;
            s32 context_state;

            context = fn_80201ADC();
            if (context != 0) {
                transformed = fn_80201BC8();
            }
            active = fn_80047178();
            transformed = fn_8012FA54(transformed, 15);
            context_state = fn_80201EB8(context);
            if ((active == 0 || transformed == 0 || context_state != lbl_8064D18C) &&
                (self->flags & 0x10) != 0) {
                return;
            }
            if (self->field_68 != 0) {
                fn_801ED3F4(self->field_68);
            }
            self->callback(self);
            }
        }
    }
}
