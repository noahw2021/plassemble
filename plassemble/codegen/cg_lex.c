//
//  cg_lex.c
//  plassemble
//
//  Created by Noah Wooten on 2/6/22.
//

#include "codegen.h"
#include "ops.h"
#include "../psin/psin.h"
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
	
	u32 InstructionLexicalIterator = psin_getbymnemonic(SourceOperation);
	if (InstructionLexicalIterator == 0xFFFFFFFF) {
		ErrorLevel++;
		cgs_posterror(_CGS_INVALIDOP, SourceOperation, CurrentLine);
	} else {
		*Operation = psin_getopcode(InstructionLexicalIterator);
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
