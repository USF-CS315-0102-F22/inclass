.PRECIOUS: %.o

all: 00-add-r.hex 01-add-i.hex 02-sll-r.hex 03-sll-i.hex \
     04-srl-r.hex 05-srl-i.hex 06-sd-ld.hex 07-sw-lw.hex \
     08-jal.hex 09-j.hex 10-beq.hex 11-blt.hex 12-bge.hex \
     13-mul.hex 14-lui.hex 15-sb-lb.hex 17-fib-rec.hex

%.o: %.s
	as -o $@ $<
 
%.hex: %.o
	objdump -d $< | python3 makerom3.py > $@

clean:
	rm -rf *.o *.hex
