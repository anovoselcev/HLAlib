# Copyright 1996-2019 The MathWorks, Inc.
#
# File    : slrt_vc.tmf 
#
#
# Abstract:
#       Makefile for building a Simulink Real-Time application from a Simulink
#       model using generated C code and a supported Microsoft Visual C/C++
#       compiler
#
#       The following defines can be used to modify the behavior of the
#       build:
#
#    OPT_OPTS       - Optimization option. Default is -O2. To enable
#                     debugging specify as OPT_OPTS=-Zd.
#    OPTS           - User specific options.
#    USER_SRCS      - Additional user sources, such as files needed by
#                     S-functions.
#    USER_INCLUDES  - Additional include paths
#                     (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")


#------------------------ Macros read by make_rtw -----------------------------
#
# The following macros are read by the code generation build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the code generation build procedure
#                    (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.
HOST            = PC
BUILD           = yes
MAKECMD         = nmake
SYS_TARGET_FILE = slrt.tlc

# Opt in to simplified format by specifying compatible Toolchain
TOOLCHAIN_NAME = [\
    "Microsoft Visual C++ 2019 v16.0 | nmake (64-bit Windows)", \
    "Microsoft Visual C++ 2017 v15.0 | nmake (64-bit Windows)", \
    "Microsoft Visual C++ 2015 v14.0 | nmake (64-bit Windows)"]

DEBUG_BUILD     = 0

#---------------------- Tokens expanded by make_rtw ---------------------------
#
# The following tokens, when wrapped with "|>" and "|<" are expanded by the
# build procedure.
#
#  MODEL_NAME      - Name of the Simulink block diagram
#  MODEL_MODULES   - Any additional generated source modules
#  MAKEFILE_NAME   - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT     - Path to were MATLAB is installed.
#  MATLAB_BIN      - Path to MATLAB executable.
#  S_FUNCTIONS_LIB - List of S-functions libraries to link.
#  NUMST           - Number of sample times
#  TID01EQ         - yes (1) or no (0): Are sampling rates of continuous task
#                    (tid=0) and 1st discrete task equal.
#  NCSTATES        - Number of continuous states
#  BUILDARGS       - Options passed in at the command line.
#  MULTITASKING    - yes (1) or no (0): Is solver mode multitasking
#  MEX_OPT_FILE    - Original file name of the mexopt.bat.

MODEL           = RITM_test_RT1007
MODULES         = rt_matrx.c rt_printf.c rt_logging.c RITM_test_RT1007.c RITM_test_RT1007_capi.c RITM_test_RT1007_data.c RITM_test_RT1007_xcp.c RITM_test_RT1007_xcp_TET.c can_datatype_ground.c rtGetInf.c rtGetNaN.c rt_nonfinite.c xpc_datatype_ground.c fiforeadwrite.c rt_logging_mmi.c rtw_modelmap_utils.c host_timer_x86.c xpc_code_profiling_utility_functions.c BA_IS_cap.c BA_IS_gpio_di.c BA_IS_gpio_do.c BA_IS_i2c_read.c BA_IS_pwm.c BA_IS_spi.c BA_IS_uart_rx.c BA_IS_uart_setup.c BA_IS_uart_tx.c CA_MA_rx.c CA_MA_setup.c CA_MA_status.c CA_MA_tx.c asciidecode.c asciiencode.c sersetupbase.c
MAKEFILE        = RITM_test_RT1007.mk
MATLAB_ROOT     = C:\Program Files\MATLAB\R2020a
ALT_MATLAB_ROOT = C:\PROGRA~1\MATLAB\R2020a
MATLAB_BIN      = C:\Program Files\MATLAB\R2020a\bin
ALT_MATLAB_BIN  = C:\PROGRA~1\MATLAB\R2020a\bin
MASTER_ANCHOR_DIR = 
START_DIR       = C:\HLA\laboratory\HLA-Simulink\SimulinkARM
S_FUNCTIONS_LIB = C:\Ritmlibs\RITM-master\RITM-master\lib\BA_IS_lib.lib C:\Ritmlibs\RITM-master\RITM-master\lib\CA_MA_lib.lib C:\Ritmlibs\RITM-master\RITM-master\lib\FC_lowlevel.lib C:\Ritmlibs\RITM-master\RITM-master\lib\GP_ID_2X_lib.lib C:\Ritmlibs\RITM-master\RITM-master\lib\GP_ID_4X_lib.lib C:\Ritmlibs\RITM-master\RITM-master\lib\GP_LC_45_lib.lib C:\Ritmlibs\RITM-master\RITM-master\lib\PCI4P.lib C:\Ritmlibs\RITM-master\RITM-master\lib\RS_MO_45_lib.lib C:\Ritmlibs\RITM-master\RITM-master\lib\TMKLL4.lib
NUMST           = 3
TID01EQ         = 0
NCSTATES        = 0
BUILDARGS       =  COMBINE_OUTPUT_UPDATE_FCNS=0 INCLUDE_MDL_TERMINATE_FCN=1 MULTI_INSTANCE_CODE=0 ISPROTECTINGMODEL=NOTPROTECTING NOT_PEDANTIC=1 OPTS="-DTID01EQ=0"
MULTITASKING    = 1
MEX_OPT_FILE    = -f "C:\Program Files\MATLAB\R2020a\bin\win64\mexopts\msvc2019.xml"

