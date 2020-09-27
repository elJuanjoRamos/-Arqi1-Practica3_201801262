htmltablero macro buffer, handle
LOCAL CONT, FIN,FN, FB, RN, RB, S
PUSH SI
PUSH AX
whritehtml SIZEOF tropen, tropen, handle
xor si,si

CONT:
    cmp si,8
    je FIN
    cmp buffer[si], 101b
    je FN
    cmp buffer[si], 100b
    je FB
    cmp buffer[si], 111b
    je RN
    cmp buffer[si], 110b
    je RB
    jmp S

    FN:
        whritehtml SIZEOF fichaNegra, fichaNegra, handle
        inc si
        jmp CONT
    FB: 
        whritehtml SIZEOF fichaBlanca, fichaBlanca, handle
        inc si
        jmp CONT
    S:
        whritehtml SIZEOF vacioBlanca, vacioBlanca, handle
        inc si
        jmp CONT
    RN:
        writeFile SIZEOF rneg, rneg, handle
        inc si
        jmp CONT
    RB:
        writeFile SIZEOF rblc, rblc, handle
        inc si
        jmp CONT
FIN:
whritehtml SIZEOF trclose, trclose, handle
POP AX
POP SI
xor si,si
endm




createFileHtml macro buffer,handle
mov ah,3ch
mov cx,00h
lea dx,buffer
int 21h
mov handle,ax
jc ErrorCrear
endm


openhtml macro ruta,handle
mov ah,3dh
mov al,10b
lea dx,ruta
int 21h
mov handle,ax
jc ErrorAbrir
endm




whritehtml macro numbytes,buffer,handle
	mov ah, 40h
	mov bx,handle
	mov cx,numbytes
	lea dx,buffer
	int 21h
	jc ErrorEscribir
endm


closehtml macro handle
mov ah,3eh
mov handle,bx
int 21h
endm
