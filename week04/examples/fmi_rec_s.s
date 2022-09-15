.global fmi_rec_s

# Recursive find_max_index (fmi)
# Note that this recursive function is
# tail recursive be no caller-saved registers
# need to be restored from the stack

# a0 - int *arr
# a1 - int len
# a2 - int i
# a3 - int max_i

# t0 - int new_max

fmi_rec_s:
    addi sp, sp, -8     # Allocate one double word
    sd ra, (sp)         # Save return address (ra)

    mv t0, a3           # t0 (new_max) = a3 (max_i)

    blt a2, a1, fmi_rec_else
                        # Base case
    mv a0, a3           # Return a3 (max_i)
    j fmi_rec_exit      # Jump to exit

fmi_rec_else:
                        # Recursive step
    li t1, 4            # t1 = 4
    mul t1, a2, t1      # t1 = (i * 4)
    add t1, a0, t1      # t1 = a0 (arr) + (i * 4)
    lw t1, (t1)         # t1 = arr[i]

    li t2, 4            # t2 = 4
    mul t2, a3, t2      # t2 = (max_i * 4)
    add t2, a0, t2      # t2 = a0 (arr) + (i * 4)
    lw t2, (t2)         # t2 = arr[max_i]

    ble t1, t2, fmi_rec_max_skip
    mv t0, a2           # t0 (new_max) = a2 (i)

fmi_rec_max_skip:
    addi a2, a2, 1      # a2 (i) = a2 (i) + 1
    mv a3, t0           # a3 (max_i) = t0 (new_max)

    call fmi_rec_s

fmi_rec_exit:
    ld ra, (sp)         # Restore return address (ra)
    addi sp, sp, 8      # Deallocate stack space
    ret


.global fmi_rectail_s

# See the following version of fmi_rec_s in which
# we apply the tail recursion optimiation to turn
# recursion into a loop. Pretty neat.

# a0 - int *arr
# a1 - int len
# a2 - int i
# a3 - int max_i

# t0 - int new_max

fmi_rectail_s:
    #addi sp, sp, -8    # We are only using caller save regs
    #sd ra, (sp)        # since this is now a loop, no need to save
    mv t0, a3           # t0 (new_max) = a3 (max_i)

    blt a2, a1, fmi_rectail_else
    mv a0, a3
    j fmi_rectail_exit

fmi_rectail_else:
    li t1, 4            # t1 = 4
    mul t1, a2, t1      # t1 = (i * 4)
    add t1, a0, t1      # t1 = a0 (arr) + (i * 4)
    lw t1, (t1)         # t1 = arr[i]

    li t2, 4            # t2 = 4
    mul t2, a3, t2      # t2 = (max_i * 4)
    add t2, a0, t2      # t2 = a0 (arr) + (i * 4)
    lw t2, (t2)         # t2 = arr[max_i]

    ble t1, t2, fmi_max_skip
    mv t0, a2           # t0 (new_max) = a2 (i)

fmi_max_skip:
    addi a2, a2, 1      # a2 (i) = a2 (i) + 1
    mv a3, t0           # a3 (max_i) = t0 (new_max)

    #call fmi_rec_s     # Can now just jump instead of call
    j fmi_rectail_s

fmi_rectail_exit:
    #ld ra, (sp)
    #addi sp, sp, 8     # Can just return
    ret
