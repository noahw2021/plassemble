//
//  ui_filemode.c
//  plassemble
//
//  Created by Noah Wooten on 2/7/22.
//

#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include "../codegen/codegen.h"
#include "../link/link.h"
extern u32 GlobalDone;
extern u32 CurrentLine;

void aui_filemode(int argc, char** argv) {
	char* Outfile = argv[2];
	char* Infile = argv[3];
	if (!Outfile) {
		printf("[ERR]: No outfile!\n");
		return;
	}
	if (!Infile) {
		printf("[ERR]: No infile!\n");
		return;
	}
	
	FILE* Output = fopen(Outfile, "wb");
	FILE* Input = fopen(Infile, "r");
	if (!Output) {
		printf("[ERR]: Failed to open output file!\n");
		return;
	}
	if (!Input) {
		printf("[ERR]: Failed to open input file!\n");
	}
	cg_init(Output);
	
	while (1) {
		parse_stdfile(Input);
		if (GlobalDone)
			break;
	}
	cg_shutdown();
	printf("[INFO]: Compiled %d bytes in %d lines!\n", ftell(Output), CurrentLine);
	fclose(Output);
	return;
}
