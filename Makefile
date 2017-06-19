EXCLUDE_ARCHS += eldk
#EXCLUDE_VERSIONS = 3.15.2

include ${EPICS_ENV_PATH}/module.Makefile

PROJECT = ioc_esys_freia

#EPICSVERSION = 3.14.15.2
#EPICS_VERSION = 3.14.15.2

#HEADERS += $(wildcard src/main/epics/esys-freiaApp/src/*.h)
SOURCES += $(wildcard src/main/epics/esys-freiaApp/src/*.c)
SOURCES += $(wildcard src/main/epics/esys-freiaApp/src/*.cpp)


STARTUPS = $(wildcard src/main/ioc/*.cmd)


OPIS= boy

# The line below id the fix needed in environment <= 1.7.0
#vpath %.mib ../../src/main/epics/mibs

MISCS += $(wildcard src/main/epics/mibs/*.mib)

