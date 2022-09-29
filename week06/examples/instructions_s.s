.global instructions_s

instructions_s:
    add a0, a0, a1
    add t0, t1, t3
    addi a0, a0, 99
    addi t0, t0, -2
    sd a0, 8(sp)
    ld t0, 8(sp)
    beq a0, t0, label 
label:
    lui t0, 0x12345
    auipc ra, 0x0
    jal ra, instruction_s
    call instruction_s
    jalr zero, ra, 0
    ret
