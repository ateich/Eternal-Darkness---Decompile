typedef struct FragmentInfo {
    void *exception_info;
    void *toc;
    int active;
} FragmentInfo;

extern FragmentInfo fragmentinfo_8032C7A8;

void __unregister_fragment(int fragment_id)
{
    FragmentInfo *fragment;
    if (fragment_id < 0) {
        return;
    }
    if (fragment_id >= 1) {
        return;
    }
    fragment = &fragmentinfo_8032C7A8 + fragment_id;
    fragment->exception_info = 0;
    fragment->toc = 0;
    fragment->active = 0;
}
