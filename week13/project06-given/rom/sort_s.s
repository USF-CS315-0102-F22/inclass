.global find_max_index_s
.global sort_s

/* sort_s sorts an array of 32-bit integers in-place,
   in descending order
    a0 is the address of the array
    a1 is the length of the array
*/

sort_s:                 # prologue
    add sp, sp, -56     # allocate stack space
    sd ra, (sp)         # save return addr

    li t0, 0            # t0 is loop index i
    mv t1, a0           # t1 is &arr[i]
                        # t2 will be arr[i]
    li t3, 0            # t3 is idx
    mv t4, a0           # t4 is &arr[idx]
                        # t5 will be arr[idx]
loop:
    bge t0, a1, done    # reached arr len?

    sd t0, 8(sp)        # save regs written by fmi_s
    sd t1, 16(sp)
    sd t2, 24(sp)
    sd t3, 32(sp)
    sd a0, 40(sp)
    sd a1, 48(sp)

    mv a0, t1           # set up len - i in a0
    sub a1, a1, t0
    jal find_max_index_s
    mv t6, a0           # save off ret val

    ld a1, 48(sp)       # restore saved regs
    ld a0, 40(sp)
    ld t3, 32(sp)
    ld t2, 24(sp)
    ld t1, 16(sp)
    ld t0, 8(sp)

    add t3, t6, t0      # idx
    sll t6, t3, 2       # offset
    add t4, a0, t6      # &arr[idx]
    lw t2, (t1)         # arr[i]
    lw t5, (t4)         # arr[idx]
    blt t5, t2, next    # swap on GE (EQ unnecessary?)
    sw t2, (t4)         # arr[idx] = arr[i]
    sw t5, (t1)         # arr[i] = arr[idx]

next:
    addi t0, t0, 1      # i++
    addi t1, t1, 4      # walk &arr[i]
    j loop              # go again

done:                   # epilogue
    ld ra, (sp)         # restore return addr
    add sp, sp, 56      # deallocate
    ret
