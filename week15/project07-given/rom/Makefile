HEX_FILES = 00-add-3nop.hex 01-add-2nop.hex 02-jal.hex 03-ld.hex\
            04-add-fwd.hex 05-ld-stl.hex 06-jal-fls.hex

.PRECIOUS: %.o

%.o: %.s
	as -o $@ $<

%.hex: %.o
	objdump -d $< | python3 makerom3.py > $@

all: $(HEX_FILES)

clean:
	rm -rf $(HEX_FILES) *.o
