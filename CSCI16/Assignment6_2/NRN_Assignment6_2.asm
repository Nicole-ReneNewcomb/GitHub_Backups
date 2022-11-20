; Nicole-Rene Newcomb's code for Assignment 6, problem 2

; Program Description: DifferentInputs Procedure
; Author: Nicole-Rene Newcomb
; Creation Date: 11/14/2022

INCLUDE Irvine32.inc

DifferentInputs PROTO,
number1: DWORD,
number2: DWORD,
number3: DWORD

.data
test1 DWORD 13
test2 DWORD 131313
test3 DWORD 3
test4 DWORD 7
test5 DWORD 434

.code
main PROC
	INVOKE DifferentInputs, test1, test1, test1        ; first first
	call WriteInt                                      ; used to verify 0/1 output
	INVOKE DifferentInputs, test1, test2, test3        ; second call
	call WriteInt
	INVOKE DifferentInputs, test4, test4, test5        ; third call
	call WriteInt
	INVOKE DifferentInputs, test5, test4, test1        ; fourth call
	call WriteInt
	INVOKE DifferentInputs, test2, test2, test2        ; fifth call
	call WriteInt
	INVOKE ExitProcess, 0   
main ENDP
DifferentInputs PROC,
	number1: DWORD,
	number2: DWORD,
	number3: DWORD
	mov eax, number1
	cmp eax, number2
	jz NotDifferent
	cmp eax, number3
	jz NotDifferent
	mov eax, number2
	cmp eax, number3
	jz NotDifferent
	mov eax, 1
	jmp IsDifferent
NotDifferent:
	mov eax, 0
IsDifferent:
	ret
DifferentInputs ENDP
END main