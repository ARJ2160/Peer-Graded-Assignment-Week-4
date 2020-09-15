#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#Joji John
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile that supports two build platforms: HOST machine and MSP432
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#	<FILE>.o 	- Builds a <FILE>.o object file
#	<FILE>.i 	- Builds a <FILE>.i preprocessed file	
#	<FILE>.asm      - Builds a <FILE>.asm assembly file
#	<FILE>.d        - Builds a <FILE>.d dependency file
#	compile-all     - Compiles all object files in project
#	build 		- Builds and links all object files 
#	clean	        - Removes all generated filE
#
#
# Platform Overrides:
#	HOST            - Default
#	MSP423	        - Target platform 
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs

GENFLAGS= -Wall \
	  -Werror \
	  -g \
	  -O0 \
	  -std=c99

TARGET = final

ifeq ($(PLATFORM),HOST)
	CC = gcc
	LD = ld
	LDFLAGS = -Wl,-Map=$(TARGET).map
	CFLAGS = $(GENFLAGS)
	CPPFLAGS = -DVERBOSE -DCOURSE1 -D$(PLATFORM) -MD $(INCLUDES)
	SOURCES = $(SRC)
	OBJDUMP = objdump
	SIZE = size
else
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	CFLAGS = -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=hard \
		 -mfpu=fpv4-sp-d16 --specs=$(SPECS) $(GENFLAGS)
	CPPFLAGS = -D$(PLATFORM) -MD $(INCLUDES)
	SOURCES = $(SRC) $(SRC_MSP432)
	OBJDUMP = arm-none-eabi-objdump
	SIZE = arm-none-eabi-size
endif


OBJS = $(SOURCES:.c=.o)
%.o : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $^ -o $@

%.i : %.c
	$(CC) $(CPPFLAGS) -E $^ -o $@

$(TARGET).asm : $(TARGET).out
	$(OBJDUMP) -d $^ > $@

%.asm : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -S $^ -o $@ 

.PHONY: compile-all
compile-all : $(OBJS)

.PHONY: build
build : $(TARGET).out

$(TARGET).out : $(OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $^ -o $@
	$(SIZE) -Atd $@ $(TARGET).out

.PHONY: clean
clean : 
	rm -f $(TARGET).out $(TARGET).map  ./src/*.i ./src/*.d ./src/*.asm ./src/*.o
       
        


