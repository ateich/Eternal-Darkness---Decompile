typedef unsigned int u32;

static void __OSDBIntegrator(void)
{
    register u32 link;
    volatile u32* debugger = (volatile u32*)0x40;

    /* ASM: mflr captures the incoming exception link, which MWCC cannot express in C. */
    asm { mflr link }
    debugger[3] = link;
    link = debugger[2] | 0x80000000;
    /* ASM: mtlr installs the debugger handoff address, which MWCC cannot express in C. */
    asm { mtlr link }
    link = 0x30;
    /* ASM: mtmsr establishes the debugger machine state, which MWCC cannot express in C. */
    asm { mtmsr link }
}
