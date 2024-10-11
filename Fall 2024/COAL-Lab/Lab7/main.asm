.386
.model flat, stdcall
.stack 4096

.data

arr1 db 1,2,3,4,5,6,7,8,9,10
arr2 db 11,12,13,14,15,16,17,18,19,20
evenarr DB 20 dup(?)
oddarr DB 20 dup(?)

arr3 db -10,9,-8,7,-6,5,-4,3,-2,1
negarr db 10 dup(?)

arr4 db 1,2,3,4,10,5,6,7,8,9
min db ?
max db ?

.code
main PROC

;Q1
    mov esi, 0
    mov edi, 0

    mov ecx, 10
    mov ebx,offset arr1

process_arr1:
    mov al, [ebx]
    test al, 1
    jz store_even_arr1
    jmp store_odd_arr1

store_even_arr1:
    mov [evenarr + esi], al
    inc esi
    jmp next_arr1

store_odd_arr1:
    mov [oddarr + edi], al
    inc edi

next_arr1:
    inc ebx
    loop process_arr1

    mov ecx, 10
    lea ebx, arr2

process_arr2:
    mov al, [ebx]
    test al, 1
    jz store_even_arr2
    jmp store_odd_arr2

store_even_arr2:
    mov [evenarr + esi], al
    inc esi
    jmp next_arr2

store_odd_arr2:
    mov [oddarr + edi], al
    inc edi

next_arr2:
    inc ebx
    loop process_arr2

    mov eax, 1


;Q2
    mov esi, 0
    mov ebx,offset arr3
    mov ecx, 10

process_arr3:
    mov al, [ebx]
    cmp al, 0
    jl store_neg

next_arr3:
    inc ebx
    loop process_arr3
    jmp end_program

store_neg:
    mov [negarr + esi], al
    inc esi
    jmp next_arr3

end_program:
    mov eax, 1
 
;Q3
mov ax,0FFFFh
and ax, 00FFh


mov bx,0FFh
or bx, 0FF00h

;Q4
mov ebx, OFFSET arr4
    mov al, [ebx]
    mov min, al
    mov ecx, 9

find_min:
    add ebx, 1
    mov al, [ebx]
    cmp al, min
    jge next_element
    mov min, al

next_element:
    loop find_min

    mov eax, 1


;Q5
mov ebx, OFFSET arr4
    mov al, [ebx]
    mov max, al
    mov ecx, 9

find_max:
    add ebx, 1
    mov al, [ebx]
    cmp al, max
    jle next_element2
    mov max, al

next_element2:
    loop find_max

    mov eax, 1


main ENDP
END main