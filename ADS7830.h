#ifndef LIB_ADS7830_LIBRARY_H
#define LIB_ADS7830_LIBRARY_H

#include <stdint.h>
#include <stdbool.h>
#include "LL_i2c.h"

enum ADS7830_PowerDown_t
{
	ADS7830_PowerDown_PDBetweenConversions = 0,
	ADS7830_PowerDown_IntRefOffADCOn = 1,
	ADS7830_PowerDown_IntRefOnADCOff = 2,
	ADS7830_PowerDown_IntRefOnADCOn = 3,
};

enum ADS7830_Channel_t
{
	ADS7830_SingleEnded_Channel0 = 8,
	ADS7830_SingleEnded_Channel1 = 12,
	ADS7830_SingleEnded_Channel2 = 9,
	ADS7830_SingleEnded_Channel3 = 13,
	ADS7830_SingleEnded_Channel4 = 10,
	ADS7830_SingleEnded_Channel5 = 14,
	ADS7830_SingleEnded_Channel6 = 11,
	ADS7830_Differential_Channel01 = 0,
	ADS7830_Differential_Channel23 = 1,
	ADS7830_Differential_Channel45 = 2,
	ADS7830_Differential_Channel67 = 3,
	ADS7830_Differential_Channel10 = 4,
	ADS7830_Differential_Channel32 = 5,
	ADS7830_Differential_Channel54 = 6,
	ADS7830_Differential_Channel76 = 7,
};

struct ADS7830_t
{
	//PRIVATE INSTANCE MEMBERS
	uint8_t _conf;
	//PUBLIC INSTANCE MEMBERS
	uint8_t I2CAddress;
	float ReferenceVoltage;
	//points to a function to handle the I2C writes
	LL_I2CMaster_WriteMethod_t i2cWriteDataMethod;
	//points to a function to handle the I2C reads
	LL_I2CMaster_ReadMethod_t i2cReadDataMethod;
};

int ADS7830_Init(struct ADS7830_t* instance, bool A0, bool A1, enum ADS7830_PowerDown_t powerMode);
float ADS7830_ReadChannel(struct ADS7830_t* instance, enum ADS7830_Channel_t channel);


#endif //LIB_ADS7830_LIBRARY_H
