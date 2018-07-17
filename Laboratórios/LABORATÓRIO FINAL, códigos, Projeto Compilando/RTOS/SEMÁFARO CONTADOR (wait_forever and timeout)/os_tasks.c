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
	osa_status_t status; // estado do semáfaro

#ifdef PEX_USE_RTOS
	while (1) {
#endif
		/* Write your code here ... */

		status = OSA_SemaWait(&semafaro, OSA_WAIT_FOREVER); // take semafaro

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

		case 1: // acende VERDE 1.5s
			status = OSA_SemaWait(&semafaro, OSA_WAIT_FOREVER); // take semafaro
			ledrgb_clearGreenLed();
			ledrgb_clearBlueLed();
			ledrgb_clearRedLed();
			ledrgb_setGreenLed();
			OSA_TimeDelay(1500);
			estado = 2;
			status = OSA_SemaPost(&semafaro); // Give semafaro
			status = OSA_SemaPost(&semafaro); // Give semafaro
			break;

		case 2: // acende Azul 1.5s
			status = OSA_SemaWait(&semafaro, OSA_WAIT_FOREVER); // take semafaro
			ledrgb_clearGreenLed();
			ledrgb_clearBlueLed();
			ledrgb_clearRedLed();
			ledrgb_setBlueLed();
			OSA_TimeDelay(1500);
			estado = 1;
			status = OSA_SemaPost(&semafaro); // Give semafaro
			status = OSA_SemaPost(&semafaro); // Give semafaro
			break;

		case 3: // acende todos 1.5s
			status = OSA_SemaWait(&semafaro, OSA_WAIT_FOREVER); // take semafaro
			ledrgb_setGreenLed();
			ledrgb_setBlueLed();
			ledrgb_setRedLed();
			OSA_TimeDelay(1500);
			estado = 1;
			status = OSA_SemaPost(&semafaro); // Give semafaro
			break;

		default: // acende Rosa 1.5s
			status = OSA_SemaWait(&semafaro, OSA_WAIT_FOREVER); // take semafaro
			ledrgb_clearBlueLed();
			ledrgb_clearRedLed();
			ledrgb_setRedLed();
			OSA_TimeDelay(1500);
			estado = 1;
			status = OSA_SemaPost(&semafaro); // Give semafaro
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

	int estado = 1;
	osa_status_t status; // estado do semáfaro
	int contTask2 = 0;

#ifdef PEX_USE_RTOS
	while (1) {
#endif
		/* Write your code here ... */

		status = OSA_SemaWait(&semafaro, OSA_WAIT_FOREVER); // take semafaro

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

		case 1: // Acende Vermelho 1.5s
			status = OSA_SemaWait(&semafaro, OSA_WAIT_FOREVER); // take semafaro
			ledrgb_clearGreenLed();
			ledrgb_clearBlueLed();
			ledrgb_clearRedLed();
			ledrgb_setRedLed();
			OSA_TimeDelay(1500);
			estado = 2;
			status = OSA_SemaPost(&semafaro);
			status = OSA_SemaPost(&semafaro);
			break;

		case 2: // Apaga Todos 1.5s
			status = OSA_SemaWait(&semafaro, OSA_WAIT_FOREVER); // take semafaro
			ledrgb_clearGreenLed();
			ledrgb_clearBlueLed();
			ledrgb_clearRedLed();
			OSA_TimeDelay(1500);
			estado = 1;
			status = OSA_SemaPost(&semafaro);
			status = OSA_SemaPost(&semafaro);
			break;

		case 3: // Acende Amarelo 1.5s
			status = OSA_SemaWait(&semafaro, OSA_WAIT_FOREVER); // take semafaro
			ledrgb_clearBlueLed();
			ledrgb_setGreenLed();
			ledrgb_setRedLed();
			OSA_TimeDelay(1500);
			estado = 1;
			status = OSA_SemaPost(&semafaro);
			break;

		default: // ERRO: Acende Ciano 1.5s
			status = OSA_SemaWait(&semafaro, OSA_WAIT_FOREVER); // take semafaro
			ledrgb_clearRedLed();
			ledrgb_setGreenLed();
			ledrgb_setBlueLed();
			OSA_TimeDelay(1500);
			estado = 1;
			status = OSA_SemaPost(&semafaro);
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
