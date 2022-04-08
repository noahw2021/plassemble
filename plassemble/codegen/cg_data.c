//
//  cg_data.c
//  plassemble
//
//  Created by Noah Wooten on 2/5/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "codegen.h"
#include "../link/link.h"
#include "../psin/psin.h"
cgctx_t* cgctx;

void cg_init(FILE* Output) {
	cgctx = malloc(sizeof(cgctx_t));
	memset(cgctx, 0, sizeof(cgctx_t));
	
	cgctx->PhysicalFile = Output;
	cgctx->NumericalBase = 10;
	ErrorLevel = 0;
	CurrentLine = 0;
	
	link_init();
	psin_init();
	cgs_init();
	cgi_loadintructions();
}
void cg_shutdown(void) {
	cgs_shutdown();
	link_shutdown();
	psin_shutdown();
	free(cgctx);
}

void cg_emit(byte Emit) {
	fputc(Emit, cgctx->PhysicalFile);
}

void cg_emitw(u64 Data, byte Count) {
	union {
		u64 Big;
		byte Small[8];
	}MedInt;
	MedInt.Big = Data;
	for (int i = 0; i < Count; i++)
		cg_emit(MedInt.Small[i]);
}
