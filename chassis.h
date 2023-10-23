#ifndef CHASSIS_H
#define CHASSIS_H


struct Chassis;
typedef struct Chassis* ChassisHandle;
typedef void* (*funcMemoryAlloc)(size_t);

typedef struct
{
    int x;
    int y;
    const char* title;
} InitWindowDesc;


//Create chassis handle allocating with user supplied allocation callback
ChassisHandle chassisCreate(funcMemoryAlloc);
//Returns
// 1: If success
// 0: If failed
int chassisInit(ChassisHandle);
//Creates window
//Returns
// 1: If success
// 0: If failed
int chassisInitWindow(ChassisHandle, InitWindowDesc);
//Updates screen and checks if window should close
//Returns:
// 1: Continure to next frame
// 0: Chassis has stopped
int chassisContinue(ChassisHandle);
void* chassisGetWindow(ChassisHandle);


#endif