###################################################################
## User provided PLC or fast controller driver pre configuration ##
###################################################################

devSnmpSetSnmpVersion($(CCU_IPADDR),SNMP_VERSION_1)

devSnmpSetMaxOidsPerReq($(CCU_IPADDR),50)
devSnmpSetParam(MaxOidCompFailures, 0)
devSnmpSetParam(DoNotPollWeight, 100)
devSnmpSetParam(SetSkipReadbackMSec, 8000)
devSnmpSetParam(SessionTimeout, 15000000)


#devSnmpSetParam("DebugLevel",10)
