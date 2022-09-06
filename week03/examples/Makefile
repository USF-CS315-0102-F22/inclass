PROGS = sumarr sizes

SUMARR_OBJS = sumarr.o sumarr_c.o sumarr_s.o
SIZES_OBJS = sizes.o

all : $(PROGS)

%.o : %.c
	gcc -c -g -o $@ $<

%.o : %.s
	as -g -o $@ $<

sumarr : $(SUMARR_OBJS)
	gcc -g -o $@ $^

sizes : $(SIZES_OBJS)
	gcc -g -o $@ $^


clean :
	rm -rf $(PROGS) $(SUMARR_OBJS) $(SIZES_OBJS)
