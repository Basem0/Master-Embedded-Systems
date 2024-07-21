#@copyright : Ahmed Basem

CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_name=PressureDetectionSystem


all: $(Project_name).bin
	@echo "======== Buid is Done ========"

%.o: %.c 
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@
	
%.s: %.c 
	$(CC)gcc.exe -S $(CFLAGS) $(INCS) $< -o $@
	
	

$(Project_name).elf: $(AsOBJ) $(OBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(AsOBJ) $(OBJ) -o $@ -Map=Map_file.map

	 
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	 
	 	 
clean-all: 
	rm $(OBJ) $(Project_name).elf $(Project_name).bin
	 
clean: 
	rm $(Project_name).elf $(Project_name).bin