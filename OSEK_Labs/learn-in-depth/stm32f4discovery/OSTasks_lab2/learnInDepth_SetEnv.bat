@echo off
SET ARM_CROSS_TOOLCHAIN_PATH=C:\Program Files (x86)\Arm GNU Toolchain arm-none-eabi\13.2 Rel1\bin
SET PYTHON_PATH=C:\Users\dell\AppData\Local\Programs\Python\Python312
SET goil_PATH=..\..\

SET PATH=%ARM_CROSS_TOOLCHAIN_PATH%;%PYTHON_PATH%;%goil_PATH%;%PATH%

echo Environment variables have been set.
