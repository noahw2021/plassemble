//
//  lex.c
//  plassemble
//
//  Created by Noah Wooten on 2/6/22.
//

#include "codegen.h"
#include "ops.h"
#include <stdlib.h>
#include <string.h>

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
#define Register(Source, Destination, ID) if (!strcmp(Source, "R" #ID)) { *Destination = ID; if (Source == SourceOperandA) { *Regmap |= 0b100; *PresentMap |= 0b100; } else if (Source == SourceOperandB) { *Regmap |= 0b010; *PresentMap |= 0b010; } else if (Source == SourceOperandC) { *Regmap |= 0b001; *PresentMap |= 0b001; } } else if (strtoull(Source, NULL, 10) != 0) { if (Source == SourceOperandA) { *PresentMap |= 0b100; } else if (Source == SourceOperandB) { *PresentMap |= 0b010; } else if (Source == SourceOperandC) { *PresentMap |= 0b001; } }

void cgi_lexicalparse(char* OperationStr, char* OperandAStr, char* OperandBStr, char* OperandCStr, byte* Operation, u64* OperandA, u64* OperandB, u64* OperandC, byte* Regmap, byte* PresentMap) {
	
	char* SourceOperation = malloc(64);
	char* SourceOperandA = malloc(64);
	char* SourceOperandB = malloc(64);
	char* SourceOperandC = malloc(64);
	
	strcpy(SourceOperation, OperationStr);
	strcpy(SourceOperandA, OperandAStr);
	strcpy(SourceOperandB, OperandBStr);
	strcpy(SourceOperandC, OperandCStr);
	rtl_strupr(SourceOperation, SourceOperation);
	rtl_strupr(SourceOperandA, SourceOperandA);
	rtl_strupr(SourceOperandB, SourceOperandB);
	rtl_strupr(SourceOperandC, SourceOperandC);

	Instruction(SourceOperation, Operation, SET);
	Instruction(SourceOperation, Operation, LDWM);
	Instruction(SourceOperation, Operation, STWM);
	Instruction(SourceOperation, Operation, LDBM);
	Instruction(SourceOperation, Operation, STBM);
	Instruction(SourceOperation, Operation, OR);
	Instruction(SourceOperation, Operation, AND);
	Instruction(SourceOperation, Operation, XOR);
	Instruction(SourceOperation, Operation, NOT);
	Instruction(SourceOperation, Operation, ADD);
	Instruction(SourceOperation, Operation, SUB);
	Instruction(SourceOperation, Operation, MUL);
	Instruction(SourceOperation, Operation, DIV);
	Instruction(SourceOperation, Operation, SETI);
	Instruction(SourceOperation, Operation, LDWMI);
	Instruction(SourceOperation, Operation, STWMI);
	Instruction(SourceOperation, Operation, LDBMI);
	Instruction(SourceOperation, Operation, STBMI);
	Instruction(SourceOperation, Operation, ORI);
	Instruction(SourceOperation, Operation, ANDI);
	Instruction(SourceOperation, Operation, XORI);
	Instruction(SourceOperation, Operation, ADDI);
	Instruction(SourceOperation, Operation, SUBI);
	Instruction(SourceOperation, Operation, MULI);
	Instruction(SourceOperation, Operation, DIVI);
	Instruction(SourceOperation, Operation, SL);
	Instruction(SourceOperation, Operation, SR);
	Instruction(SourceOperation, Operation, SLI);
	Instruction(SourceOperation, Operation, SRI);
	Instruction(SourceOperation, Operation, SA);
	Instruction(SourceOperation, Operation, SP);
	Instruction(SourceOperation, Operation, SAI);
	Instruction(SourceOperation, Operation, GO);
	Instruction(SourceOperation, Operation, ENT);
	Instruction(SourceOperation, Operation, RT);
	Instruction(SourceOperation, Operation, RTF);
	Instruction(SourceOperation, Operation, RTFI);
	Instruction(SourceOperation, Operation, GOI);
	Instruction(SourceOperation, Operation, ENTI);
	Instruction(SourceOperation, Operation, CMP);
	Instruction(SourceOperation, Operation, CMPI);
	Instruction(SourceOperation, Operation, GOF);
	Instruction(SourceOperation, Operation, ENTF);
	Instruction(SourceOperation, Operation, ENTFI);
	Instruction(SourceOperation, Operation, ENTFII);
	Instruction(SourceOperation, Operation, GOFI);
	Instruction(SourceOperation, Operation, GOFII);
	Instruction(SourceOperation, Operation, NEG);
	Instruction(SourceOperation, Operation, EIH);
	Instruction(SourceOperation, Operation, DIH);
	Instruction(SourceOperation, Operation, HLT);
	Instruction(SourceOperation, Operation, INT);
	Instruction(SourceOperation, Operation, INTI);
	Instruction(SourceOperation, Operation, HND);
	Instruction(SourceOperation, Operation, HNDI);
	Instruction(SourceOperation, Operation, HNDII);
	Instruction(SourceOperation, Operation, SPA);
	Instruction(SourceOperation, Operation, SPG);
	Instruction(SourceOperation, Operation, SAA);
	Instruction(SourceOperation, Operation, SAG);
	Instruction(SourceOperation, Operation, LDSD);
	Instruction(SourceOperation, Operation, LDSDI);
	Instruction(SourceOperation, Operation, STSD);
	Instruction(SourceOperation, Operation, LDVM);
	Instruction(SourceOperation, Operation, LDVMI);
	Instruction(SourceOperation, Operation, STVM);
	Instruction(SourceOperation, Operation, SPN);
	Instruction(SourceOperation, Operation, MSP);
	Instruction(SourceOperation, Operation, SSP);
	Instruction(SourceOperation, Operation, ASP);
	Instruction(SourceOperation, Operation, SPB);
	Instruction(SourceOperation, Operation, SAB);
	Instruction(SourceOperation, Operation, SAII);
	Instruction(SourceOperation, Operation, INC);
	Instruction(SourceOperation, Operation, DEC);
	Instruction(SourceOperation, Operation, SBN);
	Instruction(SourceOperation, Operation, SBN);
	Instruction(SourceOperation, Operation, IOB);
	Instruction(SourceOperation, Operation, IIB);
	Instruction(SourceOperation, Operation, IOW);
	Instruction(SourceOperation, Operation, IIW);
	Instruction(SourceOperation, Operation, IOS);
	Instruction(SourceOperation, Operation, IIS);
	Instruction(SourceOperation, Operation, LDQM);
	Instruction(SourceOperation, Operation, LDQMI);
	Instruction(SourceOperation, Operation, LDHM);
	Instruction(SourceOperation, Operation, LDHMI);
	Instruction(SourceOperation, Operation, STQM);
	Instruction(SourceOperation, Operation, STQMI);
	Instruction(SourceOperation, Operation, STHM);
	Instruction(SourceOperation, Operation, STHMI) { // End of else
		
	}
	
	Register(SourceOperandA, OperandA, 0);
	Register(SourceOperandA, OperandA, 1);
	Register(SourceOperandA, OperandA, 2);
	Register(SourceOperandA, OperandA, 3);
	Register(SourceOperandA, OperandA, 4);
	Register(SourceOperandA, OperandA, 5);
	Register(SourceOperandA, OperandA, 6);
	Register(SourceOperandA, OperandA, 7);
	Register(SourceOperandA, OperandA, 8);
	Register(SourceOperandA, OperandA, 9);
	Register(SourceOperandA, OperandA, 10);
	Register(SourceOperandA, OperandA, 11);
	Register(SourceOperandA, OperandA, 12);
	Register(SourceOperandA, OperandA, 13);
	Register(SourceOperandA, OperandA, 14);
	Register(SourceOperandA, OperandA, 15);
	
	Register(SourceOperandB, OperandB, 0);
	Register(SourceOperandB, OperandB, 1);
	Register(SourceOperandB, OperandB, 2);
	Register(SourceOperandB, OperandB, 3);
	Register(SourceOperandB, OperandB, 4);
	Register(SourceOperandB, OperandB, 5);
	Register(SourceOperandB, OperandB, 6);
	Register(SourceOperandB, OperandB, 7);
	Register(SourceOperandB, OperandB, 8);
	Register(SourceOperandB, OperandB, 9);
	Register(SourceOperandB, OperandB, 10);
	Register(SourceOperandB, OperandB, 11);
	Register(SourceOperandB, OperandB, 12);
	Register(SourceOperandB, OperandB, 13);
	Register(SourceOperandB, OperandB, 14);
	Register(SourceOperandB, OperandB, 15);
	
	Register(SourceOperandC, OperandC, 0);
	Register(SourceOperandC, OperandC, 1);
	Register(SourceOperandC, OperandC, 2);
	Register(SourceOperandC, OperandC, 3);
	Register(SourceOperandC, OperandC, 4);
	Register(SourceOperandC, OperandC, 5);
	Register(SourceOperandC, OperandC, 6);
	Register(SourceOperandC, OperandC, 7);
	Register(SourceOperandC, OperandC, 8);
	Register(SourceOperandC, OperandC, 9);
	Register(SourceOperandC, OperandC, 10);
	Register(SourceOperandC, OperandC, 11);
	Register(SourceOperandC, OperandC, 12);
	Register(SourceOperandC, OperandC, 13);
	Register(SourceOperandC, OperandC, 14);
	Register(SourceOperandC, OperandC, 15);
	
	
	free(SourceOperation);
	free(SourceOperandA);
	free(SourceOperandB);
	free(SourceOperandC);
}
