# This file has three implementations of add4_s
#
# 1) Using caller-saved (t) registers for intermediate values
# 2) Using callee-saved (s) registers for intermediate values
# 3) Using the stack directly to preserve intermediate values

.global add4_s

# Note: add2_s does not call another function and only uses
#       caller-saved registers. So, no need to allocate stack
#       space.

# a0 - int a
# a1 - int b
add2_s:
    add a0, a0, a1
    ret
    
# a0 - int a
# a1 - int b
# a2 - int c
# a3 - int d

# t0 - int r1
# t1 - int r2

# This first saves caller-saved registers a0 and a1 across
# the first function call and uses t0 for the intermediate
# value, which mush be stored on the stack because it is
# caller saved. 
add4_temp_s:
    addi sp, sp, -24 # Allocate 24 bytes or 24 / 8 = 4 double words
    sd ra, 0(sp)     # Store ra at first slots 0(sp)

    sd a2, 8(sp)     # We need to preserve a2 and a3 just in case
    sd a3, 16(sp)    # add2_s were to modify these registers.
                     # All the a regs and t regs are caller-saved.


    call add2_s      # Note that a0 and a1 already have the first two args
    mv t0, a0        # t0 (r1) = a + b

    ld a0, 8(sp)     # Restore a2, put into a0
    ld a1, 16(sp)    # Restore a3, put into a1

    sd t0, 8(sp)     # We need to save t0 (caller saved)
    
    call add2_s
    mv t1, a0        # t1 (r2) = c + d
    ld t0, 8(sp)     # Restore previous t0

    mv a0, t0        # a0 (a) = t0 (r1)
    mv a1, t1        # a1 (b) = t1 (r2)
    call add2_s      # Note the return value will be in a0
    
    ld ra, (sp)      # Restore ra, becuase the calls above modified ra
    addi sp, sp, 24  # Deallocate the stack, must be the same amount
                     # allocated above with addi sp, sp, -24
    ret


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
    mv a1, s3
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

# a0 - int a
# a1 - int b
# a2 - int c
# a3 - int d

# t0 - int r1
# t1 - int r2

# This version uses the stack directly to store the
# intermediate value.
add4_s:
    addi sp, sp, -32  # Alloacte 32 / 8 = 4 double words
    sd ra, 0(sp)     # Save ra

    sd a2, 8(sp)     # Save a2
    sd a3, 16(sp)    # Save a3

    call add2_s
    sd a0, 24(sp)    # Put a + b onto the stack

    ld a0, 8(sp)     # a0 = a2
    ld a1, 16(sp)    # a1 = a3

    call add2_s
    mv t1, a0        # t1 = c + d
    ld t0, 24(sp)    # Restore t0

    mv a0, t0        # a0 = a + b
    mv a1, t1        # a1 = c + d
    call add2_s

    ld ra, (sp)      # Restore ra
    addi sp, sp, 32  # Deallocate stack space
    ret
