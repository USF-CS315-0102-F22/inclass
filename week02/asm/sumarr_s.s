.global sumarr_s

# a[] - a0
# len - a1
# sum - t0
# i   - t1

sumarr_s:
    li t0, 0           # sum = 0
    li t1, 0           # i = 0
loop:
    beq t1, a1, done   # i == len ?
    lw t2, (a0)        # t2 == a[i]
    add t0, t0, t2     # sum == sum + t2
    addi t1, t1, 1     # i = i + 1
    add a0, a0, 4      # a0 = a0 + 4
    j loop            
done:
    mv a0, t0          # a0 = sum
    ret
