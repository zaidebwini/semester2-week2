// R0 = base address
// R1 = number of elements
// R2 = sum

@R2
M=0

@R3
M=0

(LOOP)
@R3
D=M
@R1
D=D-M
@END
D;JGE

@R0
D=M
@R3
A=D+M
D=M

@R2
M=M+D

@R3
M=M+1

@LOOP
0;JMP

(END)
@END
0;JMP