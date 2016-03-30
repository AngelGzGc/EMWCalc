################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Camera.cpp \
../src/CameraMgr.cpp \
../src/DataVisGL.cpp \
../src/HMap.cpp \
../src/HUD.cpp \
../src/Map.cpp \
../src/Object.cpp \
../src/Source.cpp \
../src/VisualConfig.cpp 

OBJS += \
./src/Camera.o \
./src/CameraMgr.o \
./src/DataVisGL.o \
./src/HMap.o \
./src/HUD.o \
./src/Map.o \
./src/Object.o \
./src/Source.o \
./src/VisualConfig.o 

CPP_DEPS += \
./src/Camera.d \
./src/CameraMgr.d \
./src/DataVisGL.d \
./src/HMap.d \
./src/HUD.d \
./src/Map.d \
./src/Object.d \
./src/Source.d \
./src/VisualConfig.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I../../libs/all/includes -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


