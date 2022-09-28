; Nicole-Rene Newcomb's code for Assignment2

; Program Description: Calculates result1 & result2 from x & y, where x = 1000h,
;	 y = 2000h, result1 = (X - Y) + (X + Y), & result2 = result1 - (X + Y) 
; Author: Nicole-Rene Newcomb
; Creation Date: 09/26/2022

.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD

.data
x DWORD 1000h
y DWORD 2000h
result1 DWORD ?
result2 DWORD ?

.code
main PROC
   mov eax, x            ; set eax = x = 1000h
   sub eax, y            ; subtract value of y from eax, eax -= y
   mov ebx, x            ; set ebx = x = 1000h
   add ebx, y            ; add value of y to ebx, ebx += y
   add eax, ebx          ; eax += ebx
   mov result1, eax      ; set result1 = eax, which equals (X - Y) + (X + Y)
   mov ebx, x            ; set ebx = x = 1000h
   add ebx, y            ; add value of y to ebx, ebx += y
   sub eax, ebx          ; eax -= ebx
   mov result2, eax      ; set result2 = eax, which equals result1 - (X + Y)
  ;mov ecx, result1      ; confirms result1 = 2000h by moving it to ecx
  ;mov edx, result2      ; confirms result2 = -1000h (negative hex value notation) by moving it to edx
  ;add edx, 1000h        ; confirms result2 + 1000h = 0 to ensure proper negative hex value stored
   INVOKE ExitProcess, 0
main ENDP
END main