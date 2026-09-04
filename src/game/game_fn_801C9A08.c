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
    Bucket buckets[176];
    Event events[64];
} AudioState;

typedef struct BucketCursor {
    char pad000[0x50];
    Bucket bucket;
} BucketCursor;

extern AudioState lbl_80629390;
extern u8 lbl_8064D4D3;
extern u8 lbl_8064D4D5;

void fn_801C9A08(Voice* voice, float key)
{
    Bucket* bucket;
    BucketCursor* cursor;
    AudioState* state;
    int bucket_count;
    int index;
    Event* current;
    Event* previous;
    Event* event;
    Event** second;

    bucket_count = lbl_8064D4D3;
    state = &lbl_80629390;
    bucket = state->buckets;
    index = 0;

    {
        int remaining = bucket_count;
        while (remaining-- > 0) {
            if (voice->resource == bucket->resource) {
                break;
            }
            bucket++;
            index++;
        }
    }

    if (index == bucket_count) {
        cursor = (BucketCursor*)((char*)state + index * sizeof(Bucket));
        cursor->bucket.first = 0;
        cursor->bucket.second = 0;
        cursor->bucket.count = 0;
        cursor->bucket.resource = voice->resource;
        lbl_8064D4D3++;
    }

    cursor = (BucketCursor*)((char*)state + index * sizeof(Bucket));
    cursor->bucket.count++;
    previous = 0;
    second = &cursor->bucket.second;
    current = *second;
    while (current != 0) {
        if (current->key > key) {
            break;
        }
        previous = current;
        current = current->next;
    }

    if (previous == 0) {
        *second = &state->events[lbl_8064D4D5];
    } else {
        previous->next = &state->events[lbl_8064D4D5];
    }
    event = &state->events[lbl_8064D4D5];
    event->next = current;
    event->voice = voice;
    state->events[lbl_8064D4D5++].key = key;
}
