#ifndef __MEMS_H_
#define __MEMS_H_

// *********************** GPIO ************************
#define MEMS_SIGNAL_PORT			0
#define MEMS_SIGNAL_INT1			0
#define MEMS_SIGNAL_INT2			1

// *********************** MEMS ************************
// LIS2DTW12_ID
#define LIS2DTW12_ID				0x44

#define MEMS_WHO_AM_I				0x0f
#define MEMS_OUT_X_L				0x28

#define MEMS_DISABLED				0x00
#define MEMS_ENABLED				0x01

#define	MEMS_CTRL1					0x20

#define	MEMS_ODR_POWER_DOWN			0x0
#define	MEMS_ODR_1Hz6				0x1
#define	MEMS_ODR_12Hz5				0x2
#define	MEMS_ODR_25Hz				0x3
#define	MEMS_ODR_50Hz				0x4
#define	MEMS_ODR_100Hz				0x5
#define	MEMS_ODR_200Hz				0x6
#define	MEMS_ODR_400Hz				0x7
#define	MEMS_ODR_800Hz				0x8
#define	MEMS_ODR_1600Hz				0x9

#define	MEMS_MODE_LOW_POWER			0x0
#define	MEMS_MODE_HIGH_PERFORMANCE	0x1
#define	MEMS_MODE_SINGLE_DATA_CONV	0x2

#define	MEMS_LP_MODE_1				0x0
#define	MEMS_LP_MODE_2				0x1
#define	MEMS_LP_MODE_3				0x2
#define	MEMS_LP_MODE_4				0x3

typedef struct MEMS_CTRL1_S {
	uint8_t lp_mode			: 2;
	uint8_t mode			: 2;
	uint8_t odr				: 4;
} MEMS_CTRL1_T;

#define	MEMS_CTRL2			0x21
typedef struct MEMS_CTRL2_S {
	uint8_t sim				: 1;
	uint8_t i2c_disable		: 1;
	uint8_t if_add_inc		: 1;
	uint8_t bdu				: 1;
	uint8_t cs_pu_disc		: 1;
	uint8_t not_used_01		: 1;
	uint8_t soft_reset		: 1;
	uint8_t boot			: 1;
} MEMS_CTRL2_T;

#define MEMS_CTRL3					0x22

#define MEMS_SLP_INT2				0x0
#define MEMS_SLP_SPI				0x1

typedef struct MEMS_CTRL3_S {
	uint8_t	slp_mode_1		: 1;
	uint8_t	slp_mode_sel	: 1;
	uint8_t	not_used_01		: 1;
	uint8_t	h_lactive		: 1;
	uint8_t	lir				: 1;
	uint8_t	pp_od			: 1;
	uint8_t	st				: 2;
} MEMS_CTRL3_T;

#define MEMS_CTRL4_INT1_PAD_CTRL	0x23

typedef struct MEMS_CTRL4_INT1_PAD_CTRL_S {
	uint8_t int1_drdy		: 1;
	uint8_t int1_fth		: 1;
	uint8_t int1_diff5		: 1;
	uint8_t int1_tap		: 1;
	uint8_t int1_ff			: 1;
	uint8_t int1_wu			: 1;
	uint8_t int1_single_tap	: 1;
	uint8_t int1_6d			: 1;
} MEMS_CTRL4_INT1_PAD_CTRL_T;

//#define MEMS_CTRL5									0x24
//
#define MEMS_CTRL6					0x25

#define MEMS_BW_FILT_ODR_DIV_2		0x0
#define MEMS_BW_FILT_ODR_DIV_4		0x1
#define MEMS_BW_FILT_ODR_DIV_10		0x2
#define MEMS_BW_FILT_ODR_DIV_20		0x3

#define MEMS_FULL_SCALE_2G			0x0
#define MEMS_FULL_SCALE_4G			0x1
#define MEMS_FULL_SCALE_8G			0x2
#define MEMS_FULL_SCALE_16G			0x3

#define MEMS_LOW_PASS_FILTER		0x00
#define MEMS_HIGH_PASS_FILTER		0x01

typedef struct MEMS_CTRL6_S {
	uint8_t	nut_used_01		: 2;
	uint8_t	low_noise		: 1;
	uint8_t	fds				: 1;
	uint8_t	fs				: 2;
	uint8_t	bw_filt			: 2;
} MEMS_CTRL6_T;

#define MEMS_STATUS					0x27

typedef struct MEMS_STATUS_S {
	uint8_t drdy			: 1;
	uint8_t ff_ia			: 1;
	uint8_t _6d_ia			: 1;
	uint8_t single_tap		: 1;
	uint8_t double_tap		: 1;
	uint8_t sleep_state		: 1;
	uint8_t wu_ia			: 1;
	uint8_t fifo_ths		: 1;
} MEMS_STATUS_T;

