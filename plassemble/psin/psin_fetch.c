//
//  psin_fetch.c
//  plassemble
//
//  Created by Noah Wooten on 2/7/22.
//

#include "psin.h"
#include <stdlib.h>
#include <string.h>

u32 psin_getbyopcode(byte Opcode) {
	for (int i = 0; i < InstructionCount; i++) {
		if (InstructionMap[i].Opcode == Opcode)
			return i;
	}
	return 0xFFFFFFFF;
}
u32 psin_getbymnemonic(char* Mnemonic) {
	char* Uppercased = malloc(strlen(Mnemonic) + 1);
	rtl_strupr(Mnemonic, Uppercased);
	
	for (int i = 0; i < InstructionCount; i++) {
		if (!strcmp(InstructionMap[i].Mnemonic, Uppercased)) {
			free(Uppercased);
			return i;
		}
	}
	
	free(Uppercased);
	return 0xFFFFFFFF;
}
