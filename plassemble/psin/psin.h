//
//  psin.h
//  plassemble
//
//  Created by Noah Wooten on 2/7/22.
//

#ifndef psin_h
#define psin_h
#include "../root.h"

void psin_init(void);
void psin_shutdown(void);

u32 psin_declare(const char* Instruction);
char* psin_getsyntax(void);

char* psin_parseline(byte Opcode, word OperandA, word OperandB, word OperandC, byte Regmap);

typedef struct psinentry {
	str Mnemonic[16];
	byte Opcode;
	byte RegMap;
	byte PresentMap;
	byte OperandASize;
	byte OperandBSize;
	byte OperandCSize;
}psinentry_t;
extern psinentry_t* InstructionMap;

#endif /* psin_h */
