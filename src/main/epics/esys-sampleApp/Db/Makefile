TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#----------------------------------------------------
#  Optimization of db files using dbst (DEFAULT: NO)
#DB_OPT = YES

#----------------------------------------------------
# Create and install (or just install)
# databases, templates, substitutions like this
DB += snmp.db
DB += integer.template
DB += 3integer.template
DB += states.template
DB += states_MS.template
DB += sngl_statusbit.template
DB += write.template
DB += hlogtstamp.template
DB += hlogcode.template
DB += comstat.template
DB += txinput.substitutions

#----------------------------------------------------
# If <anyname>.db template is not named <anyname>*.template add
# <anyname>_TEMPLATE = <templatename>

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE
