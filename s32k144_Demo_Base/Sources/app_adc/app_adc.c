#include "app_adc.h"

static uint16_t ad_ch2 = 0;
static uint16_t ad_ch3 = 0;


void bsp_ADC_init(void)
{
	ADC_DRV_Reset(INST_ADCONV1);
	//ADC_DRV_InitConverterStruct(&adConv1_ConvConfig0);
	ADC_DRV_ConfigConverter(INST_ADCONV1, &adConv1_ConvConfig0);
	//ADC_DRV_InitChanStruct(&adConv1_ChnConfig0);
	//ADC_DRV_InitChanStruct(&adConv1_ChnConfig1);
    ADC_DRV_AutoCalibration(INST_ADCONV1);
}


void bsp_get_ADC_val(void)
{ 
    ADC_DRV_WaitConvDone(INST_ADCONV1);
    ADC_DRV_ConfigChan(INST_ADCONV1,0,&adConv1_ChnConfig0);
    ADC_DRV_GetChanResult(INST_ADCONV1,0,&ad_ch2);

    ADC_DRV_WaitConvDone(INST_ADCONV1);
    ADC_DRV_ConfigChan(INST_ADCONV1,0,&adConv1_ChnConfig1);
    ADC_DRV_GetChanResult(INST_ADCONV1,0,&ad_ch3);
    #if 0
    if (ADC_DRV_GetConvCompleteFlag(INST_ADCONV1,ADC_INPUTCHAN_EXT2))
    {

    }
    #endif
}


