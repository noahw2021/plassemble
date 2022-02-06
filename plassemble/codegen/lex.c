//
//  lex.c
//  plassemble
//
//  Created by Noah Wooten on 2/6/22.
//

#include "codegen.h"
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

#define Instruction(Source, Destination, Opcode) if (!strcmp(Source, #Opcode)) { *Destination = Opcode; }

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

	
	
	free(SourceOperation);
	free(SourceOperandA);
	free(SourceOperandB);
	free(SourceOperandC);
}
