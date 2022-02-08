//
//  cg_lex.c
//  plassemble
//
//  Created by Noah Wooten on 2/6/22.
//

#include "codegen.h"
#include "ops.h"
#include <stdlib.h>
#include <string.h>
u32 ErrorLevel;
u32 CurrentLine;

void cgi_tokenize(char* Source, char* Operation, char* OperandA, char* OperandB, char* OperandC) {
	char* Data = malloc(2048);
	strcpy(Data, Source);
	char* Tokenized = strtok(Source, " ,");
	u32 Count = 0;
	while (Tokenized != NULL) {
		switch (Count) {
			case 0:
				strcpy(Operation, Tokenized);
				break;
			case 1:
				strcpy(OperandA, Tokenized);
				break;
			case 2:
				strcpy(OperandB, Tokenized);
				break;
			case 3:
				strcpy(OperandC, Tokenized);
				break;
		}
		Count++;
		Tokenized = strtok(NULL, " ,");
	}
	free(Data);
}

#define Instruction(Source, Destination, Opcode) if (!strcmp(Source, #Opcode)) { *Destination = __##Opcode; } else
#define Register(Source, Value, RegisterID, Mask) if (!strcmp(Source, "R" #RegisterID)) { *Value = strtoull(Source + 1, NULL, 10); *Regmap |= Mask; *PresentMap |= Mask; } else
void cgi_lexicalparse(char* OperationStr, char* OperandAStr, char* OperandBStr, char* OperandCStr, byte* Operation, u64* OperandA, u64* OperandB, u64* OperandC, byte* Regmap, byte* PresentMap) {
	char* SourceOperation = malloc(64);
	char* SourceOperandA = malloc(64);
	char* SourceOperandB = malloc(64);
	char* SourceOperandC = malloc(64);
	
	strcpy(SourceOperation, OperationStr);
	strcpy(SourceOperandA, OperandAStr);
	strcpy(SourceOperandB, OperandBStr);
	strcpy(SourceOperandC, OperandCStr);
	rtl_strupr(OperationStr, SourceOperation);
	rtl_strupr(OperandAStr, SourceOperandA);
	rtl_strupr(OperandBStr, SourceOperandB);
	rtl_strupr(OperandCStr, SourceOperandC);
	Instruction(SourceOperation, Operation, SET)
	Instruction(SourceOperation, Operation, LDWM)
	Instruction(SourceOperation, Operation, STWM)
	Instruction(SourceOperation, Operation, LDBM)
	Instruction(SourceOperation, Operation, STBM)
	Instruction(SourceOperation, Operation, OR)
	Instruction(SourceOperation, Operation, AND)
	Instruction(SourceOperation, Operation, XOR)
	Instruction(SourceOperation, Operation, NOT)
	Instruction(SourceOperation, Operation, ADD)
	Instruction(SourceOperation, Operation, SUB)
	Instruction(SourceOperation, Operation, MUL)
	Instruction(SourceOperation, Operation, DIV)
	Instruction(SourceOperation, Operation, SETI)
	Instruction(SourceOperation, Operation, LDWMI)
	Instruction(SourceOperation, Operation, STWMI)
	Instruction(SourceOperation, Operation, LDBMI)
	Instruction(SourceOperation, Operation, STBMI)
	Instruction(SourceOperation, Operation, ORI)
	Instruction(SourceOperation, Operation, ANDI)
	Instruction(SourceOperation, Operation, XORI)
	Instruction(SourceOperation, Operation, ADDI)
	Instruction(SourceOperation, Operation, SUBI)
	Instruction(SourceOperation, Operation, MULI)
	Instruction(SourceOperation, Operation, DIVI)
	Instruction(SourceOperation, Operation, SL)
	Instruction(SourceOperation, Operation, SR)
	Instruction(SourceOperation, Operation, SLI)
	Instruction(SourceOperation, Operation, SRI)
	Instruction(SourceOperation, Operation, SA)
	Instruction(SourceOperation, Operation, SP)
	Instruction(SourceOperation, Operation, SAI)
	Instruction(SourceOperation, Operation, GO)
	Instruction(SourceOperation, Operation, ENT)
	Instruction(SourceOperation, Operation, RT)
	Instruction(SourceOperation, Operation, RTF)
	Instruction(SourceOperation, Operation, RTFI)
	Instruction(SourceOperation, Operation, GOI)
	Instruction(SourceOperation, Operation, ENTI)
	Instruction(SourceOperation, Operation, CMP)
	Instruction(SourceOperation, Operation, CMPI)
	Instruction(SourceOperation, Operation, GOF)
	Instruction(SourceOperation, Operation, ENTF)
	Instruction(SourceOperation, Operation, ENTFI)
	Instruction(SourceOperation, Operation, ENTFII)
	Instruction(SourceOperation, Operation, GOFI)
	Instruction(SourceOperation, Operation, GOFII)
	Instruction(SourceOperation, Operation, NEG)
	Instruction(SourceOperation, Operation, EIH)
	Instruction(SourceOperation, Operation, DIH)
	Instruction(SourceOperation, Operation, HLT)
	Instruction(SourceOperation, Operation, INT)
	Instruction(SourceOperation, Operation, INTI)
	Instruction(SourceOperation, Operation, HND)
	Instruction(SourceOperation, Operation, HNDI)
	Instruction(SourceOperation, Operation, HNDII)
	Instruction(SourceOperation, Operation, SPA)
	Instruction(SourceOperation, Operation, SPG)
	Instruction(SourceOperation, Operation, SAA)
	Instruction(SourceOperation, Operation, SAG)
	Instruction(SourceOperation, Operation, LDSD)
	Instruction(SourceOperation, Operation, LDSDI)
	Instruction(SourceOperation, Operation, STSD)
	Instruction(SourceOperation, Operation, LDVM)
	Instruction(SourceOperation, Operation, LDVMI)
	Instruction(SourceOperation, Operation, STVM)
	Instruction(SourceOperation, Operation, SPN)
	Instruction(SourceOperation, Operation, MSP)
	Instruction(SourceOperation, Operation, SSP)
	Instruction(SourceOperation, Operation, ASP)
	Instruction(SourceOperation, Operation, SPB)
	Instruction(SourceOperation, Operation, SAB)
	Instruction(SourceOperation, Operation, SAII)
	Instruction(SourceOperation, Operation, INC)
	Instruction(SourceOperation, Operation, DEC)
	Instruction(SourceOperation, Operation, SBN)
	Instruction(SourceOperation, Operation, SBN)
	Instruction(SourceOperation, Operation, IOB)
	Instruction(SourceOperation, Operation, IIB)
	Instruction(SourceOperation, Operation, IOW)
	Instruction(SourceOperation, Operation, IIW)
	Instruction(SourceOperation, Operation, IOS)
	Instruction(SourceOperation, Operation, IIS)
	Instruction(SourceOperation, Operation, LDQM)
	Instruction(SourceOperation, Operation, LDQMI)
	Instruction(SourceOperation, Operation, LDHM)
	Instruction(SourceOperation, Operation, LDHMI)
	Instruction(SourceOperation, Operation, STQM)
	Instruction(SourceOperation, Operation, STQMI)
	Instruction(SourceOperation, Operation, STHM)
	Instruction(SourceOperation, Operation, STHMI) { // End of else
		ErrorLevel++;
		cgs_posterror(_CGS_INVALIDOP, SourceOperation, CurrentLine);
	}
	
	if (SourceOperandA[0]	 != '\0') {
		Register(SourceOperandA, OperandA, 0, 0b100)
		Register(SourceOperandA, OperandA, 1, 0b100)
		Register(SourceOperandA, OperandA, 2, 0b100)
		Register(SourceOperandA, OperandA, 3, 0b100)
		Register(SourceOperandA, OperandA, 4, 0b100)
		Register(SourceOperandA, OperandA, 5, 0b100)
		Register(SourceOperandA, OperandA, 6, 0b100)
		Register(SourceOperandA, OperandA, 7, 0b100)
		Register(SourceOperandA, OperandA, 8, 0b100)
		Register(SourceOperandA, OperandA, 9, 0b100)
		Register(SourceOperandA, OperandA, 10, 0b100)
		Register(SourceOperandA, OperandA, 11, 0b100)
		Register(SourceOperandA, OperandA, 12, 0b100)
		Register(SourceOperandA, OperandA, 13, 0b100)
		Register(SourceOperandA, OperandA, 14, 0b100)
		Register(SourceOperandA, OperandA, 15, 0b100) {
			*OperandA = strtoull(SourceOperandA, NULL, (int)cgi_getinfo(_PT_UPDATEBASE));
			*PresentMap |= 0b100;
		}
	}
	if (SourceOperandB[0] != '\0') {
		Register(SourceOperandB, OperandB, 0, 0b010)
		Register(SourceOperandB, OperandB, 1, 0b010)
		Register(SourceOperandB, OperandB, 2, 0b010)
		Register(SourceOperandB, OperandB, 3, 0b010)
		Register(SourceOperandB, OperandB, 4, 0b010)
		Register(SourceOperandB, OperandB, 5, 0b010)
		Register(SourceOperandB, OperandB, 6, 0b010)
		Register(SourceOperandB, OperandB, 7, 0b010)
		Register(SourceOperandB, OperandB, 8, 0b010)
		Register(SourceOperandB, OperandB, 9, 0b010)
		Register(SourceOperandB, OperandB, 10, 0b010)
		Register(SourceOperandB, OperandB, 11, 0b010)
		Register(SourceOperandB, OperandB, 12, 0b010)
		Register(SourceOperandB, OperandB, 13, 0b010)
		Register(SourceOperandB, OperandB, 14, 0b010)
		Register(SourceOperandB, OperandB, 15, 0b010) {
			*OperandB = strtoull(SourceOperandB, NULL, (int)cgi_getinfo(_PT_UPDATEBASE));
			*PresentMap |= 0b010;
		}
	}
	if (SourceOperandC[0] != '\0') {
		Register(SourceOperandC, OperandC, 0, 0b001)
		Register(SourceOperandC, OperandC, 1, 0b001)
		Register(SourceOperandC, OperandC, 2, 0b001)
		Register(SourceOperandC, OperandC, 3, 0b001)
		Register(SourceOperandC, OperandC, 4, 0b001)
		Register(SourceOperandC, OperandC, 5, 0b001)
		Register(SourceOperandC, OperandC, 6, 0b001)
		Register(SourceOperandC, OperandC, 7, 0b001)
		Register(SourceOperandC, OperandC, 8, 0b001)
		Register(SourceOperandC, OperandC, 9, 0b001)
		Register(SourceOperandC, OperandC, 10, 0b001)
		Register(SourceOperandC, OperandC, 11, 0b001)
		Register(SourceOperandC, OperandC, 12, 0b001)
		Register(SourceOperandC, OperandC, 13, 0b001)
		Register(SourceOperandC, OperandC, 14, 0b001)
		Register(SourceOperandC, OperandC, 15, 0b001) {
			*OperandC = strtoull(SourceOperandC, NULL, (int)cgi_getinfo(_PT_UPDATEBASE));
			*PresentMap |= 0b001;
		}
	}
	free(SourceOperation);
	free(SourceOperandA);
	free(SourceOperandB);
	free(SourceOperandC);
}
