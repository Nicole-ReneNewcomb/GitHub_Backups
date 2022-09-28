; My first Assembly Language Program
.386
.model flat,stdcall
.stack 4096

.code
main PROC
   mov eax, 20000h ; set eax = 20000h
   mov ebx, 30000h ; set ebx = 30000h
   add eax, ebx ; add ebx to eax (eax = eax + ebx)
main ENDP
END main