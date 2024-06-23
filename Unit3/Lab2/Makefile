#@copyright : Basem
CC=arm-none-eabi-
CFLAGS=-g -mcpu=cortex-m3
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
Project_name=led_cortex-m3

all: $(Project_name).bin
	@echo "====Every THINGS OKEY===="

#%.o: %.s
#	$(CC)as $(CFLAGS) $< -o $@

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