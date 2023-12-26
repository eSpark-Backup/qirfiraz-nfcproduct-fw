#include "chip.h"
#include <lsl_mems.h>

void MEMS_Init(void){
	Chip_IOCON_Init(NSS_IOCON);

	Chip_IOCON_SetPinConfig(NSS_IOCON, MEMS_SIGNAL_INT2, IOCON_FUNC_0);

	Chip_IOCON_SetPinConfig(NSS_IOCON, IOCON_PIO0_2, IOCON_FUNC_1);
	Chip_IOCON_SetPinConfig(NSS_IOCON, IOCON_PIO0_6, IOCON_FUNC_1);
	Chip_IOCON_SetPinConfig(NSS_IOCON, IOCON_PIO0_8, IOCON_FUNC_1);
	Chip_IOCON_SetPinConfig(NSS_IOCON, IOCON_PIO0_9, IOCON_FUNC_1);

	Chip_GPIO_Init(NSS_GPIO);

	Chip_GPIO_SetPinDIROutput(NSS_GPIO, MEMS_SIGNAL_PORT, MEMS_SIGNAL_INT2);
//	Chip_GPIO_SetPinOutLow(NSS_GPIO, MEMS_SIGNAL_PORT, MEMS_SIGNAL_INT2);

	Chip_SSP_Init(NSS_SSP0);

	Chip_SSP_SetMaster(NSS_SSP0, true);
    Chip_SSP_SetFormat(NSS_SSP0, SSP_BITS_8, SSP_FRAME_FORMAT_SPI, SSP_CLOCK_MODE3);
    Chip_SSP_SetBitRate(NSS_SSP0, 100000);

    Chip_SSP_Enable(NSS_SSP0);
}

uint8_t MEMS_Read_Register(uint8_t reg){
	Chip_SSP_DATA_SETUP_T sds;

	uint8_t tx[2];
	uint8_t rx[2];

	tx[0] = 0x80 | reg;
	tx[1] = 0x00;

	sds.rx_cnt = 0;
	sds.tx_cnt = 0;
	sds.length = 2;
	sds.rx_data = rx;
	sds.tx_data = tx;

	Chip_SSP_RWFrames_Blocking(NSS_SSP0, &sds);

	return rx[1];
}

void MEMS_Read_Registers(uint8_t reg, uint8_t *data, uint8_t len){
	Chip_SSP_DATA_SETUP_T sds;

	uint8_t tx[len + 1];
	uint8_t rx[len + 1];

	tx[0] = 0x80 | reg;

	for(uint8_t i = 1; i <= len; i++){
		tx[i] = 0x00;
	};

	sds.rx_cnt = 0;
	sds.tx_cnt = 0;
	sds.length = len + 1;
	sds.rx_data = rx;
	sds.tx_data = tx;

	Chip_SSP_RWFrames_Blocking(NSS_SSP0, &sds);

	for(uint8_t i = 0; i < len; i++){
		data[i] = rx[i + 1];
	}
}

void MEMS_Write_Register(uint8_t reg, uint8_t data){
	Chip_SSP_DATA_SETUP_T sds;

	uint8_t tx[2];
	uint8_t rx[2];

	tx[0] = reg;
	tx[1] = data;

	sds.rx_cnt = 0;
	sds.tx_cnt = 0;
	sds.length = 2;
	sds.rx_data = rx;
	sds.tx_data = tx;

	Chip_SSP_RWFrames_Blocking(NSS_SSP0, &sds);
}

//void MEMS_Write_Registers(uint8_t reg, uint8_t *data, uint8_t len){
//	Chip_SSP_DATA_SETUP_T sds;
//
//	uint8_t tx[len + 1];
//	uint8_t rx[len + 1];
//
//	tx[0] = reg;
//
//	for(uint8_t i = 1; i <= len; i++){
//		tx[i] = data[i - 1];
//	}
//
//	sds.rx_cnt = 0;
//	sds.tx_cnt = 0;
//	sds.length = len + 1;
//	sds.rx_data = rx;
//	sds.tx_data = tx;
//
//	Chip_SSP_RWFrames_Blocking(NSS_SSP0, &sds);
//}

