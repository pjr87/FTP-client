################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../FTPclient.cpp \
../Socket.cpp \
../log.cpp \
../main.cpp 

OBJS += \
./FTPclient.o \
./Socket.o \
./log.o \
./main.o 

CPP_DEPS += \
./FTPclient.d \
./Socket.d \
./log.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


