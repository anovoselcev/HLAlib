#include "slrtappmapping.h"
#include "./maps/RITM_test_RT1007.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <RITM_test_RT1007> */
		{ /* SignalMapInfo */
			RITM_test_RT1007_BIOMAP,
			RITM_test_RT1007_LBLMAP,
			RITM_test_RT1007_SIDMAP,
			RITM_test_RT1007_SBIO,
			RITM_test_RT1007_SLBL,
			{0,1781},
			101,
		},
		{ /* ParamMapInfo */
			RITM_test_RT1007_PTIDSMAP,
			RITM_test_RT1007_PTNAMESMAP,
			RITM_test_RT1007_SPTMAP,
			{0,154},
			155,
		},
		"RITM_test_RT1007",
		"",
		"RITM_test_RT1007",
		7,
		RITM_test_RT1007_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}