MODELREFS       = 
VISUAL_VER      = 16.0
TGT_FCN_LIB     = XPC_BLAS

OPTIMIZATION_FLAGS   = /DNDEBUG /O2 /Oy-
ADDITIONAL_LDFLAGS   = 
DEFINES_CUSTOM       = 

#--------------------------- Model and reference models -----------------------
MODELLIB                  = 
MODELREF_LINK_LIBS        = 
MODELREF_LINK_RSPFILE     = RITM_test_RT1007_ref.rsp
COMPILER_COMMAND_FILE     = RITM_test_RT1007_comp.rsp
RELATIVE_PATH_TO_ANCHOR   = ..\..
# ..\..\..\..\..\..\.. or .. or even . if you want it
MODELREF_TARGET_TYPE      = NONE

!if "$(MATLAB_ROOT)" != "$(ALT_MATLAB_ROOT)"
MATLAB_ROOT = $(ALT_MATLAB_ROOT)
!endif
!if "$(MATLAB_BIN)" != "$(ALT_MATLAB_BIN)"
MATLAB_BIN = $(ALT_MATLAB_BIN)
!endif
MATLAB_ARCH_BIN = $(MATLAB_BIN)\win64

#--------------------------- Tool Specifications ------------------------------
!include $(MATLAB_ROOT)\rtw\c\tools\vctools.mak

CMD_FILE             = $(MODEL).rsp

#------------------------------ Include/Lib Path ------------------------------

XPC_BASE = $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build

XPC_INCLUDES = $(XPC_BASE)\include;$(XPC_BASE)\xpcblocks\include
XPC_INCLUDES = $(XPC_INCLUDES);$(XPC_BASE)\xpcblocks\thirdpartydrivers
XPC_INCLUDES = $(XPC_INCLUDES);$(MATLAB_ROOT)\toolbox\slrt\target\kernel\include
INCLUDE      = .;..;$(XPC_INCLUDES);$(INCLUDE)

#----------------- Compiler and Linker Options --------------------------------
# Optimization Options
DEFAULT_OPT_OPTS = /W3 /Z7
OPT_OPTS = $(DEFAULT_OPT_OPTS)

# General User Options
OPTS =
#/GD

CC_OPTS = $(OPTS) $(OPT_OPTS) /c /nologo $(OPTIMIZATION_FLAGS) 

CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DRT -DNUMST=$(NUMST) -D_CRT_SECURE_NO_WARNINGS \
                  -DTID01EQ=$(TID01EQ) -DNCSTATES=$(NCSTATES) \
                  -DMT=$(MULTITASKING) -DHAVESTDIO -DXPCMSVISUALC \
                  -DXPCCALLCONV=__cdecl  -DUSE_RTMODEL -DERT_CORE \
                  $(DEFINES_CUSTOM)

# Uncomment this line to move warning level to W4
# cflags = $(cflags:W3=W4)
CFLAGS = $(cvarsmt) /wd4996 /fp:fast /arch:SSE2 $(CC_OPTS) $(CPP_REQ_DEFINES) @$(COMPILER_COMMAND_FILE) $(USER_INCLUDES)
CPPFLAGS = $(cflags) $(cvarsmt) /wd4996 /fp:fast /arch:SSE2 /EHsc \
           $(CPP_OPTS) $(CC_OPTS) $(CPP_REQ_DEFINES) @$(COMPILER_COMMAND_FILE) $(USER_INCLUDES)
!if "$(SLRTFTZOFF)" != ""
CFLAGS = $(cvarsmt) $(CFLAGS_VERSPECIFIC) $(CC_OPTS) $(CPP_REQ_DEFINES) @$(COMPILER_COMMAND_FILE) $(USER_INCLUDES)
CPPFLAGS = $(cflags) $(cvarsmt) $(CPPFLAGS_VERSPECIFIC) /EHsc \
           $(CPP_OPTS) $(CC_OPTS) $(CPP_REQ_DEFINES) @$(COMPILER_COMMAND_FILE) $(USER_INCLUDES)
!endif


LDFLAGS = /NOLOGO /DLL /SUBSYSTEM:CONSOLE /DEF:xpcvcdll.def  /Include:_malloc /MAP /DEBUG /IGNORE:4099 $(ADDITIONAL_LDFLAGS)

