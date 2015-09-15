importPackage(Packages.org.csstudio.opibuilder.scriptUtil); 
var pv0 = PVUtil.getDouble(pvs[0]);
var pv1 = PVUtil.getDouble(pvs[1]);
var sevr = PVUtil.getSeverityString(pvs[1]);
if((pv0==1)||(pv1==1)||(pv1==2)||(sevr=="MAJOR"))
	widget.setPropertyValue("enabled",false);
else
	widget.setPropertyValue("enabled",true);
