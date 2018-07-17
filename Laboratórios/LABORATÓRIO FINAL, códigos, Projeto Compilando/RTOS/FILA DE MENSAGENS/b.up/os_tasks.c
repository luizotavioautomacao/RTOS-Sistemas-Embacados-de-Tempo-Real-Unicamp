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

struct MESSAGE {
	//unsigned char piscaLed;
	uint8_t piscaLed;
};
// messageToGet, messageToPut;

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

	osa_status_t statusMutex; // estado do Mutex
	osa_status_t statusMsg; // estado do MsqQueue
	int estado = 1; // máquina de estado
	int contTask1 = 0;
	struct MESSAGE messageToPut; // escreve na fila

#ifdef PEX_USE_RTOS
	while (1) {
#endif
		/* Write your code here ... */
		/* identar o código => control + shift + f */

		if (contTask1 == 0)
			statusMutex = OSA_MutexLock(&mutex, OSA_WAIT_FOREVER);

//		if (contTask1 > 4)
//			status = OSA_MutexLock(&mutex, OSA_WAIT_FOREVER);

		if (statusMutex == kStatus_OSA_Success) {

			switch (estado) {

			case 1:
				messageToPut.piscaLed = 5;
				statusMsg = OSA_MsgQPut(handler, &messageToPut);

				switch (statusMsg) {

				case kStatus_OSA_Success: // lithts up Blue LED
					ledrgb_clearRedLed();
					ledrgb_clearGreenLed();
					ledrgb_clearBlueLed();
					ledrgb_setBlueLed();
					break;
				case kStatus_OSA_Error: // lithts up Red LED
					ledrgb_clearBlueLed();
					ledrgb_clearRedLed();
					ledrgb_clearGreenLed();
					ledrgb_setRedLed();
					break;
				default:
					for (int i = 0; i < 3; i++) {
						ledrgb_setBlueLed();
						ledrgb_setRedLed();
						ledrgb_setGreenLed();
						OSA_TimeDelay(500);
						ledrgb_clearRedLed();
						ledrgb_clearGreenLed();
						ledrgb_clearBlueLed();
						OSA_TimeDelay(500);
					}
				}

				OSA_TimeDelay(2000);
				estado = 2;
				break;

			case 2:
				messageToPut.piscaLed = 5;
				statusMsg = OSA_MsgQPut(handler, &messageToPut);

				switch (statusMsg) {

				case kStatus_OSA_Success: // turn off Blue LED
					ledrgb_clearRedLed();
					ledrgb_clearGreenLed();
					ledrgb_clearBlueLed();
					break;
				case kStatus_OSA_Error: // lithts up Red LED
					ledrgb_clearBlueLed();
					ledrgb_clearRedLed();
					ledrgb_clearGreenLed();
					ledrgb_setRedLed();
					break;
				default:
					for (int i = 0; i < 5; i++) {
						ledrgb_setBlueLed();
						ledrgb_setRedLed();
						ledrgb_setGreenLed();
						OSA_TimeDelay(1000);
						ledrgb_clearRedLed();
						ledrgb_clearGreenLed();
						ledrgb_clearBlueLed();
						OSA_TimeDelay(1000);
					}
				}

				OSA_TimeDelay(2000);
				estado = 1;
				break;
			}

		}

		contTask1++;

		if (contTask1 == 5) {
			OSA_MutexUnlock(&mutex);
			contTask1 = 0;
			estado = 1;
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

	osa_status_t statusMutex; // estado do Mutex
	osa_status_t statusMsg; // estado do MsgQueue
	int estado = 1; // máquina de estado
	int contTask2 = 0;
	struct MESSAGE messageToGet; // lê fila

#ifdef PEX_USE_RTOS
	while (1) {
#endif
		/* Write your code here ... */

		if (contTask2 == 0)
			statusMutex = OSA_MutexLock(&mutex, OSA_WAIT_FOREVER);

		if (statusMutex == kStatus_OSA_Success) {

			switch (estado) {

			case 1:
				statusMsg = OSA_MsgQGet(handler, &messageToGet,
				2000);

				switch (statusMsg) {
				case kStatus_OSA_Success: // lithts up Green LED
					for (int i = 0; i < messageToGet.piscaLed; i++) {
						ledrgb_clearRedLed();
						ledrgb_clearGreenLed();
						ledrgb_clearBlueLed();
						ledrgb_setGreenLed();
						OSA_TimeDelay(100);
						ledrgb_clearRedLed();
						ledrgb_clearGreenLed();
						ledrgb_clearBlueLed();
						OSA_TimeDelay(100);
					}
					break;
				case kStatus_OSA_Error: // lithts up Red LED 10x t = 0,25 s
					for (int i = 0; i < 10; i++) {
						ledrgb_clearBlueLed();
						ledrgb_clearRedLed();
						ledrgb_clearGreenLed();
						ledrgb_setRedLed();
						OSA_TimeDelay(250);
						ledrgb_clearRedLed();
						ledrgb_clearGreenLed();
						ledrgb_clearBlueLed();
						OSA_TimeDelay(250);
					}
					break;

				case kStatus_OSA_Timeout:
					for (int i = 0; i < 10; i++) {
						ledrgb_setBlueLed();
						ledrgb_setRedLed();
						ledrgb_setGreenLed();
						OSA_TimeDelay(250);
						ledrgb_clearRedLed();
						ledrgb_clearGreenLed();
						ledrgb_clearBlueLed();
						OSA_TimeDelay(250);
					}
				}

				estado = 2;
				break;

			case 2:
				statusMsg = OSA_MsgQGet(handler, &messageToGet,
				2000);

				switch (statusMsg) {
				case kStatus_OSA_Success: // lithts up Yellow LED
					for (int i = 0; i < messageToGet.piscaLed; i++) {
						ledrgb_clearRedLed();
						ledrgb_clearGreenLed();
						ledrgb_clearBlueLed();
						ledrgb_setGreenLed();
						ledrgb_setRedLed();
						OSA_TimeDelay(100);
						ledrgb_clearRedLed();
						ledrgb_clearGreenLed();
						ledrgb_clearBlueLed();
						OSA_TimeDelay(100);
					}
					break;
				case kStatus_OSA_Error: // lithts up Red LED 10x 0.25s
					for (int i = 0; i < 10; i++) {
						ledrgb_clearBlueLed();
						ledrgb_clearRedLed();
						ledrgb_clearGreenLed();
						ledrgb_setRedLed();
						OSA_TimeDelay(250);
						ledrgb_clearRedLed();
						ledrgb_clearGreenLed();
						ledrgb_clearBlueLed();
						OSA_TimeDelay(250);
					}
					break;

				case kStatus_OSA_Timeout:
					for (int i = 0; i < 10; i++) {
						ledrgb_setBlueLed();
						ledrgb_setRedLed();
						ledrgb_setGreenLed();
						OSA_TimeDelay(250);
						ledrgb_clearRedLed();
						ledrgb_clearGreenLed();
						ledrgb_clearBlueLed();
						OSA_TimeDelay(250);
					}
				}

				estado = 1;
				break;
			}
		}

		contTask2++;

		if (contTask2 == 5) {
			OSA_MutexUnlock(&mutex);
			contTask2 = 0;
			estado = 1;
		}

//		if (contTask2 > 4){
//			OSA_MutexUnlock(&mutex);
//			contTask2 = 0;
//		}

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
