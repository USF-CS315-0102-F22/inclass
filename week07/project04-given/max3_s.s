.global max3_s

# Return the max of a0 and a1
max2_s:
    bge a0, a1, done        # if taken, a0 is already the max
    mv a0, a1               # not taken so a1 is the max
done:
    ret

/* max3_s returns max of
    a0 = a
    a1 = b
    a2 = c
*/

max3_s:
                            # prologue
    addi sp, sp, -8         # rv64 regs are 8 bytes
    sd ra, (sp)             # rv64 SW is 4 bytes, SD is 8 bytes

    jal max2_s
    mv a1, a0               # a1 = max2(a0, a1)
    mv a0, a2               # set up c in a0
    jal max2_s              # max of a,b and c is in a0

                            # epilogue
    ld ra, (sp)             # LD gets 8 bytes from SP + 0
    addi sp, sp, 8
    ret
