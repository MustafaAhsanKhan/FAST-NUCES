.386
.model flat, stdcall
.stack 4096

.data

;Q1
var1 byte 12h
var2 byte 52h
var3 sbyte -15
var4 sbyte -20

;Q2
list1 byte 1,2,3,4,5,6;

;Q3
var5 byte 00001011b
var6 byte 00001101b

;Q4
var7 byte 00001110b
var8 byte 00000101b


.code
main PROC

;Q1
mov al, var1
add al, var2

mov al, var3
add al, var4

mov al, var1
sub al, var2

mov al, var3
sub al, var4

;Q2
mov esi, offset list1
mov edi, offset list1 + (lengthof list1 - 1)
mov ecx, (lengthof list1) / 2

L1:
    mov al, [esi]
    mov bl, [edi]
    mov [esi], bl
    mov [edi], al

    inc esi
    dec edi

    loop L1

;Q3
mov al, var5
add al, var6

mov al, var5
sub al, var6

;Q4
mov al, var7
inc var7

mov al, var8
dec var8

mov al, var7
sub al, var8

mov al, var7
add al, var8



;Q5
mov ecx, 25
mov al, 97

L2:
    inc al
    loop L2


main ENDP
END main