; Nicole-Rene Newcomb's code for Assignment 6, problem 3

; Program Description: StrConcat Procedure
; Author: Nicole-Rene Newcomb
; Creation Date: 11/14/2022

INCLUDE Irvine32.inc

StrConcat PROTO,
targetPtr: PTR BYTE,
sourcePtr: PTR BYTE

.data
targetString BYTE "ABCDE", 10 DUP(0)
sourceString BYTE "FGH",0

.code
main PROC
	INVOKE StrConcat, ADDR targetString, ADDR sourceString
	mov ecx, LENGTHOF targetString
	mov ebx, OFFSET targetString
ConcatVerification:	                              ; loop to verify concatenation output
	mov al, [ebx]
	call WriteChar                
	add ebx, TYPE BYTE
	loop ConcatVerification
	INVOKE ExitProcess, 0   
main ENDP
StrConcat PROC,
	targetPtr: PTR BYTE,
	sourcePtr: PTR BYTE
	mov ebx, sourcePtr
	mov edx, targetPtr
TargetStringLoop:
	mov al, [edx]
	cmp al, 0
	jz EndTargetString           ; If end of target string reached (0)
	add edx, TYPE BYTE
	jnz TargetStringLoop
EndTargetString:                 ; When reach end of target string
	mov al, [ebx]
	cmp al, 0
	jz EndSourceString           ; If end of source string reached (0)
	add [edx], al                ; moves source string char to target string
	add ebx, TYPE BYTE
	add edx, TYPE BYTE
	jmp EndTargetString
EndSourceString:                 ; Return after end of source string
	ret
StrConcat ENDP
END main