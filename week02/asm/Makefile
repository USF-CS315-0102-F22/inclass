PROGS = first_c first_s add1 ifelse sumarr
FIRSTC_OBJS = first_c.o
FIRSTS_OBJS = first_s.o
ADD1_OBJS = add1.o add1_c.o add1_s.o
IFELSE_OBJS = ifelse.o ifelse_c.o ifelse_s.o
SUMARR_OBJS = sumarr.o sumarr_c.o sumarr_s.o

%.o: %.s
	as -g -o $@ $<

%.o: %.c
	gcc -c -g -o $@ $<

all: $(PROGS)

first_c : $(FIRSTC_OBJS)
	gcc -g -o $@ $^

first_s : $(FIRSTS_OBJS)
	gcc -g -o $@ $^

add1 : $(ADD1_OBJS)
	gcc -g -o $@ $^

ifelse : $(IFELSE_OBJS)
	gcc -g -o $@ $^

sumarr : $(SUMARR_OBJS)
	gcc -g -o $@ $^


clean :
	rm -rf $(PROGS) $(FIRSTC_OBJS) $(FIRSTS_OBJS) $(ADD1_OBJS) \
	       $(IFELSE_OBJS) $(SUMARR_OBJS)
