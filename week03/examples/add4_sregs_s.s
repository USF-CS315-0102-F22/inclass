# a0 - int a
# a1 - int b
# a2 - int c
# a3 - int d

# t0 - int r1
# t1 - int r2

# This version uses a callee-saved registers, s0 and s1 for
# the intermediate values. These must be preserved on entry
# to the function, and restored on exit because they are callee
# saved.

add4_saved_s:
    addi sp, sp, -40   # Allocate 40 / 8 = 5 double words
    sd ra, 0(sp)       # Save ra
    sd s0, 8(sp)       # Save s0
    sd s1, 16(sp)      # Save s1
    sd s2, 24(sp)
    sd s3, 32(sp)

    mv s2, a2
    mv s3, a3
    call add2_s
    mv s0, a0          # s0 = a0 (a + b)

    mv a0, s2
    mv a2, s3
    call add2_s
    mv s1, a0          # s1 = a0 (c + d)

    mv a0, s0          # a0 (a) = s0 (a + b)
    mv a1, s1          # a1 (b) = s1 (c + d)
    call add2_s

    ld s0, 8(sp)       # Restore s0
    ld s1, 16(sp)      # Restore s1
    ld s2, 24(sp)
    ld s3, 32(sp)
    ld ra, (sp)        # Restore ra
    addi sp, sp, 40    # Dealloate stack space
    ret 
