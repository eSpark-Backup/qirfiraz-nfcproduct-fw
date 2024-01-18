#ifndef __APP_SEL_H_
#define __APP_SEL_H_

#define MSG_APP_HANDLERS_COUNT 12
#define MSG_APP_HANDLERS NFC_CmdHandler
#define MSG_ENABLE_GETUID 1

#define NDEFT2T_MSG_AVAILABLE_CB NFC_MsgAvailable_Cb

#include <lsl_logs.h>

#define STORAGE_EEPROM_FIRST_ROW 24
#define STORAGE_BITSIZE 56
#define STORAGE_TYPE LOGS_LOG_T
#define STORAGE_COMPRESS_CB Logs_Compress_Cb
#define STORAGE_DECOMPRESS_CB Logs_Decompress_Cb

#endif
