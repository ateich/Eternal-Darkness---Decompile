typedef struct FragmentInfo {
    void *exception_info;
    void *toc;
    int active;
} FragmentInfo;

FragmentInfo fragmentinfo_8032C7A8;

int __register_fragment(void *exception_info, void *toc)
{
    int fragment_id;
    for (fragment_id = 0; fragment_id < 1; ++fragment_id) {
        FragmentInfo *fragment = &fragmentinfo_8032C7A8 + fragment_id;
        if (fragment->active == 0) {
            fragment->exception_info = exception_info;
            fragment->toc = toc;
            fragment->active = 1;
            return fragment_id;
        }
    }
    return -1;
}
