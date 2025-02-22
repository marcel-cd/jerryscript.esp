#  SPDX-FileCopyrightText: Copyright 2025 Clever Design (Switzerland) GmbH
#  SPDX-License-Identifier: MIT

## Select the target to build (esp32 / esp32s3 / exp32c6 / ....)
TARGET := esp32s3

# import settings for the used ESP-IDF
include ../make/makefile-54.mk

# targets
# ---------------------------------------------------------------------------
.PHONY: cmake all build flash clean

build: ## (re)compile for the selected TARGET
	${IDFPY} -DIDF_TARGET=${TARGET} build size -l

flash: build ## Flash the firmware to ESP32
	${IDFPY} flash

## Delete build directory and sdkconfig
clean:
	$(RMDIR) build && $(RM) sdkconfig
