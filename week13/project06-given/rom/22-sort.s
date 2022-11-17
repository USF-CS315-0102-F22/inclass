main:
    li sp, 1024
    addi sp, sp, -32    # alloc 8 32-bit words
    li t0, 2
    sw t0, 0(sp)
    li t0, 8
    sw t0, 4(sp)
    li t0, 6
    sw t0, 8(sp)
    li t0, 4
    sw t0, 12(sp)
    li t0, 10
    sw t0, 16(sp)
    li t0, 12
    sw t0, 20(sp)
    add a0, zero, sp
    add s1, zero, sp    # save array addr
    li a1, 6
    jal sort_s

    li a0, 0            # pack the first two words into a0
    lw t0, 0(s1)
    sll t0, t0, 32
    or a0, a0, t0
    lw t0, 4(s1)
    or a0, a0, t0
    
    li a1, 0            # pack the second two words into a1
    lw t0, 8(s1)
    sll t0, t0, 32
    or a1, a1, t0
    lw t0, 12(s1)
    or a1, a1, t0
    
    li a2, 0            # pack the third two words into a2
    lw t0, 16(s1)
    sll t0, t0, 32
    or a2, a2, t0
    lw t0, 20(s1)
    or a2, a2, t0
    
    unimp

/* sort_s sorts an array of 32-bit integers in-place,
   in descending order
    a0 is the address of the array
    a1 is the length of the array
*/

/* find_max_index_s finds the index of the largest value
    a0 = array
    a1 = array length
*/

find_max_index_s:
    mv t3, zero                 # t3 is the loop index
    mv t0, zero                 # t0 is max index
    lw t1, (a0)                 # max val = first elem
fmi_loop:
    beq t3, a1, fmi_done        # reached the end of array
    lw t2, (a0)                 # t2 = *arr
    blt t2, t1, fmi_next        # if cur val < max val, go again
    mv t0, t3                   # max index = loop index
    mv t1, t2                   # max val = cur val

fmi_next:
    add t3, t3, 1               # increment loop index
    add a0, a0, 4               # walk arr to next 4 byte int
    j fmi_loop

fmi_done:
    mv a0, t0                   # set up return value
    ret

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
