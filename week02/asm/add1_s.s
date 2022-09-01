# The .global directive makes the add1_s label public
# This allow code in other files call this function.
.global add1_s

# add1_s is a label. In this case it designates the beginning
# of a function.
add1_s:
    addi a0, a0, 1
    # The return value is in a0
    ret
