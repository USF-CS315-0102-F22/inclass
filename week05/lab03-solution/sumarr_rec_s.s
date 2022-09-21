.global sumarr_rec_s

# a0 - int *arr
# a1 - int start
# a2 - int end

sumarr_rec_s:
    addi sp, sp, -24
    sd ra, (sp)

    li t0, 4
    mul t0, t0, a1
    add t0, a0, t0
    lw t2, (t0)

    bne a1, a2, sumarr_rec_step
    mv a0, t2
    j sumarr_rec_exit

sumarr_rec_step:

    sd t2, 8(sp)
    addi a1, a1, 1
    call sumarr_rec_s

    ld t2, 8(sp)
    add a0, t2, a0

sumarr_rec_exit:
    ld ra, (sp)
    addi sp, sp, 24
    ret
