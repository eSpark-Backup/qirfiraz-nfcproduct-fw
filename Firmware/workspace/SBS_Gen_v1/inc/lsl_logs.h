#ifndef __LOGS_H_
#define __LOGS_H_

#include "chip.h"
#include <lsl_nfc.h>

typedef struct LOGS_LOG_S {
	uint8_t byte_1;		// acc X
	uint8_t byte_2;		// acc Y
	uint8_t byte_3;		// acc Z
	uint8_t byte_4;		// time[0]
	uint8_t byte_5;		// time[1]
	uint8_t byte_6;		// time[2]
	uint8_t byte_7;		// time MSB and temp
} LOGS_LOG_T;

void Logs_Init(void);

LOGS_LOG_T Logs_PackData(NFC_LOG_T unpacked);
NFC_LOG_T Logs_UnpackData(LOGS_LOG_T packed);

#endif
