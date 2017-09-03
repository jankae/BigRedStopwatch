
#ifndef RFM69HW_REGISTERMAP_EXTERNAL_H
#define RFM69HW_REGISTERMAP_EXTERNAL_H

#define HAVE_REGISTER_MAP           (1)

/** Offset for register Fifo */
#define RG_FIFO                     (0x00)

/** Offset for register OP_MODE */
#define RG_OP_MODE                  (0x01)
/** Access parameters for sub-register SEQUENCER_OFF in register @ref RG_OP_MODE */
#define SR_SEQUENCER                0x01,   0x80,   7
/** Constant SEQUENCER_BY_REG_OP_MODE for sub-register @ref SR_SEQUENCER_OFF */
#define SEQUENCER_BY_REG_OP_MODE    (0)
/** Constant SEQUENCER_USER for sub-register @ref SR_SEQUENCER_OFF */
#define SEQUENCER_USER              (1)
/** Access parameters for sub-register LISTEN_ON in register @ref RG_OP_MODE */
#define SR_LISTEN                   0x01,   0x40,   6
/** Constant LISTEN_OFF for sub-register @ref SR_LISTEN_ON */
#define LISTEN_OFF                  (0)
/** Constant LISTEN_ON for sub-register @ref SR_LISTEN_ON */
#define LISTEN_ON                   (1)
/** Access parameters for sub-register LISTEN_ABORT in register @ref RG_OP_MODE */
#define SR_LISTEN_ABORT             0x01,   0x20,   5
/** Access parameters for sub-register MODE in register @ref RG_OP_MODE */
#define SR_MODE                     0x01,   0x1C,   2
/** Constant MODE_SLEEP for sub-register @ref SR_MODE */
#define MODE_SLEEP                  (0)
/** Constant MODE_STDBY for sub-register @ref SR_MODE */
#define MODE_STDBY                  (1)
/** Constant MODE_FS for sub-register @ref SR_MODE */
#define MODE_FS                     (2)
/** Constant MODE_TX for sub-register @ref SR_MODE */
#define MODE_TX                     (3)
/** Constant MODE_RX for sub-register @ref SR_MODE */
#define MODE_RX                     (4)

/** Offset for register DATA_MODUL */
#define RG_DATA_MODUL               (0x02)
/** Access parameters for sub-register DATA_MODE in register @ref RG_DATA_MODUL */
#define SR_DATA_MODE                0x02,   0x60,   5
/** Constant DATA_MODE_PACKET for sub-register @ref SR_DATA_MODE */
#define DATA_MODE_PACKET            (0)
/** Constant DATA_MODE_WITH_BIT_SYNC for sub-register @ref SR_DATA_MODE */
#define DATA_MODE_WITH_BIT_SYNC     (2)
/** Constant DATA_MODE_WITHOUT_BIT_SYNC for sub-register @ref SR_DATA_MODE */
#define DATA_MODE_WITHOUT_BIT_SYNC  (3)
/** Access parameters for sub-register MODULATION_TYPE in register @ref RG_DATA_MODUL */
#define SR_MODULATION_TYPE          0x02,   0x18,   3
/** Constant MODULATION_TYPE_FSK for sub-register @ref SR_MODULATION_TYPE */
#define MODULATION_TYPE_FSK         (0)
/** Constant MODULATION_TYPE_OOK for sub-register @ref SR_MODULATION_TYPE */
#define MODULATION_TYPE_OOK         (1)
/** Access parameters for sub-register MODULATION_SHAPING in register @ref RG_DATA_MODUL */
#define SR_MODULATION_SHAPING       0x02,   0x03,   0
/** Constant SHAPING_FSK_OFF for sub-register @ref SR_MODULATION_SHAPING */
#define SHAPING_FSK_OFF             (0)
/** Constant SHAPING_FSK_GAUSS_BT10 for sub-register @ref SR_MODULATION_SHAPING */
#define SHAPING_FSK_GAUSS_BT10      (1)
/** Constant SHAPING_FSK_GAUSS_BT05 for sub-register @ref SR_MODULATION_SHAPING */
#define SHAPING_FSK_GAUSS_BT05      (2)
/** Constant SHAPING_FSK_GAUSS_BT03 for sub-register @ref SR_MODULATION_SHAPING */
#define SHAPING_FSK_GAUSS_BT03      (3)
/** Constant SHAPING_OOK_OFF for sub-register @ref SR_MODULATION_SHAPING */
#define SHAPING_OOK_OFF             (0)
/** Constant SHAPING_OOK_FILTER_1BR for sub-register @ref SR_MODULATION_SHAPING */
#define SHAPING_OOK_FILTER_1BR      (1)
/** Constant SHAPING_OOK_FILTER_2BR for sub-register @ref SR_MODULATION_SHAPING */
#define SHAPING_OOK_FILTER_2BR      (2)

/** Offset for register BITRATE_MSB */
#define RG_BITRATE_MSB              (0x03)
/** RG_BITRATE_MSB (bits/sec) example bit rates */
#define RF_BITRATE_MSB_1200         0x68
#define RF_BITRATE_MSB_2400         0x34
#define RF_BITRATE_MSB_4800         0x1A  // Default
#define RF_BITRATE_MSB_9600         0x0D
#define RF_BITRATE_MSB_19200        0x06
#define RF_BITRATE_MSB_38400        0x03
#define RF_BITRATE_MSB_38323        0x03
#define RF_BITRATE_MSB_34482        0x03
#define RF_BITRATE_MSB_76800        0x01
#define RF_BITRATE_MSB_153600       0x00
#define RF_BITRATE_MSB_57600        0x02
#define RF_BITRATE_MSB_115200       0x01
#define RF_BITRATE_MSB_12500        0x0A
#define RF_BITRATE_MSB_25000        0x05
#define RF_BITRATE_MSB_50000        0x02
#define RF_BITRATE_MSB_100000       0x01
#define RF_BITRATE_MSB_150000       0x00
#define RF_BITRATE_MSB_200000       0x00
#define RF_BITRATE_MSB_250000       0x00
#define RF_BITRATE_MSB_300000       0x00
#define RF_BITRATE_MSB_32768        0x03
#define RF_BITRATE_MSB_55555        0x02  // custom bit rate
#define RF_BITRATE_MSB_200KBPS      0x00  // custom bit rate

/** Offset for register BITRATE_LSB */
#define RG_BITRATE_LSB              (0x04)
/** RG_BITRATE_LSB (bits/sec) example bit rates */
#define RF_BITRATE_LSB_1200         0x2B
#define RF_BITRATE_LSB_2400         0x15
#define RF_BITRATE_LSB_4800         0x0B  // Default
#define RF_BITRATE_LSB_9600         0x05
#define RF_BITRATE_LSB_19200        0x83
#define RF_BITRATE_LSB_38400        0x41
#define RF_BITRATE_LSB_38323        0x43
#define RF_BITRATE_LSB_34482        0xA0
#define RF_BITRATE_LSB_76800        0xA1
#define RF_BITRATE_LSB_153600       0xD0
#define RF_BITRATE_LSB_57600        0x2C
#define RF_BITRATE_LSB_115200       0x16
#define RF_BITRATE_LSB_12500        0x00
#define RF_BITRATE_LSB_25000        0x00
#define RF_BITRATE_LSB_50000        0x80
#define RF_BITRATE_LSB_100000       0x40
#define RF_BITRATE_LSB_150000       0xD5
#define RF_BITRATE_LSB_200000       0xA0
#define RF_BITRATE_LSB_250000       0x80
#define RF_BITRATE_LSB_300000       0x6B
#define RF_BITRATE_LSB_32768        0xD1
#define RF_BITRATE_LSB_55555        0x40  // custom bit rate
#define RF_BITRATE_LSB_200KBPS      0xa0  // custom bit rate

