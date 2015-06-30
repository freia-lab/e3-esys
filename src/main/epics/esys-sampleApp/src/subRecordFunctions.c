#include <stdio.h>
#include <string.h>

#include <dbDefs.h>
#include <registryFunction.h>
#include <subRecord.h>
#include <aSubRecord.h>
#include <epicsExport.h>

int mySubDebug;

typedef  struct {
  int code;
  int type;
  int psid;
} AlarmLkupTable; 

#define DESCR_TABLE_SIZE	241
#define MAX_MODULES 		7
#define MODX_ALARM_TABLE_SIZE	60
#define MOD0_ALARM_TABLE_SIZE	140
#define _LOG_ALM		1
#define _LOG_SET		2


static  epicsOldString AlarmsDescription[DESCR_TABLE_SIZE] =
{

/********************************************/
/* Table fields                             */
/********************************************/
/* SID      DESCR                           */
/********************************************/

/* 000 */  "Error : index out of range\0     ",
/* 001 */  "HV Alarm\0                       ",
/* 002 */  "HV Door Interlock Open\0         ",
/* 003 */  "HV Water Flow Alarm\0            ",
/* 004 */  "HV Air Temperature Alarm\0       ",
/* 005 */  "Heat Exchanger 1 Alarm\0         ",
/* 006 */  "Unbalance Load Water Flow Alarm\0",
/* 007 */  "Unbalance Load Power Alarm\0     ",
/* 008 */  "Crowbar Fired\0                  ",
/* 009 */  "Heat Exchanger 2 Alarm\0         ",
/* 010 */  "HPA1 : Filament Alarm\0          ",
/* 011 */  "HPA1 : VF Protection\0           ",
/* 012 */  "HPA1 : Control Grid Alarm\0      ",
/* 013 */  "HPA1 : Screen Grid Alarm\0       ",
/* 014 */  "HPA1 : Anode Alarm\0             ",
/* 015 */  "HPA1 : Water Flow Alarm\0        ",
/* 016 */  "HPA1 : Unb.Load Alarm\0          ",
/* 017 */  "HPA1 : Cooling Alarm\0           ",
/* 018 */  "HPA1 : HV Series Switch Alarm\0  ",
/* 019 */  "HPA1 : HV Ext.Interlock Open\0   ",
/* 020 */  "HPA1 : RF Ext.Interlock Open\0   ",
/* 021 */  "HPA1 : Cavity Interlock Open\0   ",
/* 022 */  "HPA1 : Mains Voltage Alarm\0     ",
/* 023 */  "HPA1 : Mains Phase Alarm\0       ",
/* 024 */  "HPA1 : Reflected Power Alarm\0   ",
/* 025 */  "HPA1 : Rack Blower Alarm\0       ",
/* 026 */  "HPA1 : Anode Cooling Alarm\0     ",
/* 027 */  "HPA1 : Cooling Mains Overload\0  ",
/* 028 */  "HPA1 : Air Pressure Alarm\0      ",
/* 029 */  "HPA1 : Temperat.Detectors Alarm\0",
/* 030 */  "HPA1 : Water Flow Alarm\0        ",
/* 031 */  "HPA1 : Delayed Water Flow Alarm\0",
/* 032 */  "HPA1 : Anode In Wat.Temp.Alarm\0 ",
/* 033 */  "HPA1 : Anode Out Wat.Temp Alarm\0",
/* 034 */  "HPA1 : Water Pressure Alarm\0    ",
/* 035 */  "HPA1 : Water Conductivity Alarm\0",
/* 036 */  "HPA1 : Water Conductiv.Warning\0 ",
/* 037 */  "HPA1 : Filament Overvoltage\0    ",
/* 038 */  "HPA1 : Control Grid Temp.Max\0   ",
/* 039 */  "HPA1 : Control Grid Overcurrent\0",
/* 040 */  "HPA1 : Screen Grid Power Alarm\0 ",
/* 041 */  "HPA1 : Screen Grid Overcurrent\0 ",
/* 042 */  "HPA1 : Screen Grid Arc Detected\0",
/* 043 */  "HPA1 : Anode Peak Current Alarm\0",
/* 044 */  "HPA1 : Anode dV/dT Alarm\0       ",
/* 045 */  "HPA1 : Anode Overvoltage\0       ",
/* 046 */  "HPA1 : Anode AVG Power High\0    ",
/* 047 */  "HPA1 : Filament Cooling Alarm\0  ",
/* 048 */  "HPA1 : Control Grid Pulse Lack\0 ",
/* 049 */  "\0                               ",
/* 050 */  "--- SYSTEM START ---\0           ",
/* 051 */  "--- SYSTEM  STOP ---\0           ",
/* 052 */  "Operation Mode Local\0           ",
/* 053 */  "Operation Mode Remote\0          ",
/* 054 */  "Reset System Latched Alarms\0    ",
/* 055 */  "System StandBy\0                 ",
/* 056 */  "System PowerOn\0                 ",
/* 057 */  "Reset HPA1 Latched Alarms\0      ",
/* 058 */  "HPA1 StandBy\0                   ",
/* 059 */  "HPA1 PowerOn\0                   ",
/* 060 */  "HPA1 Start\0                     ",
/* 061 */  "HPA1 Stop\0                      ",
/* 062 */  "Reset HPA2 Latched Alarms\0      ",
/* 063 */  "HPA2 StandBy\0                   ",
/* 064 */  "HPA2 PowerOn\0                   ",
/* 065 */  "--- RESET HISTORY LOG --- \0     ",
/* 066 */  "--- CCU SWITCH ON ---\0          ",
/* 067 */  "HPA2 Start\0                     ",
/* 068 */  "HPA2 Stop\0                      ",
/* 069 */  "HPA1 Settings were Stored\0      ",
/* 070 */  "HPA2 Settings were Stored\0      ",
/* 071 */  "HV Settings were Stored\0        ",
/* 072 */  "HPA1 Settings were Changed\0     ",
/* 073 */  "HPA2 Settings were Changed\0     ",
/* 074 */  "HV Settings were Changed\0       ",
/* 075 */  "\0                               ",
/* 076 */  "Crowbar Reset\0                  ",
/* 077 */  "Reset Default TCP-IP Settings\0  ",
/* 078 */  "Wattmeter Settings were Changed\0",
/* 079 */  "RTC Settings were Changed\0      ",
/* 080 */  "HPA1: PIB1 CAN Bus Disconnected\0",
/* 081 */  "HPA2: PIB2 CAN Bus Disconnected\0",
/* 082 */  "HVCS: PIB3 CAN Bus Disconnected\0",
/* 083 */  "\0                               ",
/* 084 */  "\0                               ",
/* 085 */  "\0                               ",
/* 086 */  "\0                               ",
/* 087 */  "\0                               ",
/* 088 */  "\0                               ",
/* 089 */  "\0                               ",
/* 090 */  "DRV1: Mod1 CAN Bus Disconnected\0",
/* 091 */  "DRV1: Mod2 CAN Bus Disconnected\0",
/* 092 */  "DRV1: Mod3 CAN Bus Disconnected\0",
/* 093 */  "DRV2: Mod1 CAN Bus Disconnected\0",
/* 094 */  "DRV2: Mod2 CAN Bus Disconnected\0",
/* 095 */  "DRV2: Mod3 CAN Bus Disconnected\0",
/* 096 */  "\0                               ",
/* 097 */  "\0                               ",
/* 098 */  "\0                               ",
/* 099 */  "\0                               ",
/* 100 */  "\0                               ",
/* 101 */  "\0                               ",
/* 102 */  "\0                               ",
/* 103 */  "\0                               ",
/* 104 */  "\0                               ",
/* 105 */  "\0                               ",
/* 106 */  "\0                               ",
/* 107 */  "\0                               ",
/* 108 */  "\0                               ",
/* 109 */  "\0                               ",
/* 110 */  "\0                               ",
/* 111 */  "\0                               ",
/* 112 */  "\0                               ",
/* 113 */  "\0                               ",
/* 114 */  "\0                               ",
/* 115 */  "\0                               ",
/* 116 */  "\0                               ",
/* 117 */  "\0                               ",
/* 118 */  "\0                               ",
/* 119 */  "\0                               ",
/* 120 */  "\0                               ",
/* 121 */  "\0                               ",
/* 122 */  "\0                               ",
/* 123 */  "\0                               ",
/* 124 */  "\0                               ",
/* 125 */  "\0                               ",
/* 126 */  "\0                               ",
/* 127 */  "\0                               ",
/* 128 */  "\0                               ",
/* 129 */  "\0                               ",
/* 130 */  "VSWR Alarm\0                     ",
/* 131 */  "Overdrive\0                      ",
/* 132 */  "Power Supply 1 Fault\0           ",
/* 133 */  "Power Supply 1 Temp. Fault\0     ",
/* 134 */  "Power Supply 1 Crowbar Fault\0   ",
/* 135 */  "Power Supply 2 Fault\0           ",
/* 136 */  "Power Supply 2 Temp. Fault\0     ",
/* 137 */  "Power Supply 2 Crowbar Fault\0   ",
/* 138 */  "Power Supply 3 Fault\0           ",
/* 139 */  "Power Supply 3 Temp. Fault\0     ",
/* 140 */  "Power Supply 3 Crowbar Fault\0   ",
/* 141 */  "High In Water Temperature\0      ",
/* 142 */  "High Out Water Temperature\0     ",
/* 143 */  "Module TripLockOut\0             ",
/* 144 */  "Humidity Alarm\0                 ",
/* 145 */  "\0                               ",
/* 146 */  "\0                               ",
/* 147 */  "\0                               ",
/* 148 */  "\0                               ",
/* 149 */  "\0                               ",
/* 150 */  "\0                               ",
/* 151 */  "\0                               ",
/* 152 */  "\0                               ",
/* 153 */  "\0                               ",
/* 154 */  "\0                               ",
/* 155 */  "\0                               ",
/* 156 */  "\0                               ",
/* 157 */  "\0                               ",
/* 158 */  "\0                               ",
/* 159 */  "\0                               ",
/* 160 */  "Predriver Warning\0              ",
/* 161 */  "Predriver I Max\0                ",
/* 162 */  "Predriver Alarm\0                ",
/* 163 */  "Driver 1 Warning\0               ",
/* 164 */  "Driver 1, I Max\0                ",
/* 165 */  "Driver 1 Alarm\0                 ",
/* 166 */  "Driver 2 Warning\0               ",
/* 167 */  "Driver 2 I Max\0                 ",
/* 168 */  "Driver 2 Alarm\0                 ",
/* 169 */  "Final 1 Warning\0                ",
/* 170 */  "Final 1 I Max\0                  ",
/* 171 */  "Final 1 Alarm\0                  ",
/* 172 */  "Final 2 Warning\0                ",
/* 173 */  "Final 2 I Max\0                  ",
/* 174 */  "Final 2 Alarm\0                  ",
/* 175 */  "Final 3 Warning\0                ",
/* 176 */  "Final 3 I Max\0                  ",
/* 177 */  "Final 3 Alarm\0                  ",
/* 178 */  "Final 4 Warning\0                ",
/* 179 */  "Final 4 I Max\0                  ",
/* 180 */  "Final 4 Alarm\0                  ",
/* 181 */  "\0                               ",
/* 182 */  "\0                               ",
/* 183 */  "\0                               ",
/* 184 */  "\0                               ",
/* 185 */  "\0                               ",
/* 186 */  "\0                               ",
/* 187 */  "\0                               ",
/* 188 */  "\0                               ",
/* 189 */  "\0                               ",
/* 190 */  "\0                               ",
/* 191 */  "\0                               ",
/* 192 */  "\0                               ",
/* 193 */  "\0                               ",
/* 194 */  "\0                               ",
/* 195 */  "\0                               ",
/* 196 */  "\0                               ",
/* 197 */  "\0                               ",
/* 198 */  "\0                               ",
/* 199 */  "\0                               ",
/* 200 */  "HPA2 : Filament Alarm\0          ",
/* 201 */  "HPA2 : VF Protection\0           ",
/* 202 */  "HPA2 : Control Grid Alarm\0      ",
/* 203 */  "HPA2 : Screen Grid Alarm\0       ",
/* 204 */  "HPA2 : Anode Alarm\0             ",
/* 205 */  "HPA2 : Water Flow Alarm\0        ",
/* 206 */  "HPA2 : Unb.Load Alarm\0          ",
/* 207 */  "HPA2 : Cooling Alarm\0           ",
/* 208 */  "HPA2 : HV Series Switch Alarm\0  ",
/* 209 */  "HPA2 : HV Ext.Interlock Open\0   ",
/* 210 */  "HPA2 : RF Ext.Interlock Open\0   ",
/* 211 */  "HPA2 : Cavity Interlock Open\0   ",
/* 212 */  "HPA2 : Mains Voltage Alarm\0     ",
/* 213 */  "HPA2 : Mains Phase Alarm\0       ",
/* 214 */  "HPA2 : Reflected Power Alarm\0   ",
/* 215 */  "HPA2 : Rack Blower Alarm\0       ",
/* 216 */  "HPA2 : Anode Cooling Alarm\0     ",
/* 217 */  "HPA2 : Cooling Mains Overload\0  ",
/* 218 */  "HPA2 : Air Pressure Alarm\0      ",
/* 219 */  "HPA2 : Temperat.Detectors Alarm\0",
/* 220 */  "HPA2 : Water Flow Alarm\0        ",
/* 221 */  "HPA2 : Delayed Water Flow Alarm\0",
/* 222 */  "HPA2 : Anode In Wat.Temp.Alarm\0 ",
/* 223 */  "HPA2 : Anode Out Wat.Temp Alarm\0",
/* 224 */  "HPA2 : Water Pressure Alarm\0    ",
/* 225 */  "HPA2 : Water Conductivity Alarm\0",
/* 226 */  "HPA2 : Water Conductiv.Warning\0 ",
/* 227 */  "HPA2 : Filament Overvoltage\0    ",
/* 228 */  "HPA2 : Control Grid Temp.Max\0   ",
/* 229 */  "HPA2 : Control Grid Overcurrent\0",
/* 230 */  "HPA2 : Screen Grid Power Alarm\0 ",
/* 231 */  "HPA2 : Screen Grid Overcurrent\0 ",
/* 232 */  "HPA2 : Screen Grid Arc Detected\0",
/* 233 */  "HPA2 : Anode Peak Current Alarm\0",
/* 234 */  "HPA2 : Anode dV/dT Alarm\0       ",
/* 235 */  "HPA2 : Anode Overvoltage\0       ",
/* 236 */  "HPA2 : Anode AVG Power High\0    ",
/* 237 */  "HPA2 : Filament Cooling Alarm\0  ",
/* 238 */  "HPA2 : Control Grid Pulse Lack\0 ",
/* 239 */  "\0                               ",
/* 240 */  "\0                               ",
};


 AlarmLkupTable ModX_AlarmTable[MODX_ALARM_TABLE_SIZE] =
{

/*******************************************************************/
/* Table fields                                                    */
/*******************************************************************/
/* ModX_ID  CODE    TYPE	PSID   */
/*******************************************************************/

  /*000*/ {     0,     _LOG_ALM,       0 },  /* */
  /*001*/ {     1,     _LOG_ALM,      130}, /* vswr */
  /*002*/ {     2,     _LOG_ALM,      131 }, /* overdrive */
  /*003*/ {     3,     _LOG_ALM,      132 }, /* ps1 alm */
  /*004*/ {     4,     _LOG_ALM,      133 },    /* ps1 temp */
/*005*/ {     5,     _LOG_ALM,      134 },    /* ps1 cb */
/*006*/ {     6,     _LOG_ALM,      135 },    /* ps2 alm */
/*007*/ {     7,     _LOG_ALM,      136 },    /* ps2 temp */
/*008*/ {     8,     _LOG_ALM,      137 },    /* ps2 cb */
/*009*/ {     9,     _LOG_ALM,      138 },   /* ps3 alm */
/*010*/ {    10,     _LOG_ALM,      139 },   /* ps3 temp */
/*011*/ {    11,     _LOG_ALM,      140 },   /* ps3 cb */
/*012*/ {    12,     _LOG_ALM,      141 },    /* in  W.Temp */
/*013*/ {    13,     _LOG_ALM,      142 },    /* out W.Temp */
/*014*/ {    14,     _LOG_ALM,      143 },    /* hpa trip */
/*015*/ {    15,     _LOG_ALM,      144 },    /* hum */
/*016*/ {     0,     0,      	  0 },    /* nu */
  /*017*/ {     0,     0,   	0 }, /* nu */
  /*018*/ {     0,     0,   	0 }, /* nu */
  /*019*/ {     0,     0,   	0 }, /* nu */
  /*020*/ {    20,     _LOG_ALM,      160 },    /* pdrv 1t */
/*021*/ {    21,     _LOG_ALM,      161 },    /* pdrv imax */
/*022*/ {    22,     _LOG_ALM,      162 },    /* pdrv 2t */
/*023*/ {    23,     _LOG_ALM,      163 },    /* drv1 1t */
/*024*/ {    24,     _LOG_ALM,      164 },    /* drv1 imax */
/*025*/ {    25,     _LOG_ALM,      165 },    /* drv1 2t */
/*026*/ {    26,     _LOG_ALM,      166 },    /* drv2 1t */
/*027*/ {    27,     _LOG_ALM,      167 },    /* drv2 imax */
/*028*/ {    28,     _LOG_ALM,      168 },    /* drv2 2t */
/*029*/ {    29,     _LOG_ALM,      169 },    /* fn1 1t */
/*030*/ {    30,     _LOG_ALM,      170 },    /* fn1 imax */
/*031*/ {    31,     _LOG_ALM,      171 },    /* fn1 2t */
/*032*/ {    32,     _LOG_ALM,      172 },    /* fn2 1t */
/*033*/ {    33,     _LOG_ALM,      173 },    /* fn2 imax */
/*034*/ {    34,     _LOG_ALM,      174 },    /* fn2 2t */
/*035*/ {    35,     _LOG_ALM,      175 },    /* fn3 1t */
/*036*/ {    36,     _LOG_ALM,      176 },    /* fn3 imax */
/*037*/ {    37,     _LOG_ALM,      177 },    /* fn3 2t */
/*038*/ {    38,     _LOG_ALM,      178 },    /* fn4 1t */
/*039*/ {    39,     _LOG_ALM,      179 },    /* fn4 imax */
/*040*/ {    40,     _LOG_ALM,      180 },    /* fn4 2t */
/*041*/ {     0,            0,      0 },    /* nu */
/*042*/ {     0,            0,      0 },    /* nu */
/*043*/ {     0,            0,      0 },    /* nu */
/*044*/ {     0,            0,      0 },    /* nu */
/*045*/ {     0,            0,      0 },    /* nu */
/*046*/ {     0,            0,      0 },    /* nu */
/*047*/ {     0,            0,      0 },    /* nu */
/*048*/ {     0,            0,      0 },    /* nu */
/*049*/ {     0,            0,      0 },    /* nu */
/*050*/ {     0,            0,      0 },    /* nu */
/*051*/ {     0,            0,      0 },    /* nu */
/*052*/ {     0,            0,      0 },    /* nu */
/*053*/ {     0,            0,      0 },    /* nu */
/*054*/ {     0,            0,      0 },    /* nu */
/*055*/ {     0,            0,      0 },    /* nu */
/*056*/ {     0,            0,      0 },    /* nu */
/*057*/ {     0,            0,      0 },    /* nu */
/*058*/ {     0,            0,      0 },    /* nu */
/*059*/ {     0,            0,      0 }    /* nu */
};

