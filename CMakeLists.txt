# SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
# SPDX-License-Identifier: MIT
cmake_minimum_required(VERSION 3.16)


# Set JerryScript variables
set(JERRY_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/jerryscript")
set(JERRY_ERROR_MESSAGES ON)
set(JERRY_ATTR_GLOBAL_HEAP "-DJERRY_ATTR_GLOBAL_HEAP='__attribute__((section(\".ext_ram.bss\")))'")
set(JERRY_BUILD_DIR ${JERRY_ROOT_DIR}/build/jerry)
set(JERRY_INCLUDE_DIRS "${JERRY_ROOT_DIR}/jerry-ext/include" "${JERRY_ROOT_DIR}/jerry-core/include")
if (${CONFIG_JERRYSCRIPT_MALLOC_STRATEGY_SPIRAM})
    list(APPEND JERRY_COMPILE_FLAGS "${JERRY_ATTR_GLOBAL_HEAP}")
endif()
list(APPEND JERRY_COMPILE_FLAGS "${COMPILE_OPTIONS};${C_COMPILE_OPTIONS}")
# Make compile flags separated by spaces
string(REPLACE ";" " " JERRY_COMPILE_FLAGS "${JERRY_COMPILE_FLAGS}")

list(APPEND SOURCES "${JERRY_ROOT_DIR}/targets/baremetal-sdk/espressif/main/jerry-port.c")

idf_component_register(
    SRCS ${SOURCES}
    INCLUDE_DIRS ${JERRY_INCLUDE_DIRS}
)

idf_build_get_property(python PYTHON)
# Build JerryScript
execute_process(COMMAND ${python} ${JERRY_ROOT_DIR}/tools/build.py
  --clean
  --builddir=${JERRY_BUILD_DIR}
  --lto=OFF
  --jerry-cmdline=OFF
  --jerry-math=OFF
  --amalgam=ON
  --mem-heap=${CONFIG_JERRYSCRIPT_HEAP_SIZE}
  --profile=es.next
  --compile-flag=${JERRY_COMPILE_FLAGS}
  --toolchain=${CMAKE_TOOLCHAIN_FILE})


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
