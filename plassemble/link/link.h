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

u64 link_getsymbol(char* Name);
byte link_isfuture(char* Name);
void link_notify(char* Name, u64 Location, byte Offset);
void link_ready(void);
void link_create(char* Name);

#endif /* link_h */
