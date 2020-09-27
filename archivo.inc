





getRuta macro buffer
LOCAL INICIO,FIN
	xor si,si
INICIO:
	getChar
	cmp al,0dh
	je FIN
	mov buffer[si],al
	inc si
	jmp INICIO
FIN:
	mov buffer[si],00h
endm


openFile macro ruta,handle
mov ah,3dh
mov al,10b
lea dx,ruta
int 21h
mov handle,ax
jc ErrorAbrir
endm

closeFile macro handle
mov ah,3eh
mov handle,bx
int 21h
endm

readFile macro numbytes,buffer,handle
mov ah,3fh
mov bx,handle
mov cx,numbytes
lea dx,buffer
int 21h
jc ErrorLeer
endm

createFile macro buffer,handle
mov ah,3ch
mov cx,00h
lea dx,buffer
int 21h
mov handle,ax
jc ErrorCrear
endm


writeFile macro numbytes,buffer,handle
	mov ah, 40h
	mov bx,handle
	mov cx,numbytes
	lea dx,buffer
	int 21h
	jc ErrorEscribir
endm



