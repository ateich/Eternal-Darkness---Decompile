typedef unsigned char u8;

extern int fn_8015E4E8(void);
extern int fn_8015C628(void*);
extern void* fn_8015C910(void);
extern void* fn_80201ADC(void);
extern void* fn_80201BC8(void);
extern int fn_80047178(void);
extern int fn_8012FA54(void*, int);
extern int fn_80201EB8(void*);
extern int fn_8018EEEC(u8*);
extern int lbl_8064D18C;

int fn_8018E934(u8* object)
{
    void* first;
    void* second;
    int result;

    if (*(void**)(object + 0x14C) == 0) {
        result = 0;
    } else if (fn_8015E4E8()) {
        if ((object[3] & 0x80) || (object[3] & 0x20)) {
            result = fn_8018EEEC(object);
        } else {
            result = 0;
        }
    } else if (((object[3] & 5) != 0 ||
                fn_8015C628(*(void**)(object + 0x38))) &&
               (fn_8015C910() == 0 || !(object[3] & 8))) {
        second = 0;
        first = fn_80201ADC();
        if (first != 0) {
            second = fn_80201BC8();
        }

        if ((fn_80047178() && fn_8012FA54(second, 15) &&
             lbl_8064D18C == fn_80201EB8(first)) ||
            !(object[3] & 0x10)) {
            result = fn_8018EEEC(object);
        } else {
            result = 0;
        }
    } else {
        result = 0;
    }
    return result;
}
