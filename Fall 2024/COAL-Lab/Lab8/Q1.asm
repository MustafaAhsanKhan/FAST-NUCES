comment @
.386
.model flat,stdcall
.stack 4096
.data

	arr db 21,22,1,2,3,4,67,8,9,10
	second_min db ?
	second_large db ?

.code
main PROC

	mov ecx, LENGTHOF arr  ;To iterate
L1:
	
	mov edx, ecx
	dec ecx  ;Inner loop runs till i - 1
	cmp ecx, 0  ;If length of array is 0
	je L1_END

	mov edi, 0
	L2:

		mov al, arr[edi]
		cmp al, arr[edi + 1]
		jle skip  ;If arr[edi] <= arr[edi + 1]
		    ;Swapping
			xchg al, arr[edi + 1]
			xchg al, arr[edi]
		skip:

		inc edi
	loop L2

	mov ecx, edx  ;Reset first loops value

loop L1
L1_END:

	mov al, arr[8]
	mov second_large, al  ;Storing second largest


	mov al, arr[1]
	mov second_min, al  ;Storing second minimum

main ENDP
END main
@
end