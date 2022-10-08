; Nicole-Rene Newcomb's code for Assignment3, Problem 2.

; Program Description: Calculates the sum of the gaps
; between successive array elements in increasing order.
; Author: Nicole-Rene Newcomb
; Creation Date: 10/04/2022

.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD

.data
increasingArray DWORD 0,2,5,9,10
gapSum DWORD ?

.code
main PROC
   mov edi, OFFSET increasingArray            ; sets edi to start of increasingArray
   mov ecx, (LENGTHOF increasingArray) - 1    ; sets ecx counter loop to 1 less than length
   mov eax, 0                                 ; sets eax to zero before math functions
L1:
   add eax, [edi + TYPE increasingArray]      ; adds value of (increasingArray + 1 index space) from edi index location
   sub eax, [edi]                             ; subtracts increasingArray at edi index location
   add edi, TYPE increasingArray              ; moves edi to next index position of increasingArray
   loop L1
   mov gapSum, eax                            ; moves sum of gap values to gapSum variable
   INVOKE ExitProcess, 0
main ENDP
END main