//dmd test.d chassis.di -L-lchassis -L-l<glfw|SDL2>
import std.stdio;
import chassis;
import core.stdc.stdlib;

int main()
{
    ChassisHandle chassis;
    chassis = chassisCreate(&malloc);
    chassisInit(chassis);
    InitWindowDesc windowDesc = {x:640,y:480,title:"Hello chassis"};
    chassisInitWindow(chassis,windowDesc);
    while(chassisContinue(chassis)){ }
    return 0;
}