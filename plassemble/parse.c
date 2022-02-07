//
//  parse.c
//  plassemble
//
//  Created by Noah Wooten on 2/5/22.
//

#include "root.h"
#include <stdlib.h>
#include <string.h>

#include "codegen/codegen.h"
#include "link/link.h"

void parse_stdfile(FILE* File) {
	char* Data = malloc(2048);
	fgets(Data, 2048, File);
	parse_string(Data);
	free(Data);
	return;
}

void parse_string(char* String) {
	CurrentLine++;
	if (strstr(String, "\r"))
		strstr(String, "\r")[0] = '\0';
	if (strstr(String, "\n"))
		strstr(String, "\n")[0] = '\0';
	
	if (strstr(String, "-a")) { // Assemble
		cg_compile();
	}
	
	if (strstr(String, "-e")) { // Extern function
		char* Data = malloc(241);
		strcpy(Data, String + 3);
		link_create(Data);
		free(Data);
	}
	
	if (strstr(String, "-s")) { // Semantics
		char* Data = malloc(241);
		strcpy(Data, String + 3);
		if (strstr(Data, "NumericalBase=")) {
			strcpy(Data, Data + strlen("NumericalBase="));
			cgi_notify(_PT_UPDATEBASE, strtol(Data, NULL, 10));
		}
		free(Data);
	}
	
	if (strstr(String, "-b")) { // Emit Byte
		char* Data = malloc(241);
		strcpy(Data, String + 3);
		byte RawData = (byte)strtoul(Data, NULL, (int)cgi_getinfo(_PT_UPDATEBASE)) & 0xFF;
		cg_emit(RawData);
		free(Data);
	}
	
	if (strstr(String, "-w")) { // Emit Word
		char* Data = malloc(241);
		strcpy(Data, String + 3);
		u64 RawData = strtoull(Data, NULL, (int)cgi_getinfo(_PT_UPDATEBASE));
		union {
			u64 Big;
			byte Small[8];
		}BigInt;
		BigInt.Big = RawData;
		for (int i = 0; i < 8; i++)
			cg_emit(BigInt.Small[i]);
		free(Data);
	}
	
	if (strstr(String, "-z")) { // Emit NUL-termined string
		char* Data = malloc(2049);
		strcpy(Data, String + 3);
		for (int i = 0; i < strlen(Data); i++)
			cg_emit(Data[i]);
		cg_emit(0x00);
	}
	
	cg_line(String);
}
