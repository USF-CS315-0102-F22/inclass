.global ifelse_s

# I create a legend to map registers to C variables
# a0 - val
# t0 - retval

ifelse_s:    
    # if (val > 0) {
    # We need to reverse the notion of the condition
    # to branch if val <= 0
    ble a0, zero, else
    li t0, 1
    j done
else: 
    li t0, 0
    # Here we just fall through to the mv instruction
done:
    mv a0, t0
    ret 
