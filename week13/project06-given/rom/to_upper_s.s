.global to_upper_s

/*
    Convert character string to upper case
    a0 points to the original string
    a1 points to the destination
*/

to_upper_s:
    li t1, 'a'                  # li is pseudo for addi rd, zero, imm
    li t2, '{'

loop:
    lb t0, (a0)                 # t0 = *a0
    beq t0, zero, done          # t0 == '\0', stop loop
    blt t0, t1, next            # < 'a', don't change
    bge t0, t2, next            # > 'z', don't change

    addi t0, t0, -0x20          # t0 -= 32 (uppercase)

next:
    sb t0, (a1)                 # *dest = t0
    addi a0, a0, 1              # orig++
    addi a1, a1, 1              # dest++
    j loop                      # go again

done:
    sb zero, (a1)               # *dest = '\0'
    ret
