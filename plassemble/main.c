//
//  main.c
//  plassemble
//
//  Created by Noah Wooten on 2/2/22.
//

#include <stdio.h>
#include <string.h>

#define ArgumentBody(Source, Name) if (!strcmp(Source, Name))
int main(int argc, char** argv) {
	if (argc < 2) {
		printf("Plassemble: PLASM assembler.\n");
		printf("%s -a (outfile): Start assembler in interactive mode.\n", argv[0]);
		printf("%s -f (outfile) (infile): Start assembler with file.\n", argv[0]);
		printf("%s -h: Show this screen.\n", argv[0]);
		printf("%s -s: Display syntax.\n", argv[0]);
	}
	
	char* Source = argv[1];
	ArgumentBody(Source, "-a") {
		
	}
	
	ArgumentBody(Source, "-f") {
		
	}
	
	ArgumentBody(Source, "-h") {
		
	}
	
	ArgumentBody(Source, "-s") {
		
	}
}