/** Offset for register FDEV_MSB */
#define RG_FDEV_MSB                 (0x05)
/** RG_FDEV_MSB frequency deviation (Hz) */
#define RF_FDEV_MSB_2000            0x00
#define RF_FDEV_MSB_5000            0x00  // Default
#define RF_FDEV_MSB_7500            0x00
#define RF_FDEV_MSB_10000           0x00
#define RF_FDEV_MSB_15000           0x00
#define RF_FDEV_MSB_20000           0x01
#define RF_FDEV_MSB_25000           0x01
#define RF_FDEV_MSB_30000           0x01
#define RF_FDEV_MSB_35000           0x02
#define RF_FDEV_MSB_40000           0x02
#define RF_FDEV_MSB_45000           0x02
#define RF_FDEV_MSB_50000           0x03
#define RF_FDEV_MSB_55000           0x03
#define RF_FDEV_MSB_60000           0x03
#define RF_FDEV_MSB_65000           0x04
#define RF_FDEV_MSB_70000           0x04
#define RF_FDEV_MSB_75000           0x04
#define RF_FDEV_MSB_80000           0x05
#define RF_FDEV_MSB_85000           0x05
#define RF_FDEV_MSB_90000           0x05
#define RF_FDEV_MSB_95000           0x06
#define RF_FDEV_MSB_100000          0x06
#define RF_FDEV_MSB_110000          0x07
#define RF_FDEV_MSB_120000          0x07
#define RF_FDEV_MSB_130000          0x08
#define RF_FDEV_MSB_140000          0x08
#define RF_FDEV_MSB_150000          0x09
#define RF_FDEV_MSB_160000          0x0A
#define RF_FDEV_MSB_170000          0x0A
#define RF_FDEV_MSB_180000          0x0B
#define RF_FDEV_MSB_190000          0x0C
#define RF_FDEV_MSB_200000          0x0C
#define RF_FDEV_MSB_210000          0x0D
#define RF_FDEV_MSB_220000          0x0E
#define RF_FDEV_MSB_230000          0x0E
#define RF_FDEV_MSB_240000          0x0F
#define RF_FDEV_MSB_250000          0x10
#define RF_FDEV_MSB_260000          0x10
#define RF_FDEV_MSB_270000          0x11
#define RF_FDEV_MSB_280000          0x11
#define RF_FDEV_MSB_290000          0x12
#define RF_FDEV_MSB_300000          0x13

/** Offset for register FDEV_LSB */
#define RG_FDEV_LSB                 (0x06)
/** RG_FDEV_LSB frequency deviation (Hz) */
#define RF_FDEV_LSB_2000            0x21
#define RF_FDEV_LSB_5000            0x52  // Default
#define RF_FDEV_LSB_7500            0x7B
#define RF_FDEV_LSB_10000           0xA4
#define RF_FDEV_LSB_15000           0xF6
#define RF_FDEV_LSB_20000           0x48
#define RF_FDEV_LSB_25000           0x9A
#define RF_FDEV_LSB_30000           0xEC
#define RF_FDEV_LSB_35000           0x3D
#define RF_FDEV_LSB_40000           0x8F
#define RF_FDEV_LSB_45000           0xE1
#define RF_FDEV_LSB_50000           0x33
#define RF_FDEV_LSB_55000           0x85
#define RF_FDEV_LSB_60000           0xD7
#define RF_FDEV_LSB_65000           0x29
#define RF_FDEV_LSB_70000           0x7B
#define RF_FDEV_LSB_75000           0xCD
#define RF_FDEV_LSB_80000           0x1F
#define RF_FDEV_LSB_85000           0x71
#define RF_FDEV_LSB_90000           0xC3
#define RF_FDEV_LSB_95000           0x14
#define RF_FDEV_LSB_100000          0x66
#define RF_FDEV_LSB_110000          0x0A
#define RF_FDEV_LSB_120000          0xAE
#define RF_FDEV_LSB_130000          0x52
#define RF_FDEV_LSB_140000          0xF6
#define RF_FDEV_LSB_150000          0x9A
#define RF_FDEV_LSB_160000          0x3D
#define RF_FDEV_LSB_170000          0xE1
#define RF_FDEV_LSB_180000          0x85
#define RF_FDEV_LSB_190000          0x29
#define RF_FDEV_LSB_200000          0xCD
#define RF_FDEV_LSB_210000          0x71
#define RF_FDEV_LSB_220000          0x14
#define RF_FDEV_LSB_230000          0xB8
#define RF_FDEV_LSB_240000          0x5C
#define RF_FDEV_LSB_250000          0x00
#define RF_FDEV_LSB_260000          0xA4
#define RF_FDEV_LSB_270000          0x48
#define RF_FDEV_LSB_280000          0xEC
#define RF_FDEV_LSB_290000          0x8F
#define RF_FDEV_LSB_300000          0x33

/** Offset for register FRF_MSB */
#define RG_FRF_MSB                  (0x07)
/** RG_FRF_MSB (MHz) - carrier frequency */
/** 315 MHz */
#define RF_FRF_MSB_314              0x4E
#define RF_FRF_MSB_315              0x4E
#define RF_FRF_MSB_316              0x4F
/** 433 MHz */
#define RF_FRF_MSB_433              0x6C
#define RF_FRF_MSB_434              0x6C
#define RF_FRF_MSB_435              0x6C
/** 868 MHz */
#define RF_FRF_MSB_863              0xD7
#define RF_FRF_MSB_864              0xD8
#define RF_FRF_MSB_865              0xD8
#define RF_FRF_MSB_866              0xD8
#define RF_FRF_MSB_867              0xD8
#define RF_FRF_MSB_868              0xD9
#define RF_FRF_MSB_869              0xD9
#define RF_FRF_MSB_870              0xD9
/** 915 MHz */
#define RF_FRF_MSB_902              0xE1
#define RF_FRF_MSB_903              0xE1
#define RF_FRF_MSB_904              0xE2
#define RF_FRF_MSB_905              0xE2
#define RF_FRF_MSB_906              0xE2
#define RF_FRF_MSB_907              0xE2
#define RF_FRF_MSB_908              0xE3
#define RF_FRF_MSB_909              0xE3
#define RF_FRF_MSB_910              0xE3
#define RF_FRF_MSB_911              0xE3
#define RF_FRF_MSB_912              0xE4
#define RF_FRF_MSB_913              0xE4
#define RF_FRF_MSB_914              0xE4
#define RF_FRF_MSB_915              0xE4  // Default
#define RF_FRF_MSB_916              0xE5
#define RF_FRF_MSB_917              0xE5
#define RF_FRF_MSB_918              0xE5
#define RF_FRF_MSB_919              0xE5
#define RF_FRF_MSB_920              0xE6
#define RF_FRF_MSB_921              0xE6
#define RF_FRF_MSB_922              0xE6
#define RF_FRF_MSB_923              0xE6
#define RF_FRF_MSB_924              0xE7
#define RF_FRF_MSB_925              0xE7
#define RF_FRF_MSB_926              0xE7
#define RF_FRF_MSB_927              0xE7
#define RF_FRF_MSB_928              0xE8

/** Offset for register FRF_MID */
#define RG_FRF_MID                  (0x08)
/** RG_FRF_MID (MHz) - carrier frequency */
/** 315 MHz */
#define RF_FRF_MID_314              0x80
#define RF_FRF_MID_315              0xC0
#define RF_FRF_MID_316              0x00
/** 433 MHz */
#define RF_FRF_MID_433              0x40
#define RF_FRF_MID_434              0x80
#define RF_FRF_MID_435              0xC0
/** 868 MHz */
#define RF_FRF_MID_863              0xC0
#define RF_FRF_MID_864              0x00
#define RF_FRF_MID_865              0x40
#define RF_FRF_MID_866              0x80
#define RF_FRF_MID_867              0xC0
#define RF_FRF_MID_868              0x00
#define RF_FRF_MID_869              0x40
#define RF_FRF_MID_870              0x80
/** 915 MHz */
#define RF_FRF_MID_902              0x80
#define RF_FRF_MID_903              0xC0
#define RF_FRF_MID_904              0x00
#define RF_FRF_MID_905              0x40
#define RF_FRF_MID_906              0x80
#define RF_FRF_MID_907              0xC0
#define RF_FRF_MID_908              0x00
#define RF_FRF_MID_909              0x40
#define RF_FRF_MID_910              0x80
#define RF_FRF_MID_911              0xC0
#define RF_FRF_MID_912              0x00
#define RF_FRF_MID_913              0x40
#define RF_FRF_MID_914              0x80
#define RF_FRF_MID_915              0xC0  // Default
#define RF_FRF_MID_916              0x00
#define RF_FRF_MID_917              0x40
#define RF_FRF_MID_918              0x80
#define RF_FRF_MID_919              0xC0
#define RF_FRF_MID_920              0x00
#define RF_FRF_MID_921              0x40
#define RF_FRF_MID_922              0x80
#define RF_FRF_MID_923              0xC0
#define RF_FRF_MID_924              0x00
#define RF_FRF_MID_925              0x40
#define RF_FRF_MID_926              0x80
#define RF_FRF_MID_927              0xC0
#define RF_FRF_MID_928              0x00

