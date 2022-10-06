.global merge_s

/* merge_s merges two adjacent sub arrays of 32-bit ints
    a0 is the array
    a1 is the aux array
    a2 is the start index
    a3 is the end index
*/

.align 4
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
    blt a3, t2, done            # end < i?
    lw t3, (t1)                 # t3 is aux[i]
    sw t3, (t0)                 # arr[i] = aux[i]
    addi t0, t0, 4              # walk arr to next 32-bit int
    addi t1, t1, 4              # walk aux to next 32-bit int
    addi t2, t2, 1              # i++
    j copy_loop

done:
    ret
