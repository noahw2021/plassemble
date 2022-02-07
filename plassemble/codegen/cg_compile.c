//
//  cg_compile.c
//  plassemble
//
//  Created by Noah Wooten on 2/7/22.
//

#include "codegen.h"
#include "../link/link.h"

void cg_compile(void) {
	link_ready();
	cg_shutdown();
}
