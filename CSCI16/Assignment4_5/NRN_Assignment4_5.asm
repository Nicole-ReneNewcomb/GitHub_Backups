; Nicole-Rene Newcomb's code for Assignment4, problem 5

; Program Description: Integer value to grade table
; Author: Nicole-Rene Newcomb
; Creation Date: 10/24/2022

INCLUDE Irvine32.inc

.data
GradeTable BYTE 'A'               ; originally thought problem 5 required the procedure table
	DWORD Grade_A                 ; realized it didn't, but decided to use it for practice 
	EntrySize = ($ - GradeTable)  ; it took me a while to grasp how the procedure table works
	BYTE 'B'
	DWORD Grade_B
	BYTE 'C'
	DWORD Grade_C
	BYTE 'D'
	DWORD Grade_D
	BYTE 'F'
	DWORD Grade_F
error BYTE "Error: requires an integer value between 50 and 100.", 0
Amsg WORD "This is an A."
Bmsg WORD "This is a B."
Cmsg WORD "This is a C."
Dmsg WORD "This is a D."
Fmsg WORD "This is an E."

.code
main PROC
	mov ebx, OFFSET GradeTable
	mov ecx, 10
	call Randomize
NumGen:
	mov eax, 51
	call RandomRange
	add eax, 50
	call CalcGrade
	loop NumGen
main ENDP
CalcGrade PROC
	call ReadInt
	mov ebx, OFFSET GradeTable
	.IF (eax >= 90) && (eax <= 100) 
		call NEAR PTR [ebx + 1]
	.ELSEIF (eax < 90) && (eax >= 80)
		call NEAR PTR [ebx + EntrySize + 1]
	.ELSEIF (eax < 80) && (eax >= 70)
		call NEAR PTR [ebx + EntrySize*2 + 1]
	.ELSEIF (eax < 70) && (eax >= 60)
		call NEAR PTR [ebx + EntrySize*3 + 1]
	.ELSEIF (eax < 60) && (eax >= 50)
		call NEAR PTR [ebx + EntrySize*4 + 1]
	.ELSE
		mov edx, OFFSET error
		call WriteString
	.ENDIF
	ret
CalcGrade ENDP
Grade_A PROC
	call WriteInt
	mov al, 'A'
	mov edx, Amsg
	call WriteString
	ret
Grade_A ENDP
Grade_B PROC
	call WriteInt
	mov al, 'B'
	mov edx, Bmsg
	call WriteString
	ret
Grade_B ENDP
Grade_C PROC
	call WriteInt
	mov al, 'C'
	mov edx, Cmsg
	call WriteString
	ret
Grade_C ENDP
Grade_D PROC
	call WriteInt
	mov al, 'D'
	mov edx, Dmsg
	call WriteString
	ret
Grade_D ENDP
Grade_F PROC
	call WriteInt
	mov al, 'F'
	mov edx, Fmsg
	call WriteString
	ret
Grade_F ENDP

END main