AlarmLkupTable Mod0_AlarmTable[MOD0_ALARM_TABLE_SIZE] =
{
/*******************************************************************/
/* Table fields                                                    */
/*******************************************************************/
/* Mod0_ID  CODE       TYPE      PSID    N.U....    */
/*******************************************************************/

/*000*/ {     0,            0,      0 },
/*001*/ {     1,     _LOG_SET,      66 },/* ccu switch on */
/*002*/ {     2,     _LOG_SET,      65 },/* reset history  */
/*003*/ {     0,            0,      0 },/* nu */
/*004*/ {     0,            0,      0 },/* nu */
/*005*/ {     0,            0,      0 },/* nu */
/*006*/ {     0,            0,      0 },/* nu */
/*007*/ {     7,     _LOG_SET,      50 },/* start */
/*008*/ {     8,     _LOG_SET,      51 },/* stop */
/*009*/ {     9,     _LOG_SET,      52 },/* loc */
/*010*/ {    10,     _LOG_SET,      53 },/* rem */
/*011*/ {    11,     _LOG_SET,      54 },/* reset flipflop sys */
/*012*/ {    12,     _LOG_SET,      55 },/* stdby sys */
/*013*/ {    13,     _LOG_SET,      56 },/* pwron sys */
/*014*/ {    14,     _LOG_SET,      57 },/* reset flipflop pa1 */
/*015*/ {    15,     _LOG_SET,      58 },/* stdby pa1 */
/*016*/ {   16,     _LOG_SET,      59 },/* pwron pa1 */
/*017*/ {   17,     _LOG_SET,      60 },/* start pa1 */
/*018*/ {   18,     _LOG_SET,      61 },/* stop  pa1 */
/*019*/ {   19,     _LOG_SET,      62 },/* reset flipflop pa2 */
/*020*/ {   20,     _LOG_SET,      63 },/* stdby pa2 */
/*021*/ {   21,     _LOG_SET,      64 },/* pwron pa2 */
/*022*/ {   22,     _LOG_SET,      67 },/* start pa2 */
/*023*/ {   23,     _LOG_SET,      68 },/* stop  pa2 */
/*024*/ {   24,     _LOG_SET,      69 },/* pa1 settings stored */
/*025*/ {   25,     _LOG_SET,      70 },/* pa2 settings stored */
/*026*/ {   26,     _LOG_SET,      71 },/* hv  settings stored */
/*027*/ {   27,     _LOG_SET,      72 },/* pa1 settings changed */
/*028*/ {   28,     _LOG_SET,      73 },/* pa2 settings changed */
/*029*/ {   29,     _LOG_SET,      74 },/* hv  settings changed */
/*030*/ {   30,     _LOG_ALM,      80 },/* pib comm */
/*031*/ {   31,     _LOG_ALM,      81 },/* pib comm */
/*032*/ {   32,     _LOG_ALM,      82 },/* pib comm */
/*033*/ {    0,            0,       0 },/* nu */
/*034*/ {    0,            0,       0 },/* nu */
/*035*/ {    0,            0,       0 },/* nu */
/*036*/ {   36,     _LOG_SET,      76 },/* crowbar reset */
/*037*/ {   37,     _LOG_SET,      77 },/* IP default */
/*038*/ {   38,     _LOG_SET,      78 },/* wattmeter change */
/*039*/ {   39,     _LOG_SET,      79 },/* RTC change */
/*040*/ {   40,     _LOG_ALM,      90 },/* pa comm */
/*041*/ {   41,     _LOG_ALM,      91 },/* pa comm */
/*042*/ {   42,     _LOG_ALM,      92 },/* pa comm */
/*043*/ {   43,     _LOG_ALM,      93 },/* pa comm */
/*044*/ {   44,     _LOG_ALM,      94 },/* pa comm */
/*045*/ {   45,     _LOG_ALM,      95 },/* pa comm */
/*046*/ {    0,            0,       0 },/* nu */
/*047*/ {    0,            0,       0 },/* nu */
/*048*/ {   48,     _LOG_ALM,      1 },/* HV ALARM */
/*049*/ {   49,     _LOG_ALM,      2 },/* HV DOOR INTERLOCK OPEN */
/*050*/ {   50,     _LOG_ALM,      3 },/* HV WATER FLOW ALARM */
/*051*/ {   51,     _LOG_ALM,      4 },/* HV AIR TEMPERATURE ALARM */
/*052*/ {   52,     _LOG_ALM,      5 },/* HEAT EXCHANGER 1 ALARM */
/*053*/ {   53,     _LOG_ALM,      6 },/* UNBALACE LOAD WATER FLOW ALARM */
/*054*/ {   54,     _LOG_ALM,      7 },/* UNBALACE LOAD POWER ALARM */
/*055*/ {   55,     _LOG_ALM,      8 },/* CROWBAR FIRED */
/*056*/ {   56,     _LOG_ALM,      9 },/* HEAT EXCHANGER 2 ALARM */
/*057*/ {    0,            0,      0 },/* nu */
/*058*/ {    0,            0,      0 },/* nu */
/*059*/ {    0,            0,      0 },/* nu */
/*060*/ {   60,     _LOG_ALM,      10 },/* HPA1 : Filament Alarm */
/*061*/ {   61,     _LOG_ALM,      11 },/* HPA1 : VF Protection */
/*062*/ {   62,     _LOG_ALM,      12 },/* HPA1 : Control Grid Alarm */
/*063*/ {   63,     _LOG_ALM,      13 },/* HPA1 : Screen Grid Alarm */
/*064*/ {   64,     _LOG_ALM,      14 },/* HPA1 : Anode Alarm */
/*065*/ {   65,     _LOG_ALM,      15 },/* HPA1 : Water Flow Alarm */
/*066*/ {   66,     _LOG_ALM,      16 },/* HPA1 : Unb.Load Alarm */
/*067*/ {   67,     _LOG_ALM,      17 },/* HPA1 : Cooling Alarm */
/*068*/ {   68,     _LOG_ALM,      18 },/* HPA1 : HV Series Switch Alarm */
/*069*/ {   69,     _LOG_ALM,      19 },/* HPA1 : HV External Interlock Open */
/*070*/ {   70,     _LOG_ALM,      20 },/* HPA1 : RF External Interlock Open */
/*071*/ {   71,     _LOG_ALM,      21 },/* HPA1 : Cavity Interlock Open */
/*072*/ {   72,     _LOG_ALM,      22 },/* HPA1 : Mains Voltage Alarm */
/*073*/ {   73,     _LOG_ALM,      23 },/* HPA1 : Mains Phase Alarm */
/*074*/ {   74,     _LOG_ALM,      24 },/* HPA1 : Reflected Power Alarm */
/*075*/ {   75,     _LOG_ALM,      25 },/* HPA1 : Rack Blower Alarm */
/*076*/ {   76,     _LOG_ALM,      26 },/* HPA1 : Anode Cooling Alarm */
/*077*/ {   77,     _LOG_ALM,      27 },/* HPA1 : Cooling Mains Overload */
/*078*/ {   78,     _LOG_ALM,      28 },/* HPA1 : Air Pressure Alarm */
/*079*/ {   79,     _LOG_ALM,      29 },/* HPA1 : Temperature Detectors Alarm */
/*080*/ {   80,     _LOG_ALM,      30 },/* HPA1 : Water Flow Alarm */
/*081*/ {   81,     _LOG_ALM,      31 },/* HPA1 : Delayed Water Flow Alarm */
/*082*/ {   82,     _LOG_ALM,      32 },/* HPA1 : Anode In Water Temperature Alarm */
/*083*/ {   83,     _LOG_ALM,      33 },/* HPA1 : Anode Out Water Temperature Alarm */
/*084*/ {   84,     _LOG_ALM,      34 },/* HPA1 : Water Pressure Alarm */
/*085*/ {   85,     _LOG_ALM,      35 },/* HPA1 : Water Conductivity Alarm */
/*086*/ {   86,     _LOG_ALM,      36 },/* HPA1 : Water Conductivity Warning */
/*087*/ {   87,     _LOG_ALM,      37 },/* HPA1 : Filament Overvoltage */
/*088*/ {   88,     _LOG_ALM,      38 },/* HPA1 : Control Grid Temperature Max */
/*089*/ {   89,     _LOG_ALM,      39 },/* HPA1 : Control Grid Overcurrent */
/*090*/ {   90,     _LOG_ALM,      40 },/* HPA1 : Screen Grid Power Alarm */
/*091*/ {   91,     _LOG_ALM,      41 },/* HPA1 : Screen Grid Overcurrent */
/*092*/ {   92,     _LOG_ALM,      42 },/* HPA1 : Screen Grid Arc Detected */
/*093*/ {   93,     _LOG_ALM,      43 },/* HPA1 : Anode Peak Current Alarm */
/*094*/ {   94,     _LOG_ALM,      44 },/* HPA1 : Anode dV/dT Alarm */
/*095*/ {   95,     _LOG_ALM,      45 },/* HPA1 : Anode Overvoltage */
/*096*/ {   96,     _LOG_ALM,      46 },/* HPA1 : Anode AVG Power High */
/*097*/ {   97,     _LOG_ALM,      47 },/* HPA1 : Filament Cooling Alarm */
/*098*/ {   98,     _LOG_ALM,      48 },/* HPA1 : Control Grid Pulse Lack */
/*099*/ {    0,            0,       0 },/* nu */
/*100*/ {  100,     _LOG_ALM,     200 },/* HPA2 : Filament Alarm */
/*101*/ {  101,     _LOG_ALM,     201 },/* HPA2 : VF Protection */
/*102*/ {  102,     _LOG_ALM,     202 },/* HPA2 : Control Grid Alarm */
/*103*/ {  103,     _LOG_ALM,     203 },/* HPA2 : Screen Grid Alarm */
/*104*/ {  104,     _LOG_ALM,     204 },/* HPA2 : Anode Alarm */
/*105*/ {  105,     _LOG_ALM,     205 },/* HPA2 : Water Flow Alarm */
/*106*/ {  106,     _LOG_ALM,     206 },/* HPA2 : Unb.Load Alarm */
/*107*/ {  107,     _LOG_ALM,     207 },/* HPA2 : Cooling Alarm */
/*108*/ {  108,     _LOG_ALM,     208 },/* HPA2 : HV Series Switch Alarm */
/*109*/ {  109,     _LOG_ALM,     209 },/* HPA2 : HV External Interlock Open */
/*110*/ {  110,     _LOG_ALM,     210 },/* HPA2 : RF External Interlock Open */
/*111*/ {  111,     _LOG_ALM,     211 },/* HPA2 : Cavity Interlock Open */
/*112*/ {  112,     _LOG_ALM,     212 },/* HPA2 : Mains Voltage Alarm */
/*113*/ {  113,     _LOG_ALM,     213 },/* HPA2 : Mains Phase Alarm */
/*114*/ {  114,     _LOG_ALM,     214 },/* HPA2 : Reflected Power Alarm */
/*115*/ {  115,     _LOG_ALM,     215 },/* HPA2 : Rack Blower Alarm */
/*116*/ {  116,     _LOG_ALM,     216 },/* HPA2 : Anode Cooling Alarm */
/*117*/ {  117,     _LOG_ALM,     217 },/* HPA2 : Cooling Mains Overload */
/*118*/ {  118,     _LOG_ALM,     218 },/* HPA2 : Air Pressure Alarm */
/*119*/ {  119,     _LOG_ALM,     219 },/* HPA2 : Temperature Detectors Alarm */
/*120*/ {  120,     _LOG_ALM,     220 },/* HPA2 : Water Flow Alarm */
/*121*/ {  121,     _LOG_ALM,     221 },/* HPA2 : Delayed Water Flow Alarm */
/*122*/ {  122,     _LOG_ALM,     222 },/* HPA2 : Anode In Water Temperature Alarm */
/*123*/ {  123,     _LOG_ALM,     223 },/* HPA2 : Anode Out Water Temperature Alarm */
/*124*/ {  124,     _LOG_ALM,     224 },/* HPA2 : Water Pressure Alarm */
/*125*/ {  125,     _LOG_ALM,     225 },/* HPA2 : Water Conductivity Alarm */
/*126*/ {  126,     _LOG_ALM,     226 },/* HPA2 : Water Conductivity Warning */
/*127*/ {  127,     _LOG_ALM,     227 },/* HPA2 : Filament Overvoltage */
/*128*/ {  128,     _LOG_ALM,     228 },/* HPA2 : Control Grid Temperature Max */
/*129*/ {  129,     _LOG_ALM,     229 },/* HPA2 : Control Grid Overcurrent */
/*130*/ {  130,     _LOG_ALM,     230 },/* HPA2 : Screen Grid Power Alarm */
/*131*/ {  131,     _LOG_ALM,     231 },/* HPA2 : Screen Grid Overcurrent */
/*132*/ {  132,     _LOG_ALM,     232 },/* HPA2 : Screen Grid Arc Detected */
/*133*/ {  133,     _LOG_ALM,     233 },/* HPA2 : Anode Peak Current Alarm */
/*134*/ {  134,     _LOG_ALM,     234 },/* HPA2 : Anode dV/dT Alarm */
/*135*/ {  135,     _LOG_ALM,     235 },/* HPA2 : Anode Overvoltage */
/*136*/ {  136,     _LOG_ALM,     236 },/* HPA2 : Anode AVG Power High */
/*137*/ {  137,     _LOG_ALM,     237 },/* HPA2 : Filament Cooling Alarm */
/*138*/ {  138,     _LOG_ALM,     238 },/* HPA2 : Control Grid Pulse Lack */
/*139*/ {    0,            0,     0 } /* nu */
};



