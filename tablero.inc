

printTablero macro buffer, row  ; Rcorre el arreglo que viene (buffer) y hace print de las cosas
LOCAL CONT, FIN,FN, FB, RN, RB, S
PUSH SI
PUSH AX

xor si,si
print marc
print row ;imprime la columna, 8,7,6,...,1

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
        PrintFichaNegra CONT
    FB: 
        PrintFichaBlanca CONT
    S:
        PrintSpace CONT
    RN:
        PrintRNegra CONT
    RB:
        PrintRBlanca CONT
    
FIN:
POP AX
POP SI
xor si,si
endm



PrintFichaNegra macro jumper
    print fneg
    inc si
    jmp jumper
endm


PrintFichaBlanca macro jumper
    print fblc
    inc si
    jmp jumper
endm


PrintSpace macro jumper
    print void
    inc si
    jmp jumper
endm



PrintRNegra macro jumper
    print rneg
    inc si
    jmp jumper
endm

PrintRBlanca macro jumper
    print rblc
    inc si
    jmp jumper
endm





txttablero macro buffer, handle
LOCAL CONT, FIN,FN, FB, RN, RB, S
PUSH SI
PUSH AX
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
        writeFile SIZEOF txtfneg, txtfneg, handle
        inc si
        jmp CONT
    FB: 
        writeFile SIZEOF txtfblc, txtfblc, handle
        inc si
        jmp CONT
    S:
        writeFile SIZEOF txtvoid, txtvoid, handle
        inc si
        jmp CONT
    RN:
        writeFile SIZEOF txtrneg, txtrneg, handle
        inc si
        jmp CONT
    RB:
        writeFile SIZEOF txtrblc, txtrblc, handle
        inc si
        jmp CONT
FIN:
writeFile SIZEOF endline, endline, handle

POP AX
POP SI
xor si,si
endm


obtenerArregloTablero macro texto, arreglo8, arreglo7, arreglo6, arreglo5, arreglo4, arreglo3, arreglo2, arreglo1
    LOCAL LOO, LOO71, LOO72, LLO61, LOO62, LOO51, LOO52, LOO41, LOO42, LOO31, LOO32, LOO21, LOO22, LOO11, LOO12,FIN
    xor si, si
    xor di, di
    LOO:
        cmp si,8
        je LOO71
        recrearTablero arreglo8, texto
        jmp LOO

    LOO71:
        xor SI, SI
        JMP LOO72

    LOO72:
        cmp si,8
        je LOO61
        recrearTablero arreglo7, texto
        jmp LOO72

    LOO61:
        xor SI, SI
        JMP LOO62
    LOO62:
        cmp si,8
        je LOO51
        recrearTablero arreglo6, texto
        jmp LOO62

    LOO51:
        xor SI, SI
        JMP LOO52
    LOO52:
        cmp si,8
        je LOO41
        recrearTablero arreglo5, texto
        jmp LOO52

    LOO41:
        xor SI, SI
        JMP LOO42

    LOO42:
        cmp si,8
        je LOO31
        recrearTablero arreglo4, texto
        jmp LOO42
    LOO31:
        xor SI, SI
        JMP LOO32
    LOO32:
        cmp si,8
        je LOO21
        recrearTablero arreglo3, texto
        jmp LOO32
    LOO21:
        xor SI, SI
        JMP LOO22
    LOO22:
        cmp si,8
        je LOO11
        recrearTablero arreglo2, texto
        jmp LOO22
    LOO11:
        xor SI, SI
        JMP LOO12

    LOO12:
        cmp si,8
        je FIN
        recrearTablero arreglo1, texto
        jmp LOO12
        
    FIN:
    xor di, di
endm



recrearTablero macro buffer, texto
    LOCAL RECREARNEGRA, RECREARBLANCA, RECREARSPACIO, FIN
    
    cmp texto[di], '1'
    je  RECREARNEGRA
    cmp texto[di], '2'
    je  RECREARBLANCA
    cmp texto[di], '0'
    je  RECREARSPACIO
    jmp FIN
    RECREARNEGRA:
        NEGRA buffer, SI
        inc si
        jmp FIN
    RECREARBLANCA:
        BLANCA buffer, SI
        inc si
        jmp FIN
    RECREARSPACIO:
        ESPACIO buffer, SI
        inc si
        jmp FIN
    FIN:
        inc di
        
endm

NEGRA macro buffer, i

    mov buffer[i], 101b

endm

BLANCA macro buffer, i

    mov buffer[i], 100b

endm


ESPACIO macro buffer, i

    mov buffer[i], 000b

endm