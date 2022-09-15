.global countc_rec_s

# a0 - char c
# a1 - char *str

# t0 - char first_ch (str[0])
# 

countc_rec_s:
    addi sp, sp, -24   # Allocate 3 double words on stack
    sd ra, (sp)        # Save return address (ra)

    lb t0, (a1)        # t0 = str[0]

    bne t0, zero, countc_rec_else
                       # Base case
    mv a0, zero        # Return 0
    j countc_rec_exit  # Jump to exit

countc_rec_else:
                       # Recursive step

    sd a0, 8(sp)       # Save a0 (caller-saved)
    sd t0, 16(sp)      # Save t0 (caller-saved)
        
    addi a1, a1, 1     # a1 = (str + 1)
    call countc_rec_s

    ld t1, 8(sp)       # Restore previous a0 into t1
                       # So we do not overwrite a0 from call 
    ld t0, 16(sp)      # Restore t0

    bne t0, t1, countc_rec_exit
                       # is t0 (first_ch) == c (a0)
    addi a0, a0, 1     # a0 (rv) = a0 (rv) + 1

countc_rec_exit:
    ld ra, (sp)        # Restore return address (ra)
    addi sp, sp, 24    # Deallocate stack space
    ret 
