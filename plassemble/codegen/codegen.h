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

#define _PT_UPDATEBASE	0x00

void cgi_notify(byte Point, u32 Data);
u32 cgi_getinfo(byte Point);

#endif /* codegen_h */
