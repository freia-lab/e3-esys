require snmp

epicsEnvSet("AUTOSAVE_SYSM_PV_PREFIX","esys:")
epicsEnvSet("MIBDIRS", "+$(REQUIRE_ioc_esys_freia_PATH)/misc")
epicsEnvSet("E", "ESSV900-1-6::")
epicsEnvSet("W", "SNMPv2-MIB::")
epicsEnvSet("N", "NOTIFICATION-LOG-MIB::")

epicsEnvSet("CCU_IPADDR", $(HOST_IPADDR))


requireSnippet(userPreDriverConf-esys-freia.cmd)
requireSnippet(dbToLoad-esys-freia.cmd, "H_IPADDR=$(HOST_IPADDR)")

#############################################
## IOC initialization                      ##
#############################################
iocInit

requireSnippet(userPostDriverConf-esys-freia.cmd)

