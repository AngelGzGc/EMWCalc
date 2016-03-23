################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/EMWCalc2.cpp \
../src/Map.cpp 

OBJS += \
./src/EMWCalc2.o \
./src/Map.o 

CPP_DEPS += \
./src/EMWCalc2.d \
./src/Map.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/home/angel/SwPropio/EMW/libs/all/includes -O0 -g3 -pedantic -pedantic-errors -Wall -Wextra -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


