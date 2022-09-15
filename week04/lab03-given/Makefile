PROGS = fib_rec sumarr_rec is_pal_rec

FIB_OBJS = fib.o fib_rec_c.o
SUM_OBJS = sumarr.o sumarr_rec_c.o
PAL_OBJS = is_pal.o is_pal_rec_c.o

OBJS = $(FIB_OBJS) $(SUM_OBJS) $(PAL_OBJS)

%.o: %.c
	gcc -c -g -o $@ $<

all: $(PROGS)

is_pal_rec: $(PAL_OBJS)
	gcc -g -o $@ $^

sumarr_rec: $(SUM_OBJS)
	gcc -g -o $@ $^

fib_rec: $(FIB_OBJS)
	gcc -g -o $@ $^

clean:
	rm -rf $(PROGS) $(OBJS)
