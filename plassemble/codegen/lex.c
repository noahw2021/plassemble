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
void cgi_lexicalparse(char* OperationStr, char* OperandAStr, char* OperandBStr, char* OperandCStr, byte* Operation, u64* OperandA, u64* OperandB, u64* OperandC, byte* Regmap, byte* PresentMap) {
	
}
