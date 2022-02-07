//
//  link.h
//  plassemble
//
//  Created by Noah Wooten on 2/5/22.
//

#ifndef link_h
#define link_h
#include "../root.h"

void link_init(void);
void link_shutdown(void);


void link_notify(char* Name, u64 Location, byte Offset);
void link_ready(void);

u64 link_getsymbol(char* Name);
byte link_isfuture(char* Name);
void link_create(char* Name);
void link_resolve(char* Name, u64 Location);
u64 link_dynamicreplace(char* Operand);

typedef struct _linkctx {
	char SymbolName[256];
	u64 Value;
	byte Resolved;
}linkctx_t;

typedef struct _relocctx {
	u32 LinkedSymbolIterator;
	u64 PhysicalLocation;
	byte Resolved;
}relocctx_t;
extern linkctx_t* linkctx;
extern relocctx_t* relocctx;

#endif /* link_h */
