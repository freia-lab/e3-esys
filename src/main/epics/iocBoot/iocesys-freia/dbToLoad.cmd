#############################################
## DB loading                              ##
#############################################

cd "$(TOP)/db"

dbLoadRecords("snmp-freia.db","DEV=HPRF-Esys,HOST=$(CCU_IPADDR),CHAN=0,GROUP=0")
dbLoadTemplate("esys-freia.substitutions")

# IOC monitor
cd "$(EPICS_MODULES)/iocmon/db"
# The macro CTRLTYPE identifies the controller; P for (PLC), H for PSH and F for PCF and S for SERVER
# The macro IDX is the controller's index
# The macro IOCTYPE is IOCtype; CORE, SYSM, PLC
# Uncomment below statement if iocmon feature is required and substitue XXXX with proper values
#dbLoadRecords("iocmon.db","CBS1=XXXX, CBS2=XXXX, CTRLTYPE=X, IDX=X, IOCTYPE=XXXX")