/** Offset for register FRF_LSB */
#define RG_FRF_LSB                  (0x09)
/** RG_FRF_LSB (MHz) - carrier frequency */
/** 315 MHz */
#define RF_FRF_LSB_314              0x00
#define RF_FRF_LSB_315              0x00
#define RF_FRF_LSB_316              0x00
/** 433 MHz */
#define RF_FRF_LSB_433              0x00
#define RF_FRF_LSB_434              0x00
#define RF_FRF_LSB_435              0x00
/** 868 MHz */
#define RF_FRF_LSB_863              0x00
#define RF_FRF_LSB_864              0x00
#define RF_FRF_LSB_865              0x00
#define RF_FRF_LSB_866              0x00
#define RF_FRF_LSB_867              0x00
#define RF_FRF_LSB_868              0x00
#define RF_FRF_LSB_869              0x00
#define RF_FRF_LSB_870              0x00
/** 915 MHz */
#define RF_FRF_LSB_902              0x00
#define RF_FRF_LSB_903              0x00
#define RF_FRF_LSB_904              0x00
#define RF_FRF_LSB_905              0x00
#define RF_FRF_LSB_906              0x00
#define RF_FRF_LSB_907              0x00
#define RF_FRF_LSB_908              0x00
#define RF_FRF_LSB_909              0x00
#define RF_FRF_LSB_910              0x00
#define RF_FRF_LSB_911              0x00
#define RF_FRF_LSB_912              0x00
#define RF_FRF_LSB_913              0x00
#define RF_FRF_LSB_914              0x00
#define RF_FRF_LSB_915              0x00  // Default
#define RF_FRF_LSB_916              0x00
#define RF_FRF_LSB_917              0x00
#define RF_FRF_LSB_918              0x00
#define RF_FRF_LSB_919              0x00
#define RF_FRF_LSB_920              0x00
#define RF_FRF_LSB_921              0x00
#define RF_FRF_LSB_922              0x00
#define RF_FRF_LSB_923              0x00
#define RF_FRF_LSB_924              0x00
#define RF_FRF_LSB_925              0x00
#define RF_FRF_LSB_926              0x00
#define RF_FRF_LSB_927              0x00
#define RF_FRF_LSB_928              0x00

/** Offset for register OSC1 */
#define RG_OSC1                     (0x0A)
/** Access parameters for sub-register CAL_START in register @ref RG_OSC1 */
#define SR_CAL_START                0x0A,   0x80,   7
/** Access parameters for sub-register CAL_DONE in register @ref RG_OSC1 */
#define SR_CAL_DONE                 0x0A,   0x40,   6

/** Offset for register AFC_CTRL */
#define RG_AFC_CTRL                 (0x0B)
/** Access parameters for sub-register LISTEN_RESIL_IDLE in register @ref RG_AFC_CTRL */
#define SR_AFC_LOW_BETA_ON          0x0B,   0x10,   5
/** Constant AFC_ROUTINE_STANDARD for sub-register @ref SR_AFC_LOW_BETA_ON */
#define AFC_ROUTINE_STANDARD        (0)
/** Constant AFC_ROUTINE_IMPROVED for sub-register @ref SR_AFC_LOW_BETA_ON */
#define AFC_ROUTINE_IMPROVED        (1)

/** Offset for register LISTEN1 */
#define RG_LISTEN1                  (0x0D)
/** Access parameters for sub-register LISTEN_RESOL_IDLE in register @ref RG_LISTEN1 */
#define SR_LISTEN_RESOL_IDLE        0x0D,   0x60,   6
/** Constant RESOL_IDLE_TIME_64US for sub-register @ref SR_LISTEN_RESOL_IDLE */
#define RESOL_IDLE_TIME_64US        (1)
/** Constant RESOL_IDLE_TIME_41MS for sub-register @ref SR_LISTEN_RESOL_IDLE */
#define RESOL_IDLE_TIME_41MS        (2)
/** Constant RESOL_IDLE_TIME_262MS for sub-register @ref SR_LISTEN_RESOL_IDLE */
#define RESOL_IDLE_TIME_262MS       (3)
/** Access parameters for sub-register LISTEN_RESOL_RX in register @ref RG_LISTEN1 */
#define SR_LISTEN_RESOL_RX          0x0D,   0x18,   4
/** Constant RESOL_RX_TIME_64US for sub-register @ref SR_LISTEN_RESOL_RX */
#define RESOL_RX_TIME_64US          (1)
/** Constant RESOL_RX_TIME_41MS for sub-register @ref SR_LISTEN_RESOL_RX */
#define RESOL_RX_TIME_41MS          (2)
/** Constant RESOL_RX_TIME_262MS for sub-register @ref SR_LISTEN_RESOL_RX */
#define RESOL_RX_TIME_262MS         (3)
/** Access parameters for sub-register LISTEN_CRITERIA in register @ref RG_LISTEN1 */
#define SR_LISTEN_CRITERIA          0x0D,   0x08,   3
/** Constant LISTEN_CRITERIA1 for sub-register @ref SR_LISTEN_CRITERIA */
#define LISTEN_CRITERIA1            (0)
/** Constant LISTEN_CRITERIA2 for sub-register @ref SR_LISTEN_CRITERIA */
#define LISTEN_CRITERIA2            (1)
/** Access parameters for sub-register LISTEN_END in register @ref RG_LISTEN1 */
#define SR_LISTEN_END               0x0D,   0x06,   1
/** Constant LISTEN_ACTION1 for sub-register @ref SR_LISTEN_END */
#define LISTEN_ACTION1              (0)
/** Constant LISTEN_ACTION2 for sub-register @ref SR_LISTEN_END */
#define LISTEN_ACTION2              (2)
/** Constant LISTEN_ACTION3 for sub-register @ref SR_LISTEN_END */
#define LISTEN_ACTION3              (3)

/** Offset for register LISTEN2 */
#define RG_LISTEN2                  (0x0E)
/** Access parameters for sub-register LISTEN_COEF_IDLE in register @ref RG_LISTEN2 */
#define SR_LISTEN_COEF_IDLE         0x0E,   0xFF,   0

/** Offset for register LISTEN3 */
#define RG_LISTEN3                  (0x0F)
/** Access parameters for sub-register LISTEN_COEF_RX in register @ref RG_LISTEN3 */
#define SR_LISTEN_COEF_RX           0x0F,   0xFF,   0

/** Offset for register VERSION */
#define RG_VERSION                  (0x10)

/** Offset for register PA_LEVEL */
#define RG_PA_LEVEL                 (0x11)
/** Access parameters for sub-register PA0_ON in register @ref RG_PA_LEVEL */
#define SR_PA0                      0x11,   0x80,   7
/** Constant PA0_OFF for sub-register @ref SR_PA0 */
#define PA0_OFF                     (0)
/** Constant PA0_ON for sub-register @ref SR_PA0 */
#define PA0_ON                      (1)
/** Access parameters for sub-register PA1_ON in register @ref RG_PA_LEVEL */
#define SR_PA1                      0x11,   0x40,   6
/** Constant PA1_OFF for sub-register @ref SR_PA1 */
#define PA1_OFF                     (0)
/** Constant PA1_ON for sub-register @ref SR_PA1 */
#define PA1_ON                      (1)
/** Access parameters for sub-register PA2_ON in register @ref RG_PA_LEVEL */
#define SR_PA2                      0x11,   0x20,   5
/** Constant PA2_OFF for sub-register @ref SR_PA2 */
#define PA2_OFF                     (0)
/** Constant PA2_ON for sub-register @ref SR_PA2 */
#define PA2_ON                      (1)
/** Access parameters for sub-register OUTPUT_POWER in register @ref RG_PA_LEVEL */
#define SR_OUTPUT_POWER             0x11,   0x1F,   0

