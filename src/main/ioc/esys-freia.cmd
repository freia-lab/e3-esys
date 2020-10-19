require autosave,5.7+

epicsEnvSet("AUTOSAVE_SYSM_PV_PREFIX","esys:")
epicsEnvSet("MIBDIRS", "+$(REQUIRE_ioc_esys_freia_PATH)/misc")
epicsEnvSet("E", "ESSV900-1-6::")
epicsEnvSet("W", "SNMPv2-MIB::")
epicsEnvSet("N", "NOTIFICATION-LOG-MIB::")

epicsEnvSet("CCU_IPADDR", $(HOST_IPADDR))


requireSnippet(userPreDriverConf-esys-freia.cmd)
requireSnippet(dbToLoad-esys-freia.cmd, "H_IPADDR=$(HOST_IPADDR)")
requireSnippet(esys-freia-preSaveRestore.cmd)

#############################################
## IOC initialization                      ##
#############################################
iocInit

requireSnippet(esys-freia-postSaveRestore.cmd)
#requireSnippet(userPostDriverConf-esys-freia.cmd)

