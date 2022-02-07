//
//  link_symbols.c
//  plassemble
//
//  Created by Noah Wooten on 2/7/22.
//

#include "link.h"
#include <string.h>
#include <stdlib.h>
extern u32 LinkSymbolCount;
extern u32 LinkRelocCount;

u64 link_getsymbol(char* Name) {
	for (int i = 0; i < LinkSymbolCount; i++) {
		if (!strcmp(linkctx[i].SymbolName, Name)) {
			return linkctx[i].Value;
		}
	}
	return 0;
}

byte link_isfuture(char* Name) {
	for (int i = 0; i < LinkSymbolCount; i++) {
		if (!strcmp(linkctx[i].SymbolName, Name)) {
			return !linkctx[i].Resolved;
		}
	}
	return 0;
}

void link_create(char* Name) {
	if (!linkctx)
		linkctx = malloc(sizeof(linkctx_t) * (LinkSymbolCount + 1));
	else
		linkctx = realloc(linkctx, sizeof(linkctx_t) * (LinkSymbolCount + 1));
	memset(&linkctx[LinkSymbolCount], 0, sizeof(linkctx_t));
	
	strncpy(linkctx[LinkSymbolCount].SymbolName, Name, 64);
	linkctx[LinkSymbolCount].Resolved = 0;
	linkctx[LinkSymbolCount].Value = 0;
	LinkSymbolCount++;
}

void link_resolve(char* Name, u64 Location) {
	for (int i = 0; i < LinkSymbolCount; i++) {
		if (!strcmp(linkctx[i].SymbolName, Name)) {
			linkctx[i].Value = Location;
			linkctx[i].Resolved = 1;
			return;
		}
	}
}
