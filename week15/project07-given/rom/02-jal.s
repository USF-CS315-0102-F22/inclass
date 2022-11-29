main:
    li a1, 1
    nop
    nop
    li a2, 2
    nop
    nop
    jal first
    nop
    nop
    nop
    nop
    unimp      # end marker        
    nop
    nop
    nop
    nop

first:
    add a0, a1, a2
    nop
    nop
    addi a0, a0, 1
    nop
    nop
    ret
    nop
    nop
    nop
    nop
