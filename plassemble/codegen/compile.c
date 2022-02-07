//
//  compile.c
//  plassemble
//
//  Created by Noah Wooten on 2/6/22.
//

#include "codegen.h"
#include <stdlib.h>

void cg_line(char* Str) {
	byte PresentMap, RegMap;
	byte Opcode;
	u64 OperandA, OperandB, OperandC;
	
	char* StrOperation = malloc(64);
	char* StrOperandA = malloc(64);
	char* StrOperandB = malloc(64);
	char* StrOperandC = malloc(64);
	
	cgi_tokenize(Str, StrOperation, StrOperandA, StrOperandB, StrOperandC);
	cgi_lexicalparse(StrOperation, StrOperandA, StrOperandB, StrOperandC, &Opcode, &OperandA, &OperandB, &OperandC, &RegMap, &PresentMap);
	
	cg_emit(Opcode);
	if ((RegMap & 0b110) == 0b110) {
		union {
			byte Data;
			struct {
				byte Register0 : 4;
				byte Register1 : 4;
			};
		}Registers;
		Registers.Register0 = OperandA;
		Registers.Register1 = OperandB;
	}
	if ((RegMap & 0b111) == 0b011) {
		cg_emitw(OperandA, <#byte Count#>);
		union {
			byte Data;
			struct {
				byte Register0 : 4;
				byte Register1 : 4;
			};
		}Registers;
		Registers.Register0 = OperandB;
		Registers.Register1 = OperandC;
		
	}
	
	free(StrOperation);
	free(StrOperandA);
	free(StrOperandB);
	free(StrOperandC);
}
