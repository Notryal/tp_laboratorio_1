################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Hoja\ de\ Trabajo.c \
../src/biblioteca.c \
../src/operaciones.c 

OBJS += \
./src/Hoja\ de\ Trabajo.o \
./src/biblioteca.o \
./src/operaciones.o 

C_DEPS += \
./src/Hoja\ de\ Trabajo.d \
./src/biblioteca.d \
./src/operaciones.d 


# Each subdirectory must supply rules for building sources it contributes
src/Hoja\ de\ Trabajo.o: ../src/Hoja\ de\ Trabajo.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Hoja de Trabajo.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


