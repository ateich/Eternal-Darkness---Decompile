typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct SlotSet { u8 count; u8 pad1[3]; u16 mask; u16 active; u8 pad8[0x80]; void* objects[16]; } SlotSet;
extern void *fn_80156938(); extern u32 fn_80193860(void*); extern void fn_801938C8(void*,u8);
extern int fn_8017FD98(void*); extern void fn_801938D8(void*,u32); extern void fn_8017FD6C(void*);
extern int fn_801562DC(void*); extern u8 fn_80193870(void*); extern u8 fn_80193888(void*);
extern u8 fn_80193878(void*); extern u8 fn_80193868(void*); extern void fn_801938B8(void*,u8);
extern void fn_801938B0(void*,u8); extern unsigned int fn_800FBFB0(); extern void fn_8017FE1C(void*,void*);
#define fn_800FBFB0() ((int)fn_800FBFB0())
extern void fn_801939DC(void); extern u8 fn_80193890(void*); extern void fn_801938C0(void*,u8);
extern u8 fn_80193898(void*); extern u8 fn_80193858(void*); extern void* fn_8017FDE4(void*);
extern void fn_8014B454(void*,void*,u8,int,int); extern u8 fn_80193850(void*); extern void* fn_801938A8(void*);
extern int fn_80157034(void*);

void fn_8014A6BC(void* left, void* right) {
    SlotSet* rs = fn_80156938(right); SlotSet* ls = fn_80156938(left);
    void* source = rs->objects[0]; u32 sourceFlags = source ? fn_80193860(source) : 0x40000;
    u16 bit; int i;
    for (i=0,bit=1;i<ls->count;i++,bit<<=1) {
        void* o; u32 flags;
        if (!(ls->mask & bit) || !(o=ls->objects[i])) continue;
        flags=fn_80193860(o);
        if (sourceFlags & 0x40000) { ls->active=1; fn_801938C8(o,0); if(fn_8017FD98(o)) fn_801938D8(o,(flags|0x40000)&~0x400); else { fn_8017FD6C(o); ls->mask&=~bit; } }
        else if (!fn_801562DC(left)) {
            u8 low=fn_80193870(source), high=fn_80193888(source), state=fn_80193878(o);
            if (!state) { state=fn_80193868(o); if (!state) { int changed=0;
                if(flags&1){fn_801938B8(o,0);fn_801938B0(o,2);changed=1;}
                else if(flags&2){int span=(u8)high-4;u8 first=fn_800FBFB0()%span;if(low>=first){fn_801938B8(o,first);fn_801938B0(o,first+fn_800FBFB0()%(span-first)+2);changed=1;}}
                else if(flags&4){u8 first=(u8)(high-5);if(low>=first){fn_801938B8(o,first);fn_801938B0(o,(u8)(high-3));changed=1;}}
                if(changed){fn_8017FE1C(o,fn_801939DC);state=fn_80193890(o);} fn_801938C0(o,state); fn_801938C8(o,fn_80193898(o));
            } else fn_801938C0(o,state-1); } else fn_801938C8(o,state-1);
        }
        if(source && fn_8017FD98(o)){u8 v=fn_80193858(o);void* p=fn_8017FDE4(o);fn_8014B454(source,p,v,0,0);v=fn_80193850(o);p=fn_801938A8(o);fn_8014B454(source,p,v,0,0);}
    }
    if(fn_80157034(right)){ls->active=1;for(i=0,bit=1;i<ls->count;i++,bit<<=1){void* o;if((ls->mask&bit)&&(o=ls->objects[i])){fn_8017FD6C(o);ls->mask&=~bit;}}}
}
