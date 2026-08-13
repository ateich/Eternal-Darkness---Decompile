extern void *fn_80049220(void *, int);
extern void *fn_80049304(void *, void *);
extern void *fn_80201BC8(void *);
extern int fn_8011EB04(void *);

int fn_80071950(void *object)
{
    int result = 0;

    if (object != 0) {
        void *value = fn_80049220(object, 1);
        void *other = fn_80049304(object, value);
        if (other != 0) {
            void *resource = fn_80201BC8(other);
            if (resource != 0) {
                int type = fn_8011EB04(resource);
                switch (type) {
                case 0xC1:
                case 0x61:
                    result = 1;
                    break;
                }
            }
        }
    }
    return result;
}
