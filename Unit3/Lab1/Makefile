#@copyright : Basem
CC=arm-none-eabi-
CFLAGS=-mcpu=arm926ej-s -g
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
Project_name=output

all: $(Project_name).bin
	@echo "====Every THINGS OKEY===="

startup.o: startup.s
	$(CC)as $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc -c $(INCS) $(CFLAGS) $< -o $@

$(Project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld -T linkerScript.ld $(LIBS) $^ -o $@ -Map=mapFile.map

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy -O binary $< $@

clean_all:
	rm -f *.o *.elf *.bin

clean:
	rm -f *.bin *.elf