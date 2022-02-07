//
//  link_reloc.c
//  plassemble
//
//  Created by Noah Wooten on 2/7/22.
//

#include "link.h"
#include "../codegen/codegen.h"
extern u32 LinkSymbolCount;
extern u32 LinkRelocCount;

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void link_notify(char* Name, u64 Location, byte Offset) {
	for (int i = 0; i < LinkSymbolCount; i++) {
		if (!strcmp(linkctx[i].SymbolName, Name)) {
			if (!relocctx)
				relocctx = malloc(sizeof(relocctx_t) * (LinkRelocCount + 1));
			else
				relocctx = realloc(relocctx, sizeof(relocctx_t) * (LinkRelocCount + 1));
			
			relocctx[LinkRelocCount].LinkedSymbolIterator = i;
			relocctx[LinkRelocCount].PhysicalLocation = Location + Offset + 1; // account for opcode
			relocctx[LinkRelocCount].Resolved = 0;
			
			LinkRelocCount++;
			return;
		}
	}
}
void link_ready(void) {
	for (int i = 0; i < LinkRelocCount; i++) {
		if (!relocctx[i].Resolved) {
			u32 Output = ftell(cgctx->PhysicalFile);
			fseek(cgctx->PhysicalFile, relocctx[i].PhysicalLocation, SEEK_SET);
			fwrite(&linkctx[relocctx[i].LinkedSymbolIterator].Value, 8, 1, cgctx->PhysicalFile);
			fseek(cgctx->PhysicalFile, Output, SEEK_SET);
		}
	}
}
