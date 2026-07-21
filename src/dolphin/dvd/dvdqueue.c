typedef int BOOL;
typedef int s32;
typedef unsigned int u32;

typedef struct DVDCommandBlock DVDCommandBlock;
struct DVDCommandBlock {
    DVDCommandBlock* next;
    DVDCommandBlock* prev;
};

typedef struct DVDQueue {
    DVDCommandBlock* next;
    DVDCommandBlock* prev;
} DVDQueue;

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL enabled);

static DVDQueue WaitingQueue[4];

void __DVDClearWaitingQueue(void)
{
    u32 i;

    for (i = 0; i < 4; i++) {
        DVDCommandBlock* q;

        q = (DVDCommandBlock*)&WaitingQueue[i];
        q->next = q;
        q->prev = q;
    }
}

BOOL __DVDPushWaitingQueue(s32 prio, DVDCommandBlock* block)
{
    BOOL enabled;
    DVDCommandBlock* q;

    enabled = OSDisableInterrupts();
    q = (DVDCommandBlock*)&WaitingQueue[prio];
    q->prev->next = block;
    block->prev = q->prev;
    block->next = q;
    q->prev = block;
    OSRestoreInterrupts(enabled);
    return 1;
}

static DVDCommandBlock* PopWaitingQueuePrio(s32 prio)
{
    DVDCommandBlock* tmp;
    BOOL enabled;
    DVDCommandBlock* q;

    enabled = OSDisableInterrupts();
    q = (DVDCommandBlock*)&WaitingQueue[prio];
    tmp = q->next;
    q->next = tmp->next;
    tmp->next->prev = q;
    OSRestoreInterrupts(enabled);
    tmp->next = 0;
    tmp->prev = 0;
    return tmp;
}

DVDCommandBlock* __DVDPopWaitingQueue(void)
{
    u32 i;
    BOOL enabled;
    DVDCommandBlock* q;

    enabled = OSDisableInterrupts();
    for (i = 0; i < 4; i++) {
        q = (DVDCommandBlock*)&WaitingQueue[i];
        if (q->next != q) {
            OSRestoreInterrupts(enabled);
            return PopWaitingQueuePrio((s32)i);
        }
    }
    OSRestoreInterrupts(enabled);
    return 0;
}

BOOL __DVDCheckWaitingQueue(void)
{
    u32 i;
    BOOL enabled;
    DVDCommandBlock* q;

    enabled = OSDisableInterrupts();
    for (i = 0; i < 4; i++) {
        q = (DVDCommandBlock*)&WaitingQueue[i];
        if (q->next != q) {
            OSRestoreInterrupts(enabled);
            return 1;
        }
    }
    OSRestoreInterrupts(enabled);
    return 0;
}
