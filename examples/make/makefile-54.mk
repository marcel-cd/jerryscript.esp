## PATH to your esp-idf 5.2.4 installation (e.g. ~/esp-idf/524/)
export IDF_PATH := $(HOME)/_dev/_lib/esp-idf_54
## PATH to the directory, used in install.sh (e.g. ~/.espressif)
export IDF_BUILD := $(HOME)/.espressif

export IDF_COMPILER_VERSION := 14.2.0_20241119
export IDF_PY := idf5.4_py3.13
export IDF_TOOLS_PATH := $(IDF_BUILD)
export IDF_PYTHON_ENV_PATH := $(IDF_TOOLS_PATH)/python_env/$(IDF_PY)_env
PATH := ${IDF_PATH}/tools:${IDF_PATH}/components/esptool_py/esptool:$(PATH)
PATH := ${IDF_PATH}/components/espcoredump:$(PATH)
PATH := ${IDF_PATH}:/components/partition_table:$(PATH)
PATH := ${IDF_PATH}/components/app_update:$(PATH)
PATH := ${IDF_BUILD}/tools/xtensa-esp-elf/esp-${IDF_COMPILER_VERSION}/xtensa-esp-elf/bin:$(PATH)
PATH := $(IDF_BUILD)/python_env/${IDF_PY}_env/bin:$(PATH)

IDFPY := ${IDF_PATH}/tools/idf.py

include ../make/makefile.mk
