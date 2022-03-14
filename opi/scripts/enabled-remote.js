importPackage(Packages.org.csstudio.opibuilder.scriptUtil); 
var pv0 = PVUtil.getDouble(pvs[0]);
if(pv0==1)
	widget.setPropertyValue("enabled",false);
else
	widget.setPropertyValue("enabled",true);
