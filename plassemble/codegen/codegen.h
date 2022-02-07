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
void cg_emitw(u64 Data, byte Count);
void cg_line(char* Str);
void cg_compile(void);

void cgi_tokenize(char* Source, char* Operation, char* OperandA, char* OperandB, char* OperandC);
void cgi_lexicalparse(char* OperationStr, char* OperandAStr, char* OperandBStr, char* OperandCStr, byte* Operation, u64* OperandA, u64* OperandB, u64* OperandC, byte* Regmap, byte* PresentMap);
void cgi_loadintructions(void);

#define _CGS_INVALIDOP  0x00
#define _CGS_INVALIDREG 0x01
#define _CGS_TOOBIGIMM	0x02
#define _CGS_INVALIDARG 0x03

void cgs_init(void);
void cgs_shutdown(void);
void cgs_posterror(byte Type, char* Argument, u32 Line);
byte cgs_reduce(u64 Variable);

u32 cgs_geterrorcnt(void);
char* cgs_geterrorstr(int Reference);

#define _PT_UPDATEBASE	0x00

void cgi_notify(byte Point, u32 Data);
u32 cgi_getinfo(byte Point);

typedef struct _cgctx {
	FILE* PhysicalFile;
	u32 NumericalBase;
}cgctx_t;

extern cgctx_t* cgctx;
extern u32 ErrorLevel;
extern u32 CurrentLine;

#endif /* codegen_h */
