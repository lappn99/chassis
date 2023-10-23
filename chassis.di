module chassis;

extern(C)
{
    struct Chassis;
    alias funcMemoryAlloc = void* function(size_t);
    struct InitWindowDesc
    {
        int x;
        int y;
        const char* title;
    }
    alias ChassisHandle = Chassis*;
    ChassisHandle chassisCreate(funcMemoryAlloc);
    int chassisInit(ChassisHandle);
    int chassisInitWindow(ChassisHandle, InitWindowDesc);
    int chassisContinue(ChassisHandle);
}