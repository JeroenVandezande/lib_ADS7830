#include "ADS7830.h"
#include <math.h>

#define ADS7830_BaseAddress 144

int ADS7830_Init(struct ADS7830_t* instance, bool A0, bool A1, enum ADS7830_PowerDown_t powerMode)
{
	int resultCode = 0;
	instance->I2CAddress = ADS7830_BaseAddress | (A0?2:0) | (A1?4:0);
	uint8_t configData = powerMode << 2;
	instance->i2cWriteDataMethod(instance->I2CAddress, &configData, 1);
	instance->_conf = configData;
	instance->ReferenceVoltage = 2.5;
	return resultCode;
}

uint8_t ADS7830_ReadChannel(struct ADS7830_t* instance, enum ADS7830_Channel_t channel)
{
	uint8_t configData = instance->_conf;
	configData |= (channel << 4);
	instance->i2cWriteDataMethod(instance->I2CAddress, &configData, 1);
	uint8_t returnData;
	instance->i2cReadDataMethod(instance->I2CAddress, &returnData, 1);
	float multiplier = instance->ReferenceVoltage / 255;
	return (uint8_t) round(returnData * multiplier);
}