bool MEMS_CheckDeviceID(){
	return MEMS_Read_Register(MEMS_WHO_AM_I) == LIS2DTW12_ID;
}

void MEMS_RestoreDefault(){
	uint8_t reg = MEMS_Read_Register(MEMS_CTRL2);

//	reg
}

MEMS_ACC_DATA_T MEMS_ReadAcceleration(){
	MEMS_ACC_DATA_T acc;

	if(MEMS_CheckDeviceID()){
		MEMS_RestoreDefault();
	}else{
		acc.x = 0;
		acc.y = 0;
		acc.z = 0;
	}



//	if(MEMS_STATUS_Data_Ready_Flag_Read()){
//		uint8_t raw[6];
//
//		MEMS_Read_Registers(MEMS_OUT_X_L, raw, 6);
//
//		acc.x = raw[1] << 8;
//		acc.x |= raw[0];
//
//		acc.y = raw[3] << 8;
//		acc.y |= raw[2];
//
//		acc.z = raw[5] << 8;
//		acc.z |= raw[4];
//	}else{
//		acc.x = 0;
//		acc.y = 0;
//		acc.z = 0;
//	}

	return acc;
}

//void MEMS_CTRL1_Set(uint8_t odr, uint8_t mode, uint8_t lp_mode){
//	uint8_t data = 0x00;
//
//	data = odr << 4;
//	data |= mode << 2;
//	data |= lp_mode;
//
//	MEMS_Write_Register(MEMS_CTRL1, data);
//}
//
//void MEMS_CTRL2_Set(bool boot, bool soft_reset, bool cs_pu_disc, bool bdu, bool if_add_inc, bool i2c_disable, bool sim){
//	uint8_t data = 0x00;
//
//	data = boot << 7;
//	data |= soft_reset << 6;
//	data |= cs_pu_disc << 4;
//	data |= bdu << 3;
//	data |= if_add_inc << 2;
//	data |= i2c_disable << 1;
//	data |= sim;
//
//	MEMS_Write_Register(MEMS_CTRL2, data);
//}
//
//void MEMS_CTRL3_Set(uint8_t st, bool pp_od, bool lir, bool h_lactive, bool slp_mode_sel, bool slp_mode_1){
//	uint8_t data = 0x00;
//
//	data = st << 6;
//	data |= pp_od << 5;
//	data |= lir << 4;
//	data |= h_lactive << 3;
//	data |= slp_mode_sel << 1;
//	data |= slp_mode_1;
//
//	MEMS_Write_Register(MEMS_CTRL3, data);
//}
//
//void MEMS_CTRL4_Set(bool _6d, bool single_tap, bool wu, bool ff, bool tap, bool diff5, bool fth, bool drdy){
//	uint8_t data = 0x00;
//
//	data = _6d << 7;
//	data |= single_tap << 6;
//	data |= wu << 5;
//	data |= ff << 4;
//	data |= tap << 3;
//	data |= diff5 << 2;
//	data |= fth << 1;
//	data |= drdy;
//
//	MEMS_Write_Register(MEMS_CTRL4, data);
//}
//
//void MEMS_CTRL5_Set(bool sleep_state, bool sleep_chg, bool boot, bool drdy_t, bool ovr, bool diff5, bool fth, bool drdy){
//	uint8_t data = 0x00;
//
//	data = sleep_state << 7;
//	data |= sleep_chg << 6;
//	data |= boot << 5;
//	data |= drdy_t << 4;
//	data |= ovr << 3;
//	data |= diff5 << 2;
//	data |= fth << 1;
//	data |= drdy;
//
//	MEMS_Write_Register(MEMS_CTRL5, data);
//}
//
//void MEMS_CTRL6_Set(uint8_t bw_filt, uint8_t fs, bool fds, bool low_noise){
//	uint8_t data = 0x00;
//
//	data = bw_filt << 6;
//	data |= fs << 4;
//	data |= fds << 3;
//	data |= low_noise << 2;
//
//	MEMS_Write_Register(MEMS_CTRL5, data);
//}
//
//void MEMS_WAKE_UP_THS_Set(bool single_double_tap, bool sleep_on, uint8_t wk_ths){
//	uint8_t data = 0x00;
//
//	data = single_double_tap << 7;
//	data |= sleep_on << 6;
//	data |= wk_ths;
//
//	MEMS_Write_Register(MEMS_WAKE_UP_THS, data);
//}
//
//void MEMS_CTRL7_Set(bool drdy_pulsed, bool int2_on_int1, bool interrupts_enable, bool usr_off_on_out, bool usr_off_on_wu, bool usr_off_w, bool hp_ref_mode, bool lpass_on6d){
//	uint8_t data = 0x00;
//
//	data = drdy_pulsed << 7;
//	data |= int2_on_int1 << 6;
//	data |= interrupts_enable << 5;
//	data |= usr_off_on_out << 4;
//	data |= usr_off_on_wu << 3;
//	data |= usr_off_w << 2;
//	data |= hp_ref_mode << 1;
//	data |= lpass_on6d;
//
//	MEMS_Write_Register(MEMS_CTRL7, data);
//}
//
//uint8_t MEMS_STATUS_Read(){
//	return MEMS_Read_Register(MEMS_STATUS);
//}
//
//uint8_t MEMS_STATUS_DUP_Read(){
//	return MEMS_Read_Register(MEMS_STATUS_DUP);
//}
//
//void MEMS_Single_Data_Conversion_Start(){
////	uint8_t data = MEMS_Read_Register(MEMS_CTRL3);
////
////	data |= MEMS_CTRL3_SINGLE_DATA_CONV_DEMAND_BIT;
////
////	MEMS_Write_Register(MEMS_CTRL3, data);
//
//	Chip_GPIO_SetPinOutHigh(NSS_GPIO, MEMS_SIGNAL_PORT, MEMS_SIGNAL_INT2);
//
//	Chip_Clock_System_BusyWait_ms(5);
//
//	Chip_GPIO_SetPinOutLow(NSS_GPIO, MEMS_SIGNAL_PORT, MEMS_SIGNAL_INT2);
//
////	Chip_Clock_System_BusyWait_ms(15);
//}
//
//bool MEMS_STATUS_FIFO_Threshold_Flag_Read(){
//	return (bool) (MEMS_STATUS_FIFO_THRESHOLD_MSK & MEMS_Read_Register(MEMS_STATUS));
//}
//
//bool MEMS_STATUS_Wakeup_Event_Flag_Read(){
//	return (bool) (MEMS_STATUS_WAKEUP_EVENT_MSK & MEMS_Read_Register(MEMS_STATUS));
//}
//
//bool MEMS_STATUS_Sleep_Event_Flag_Read(){
//	return (bool) (MEMS_STATUS_SLEEP_STATE_MSK & MEMS_Read_Register(MEMS_STATUS));
//}
//
//bool MEMS_STATUS_Double_Tap_Event_Flag_Read(){
//	return (bool) (MEMS_STATUS_DOUBLE_TAP_MSK & MEMS_Read_Register(MEMS_STATUS));
//}
//
//bool MEMS_STATUS_SingleTap_Event_Flag_Read(){
//	return (bool) (MEMS_STATUS_SINGLE_TAP_MSK & MEMS_Read_Register(MEMS_STATUS));
//}
//
//bool MEMS_STATUS_6D_Change_Position_Flag_Read(){
//	return (bool) (MEMS_STATUS_6D_CHANGE_IN_POSITION_MSK & MEMS_Read_Register(MEMS_STATUS));
//}
//
//bool MEMS_STATUS_Free_Fall_Flag_Read(){
//	return (bool) (MEMS_STATUS_FREE_FALL_EVENT_MSK & MEMS_Read_Register(MEMS_STATUS));
//}
//
//bool MEMS_STATUS_Data_Ready_Flag_Read(){
//	return (bool) (MEMS_STATUS_DATA_READY_MSK & MEMS_Read_Register(MEMS_STATUS));
//}
//
//bool MEMS_STATUS_DUP_FIFO_Overrun_Flag_Read(){
//	return (bool) (MEMS_STATUS_DUP_FIFO_OVERRUN_MSK & MEMS_Read_Register(MEMS_STATUS_DUP));
//}
//
//bool MEMS_STATUS_DUP_Temperature_Data_Ready_Flag_Read(){
//	return (bool) (MEMS_STATUS_DUP_TEMPERATURE_DATA_READY_MSK & MEMS_Read_Register(MEMS_STATUS_DUP));
//}
//
//bool MEMS_STATUS_DUP_Sleep_Event_Flag_Read(){
//	return (bool) (MEMS_STATUS_DUP_SLEEP_STATE_MSK & MEMS_Read_Register(MEMS_STATUS_DUP));
//}
//
//bool MEMS_STATUS_DUP_Double_Tap_Event_Flag_Read(){
//	return (bool) (MEMS_STATUS_DUP_DOUBLE_TAP_MSK & MEMS_Read_Register(MEMS_STATUS_DUP));
//}
//
//bool MEMS_STATUS_DUP_SingleTap_Event_Flag_Read(){
//	return (bool) (MEMS_STATUS_DUP_SINGLE_TAP_MSK & MEMS_Read_Register(MEMS_STATUS_DUP));
//}
//
//bool MEMS_STATUS_DUP_6D_Change_Position_Flag_Read(){
//	return (bool) (MEMS_STATUS_DUP_6D_CHANGE_IN_POSITION_MSK & MEMS_Read_Register(MEMS_STATUS_DUP));
//}
//
//bool MEMS_STATUS_DUP_Free_Fall_Flag_Read(){
//	return (bool) (MEMS_STATUS_DUP_FREE_FALL_EVENT_MSK & MEMS_Read_Register(MEMS_STATUS_DUP));
//}
//
//bool MEMS_STATUS_DUP_Data_Ready_Flag_Read(){
//	return (bool) (MEMS_STATUS_DUP_DATA_READY_MSK & MEMS_Read_Register(MEMS_STATUS_DUP));
//}
//
//float MEMS_Read_Temperature(){
//	if(MEMS_STATUS_DUP_Temperature_Data_Ready_Flag_Read()){
//		uint8_t raw[2];
//		int16_t temp;
//
//		MEMS_Read_Registers(MEMS_OUT_T_L, raw, 2);
//
//		temp = raw[1] << 8;
//		temp |= raw[0];
//
//		return (float)temp / 256 + 25;
//	}else
//		return (float) 999;
//}
//
//float MEMS_Read_Acceleration_x(){
//	if(MEMS_STATUS_Data_Ready_Flag_Read()){
//		uint8_t raw[2];
//		int16_t acc_x;
//
//		MEMS_Read_Registers(MEMS_OUT_X_L, raw, 2);
//
//		acc_x = raw[1] << 8;
//		acc_x |= raw[0];
//
//		return (float)acc_x / 3904; // MEMS_CTRL1_LP_MODE_LOW_POWER_MODE_2 --> FS ±8 g in High-Performance Mode and all low-power modes except Low-Power Mode 1
//	}else
//		return (float) 999;
////		return false;
////		return MEMS_Read_Acceleration_x();
//}
//
//float MEMS_Read_Acceleration_y(){
//	if(MEMS_STATUS_Data_Ready_Flag_Read()){
//		uint8_t raw[2];
//		int16_t acc_y;
//
//		MEMS_Read_Registers(MEMS_OUT_Y_L, raw, 2);
//
//		acc_y = raw[1] << 8;
//		acc_y |= raw[0];
//
//		return (float)acc_y / 3904; // MEMS_CTRL1_LP_MODE_LOW_POWER_MODE_2 --> FS ±8 g in High-Performance Mode and all low-power modes except Low-Power Mode 1
//	}else
//		return (float) 999;
////		return false;
////		return MEMS_Read_Acceleration_y();
//}
//
//float MEMS_Read_Acceleration_z(){
//	if(MEMS_STATUS_Data_Ready_Flag_Read()){
//		uint8_t raw[2];
//		int16_t acc_z;
//
//		MEMS_Read_Registers(MEMS_OUT_Z_L, raw, 2);
//
//		acc_z = raw[1] << 8;
//		acc_z |= raw[0];
//
//		return (float)acc_z /3904; // MEMS_CTRL1_LP_MODE_LOW_POWER_MODE_2 --> FS ±8 g in High-Performance Mode and all low-power modes except Low-Power Mode 1
//	}else
//		return (float) 999;
////		return false;
////		return MEMS_Read_Acceleration_z();
//}



