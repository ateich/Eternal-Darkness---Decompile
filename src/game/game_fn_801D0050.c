typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef struct Vec3 { float x, y, z; } Vec3;
typedef union Payload { u8 bytes[20]; u32 words[5]; } Payload;

extern s32 fn_80144C40(void), fn_801A5CE0(void), fn_801A5D04(void);
extern s32 fn_80070A6C(s32), fn_801118E8(void);
extern void* fn_801E6CA0(void*, s32, s32, s32, s32);
extern void fn_80006954(s32), fn_80027730(void*, s32, s32);
extern u32 fn_80201AE4(void); extern void* fn_80201ADC(void);
extern s32 fn_80201B64(void*); extern u64 fn_8020123C(s32,u32,u32,s32);
extern s32 fn_8006D3E4(s32,s32); extern void* fn_80201814(s32);
extern void* fn_80201C24(void*); extern s32 fn_801579EC(void*);
extern u32 fn_80157888(void*), fn_80157894(void*); extern u8 fn_80157AB8(void*);
extern void* fn_80158598(u32,s32); extern void* fn_80158550(void*,void*);
extern s32 fn_80205110(void*); extern void fn_80006D50(s32,s32);
extern s32 fn_8001DA04(void); extern void fn_80118060(s32,u32);
extern void fn_80049194(void); extern s32 fn_801A6D94(void);
extern void* fn_80201B94(void*); extern s32 fn_80201C48(void*);
extern s32 fn_80201EB8(void*); extern void* fn_80204318(void*,s32);
extern u32 fn_80201B54(void*); extern s32 fn_800462C8(s32), fn_80071DB0(void);
extern s32 fn_801D38E8(u32); extern void fn_800A09D8(s32);
extern u32 fn_8020216C(void*); extern void fn_801D3E0C(u32,s16*,s16*,s16*);
extern s32 fn_801D3D2C(void*,s16,s16,s16), fn_802021AC(void*);
extern void fn_80038308(void*,s32,s16*), fn_800389E0(void*,s32,s16,s32);
extern void fn_80201E78(Vec3*,void*);
extern void fn_80205470(s32,u32,s16*,s32,float);
extern s32 fn_801D0794(u32,s32,u32,Payload*,void*,s32,void*,u32);
extern void fn_801CE720(u32,s32,Vec3*,s32,float,s32,s32,s32);
extern void fn_801D313C(u32,u32,Vec3*);
extern void fn_801D0C94(void), fn_801D0C9C(void), fn_800CA554(void);
extern s32 lbl_8064D18C; extern void* lbl_8064C504;
extern char lbl_80331748[]; extern char lbl_80332140[];
extern s32 lbl_8064D538; extern float lbl_80651068, lbl_8065106C;

static inline s32 entity_handle(s32 index)
{
    return ((s32*)lbl_80332140)[index];
}

