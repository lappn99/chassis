include config.mk
CC=gcc
CCFLAGS=-c -Wall -Wextra -std=c11 -pedantic -fpic
LDFLAGS=-shared
INCLUDE=-I./

ifeq ($(WINDOWING_BACKEND),SDL2)
	LIBS=-lSDL2
	CCFLAGS+=-DCHASSIS_SDL2
else ifeq ($(WINDOWING_BACKEND),GLFW)
	LIBS=-lglfw
	CCFLAGS+=-DCHASSIS_GLFW
endif



build: libchassis.so
install: build
	cp libchassis.so /usr/lib
	chmod 0755 /usr/lib/libchassis.so
	ldconfig

chassis.o: config.h chassis.c
	echo "Building chassis.o"
	${CC} ${CCFLAGS} ${LIBS} ${INCLUDE} chassis.c 

libchassis.so: chassis.o
	${CC} ${LDFLAGS} -o libchassis.so chassis.o

config.h : config.def.h
	cp config.def.h config.h
	

clean:
	rm -f libchassis.so
	rm -f chassis.o
	rm -f /usr/lib/libchassis.so
