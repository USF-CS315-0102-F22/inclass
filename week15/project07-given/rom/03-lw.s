main:
    li a1, 1
    li a2, 2
    add a0, a1, a2
    addi a0, a0, 1
    li t0, 0
    li t1, 99
    sw t1, (t0)
    lw t1, (t0)
    add a0, t1, 1      # a0 should be 100
    unimp              # end marker
    nop
    nop
    nop
    nop
