; Nicole-Rene Newcomb's code for Assignment 5, problem 2

; Program Description: WriteScaled procedure - decimal ASCII
; Author: Nicole-Rene Newcomb
; Creation Date: 11/07/2022

INCLUDE Irvine32.inc

DECIMAL_OFFSET = 5                    ; how many decimal places
.data
decimal_one BYTE "100123456789765"    ; 1001234567.89765
decimal_two BYTE "1300000"            ; 13.00000
decimal_three BYTE "13131313131"      ; 131313.13131

.code
main PROC
	call TestOne
	call TestTwo
	call TestThree
	INVOKE ExitProcess, 0         
main ENDP
TestOne PROC
	mov ebx, DECIMAL_OFFSET          ; move DECIMAL_OFFSET into EBX
	mov edx, OFFSET decimal_one      ; move decimal_one number's offset into EDX
	mov ecx, LENGTHOF decimal_one    ; move decimal_one number's length into ECX
	call WriteScaled                 ; call WriteScaled procedure
	ret
TestOne ENDP
TestTwo PROC
	mov ebx, DECIMAL_OFFSET          ; move DECIMAL_OFFSET into EBX
	mov edx, OFFSET decimal_two      ; move decimal_two number's offset into EDX
	mov ecx, LENGTHOF decimal_two    ; move decimal_two number's length into ECX
	call WriteScaled                 ; call WriteScaled procedure
	ret
TestTwo ENDP
TestThree PROC
	mov ebx, DECIMAL_OFFSET          ; move DECIMAL_OFFSET into EBX
	mov edx, OFFSET decimal_three    ; move decimal_three number's offset into EDX
	mov ecx, LENGTHOF decimal_three  ; move decimal_three number's length into ECX
	call WriteScaled                 ; call WriteScaled procedure
	ret
TestThree ENDP
WriteScaled PROC
	push edx                         ; save edx for later
	mov edx, ecx                     ; move size of number to eax
	sub edx, ebx                     ; subtract decimal places from number size
	mov ebx, edx                     ; move result to ebx (digits before decimal place)
	pop edx                          ; recover edx value
	mov esi, 0                       ; set esi (index) to zero
Loop1:
	.IF (esi == ebx)                 ; if index/counter is at position for decimal
		mov al, 101110b              ; move ASCII decimal character into al
		call WriteChar               ; output decimal character from al
	.ENDIF
	mov al, [edx]                    ; move offset of number to al
	call WriteChar                   ; output char digit
	add edx, TYPE BYTE               ; move position to next digit
	inc esi                          ; increment index/counter
	loop Loop1                       ; loop back to Loop1
	call Crlf
	ret
WriteScaled ENDP
END main