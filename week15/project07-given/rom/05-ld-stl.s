main:
    li a0, 0
    li a1, 1
    sd a1, (a0)
    ld a2, (a0)
    addi a0, a2, 1      # a0 should be 2
    unimp               # marker instruction
