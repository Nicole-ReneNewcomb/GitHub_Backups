INCLUDE Irvine32.inc
INCLUDE Macros.inc

mWritestringAttr Macro theString, color
call Clrscr
mov eax, color + (lightGray * 16)
mov esi, OFFSET mystring
call SetTextColor
endm

.data
myString BYTE "Here is my string", 0

.code
main PROC
mWriteStringAttr myString, white



main ENDP
END main