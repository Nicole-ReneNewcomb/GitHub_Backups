; Nicole-Rene Newcomb's code for Assignment 5, problem 3

; Program Description: encryption using rotation
; Author: Nicole-Rene Newcomb
; Creation Date: 11/07/2022

INCLUDE Irvine32.inc

.data
message1 BYTE "Hello, matey! This here is a secret message!", 0
message2 BYTE "Secrets, secrets everywhere! No wonder I'm losing all my hair!", 0
decryptionMessage BYTE "Here is a decoding test to ensure original encryption works: ", 0
key BYTE -2, 4, 1, 0, -3, 5, 2, -4, -4, 6
keyEndFlag BYTE 0

.code
main PROC
	call TestOne
	call TestTwo
	mov edx, OFFSET decryptionMessage
	call Crlf
	call WriteString
	call Crlf
	call DecryptTestOne
	call DecryptTestTwo
	INVOKE ExitProcess, 0   
main ENDP
TestOne PROC
	mov edx, OFFSET message1             ; move message1 offset into EDX
	call WriteString
	call Crlf
	mov ecx, LENGTHOF message1 - 1       ; move message1 length into ECX
	call Encryption
	call Crlf
	ret
TestOne ENDP
TestTwo PROC
	mov edx, OFFSET message2             ; move message2 offset into EDX
	call WriteString
	call Crlf
	mov ecx, LENGTHOF message2 - 1       ; move message2 length into ECX
	call Encryption
	call Crlf
	ret
TestTwo ENDP
Encryption PROC
	mov ebx, OFFSET key                  ; move key offset into ebx
	mov esi, 1                           ; set index/counter to 1
Loop1:
	mov ah, [ebx]
	.IF (esi == 11)
		mov ebx, OFFSET key
		mov esi, 1
	.ENDIF
	.IF (ah < 0)
		neg ah
		mov al, [edx]
		push ecx
		mov cl, ah
		rol al, cl
		pop ecx
		mov [edx], al
	.ELSE
		mov al, [edx]
		push ecx
		mov cl, ah
		ror al, cl
		pop ecx
		mov [edx], al
	.ENDIF
	call WriteChar
	inc esi
	add ebx, TYPE BYTE
	add edx, TYPE BYTE
	loop Loop1
	ret
Encryption ENDP
DecryptTestOne PROC
	mov edx, OFFSET message1             ; move message1 offset into EDX
	mov ecx, LENGTHOF message1 - 1       ; move message1 length into ECX
	call Decryption
	call Crlf
	ret
DecryptTestOne ENDP
DecryptTestTwo PROC
	mov edx, OFFSET message2             ; move message2 offset into EDX
	mov ecx, LENGTHOF message2 - 1       ; move message2 length into ECX
	call Decryption
	call Crlf
	ret
DecryptTestTwo ENDP
Decryption PROC
	mov ebx, OFFSET key                  ; move key offset into ebx
	mov esi, 1                           ; set index/counter to 1
Loop1:
	mov ah, [ebx]
	.IF (esi == 11)
		mov ebx, OFFSET key
		mov esi, 1
	.ENDIF
	.IF (ah < 0)
		neg ah
		mov al, [edx]
		push ecx
		mov cl, ah
		ror al, cl
		pop ecx
		mov [edx], al
	.ELSE
		mov al, [edx]
		push ecx
		mov cl, ah
		rol al, cl
		pop ecx
		mov [edx], al
	.ENDIF
	call WriteChar
	inc esi
	add ebx, TYPE BYTE
	add edx, TYPE BYTE
	loop Loop1
	ret
Decryption ENDP
END main