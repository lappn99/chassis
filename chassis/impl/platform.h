#include <assert.h> /* assert */
#include <errno.h> /* errno */
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* strerror */

#ifdef CHASSIS_GLFW 
#include <GLFW/glfw3.h> 
#endif
#ifdef CHASSIS_SDL2
#include <SDL2/SDL.h>
#endif

#define __NOT_IMPL assert(0)

//GLFW Implementation
#ifdef CHASSIS_GLFW

struct Chassis
{
    GLFWwindow* window;
};
 
int 
chassisInit(ChassisHandle handle)
{
    (void)handle;
    if(!glfwInit())
    {
        fprintf(stderr,"Could not init GLFW");
        return 0;
    }

    

    return 1;

}

int 
chassisInitWindow(ChassisHandle handle, InitWindowDesc initWindowDesc)
{

    handle->window = glfwCreateWindow(initWindowDesc.x,initWindowDesc.y,initWindowDesc.title,NULL,NULL);
    if(!handle->window)
    {
        fprintf(stderr,"Could not create GLFW window\n");
        return 0;

    }
    glfwMakeContextCurrent(handle->window);
    return 1;
}

int
chassisContinue(ChassisHandle handle)
{
    if(glfwWindowShouldClose(handle->window))
    {
        return 0;
    }
    glfwSwapBuffers(handle->window);
    glfwPollEvents();
    return 1;

}



#endif
#ifdef CHASSIS_SDL2

struct Chassis
{
    SDL_Window* window;
    SDL_Surface* surface;

};

int 
chassisInit(ChassisHandle handle)
{
    (void)handle;
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr,"Could not init SDL2: %s\n",SDL_GetError());
        return 0;
    }
    return 1;
}
int 
chassisInitWindow(ChassisHandle handle, InitWindowDesc initWindowDesc)
{
    handle->window = SDL_CreateWindow(initWindowDesc.title,SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,initWindowDesc.x,initWindowDesc.y,0);
    if(handle->window == NULL)
    {
        fprintf(stderr,"Could not create SDL2 window: %s\n",SDL_GetError());
        return 0;
    }
    handle->surface = SDL_GetWindowSurface(handle->window);
    return 1;
}
int 
chassisContinue(ChassisHandle handle)
{
    SDL_FillRect(handle->surface,NULL,SDL_MapRGB(handle->surface->format,0xFF,0xFF,0xFF));
    SDL_UpdateWindowSurface(handle->window);
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_QUIT)
        {
            return 0;
            SDL_DestroyWindow(handle->window);
            SDL_Quit();
        }
    }
    return 1;
}


#endif


ChassisHandle 
chassisCreate(MemoryAlloc_func memAlloc)
{
    ChassisHandle handle = memAlloc(sizeof(struct Chassis));
    if(handle == NULL)
    {
        fprintf(stderr,"Error allocation memory for ChassisHandle: %s",strerror(errno));

        return NULL;
    }
    return handle;
}

//Structs have same field name for window
//Will work if that stays true
void*
chassisGetWindow(ChassisHandle handle)
{
    return handle->window;
}