#----------------------------- Source Files -----------------------------------
#Standalone executable
!if "$(MODELREF_TARGET_TYPE)" == "NONE"
PRODUCT   = $(RELATIVE_PATH_TO_ANCHOR)\$(MODEL).dlm
SLRT_SRCS = xpctarget.c appmappingData.c legacy_stdio.c
REQ_SRCS  = $(MODULES) $(SLRT_SRCS)

#Model Reference Target
!else
PRODUCT   = $(MODELLIB)
REQ_SRCS  = $(MODULES)
!endif


USER_SRCS =

SRCS = $(REQ_SRCS) $(USER_SRCS)
OBJS_CPP_UPPER = $(SRCS:.CPP=.obj)
OBJS_CPP_LOWER = $(OBJS_CPP_UPPER:.cpp=.obj)
OBJS_C_UPPER = $(OBJS_CPP_LOWER:.C=.obj)
OBJS = $(OBJS_C_UPPER:.c=.obj)

# Special handling for object files that are not in the pre-generated linker
# response file
SLRT_OBJS = $(SLRT_SRCS:.c=.obj)

# ------------------------- Libraries ------------------------------
LIBS =



!if "$(MODELREF_TARGET_TYPE)" == "NONE"
LIBS = $(LIBS) xpcruntime.lib
!endif

# include the BLAS libs unconditionally
BLASLIBS = $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\lib\libatlas.a $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\lib\libcblas.a

#--------------------------------- Rules --------------------------------------
!if "$(MODELREF_TARGET_TYPE)" == "NONE"
#--- Stand-alone model ---
$(RELATIVE_PATH_TO_ANCHOR)\$(MODEL).dlm : $(MODEL)_slrt.dll
	$(MATLAB_ROOT)\toolbox\slrt\target\thirdparty\OnTime\bin\mkusrdlm -c+ -q+ $(MODEL)_slrt.dll $(RELATIVE_PATH_TO_ANCHOR)\$(MODEL)
	@cmd /C "echo ### Created DLM $@"
	@del $(MODEL)_slrt.lib

$(MODEL)_slrt.dll : set_environment_variables $(OBJS) $(LIBS) $(MODELREF_LINK_LIBS)
	@cmd /C "echo ### Linking ..."
	$(LD) $(LDFLAGS) $(BLASLIBS) $(LIBS) $(S_FUNCTIONS_LIB) $(CANLIB) $(SLRT_OBJS) @$(CMD_FILE) @$(MODELREF_LINK_RSPFILE) -out:$@
	@cmd /C "echo ### Created DLL $@"

!else
#--- Model reference Target ---
$(PRODUCT) : set_environment_variables $(OBJS) $(LIBS)
	@cmd /C "echo ### Linking ..."
	$(LD) -lib /OUT:$(MODELLIB) @$(CMD_FILE)
	@cmd /C "echo ### Created static library $(MODELLIB)"
!endif

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

xpcruntime.lib: xpcimports.obj xpcPCFunctions.obj
	$(LIBCMD) /nologo /out:$@ $**

# Additional sources

{C:\Ritmlibs\RITM-master\RITM-master\blocks}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(START_DIR)\RITM_test_RT1007_slrt_rtw}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{..}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\coder\profile\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
rt_matrx.obj : $(MATLAB_ROOT)\rtw\c\src\rt_matrx.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\rtw\c\src\rt_matrx.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\rtw\c\src\rt_matrx.c
rt_printf.obj : $(MATLAB_ROOT)\rtw\c\src\rt_printf.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\rtw\c\src\rt_printf.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\rtw\c\src\rt_printf.c
rt_logging.obj : $(MATLAB_ROOT)\rtw\c\src\rt_logging.c
	@cmd /C "echo ### Compiling $(MATLAB_ROOT)\rtw\c\src\rt_logging.c
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\rtw\c\src\rt_logging.c
BA_IS_cap.obj : C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_cap.c
	@cmd /C "echo ### Compiling C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_cap.c
	$(CC) $(CFLAGS) C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_cap.c
BA_IS_gpio_di.obj : C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_gpio_di.c
	@cmd /C "echo ### Compiling C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_gpio_di.c
	$(CC) $(CFLAGS) C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_gpio_di.c
BA_IS_gpio_do.obj : C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_gpio_do.c
	@cmd /C "echo ### Compiling C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_gpio_do.c
	$(CC) $(CFLAGS) C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_gpio_do.c
BA_IS_i2c_read.obj : C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_i2c_read.c
	@cmd /C "echo ### Compiling C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_i2c_read.c
	$(CC) $(CFLAGS) C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_i2c_read.c
BA_IS_pwm.obj : C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_pwm.c
	@cmd /C "echo ### Compiling C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_pwm.c
	$(CC) $(CFLAGS) C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_pwm.c
