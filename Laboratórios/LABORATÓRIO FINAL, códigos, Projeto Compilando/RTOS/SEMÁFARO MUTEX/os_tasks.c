/* ###################################################################
 **     Filename    : os_tasks.c
 **     Project     : Projeto
 **     Processor   : MKL25Z128VLK4
 **     Component   : Events
 **     Version     : Driver 01.00
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2018-04-25, 20:31, # CodeGen: 3
 **     Abstract    :
 **         This is user's event module.
 **         Put your event handler code here.
 **     Settings    :
 **     Contents    :
 **         Task1_task - void Task1_task(os_task_param_t task_init_data);
 **
 ** ###################################################################*/
/*!
 ** @file os_tasks.c
 ** @version 01.00
 ** @brief
 **         This is user's event module.
 **         Put your event handler code here.
 */
/*!
 **  @addtogroup os_tasks_module os_tasks module documentation
 **  @{
 */
/* MODULE os_tasks */

#include "Cpu.h"
#include "Events.h"
#include "os_tasks.h"
#include "ledrgb_hal.h"

#ifdef __cplusplus
extern "C" {
#endif 

/* User includes (#include below this line is not maintained by Processor Expert) */

/*
 ** ===================================================================
 **     Event       :  Task1_task (module os_tasks)
 **
 **     Component   :  Task1 [OS_Task]
 */
/*!
 **     @brief
 **         RTOS task routine. The routine is generated into os_tasks.c
 **         file.
 **     @param
 **         task_init_data  - Parameter to be passed to the
 **         task when it is created.
 */
/* ===================================================================*/
void Task1_task(os_task_param_t task_init_data) {
	/* Write your local variable definition here */

	osa_status_t status; // estado do sem�faro
	int estado = 1; // m�quina de estado

#ifdef PEX_USE_RTOS
	while (1) {
#endif
		/* Write your code here ... */
		// identar o c�digo => control + shift + f

		switch (estado) {
		case 1:
			status = OSA_MutexLock(&mutex, OSA_WAIT_FOREVER);
			boolean unlock = false;

			switch (status) {
			case kStatus_OSA_Success: // Acende Verde 1.5s
				ledrgb_clearRedLed();
				ledrgb_clearGreenLed();
				ledrgb_clearBlueLed();
				ledrgb_setGreenLed();
				OSA_TimeDelay(5000);
				unlock = true;
				break;
			case kStatus_OSA_Error: // Acende Vermelho 1.5s
				ledrgb_clearBlueLed();
				ledrgb_clearRedLed();
				ledrgb_clearGreenLed();
				ledrgb_setRedLed();
				OSA_TimeDelay(5000);
				break;
			case kStatus_OSA_Timeout: // Acende Todos 1.5s
				ledrgb_setRedLed();
				ledrgb_setGreenLed();
				ledrgb_setBlueLed();
				OSA_TimeDelay(5000);
				break;
			}

			estado = 2;
			if(unlock == true)
				OSA_MutexUnlock(&mutex);
			break;
		case 2:
			status = OSA_MutexLock(&mutex, OSA_WAIT_FOREVER);

			switch (status) {
			case kStatus_OSA_Success: // Pisca Verde 50x
				for (int i = 0; i < 50; i++) {
					ledrgb_clearRedLed();
					ledrgb_clearGreenLed();
					ledrgb_clearBlueLed();
					ledrgb_setGreenLed();
					OSA_TimeDelay(50);
					ledrgb_clearRedLed();
					ledrgb_clearGreenLed();
					ledrgb_clearBlueLed();
					OSA_TimeDelay(50);
				}
				break;
			case kStatus_OSA_Error: // Pisca Vermelho 50x
				for (int i = 0; i < 50; i++) {
					ledrgb_clearRedLed();
					ledrgb_clearGreenLed();
					ledrgb_clearBlueLed();
					ledrgb_setRedLed();
					OSA_TimeDelay(50);
					ledrgb_clearRedLed();
					ledrgb_clearGreenLed();
					ledrgb_clearBlueLed();
					OSA_TimeDelay(50);
				}
				break;
			case kStatus_OSA_Timeout: // pisca Todos 50x
				for (int i = 0; i < 50; i++) {
					ledrgb_setGreenLed();
					ledrgb_setRedLed();
					ledrgb_setBlueLed();
					OSA_TimeDelay(50);
					ledrgb_clearRedLed();
					ledrgb_clearGreenLed();
					ledrgb_clearBlueLed();
					OSA_TimeDelay(50);
				}
				break;
			}

			estado = 1;
			OSA_MutexUnlock(&mutex);
			break;
		}

		OSA_TimeDelay(10);

#ifdef PEX_USE_RTOS   
	}
#endif    
}

/*
 ** ===================================================================
 **     Event       :  Task2_task (module os_tasks)
 **
 **     Component   :  Task2 [OS_Task]
 */
/*!
 **     @brief
 **         RTOS task routine. The routine is generated into os_tasks.c
 **         file.
 **     @param
 **         task_init_data  - Parameter to be passed to the
 **         task when it is created.
 */
/* ===================================================================*/
void Task2_task(os_task_param_t task_init_data) {
	/* Write your local variable definition here */

	osa_status_t status; // estado do sem�faro
	int estado = 1;
	int contTask2 = 0;

#ifdef PEX_USE_RTOS
	while (1) {
#endif
		/* Write your code here ... */

		if (contTask2 == 0)
			status = OSA_MutexLock(&mutex, OSA_WAIT_FOREVER);

		if (contTask2 > 10)
			status = OSA_MutexLock(&mutex, 20);

		switch (estado) {
		case 1:
			switch (status) {
			case kStatus_OSA_Success: // Acende Azul 1.5s
				ledrgb_clearRedLed();
				ledrgb_clearGreenLed();
				ledrgb_clearBlueLed();
				ledrgb_setBlueLed();
				OSA_TimeDelay(5000);
				break;
			case kStatus_OSA_Error: // Acende Amarelo 1.5s
				ledrgb_clearGreenLed();
				ledrgb_clearRedLed();
				ledrgb_clearBlueLed();
				ledrgb_setRedLed();
				ledrgb_setGreenLed();
				OSA_TimeDelay(5000);
				break;
			case kStatus_OSA_Timeout: // Acende Rosa
				ledrgb_clearGreenLed();
				ledrgb_setRedLed();
				ledrgb_setBlueLed();
				OSA_TimeDelay(5000);
				break;
			}

			estado = 2;
			break;

		case 2:
			switch (status) {
			case kStatus_OSA_Success: // Pisca Azul 50x
				for (int i = 0; i < 50; i++) {
					ledrgb_clearRedLed();
					ledrgb_clearGreenLed();
					ledrgb_clearBlueLed();
					ledrgb_setBlueLed();
					OSA_TimeDelay(50);
					ledrgb_clearRedLed();
					ledrgb_clearGreenLed();
					ledrgb_clearBlueLed();
					OSA_TimeDelay(50);
				}
				break;
			case kStatus_OSA_Error: // Pisca Amarelo 50x
				for (int i = 0; i < 50; i++) {
					ledrgb_setGreenLed();
					ledrgb_setRedLed();
					ledrgb_clearBlueLed();
					OSA_TimeDelay(50);
					ledrgb_clearRedLed();
					ledrgb_clearGreenLed();
					ledrgb_clearBlueLed();
					OSA_TimeDelay(50);
				}
				break;
			case kStatus_OSA_Timeout: // Pisca Rosa 50x
				for (int i = 0; i < 50; i++) {
					ledrgb_clearGreenLed();
					ledrgb_setRedLed();
					ledrgb_setBlueLed();
					OSA_TimeDelay(50);
					ledrgb_clearRedLed();
					ledrgb_clearGreenLed();
					ledrgb_clearBlueLed();
					OSA_TimeDelay(50);
				}
				break;
			}

			estado = 1;
			break;
		}

		contTask2++;

		if (contTask2 == 10)
			OSA_MutexUnlock(&mutex);

		if (contTask2 > 10) {
			OSA_MutexUnlock(&mutex);
			contTask2 = 20;
		}

		OSA_TimeDelay(10);

#ifdef PEX_USE_RTOS   
	}
#endif    
}

/* END os_tasks */

#ifdef __cplusplus
} /* extern "C" */
#endif 

/*!
 ** @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Processor Expert 10.5 [05.21]
 **     for the Freescale Kinetis series of microcontrollers.
 **
 ** ###################################################################
 */
