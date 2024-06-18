/*
 * i2c.h
 *
 *  Created on: Jun 26, 2022
 *      Author: edgar
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_

#include "main.h"
#include <stdbool.h>

#define I2C_TIMEOUT 50

extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;
extern I2C_HandleTypeDef hi2c3;


/** __LL_ADC_CALC_DATA_TO_VOLTAGE
 * Structure defining a handle describing a SHT3x device.
 */
typedef struct {

	/**
	 * The handle to the I2C bus for the device.
	 */
	I2C_HandleTypeDef *i2c_handle;

	/**
	 * The I2C device address.
	 * @see{PCA9865_I2C_DEVICE_ADDRESS_ADDR_PIN_LOW} and @see{SHT3X_I2C_DEVICE_ADDRESS_ADDR_PIN_HIGH}
	 */
	uint16_t device_address;

} i2c_handle_t;

void i2c_init(uint8_t inst);
void i2c_deinit();
void i2c_de(uint8_t inst);
void powOn();
void powOff();
void i2c_in();

 void MX_I2C1_Init(void);
 void MX_I2C2_Init(void);
 void MX_I2C3_Init(void);

 int getState(i2c_handle_t *handle);
 int16_t getVal(i2c_handle_t *handle, uint8_t reg);
 uint32_t getVal32(i2c_handle_t *handle, uint8_t reg);
 int setReg8(i2c_handle_t *handle, uint8_t reg, uint8_t val);
 int setReg(i2c_handle_t *handle, uint8_t reg);
 bool sentCmd(i2c_handle_t *handle, uint8_t cmd);

#endif /* INC_I2C_H_ */
