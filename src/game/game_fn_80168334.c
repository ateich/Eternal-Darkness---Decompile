typedef struct InputComposite {
    void* records;
    int record_count;
    void** first_values;
    int first_count;
    void** second_values;
    int second_count;
} InputComposite;

#pragma use_lmw_stmw on

extern int fn_80167FE4(void*, void*, int);
extern void* fn_8016B5CC(void*, void*, unsigned int, const char*, int);
extern void fn_80167F48(void*, void*, int, unsigned int, void*, int);
extern void* fn_80168080(void*, void*, int);
extern void* fn_80168490(void*, void*, int);
extern const char lbl_8024FAF4[];

void fn_80168334(void* object, InputComposite* composite, void* input,
                 int reverse)
{
    int i;
    int n;

    composite->first_count = n = fn_80167FE4(object, input, reverse);
    composite->first_values = fn_8016B5CC(object, 0,
                                           n * sizeof(void*),
                                           lbl_8024FAF4, 141);
    for (i = 0; i < n; i++)
        composite->first_values[i] = fn_80168080(object, input, reverse);

    composite->record_count = n = fn_80167FE4(object, input, reverse);
    composite->records = fn_8016B5CC(object, 0,
                                      n * 8,
                                      lbl_8024FAF4, 145);
    fn_80167F48(object, composite->records, n, 8, input, reverse);

    composite->second_count = n = fn_80167FE4(object, input, reverse);
    composite->second_values = fn_8016B5CC(object, 0,
                                            n * sizeof(void*),
                                            lbl_8024FAF4, 148);
    for (i = 0; i < n; i++)
        composite->second_values[i] = fn_80168490(object, input, reverse);
}
