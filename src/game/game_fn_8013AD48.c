typedef struct Contact {
    unsigned char data[0x18];
    float value18;
    unsigned char pad1C[0x0C];
    float value28;
} Contact;
typedef struct Result { unsigned int word[6]; } Result;

extern int lbl_8064B7EC;
extern float lbl_806502B8;
extern float lbl_806502CC;
extern float lbl_806502D0;
extern float lbl_806502D4;
extern void fn_8011EB04(void*);
extern int fn_8011EB1C(void*);
extern int fn_8011FB4C(void*);
extern unsigned int fn_8011FAEC(void*);
extern void* fn_80201B9C(void);
extern void* fn_80201BC8(void*);
extern void* fn_80201BC0(void*);
extern int fn_80137658(void*, Contact*, void*, Result*, float);
extern int fn_801377A4(void*, Contact*, void*, Result*);
extern float fn_80211D4C(Result*, Contact*);

/* Iterative contact correction. The guards, peer filtering, nearest-contact
 * selection and iteration cap are recovered; response-vector updates remain. */
int fn_8013AD48(void* object, Contact* contact, Result* output)
{
    int group;
    unsigned char pass;
    unsigned short contacts = 0;

    fn_8011EB04(object);
    fn_8011EB1C(object);
    group = fn_8011FB4C(object);
    if (lbl_8064B7EC == 0 || (fn_8011FAEC(object) & 0x40) == 0)
        return 0;
    if (contact->value28 == lbl_806502B8)
        return 1;

    for (pass = 0; pass < 8; ++pass) {
        float best = lbl_806502CC;
        void* iterator = fn_80201B9C();
        while (iterator != 0) {
            void* other = fn_80201BC8(iterator);
            if (other != 0 && other != object && fn_8011FB4C(other) == group &&
                (fn_8011FAEC(other) & 0x80) != 0) {
                Result candidate;
                int ok;
                if (contact->value28 >= lbl_806502D0 && contact->value28 <= lbl_806502D4)
                    ok = fn_80137658(object, contact, other, &candidate, contact->value18);
                else
                    ok = fn_801377A4(object, contact, other, &candidate);
                if (ok != 0) {
                    float distance = fn_80211D4C(&candidate, contact);
                    if (distance < best) {
                        best = distance;
                        *output = candidate;
                    }
                    ++contacts;
                }
            }
            iterator = fn_80201BC0(iterator);
        }
        if (contacts == 0)
            break;
    }
    return pass >= 8 || contacts != 0 ? 3 : 2;
}
