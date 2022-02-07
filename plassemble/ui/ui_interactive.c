//
//  ui_interactive.c
//  plassemble
//
//  Created by Noah Wooten on 2/5/22.
//

#include "ui.h"
#include "../codegen/codegen.h"
#include <stdio.h>
extern u32 GlobalDone;

// printf("%s -a (outfile): Start assembler in interactive mode.\n", argv[0]);
void aui_interactive(int argc, char** argv) {
	char* Outfile = argv[2];
	if (!Outfile) {
		printf("[ERR]: No outfile!\n");
		return;
	}
	
	FILE* Output = fopen(Outfile, "wb");
	if (!Output) {
		printf("[ERR]: Failed to open file!\n");
		return;
	}
	cg_init(Output);
	
	while (1) {
		parse_stdfile(stdin);
		if (GlobalDone)
			break;
	}
	cg_shutdown();
	printf("[INFO]: Compiled!\n");
	fclose(Output);
	return;
}
