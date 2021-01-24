/**
******************************************************************************
* File    readme.txt  
* Version V3.3.0
* Date    08-May-2018
******************************************************************************
* Attention
*
* COPYRIGHT(c) 2018 STMicroelectronics
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*   1. Redistributions of source code must retain the above copyright notice,
*      this list of conditions and the following disclaimer.
*   2. Redistributions in binary form must reproduce the above copyright notice,
*      this list of conditions and the following disclaimer in the documentation
*      and/or other materials provided with the distribution.
*   3. Neither the name of STMicroelectronics nor the names of its contributors
*      may be used to endorse or promote products derived from this software
*      without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************
*/

Application Description:

FP-CLD-AZURE1/Azure_Motor provides a software running on STM32 which offers a complete middleware to build applications based on 
WiFi connectivity (SPW01SA) and to connect STM32 Nucleo boards (or B-L475E-IOT01A Discovery kit IoT node)
with Microsoft Azure IoT services.

FP-CLD-AZURE1/Azure_Motor is an function package software for STM32Cube. The software runs on the STM32 micro-controller and 
includes drivers that recognize WiFi module (SPWF01SA), dynamic NFC/RFID tag (ST25DV4K) and dual stepper motor drivers (L6470)
It also includes the porting of the Microsoft Azure IoT device SDK for easy connection with 
Azure IoT services. The expansion software is built on STM32Cube software technology 
to ease portability across different STM32 microcontrollers. The software comes with examples for registering the 
device on Microsoft Azure IoT Hub, transmit data and receive commands, and control 2 stepper motors

This application allows the user to control the initialization phase via UART.
Launch a terminal application and set the UART port to 115200 bps, 8 bit, No Parity, 1 stop bit
 
This firmware package includes Components Device Drivers, Board Support Package and example application for the following STMicroelectronics elements:
- X-NUCLEO-IDW01M1 Wi-Fi evaluation board based on the SPWF01SA module
- X-NUCLEO-NFC04A1 a Dynamic NFC tag evaluation board
- X-NUCLEO-IHM02A1 Dual stepper motor drivers module
- NUCLEO-L476RG Nucleo board
- NUCLEO-F429ZI Nucleo board
- B-L475E-IOT01A Discovery kit IoT node

@par Hardware and Software environment

  - This example runs on expansion boards attached to STM32 Nucleo boards or B-L475E-IOT01A Discovery that
    can be easily tailored to any other supported device and development board.

@par STM32Cube packages:
  - STM32L4xx drivers from STM32CubeL4 V1.11.0
@par X-CUBE packages:
  - X-CUBE-WIFI1 V2.1.1
  - X-CUBE-NFC4 V1.1.0
  - X-CUBE-SPN2 V1.1.0
  - X-CUBE-AZURE_V1.1.0
@par Middlewares packages:
  - mbedTLS V1.1.31
  - Azure SDK V1.1.31
  - MetaDataManager V0.8.0
  - LibNDEF


@par How to use it ? 

This package contains projects for 3 IDEs viz. IAR, µVision and System Workbench. 
In order to make the  program work, you must do the following:
 - WARNING: before opening the project with any toolchain be sure your folder
   installation path is not too in-depth since the toolchain may report errors
   after building.

For IAR:
 - Open IAR toolchain (this firmware has been successfully tested with Embedded Workbench V7.80.4).
 - Open the IAR project file (for example) EWARM\STM32L476RG-Nucleo\Azure1_Sns_DM.eww
 - Rebuild all files and flash the binary to the board

For µVision:
 - Open µVision toolchain (this firmware has been  successfully tested with MDK-ARM Professional Version: 5.22.0).
 - Open the µVision project file (for example) MDK-ARM\STM32L476RG-Nucleo\Project.uvprojx
 - Rebuild all files and flash the binary to the board
 
For System Workbench:
 - Open System Workbench for STM32 (this firmware has been successfully tested with System Workbench for STM32 Version 2.4.0.20181120948).
 - Set the default workspace proposed by the IDE (please be sure that there are not spaces in the workspace path).
 - Press "File" -> "Import" -> "Existing Projects into Workspace"; press "Browse" in the "Select root directory" and choose the path where the System
   Workbench project is located (it should be for example SW4STM32\STM32L476RG-Nucleo\ ). 
 - Rebuild all files and flash the binary to the board             
             
Message format for Commands:
{"Name" : "Pause", "Parameters" : {}}

For Motor Control Send a Message with:
- For Moving one motor:
{"Name" :  "MoveMotor", "Parameters" : {"MotorNum":1,"Angle":-90}}
With MotorNum=0/1
 -360 <=Angle <= 360

- For Running one motor:
{"Name" :  "RunMotor", "Parameters" : {"MotorNum":1,"Speed":-5}}
With MotorNum=0/1
 -10 <=Speed <= 10

- For reporting the Motor to the default position:
{"Name" :  "GoHomeMotor", "Parameters" : {"MotorNum":1}}

- For resetting one Motor:
{"Name" :  "ResetMotor", "Parameters" : {"MotorNum":1}}


- For Sending a Complex Movement:
{"Name" : "ComplexMove", "Parameters" : {"ComplexProgram" : "M 1 -90 D 100 M 0 180 M 1 140 D 2000 H 0 H 1 E" }}
For example it makes:
- Move Motor 1 of -90 degree
- Delay of 100 mS
- Move Motor 0 of 180 degree
- Move Motor 1 of 140 degree
- Delay of 2000 mS
- Return to Home Position for Motor 0
- Return to Home Position for Motor 1
- End of program

Possible commands for Complex Movement are:
- M -> for MoveMotor Command
- D -> for Delay Command
- H -> for GoHomeMotor Command
- S -> for RunMotor Command
- R -> for ResetMotor Command (it must be used for stopping one motor after the RunMotor Command)
- E -> for END of Complex Movement program

{"Name" : "ComplexMove", "Parameters" : {"ComplexProgram" : "M 1 -90 D 100 M 0 180 S 1 10 D 3000 R 1 S 0 -5 D 2000 R 0 E" }}

For Desired property:
"DesiredTelemetryInterval":2

 /******************* (C) COPYRIGHT 2017 STMicroelectronics *****END OF FILE****/
