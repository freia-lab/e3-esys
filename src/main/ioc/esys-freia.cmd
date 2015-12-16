require snmp

epicsEnvSet("AUTOSAVE_SYSM_PV_PREFIX","esys:")
epicsEnvSet("MIBDIRS", "+$(REQUIRE_ioc-esys-freia_PATH)/misc")
epicsEnvSet("E", "ESSV900-1-6::")
epicsEnvSet("W", "SNMPv2-MIB::")
epicsEnvSet("N", "NOTIFICATION-LOG-MIB::")

requireSnippet(userPreDriverConf-esys-freia.cmd, "IP_ADDR=$(CCU_IPADDR)")
requireSnippet(dbToLoad-esys-freia.cmd, "HOST_IPADDR=$(CCU_IPADDR)")

#############################################
## IOC initialization                      ##
#############################################
iocInit

requireSnippet(userPostDriverConf-esys-freia.cmd)

