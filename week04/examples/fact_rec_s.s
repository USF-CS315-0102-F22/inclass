.global fact_rec_s

# This version uses saves caller-saved a0 on stack

# a0 - n

fact_rec_s:
    addi sp, sp, -16  # Allocate 2 double words
    sd ra, (sp)       # Save return address (ra)

    bne a0, zero, fact_rec_else
                      # Base case
    li a0, 1          # Set return value to 1
    j fact_rec_exit       # Jump to exit

fact_rec_else:        # Recursive step
    sd a0, 8(sp)      # Save a0 (n) on stack
    addi a0, a0, -1   # a0 = a0 (n) - 1
    call fact_rec_s
    ld t0, 8(sp)      # Restore n from stack
    mul a0, a0, t0    # a0 = fact(n - 1) * n

fact_rec_exit:
    ld ra, (sp)       # Restore return address (ra)
    addi sp, sp, 16   # Deallocate stack space
    ret


# Alternate version of fact_rec_s using callee-saved
# register, s0

.global fact_rec2_s

# a0 - n

fact_rec2_s:
    addi sp, sp, -16  # Allocate 2 double words
    sd ra, (sp)       # Save return address (ra)
    sd s0, 8(sp)      # Save s0 on stack

    bne a0, zero, fact_rec2_else
                      # Base case
    li a0, 1          # Set return value to 1
    j fact_rec2_exit  # Jump to exit

fact_rec2_else:        # Recursive step
    mv s0, a0         # Save a0 in s0
    addi a0, a0, -1   # a0 = a0 (n) - 1
    call fact_rec2_s
    mul a0, a0, s0    # a0 = fact(n - 1) * n

fact_rec2_exit:
    ld s0, 8(sp)      # Restore s0 from stack
    ld ra, (sp)       # Restore return address (ra)
    addi sp, sp, 16   # Deallocate stack space
    ret
