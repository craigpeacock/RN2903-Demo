
#include "mcc_generated_files/i2c1.h"
#include <stdint.h>
#include <stdio.h>
#include "shtc3.h"

#define CRC_POLYNOMIAL          0x131 // P(x) = x^8 + x^5 + x^4 + 1 = 100110001
#define SHTC3_NO_ERROR          0
#define SHTC3_CHECKSUM_ERROR    -1

static uint8_t shtc3_checkcrc(uint8_t data[], uint8_t nbrOfBytes, uint8_t checksum){
  uint8_t bitmask;      // bit mask
  uint8_t crc = 0xFF;   // calculated checksum
  uint8_t byteCtr;      // byte counter
 
  // calculates 8-Bit checksum with given polynomial
  for(byteCtr = 0; byteCtr < nbrOfBytes; byteCtr++) {
    crc ^= (data[byteCtr]);
    for(bitmask = 8; bitmask > 0; --bitmask) {
      if(crc & 0x80) {
        crc = (crc << 1) ^ CRC_POLYNOMIAL;
      } else {
        crc = (crc << 1);
      }
    }
  }

  // verify checksum
  if(crc != checksum) {
    return SHTC3_CHECKSUM_ERROR;
  } else {
    return SHTC3_NO_ERROR;
  }
}

struct VALUES {
    uint16_t    temperature;
    uint8_t     temperature_crc;
    uint16_t    humidity;
    uint8_t     humidity_crc;
};

union DATA {
    struct VALUES meas;
    uint8_t buffer[6];
};

uint8_t shtc3_GetTempAndHumidity(uint16_t * temperature, uint16_t * humidity)
{
    I2C1_MESSAGE_STATUS status;
    uint8_t temp;
    uint8_t error; 
    
    union DATA data;
    
    uint8_t buffer[2];
    buffer[0] = (SHTC3_READ_T_FIRST >> 8);
    buffer[1] = (SHTC3_READ_T_FIRST & 0xFF);  
    
    I2C1_MasterWrite(buffer, 2, SHTC3_ADDR, &status);
    while(status == I2C1_MESSAGE_PENDING);
    if (status != I2C1_MESSAGE_COMPLETE) {
        printf("shtc3_GetTempAndHumdity() Read Err %d\r\n", status);
    }
    
    do {
        I2C1_MasterRead(&data.buffer, 6, SHTC3_ADDR, &status);
        while(status == I2C1_MESSAGE_PENDING);
        //printf("Status %d\r\n",status);
    } while (status != I2C1_MESSAGE_COMPLETE);
        
    if (status != I2C1_MESSAGE_COMPLETE) {
        printf("shtc3_GetTempAndHumdity() Read Err %d\r\n", status);
    }

    error = shtc3_checkcrc((uint8_t *)&data.meas.temperature, 2, data.meas.temperature_crc);
    if (error != SHTC3_NO_ERROR) {
        printf("Checksum Err\r\n");
    } else {
        // byteswap Temperature
        temp = data.buffer[1];
        data.buffer[1] = data.buffer[0];
        data.buffer[0] = temp;
        *temperature = data.meas.temperature;
        //printf("Raw Temp = %d\r\n", data.meas.temperature);
    }
    
    error = shtc3_checkcrc((uint8_t *)&data.meas.humidity, 2, data.meas.humidity_crc);
    if (error != SHTC3_NO_ERROR) {
        printf("Checksum Err\r\n");
    } else {
        // byteswap Humidity
        temp = data.buffer[4];
        data.buffer[4] = data.buffer[3];
        data.buffer[3] = temp;
        *humidity = data.meas.humidity;
        //printf("Raw Humd = %d\r\n", data.meas.humidity);
    }
}

float shtc3_convert_humd(uint16_t raw_humd)
{
    float humidity = 100.0 * ((float)raw_humd / 65536);
    //printf("RH %.01f%%\r\n", RH);
    return(humidity);
}

float shtc3_convert_temp(uint16_t raw_temp)
{
    float temperature = 175.0 * ((float)raw_temp / 65536.0) - 45.0;
    //printf("Temp %.02f degC\r\n", temperature);
    return (temperature);
}

uint8_t shtc3_wakeup(void)
{
    I2C1_MESSAGE_STATUS status;
    
    uint8_t buffer[2];
    buffer[0] = (SHTC3_WAKEUP >> 8);
    buffer[1] = (SHTC3_WAKEUP & 0xFF);      
    
    I2C1_MasterWrite(buffer, 2, SHTC3_ADDR, &status);
    while(status == I2C1_MESSAGE_PENDING);
    if (status != I2C1_MESSAGE_COMPLETE) {
        printf("shtc3_wakeup() Write Err %d\r\n", status);
    }
}

uint8_t shtc3_sleep(void)
{
    I2C1_MESSAGE_STATUS status;
    
    uint8_t buffer[2];
    buffer[0] = (SHTC3_SLEEP >> 8);
    buffer[1] = (SHTC3_SLEEP & 0xFF);      
    
    I2C1_MasterWrite(buffer, 2, SHTC3_ADDR, &status);
    while(status == I2C1_MESSAGE_PENDING);
    if (status != I2C1_MESSAGE_COMPLETE) {
        printf("shtc3_wakeup() Write Err %d\r\n", status);
    } 
}

uint8_t shtc3_readid(void)
{
    I2C1_MESSAGE_STATUS status;

    uint8_t buffer[2];
    buffer[0] = (SHTC3_IDREG >> 8);
    buffer[1] = (SHTC3_IDREG & 0xFF);            
    
    I2C1_MasterWrite(buffer, 2, SHTC3_ADDR, &status);
    while(status == I2C1_MESSAGE_PENDING);
    if (status != I2C1_MESSAGE_COMPLETE) {
        printf("shtc3_readid() Write Err %d\r\n", status);
    }

    I2C1_MasterRead(buffer, 2, SHTC3_ADDR, &status);
    while(status == I2C1_MESSAGE_PENDING);
    if (status != I2C1_MESSAGE_COMPLETE) {
        printf("shtc3_readid() Read Err %d\r\n", status);
    }
    
    printf("ID Reg = 0x%02X%02X\r\n", buffer[0], buffer[1]);
}
