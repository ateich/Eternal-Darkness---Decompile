/* NonMatching: size-exact binary search. GC/1.2.5n rotates the low, high, and
 * middle live ranges through r29, r28, and r30 instead of retail r30, r29,
 * and r28; control flow, scheduling, and all other registers are exact. */
void* fn_801CC370(const void* key, const void* base, int count, int width,
                  int (*compare)(const void*, const void*))
{
    register int middle;
    register int low;
    register int high;
    const char* element;
    int result;

    if (count != 0) {
        low = 1;
        high = count;
        do {
            middle = (low + high) >> 1;
            element = (const char*)base + width * (middle - 1);
            result = compare(key, element);
            if (result == 0) {
                return (void*)element;
            }
            if (result < 0) {
                high = middle - 1;
            } else {
                low = middle + 1;
            }
        } while (low <= high);
    }
    return 0;
}
