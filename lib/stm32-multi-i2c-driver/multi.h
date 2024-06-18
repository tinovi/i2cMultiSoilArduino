/*
 * vcs3i2c.h
 *
 */

#ifndef MULTI_H_
#define MULTI_H_

#include "main.h"
#include "i2c.h"

#define ZONES 5
#define TEMPS 2

  typedef struct{
	  int16_t temp[TEMPS];
	  int16_t dp[ZONES];
  } vals_t;

  typedef struct{
	  uint8_t ver;
	  int16_t temp[TEMPS+1];
	  int16_t dp[ZONES+1];
  } vals_out_t;


  typedef struct{
	  float temp[TEMPS+1];
	  float dp[ZONES+1];
	  float vwc[ZONES+1];
  } soil_ret_t;


#define  REG_READ_START    0x01
#define  REG_GET_DATA      0x09

#define  REG_READ_E25     0x02
#define  REG_READ_EC      0x03
#define  REG_READ_TEMP    0x04
#define  REG_READ_VWC     0x05


#define  REG_CAP     0x0A
#define  REG_RES     0x0B
#define  REG_RC     0x0C
#define  REG_RT     0x0D

#define  REG_CALIBRATE_AIR    0x06
#define  REG_CALIBRATE_WATER  0x07
#define  REG_CALIBRATE_EC  0x10

#define  REG_RES     0x0B

#define REG_SET_I2C_ADDR    0x08


  int multi_resetDefault(i2c_handle_t *handle);
  int multi_calibrationAir(i2c_handle_t *handle);
  int multi_calibrationWater(i2c_handle_t *handle);
  int multi_newReading(i2c_handle_t *handle);
  float multi_getE25(i2c_handle_t *handle);
  soil_ret_t multi_getData(i2c_handle_t *handle);
  int multi_getRaw(i2c_handle_t *handle, vals_t *vals);
  int multi_getCap(i2c_handle_t *handle, uint8_t * capArr);
  int multi_newAddress(i2c_handle_t *handle, uint8_t newAddr);

#endif /* MULTI_H_ */

