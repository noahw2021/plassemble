//
//  codegen.h
//  plassemble
//
//  Created by Noah Wooten on 2/5/22.
//

#ifndef codegen_h
#define codegen_h
#include <stdio.h>

#include "../root.h"

void cg_init(FILE* Output);
void cg_shutdown(void);

void cg_emit(byte Data);
void cg_line(char* Str);
void cg_compile(void);

void cgi_tokenize(char* Source, char* Operation, char* OperandA, char* OperandB, char* OperandC);
void cgi_lexicalparse(char* OperationStr, char* OperandAStr, char* OperandBStr, char* OperandCStr, byte* Operation, u64* OperandA, u64* OperandB, u64* OperandC, byte* Regmap, byte* PresentMap);

#define _PT_UPDATEBASE	0x00

void cgi_notify(byte Point, u32 Data);
u32 cgi_getinfo(byte Point);

typedef struct _cgctx {
	FILE* PhysicalFile;
	u32 NumericalBase;
}cgctx_t;
extern cgctx_t* cgctx;

#endif /* codegen_h */
