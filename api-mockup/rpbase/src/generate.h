/**
 * $Id: $
 *
 * @brief Red Pitaya library Generate module interface
 *
 * @Author Red Pitaya
 *
 * (c) Red Pitaya  http://www.redpitaya.com
 *
 * This part of code is written in C programming language.
 * Please visit http://en.wikipedia.org/wiki/C_(programming_language)
 * for more details on the language used herein.
 */
#ifndef __GENERATE_H
#define __GENERATE_H

#define LEVEL_MAX	   1.0	   // V
#define AMPLITUDE_MAX  1.0     // V
#define ARBITRARY_MIN -1.0	   // V
#define ARBITRARY_MAX  1.0     // V
#define OFFSET_MAX     2.0     // V
#define FREQUENCY_MIN  0	   // Hz
#define FREQUENCY_MAX  62.5e6  // Hz
#define PHASE_MIN	  -360       // deg
#define PHASE_MAX	   360     // deg
#define DUTY_CYCLE_MIN 0       // %
#define DUTY_CYCLE_MAX 100     // %
#define DAC_FREQUENCY 125e6    // Hz

#define BUFFER_LENGTH (16 * 1024)
#define CHA_DATA_OFFSET 0x10000
#define CHB_DATA_OFFSET 0x20000
#define DATA_BIT_LENGTH 14

#define CHECK_OUTPUT(X, Y) { \
if (channel == RP_CH_1) { \
	X; \
} \
else if (channel == RP_CH_2) { \
	Y; \
} \
else { \
	return RP_EPN; \
} \
}

int generate_Init();
int generate_Release();

int generate_setOutputDisable(rp_channel_t out, bool disable);
int generate_setAmplitude(rp_channel_t out, float amplitude);
int generate_setDCOffset(rp_channel_t out, float offset);
int generate_setFrequency(rp_channel_t out, float frequency);
int generate_setWrapCounter(rp_channel_t channel, uint32_t size);
int generate_setTriggerSource(rp_channel_t out, unsigned short value);
int generate_GenTrigger(rp_channel_t out);
int generate_setOneTimeTrigger(rp_channel_t out, uint32_t value);
int generate_Synchronise();

int generate_writeData(rp_channel_t out, float *data, uint32_t start, uint32_t length);

#endif //__GENERATE_H