//
//  cg_semantics.c
//  plassemble
//
//  Created by Noah Wooten on 2/7/22.
//

#include "codegen.h"

void cgi_notify(byte Point, u32 Data) {
	switch (Point) {
		case _PT_UPDATEBASE:
			cgctx->NumericalBase = Data;
			break;
	}
}
u32 cgi_getinfo(byte Point) {
	switch (Point) {
		case _PT_UPDATEBASE:
			return cgctx->NumericalBase;
	}
	return 0;
}
