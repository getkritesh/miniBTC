#ifndef BITCOIN_ADDRESS_H

#define BITCOIN_ADDRESS_H

#include <stdint.h>

// Converts an ASCII bitcoin address into the 25 byte version.
bool bitcoinAsciiToAddress(const char *input,uint8_t output[25]); // convert an ASCII bitcoin address into binary.

// Converts a 25 byte bitcoin address into the ASCII versions
bool bitcoinAddressToAscii(const uint8_t address[25],char *output,uint32_t maxOutputLen);

// Converts a full 65 byte ECDSA public key into an ASCII representation
bool bitcoinPublicKeyToAscii(const uint8_t input[65], // The 65 bytes long ECDSA public key; first byte will always be 0x4 followed by two 32 byte components
						  char *output,				// The output ascii representation.
						  uint32_t maxOutputLen); // convert a binary bitcoin address into ASCII

// Converts a 33 byte compressed ECDSA public key into an ASCII representation
bool bitcoinCompressedPublicKeyToAscii(const uint8_t input[33], // The 65 bytes long ECDSA public key; first byte will always be 0x4 followed by two 32 byte components
							 char *output,				// The output ascii representation.
							 uint32_t maxOutputLen); // convert a binary bitcoin address into ASCII

// Converts a full 65 byte ECDSA public key into the 25 byte RIPEMD160 version (with header and 4 byte checksum at the end).  
bool bitcoinPublicKeyToAddress(const uint8_t input[65], // The 65 bytes long ECDSA public key; first byte will always be 0x4 followed by two 32 byte components
							   uint8_t output[25]);		// A bitcoin address (in binary( is always 25 bytes long.

// Converts a compressed 33 byte ECDSA public key into the 25 byte RIPEMD160 version (with header and 4 byte checksum at the end).  
bool bitcoinCompressedPublicKeyToAddress(const uint8_t input[33], // The 65 bytes long ECDSA public key; first byte will always be 0x4 followed by two 32 byte components
							   uint8_t output[25]);		// A bitcoin address (in binary( is always 25 bytes long.

// If someone gives you a bitcoin address as the already encoded 20 byte RIPEMD, then this will produce the 25 byte 'address' which has the padding and checksum added to it.
// This puts the one byte header and the 4 byte checksum to conver a 20 byte RIPEMD public key into the padded 25 byte address version
void bitcoinRIPEMD160ToAddress(const uint8_t ripeMD160[20],uint8_t address[25]);

void bitcoinRIPEMD160ToScriptAddress(const uint8_t ripeMD160[20],uint8_t address[25]);

#endif
