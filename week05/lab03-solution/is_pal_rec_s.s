.global pal_rec_s

# a0 - char *str
# a1 - int start
# a2 - int end

pal_rec_s:
    addi sp, sp, -8
    sd ra, (sp)

    blt a1, a2, pal_rec_2nd_if
    li a0, 1
    j pal_rec_exit

pal_rec_2nd_if:
    add t0, a0, a1
    lb t0, (t0)
    add t1, a0, a2
    lb t1, (t1)
    beq t0, t1, pal_rec_step
    li a0, 0
    j pal_rec_exit    

pal_rec_step:
    addi a1, a1, 1
    addi a2, a2, -1
    call pal_rec_s

pal_rec_exit:
    ld ra, (sp)
    addi sp, sp, 8
    ret
