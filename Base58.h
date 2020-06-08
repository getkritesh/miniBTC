#ifndef BASE58_H

#define BASE58_H

#include <stdint.h>


bool encodeBase58(const uint8_t *bigNumber, // The block of memory corresponding to the 'big number'
					   uint32_t length,			 // The number of bytes in the 'big-number'; this will be 25 for a bitcoin address
					   bool sourceIsBigEndian,	 // True if the input number is in big-endian format (this will be true for a bitcoin address)
					   char *output,			 // The address to store the output string.
					   uint32_t maxStrLen);		 // the maximum length of the output string

// Decode a previously encoded base58 string.  Returns the number of bytes in the decoded binary stream.  If there was an error decoded it
// then it returns a zero byte length.
uint32_t decodeBase58(const char *string,		// The base58 encoded string
					   uint8_t *output,			// The output binary buffer
					   uint32_t maxOutputLength, // The maximum output length of the binary buffer.
					   bool outputIsBigEndian);		// Whether or not the output is considered big endian and therefore needs to be byte reverse; true for bitcoin addresses

#endif
