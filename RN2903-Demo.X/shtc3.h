
#define SHTC3_ADDR          0x70

#define SHTC3_SLEEP         0xB098
#define SHTC3_WAKEUP        0x3517

#define SHTC3_SWRESET       0x805D     
#define SHTC3_IDREG         0xEFC8

#define SHTC3_READ_T_FIRST  0x7866
#define SHTC3_READ_RH_FIRST 0x58E0

uint8_t shtc3_wakeup(void);
uint8_t shtc3_readid(void);
uint8_t shtc3_GetTempAndHumidity(uint16_t * temperature, uint16_t * humidity);
uint8_t shtc3_sleep(void);

float shtc3_convert_humd(uint16_t raw_humd);
float shtc3_convert_temp(uint16_t raw_temp);



