extern unsigned int OSGetTick(void);

void fn_80145408(unsigned int ticks)
{
    unsigned int start = OSGetTick();
    unsigned int end = start + ticks;
    unsigned int now;

    if (start <= end) {
        do {
            now = OSGetTick();
        } while (start <= now && now <= end);
    } else {
        do {
            now = OSGetTick();
        } while (now <= end || start <= now);
    }
}