static long mysubInit(struct subRecord *psub)
{
    printf("subInit was called\n");
    return(0);
}
 
static long mysubProcess(struct subRecord *psub)
{
    psub->val++;
    return(0);
}

static long myAsubInit(aSubRecord *precord)
{
    if (mySubDebug)
        printf("Record %s called myAsubInit(%p)\n",
               precord->name, (void*) precord);
    return 0;
}

static long myAsubProcess(aSubRecord *precord)
{
  epicsOldString outs;
  int m, d, y, hh, mm, ss;
  unsigned long l;
  if (mySubDebug > 5) {
        printf("Record %s called myAsubProcess(%p)\n",
               precord->name, (void*) precord);
	printf ("Input: %lu\n", *((unsigned long *) precord->a));
  }
  l = *(unsigned long *) precord->a;
  if (l==0)  { 
    sprintf ((char *) outs, "Active");
  } else  { 
    ss = l & 0x0000003F;
    mm = (l & 0x00000FC0) >> 6;
    hh = (l & 0x0001F000) >> 12;
    y = 2000 + ((l & 0x007E0000) >> 17);
    m = (l & 0x07800000) >> 23;
    d = (l & 0xF8000000) >> 27;
    sprintf ((char *) outs, "%d-%02d-%02d %02d:%02d:%02d", y, m, d, hh, mm, ss);
  } 

  strncpy ((char *) precord->vala, outs, 40);
  if (mySubDebug > 4) {  
    printf ("Output: %s p->vala: %p: %s\n", outs, (void*) (precord->vala), (char *)  precord->vala);
    printf ("Old output: %s\n",  (char *)  precord->ovla);
  } 
    return 0;
}

