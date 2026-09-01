typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Entry Entry;
struct Entry {
    u8 state;
    u8 type;
    u8 channels;
    u8 rate;
    u32 id;
    Entry* first;
    Entry* second;
    u8 padding10[64];
    void* stream;
    u8 padding54[48];
};

extern Entry lbl_8060B430[];
extern void fn_801ADC08(void);
extern void fn_801ADBC0(void);
extern u32 fn_801ADAF8(u32);
extern u32 fn_801A9B94(u32, u32);
extern void fn_801BA94C(void*, u32, u32, u32, u32, u32);

void fn_801AE91C(u32 id, u8 type, int channels, int rate)
{
    int rate_arg = rate;
    u32 id_arg = id;
    int channels_arg = channels;
    u32 index;
    Entry* entry;
    u32 format;
    u8 selected_channels;
    u8 selected_rate;

    fn_801ADC08();
    index = fn_801ADAF8(id_arg);
    if (index != -1) {
        entry = &lbl_8060B430[index];
        if (channels_arg == -1) {
            selected_channels = entry->channels;
        } else {
            selected_channels = channels_arg;
        }
        if (rate_arg == -1) {
            selected_rate = entry->rate;
        } else {
            selected_rate = rate_arg;
        }

        entry->type = type;
        entry->channels = selected_channels;
        entry->rate = selected_rate;
        format = fn_801A9B94(entry->type, 2);
        fn_801BA94C(entry->stream, format, entry->channels, entry->rate, 0, 0);

        if (entry->first != 0) {
            entry->first->type = type;
            format = fn_801A9B94(entry->first->type, 2);
            fn_801BA94C(entry->first->stream, format, entry->first->channels,
                        entry->first->rate, 0, 0);
        } else if (entry->second != 0) {
            entry->second->type = type;
            format = fn_801A9B94(entry->second->type, 2);
            fn_801BA94C(entry->second->stream, format, entry->second->channels,
                        entry->second->rate, 0, 0);
        }
    }
    fn_801ADBC0();
}
