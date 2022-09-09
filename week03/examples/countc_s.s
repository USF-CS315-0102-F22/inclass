.global find_char_index_s

# a0 - char c
# a1 - char *str
# a2 - int start
# a3 - int len

# t0 - int i
# t1 - int rv

find_char_index_s:
    li t1, -1                # t1 (rv) = -1
    mv t0, a2                # t0 (i) = a2 (start)
    
find_char_index_loop:
    bge t0, a3, find_char_index_exit

    add t2, a1, t0           # t2 (addr) = a1 (str) + t0 (i)    
    lb t3, (t2)              # t3 = str[i]
    bne t3, a0, find_char_index_cont
    mv t1, t0                # t1 (tv) = t0 (i)
    j find_char_index_exit
find_char_index_cont:
    addi t0, t0, 1           # t0 (i) = t0 (i) + 1
    j find_char_index_loop
    
find_char_index_exit:
    mv a0, t1                # return value = t1 (rv)
    ret

.global count_char_s

# a0 - char c
# a1 - char *str
# a2 - int len

# t0 - int start
# t1 - int count
# t2 - int r;

count_char_s:
    addi sp, sp, -56
    sd ra, (sp)

    li t0, 0                     # t0 (start) = 0
    li t1, 0                     # t1 (count) = 0

count_char_loop:
    bge t0, a2, count_char_exit

    sd a0, 8(sp)                 # Save all used caller-saved regs
    sd a1, 16(sp)                # These are needed after we the call to
    sd a2, 24(sp)                # find_char_index_s
    sd a3, 32(sp)
    sd t0, 40(sp)
    sd t1, 48(sp)
   
    mv a3, a2                    # a3 (len) = a2 (len)
    mv a2, t0                    # a2 (start) = t0 (start)

    call find_char_index_s
    mv t2, a0                    # t2 (r) = a0 (return index)

    ld a0, 8(sp)
    ld a1, 16(sp)
    ld a2, 24(sp)
    ld a3, 32(sp)
    ld t0, 40(sp)
    ld t1, 48(sp)

    li t3, -1
    beq t2, t3, count_char_exit  # if t2 (r) == -1, exit
    addi t1, t1, 1               # t1 (count) = t1 (count) + 1
    addi t0, t2, 1               # t0 (start) = t2 (r) + 1
    j count_char_loop

count_char_exit:

    mv a0, t1            # return value = t1 (count)
    ld ra, (sp)
    addi sp, sp, 56
    ret
