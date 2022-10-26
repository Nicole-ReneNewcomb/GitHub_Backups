; Nicole-Rene Newcomb's code for Assignment4, part 1

; Program Description: Calculates result1 & result2 from x & y, where x = 1000h,
;	 y = 2000h, result1 = (X - Y) + (X + Y), & result2 = result1 - (X + Y) 
; Author: Nicole-Rene Newcomb
; Creation Date: 10/23/2022

.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD

.data
array SWORD 50 DUP(?)
sentinel SWORD 0FFFFh

.code
mov esi,OFFSET array
mov ecx,LENGTHOF array
L1: cmp WORD PTR [esi],0 ; check for zero
   INVOKE ExitProcess, 0
main ENDP
END main