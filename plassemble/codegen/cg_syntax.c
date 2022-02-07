//
//  cg_syntax.c
//  plassemble
//
//  Created by Noah Wooten on 2/7/22.
//

#include "codegen.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct cgserror {
	str Message[256];
	u32 Line;
	byte ErrorMsg;
	str Argument[64];
	u32 Code;
}cgserror_t;
u32 ErrorCount;
cgserror_t* ErrorList;

void cgs_init(void) {
	ErrorList = NULL;
	return;
}
void cgs_shutdown(void) {
	if (ErrorList)
		free(ErrorList);
}
void cgs_posterror(byte Type, char* Argument, u32 Line) {
	if (!ErrorList)
		ErrorList = malloc(sizeof(cgserror_t) * (ErrorCount + 1));
	else
		ErrorList = realloc(ErrorList, sizeof(cgserror_t) * (ErrorCount + 1));
	
	memset(&ErrorList[ErrorCount], 0, sizeof(cgserror_t));
	ErrorList[ErrorCount].Code = Type;
	strncpy(ErrorList[ErrorCount].Argument, Argument, 63);
	ErrorList[ErrorCount].Line = Line;
	
	char* PrettyErrorStr = malloc(256);
	
	switch (Type) {
		case _CGS_TOOBIGIMM:
			strcpy(PrettyErrorStr, "Immediate too big");
			break;
		case _CGS_INVALIDOP:
			strcpy(PrettyErrorStr, "Invalid operation");
			break;
		case _CGS_INVALIDARG:
			strcpy(PrettyErrorStr, "Invalid argument");
			break;
		case _CGS_INVALIDREG:
			strcpy(PrettyErrorStr, "Invalid register");
			break;
		default:
			strcpy(PrettyErrorStr, "Unexpected error");
			break;
	}
	
	sprintf(ErrorList[ErrorCount].Message, "[E%04u]: Error %s at line %lu, '%s' is unexpected.\n", Type,
		PrettyErrorStr, Line, Argument);
	ErrorCount++;
}

byte cgs_reduce(u64 Variable) {
	union {
		u64 Big;
		byte Small[8];
	}BigInt;
	BigInt.Big = Variable;
	int i = 8;
	while (i) {
		if (BigInt.Small[i])
			return i;
		i--;
	}
	return 1;
}

u32 cgs_geterrorcnt(void){
	return ErrorCount;
}
char* cgs_geterrorstr(int Reference) {
	return ErrorList[Reference].Message;
}
