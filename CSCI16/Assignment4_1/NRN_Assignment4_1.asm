; Nicole-Rene Newcomb's code for Assignment4, problem 1

; Program Description: locates first nonzero value in array
; Author: Nicole-Rene Newcomb
; Creation Date: 10/23/2022

.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD

.data
array SWORD 50 DUP(?)         ; tested with 4 DUP(?), 4, 45 DUP(?) and loop stopped properly
sentinel SWORD 0FFFFh

.code
main PROC
	mov esi,OFFSET array
	mov ecx,LENGTHOF array
L1: cmp WORD PTR [esi],0      ; check for zero
	pushfd
	add esi, TYPE array
	popfd
	loopz L1
	jz quit
	sub esi, TYPE array
quit:
   INVOKE ExitProcess, 0
main ENDP
END main