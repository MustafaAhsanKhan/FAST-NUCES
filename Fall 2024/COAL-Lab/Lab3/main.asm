.386
.model flat, stdcall
.stack 4096
.data

comment @
; Q1
Var1 dw 010h
Var2 dw 5566h
Var3 dw 6261h, 64h
Var4 dw 2211h, 030h
Var5 dw 050h, 060h, 070h, 080h
Var6 dw ?, ?
Var7 dw 2 DUP(?)
@

; Q2
;Var1 byte 10h
Var2 dw 5566h
Var3 db 'abcd', 0
Var4 byte 11h, 22h, 30h
Var5 word 50h, 60h, 70h, 80h
Var6 db ?, ?
Var7 byte 4 DUP(?)

; Q3
Var1 dd 12345678h

; Q4
byte_Arr db 01h, 03h, 05h, 02h, 09h
word_Arr dw 00h, 01h, 05h, 03h, 09h, 08h
dword_Arr dd 10h, 20h, 30h, 40h
arr_len db ?
word_len db ?
dword_len db ?


;Q5
arr_Size db ?
word_Size db ?
dword_Size db ?

.code

main PROC

mov arr_len, LENGTHOF byte_Arr
mov word_len, LENGTHOF word_Arr
mov dword_len, LENGTHOF dword_Arr

mov arr_Size, SIZEOF byte_Arr
mov word_Size, SIZEOF word_Arr
mov dword_Size, SIZEOF dword_Arr

main ENDP
END main