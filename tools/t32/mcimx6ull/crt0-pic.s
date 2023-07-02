.section .text.crt
.globl  _start
.globl  _exit.crt0
.globl  watchdogTrigger

#ifdef __thumb__
# define subs sub
# define adds add
#endif

_start:
    /* get current PC , in R7 */
    bl     _start_pc
_start_pc:
    /* get PC from LR and correct it, used as PIC pointer r7+r9 onwards */
    mov    r7, lr
    mov    r0, #1
    bic    r7, r7, r0
    ldr    r0, .BASE
    subs   r7, r7, r0
    mov    r9, r7

    /* check for detailed relocation info and relocate */
    bl     relocate

    /* set stack and frame pointer */
    ldr    r1, .SP
    add    r1, r7
    mov    r0, #7
    bic    r1, r0
    mov    r0, #0
    mov    sp, r1
    mov    fp, r0

    /* clear .bss-section */
    ldr    r4, .BSS_S
    ldr    r5, .BSS_E
    mov    r0, #0
    b      bss_check
bss_clear:
    strb   r0, [r7, r4]
    add    r4, r4, #1
bss_check:
    cmp    r5, r4
    bne    bss_clear
bss_done:

    /* correct global-offset-table, .got */
    /* correct data with relocations, .data.rel - with limitations */
    ldr    r4, .RELOC_S
    ldr    r5, .RELOC_E
    b      got_check
got:
    ldr    r3, [r7, r4]
    add    r3, r7
    str    r3, [r7, r4]
    add    r4, r4, #4
got_check:
    cmp    r5, r4
    bne    got
got_done:

    /* initialize Watchdog */
    ldr    r3, .WDG_INIT
    cmp    r3, #0
    beq    wdg_init_done
    add    r3, r7
    bl     crt0_veneer
wdg_init_done:
    /* register the WatchdogHook */
    ldr    r3, .WDG_TRIGGER
    ldr    r4, .WDG_HOOK
    cmp    r3, #0
    beq    wdg_hook_done
    add    r3, r7
wdg_hook_done:
    str    r3, [r7, r4]

    /* initialization of e.g. static objects */
    ldr    r4, .INIT_S
    ldr    r5, .INIT_E
    b      init_check
init:
    ldr    r3, [r7,r4]
    add    r3, r7
    bl     crt0_veneer
    add    r4, r4, #4
init_check:
    cmp    r5, r4
    bne    init
init_done:

gomain:
    ldr    r3, .MAIN
    add    r3, r7
    bl     crt0_veneer
    nop

_exit.crt0:
    b      _exit.crt0

crt0_veneer:
    /* make a THUMB/ARM generic veneer call to r3 */
    /* lr is set by preceding bl instruction      */
    mov    r0, #0
    mov    r1, #0
    bx     r3

.org     0xFC
_start_secondary:
    /* get current PC , in R7 */
    bl    _start_secondary_pc
    .align 1
_start_secondary_pc:
    /* get PC from LR and correct it - _start_secondary_pc-_start_pc = 0xfc = 0x80+0x7c */
    mov    r7, lr
    mov    r0, #1
    bic    r7, r7, r0
    ldr    r0, .BASE
    subs   r7, r7, r0
    subs   r7, r7, #0x80
    subs   r7, r7, #0x7c
    mov    r9, r7

    /* set stack and frame pointer */
    /* SP is placed 0xF0 bytes after SP of Core0 */
    ldr    r1, .SP
    add    r1, r7
    add    r1, r1, #0xf0
    mov    r0, #0
    mov    sp, r1
    mov    fp, r0
    ldr    r3, .BACKGROUND
    add    r3, r9
    bl     crt0_veneer
    nop
    b      _exit.crt0

.align  2
.BASE:
    .word RAMSTART+0x4+0x4
.SP:
    .word __stack_end
.BSS_S:
    .word __bss_start
.BSS_E:
    .word __bss_end
.INIT_S:
    .word __init_array_start
.INIT_E:
    .word __init_array_end
.RELOC_S:
    .word __simple_relocate_start
.RELOC_E:
    .word __simple_relocate_end
.DATA_S:
    .word __data_vaddr
.DATA_LADDR:
    .word __data_laddr
.DATA_SIZE:
    .word __data_size
#ifndef WATCHDOG
.WDG_INIT:
    .word 0x0
.WDG_TRIGGER:
    .word 0x0
#else
.WDG_INIT:
    .word WatchdogInit
.WDG_TRIGGER:
    .word WatchdogTrigger
#endif
.WDG_HOOK:
    .word watchdogTrigger
.MAIN:
    .word main
.BACKGROUND:
    .word background

relocate:
    ldr    r4, .REL_DYN_S
    ldr    r5, .REL_DYN_E
    cmp    r4, r5
    beq    relocate_done
    ldr    r6, .DYNSYM_S
    add    r4, r4, r7
    add    r5, r5, r7
    add    r6, r6, r7
    b relocate_check
relocate_do:
    ldr    r0, [r4]
    ldr    r1, [r7, r0]
    ldrb   r2, [r4, #4]
    cmp    r2, #23
    beq    relocate_fix_rel
    cmp    r2, #2
    beq    relocate_fix_abs
    b      _exit.crt0
relocate_fix_abs:
    ldr    r2, [r4, #4]
    lsr    r2, #4
    add    r2, r2, r6
    ldr    r2, [r2, #4]
    add    r1, r1, r2
    /* intended fall-through */
relocate_fix_rel:
    add    r1, r1, r7
    str    r1, [r7, r0]
relocate_next:
    add    r4, r4, #8
relocate_check:
    cmp    r4, r5
    bne    relocate_do
    mov    r7, #0
relocate_done:
    bx     r14
.align 2
.REL_DYN_S:
    .word _rel_dyn_start
.REL_DYN_E:
    .word _rel_dyn_end
.DYNSYM_S:
    .word _dynsym_start

.section .data
watchdogTrigger:
    .word 0x0

.section .text
.weak background
background:
1:
    b 1b
