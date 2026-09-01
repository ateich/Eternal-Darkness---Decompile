typedef unsigned char u8;

typedef struct Entry {
    u8 pad000[0x15c];
    int owner;
    u8 pad160[0x19];
    u8 rank;
    u8 state;
    u8 pad17b[3];
    u8 count;
    u8 pad17f[5];
} Entry;

extern Entry lbl_8060B5E0[];
extern void fn_801B0E68(int);

int fn_801AFCC8(int owner_arg, int wanted_arg, u8 limit_arg, int increment,
                Entry** choices_arg, Entry** special_arg)
{
    int first_rank = 7;
    int second_rank = 7;
    int result = 0;
    Entry* entry = lbl_8060B5E0;
    int remaining = 3;
    int total = 0;
    int found = 0;
    Entry** special = special_arg;
    Entry** choices = choices_arg;
    u8 limit = limit_arg;
    int wanted = wanted_arg;
    int owner = owner_arg;

    choices[0] = 0;
    choices[1] = 0;
    *special = 0;
    if (increment != 0) {
        limit++;
    }

    {
    for (owner_arg = 0; owner_arg < 4; owner_arg++, entry++) {
        switch (entry->state) {
        case 0:
        case 1:
          break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
          if (entry->owner != owner) {
            remaining -= entry->count;
            if (entry->rank < limit) {
                total += entry->count;
                if (entry->count == 2) {
                    if (found == 1) {
                        fn_801B0E68(12);
                    }
                    found = 1;
                    *special = entry;
                }
                if (first_rank > entry->rank && first_rank >= second_rank) {
                    first_rank = entry->rank;
                    choices[0] = entry;
                } else if (second_rank > entry->rank) {
                    second_rank = entry->rank;
                    choices[1] = entry;
                }
            }
          }
          break;
        }
    }
    }

    if (remaining >= wanted) {
        *special = 0;
        choices[1] = 0;
        choices[0] = 0;
        result = 1;
    } else if (wanted == 1) {
        if (first_rank == 1) {
            *special = 0;
            choices[1] = 0;
            result = 1;
        } else if (second_rank == 1) {
            *special = 0;
            choices[0] = 0;
            result = 1;
        } else if (found != 0) {
            choices[1] = 0;
            choices[0] = 0;
            result = 1;
        } else if (first_rank < second_rank) {
            choices[1] = 0;
            result = 1;
        } else if (second_rank < 7) {
            choices[0] = 0;
            result = 1;
        } else {
            *special = 0;
            choices[1] = 0;
            choices[0] = 0;
        }
    } else if (remaining == 1 && first_rank == 1) {
        *special = 0;
        choices[1] = 0;
        result = 1;
    } else if (remaining == 1 && second_rank == 1) {
        *special = 0;
        choices[0] = 0;
        result = 1;
    } else if (first_rank == 1 && second_rank == 1) {
        *special = 0;
        result = 1;
    } else if (remaining == 1 && found != 0) {
        choices[1] = 0;
        choices[0] = 0;
        result = 1;
    } else if (total >= 2) {
        if (found != 0) {
            if (choices[0] == *special) {
                if (choices[1] != 0) {
                    choices[0] = 0;
                    result = 1;
                } else {
                    *special = 0;
                    result = 1;
                }
            } else if (choices[1] == *special) {
                if (choices[0] != 0) {
                    choices[1] = 0;
                    result = 1;
                } else {
                    *special = 0;
                    result = 1;
                }
            } else if (first_rank < second_rank) {
                choices[1] = 0;
            } else if (second_rank < 7) {
                choices[0] = 0;
            } else {
                result = 0;
            }
        } else if (choices[0] != 0 && choices[1] != 0) {
            result = 1;
        } else {
            result = 0;
        }
    } else {
        *special = 0;
        choices[1] = 0;
        choices[0] = 0;
        result = 0;
    }
    return result;
}
