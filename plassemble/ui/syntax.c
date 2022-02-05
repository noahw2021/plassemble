//
//  syntax.c
//  plassemble
//
//  Created by Noah Wooten on 2/5/22.
//

#include "ui.h"
#include <stdio.h>

void aui_showsyntax(int argc, char** argv) {
	printf("Plassemble is an assembler that generate code for the PLASM architecture.\n");
	printf("Below, a list of non-instruction operations are displayed.\n");
	printf("-a: Assemble: Compiles and links current file.\n");
	printf("-b: Emit Byte: Emits a raw byte in the current numerical base.\n");
	printf("-e: Extern Function: Creates a function that can be called now but is defined later.\n");
	printf("-s Semantic=Value: Semantic: Update a semantic value that changes how the assembler processes information.\n");
	printf("-w: Emit Word: Emits a raw word (8 bytes).\n");
	printf("-z: Emit String: Emits a ASCII NUL-termined string.\n");
	printf("\nSemantics:");
	printf("NumericalBase: How numbers are interpreted. (2-36)\n");
	printf("\n");
	return;
}
