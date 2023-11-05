//gcc -o test test.c -l<glfw|SDL2>

#include <stdio.h>
#include <stdlib.h>
#define CHASSIS_IMPL
#include <chassis/chassis.h>


int 
main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    printf("Hello chassis!\n");



    ChassisHandle chassis;
    chassis = chassisCreate(malloc);
    chassisInit(chassis);
    chassisInitWindow(chassis,(InitWindowDesc){
        .x = 640,
        .y = 480,
        .title = "Hello Chassis"
    });
    while(chassisContinue(chassis)){ }
    return 1;

}