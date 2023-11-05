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
    ChassisHandle chassisCreate(funcMemoryAlloc) nothrow @nogc;
    int chassisInit(ChassisHandle) nothrow @nogc;
    int chassisInitWindow(ChassisHandle, InitWindowDesc) nothrow @nogc;
    int chassisContinue(ChassisHandle) nothrow @nogc;
    void* chassisGetWindow(ChassisHandle) nothrow @nogc;
}

unittest
{
    import core.stdc.stdlib;
    ChassisHandle chassis;
    chassis = chassisCreate(&malloc);
    chassisInit(chassis);
    InitWindowDesc windowDesc = {x:640,y:480,title:"Hello chassis"};
    chassisInitWindow(chassis,windowDesc);
    while(chassisContinue(chassis)){ }

}