# Control Line Key for Given Project07 Pipelined Processor

IW   - Instruction Word (32 bits)

RR0  - Read Register 0 (5 bits)
RR1  - Read Register 1 (5 bits)
WR   - Write Register (5 bits)

MSZ  - Memory Size (2 bits)
MST  - Memory Store ST (1 bit)
MLD  - Memory Load LD (1 bit)
MR   - Memory To Register Selector (1 bit)
       Picks ALU Result or Memory Data to write back to RegFile

BUOp - Branch Unit Operation (3 bits)
WDsl - Write Data Mux Selector (1 bit)
       Picks MR MUX value or PC+4

PCsl - PC MUX Selector (1)
       Picks Branch Target Address (BTA) or PC+4
       Goes to Branch Unit and becomes PCbr

ALUB - ALU Source B MUX Selector (1 bit)
ALUA - ALU Source A MUX Selector (3 bits)
ALOp - ALU Operation (4 bits)

RFW  - RegFile Write control (1 bit)

PCbr - PCbr MUX Selector

ALUR - ALU Result (64 bits)
RD0  - Read Data 0 value (64 bits)
RD1  - Read Data 1 value (64 bits)
