//
//  data.c
//  plassemble
//
//  Created by Noah Wooten on 2/5/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "codegen.h"
cgctx_t* cgctx;

void cg_init(FILE* Output) {
	cgctx = malloc(sizeof(cgctx_t));
	memset(cgctx, 0, sizeof(cgctx_t));
	
	cgctx->PhysicalFile = Output;
}
void cg_shutdown(void) {
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
