# SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
# SPDX-License-Identifier: MIT
cmake_minimum_required(VERSION 3.16)

# Set JerryScript variables
set(JERRY_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/jerryscript")
set(JERRY_ERROR_MESSAGES ON)
set(JERRY_BUILD_DIR ${JERRY_ROOT_DIR}/build/jerry)
set(JERRY_INCLUDE_DIRS "${JERRY_ROOT_DIR}/jerry-ext/include" "${JERRY_ROOT_DIR}/jerry-core/include")
if (${CONFIG_JERRYSCRIPT_MALLOC_STRATEGY_SPIRAM})
    set(JERRY_ATTR_GLOBAL_HEAP "__attribute__((section(\".ext_ram.bss\")))")
else()
    set(JERRY_ATTR_GLOBAL_HEAP "")
endif()
# Xtensa processor architecture optimization
set(EXTERNAL_COMPILE_FLAGS -ffunction-sections -fdata-sections -fstrict-volatile-bitfields -mlongcalls -Wno-frame-address)
string(REPLACE ";" "|" EXTERNAL_COMPILE_FLAGS_ALT_SEP "${EXTERNAL_COMPILE_FLAGS}")

list(APPEND SOURCES "${JERRY_ROOT_DIR}/targets/baremetal-sdk/espressif/main/jerry-port.c")

idf_component_register(
    SRCS ${SOURCES}
    INCLUDE_DIRS ${JERRY_INCLUDE_DIRS}
)
set(JERRY_ATTR_GLOBAL_HEAP "__attribute__((section(\".ext_ram.bss\")))")
externalproject_add(jerryscript_build
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}
  SOURCE_DIR ${JERRY_ROOT_DIR}
  BUILD_IN_SOURCE 0
  BINARY_DIR jerryscript
  INSTALL_COMMAND "" # Do not install to host
  LIST_SEPARATOR | # Use the alternate list separator
  CMAKE_ARGS
    -DJERRY_GLOBAL_HEAP_SIZE=${CONFIG_JERRYSCRIPT_HEAP_SIZE}
    -DJERRY_ATTR_GLOBAL_HEAP=${JERRY_ATTR_GLOBAL_HEAP}
    -DJERRY_ERROR_MESSAGES=${JERRY_ERROR_MESSAGES}
    -DJERRY_CMDLINE=OFF
    -DCMAKE_C_COMPILER_WORKS=true # cross-compiler
    -DCMAKE_SYSTEM_NAME=esp-idf
    -DCMAKE_SYSTEM_PROCESSOR=xtensa
    -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
    -DEXTERNAL_COMPILE_FLAGS=${EXTERNAL_COMPILE_FLAGS_ALT_SEP}
    -DCMAKE_EXE_LINKER_FLAGS=${CMAKE_EXE_LINKER_FLAGS}
    -DCMAKE_LINKER=${CMAKE_LINKER}
    -DCMAKE_AR=${CMAKE_AR}
    -DCMAKE_NM=${CMAKE_NM}
    -DCMAKE_RANLIB=${CMAKE_RANLIB}
    -DCMAKE_FIND_ROOT_PATH_MODE_PROGRAM=NEVER
)
add_dependencies(${COMPONENT_LIB} jerryscript_build)

add_library(jerry-core STATIC IMPORTED)
add_library(jerry-ext STATIC IMPORTED)
add_library(jerry-port STATIC IMPORTED)

set_target_properties(jerry-core PROPERTIES IMPORTED_LOCATION "${JERRY_BUILD_DIR}/lib/libjerry-core.a")
set_target_properties(jerry-ext PROPERTIES IMPORTED_LOCATION "${JERRY_BUILD_DIR}/lib/libjerry-ext.a")
set_target_properties(jerry-port PROPERTIES IMPORTED_LOCATION "${JERRY_BUILD_DIR}/lib/libjerry-port.a")

# jerry-core has espressif/main/jerry-port.c as dependency
target_link_libraries(jerry-core INTERFACE ${COMPONENT_LIB})
# jerry-main has jerry-core, jerry-ext, jerry-port as dependencies
target_link_libraries(${COMPONENT_LIB} INTERFACE jerry-core jerry-ext jerry-port)
