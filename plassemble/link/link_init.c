//
//  link_init.c
//  plassemble
//
//  Created by Noah Wooten on 2/7/22.
//

#include "link.h"
#include <stdlib.h>
#include <string.h>

linkctx_t* linkctx;
relocctx_t* relocctx;
u32 LinkSymbolCount;
u32 LinkRelocCount;

void link_init(void) {
	LinkSymbolCount = 0;
	LinkRelocCount = 0;
}
void link_shutdown(void) {
	if (linkctx)
		free(linkctx);
	if (relocctx)
		free(relocctx);
}
