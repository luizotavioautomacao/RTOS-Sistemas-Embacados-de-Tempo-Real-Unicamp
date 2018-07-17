/* ###################################################################
 **     Filename    : os_tasks.c
 **     Project     : Projeto
 **     Processor   : MKL15Z128VLK4
 **     Component   : Events
 **     Version     : Driver 01.00
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2018-04-15, 20:31, # CodeGen: 3
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
	int estado = 1;
	osa_status_t status; // estado do sem�faro
	osa_status_t statusMutex; // estado do Mutex
//	int contTask1 = 0;

#ifdef PEX_USE_RTOS
	while (1) {
#endif
		/* Write your code here ... */

		status = OSA_SemaWait(&semafaro, OSA_WAIT_FOREVER); // pega
//		contTask1++;

		switch (status) {
		case kStatus_OSA_Success:
			break;
		case kStatus_OSA_Timeout:
			estado = 3;
			break;
		case kStatus_OSA_Error:
			estado = 4;
			break;
		}

		switch (estado) {

		case 1: // acende VERDE 5s
			statusMutex = OSA_MutexLock(&mutex, OSA_WAIT_FOREVER);
			status = OSA_SemaWait(&semafaro, OSA_WAIT_FOREVER); // pega
			ledrgb_clearGreenLed();
			ledrgb_clearBlueLed();
			ledrgb_clearRedLed();
			ledrgb_setGreenLed();
			OSA_TimeDelay(1500);
			estado = 2;
			statusMutex = OSA_MutexUnlock(&mutex);
			break;

		case 2: // pisca Azul 5s
			statusMutex = OSA_MutexLock(&mutex, OSA_WAIT_FOREVER);
			status = OSA_SemaWait(&semafaro, OSA_WAIT_FOREVER); // pega
			ledrgb_clearGreenLed();
			ledrgb_clearBlueLed();
			ledrgb_clearRedLed();
			ledrgb_setBlueLed();
			OSA_TimeDelay(1500);
			estado = 1;
			statusMutex = OSA_MutexUnlock(&mutex);
			break;

		case 3: // acende todos 5s
			statusMutex = OSA_MutexLock(&mutex, OSA_WAIT_FOREVER);
			ledrgb_setGreenLed();
			ledrgb_setBlueLed();
			ledrgb_setRedLed();
			OSA_TimeDelay(1500);
			statusMutex = OSA_MutexUnlock(&mutex);
			break;

		default: // acende VERMELHO 5s
			statusMutex = OSA_MutexLock(&mutex, OSA_WAIT_FOREVER);
			ledrgb_clearGreenLed();
			ledrgb_clearBlueLed();
			ledrgb_clearRedLed();
			ledrgb_setRedLed();
			OSA_TimeDelay(1500);
			estado = 1;
			statusMutex = OSA_MutexUnlock(&mutex);
			break;
		}

		status = OSA_SemaPost(&semafaro); // solta
		status = OSA_SemaPost(&semafaro); // solta
		status = OSA_SemaPost(&semafaro); // solta

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

	int estado = 1;
	osa_status_t status; // estado do sem�faro
	int contTask2 = 0;
	osa_status_t statusMutex; // estado do Mutex

#ifdef PEX_USE_RTOS
	while (1) {
#endif
		/* Write your code here ... */

//		if (contTask2 == 0)
//			status = OSA_SemaWait(&semafaro, 100); // pega
//		if (contTask2 == 3) {
//			status = OSA_SemaWait(&semafaro, 0); // pega
//			contTask2 = 0;
//		}

		status = OSA_SemaWait(&semafaro, OSA_WAIT_FOREVER); // pega
		//contTask2++;

		switch (status) {
		case kStatus_OSA_Success:
//			estado = 4;
			break;
		case kStatus_OSA_Timeout:
			estado = 3;
			break;
		case kStatus_OSA_Error:
			estado = 4;
			break;
		}

		switch (estado) {

		case 1: // pisca VERDE 15x
			statusMutex = OSA_MutexLock(&mutex, OSA_WAIT_FOREVER);
			for (int i = 0; i < 15; i++) {
				ledrgb_clearGreenLed();
				ledrgb_clearBlueLed();
				ledrgb_clearRedLed();
				ledrgb_setGreenLed();
				OSA_TimeDelay(100);
				ledrgb_clearGreenLed();
				ledrgb_clearBlueLed();
				ledrgb_clearRedLed();
				OSA_TimeDelay(100);
			}
			estado = 2;
			status = OSA_SemaPost(&semafaro);
			statusMutex = OSA_MutexUnlock(&mutex);
			break;

		case 2: // pisca AZUL 15x
			statusMutex = OSA_MutexLock(&mutex, OSA_WAIT_FOREVER);
			for (int i = 0; i < 15; i++) {
				ledrgb_clearGreenLed();
				ledrgb_clearBlueLed();
				ledrgb_clearRedLed();
				ledrgb_setBlueLed();
				OSA_TimeDelay(100);
				ledrgb_clearGreenLed();
				ledrgb_clearBlueLed();
				ledrgb_clearRedLed();
				OSA_TimeDelay(100);
			}
			estado = 1;
			status = OSA_SemaPost(&semafaro);
			statusMutex = OSA_MutexUnlock(&mutex);
			break;

		case 3: // TIME OUT: pisca TODOS 15x
			statusMutex = OSA_MutexLock(&mutex, OSA_WAIT_FOREVER);
			for (int i = 0; i < 15; i++) {
				ledrgb_clearGreenLed();
				ledrgb_clearBlueLed();
				ledrgb_clearRedLed();
				ledrgb_setGreenLed();
				ledrgb_setBlueLed();
				ledrgb_setRedLed();
				OSA_TimeDelay(100);
				ledrgb_clearGreenLed();
				ledrgb_clearBlueLed();
				ledrgb_clearRedLed();
				OSA_TimeDelay(100);
			}
			estado = 1;
			status = OSA_SemaPost(&semafaro);
			statusMutex = OSA_MutexUnlock(&mutex);
			break;

		default: // ERRO: pisca VERMELHO 15x
			statusMutex = OSA_MutexLock(&mutex, OSA_WAIT_FOREVER);
			for (int i = 0; i < 15; i++) {
				ledrgb_clearGreenLed();
				ledrgb_clearBlueLed();
				ledrgb_clearRedLed();
				ledrgb_setRedLed();
				OSA_TimeDelay(100);
				ledrgb_clearGreenLed();
				ledrgb_clearBlueLed();
				ledrgb_clearRedLed();
				OSA_TimeDelay(100);
			}
			estado = 1;
			status = OSA_SemaPost(&semafaro);
			statusMutex = OSA_MutexUnlock(&mutex);
			break;
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
