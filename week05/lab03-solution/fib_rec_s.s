.global fib_rec_s

# a0 - int n

fib_rec_s:
    addi sp, sp, -24
    sd ra, (sp)

    li t0, 1
    ble a0, t0, fib_rec_exit

fib_rec_step:

    sd a0, 8(sp)
    addi a0, a0, -1
    call fib_rec_s

    sd a0, 16(sp)
    ld a0, 8(sp)
    
    addi a0, a0, -2
    call fib_rec_s

    ld t0, 16(sp)
    add a0, t0, a0

fib_rec_exit:
    ld ra, (sp)
    addi sp, sp, 24
    ret
