; Nicole-Rene Newcomb's code for Assignment3, Problem 1.

; Program Description: Exchange every pair of values in an
; aray with an even number of elements using a loop.
; Author: Nicole-Rene Newcomb
; Creation Date: 10/04/2022

.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD

.data
evenArray DWORD 100,200,300,400,500,600

.code
main PROC
   mov edi, OFFSET evenArray              ; sets edi to start of evenArray
   mov ecx, (LENGTHOF evenArray) / 2      ; sets ecx loop counter to length / 2
   mov eax, 0                             ; sets eax to zero before math functions
L1:
   mov eax, [edi]                         ; moves value of evenArray at edi location to eax
   xchg eax, [edi + TYPE evenArray]       ; exchanges value of (evenArray + 1 index space) from edi location with eax
   xchg eax, [edi]                        ; exchanges value of evenArray at edi location with eax
   add edi, (TYPE evenArray) * 2          ; moves edi two index spaces further along the evenArray
   loop L1
   INVOKE ExitProcess, 0
main ENDP
END main