s32 fn_801D0050(s32 mode, u32* event)
{
    u32 event_word = *event;
    void* callback = fn_801D0C94;
    u32 callback_arg = 0;
    s32 result = 0;
    u32 subsystem;
    void *object;
    s32 perform, reason, special;
    void *message;
    Payload payload;
    Vec3 special_pos;
    Vec3 fail_pos;
    s16 xyz[3];
    s16 x, z, y, old_x, old_y, old_z;

    fn_80144C40();
    if (fn_801A5CE0() == 0 && fn_801A5D04() == 0) return 0;
    if (fn_80070A6C(2) != 0) return 0;
    if (lbl_8064D18C == 0x53) {
        message = fn_801E6CA0(lbl_8064C504,0,0x1F,0,1);
        fn_80006954(2); fn_80027730(message,0,0); return 0;
    }
    if (mode != 0 && fn_801118E8() == 0) {
        if (*(void**)(lbl_80331748 + 8) != 0) {
            void* notice = fn_801E6CA0(lbl_8064C504,0,0x16,0,1);
            fn_80006954(2); fn_80027730(notice,0,0);
        }
        return 0;
    }
    if (lbl_8064D538 != 0) goto done;
    subsystem = fn_80201AE4();
    object = fn_80201ADC();
    if (object == 0) goto done;
    perform = 1;
    if (fn_80201B64(object) != 0x40 || !(event_word & 0x80000000))
        if ((u32)(fn_8020123C(0xAF,subsystem,subsystem,0) & 0xFFFFFFFFULL) != 1) goto done;

    lbl_8064D538 = event_word;
    special = 0;
    switch (event_word & 0x1FF0) {
    case 0x300:
        payload.words[1] = subsystem; payload.words[0] = 0;
        if (fn_8006D3E4(0x800,0)) { perform=0; reason=0xC; }
        else if (event_word & 0x80000000) {
            s32 entity = entity_handle(0); void* state; s32 alt; u32 a,b;
            if (entity) {
                state=fn_80201C24(fn_80201814(entity)); alt=fn_801579EC(state);
                if (alt) { entity=alt; state=fn_80201C24(fn_80201814(entity)); }
                a=fn_80157888(state); b=fn_80157894(state);
                if (b & 1) { payload.words[0]=(u32)entity; special=1; }
                else if ((a&1) && (!fn_80157AB8(state) || !(b&0x100))) {
                    if (!fn_80158550(fn_80158598(subsystem,0),(void*)entity)) { perform=0; reason=6; }
                    payload.words[0]=(u32)entity;
                } else { perform=0; reason=6; }
            } else { perform=0; reason=6; }
        } else if (fn_80205110(object)>0) {
            fn_80006D50(0,1); lbl_8064D538=0;
            if (fn_8001DA04()!=3) fn_8020123C(0xB0,subsystem,subsystem,0);
            else fn_80118060(2,event_word);
        } else { perform=0; reason=0x1D; }
        break;
    case 0x810: {
        void* entity=0; fn_80049194();
        if (fn_801A6D94()) { s32 handle=fn_80201C48(fn_80201B94(object)); if (handle) {
            entity=fn_80201814(handle);
            if (lbl_8064D18C!=fn_80201EB8(entity)) entity=0;
        }}
        if (!entity) entity=fn_80204318(object,1);
        if (entity) payload.words[0]=fn_80201B54(entity);
        else { perform=0; reason=3; }
        break;
    }
    case 0x820:
        if (fn_800462C8(1)) { perform=0; reason=0xC; }
        else {
            s32 room=lbl_8064D18C;
            if (room==0x47 || room==0x68 || room==0xEC || room==0x3A) { perform=0; reason=0x13; }
            callback=fn_800CA554; callback_arg=(subsystem<<8)|0x78;
        }
        break;
    case 0x1010: payload.words[0]=0; payload.bytes[4]=0; break;
    case 0x410:
        payload.bytes[0]=0;
        if (fn_80071DB0()) { perform=0; reason=0xC; }
        break;
    case 0x440:
        if (fn_80071DB0() && fn_801D38E8(event_word)==4) { perform=0; reason=0xC; }
        break;
    case 0x1040: fn_800A09D8(0); break;
    case 0x420: case 0x480: case 0x500: break;
    default:
        lbl_8064D538=0; fn_8020123C(0xB0,subsystem,subsystem,0); break;
    }

    if (!lbl_8064D538) goto done;
    if (perform && !(event_word & 0x40000000)) {
        u32 flags=fn_8020216C(object); s32 amount;
        fn_801D3E0C(event_word,&x,&y,&z);
        amount=fn_801D3D2C(object,x,y,z);
        if (amount>0 && !fn_802021AC(object)) { reason=amount+0xA; perform=0; }
        else {
            if (x && !(flags&0x800)) { fn_80038308(object,0,&old_x); fn_800389E0(object,0,old_x+x,1); }
            if (y && !(flags&0x1000)) { fn_80038308(object,1,&old_y); fn_800389E0(object,1,old_y+y,1); }
            if (z && !(flags&0x2000)) { fn_80038308(object,2,&old_z); fn_800389E0(object,2,old_z+z,1); }
        }
    }
    if (perform) {
        if (special) {
            fn_80201E78(&special_pos,object);
            xyz[0]=(s32)special_pos.x; xyz[1]=(s32)special_pos.y; xyz[2]=(s32)(lbl_80651068+special_pos.z);
            fn_80205470(0,payload.words[0],xyz,0x48,lbl_8065106C);
        }
        lbl_8064D538=0;
        result=fn_801D0794(event_word,1,subsystem,&payload,fn_801D0C9C,0,callback,callback_arg);
    } else {
        fn_80201E78(&fail_pos,object);
        fn_801CE720(event_word,lbl_8064D18C,&fail_pos,0x78,lbl_8065106C,1,0,0);
        fn_801D313C(event_word,subsystem,&fail_pos);
        message=fn_801E6CA0(lbl_8064C504,0,reason,0,1);
        fn_80027730(message,0,0);
        fn_8020123C(0xB0,subsystem,subsystem,0);
    }
done:
    return result;
}
