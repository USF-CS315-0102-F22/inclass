PROG = lab04
OBJS = lab04.o rv_emu.o\
	   quadratic_c.o quadratic_s.o\
	   max3_c.o max3_s.o\
       get_bitseq_c.o get_bitseq_s.o\
       midpoint_c.o midpoint_s.o
HEADERS = rv_emu.h bits.h

CFLAGS = -g -Wall

%.o : %.c $(HEADERS)
	gcc $(CFLAGS) -c -o $@ $<

%.o : %.s $(HEADERS)
	as -g -o $@ $<

all : $(PROG)

$(PROG) : $(OBJS)
	gcc $(CFLAGS) -o $@ $(OBJS)

clean :
	rm -rf $(PROG) $(OBJS)