/** Offset for register PA_RAMP */
#define RG_PA_RAMP                  (0x12)
/** Access parameters for sub-register PA_RAMP in register @ref RG_PA_RAMP */
#define SR_PA_RAMP                  0x12,   0x0F,   0
/** Constant PA_RAMP_TIME_34MS for sub-register @ref SR_PA_RAMP */
#define PA_RAMP_TIME_34MS           (0)
/** Constant PA_RAMP_TIME_2MS for sub-register @ref SR_PA_RAMP */
#define PA_RAMP_TIME_2MS            (1)
/** Constant PA_RAMP_TIME_1MS for sub-register @ref SR_PA_RAMP */
#define PA_RAMP_TIME_1MS            (2)
/** Constant PA_RAMP_TIME_500US for sub-register @ref SR_PA_RAMP */
#define PA_RAMP_TIME_500US          (3)
/** Constant PA_RAMP_TIME_250US for sub-register @ref SR_PA_RAMP */
#define PA_RAMP_TIME_250US          (4)
/** Constant PA_RAMP_TIME_125US for sub-register @ref SR_PA_RAMP */
#define PA_RAMP_TIME_125US          (5)
/** Constant PA_RAMP_TIME_100US for sub-register @ref SR_PA_RAMP */
#define PA_RAMP_TIME_100US          (6)
/** Constant PA_RAMP_TIME_62US for sub-register @ref SR_PA_RAMP */
#define PA_RAMP_TIME_62US           (7)
/** Constant PA_RAMP_TIME_50US for sub-register @ref SR_PA_RAMP */
#define PA_RAMP_TIME_50US           (8)
/** Constant PA_RAMP_TIME_40US for sub-register @ref SR_PA_RAMP */
#define PA_RAMP_TIME_40US           (9)
/** Constant PA_RAMP_TIME_31US for sub-register @ref SR_PA_RAMP */
#define PA_RAMP_TIME_31US           (10)
/** Constant PA_RAMP_TIME_25US for sub-register @ref SR_PA_RAMP */
#define PA_RAMP_TIME_25US           (11)
/** Constant PA_RAMP_TIME_20US for sub-register @ref SR_PA_RAMP */
#define PA_RAMP_TIME_20US           (12)
/** Constant PA_RAMP_TIME_15US for sub-register @ref SR_PA_RAMP */
#define PA_RAMP_TIME_15US           (13)
/** Constant PA_RAMP_TIME_12US for sub-register @ref SR_PA_RAMP */
#define PA_RAMP_TIME_12US           (14)
/** Constant PA_RAMP_TIME_10US for sub-register @ref SR_PA_RAMP */
#define PA_RAMP_TIME_10US           (15)

/** Offset for register OCP */
#define RG_OCP                      (0x13)
/** Access parameters for sub-register OCP_ON  in register @ref RG_OCP */
#define SR_OCP                      0x13,   0x10,   4
/** Constant OCP_OFF for sub-register @ref SR_OCP_ON */
#define OCP_OFF                     (0)
/** Constant OCP_ON for sub-register @ref SR_OCP_ON */
#define OCP_ON                      (1)
/** Access parameters for sub-register OCP_TRIM in register @ref RG_OCP */
#define SR_OCP_TRIM                 0x13,   0x0F,   0

/** Offset for register LNA */
#define RG_LNA                      (0x18)
/** Access parameters for sub-register LNA_ZIN in register @ref RG_LNA */
#define SR_LNA_ZIN                  0x18,   0x80,   7
/** Constant LNA_ZIN_50OHM for sub-register @ref SR_LNA_ZIN */
#define LNA_ZIN_50OHM               (0)
/** Constant LNA_ZIN_200OHM for sub-register @ref SR_LNA_ZIN */
#define LNA_ZIN_200OHM              (1)
/** Access parameters for sub-register LNA_CURRENT_GAIN in register @ref RG_LNA */
#define SR_LNA_CURRENT_GAIN         0x18,   0x38,   3
/** Access parameters for sub-register LNA_GAIN_SELECT in register @ref RG_LNA */
#define SR_LNA_GAIN_SELECT          0x18,   0x07,   0
/** Constant  for sub-register @ref */
#define GAIN_SELECT_BY_AGC          (0)
/** Constant GAIN_SELECT_G1 for sub-register @ref GAIN_SELECT_BY_AGC */
#define GAIN_SELECT_G1              (1)
/** Constant GAIN_SELECT_G2 for sub-register @ref GAIN_SELECT_BY_AGC */
#define GAIN_SELECT_G2              (2)
/** Constant GAIN_SELECT_G3 for sub-register @ref GAIN_SELECT_BY_AGC */
#define GAIN_SELECT_G3              (3)
/** Constant GAIN_SELECT_G4 for sub-register @ref GAIN_SELECT_BY_AGC */
#define GAIN_SELECT_G4              (4)
/** Constant GAIN_SELECT_G5 for sub-register @ref GAIN_SELECT_BY_AGC */
#define GAIN_SELECT_G5              (5)
/** Constant GAIN_SELECT_G6 for sub-register @ref GAIN_SELECT_BY_AGC */
#define GAIN_SELECT_G6              (6)

/** Offset for register RX_BW */
#define RG_RX_BW                    (0x19)
/** Access parameters for sub-register DCC_FREQ in register @ref RG_RX_BW */
#define SR_DCC_FREQ                 0x19,   0xE0,   5
/** Constant DCC_FREQ_000 for sub-register @ref SR_DCC_FREQ */
#define DCC_FREQ_000                (0)
/** Constant DCC_FREQ_001 for sub-register @ref SR_DCC_FREQ */
#define DCC_FREQ_001                (1)
/** Constant DCC_FREQ_010 for sub-register @ref SR_DCC_FREQ (Recommended default) */
#define DCC_FREQ_010                (2)
/** Constant DCC_FREQ_011 for sub-register @ref SR_DCC_FREQ */
#define DCC_FREQ_011                (3)
/** Constant DCC_FREQ_100 for sub-register @ref SR_DCC_FREQ */
#define DCC_FREQ_100                (4)
/** Constant DCC_FREQ_101 for sub-register @ref SR_DCC_FREQ */
#define DCC_FREQ_101                (5)
/** Constant DCC_FREQ_110 for sub-register @ref SR_DCC_FREQ */
#define DCC_FREQ_110                (6)
/** Constant DCC_FREQ_111 for sub-register @ref SR_DCC_FREQ */
#define DCC_FREQ_111                (7)
/** Access parameters for sub-register RX_BW_MANT in register @ref RG_RX_BW */
#define SR_RX_BW_MANT               0x19,   0x18,   3
/** Constant RX_BW_MANT_16 for sub-register @ref SR_RX_BW_MANT */
#define RX_BW_MANT_16               (0)
/** Constant RX_BW_MANT_20 for sub-register @ref SR_RX_BW_MANT */
#define RX_BW_MANT_20               (1)
/** Constant RX_BW_MANT_24 for sub-register @ref SR_RX_BW_MANT (Recommended default) */
#define RX_BW_MANT_24               (2)
/** Access parameters for sub-register RX_BW_EXP in register @ref RG_RX_BW */
#define SR_RX_BW_EXP                0x19,   0x07,   0
/** Constant RX_BW_EXP_0 for sub-register @ref SR_RX_BW_EXP */
#define RX_BW_EXP_0                 (0)
/** Constant RX_BW_EXP_1 for sub-register @ref SR_RX_BW_EXP */
#define RX_BW_EXP_1                 (1)
/** Constant RX_BW_EXP_2 for sub-register @ref SR_RX_BW_EXP */
#define RX_BW_EXP_2                 (2)
/** Constant RX_BW_EXP_3 for sub-register @ref SR_RX_BW_EXP */
#define RX_BW_EXP_3                 (3)
/** Constant RX_BW_EXP_4 for sub-register @ref SR_RX_BW_EXP */
#define RX_BW_EXP_4                 (4)
/** Constant RX_BW_EXP_5 for sub-register @ref SR_RX_BW_EXP (Recommended default) */
#define RX_BW_EXP_5                 (5)
/** Constant RX_BW_EXP_6 for sub-register @ref SR_RX_BW_EXP */
#define RX_BW_EXP_6                 (6)
/** Constant RX_BW_EXP_7 for sub-register @ref SR_RX_BW_EXP */
#define RX_BW_EXP_7                 (7)

/** Offset for register AFC_BW */
#define RG_AFC_BW                   (0x1A)
/** Access parameters for sub-register DCC_FREQ_AFC in register @ref RG_AFC_BW */
#define SR_DCC_FREQ_AFC             0x1A,   0xE0,   5
/** Access parameters for sub-register RX_BW_MANT_AFC in register @ref RG_AFC_BW */
#define SR_RX_BW_MANT_AFC           0x1A,   0x18,   3
/** Access parameters for sub-register RX_BW_EXP_AFC in register @ref RG_AFC_BW */
#define SR_RX_BW_EXP_AFC            0x1A,   0x07,   0

