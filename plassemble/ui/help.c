//
//  help.c
//  plassemble
//
//  Created by Noah Wooten on 2/5/22.
//

#include <stdio.h>
#include "ui.h"

void aui_help(int argc, char** argv) {
	printf("Plassemble: PLASM assembler.\n");
	printf("%s -a (outfile): Start assembler in interactive mode.\n", argv[0]);
	printf("%s -f (outfile) (infile): Start assembler with file.\n", argv[0]);
	printf("%s -h: Show this screen.\n", argv[0]);
	printf("%s -s: Display syntax.\n", argv[0]);
	return;
}
