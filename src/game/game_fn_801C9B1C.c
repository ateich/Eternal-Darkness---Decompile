typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Voice Voice;
typedef struct Event Event;

struct Voice {
    char pad00[0x40];
    void* resource;
};

struct Event {
    Event* next;
    float key;
    float value2;
    float value3;
    float value4;
    float value5;
    Voice* voice;
};

typedef struct Bucket {
    void* resource;
    Event* first;
    Event* second;
    u16 count;
    u16 pad0E;
} Bucket;

typedef struct AudioState {
    char pad000[0x50];
    Bucket buckets[64];
    Event events[64];
} AudioState;

typedef struct BucketCursor {
    char pad000[0x50];
    Bucket bucket;
} BucketCursor;

typedef struct EventCursor {
    char pad000[0x450];
    Event event;
} EventCursor;

extern AudioState lbl_80629390;
extern u8 lbl_8064D4D3;
extern u8 lbl_8064D4D4;

int fn_801C9B1C(Voice* voice, float key, float value2, float value3,
                float value4, float value5)
{
    unsigned int work;
    long bucket_count;
    BucketCursor* cursor;
    AudioState* state;
    int index;
    Event* current;
    Event* previous;
    EventCursor* event_cursor;
    char* event_ptr;
    Event** first;

    state = &lbl_80629390;
    work = (unsigned int)state->buckets;
    bucket_count = lbl_8064D4D3;
    index = 0;

    {
        int remaining = bucket_count;
        while (remaining-- > 0) {
            if (voice->resource == ((Bucket*)work)->resource) {
                break;
            }
            work += sizeof(Bucket);
            index++;
        }
    }

    if (index == bucket_count) {
        if ((unsigned int)bucket_count == 64) {
            return 0;
        }
        cursor = (BucketCursor*)((char*)state + index * sizeof(Bucket));
        cursor->bucket.first = 0;
        cursor->bucket.second = 0;
        cursor->bucket.count = 0;
        cursor->bucket.resource = voice->resource;
        lbl_8064D4D3++;
    }

    cursor = (BucketCursor*)state;
    work = lbl_8064D4D4;
    if (work == 64) {
        return 0;
    }

    cursor = (BucketCursor*)((char*)cursor + index * sizeof(Bucket));
    first = &cursor->bucket.first;
    current = *first;
    if ((previous = current) != 0) {
        while ((current = previous->next) != 0) {
            if (previous->key < key) {
                break;
            }
            previous = current;
        }
        event_ptr = (char*)state + work * sizeof(Event);
        *(Event**)(event_ptr += 0x450) = current;
        previous->next = (Event*)event_ptr;
    } else {
        event_ptr = (char*)state + work * sizeof(Event);
        *(Event**)(event_ptr += 0x450) = current;
        *first = (Event*)event_ptr;
    }

    event_cursor = (EventCursor*)((char*)state + lbl_8064D4D4 * sizeof(Event));
    event_cursor->event.voice = voice;
    event_cursor->event.value5 = value5;
    event_cursor->event.value2 = value2;
    event_cursor->event.value3 = value3;
    event_cursor->event.value4 = value4;
    state->events[lbl_8064D4D4++].key = key;
    return 1;
}