//// TODO - dorobit funkciu MEMS_DeInit()
//
//	// MEMS SOFT RESET
////	uint8_t reg2 = MEMS_Read_Register(0x21);
////	reg2 |= 1 << 6;
////	MEMS_Write_Register(0x21, reg2);
//
//// logy pri naraze
//bool MEMS_Start_Logging(void){
//	MEMS_Init();
//
//	MEMS_CTRL1_Set(MEMS_CTRL1_ODR_200Hz, MEMS_CTRL1_MODE_LOW_POWER, MEMS_CTRL1_LP_MODE_LOW_POWER_MODE_1);
//
//	MEMS_CTRL3_Set(MEMS_CTRL3_ST_NORMAL_MODE, MEMS_CTRL3_PP_OD_ON_INT_PAD_PUSH_PULL, MEMS_CTRL3_INT_REQUEST_NOT_LATCHED, MEMS_CTRL3_INTERRUPT_ACTIVE_LOW, MEMS_CTRL3_SINGLE_DATA_CONV_SEL_EXT_TRIG, MEMS_CTRL3_SINGLE_DATA_CONV_DISABLE);
//
//	MEMS_CTRL4_Set(MEMS_CTRL4_INT_6D_DISABLED, MEMS_CTRL4_INT_SINGLE_TAP_DISABLED, MEMS_CTRL4_INT_WAKE_UP_ENABLED, MEMS_CTRL4_INT_FREE_FALL_DISABLED, MEMS_CTRL4_INT_DOUBLE_TAP_DISABLED, MEMS_CTRL4_INT_FIFO_FULL_DISABLED, MEMS_CTRL4_INT_FIFO_THRESHOLD_DISABLED, MEMS_CTRL4_INT_DATA_READY_DISABLED);
//
////	MEMS_CTRL6_Set(MEMS_CTRL6_FILTER_CUTOFF_ODR_DIV_2, MEMS_CTRL6_FULL_SCALE_16G, MEMS_CTRL6_FILTER_TYPE_LOW_PASS, MEMS_CTRL6_LOW_NOISE_DISABLED);
//
//	MEMS_WAKE_UP_THS_Set(MEMS_WAKE_UP_THS_SINGLE_TAP_ONLY_ENABLED, MEMS_WAKE_UP_THS_SLEEP_ENABLED, 2);
//
//  	MEMS_CTRL7_Set(MEMS_CTRL7_DATA_READY_INT_LATCHED_MODE, MEMS_CTRL7_NORMAL_SIGNAL_ROUTING, MEMS_CTRL7_INTERRUPTS_ENABLED, MEMS_CTRL7_OFFSET_OUTPUT_DATA_DISABLED, MEMS_CTRL7_OFFSET_OUTPUT_WAKEUP_DISABLED, MEMS_CTRL7_USER_OFFSET_WEIGHT_977ug_LSB, MEMS_CTRL7_HIGH_PASS_REF_MODE_DISABLED, MEMS_CTRL7_ODR_2_SEND_TO_D6_INT_FUNC);
//
//	return true;
//}
//
//// NOTE - tu sa cita priznak vygenerovania udalosti interuptu
//
////status = MEMS_Read_Register(0x27);
////
////if(status >> 6 && 1){
////	temperature = MEMS_Read_Temperature();
////
////	MEMS_Read_Acceleration(acceleration);
////}
