#############################################
## DB loading                              ##
#############################################

dbLoadRecords("snmp-freia.db","DEV=HPRF-Esys,HOST=$(H_IPADDR),CHAN=0,GROUP=0")
#dbLoadTemplate("esys-freia.substitutions", "SNMP_IPADDR=$(HOST_IPADDR)")
#dbLoadRecords("esys-freia.db", "SNMP_IPADDR=$(HOST_IPADDR)")
dbLoadRecords("esys-freia.db")
