//
//  root.h
//  plassemble
//
//  Created by Noah Wooten on 2/5/22.
//

#ifndef root_h
#define root_h
#include <stdio.h>

typedef unsigned char byte;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef char i8, str;
typedef short i16;
typedef long i32;
typedef long long i64;

void parse_stdfile(FILE* File);
void parse_string(char* String);

char* rtl_strupr(char* Source, char* Destination);

#endif /* root_h */
