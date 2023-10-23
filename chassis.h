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

ChassisHandle chassisCreate(funcMemoryAlloc);

int chassisInit(ChassisHandle);
int chassisInitWindow(ChassisHandle, InitWindowDesc);
int chassisContinue(ChassisHandle);

#endif