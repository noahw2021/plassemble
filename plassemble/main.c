//
//  main.c
//  plassemble
//
//  Created by Noah Wooten on 2/2/22.
//

#include <stdio.h>
#include <string.h>

#include "ui/ui.h"

#define ArgumentBody(Source, Name) if (!strcmp(Source, Name))
int main(int argc, char** argv) {
	if (argc < 2) {
		aui_showhelp(argc, argv);
		return 0;
	}
	
	char* Source = argv[1];
	ArgumentBody(Source, "-a") { // Assembler in interactive mode
		
	}
	
	ArgumentBody(Source, "-f") { // Assembler in file mode
		
	}
	
	ArgumentBody(Source, "-h") { // Help
		aui_showhelp(argc, argv);
	}
	
	ArgumentBody(Source, "-s") { // Display syntax
		
	}
}
