typedef struct Entry Entry;

extern Entry* fn_80158598(int, int);
extern int fn_80157E1C(void);
extern int fn_80157E24(Entry*, int);

int fn_801586FC(int value, int key)
{
    Entry* entry = fn_80158598(key, 0);
    int count;
    int index;
    int result;

    if (entry != 0) {
        count = fn_80157E1C();
        for (index = 0; index < count; index++) {
            result = fn_80157E24(entry, index);
            if (result != value)
                continue;
            return 1;
        }
    }
    return 0;
}
