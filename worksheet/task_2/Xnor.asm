// R2 = R0 xnor R1
@R0
D=M
@R1
D=D&M
@R2
M=D

@R0
D=M
D=!D
@R3
M=D

@R1
D=M
D=!D
@R3
D=D&M

@R2
M=M|D

(END)
@END
0;JMP