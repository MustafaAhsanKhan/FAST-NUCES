.386
.model flat, stdcall
.stack 4096

.data
	complexArray word 1234h, 5678h, 9ABCh
	indexPtr dword ?

	array word 12h, 34h, 56h, 78h, 90h, 21h

	var1 byte 10h
	align dword
	var2 dword 20h

	dynamicArray dword 10000000h, 20000000h, 30000000h
	dynamicPtr dword ?
	copyArray dd 3 dup(?)

	baseValue byte 0ffh
	offsetValue word 0020h

.code
	main PROC

		;Q1
		mov eax, dword PTR complexArray + 2
		mov indexPtr, eax
		mov ax, word PTR indexPtr

		;Q2
		mov si, word PTR array + 4

		;Q3

		;Q4
		mov esi,offset dynamicArray
		mov edi,offset copyArray

		mov dynamicPtr, esi

		mov eax,[esi]
		mov [edi],eax
		add esi,4
		add edi,4

		mov eax,[esi]
		mov [edi],eax
		add esi,4
		add edi,4

		mov eax,[esi]
		mov [edi],eax
		add esi,4
		add edi,4
		
		;Q5
		mov esi, offset baseValue
		mov edi, offset offsetvalue
		add esi, [edi]
		mov eax, esi

		

main ENDP
END main