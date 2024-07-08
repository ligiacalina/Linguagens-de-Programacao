# Exercicio Avaliado 01 - Times de Futebol
# Ligia Calina Bueno Bonifacio
# Data: 17/05/2023
# DRE: 122046065

CC = g++
LD = g++

CFLAGS = -Wall -std=c++11
LFLAGS = -Wall -std=c++11

EXERCICIO_AVALIADO_01_OBJS = main.o time.o liga.o

EXERCICIO = timesDeFutebol

.cpp.o:
	$(CC) $(CFLAGS) -c $<

all: $(EXERCICIO)

timesDeFutebol: $(EXERCICIO_AVALIADO_01_OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXERCICIO_AVALIADO_01_OBJS) -lm

clean:
	rm -f *.o $(EXERCICIO)

clean-objs:
	rm -f *.o