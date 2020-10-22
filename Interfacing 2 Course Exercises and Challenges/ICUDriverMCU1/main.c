#include "lcd.h"
#include "icu.h"

uint8 flag = 0;
uint16 t1 = 0;
uint16 t2 = 0;
uint16 t3 = 0;

void getReading(void) {

	if (flag == 0 || flag == 4) {
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(ICU_FALL);
		flag = 1;
	} else if (flag == 1) {
		t1 = ICU_getInputCaptureValue();
		ICU_setEdgeDetectionType(ICU_RISE);
		flag = 2;
	} else if (flag == 2) {
		t2 = ICU_getInputCaptureValue();
		ICU_setEdgeDetectionType(ICU_FALL);
		flag = 3;
	} else if (flag == 3) {
		t3 = ICU_getInputCaptureValue();
		ICU_setEdgeDetectionType(ICU_RISE);

		flag = 4;
	}
}

int main() {
	uint32 dutyCycle = 0;
	ICUConfig icu = { ICU_RISE, ICU_CPU_1 };

	SREG |= (1 << 7);

	ICU_setCallBack(getReading);

	LCD_init();
	ICU_init(&icu);

	while (1) {
		if (flag == 4) {
			LCD_clearScreen();
			dutyCycle = ((float) (t3 - t2) / (t3 - t1)) * 100;
			LCD_displayInteger(dutyCycle);

			_delay_ms(500);
		}
	}
}
