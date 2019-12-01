/*
 * Copyright (c) 2015-2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== mutex.c ========
 */

/* XDC module Headers */
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <ti/drivers/UART.h>

#include "ti_drivers_config.h"
#include<stdio.h>
/* BIOS module Headers */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/drivers/GPIO.h>
#include <ti/drivers/Board.h>
#include <stdint.h>
#include <stddef.h>
#define __MSP432P4XX__
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#define TASKSTACKSIZE   10240
#include <stdbool.h>

Void task1Fxn(UArg arg0, UArg arg1);
Void task2Fxn(UArg arg0, UArg arg1);

Int resource = 0;
Int finishCount = 0;
UInt32 sleepTickCount;

Task_Struct task1Struct, task2Struct;
Char task1Stack[TASKSTACKSIZE], task2Stack[TASKSTACKSIZE];
Semaphore_Struct semStruct;
Semaphore_Handle semHandle;

/*
 *  ======== main ========
 */


int main()
{
    /* Construct BIOS objects */
    Task_Params taskParams;
    Semaphore_Params semParams;

    /* Call driver init functions */
    Board_init();

    /*set GPIO pin*/
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);

    /* Construct writer/reader Task threads */
    Task_Params_init(&taskParams);
    taskParams.stackSize = TASKSTACKSIZE;
 //  taskParams.stack = &task1Stack;
//   taskParams.priority = 1;
//    Task_construct(&task1Struct, (Task_FuncPtr)task1Fxn, &taskParams, NULL);

    taskParams.stack = &task2Stack;
    taskParams.priority = 2;
    Task_construct(&task2Struct, (Task_FuncPtr)task2Fxn, &taskParams, NULL);

    /* Construct a Semaphore object to be use as a resource lock, inital count 1 */
    Semaphore_Params_init(&semParams);
    Semaphore_construct(&semStruct, 1, &semParams);

    /* Obtain instance handle */
    semHandle = Semaphore_handle(&semStruct);

    /* We want to sleep for 10000 microseconds */
    sleepTickCount = 10000 / Clock_tickPeriod;

    BIOS_start();    /* Does not return */
    return(0);


}

/*
 *  ======== task1Fxn ========
 */
Void task1Fxn(UArg arg0, UArg arg1)
{
//    char        input;
//    UART_Handle uart;
//    UART_Params uartParams;
//
//    UART_init();
//    /* Create a UART with data processing off. */
//    UART_Params_init(&uartParams);
//   uartParams.writeDataMode = UART_DATA_BINARY;
//   uartParams.readDataMode = UART_DATA_BINARY;
//   uartParams.readReturnMode = UART_RETURN_FULL;
//   uartParams.readEcho = UART_ECHO_OFF;
//   uartParams.baudRate = 115200;
//
//   uart = UART_open(CONFIG_UART_0, &uartParams);
//
//    while(1){
//        UART_read(uart, &input,1);
//        if(input == 49)
//        {
//            MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
//        }
//        else if(input == 48)
//        {
//            MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
//        }
//        printf("%d\n", input);
//    }
}
Void task2Fxn(UArg arg0, UArg arg1)
{
    char        input;
    UART_Handle uart;
    UART_Params uartParams;
    bool status = false; // set default
    bool last = true;
    UART_init();
    /* Create a UART with data processing off. */
    UART_Params_init(&uartParams);
   uartParams.writeDataMode = UART_DATA_BINARY;
   uartParams.readDataMode = UART_DATA_BINARY;
   uartParams.readReturnMode = UART_RETURN_FULL;
   uartParams.readEcho = UART_ECHO_OFF;
   uartParams.baudRate = 115200;

   uart = UART_open(CONFIG_UART_0, &uartParams);
   const char  echoPrompt[] = "OPEN\n";
   const char  echoPrompt1[] = "CLOSE\n";
//   UART_write(uart, echoPrompt, sizeof(echoPrompt));
        while(1) //check status
        {
            Task_sleep(100);
            //UART_write(uart, echoPrompt, sizeof(echoPrompt));
            status = false;    // precondition false
            if(status == false){
                if(status == last){
                Task_sleep(2000);
                UART_write(uart, echoPrompt, sizeof(echoPrompt));
                }
                else if(status!= last)
                {
                UART_write(uart, echoPrompt, sizeof(echoPrompt));
                last = status;
                }

            }
            UART_read(uart, &input, 1);
            if(input == 49 || 48)
            {
                status = true;
                UART_write(uart, echoPrompt1, sizeof(echoPrompt1));
                last = status;

            }

        }


}

