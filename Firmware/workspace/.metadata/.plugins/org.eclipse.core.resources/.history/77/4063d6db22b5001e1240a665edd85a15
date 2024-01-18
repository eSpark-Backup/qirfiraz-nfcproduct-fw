#include "chip.h"
#include <compress/compress.h>
#include <storage/storage.h>
#include <lsl_logs.h>

void Logs_Init(void){
	Storage_Init();
}

int Logs_Compress_Cb(int eepromByteOffset, int bitCount, void *pOut){
	uint8_t data[bitCount];
	Chip_EEPROM_Read(NSS_EEPROM, eepromByteOffset, data, bitCount);
	int size = Compress_Encode(data, bitCount, pOut, bitCount);

	return size * 8;
}

int Logs_Decompress_Cb(const uint8_t *pData, int bitCount, void *pOut){
	int size = Compress_Decode(pData, STORAGE_IDIVUP(bitCount, 8), pOut, STORAGE_UNCOMPRESSED_BLOCK_SIZE_IN_BYTES);
	return (size == STORAGE_UNCOMPRESSED_BLOCK_SIZE_IN_BYTES) ? STORAGE_UNCOMPRESSED_BLOCK_SIZE_IN_BITS : 0;
}

LOGS_LOG_T Logs_PackData(NFC_LOG_T unpacked){
	LOGS_LOG_T packed;

	packed.byte_1 = unpacked.accX;
	packed.byte_2 = unpacked.accY;
	packed.byte_3 = unpacked.accZ;
	packed.byte_4 = unpacked.timeStamp[0];
	packed.byte_5 = unpacked.timeStamp[1];
	packed.byte_6 = unpacked.timeStamp[2];
	packed.byte_7 = (unpacked.timeStamp[3] << 7) | (unpacked.temp & 0x7f);

	return packed;
}

NFC_LOG_T Logs_UnpackData(LOGS_LOG_T packed){
	NFC_LOG_T unpacked;

	unpacked.accX = packed.byte_1;
	unpacked.accY = packed.byte_2;
	unpacked.accZ = packed.byte_3;
	unpacked.timeStamp[0] = packed.byte_4;
	unpacked.timeStamp[1] = packed.byte_5;
	unpacked.timeStamp[2] = packed.byte_6;
	unpacked.timeStamp[3] = (packed.byte_7 & 0x80) >> 7;
	unpacked.temp = packed.byte_7 & 0x7f;

	return unpacked;
}
