//
//  rtl.c
//  plassemble
//
//  Created by Noah Wooten on 2/6/22.
//

#include "root.h"
#include <string.h>

#define rtl_toupr(c)	((c) >= 'a' && (c) <= 'z' ? (c) - 0x20: (c))
char* rtl_strupr(char* Source, char* Destination) {
	u32 Length = strlen(Source);
	strcpy(Destination, Source);
	
	for (int i = 0; i < Length; i++)
		Destination[i] = rtl_toupr(Destination[i]);
	
	return Destination;
}
