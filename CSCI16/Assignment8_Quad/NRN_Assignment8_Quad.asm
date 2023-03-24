; Nicole-Rene Newcomb's code for Assignment 8, problem 4

; Program Description: Polynomial Roots Calculator
; user prompted to enter coefficients a, b, and c
; in the form ax^2 + bx + c = 0.
; Author: Nicole-Rene Newcomb
; Creation Date: 12/12/2022

INCLUDE Irvine32.inc

.data
aVar REAL8 ?        
bVar REAL8 ?
cVar REAL8 ?
constant4 REAL8 4.0
constant2 REAL8 2.0
acConstant4 REAL8 ?           ; will hold 4*a*c
aConstant2 REAL8 ?            ; will hold 2*a
positiveSqrt REAL8 ?          ; will hold positive sqrt(b^2-4*a*c)
negativeSqrt REAL8 ?          ; will hold negative sqrt(b^2-4*a*c)
addedNumerator REAL8 ?        ; will hold -b + sqrt(b^2-4*a*c)
subtractedNumerator REAL8 ?   ; will hold -b - sqrt(b^2-4*a*c)
addedRoot REAL8 ?             ; will hold (-b + sqrt(b^2-4*a*c)) / 2*a
subtractedRoot REAL8 ?        ; will hold (-b - sqrt(b^2-4*a*c)) / 2*a
aMessage BYTE "Please enter the coefficient a: ", 0
bMessage BYTE "Please enter the coefficient b: ", 0
cMessage BYTE "Please enter the coefficient c: ", 0
realRootMsg1 BYTE "The roots are real and the first is : ", 0
realRootMsg2 BYTE "The roots are real and the second is : ", 0
imaginaryMsg BYTE "The roots are imaginary and are: ", 0
plusMinus BYTE " (+-) ", 0
iCharacter BYTE "i", 0

.code
main PROC   
	finit                           ; initialize FPU
	mov edx, OFFSET aMessage   
	call WriteString
	call ReadFloat
	fstp aVar                    ; store user value in aVar
	mov edx, OFFSET bMessage
	call WriteString
	call ReadFloat
	fstp bVar                    ; store user value in bVar
	mov edx, OFFSET cMessage
	call WriteString
	call ReadFloat
	fstp cVar                    ; store user value in cVar
	call ShowFPUStack
	fld aVar                      
	fld bVar
	fld cVar                     ; ST(0) = c, ST(1) = b, ST(2) = a
	fmul ST(0), ST(2)            ; ST(0) = a*c
	fmul constant4                ; ST(0) = 4*a*c
	fstp acConstant4              ; acConstant4 = 4*a*c, ST(0) = b, ST(1) = a
	fmul bVar                    ; ST(0) = b^2
	fsub acConstant4              ; ST(0) = b^2-4*a*c, ST(1) = a 
	fsqrt                        ; ST(0) = sqrt(b^2-4*a*c), ST(1) = a
	fstp positiveSqrt            ; positiveSqrt = sqrt(b^2-4*a*c)
	fld positiveSqrt
	fchs                         ; changes sign
	fstp negativeSqrt            ; negativeSqrt = -sqrt(b^2-4*a*c)
	fld bVar                     ; ST(0) = b, ST(1) = a
	fchs                         ; ST(0) = -b , ST(1) = a
	fadd positiveSqrt            ; ST(0) = -b + sqrt(b^2-4*a*c), ST(1) = a
	fstp addedNumerator          ; addedNumerator = -b + sqrt(b^2-4*a*c), ST(0) = a
	fld bVar
	fchs
	fadd negativeSqrt            ; ST(0) = -b + (-sqrt(b^2-4*a*c)), ST(1) = a
	fstp subtractedNumerator     ; subtractedNumerator = -b + (-sqrt(b^2-4*a*c)), ST(0) = a
	fmul constant2                ; ST(0) = 2*a
	fstp aConstant2              ; aConstant2 = 2*a
	fld addedNumerator           ; ST(0) = -b + sqrt(b^2-4*a*c)
	fdiv aConstant2              ; ST(0) = (-b + sqrt(b^2-4*a*c)) / 2*a
	fstp addedRoot               ; addedRoot = (-b + sqrt(b^2-4*a*c)) / 2*a
	fld subtractedNumerator      ; ST(0) = -b - sqrt(b^2-4*a*c)
	fdiv aConstant2              ; ST(0) = (-b - sqrt(b^2-4*a*c)) / 2*a
	fstp subtractedRoot          ; subtractedRoot = (-b - sqrt(b^2-4*a*c)) / 2*a
	fld bVar
	fmul bVar                    ; ST(0) = b^2
	fcomp acConstant4            ; compare b^2 with 4*a*c
	fnstsw ax
	sahf
	jnb realRoot
	mov edx, OFFSET imaginaryMsg
	call WriteString
	fld bVar
	fchs
	fdiv aConstant2
	call WriteFloat
	mov edx, OFFSET plusMinus
	call WriteString
	fld bVar
	fmul bVar
	fadd acConstant4
	fsqrt
	fdiv aConstant2
	call WriteFloat
	mov edx, OFFSET iCharacter
	call WriteString
	call Crlf
	jmp imaginaryRoot
realRoot:
	mov edx, OFFSET realRootMsg1
	call WriteString
	fld addedRoot
	call WriteFloat
	call Crlf
	mov edx, OFFSET realRootMsg2
	call WriteString
	fld subtractedRoot
	call WriteFloat
	call Crlf
imaginaryRoot:

	INVOKE ExitProcess, 0
main ENDP
END main