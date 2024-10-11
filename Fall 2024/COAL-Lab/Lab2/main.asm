.386
.model flat, stdcall
.stack 4096
.data
var1 db 10
var2 db 6
n BYTE "Mustafa",0
s db 7
.code
main PROC

; Q1

comment @

mov ax, 1
mov bx, 2
add ax, bx

mov cx, 20
mov dx, 3
sub cx, dx


mov al, 2
mov ah, 4
add al, ah

mov bl, 5
mov bh, 6
add bl, bh

mov cl, 6
mov ch, 2
sub cl, ch

mov dl, 1
mov dh, 5
sub dl, dh


; Q2

mov ax, 2
mov cx, 5

mov bx, 10
mov dx, 5

add ax, cx

sub bx, dx

mov al, 1
mov ah, 5

mov bl, 2
mov bh, 5

mov cl, 3
mov ch, 5

mov dl, 4
mov dh, 5

add al, ah
add bl, bh
sub cl, ch
sub dl, dh


; Q3

mov ax, 12 ; ax = 12, al = 12, ah = 0
mov bx, 10 ; bx = 10, bl = 10, bh = 0
add ax, bx ; ax = 22, al = 22, ah = 0


; Q4

mov cx, 0549
mov dx, 0049
add cx, dx ; 0549 + 0049 = 0598


; Q5

mov cx, 2024
mov dx, 2004
sub cx, dx ; 2024 - 2004 = 20


; Q6

mov cx, 001b
mov dx, 010b
add cx, dx ; 1 + 2 = 3


; Q7

mov cx, 010b
mov dx, 0Dh
add cx, dx  ; 2 + 13 = 15


; Q8

mov cx, 010b
mov dx, 05o
add cx, dx ; 2 + 5 = 7


; Q9

mov cx, 0Dh
mov dx, 05o
add cx, dx ; 13 + 5 = 18

; Q10

mov al, var1 ; var 1 = 6, var 2 = 10
add al, var2 ; 6 + 10 = 16

; Q11

mov al, var1 ; var 1 = 6, var 2 = 10
sub al, var2 ; 10 - 6 = 4

@


; Q 12
main ENDP
END main