/** Offset for register OOK_PEAK */
#define RG_OOK_PEAK                 (0x1B)
/** Access parameters for sub-register OOK_THRESH_TYPE  in register @ref RG_OOK_PEAK */
#define SR_OOK_THRESH_TYPE          0x1B,   0xC0,   6
/** Constant OOK_THRESH_TYPE_FIXED for sub-register @ref SR_OOK_THRESH_TYPE */
#define OOK_THRESH_TYPE_FIXED       (0)
/** Constant OOK_THRESH_TYPE_PEAK for sub-register @ref SR_OOK_THRESH_TYPE */
#define OOK_THRESH_TYPE_PEAK        (1)
/** Constant OOK_THRESH_TYPE_AVERAGE for sub-register @ref SR_OOK_THRESH_TYPE */
#define OOK_THRESH_TYPE_AVERAGE     (2)
/** Access parameters for sub-register OOK_PEAK_THRESH_STEP in register @ref RG_OOK_PEAK */
#define SR_OOK_PEAK_THRESH_STEP     0x1B,   0x38,   3
/** Constant OOK_PEAK_THRESH_STEP_05 for sub-register @ref SR_OOK_PEAK_THRESH_STEP */
#define OOK_PEAK_THRESH_STEP_05     (0)
/** Constant OOK_PEAK_THRESH_STEP_10 for sub-register @ref SR_OOK_PEAK_THRESH_STEP */
#define OOK_PEAK_THRESH_STEP_10     (1)
/** Constant OOK_PEAK_THRESH_STEP_15 for sub-register @ref SR_OOK_PEAK_THRESH_STEP */
#define OOK_PEAK_THRESH_STEP_15     (2)
/** Constant OOK_PEAK_THRESH_STEP_20 for sub-register @ref SR_OOK_PEAK_THRESH_STEP */
#define OOK_PEAK_THRESH_STEP_20     (3)
/** Constant OOK_PEAK_THRESH_STEP_30 for sub-register @ref SR_OOK_PEAK_THRESH_STEP */
#define OOK_PEAK_THRESH_STEP_30     (4)
/** Constant OOK_PEAK_THRESH_STEP_40 for sub-register @ref SR_OOK_PEAK_THRESH_STEP */
#define OOK_PEAK_THRESH_STEP_40     (5)
/** Constant OOK_PEAK_THRESH_STEP_50 for sub-register @ref SR_OOK_PEAK_THRESH_STEP */
#define OOK_PEAK_THRESH_STEP_50     (6)
/** Constant OOK_PEAK_THRESH_STEP_60 for sub-register @ref SR_OOK_PEAK_THRESH_STEP */
#define OOK_PEAK_THRESH_STEP_60     (7)
/** Access parameters for sub-register OOK_PEAK_THRESH_DEC in register @ref RG_OOK_PEAK */
#define SR_OOK_PEAK_THRESH_DEC      0x1B,   0x07,   0
/** Constant OOK_PEAK_THRESH_DEC_1_1 for sub-register @ref SR_OOK_PEAK_THRESH_DEC */
#define OOK_PEAK_THRESH_DEC_1_1     (0)
/** Constant OOK_PEAK_THRESH_DEC_1_2 for sub-register @ref SR_OOK_PEAK_THRESH_DEC */
#define OOK_PEAK_THRESH_DEC_1_2     (1)
/** Constant OOK_PEAK_THRESH_DEC_1_4 for sub-register @ref SR_OOK_PEAK_THRESH_DEC */
#define OOK_PEAK_THRESH_DEC_1_4     (2)
/** Constant OOK_PEAK_THRESH_DEC_1_8 for sub-register @ref SR_OOK_PEAK_THRESH_DEC */
#define OOK_PEAK_THRESH_DEC_1_8     (3)
/** Constant OOK_PEAK_THRESH_DEC_2_1 for sub-register @ref SR_OOK_PEAK_THRESH_DEC */
#define OOK_PEAK_THRESH_DEC_2_1     (4)
/** Constant OOK_PEAK_THRESH_DEC_4_1 for sub-register @ref SR_OOK_PEAK_THRESH_DEC */
#define OOK_PEAK_THRESH_DEC_4_1     (5)
/** Constant OOK_PEAK_THRESH_DEC_8_1 for sub-register @ref SR_OOK_PEAK_THRESH_DEC */
#define OOK_PEAK_THRESH_DEC_8_1     (6)
/** Constant OOK_PEAK_THRESH_DEC_16_1 for sub-register @ref SR_OOK_PEAK_THRESH_DEC */
#define OOK_PEAK_THRESH_DEC_16_1    (7)

/** Offset for register OOK_AVG */
#define RG_OOK_AVG                  (0x1C)
/** Access parameters for sub-register OOK_AVERAGE_THRESH_FILT in register @ref RG_OOK_AVG */
#define SR_OOK_AVERAGE_THRESH_FILT  0x1C,   0xC0,   6
/** Constant OOK_AVERAGE_THRESH_FILT1 for sub-register @ref SR_OOK_AVERAGE_THRESH_FILT */
#define OOK_AVERAGE_THRESH_FILT1    (0)
/** Constant OOK_AVERAGE_THRESH_FILT2 for sub-register @ref SR_OOK_AVERAGE_THRESH_FILT */
#define OOK_AVERAGE_THRESH_FILT2    (1)
/** Constant OOK_AVERAGE_THRESH_FILT3 for sub-register @ref SR_OOK_AVERAGE_THRESH_FILT */
#define OOK_AVERAGE_THRESH_FILT3    (2)
/** Constant OOK_AVERAGE_THRESH_FILT4 for sub-register @ref SR_OOK_AVERAGE_THRESH_FILT */
#define OOK_AVERAGE_THRESH_FILT4    (3)

/** Offset for register OOK_FIX */
#define RG_OOK_FIX                  (0x1D)
/** Access parameters for sub-register OOK_FIXED_THRESH in register @ref RG_OOK_FIX */
#define SR_OOK_FIXED_THRESH         0x1D,   0xFF,   0

/** Offset for register AFC_FEI */
#define RG_AFC_FEI                  (0x1E)
/** Access parameters for sub-register FEI_DONE in register @ref RG_AFC_FEI */
#define SR_FEI_DONE                 0x1E,   0x40,   6
/** Access parameters for sub-register FEI_START in register @ref RG_AFC_FEI */
#define SR_FEI_START                0x1E,   0x20,   5
/** Access parameters for sub-register AFC_DONE in register @ref RG_AFC_FEI */
#define SR_AFC_DONE                 0x1E,   0x10,   4
/** Access parameters for sub-register AFC_AUTOCLEAR_ON in register @ref RG_AFC_FEI */
#define SR_AFC_AUTOCLEAR_ON         0x1E,   0x08,   3
/** Constant AFC_NOT_CLEARED for sub-register @ref SR_AFC_AUTOCLEAR_ON */
#define AFC_NOT_CLEARED             (0)
/** Constant AFC_CLEARED for sub-register @ref SR_AFC_AUTOCLEAR_ON */
#define AFC_CLEARED                 (1)
/** Access parameters for sub-register AFC_AUTO_ON in register @ref RG_AFC_FEI */
#define SR_AFC_AUTO_ON              0x1E,   0x04,   2
/** Constant AFC_AUTO_ON_MODE1 for sub-register @ref SR_AFC_AUTO_ON */
#define AFC_AUTO_ON_MODE1           (0)
/** Constant AFC_AUTO_ON_MODE2 for sub-register @ref SR_AFC_AUTO_ON */
#define AFC_AUTO_ON_MODE2           (1)
/** Access parameters for sub-register AFC_CLEAR in register @ref RG_AFC_FEI */
#define SR_AFC_CLEAR                0x1E,   0x02,   1
/** Access parameters for sub-register AFC_START in register @ref RG_AFC_FEI */
#define SR_AFC_START                0x1E,   0x01,   0

/** Offset for register AFC_LSB */
#define RG_AFC_MSB                  (0x1F)

/** Offset for register PACKET_PAYLOAD_LENGTH */
#define RG_AFC_LSB                  (0x20)

/** Offset for register FEI_MSB */
#define RG_FEI_MSB                  (0x21)

/** Offset for register FEI_LSB */
#define RG_FEI_LSB                  (0x22)

/** Offset for register RSSI_CONFIG */
#define RG_RSSI_CONFIG              (0x23)
/** Access parameters for sub-register RSSI_DONE in register @ref RG_RSSI_CONFIG */
#define SR_RSSI_DONE                0x23,   0x02,   1
/** Access parameters for sub-register RSSI_START in register @ref RG_RSSI_CONFIG */
#define SR_RSSI_START               0x23,   0x01,   0

/** Offset for register RSSI_VALUE */
#define RG_RSSI_VALUE               (0x24)

