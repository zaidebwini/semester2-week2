// R2 = max(R0, R1)
// R3 = 0 if max is R0, 1 if max is R1

@R0
D=M
@R1
D=D-M

@R1GREATER
D;JLT

@R0
D=M
@R2
M=D
@R3
M=0
@END
0;JMP

(R1GREATER)
@R1
D=M
@R2
M=D
@R3
M=1

(END)
@END
0;JMP