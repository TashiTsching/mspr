/**
 * @file   app_main.c
 * @author (c) Matthias Meier, 2021
 * @brief  Template for hands-on 'V2_Intro_FreeRTOS' of course mspr
 *
 */

#include <stdio.h>
#include "stm32f4xx.h"
#include "stm32f429i_discovery_lcd.h"
//#include "stm32f429i_discovery_ts.h"
//#include "lcd_log.h"
#include "stm32f429i_discovery_ts.h"
#include "lcd_log.h"
#include "FreeRTOS.h"
#include "task.h"
//#include "queue.h"
//#include "semphr.h"
#include "queue.h"
#include "semphr.h"
#include "app_main.h"

#define LD3_GREEN GPIO_PIN_13
#define LD4_RED GPIO_PIN_14
#define LD_GPIO_PORT GPIOG

#define WITH_TOUCH_TASK


//static void CounterTask(void *pvParameters);
//static void HeartbeatTask(void *pvParameters);
//static void WorkerTask(void *pvParameters);
static void TouchTask(void *pvParameters);

void app_main(void)
{
	BSP_LCD_Init();
	//xTaskCreate(CounterTask, "CtrTask", (configMINIMAL_STACK_SIZE + 80), NULL, (tskIDLE_PRIORITY + 1), NULL);
	//xTaskCreate(HeartbeatTask, "CtrTask", (configMINIMAL_STACK_SIZE + 80), NULL, (tskIDLE_PRIORITY + 1), NULL);
	//xTaskCreate(WorkerTask, "CtrTask", (configMINIMAL_STACK_SIZE + 80), NULL, (tskIDLE_PRIORITY + 1), NULL);
	xTaskCreate(TouchTask, "CtrTask", (configMINIMAL_STACK_SIZE + 80), NULL, (tskIDLE_PRIORITY + 1), NULL);
	vTaskStartScheduler();
	/* The FreeRTOS scheduler should never return to here, except on out of memory at creating the idle task! */
	for (;;) ;
}

#ifdef WITH_Counter_TASK
static void CounterTask(__attribute__ ((unused)) void *pvParameters)
{
	int n=0;
	BSP_LCD_SetTextColor(LCD_COLOR_RED);

	while (1) {
		char text[20];
		HAL_GPIO_TogglePin(LD_GPIO_PORT, LD3_GREEN);
		vTaskDelay(500);
		snprintf(text, sizeof(text), "Counter = %d", n++);
		BSP_LCD_DisplayStringAt(0,BSP_LCD_GetYSize() / 2, text, CENTER_MODE);
	}
}
#endif

#ifdef WITH_HEARTBEAT_TASK
static void HeartbeatTask(__attribute__ ((unused)) void *pvParameters)
{

	while (1) {
		HAL_GPIO_TogglePin(LD_GPIO_PORT, LD4_RED);
		vTaskDelay(100);
		HAL_GPIO_TogglePin(LD_GPIO_PORT, LD4_RED);
		vTaskDelay(100);
	}
}

#endif

#ifdef WITH_WORKER_TASK
static void WorkerTask(__attribute__ ((unused)) void *pvParameters)
{
	BSP_LCD_SetTextColor(LCD_COLOR_RED);

	while (1) {
		char text[30];
		snprintf(text, sizeof(text), "Hello from Worker Task");
		BSP_LCD_DisplayStringAt(0,0, text, LEFT_MODE);
	}
}
#endif



#ifdef WITH_TOUCH_TASK
static void TouchTask(__attribute__ ((unused)) void *pvParameters)
{
	while (BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize())) {
		BSP_LCD_DisplayStringAt(0, 0, "Error init. TS!!", CENTER_MODE);
		vTaskDelay(500);
	}
	while (1) {
		TS_StateTypeDef  ts;
		BSP_TS_GetState(&ts);
		if (ts.TouchDetected) {
			char s[20];
			sprintf(s, "  (%d,%d)  ", ts.X, ts.X);
			BSP_LCD_DisplayStringAt(0, 0, s, CENTER_MODE);
			HAL_GPIO_WritePin(LD_GPIO_PORT, LD4_RED,1);
		}
		else {
			BSP_LCD_DisplayStringAt(0, 0, "      touch me!     ", CENTER_MODE);
			HAL_GPIO_WritePin(LD_GPIO_PORT, LD4_RED,0);
		}
		vTaskDelay(100);
	}
}
#endif