/** Offset for register DIO_MAPPING1 */
#define RG_DIO_MAPPING1             (0x25)
/** Access parameters for sub-register DIO0_MAPPING in register @ref RG_DIO_MAPPING1 */
#define SR_DIO0_MAPPING             0x25,   0xC0,   6
/** Constant DIO0_MAPPING_00 for sub-register @ref SR_DIO0_MAPPING */
#define DIO0_MAPPING_00             (0)
/** Constant DIO0_MAPPING_01 for sub-register @ref SR_DIO0_MAPPING */
#define DIO0_MAPPING_01             (1)
/** Constant DIO0_MAPPING_10 for sub-register @ref SR_DIO0_MAPPING */
#define DIO0_MAPPING_10             (2)
/** Constant DIO0_MAPPING_11 for sub-register @ref SR_DIO0_MAPPING */
#define DIO0_MAPPING_11             (3)
/** Access parameters for sub-register DIO1_MAPPING in register @ref RG_DIO_MAPPING1 */
#define SR_DIO1_MAPPING             0x25,   0x30,   4
/** Constant DIO1_MAPPING_00 for sub-register @ref SR_DIO1_MAPPING */
#define DIO1_MAPPING_00             (0)
/** Constant DIO1_MAPPING_01 for sub-register @ref SR_DIO1_MAPPING */
#define DIO1_MAPPING_01             (1)
/** Constant DIO1_MAPPING_10 for sub-register @ref SR_DIO1_MAPPING */
#define DIO1_MAPPING_10             (2)
/** Constant DIO1_MAPPING_11 for sub-register @ref SR_DIO1_MAPPING */
#define DIO1_MAPPING_11             (3)
/** Access parameters for sub-register DIO2_MAPPING in register @ref RG_DIO_MAPPING1 */
#define SR_DIO2_MAPPING             0x25,   0x0C,   2
/** Constant DIO2_MAPPING_00 for sub-register @ref SR_DIO2_MAPPING */
#define DIO2_MAPPING_00             (0)
/** Constant DIO2_MAPPING_01 for sub-register @ref SR_DIO2_MAPPING */
#define DIO2_MAPPING_01             (1)
/** Constant DIO2_MAPPING_10 for sub-register @ref SR_DIO2_MAPPING */
#define DIO2_MAPPING_10             (2)
/** Constant DIO2_MAPPING_11 for sub-register @ref SR_DIO2_MAPPING */
#define DIO2_MAPPING_11             (3)
/** Access parameters for sub-register DIO3_MAPPING in register @ref RG_DIO_MAPPING1 */
#define SR_DIO3_MAPPING             0x25,   0x03,   0
/** Constant DIO3_MAPPING_00 for sub-register @ref SR_DIO3_MAPPING */
#define DIO3_MAPPING_00             (0)
/** Constant DIO3_MAPPING_01 for sub-register @ref SR_DIO3_MAPPING */
#define DIO3_MAPPING_01             (1)
/** Constant DIO3_MAPPING_10 for sub-register @ref SR_DIO3_MAPPING */
#define DIO3_MAPPING_10             (2)
/** Constant DIO3_MAPPING_11 for sub-register @ref SR_DIO3_MAPPING */
#define DIO3_MAPPING_11             (3)

/** Offset for register DIO_MAPPING2 */
#define RG_DIO_MAPPING2             (0x26)
/** Access parameters for sub-register DIO4_MAPPING in register @ref DIO_MAPPING2 */
#define SR_DIO4_MAPPING             0x26,   0xC0,   6
/** Constant DIO4_MAPPING_00 for sub-register @ref SR_DIO4_MAPPING */
#define DIO4_MAPPING_00             (0)
/** Constant DIO4_MAPPING_01 for sub-register @ref SR_DIO4_MAPPING */
#define DIO4_MAPPING_01             (1)
/** Constant DIO4_MAPPING_10 for sub-register @ref SR_DIO4_MAPPING */
#define DIO4_MAPPING_10             (2)
/** Constant DIO4_MAPPING_11 for sub-register @ref SR_DIO4_MAPPING */
#define DIO4_MAPPING_11             (3)
/** Access parameters for sub-register DIO5_MAPPING in register @ref DIO_MAPPING2 */
#define SR_DIO5_MAPPING             0x26,   0x30,   4
/** Constant DIO5_MAPPING_00 for sub-register @ref SR_DIO5_MAPPING */
#define DIO5_MAPPING_00             (0)
/** Constant DIO5_MAPPING_01 for sub-register @ref SR_DIO5_MAPPING */
#define DIO5_MAPPING_01             (1)
/** Constant DIO5_MAPPING_10 for sub-register @ref SR_DIO5_MAPPING */
#define DIO5_MAPPING_10             (2)
/** Constant DIO5_MAPPING_11 for sub-register @ref SR_DIO5_MAPPING */
#define DIO5_MAPPING_11             (3)
/** Access parameters for sub-register CLK_OUT in register @ref DIO_MAPPING2 */
#define SR_CLK_OUT                  0x26,   0x07,   0
/** Constant CLK_OUT_FXOSC for sub-register @ref SR_CLK_OUT */
#define CLK_OUT_FXOSC               (0)
/** Constant CLK_OUT_FXOSC_2 for sub-register @ref SR_CLK_OUT */
#define CLK_OUT_FXOSC_2             (1)
/** Constant CLK_OUT_FXOSC_4 for sub-register @ref SR_CLK_OUT */
#define CLK_OUT_FXOSC_4             (2)
/** Constant CLK_OUT_FXOSC_8 for sub-register @ref SR_CLK_OUT */
#define CLK_OUT_FXOSC_8             (3)
/** Constant CLK_OUT_FXOSC_16 for sub-register @ref SR_CLK_OUT */
#define CLK_OUT_FXOSC_16            (4)
/** Constant CLK_OUT_FXOSC_32 for sub-register @ref SR_CLK_OUT */
#define CLK_OUT_FXOSC_32            (5)
/** Constant CLK_OUT_RC for sub-register @ref SR_CLK_OUT */
#define CLK_OUT_RC                  (6)
/** Constant CLK_OUT_OFF for sub-register @ref SR_CLK_OUT */
#define CLK_OUT_OFF                 (7)

/** Offset for register IRQ_FLAGS1 */
#define RG_IRQ_FLAGS1               (0x27)
/** Access parameters for sub-register MODE_READY in register @ref RG_IRQ_FLAGS1 */
#define SR_MODE_READY               0x27,   0x80,   7
/** Access parameters for sub-register RX_READY in register @ref RG_IRQ_FLAGS1 */
#define SR_RX_READY                 0x27,   0x40,   6
/** Access parameters for sub-register TX_READY in register @ref RG_IRQ_FLAGS1 */
#define SR_TX_READY                 0x27,   0x20,   5
/** Access parameters for sub-register PLL_LOCK in register @ref RG_IRQ_FLAGS1 */
#define SR_PLL_LOCK                 0x27,   0x10,   4
/** Access parameters for sub-register RSSI in register @ref RG_IRQ_FLAGS1 */
#define SR_RSSI                     0x27,   0x08,   3
/** Access parameters for sub-register TIMEOUT in register @ref RG_IRQ_FLAGS1 */
#define SR_TIMEOUT                  0x27,   0x04,   2
/** Access parameters for sub-register AUTO_MODE in register @ref RG_IRQ_FLAGS1 */
#define SR_AUTO_MODE                0x27,   0x02,   1
/** Access parameters for sub-register SYNC_ADDRESS_MATCH in register @ref RG_IRQ_FLAGS1 */
#define SR_SYNC_ADDRESS_MATCH       0x27,   0x01,   0

/** Offset for register IRQ_FLAGS2 */
#define RG_IRQ_FLAGS2               (0x28)
/** Access parameters for sub-register FIFO_FULL in register @ref RG_IRQ_FLAGS2 */
#define SR_FIFO_FULL                0x28,   0x80,   7
/** Access parameters for sub-register FIFO_NOT_EMPTY in register @ref RG_IRQ_FLAGS2 */
#define SR_FIFO_NOT_EMPTY           0x28,   0x40,   6
/** Access parameters for sub-register FIFO_LEVEL in register @ref RG_IRQ_FLAGS2 */
#define SR_FIFO_LEVEL               0x28,   0x20,   5
/** Access parameters for sub-register FIFO_OVERRUN in register @ref RG_IRQ_FLAGS2 */
#define SR_FIFO_OVERRUN             0x28,   0x10,   4
/** Access parameters for sub-register PACKET_SENT in register @ref RG_IRQ_FLAGS2 */
#define SR_PACKET_SENT              0x28,   0x08,   3
/** Access parameters for sub-register PAYLOAD_READY in register @ref RG_IRQ_FLAGS2 */
#define SR_PAYLOAD_READY            0x28,   0x04,   2
/** Access parameters for sub-register CRC_OK in register @ref RG_IRQ_FLAGS2 */
#define SR_CRC_OK                   0x28,   0x02,   1

