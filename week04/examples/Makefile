PROGS = fact_rec countc_rec fmi_rec
CNTCREC_OBJS = countc_rec.o countc_rec_c.o countc_rec_s.o
FACTREC_OBJS = fact_rec.o fact_rec_c.o fact_rec_s.o
FMIREC_OBJS = fmi_rec.o fmi_rec_c.o fmi_rec_s.o

%.o: %.c
	gcc -g -c -o $@ $<

%.o: %.s
	as -g -o $@ $<

all: $(PROGS)

fact_rec : $(FACTREC_OBJS)
	gcc -g -o $@ $^

countc_rec : $(CNTCREC_OBJS)
	gcc -g -o $@ $^

fmi_rec : $(FMIREC_OBJS)
	gcc -g -o $@ $^

clean:
	rm -rf $(PROGS) $(FACTREC_OBJS) $(CNTCREC_OBJS) $(FMIREC_OBJS)
