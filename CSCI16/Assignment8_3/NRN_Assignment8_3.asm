; Nicole-Rene Newcomb's code for Assignment 8, problem 3

; Program Description: Implement C++ Double Comparison
; Author: Nicole-Rene Newcomb
; Creation Date: 12/12/2022

INCLUDE Irvine32.inc

.data
X REAL8 12.3        ; test floating-point values
Y REAL8 13.5
xLowerMsg BYTE "X is lower", 0
xHigherMsg BYTE "X is higher", 0

.code
main PROC   
	fld X        ; ST(0) = X
	fcomp Y      ; compares Y to ST(0) = X & pops ST(0) off stack
	fnstsw ax    ; moves status word into ax
	sahf         ; copy AH into EFLAGS
	jb XLower
	mov edx, OFFSET xHigherMsg   
	call WriteString
	call Crlf
	jmp XHigher
XLower:
	mov edx, OFFSET xLowermsg
	call WriteString
	call Crlf
XHigher:
	INVOKE ExitProcess, 0
main ENDP
END main