/** Offset for register RSSI_THRESH */
#define RG_RSSI_THRESH              (0x29)

/** Offset for register RX_TIMEOUT1 */
#define RG_RX_TIMEOUT1              (0x2A)
/** Access parameters for sub-register TIMEOUT_RX_START in register @ref RG_RX_TIMEOUT1 */
#define SR_TIMEOUT_RX_START         0x2A,   0xFF,   0

/** Offset for register RX_TIMEOUT2 */
#define RG_RX_TIMEOUT2              (0x2B)
/** Access parameters for sub-register TIMEOUT_RSSI_THRESH in register @ref RG_RX_TIMEOUT2 */
#define SR_TIMEOUT_RSSI_THRESH      0x2B,   0xFF,   0

/** Offset for register PREAMBLE_MSB */
#define RG_PREAMBLE_MSB             (0x2C)

/** Offset for register PREAMBLE_LSB */
#define RG_PREAMBLE_LSB             (0x2D)

/** Offset for register SYNC_CONFIG */
#define RG_SYNC_CONFIG              (0x2E)
/** Access parameters for sub-register SYNC_ON in register @ref SYNC_CONFIG */
#define SR_SYNC                     0x2E,   0x80,   7
/** Constant SYNC_OFF for sub-register @ref SR_SYNC_ON */
#define SYNC_OFF                    (0)
/** Constant SYNC_ON for sub-register @ref SR_SYNC_ON */
#define SYNC_ON                     (1)
/** Access parameters for sub-register FIFO_FILL_CONDITION in register @ref SYNC_CONFIG */
#define SR_FIFO_FILL_CONDITION      0x2E,   0x40,   6
/** Constant FIFO_FILL_CONDITION_AUTO for sub-register @ref SR_FIFO_FILL_CONDITION */
#define FIFO_FILL_CONDITION_AUTO    (0)
/** Constant FIFO_FILL_CONDITION_MANUAL for sub-register @ref SR_FIFO_FILL_CONDITION */
#define FIFO_FILL_CONDITION_MANUAL  (1)
/** Access parameters for sub-register SYNC_SIZE in register @ref SYNC_CONFIG */
#define SR_SYNC_SIZE                0x2E,   0x38,   3
#define SYNC_SIZE_1                 (0)
#define SYNC_SIZE_2                 (1)
#define SYNC_SIZE_3                 (2)
#define SYNC_SIZE_4                 (3)
#define SYNC_SIZE_5                 (4)
#define SYNC_SIZE_6                 (5)
#define SYNC_SIZE_7                 (6)
#define SYNC_SIZE_8                 (7)
/** Access parameters for sub-register SYNC_TOL in register @ref SYNC_CONFIG */
#define SR_SYNC_TOL                 0x2E,   0x07,   0

/** Offset for register SYNC_VALUE1 */
#define RG_SYNC_VALUE1              (0x2F)

/** Offset for register SYNC_VALUE2 */
#define RG_SYNC_VALUE2              (0x30)

/** Offset for register SYNC_VALUE3 */
#define RG_SYNC_VALUE3              (0x31)

/** Offset for register SYNC_VALUE4 */
#define RG_SYNC_VALUE4              (0x32)

/** Offset for register SYNC_VALUE5 */
#define RG_SYNC_VALUE5              (0x33)

/** Offset for register SYNC_VALUE6 */
#define RG_SYNC_VALUE6              (0x34)

/** Offset for register SYNC_VALUE7 */
#define RG_SYNC_VALUE7              (0x35)

/** Offset for register SYNC_VALUE8 */
#define RG_SYNC_VALUE8              (0x36)

/** Offset for register PACKET_CONFIG1 */
#define RG_PACKET_CONFIG1           (0x37)
/** Access parameters for sub-register PACKET_FORMAT in register @ref RG_PACKET_CONFIG1 */
#define SR_PACKET_FORMAT            0x37,   0x80,   7
/** Constant PACKET_FORMAT_FIXED for sub-register @ref SR_PACKET_FORMAT */
#define PACKET_FORMAT_FIXED         (0)
/** Constant PACKET_FORMAT_VARIABLE for sub-register @ref SR_PACKET_FORMAT */
#define PACKET_FORMAT_VARIABLE      (1)
/** Access parameters for sub-register DC_FREE in register @ref RG_PACKET_CONFIG1 */
#define SR_DC_FREE                  0x37,   0x60,   5
/** Constant DC_FREE_NONE for sub-register @ref SR_DC_FREE */
#define DC_FREE_NONE                (0)
/** Constant DC_FREE_MANCHESTER for sub-register @ref SR_DC_FREE */
#define DC_FREE_MANCHESTER          (1)
/** Constant DC_FREE_WHITENING for sub-register @ref SR_DC_FREE */
#define DC_FREE_WHITENING           (2)
/** Access parameters for sub-register CRC_ON in register @ref RG_PACKET_CONFIG1 */
#define SR_CRC                      0x37,   0x10,   4
/** Constant CRC_OFF for sub-register @ref SR_CRC_ON */
#define CRC_OFF                     (0)
/** Constant CRC_ON for sub-register @ref SR_CRC_ON */
#define CRC_ON                      (1)
/** Access parameters for sub-register CRC_AUTO_CLEAR_OFF in register @ref RG_PACKET_CONFIG1 */
#define SR_CRC_AUTO_CLEAR           0x37,   0x08,   3
/** Constant CRC_AUTO_CLEAR_OFF_MODE1 for sub-register @ref SR_CRC_AUTO_CLEAR_OFF */
#define CRC_AUTO_CLEAR_ON           (0)
/** Constant CRC_AUTO_CLEAR_OFF_MODE2 for sub-register @ref SR_CRC_AUTO_CLEAR_OFF */
#define CRC_AUTO_CLEAR_OFF          (1)
/** Access parameters for sub-register ADDRESS_FILTERING in register @ref RG_PACKET_CONFIG1 */
#define SR_ADDRESS_FILTERING        0x37,   0x06,   1
/** Constant ADDRESS_FILTERING_OFF for sub-register @ref SR_ADDRESS_FILTERING */
#define ADDRESS_FILTERING_OFF       (0)
/** Constant ADDRESS_FILTERING_MODE1 for sub-register @ref SR_ADDRESS_FILTERING */
#define ADDRESS_FILTERING_MODE1     (1)
/** Constant ADDRESS_FILTERING_MODE2 for sub-register @ref SR_ADDRESS_FILTERING */
#define ADDRESS_FILTERING_MODE2     (2)

/** Offset for register PACKET_PAYLOAD_LENGTH */
#define RG_PACKET_PAYLOAD_LENGTH    (0x38)

/** Offset for register NODE_ADRS */
#define RG_NODE_ADRS                (0x39)

/** Offset for register BROADCAST_ADRS */
#define RG_BROADCAST_ADRS           (0x3A)

