main:
    li sp, 1024
    addi sp, sp, -32    # alloc 8 32-bit words
    li t0, 1
    sw t0, 0(sp)
    li t0, 3
    sw t0, 4(sp)
    li t0, 5
    sw t0, 8(sp)
    li t0, 2
    sw t0, 12(sp)
    li t0, 4
    sw t0, 16(sp)
    li t0, 6
    sw t0, 20(sp)
    add a0, zero, sp    # set up arr arg
    add s1, zero, sp    # save array addr
    addi sp, sp, -32    # alloc aux arr
    add a1, zero, sp    # set up aux arg
    li a2, 0            # set up start index arg
    li a3, 5            # set up end index arg
    jal merge_s

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

/* merge_s merges two adjacent sub arrays of 32-bit ints
    a0 is the array
    a1 is the aux array
    a2 is the start index
    a3 is the end index
*/

merge_s:
    add t0, a2, a3              # start + end
    srli t0, t0, 1              # mid = (start + end) / 2
    add t0, t0, 1               # mid + 1. mid not needed
    mv t1, a2                   # t1 is ptr_left
    mv t2, t0                   # ptr_right = mid + 1
    mv t3, a2                   # t3 is loop index variable
loop:
    bgt a3, t3, start_copy      # break if end > i
    slli t4, t3, 2              # t4 is the offset of i
    add t5, a1, t4              # t5 is &aux[i]

    slli a4, t2, 2              # a4 is the offset of ptr_right
    add a4, a0, a4              # a4 is &arr[ptr_right]
    lw a4, (a4)                 # a4 is arr[ptr_right]

    slli a5, t1, 2              # a5 is the offset of ptr_left
    add a5, a0, a5              # a5 is &arr[ptr_left]
    lw a5, (a5)                 # a5 is arr[ptr_left]

    bne t0, t1, ptr_right_limit
    sw a4, (t5)                 # aux[i] = arr[ptr_right]
    addi t2, t2, 1              # ptr_right++
    j next_loop

ptr_right_limit:
    addi a6, a3, 1              # end + 1
    bne t2, a6, ptr_left_smaller
    sw a5, (t5)                 # aux[i] = arr[ptr_left]
    addi t1, t1, 1              # ptr_left++
    j next_loop

ptr_left_smaller:
    bge a5, a4, ptr_right_smaller
    sw a5, (t5)                 # aux[i] = arr[ptr_left]
    addi t1, t1, 1              # ptr_left++
    j next_loop

ptr_right_smaller:
    sw a4, (t5)                 # aux[i] = arr[ptr_right]
    addi t2, t2, 1              # ptr_right++

next_loop:
    addi t3, t3, 1              # i++
    j loop

start_copy:                     # copy elements from aux/a1 to arr/a0
    mv t0, a0                   # t0 walks arr
    mv t1, a1                   # t1 walks aux
    mv t2, a2                   # t2 is start
    
copy_loop:
    blt a3, t2, merge_done      # end < i?
    lw t3, (t1)                 # t3 is aux[i]
    sw t3, (t0)                 # arr[i] = aux[i]
    addi t0, t0, 4              # walk arr to next 32-bit int
    addi t1, t1, 4              # walk aux to next 32-bit int
    addi t2, t2, 1              # i++
    j copy_loop

merge_done:
    ret

/* merge_sort_s recursively sorts arr
    a0 is arr
    a1 is aux
    a2 is start index
    a3 is end index
*/

merge_sort_s:
    addi sp, sp, -32            # prologue
    sd ra, (sp)

    ble a3, a2, done            # end <= start?
    add t0, a2, a3              # start + end
    srli t0, t0, 1              # mid = (start + end) / 2
    sd t0, 8(sp)                # preserve mid
    sd a2, 16(sp)               # preserve start
    sd a3, 24(sp)               # preserve end

    mv a3, t0                   # set up mid param
    jal merge_sort_s
    ld a2, 8(sp)                # restore mid
    addi a2, a2, 1              # set up mid + 1 param
    ld a3, 24(sp)               # restore end
    jal merge_sort_s

    ld a2, 16(sp)               # restore start
    ld a3, 24(sp)               # restore end
    jal merge_s

done:                           # epilogue
    ld ra, (sp)
    addi sp, sp, 32
    ret
