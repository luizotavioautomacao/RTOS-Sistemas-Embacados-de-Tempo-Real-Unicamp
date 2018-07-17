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
	osa_status_t status; // estado do semáfaro
	int estado = 1; // máquina de estado

#ifdef PEX_USE_RTOS
	while (1) {
#endif
		/* Write your code here ... */

		//status = OSA_SemaWait(&Semaphore, 100);
		status = OSA_SemaWait(&semafaro, OSA_WAIT_FOREVER);
		switch (status) {
		case kStatus_OSA_Success: // AZUL
			ledrgb_clearGreenLed();
			ledrgb_clearRedLed();
			ledrgb_clearBlueLed();
			ledrgb_setBlueLed();
			OSA_TimeDelay(2500);
			break;
		case kStatus_OSA_Error: // VERMELHO
			ledrgb_clearGreenLed();
			ledrgb_clearRedLed();
			ledrgb_clearBlueLed();
			ledrgb_setRedLed();
			OSA_TimeDelay(2500);
			break;
		case kStatus_OSA_Timeout: // AZUE E VERMELHO
			ledrgb_clearGreenLed();
			ledrgb_clearRedLed();
			ledrgb_clearBlueLed();
			ledrgb_setBlueLed();
			ledrgb_setRedLed();
			OSA_TimeDelay(2500);
			break;
		}

		OSA_TimeDelay(10); /* Example code (for task release) */

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

	osa_status_t status; // estado do semáfaro

#ifdef PEX_USE_RTOS
	while (1) {
#endif
		/* Write your code here ... */

		switch (status) {
		case kStatus_OSA_Success: // VERDE
			ledrgb_clearGreenLed();
			ledrgb_clearRedLed();
			ledrgb_clearBlueLed();
			ledrgb_setGreenLed();
			OSA_TimeDelay(500);
			break;
		case kStatus_OSA_Error: // VERMELHO
			ledrgb_clearGreenLed();
			ledrgb_clearRedLed();
			ledrgb_clearBlueLed();
			ledrgb_setRedLed();
			OSA_TimeDelay(500);
			break;
		case kStatus_OSA_Timeout: // PISCA AZUL
			for (int i = 0; i < 5; i++) {
				ledrgb_clearGreenLed();
				ledrgb_clearRedLed();
				ledrgb_clearBlueLed();
				ledrgb_setRedLed();
				OSA_TimeDelay(100);
			}
			break;
		}

		status = OSA_SemaPost(&semafaro); //libera o semafaro (aumenta o contador)
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
