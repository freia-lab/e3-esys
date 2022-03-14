# This should be a test or example startup script

require esys

epicsEnvSet ("IOCNAME", "ioc05-esys")

iocshLoad("$(esys_DIR)/esys.iocsh", "CCU_IP=192.168.4.40, TOP=/opt/epics/autosave, IOCNAME=$(IOCNAME)")
