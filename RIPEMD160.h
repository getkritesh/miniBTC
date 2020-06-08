#ifndef RIPEMD160_H

#define RIPEMD160_H

#include <stdint.h>	// Include stdint.h; available on most compilers but, if not, a copy is provided here for Microsoft Visual Studio


void computeRIPEMD160(const void *input,	// The input data to compute the hash for.
					  uint32_t length,		// The length of the input data
					  uint8_t hashcode[20]); // The output hash of 160 bits (20 bytes)

#endif
