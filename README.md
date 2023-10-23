# chassis
Simple library with interfaces in both C and D to get a window up using SDL2 or GLFW (users choice)



## Build steps:
  1. Modify config.mk so `WINDOWING_BACKEND` is using set to your backend of choice. Available choices are `SDL2` or `GLFW`
  2. `sudo make clean install`
  3. Optionally test it against provided example files `test.c` and `test.d` for C and D respectively
     
