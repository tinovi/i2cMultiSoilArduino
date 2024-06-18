/*
 * vcs3i2c.cpp
 *
 */
#include "multi.h"
#include "mw_log_conf.h"
#include <stdio.h>
#include <math.h>
#include "sys_app.h"

int multi_resetDefault(i2c_handle_t *handle){
  return setReg(handle, REG_RES);
}

int multi_newAddress(i2c_handle_t *handle, uint8_t newAddr){
  if(setReg8(handle, REG_SET_I2C_ADDR, newAddr)){
	  return 1;
  }
  else{
    return 0;
  }
}

int multi_calibrationAir(i2c_handle_t *handle){
 	sentCmd(handle, REG_CALIBRATE_AIR);
 	HAL_Delay(100);
   return getState(handle);
}

int multi_calibrationWater(i2c_handle_t *handle){
	sentCmd(handle, REG_CALIBRATE_WATER);
	HAL_Delay(100);
	return getState(handle);
}


int multi_newReading(i2c_handle_t *handle){
  sentCmd(handle, REG_READ_START);
  HAL_Delay(50);
  return getState(handle);
}

float multi_getE25(i2c_handle_t *handle)
{
  return getVal(handle, REG_READ_E25)/100.0;
}


int multi_getCap(i2c_handle_t *handle, uint8_t * capArr)
{
	sentCmd(handle, REG_CAP);
	HAL_Delay(10);
	return HAL_I2C_Master_Receive(handle->i2c_handle, handle->device_address << 1u, capArr, 10, I2C_TIMEOUT);
}

int16_t multi_getRc(i2c_handle_t *handle)
{
  return getVal(handle, REG_RC);
}

uint32_t  multi_getRt(i2c_handle_t *handle){
	return getVal32(handle, REG_RT);
}

soil_ret_t multi_getData(i2c_handle_t *handle){
  sentCmd(handle, REG_GET_DATA);
  HAL_Delay(10);
  vals_t vals;
  soil_ret_t ret;
  if(HAL_I2C_Master_Receive(handle->i2c_handle, handle->device_address << 1u, (uint8_t *)&vals, sizeof(vals), I2C_TIMEOUT) == HAL_OK){
	  APP_LOG( TS_OFF, VLEVEL_M,  "multi read OK \r\n");
	  for(int a=0;a<ZONES;a++){
		  ret.dp[a] = vals.dp[a]/100.0;
		  ret.vwc[a] = (4.3e-6 * pow(ret.dp[a],3) - 5.5e-4*pow(ret.dp[a],2) + 2.92e-2*ret.dp[a] - 5.3e-2);
	  }
	  for(int a=0;a<TEMPS;a++){
		  ret.temp[a] = vals.temp[a]/100.0;
	  }
  }
  return ret;
}

int multi_getRaw(i2c_handle_t *handle, vals_t *vals){
  //sentCmd(handle, REG_GET_DATA);
 	uint8_t command_buffer[1] = {REG_GET_DATA};
 	HAL_StatusTypeDef def = HAL_I2C_Master_Transmit(handle->i2c_handle, handle->device_address << 1u, command_buffer, 1,
 			I2C_TIMEOUT);
 	if (def!= HAL_OK) {
 		APP_LOG(TS_OFF, VLEVEL_M,"i2c sentCmd err address: %i cmd %i err:%i\r\n", handle->device_address, REG_GET_DATA,def);
 		return false;
 	}else{
 		//APP_LOG(TS_OFF, VLEVEL_M,"i2c sentCmd OK address: %i cmd %i err:%i  size:%i\r\n", handle->device_address, REG_GET_DATA,def,sizeof(command_buffer));
 	}

  HAL_Delay(10);
  return HAL_I2C_Master_Receive(handle->i2c_handle, handle->device_address << 1u, (uint8_t *)vals, sizeof(vals_t), I2C_TIMEOUT);
}
