//
//  cg_line.c
//  plassemble
//
//  Created by Noah Wooten on 2/6/22.
//

#include "codegen.h"
#include "../psin/psin.h"
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
	
	u32 PsinLexicalIterator = psin_getbyopcode(Opcode);
	if (psin_getregmap(PsinLexicalIterator) != RegMap) {
		char* GeneratedArgument = NULL;
		byte Contrast = RegMap ^ psin_getregmap(PsinLexicalIterator);
		if (Contrast & 0b100)
			GeneratedArgument = StrOperandA;
		if (Contrast & 0b010)
			GeneratedArgument = StrOperandB;
		if (Contrast & 0b001)
			GeneratedArgument = StrOperandC;
	
		cgs_posterror(_CGS_INVALIDREG, GeneratedArgument, CurrentLine);
		return;
	}
	if (psin_getpresentmap(PsinLexicalIterator) != PresentMap) {
		char* GeneratedArgument = NULL;
		byte Contrast = PresentMap ^ psin_getregmap(PsinLexicalIterator);
		if (Contrast & 0b100)
			GeneratedArgument = StrOperandA;
		if (Contrast & 0b010)
			GeneratedArgument = StrOperandB;
		if (Contrast & 0b001)
			GeneratedArgument = StrOperandC;
	
		cgs_posterror(_CGS_INVALIDARG, GeneratedArgument, CurrentLine);
		return;
	}
	
	if (PresentMap & 0b100) {
		if (cgs_reduce(OperandA) > psin_getoperandasize(PsinLexicalIterator))
			cgs_posterror(_CGS_TOOBIGIMM, StrOperandA, CurrentLine);
	}
	if (PresentMap & 0b010) {
		if (cgs_reduce(OperandB) > psin_getoperandbsize(PsinLexicalIterator))
			cgs_posterror(_CGS_TOOBIGIMM, StrOperandB, CurrentLine);
	}
	if (PresentMap & 0b001) {
		if (cgs_reduce(OperandC) > psin_getoperandcsize(PsinLexicalIterator))
			cgs_posterror(_CGS_TOOBIGIMM, StrOperandC, CurrentLine);
	}
	
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
		cg_emit(Registers.Data);
		if ((PresentMap & 0b001) == 0b001)
			cg_emitw(OperandC, psin_getoperandcsize(PsinLexicalIterator) / 8);
		goto EndLine;
	} else
	if ((RegMap & 0b111) == 0b011) {
		cg_emitw(OperandA, psin_getoperandasize(PsinLexicalIterator) / 8);
		union {
			byte Data;
			struct {
				byte Register0 : 4;
				byte Register1 : 4;
			};
		}Registers;
		Registers.Register0 = OperandB;
		Registers.Register1 = OperandC;
		cg_emit(Registers.Data);
		goto EndLine;
	} else {
		cg_emitw(OperandA, psin_getoperandasize(PsinLexicalIterator));
		cg_emitw(OperandB, psin_getoperandasize(PsinLexicalIterator));
		cg_emitw(OperandC, psin_getoperandasize(PsinLexicalIterator));
	}
	
EndLine:
	free(StrOperation);
	free(StrOperandA);
	free(StrOperandB);
	free(StrOperandC);
}
