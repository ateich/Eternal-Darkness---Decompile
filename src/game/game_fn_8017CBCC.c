typedef unsigned char u8;
typedef struct Request { int kind; int state; int result; u8 value; } Request;
extern char lbl_802510D4[];
extern void fn_8017BA60();

void fn_8017CBCC(Request* request)
{
    __asm {
        lwz r4, 8(r3)
        cmpwi r4, -1
        beq done
        cmpwi r4, 0
        bne error
    }
    request->state = 2;
    goto done;
error:
    fn_8017BA60(lbl_802510D4);
    request->state = 2;
done:
    return;
}
