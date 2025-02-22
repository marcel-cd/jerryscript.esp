# SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
# SPDX-License-Identifier: MIT
cmake_minimum_required(VERSION 3.16)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(EXTRA_COMPONENT_DIRS ../..)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
# "Trim" the build. Include the minimal set of components, main, and anything it depends on.
idf_build_set_property(MINIMAL_BUILD ON)
project(hello_world)
