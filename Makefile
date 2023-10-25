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
	mkdir -p ${DESTDIR}${LIB_PREFIX}
	mkdir -p ${DESTDIR}${INCLUDE_PREFIX}
	cp libchassis.so ${DESTDIR}${LIB_PREFIX}
	chmod 0755 ${DESTDIR}${LIB_PREFIX}/libchassis.so
	ldconfig
	cp chassis.h ${DESTDIR}${INCLUDE_PREFIX}

uninstall:
	rm -f ${DESTDIR}${LIB_PREFIX}/libchassis.so
	rm -f ${DESTDIR}${INCLUDE_PREFIX}/chassis.h

chassis.o: config.h chassis.c
	echo "Building chassis.o"
	${CC} ${CCFLAGS} ${LIBS} ${INCLUDE} chassis.c 

libchassis.so: chassis.o
	${CC} ${LDFLAGS} -o ${DESTDIR}libchassis.so ${DESTDIR}chassis.o

config.h : config.def.h
	cp config.def.h config.h
	


clean:
	rm -f ${DESTDIR}libchassis.so
	rm -f ${DESTDIR}chassis.o
