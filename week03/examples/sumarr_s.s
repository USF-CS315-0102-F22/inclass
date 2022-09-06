.global sumarr_ptr_s

# a0 - int *arr
# a1 - int len
#
# t0 - i
# t1 - sum
# t2 - element

sumarr_ptr_s:
    li t0, 0                     # t0 (i) = 0
    li t1, 0                     # t1 (sum) = 0

sumarr_ptr_loop:
    bge t0, a1, sumarr_ptr_exit
    lw t2, (a0)
    add t1, t1, t2
    addi t0, t0, 1
    addi a0, a0, 4
    j sumarr_ptr_loop

sumarr_ptr_exit:
    mv a0, t1
    ret

.global sumarr_index_s

# a0 - int *arr
# a1 - int len
#
# t0 - i
# t1 - sum
# t2 - element
# t3 - 4
# t4 - addr

sumarr_index_s:
    li t0, 0                     # t0 (i) = 0
    li t1, 0                     # t1 (sum) = 0
    li t3, 4

sumarr_index_loop:
    bge t0, a1, sumarr_index_exit
    mul t4, t0, t3               # t4 = t0 (i) * t3 (4)
    add t4, a0, t4               # t4 = a0 (arr) + t4
    lw t2, (t4)
    add t1, t1, t2
    addi t0, t0, 1
    j sumarr_index_loop

sumarr_index_exit:
    mv a0, t1
    ret