#define MEMS_INT_DUR				0x33

typedef struct MEMS_INT_DUR_S {
	uint8_t shock			: 2;
	uint8_t quiet			: 2;
	uint8_t latency			: 4;
} MEMS_INT_DUR_T;

#define MEMS_WAKE_UP_THS			0x34

typedef struct MEMS_WAKE_UP_THS_S {
	uint8_t wk_ths			: 6;
	uint8_t sleep_on		: 1;
	uint8_t sngl_dbl_tap	: 1;
} MEMS_WAKE_UP_THS_T;

#define MEMS_WAKE_UP_DUR			0x35

typedef struct MEMS_WAKE_UP_DUR_S {
	uint8_t sleep_dur		: 4;
	uint8_t stationary		: 1;
	uint8_t wake_dur		: 2;
	uint8_t ff_dur			: 1;
} MEMS_WAKE_UP_DUR_T;

#define MEMS_STATUS_DUP				0x37

typedef struct MEMS_STATUS_DUP_S {
	uint8_t drdy			: 1;
	uint8_t ff_ia			: 1;
	uint8_t _6d_ia			: 1;
	uint8_t single_tap		: 1;
	uint8_t double_tap		: 1;
	uint8_t sleep_state_ia	: 1;
	uint8_t drdy_t			: 1;
	uint8_t ovr 			: 1;
} MEMS_STATUS_DUP_T;

#define MEMS_WAKE_UP_SRC			0x38

typedef struct MEMS_WAKE_UP_SRC_S {
	uint8_t z_wu			: 1;
	uint8_t y_wu			: 1;
	uint8_t x_wu			: 1;
	uint8_t wu_ia			: 1;
	uint8_t sleep_state_ia	: 1;
	uint8_t ff_ia			: 1;
	uint8_t not_used_01		: 2;
} MEMS_WAKE_UP_SRC_T;

#define MEMS_TAP_SRC				0x39

typedef struct MEMS_TAP_SRC_S {
	uint8_t z_tap			: 1;
	uint8_t y_tap			: 1;
	uint8_t x_tap			: 1;
	uint8_t tap_sign		: 1;
	uint8_t double_tap		: 1;
	uint8_t single_tap		: 1;
	uint8_t tap_ia			: 1;
	uint8_t not_used		: 1;
} MEMS_TAP_SRC_T;

#define MEMS_SIXD_SRC				0x3a

typedef struct MEMS_SIXD_SRC_S {
	uint8_t xl				: 1;
	uint8_t xh				: 1;
	uint8_t yl				: 1;
	uint8_t yh				: 1;
	uint8_t zl				: 1;
	uint8_t zh				: 1;
	uint8_t _6d_ia			: 1;
	uint8_t not_used_01		: 1;
} MEMS_SIXD_SRC_T;

#define MEMS_ALL_INT_SRC			0x3b

typedef struct MEMS_ALL_INT_SRC_S {
	uint8_t ff_ia			: 1;
	uint8_t wu_ia			: 1;
	uint8_t single_tap		: 1;
	uint8_t double_tap		: 1;
	uint8_t _6d_ia			: 1;
	uint8_t sleep_change_ia	: 1;
	uint8_t not_used_01		: 2;
} MEMS_ALL_INT_SRC_T;

typedef struct MEMS_ALL_SOURCES_S {
	MEMS_STATUS_DUP_T	status_dup;
	MEMS_WAKE_UP_SRC_T	wake_up_src;
	MEMS_TAP_SRC_T		tap_src;
	MEMS_SIXD_SRC_T		sixd_src;
	MEMS_ALL_INT_SRC_T	all_int_src;
} MEMS_ALL_SOURCES_T;

#define MEMS_CTRL7					0x3f

typedef struct MEMS_CTRL7_S {
	uint8_t lpass_on6d		: 1;
	uint8_t hp_ref_mode		: 1;
	uint8_t usr_off_w		: 1;
	uint8_t usr_off_on_wu	: 1;
	uint8_t usr_off_on_out	: 1;
	uint8_t int_enable		: 1;
	uint8_t int2_on_int1	: 1;
	uint8_t drdy_pulsed		: 1;
} MEMS_CTRL7_T;

//#define MEMS_STATUS_DUP								0x37

typedef struct MEMS_ACC_DATA_S {
	int16_t x;
	int16_t y;
	int16_t z;
} MEMS_ACC_DATA_T;

void MEMS_Init(void);
MEMS_ACC_DATA_T MEMS_SingleReadAcceleration(void);
bool MEMS_ThresholdSet(void);
void MEMS_ReadAllSourcesFlags(void);
void MEMS_RestoreDefault(void);

#endif
