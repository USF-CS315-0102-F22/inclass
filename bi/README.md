# bi - Bit Inspector

This directory contains the bi executable for riscv64 Linux and bi_aliases.

## Installation

Link (or copy) the bi binary to a location in your home directory that is on your PATH:
```
$ ln -s ~/cs315/inclass/bi/bi ~/.local/bin/bi
```

Add the contents of ```bi_aliases``` to your ```~/.bash_aliases``` file. Make sure to 
```source ~/.bash_aliases``` or logout and log back in to get the shell to recognize
the aliases.


## Usage

```
$ bi
usage: bi start,end [start,end ...] value
       bi start,end,name [start,end,name ...] value
  value can be a decimal string, binary string or hexadecimal string
  examples:
    bi 0,3 8,11 0x1234
    bi 0,3,foo 8,11,bar, 0x1234
    bi 0b10101111 4,6
    bi 5000 0,8
```

## Examples

```
0:	00b50533          	add	a0,a0,a1
```
```
$ bir 0x00b50533
opcode    : [00,06](07 bits) = 0b0110011 0x33 51
rd        : [07,11](05 bits) = 0b01010 0x0A 10
funct3    : [12,14](03 bits) = 0b000 0x0 0
rs1       : [15,19](05 bits) = 0b01010 0x0A 10
rs2       : [20,24](05 bits) = 0b01011 0x0B 11
funct7    : [25,31](07 bits) = 0b0000000 0x00 0
```

```
c:	ffe28293          	addi	t0,t0,-2
```
```
$ bii 0xffe28293
opcode    : [00,06](07 bits) = 0b0010011 0x13 19
rd        : [07,11](05 bits) = 0b00101 0x05 5
funct3    : [12,14](03 bits) = 0b000 0x0 0
rs1       : [15,19](05 bits) = 0b00101 0x05 5
imm       : [20,31](12 bits) = 0b111111111110 0xFFE 4094
```
