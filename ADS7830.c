#include "ADS7830.h"

#define ADS7830_BaseAddress 144

int ADS7830_Init(struct ADS7830_t* instance, bool A0, bool A1, enum ADS7830_PowerDown_t powerMode)
{
	int resultCode = 0;
	instance->I2CAddress = ADS7830_BaseAddress | (A0?2:0) | (A1?4:0);
	uint8_t configData = powerMode << 2;
	instance->i2cWriteDataMethod(instance->I2CAddress, &configData, 1);
	instance->_conf = configData;
	return resultCode;
}

uint8_t ADS7830_ReadChannel(struct ADS7830_t* instance, enum ADS7830_Channel_t channel)
{

}