BA_IS_spi.obj : C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_spi.c
	@cmd /C "echo ### Compiling C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_spi.c
	$(CC) $(CFLAGS) C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_spi.c
BA_IS_uart_rx.obj : C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_uart_rx.c
	@cmd /C "echo ### Compiling C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_uart_rx.c
	$(CC) $(CFLAGS) C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_uart_rx.c
BA_IS_uart_setup.obj : C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_uart_setup.c
	@cmd /C "echo ### Compiling C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_uart_setup.c
	$(CC) $(CFLAGS) C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_uart_setup.c
BA_IS_uart_tx.obj : C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_uart_tx.c
	@cmd /C "echo ### Compiling C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_uart_tx.c
	$(CC) $(CFLAGS) C:\Ritmlibs\RITM-master\RITM-master\blocks\BA_IS_uart_tx.c
CA_MA_rx.obj : C:\Ritmlibs\RITM-master\RITM-master\blocks\CA_MA_rx.c
	@cmd /C "echo ### Compiling C:\Ritmlibs\RITM-master\RITM-master\blocks\CA_MA_rx.c
	$(CC) $(CFLAGS) C:\Ritmlibs\RITM-master\RITM-master\blocks\CA_MA_rx.c
CA_MA_setup.obj : C:\Ritmlibs\RITM-master\RITM-master\blocks\CA_MA_setup.c
	@cmd /C "echo ### Compiling C:\Ritmlibs\RITM-master\RITM-master\blocks\CA_MA_setup.c
	$(CC) $(CFLAGS) C:\Ritmlibs\RITM-master\RITM-master\blocks\CA_MA_setup.c
CA_MA_status.obj : C:\Ritmlibs\RITM-master\RITM-master\blocks\CA_MA_status.c
	@cmd /C "echo ### Compiling C:\Ritmlibs\RITM-master\RITM-master\blocks\CA_MA_status.c
	$(CC) $(CFLAGS) C:\Ritmlibs\RITM-master\RITM-master\blocks\CA_MA_status.c
CA_MA_tx.obj : C:\Ritmlibs\RITM-master\RITM-master\blocks\CA_MA_tx.c
	@cmd /C "echo ### Compiling C:\Ritmlibs\RITM-master\RITM-master\blocks\CA_MA_tx.c
	$(CC) $(CFLAGS) C:\Ritmlibs\RITM-master\RITM-master\blocks\CA_MA_tx.c
asciidecode.obj : "C:\Program Files\MATLAB\R2020a\toolbox\rtw\targets\xpc\target\build\xpcblocks\asciidecode.c"
	@cmd /C "echo ### Compiling "C:\Program Files\MATLAB\R2020a\toolbox\rtw\targets\xpc\target\build\xpcblocks\asciidecode.c"
	$(CC) $(CFLAGS) "C:\Program Files\MATLAB\R2020a\toolbox\rtw\targets\xpc\target\build\xpcblocks\asciidecode.c"
asciiencode.obj : "C:\Program Files\MATLAB\R2020a\toolbox\rtw\targets\xpc\target\build\xpcblocks\asciiencode.c"
	@cmd /C "echo ### Compiling "C:\Program Files\MATLAB\R2020a\toolbox\rtw\targets\xpc\target\build\xpcblocks\asciiencode.c"
	$(CC) $(CFLAGS) "C:\Program Files\MATLAB\R2020a\toolbox\rtw\targets\xpc\target\build\xpcblocks\asciiencode.c"
sersetupbase.obj : "C:\Program Files\MATLAB\R2020a\toolbox\rtw\targets\xpc\target\build\xpcblocks\sersetupbase.c"
	@cmd /C "echo ### Compiling "C:\Program Files\MATLAB\R2020a\toolbox\rtw\targets\xpc\target\build\xpcblocks\sersetupbase.c"
	$(CC) $(CFLAGS) "C:\Program Files\MATLAB\R2020a\toolbox\rtw\targets\xpc\target\build\xpcblocks\sersetupbase.c"


{C:\Ritmlibs\RITM-master\RITM-master\blocks}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(START_DIR)\RITM_test_RT1007_slrt_rtw}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\simulink\src}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{..}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\coder\profile\src}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<



# Look in simulink/src helper files

{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

# Libraries:





# Put this rule last, otherwise nmake will check toolboxes first

{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\include}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

xpctarget.obj : $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\src\xpctarget.c xpcoptions.h
	@cmd /C "echo ### Compiling xpctarget.c"
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\src\xpctarget.c

{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\thirdpartydrivers}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{..}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

set_environment_variables:
	@set INCLUDE=$(INCLUDE)
	@set LIB=$(LIB)

#----------------------------- Dependencies -----------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

xpcPCFunctions.obj xpcimports.obj: $(MAKEFILE) rtw_proj.tmw