/** Offset for register AUTO_MODES */
#define RG_AUTO_MODES               (0x3B)
/** Access parameters for sub-register ENTER_CONDITION in register @ref RG_AUTO_MODES */
#define SR_ENTER_CONDITION          0x3B,   0xE0,   5
/** Constant ENTER_CONDITION_1 for sub-register @ref SR_ENTER_CONDITION */
#define ENTER_CONDITION_1           (0)
/** Constant ENTER_CONDITION_2 for sub-register @ref SR_ENTER_CONDITION */
#define ENTER_CONDITION_2           (1)
/** Constant ENTER_CONDITION_3 for sub-register @ref SR_ENTER_CONDITION */
#define ENTER_CONDITION_3           (2)
/** Constant ENTER_CONDITION_4 for sub-register @ref SR_ENTER_CONDITION */
#define ENTER_CONDITION_4           (3)
/** Constant ENTER_CONDITION_5 for sub-register @ref SR_ENTER_CONDITION */
#define ENTER_CONDITION_5           (4)
/** Constant ENTER_CONDITION_6 for sub-register @ref SR_ENTER_CONDITION */
#define ENTER_CONDITION_6           (5)
/** Constant ENTER_CONDITION_7 for sub-register @ref SR_ENTER_CONDITION */
#define ENTER_CONDITION_7           (6)
/** Constant ENTER_CONDITION_8 for sub-register @ref SR_ENTER_CONDITION */
#define ENTER_CONDITION_8           (7)
/** Access parameters for sub-register EXIT_CONDITION in register @ref RG_AUTO_MODES */
#define SR_EXIT_CONDITION           0x3B,   0x1C,   2
/** Constant EXIT_CONDITION_1 for sub-register @ref SR_EXIT_CONDITION */
#define EXIT_CONDITION_1            (0)
/** Constant EXIT_CONDITION_2 for sub-register @ref SR_EXIT_CONDITION */
#define EXIT_CONDITION_2            (1)
/** Constant EXIT_CONDITION_3 for sub-register @ref SR_EXIT_CONDITION */
#define EXIT_CONDITION_3            (2)
/** Constant EXIT_CONDITION_4 for sub-register @ref SR_EXIT_CONDITION */
#define EXIT_CONDITION_4            (3)
/** Constant EXIT_CONDITION_5 for sub-register @ref SR_EXIT_CONDITION */
#define EXIT_CONDITION_5            (4)
/** Constant EXIT_CONDITION_6 for sub-register @ref SR_EXIT_CONDITION */
#define EXIT_CONDITION_6            (5)
/** Constant EXIT_CONDITION_7 for sub-register @ref SR_EXIT_CONDITION */
#define EXIT_CONDITION_7            (6)
/** Constant EXIT_CONDITION_8 for sub-register @ref SR_EXIT_CONDITION */
#define EXIT_CONDITION_8            (7)
/** Access parameters for sub-register INTERMEDIATE_MODE in register @ref RG_AUTO_MODES */
#define SR_INTERMEDIATE_MODE        0x3B,   0x03,   0
/** Constant INTERMEDIATE_MODE_SLEEP for sub-register @ref SR_INTERMEDIATE_MODE */
#define INTERMEDIATE_MODE_SLEEP     (0)
/** Constant INTERMEDIATE_MODE_STDBY for sub-register @ref SR_INTERMEDIATE_MODE */
#define INTERMEDIATE_MODE_STDBY     (1)
/** Constant INTERMEDIATE_MODE_RX for sub-register @ref SR_INTERMEDIATE_MODE */
#define INTERMEDIATE_MODE_RX        (2)
/** Constant INTERMEDIATE_MODE_TX for sub-register @ref SR_INTERMEDIATE_MODE */
#define INTERMEDIATE_MODE_TX        (3)

/** Offset for register FIFO_THRESH */
#define RG_FIFO_THRESH              (0x3C)
/** Access parameters for sub-register TX_START_CONDITION in register @ref RG_FIFO_THRESH */
#define SR_TX_START_CONDITION       0x3C,   0x80,   7
/** Constant TX_START_CONDITION1 for sub-register @ref SR_TX_START_CONDITION */
#define TX_START_CONDITION1         (0)
/** Constant TX_START_CONDITION2 for sub-register @ref SR_TX_START_CONDITION */
#define TX_START_CONDITION2         (1)
/** Access parameters for sub-register FIFO_THRESHOLD in register @ref RG_FIFO_THRESH */
#define SR_FIFO_THRESHOLD           0x3C,   0x7F,   0

/** Offset for register PACKET_CONFIG2 */
#define RG_PACKET_CONFIG2           (0x3D)
/** Access parameters for sub-register INTER_PACKET_RX_DELAY in register @ref RG_PACKET_CONFIG2 */
#define SR_INTER_PACKET_RX_DELAY    0x3D,   0xF0,   4
/** Access parameters for sub-register RESTART_RX in register @ref RG_PACKET_CONFIG2 */
#define SR_RESTART_RX               0x3D,   0x04,   2
/** Access parameters for sub-register AUTO_RX_RESTART_ON in register @ref RG_PACKET_CONFIG2 */
#define SR_AUTO_RX_RESTART          0x3D,   0x02,   1
/** Constant AUTO_RX_RESTART_OFF for sub-register @ref SR_AUTO_RX_RESTART_ON */
#define AUTO_RX_RESTART_OFF         (0)
/** Constant AUTO_RX_RESTART_ON for sub-register @ref SR_AUTO_RX_RESTART_ON */
#define AUTO_RX_RESTART_ON          (1)
/** Access parameters for sub-register AES_ON in register @ref RG_PACKET_CONFIG2 */
#define SR_AES                      0x3D,   0x01,   0
/** Constant AES_OFF for sub-register @ref SR_AES_ON */
#define AES_OFF                     (0)
/** Constant AES_ON for sub-register @ref SR_AES_ON */
#define AES_ON                      (1)

/** Offset for register AES_KEY1 */
#define RG_AES_KEY1                 (0x3E)

/** Offset for register AES_KEY2 */
#define RG_AES_KEY2                 (0x3F)

/** Offset for register AES_KEY3 */
#define RG_AES_KEY3                 (0x40)

/** Offset for register AES_KEY4 */
#define RG_AES_KEY4                 (0x41)

/** Offset for register AES_KEY5 */
#define RG_AES_KEY5                 (0x42)

/** Offset for register AES_KEY6 */
#define RG_AES_KEY6                 (0x43)

/** Offset for register AES_KEY7 */
#define RG_AES_KEY7                 (0x44)

/** Offset for register AES_KEY8 */
#define RG_AES_KEY8                 (0x45)

/** Offset for register AES_KEY9 */
#define RG_AES_KEY9                 (0x46)

/** Offset for register AES_KEY10 */
#define RG_AES_KEY10                (0x47)

/** Offset for register AES_KEY11 */
#define RG_AES_KEY11                (0x48)

/** Offset for register AES_KEY12 */
#define RG_AES_KEY12                (0x49)

/** Offset for register AES_KEY13 */
#define RG_AES_KEY13                (0x4A)

/** Offset for register AES_KEY14 */
#define RG_AES_KEY14                (0x4B)

/** Offset for register AES_KEY15 */
#define RG_AES_KEY15                (0x4C)

/** Offset for register AES_KEY16 */
#define RG_AES_KEY16                (0x4D)

/** Offset for register TEMP1 */
#define RG_TEMP1                    (0x4E)
/** Access parameters for sub-register TEMP_MEAS_START in register @ref RG_TEMP1 */
#define SR_TEMP_MEAS_START          0x4E,   0x08,   3
/** Access parameters for sub-register TEMP_MEAS_RUNNING in register @ref RG_TEMP1 */
#define SR_TEMP_MEAS_RUNNING        0x4E,   0x04,   2

/** Offset for register TEMP2 */
#define RG_TEMP2                    (0x4F)
/** Access parameters for sub-register TEMP_VALUE in register @ref RG_TEMP2 */
#define SR_TEMP_VALUE               0x4F,   0xFF,   0

/** Offset for register TEST_LNA */
#define RG_TEST_LNA                 (0x58)
/** Constant TEST_LNA_NORMAL for sub-register @ref RG_TEST_LNA */
#define TEST_LNA_NORMAL             (0x1B)
/** Constant TEST_LNA_HIGH_SENSITIVITY for sub-register @ref RG_TEST_LNA */
#define TEST_LNA_HIGH_SENSITIVITY   (0x2D)

/** Offset for register TEST_PA1 */
#define RG_TEST_PA1                 (0x5A)
/** Constant TEST_PA1_NORMAL for sub-register @ref RG_TEST_PA1 */
#define TEST_PA1_NORMAL             (0x55)
/** Constant TEST_PA1_20DBM for sub-register @ref RG_TEST_PA1 */
#define TEST_PA1_20DBM              (0x5D)

/** Offset for register TEST_PA2 */
#define RG_TEST_PA2                 (0x5C)
/** Constant TEST_PA2_NORMAL for sub-register @ref RG_TEST_PA2 */
#define TEST_PA2_NORMAL             (0x70)
/** Constant TEST_PA2_20DBM for sub-register @ref RG_TEST_PA2 */
#define TEST_PA2_20DBM              (0x7C)

/** Offset for register TEST_DAGC */
#define RG_TEST_DAGC                (0x6F)
/** Constant TEST_DAGC_NORMAL for sub-register @ref RG_TEST_DAGC */
#define TEST_DAGC_NORMAL            (0x00)
/** Constant TEST_DAGC_IMPROVED1 for sub-register @ref RG_TEST_DAGC */
#define TEST_DAGC_LOWBETA0          (0x20)
/** Constant TEST_DAGC_IMPROVED2 for sub-register @ref RG_TEST_DAGC */
#define TEST_DAGC_LOWBETA1          (0x30)

/** Offset for register TEST_AFC */
#define RG_TEST_AFC                 (0x71)

#endif /* RFM69HW_REGISTERMAP_EXTERNAL_H */
