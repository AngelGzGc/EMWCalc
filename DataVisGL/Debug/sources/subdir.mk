################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/angel/SwPropio/EMW/libs/all/sources/jsoncpp.cpp 

OBJS += \
./sources/jsoncpp.o 

CPP_DEPS += \
./sources/jsoncpp.d 


# Each subdirectory must supply rules for building sources it contributes
sources/jsoncpp.o: /home/angel/SwPropio/EMW/libs/all/sources/jsoncpp.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/angel/SwPropio/EMW/libs/all/includes -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

