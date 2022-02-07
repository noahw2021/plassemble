//
//  psin_loadint.c
//  plassemble
//
//  Created by Noah Wooten on 2/7/22.
//

#include "psin.h"
#include <stdlib.h>
#include <string.h>

void psini_createinst(byte Opcode, byte OperandA, byte OperandB, byte OperandC, byte Regmap, byte PresentMap, char* Name) {
	if (InstructionCount == 0)
		InstructionMap = malloc((InstructionCount + 1) * sizeof(psinentry_t));
	else
		InstructionMap = realloc(InstructionMap, (InstructionCount + 1) * sizeof(psinentry_t));
	
	memset(&InstructionMap[InstructionCount], 0, sizeof(psinentry_t));
	InstructionMap[InstructionCount].PresentMap = PresentMap;
	InstructionMap[InstructionCount].RegMap = Regmap;
	InstructionMap[InstructionCount].Opcode = Opcode;
	strncpy(InstructionMap[InstructionCount].Mnemonic, Name, 23);
	InstructionMap[InstructionCount].OperandASize = OperandA;
	InstructionMap[InstructionCount].OperandBSize = OperandB;
	InstructionMap[InstructionCount].OperandCSize = OperandC;

	InstructionCount++;
	return;
}

u32 psin_declare(const char* Instruction) {
	
}
