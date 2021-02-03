#include "slrtappmapping.h"
#include "./maps/Ethernet.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <Ethernet> */
		{ /* SignalMapInfo */
			Ethernet_BIOMAP,
			Ethernet_LBLMAP,
			Ethernet_SIDMAP,
			Ethernet_SBIO,
			Ethernet_SLBL,
			{0,19},
			9,
		},
		{ /* ParamMapInfo */
			Ethernet_PTIDSMAP,
			Ethernet_PTNAMESMAP,
			Ethernet_SPTMAP,
			{0,35},
			36,
		},
		"Ethernet",
		"",
		"Ethernet",
		4,
		Ethernet_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}