static long code2msgInit(aSubRecord *precord)
{
    if (mySubDebug)
        printf("Record %s called code2msgInit(%p)\n",
               precord->name, (void*) precord);
    return 0;
}

static long code2msgProcess(aSubRecord *precord)
{
 int module, code, psid;
 unsigned long l;
  if (mySubDebug > 5) {
        printf("Record %s called code2msgProcess(%p)\n",
               precord->name, (void*) precord);
	printf ("Input: %lu\n", *((unsigned long *) precord->a));
  }
  l = *(unsigned long *) precord->a;
  module = (l & 0xFFFF0000) >> 16;
  code = l & 0xFFFF;

  switch (module) {
  case 0:
    if (code < MOD0_ALARM_TABLE_SIZE) {
      psid = Mod0_AlarmTable[code].psid;
      if (psid < DESCR_TABLE_SIZE)
	strncpy ((char *) precord->vala, AlarmsDescription[psid], 40);
      if (mySubDebug > 3) {
        printf("Record %s: module: %d; code: %d; psid: %d; message: %s (%s)\n",
               precord->name, module, code, psid, AlarmsDescription[psid], (char *) precord->vala);
      }
    }
    break;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
    if (code < MODX_ALARM_TABLE_SIZE) {
      psid = ModX_AlarmTable[code].psid;
      if (psid < DESCR_TABLE_SIZE)
	strncpy ((char *) precord->vala, AlarmsDescription[psid], 40);	
    }
   break;
 default:
   if (mySubDebug > 1) {
     printf ("code2msgProcess: Illegal module number: %d\n", module);
   }
  }

  if (mySubDebug > 5) {  
    printf ("Output: p->vala: %p: %s\n", (void*) (precord->vala), (char *)  precord->vala);
    printf ("Old output: %s\n",  (char *)  precord->ovla);
  } 
    return 0;
}

/* Register these symbols for use by IOC code: */

epicsRegisterFunction(mysubInit);
epicsRegisterFunction(mysubProcess);
epicsExportAddress(int, mySubDebug);
epicsRegisterFunction(myAsubInit);
epicsRegisterFunction(myAsubProcess);
epicsRegisterFunction(code2msgInit);
epicsRegisterFunction(code2msgProcess);

