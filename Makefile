include config.mk



build: libchassis.so 

install: ./chassis/chassis.h
	mkdir -p ${DESTDIR}${INCLUDE_PREFIX}
	cp -r ./chassis ${DESTDIR}${INCLUDE_PREFIX}

uninstall:
	rm -rf ${DESTDIR}${INCLUDE_PREFIX}chassis

test: ./tests/c/test.c
	gcc -o test ./tests/c/test.c -lglfw