.global strlen_ptr_s

# a0 - char *str

# t0 - int len

strlen_ptr_s:
    li t0, 0

strlen_ptr_loop:
    lb t1, (a0)          # t1 = *str, need to use lb to load a byte
    beq t1, zero, strlen_ptr_exit
    addi t0, t0, 1       # t0 (len) = t0 (len) + 1
    addi a0, a0, 1       # a0 (str) = a0 (str) + 1, go to next char
    j strlen_ptr_loop
strlen_ptr_exit:
    mv a0, t0            # a0 (return value) = t0 (len)
    ret

.global strlen_index_s

# a0 - char *str

# t0 - int len

strlen_index_s:
    li t0, 0

strlen_index_loop:
    add t1, a0, t0       # t1 = a0 (str) + t0 (len)
    lb t2, (t1)          # t1 = str[len]
    beq t2, zero, strlen_index_exit
    addi t0, t0, 1       # t0 (len) = t0 (len) + 1
     j strlen_index_loop
strlen_index_exit:
    mv a0, t0            # a0 (return value) = t0 (len)
    ret
