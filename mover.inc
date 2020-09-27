moverFichaBlanco macro turno
	LOCAL ORIGEN,EXIT
		CMP comando[2],','
		JE ORIGEN
		JMP EXIT

		ORIGEN:
			moveOrigen
            moveBlanca
		EXIT:
endm

moverFichaNegro macro turno
	LOCAL ORIGEN,EXIT
		CMP comando[2],','
		JE ORIGEN
		JMP EXIT

		ORIGEN:
			moveOrigen
            moveNegro
		EXIT:
endm

moveBlanca macro 
	LOCAL getRow8,getRow7,getRow6,getRow5,getRow4,getRow3,getRow2,getRow1,EXIT
			CMP comando[4],'1'
			JE getRow1
			CMP comando[4],'2'
			JE getRow2
			CMP comando[4],'3'
			JE getRow3
			CMP comando[4],'4'
			JE getRow4
			CMP comando[4],'5'
			JE getRow5
			CMP comando[4],'6'
			JE getRow6
			CMP comando[4],'7'
			JE getRow7
			CMP comando[4],'8'
			JE getRow8	

			getRow8:
				writeBlanca row8
				JMP EXIT
			getRow7:
			 	writeBlanca row7
			 	JMP EXIT
			getRow6:
			 	writeBlanca row6
			 	JMP EXIT
			getRow5:
			 	writeBlanca row5
			 	JMP EXIT
			getRow4:
				writeBlanca row4
				JMP EXIT
			getRow3:
				writeBlanca row3
				JMP EXIT
			getRow2:
				writeBlanca row2
				JMP EXIT
			getRow1:
				writeBlanca row1
				JMP EXIT
			EXIT:
endm



moveNegro macro 
	LOCAL getRow8,getRow7,getRow6,getRow5,getRow4,getRow3,getRow2,getRow1,EXIT
			CMP comando[4],'1'
			JE getRow1
			CMP comando[4],'2'
			JE getRow2
			CMP comando[4],'3'
			JE getRow3
			CMP comando[4],'4'
			JE getRow4
			CMP comando[4],'5'
			JE getRow5
			CMP comando[4],'6'
			JE getRow6
			CMP comando[4],'7'
			JE getRow7
			CMP comando[4],'8'
			JE getRow8	

			getRow8:
				writeNegra row8
				JMP EXIT
			getRow7:
			 	writeNegra row7
			 	JMP EXIT
			getRow6:
			 	writeNegra row6
			 	JMP EXIT
			getRow5:
			 	writeNegra row5
			 	JMP EXIT
			getRow4:
				writeNegra row4
				JMP EXIT
			getRow3:
				writeNegra row3
				JMP EXIT
			getRow2:
				writeNegra row2
				JMP EXIT
			getRow1:
				writeNegra row1
				JMP EXIT
			EXIT:
endm














moveOrigen macro 
	LOCAL getRow1,getRow2,getRow3,getRow4,getRow5,getRow6,getRow7,getRow8,EXIT, ERROR
			CMP comando[1],'1'
			JE getRow1
			CMP comando[1],'2'
			JE getRow2
			CMP comando[1],'3'
			JE getRow3
			CMP comando[1],'4'
			JE getRow4
			CMP comando[1],'5'
			JE getRow5
			CMP comando[1],'6'
			JE getRow6
			CMP comando[1],'7'
			JE getRow7	
			CMP comando[1],'8'
			JE getRow8	
            getRow8:
				delete row8
				JMP EXIT
			getRow7:
			 	delete row7
			 	JMP EXIT
			getRow6:
			 	delete row6
			 	JMP EXIT
			getRow5:
                delete row5
			 	JMP EXIT
			getRow4:
				delete row4
				JMP EXIT
			getRow3:
                delete row3
				JMP EXIT
			getRow2:
				delete row2
				JMP EXIT
			getRow1:
				delete row1
				JMP EXIT
			EXIT:
            
endm

writeBlanca macro row
	LOCAL dest1,dest2,dest3,dest4,dest5,dest6,dest7,dest8,EXIT
		CMP comando[3],'A'
		JE dest1
		CMP comando[3],'B'
		JE dest2
		CMP comando[3],'C'
		JE dest3
		CMP comando[3],'D'
		JE dest4
		CMP comando[3],'E'
		JE dest5
		CMP comando[3],'F'
		JE dest6
		CMP comando[3],'G'
		JE dest7
		CMP comando[3],'H'
		JE dest8


		dest8:
			MOV row[7],100b
			JMP EXIT
		dest7:
			MOV row[6],100b
			JMP EXIT
		dest6:
			MOV row[5],100b
			JMP EXIT
		dest5:
			MOV row[4],100b
			JMP EXIT
		dest4:
			MOV row[3],100b
			JMP EXIT
		dest3:
			MOV row[2],100b
			JMP EXIT
		dest2:
			MOV row[1],100b
			JMP EXIT
		dest1:
			MOV row[0],100b
			JMP EXIT

		EXIT:
endm

writeNegra macro row
	LOCAL dest1,dest2,dest3,dest4,dest5,dest6,dest7,dest8,EXIT
		CMP comando[3],'A'
		JE dest1
		CMP comando[3],'B'
		JE dest2
		CMP comando[3],'C'
		JE dest3
		CMP comando[3],'D'
		JE dest4
		CMP comando[3],'E'
		JE dest5
		CMP comando[3],'F'
		JE dest6
		CMP comando[3],'G'
		JE dest7
		CMP comando[3],'H'
		JE dest8


		dest8:
			MOV row[7],101b
			JMP EXIT
		dest7:
			MOV row[6],101b
			JMP EXIT
		dest6:
			MOV row[5],101b
			JMP EXIT
		dest5:
			MOV row[4],101b
			JMP EXIT
		dest4:
			MOV row[3],101b
			JMP EXIT
		dest3:
			MOV row[2],101b
			JMP EXIT
		dest2:
			MOV row[1],101b
			JMP EXIT
		dest1:
			MOV row[0],101b
			JMP EXIT

		EXIT:
endm


delete macro row
	LOCAL F1,F2,F3,F4,F5,F6,F7,F8,EXIT
		CMP comando[0],'A'
		JE F1
		CMP comando[0],'B'
		JE F2
		CMP comando[0],'C'
		JE F3
		CMP comando[0],'D'
		JE F4
		CMP comando[0],'E'
		JE F5
		CMP comando[0],'F'
		JE F6
		CMP comando[0],'G'
		JE F7
		CMP comando[0],'H'
		JE F8

		F8:
			MOV row[7],000b
			JMP EXIT
		F7:
			MOV row[6],000b
			JMP EXIT
		F6:
			MOV row[5],000b
			JMP EXIT
		F5:
			MOV row[4],000b
			JMP EXIT
		F4:
			MOV row[3],000b
			JMP EXIT
		F3:
			MOV row[2],000b
			JMP EXIT
		F2:
            MOV row[1],000b
			JMP EXIT
		F1:
			MOV row[0],000b
			JMP EXIT

		EXIT:
endm




































