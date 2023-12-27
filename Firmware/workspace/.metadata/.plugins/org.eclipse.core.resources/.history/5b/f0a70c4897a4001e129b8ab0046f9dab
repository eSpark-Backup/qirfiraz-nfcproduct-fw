#ifndef __NFC_H_
#define __NFC_H_

#include "chip.h"

enum {
	NFC_CMD_RES_ERROR = 0x00,
	NFC_CMD_RES_OK = 0x01,
	NFC_CMD_RES_END_OF_FILE = 0x02,
	NFC_CMD_RES_INVALID_DATA = 0x03,
	NFC_CMD_RES_LOGGING_ALREADY_RUNNING = 0x04,
	NFC_CMD_RES_LOGGING_ALREADY_STOPPED = 0x05
};

#define NFC_REG_SHIPPING_ID_OFFSET 0x00
#define NFC_REG_SHIPPING_ID_LENGTH 100

typedef struct NFC_CMD_0x70_RES_S {
	uint8_t success;
	uint8_t uid[16];
} NFC_CMD_0x70_RES_T;

typedef struct NFC_CMD_0x71_RES_S {
	uint8_t success;
} NFC_CMD_0x71_RES_T;

typedef struct NFC_CMD_0x72_RES_S {
	uint8_t success;
	uint8_t length;
	uint8_t shipping_id[NFC_REG_SHIPPING_ID_LENGTH];
} NFC_CMD_0x72_RES_T;

typedef struct NFC_CMD_0x73_RES_S {
	uint8_t success;
	int8_t accX;
	int8_t accY;
	int8_t accZ;
	int8_t temp;
	uint8_t volt;
} NFC_CMD_0x73_RES_T;

#define NFC_REG_SENSOR_SETTINGS_OFFSET (NFC_REG_SHIPPING_ID_OFFSET + NFC_REG_SHIPPING_ID_LENGTH + 1)

typedef struct NFC_REG_SENSOR_SETTINGS_S {
	uint8_t shock_scale;
	uint8_t shock_threshold;
	int8_t temp_threshold_min;
	int8_t temp_threshold_max;
	uint16_t measure_interval;
} NFC_REG_SENSOR_SETTINGS_T;

#define NFC_REG_SENSOR_SETTINGS_LENGTH (sizeof(NFC_REG_SENSOR_SETTINGS_T))

typedef struct NFC_CMD_0x74_RES_S {
	uint8_t success;
} NFC_CMD_0x74_RES_T;

typedef struct NFC_CMD_0x75_RES_S {
	uint8_t success;
	uint8_t shock_scale;
	uint8_t shock_threshold;
	int8_t temp_threshold_min;
	int8_t temp_threshold_max;
	uint8_t measure_interval[2];
} NFC_CMD_0x75_RES_T;

#define NFC_REG_LOGGING_STATUS_OFFSET (NFC_REG_SENSOR_SETTINGS_OFFSET + NFC_REG_SENSOR_SETTINGS_LENGTH)

#define NFC_RUNNING	1
#define NFC_STOPPED	0

typedef struct NFC_REG_LOGGING_STATUS_S {
	uint8_t running		: 1;
	uint8_t postponed	: 1;
	uint8_t not_used_01	: 6;
	uint8_t logStartTime[4];
} NFC_REG_LOGGING_STATUS_T;

#define NFC_REG_LOGGING_STATUS_LENGTH (sizeof(NFC_REG_LOGGING_STATUS_T))

typedef struct NFC_LOG_S {
	int16_t accX;
	int16_t accY;
	int16_t accZ;
	uint8_t temp;
	uint8_t timeStamp[4];

} NFC_LOG_T;
typedef struct NFC_CMD_0x76_RES_S {
	uint8_t success;
	uint8_t running;
	uint16_t fileSize;
	uint8_t logStartTime[4];
} NFC_CMD_0x76_RES_T;

typedef struct NFC_CMD_0x77_RES_S {
	uint8_t success;
} NFC_CMD_0x77_RES_T;

typedef struct NFC_CMD_0x78_RES_S {
	uint8_t success;
} NFC_CMD_0x78_RES_T;

typedef struct NFC_CMD_0x79_RES_S {
	uint8_t success;
	uint8_t fileSize[2];
	uint8_t recNumber[2];
	int8_t accX;
	int8_t accY;
	int8_t accZ;
	uint8_t temp;
	uint8_t timeStamp[4];
} NFC_CMD_0x79_RES_T;

typedef struct NFC_CMD_0x7a_RES_S {
	uint8_t success;
} NFC_CMD_0x7a_RES_T;

#define NFC_REG_SECURITY_SETTINGS_OFFSET (NFC_REG_LOGGING_STATUS_OFFSET + NFC_REG_LOGGING_STATUS_LENGTH)

typedef struct NFC_REG_SECURITY_SETTINGS_S {
	uint8_t securityScheme;
	uint8_t lslKeyLength;
	uint8_t lslKey[32];
	uint8_t appKeyLength;
	uint8_t appKey[32];
} NFC_REG_SECURITY_SETTINGS_T;

#define NFC_REG_SECURITY_SETTINGS_LENGTH (sizeof(NFC_REG_SECURITY_SETTINGS_T))

typedef struct NFC_CMD_0x80_RES_S {
	uint8_t success;
	uint8_t securityScheme;
	uint8_t keyLength;
	uint8_t key[32];
} NFC_CMD_0x80_RES_T;

void NFC_Init(void);

#endif
