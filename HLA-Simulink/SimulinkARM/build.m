specs = legacy_code('initialize');
specs.Options.language = 'c++';
specs.SourceFiles = {'Wrapper.cpp', 'SimFederate.cpp'};
specs.HeaderFiles = {'Wrapper.hpp', 'SimFederate.hpp'};
os = 'windows'
if (computer == 'GLNXA64')
    os = 'linux'
    setenv('RRTI_HOME', '/home/k-110-04/Desktop/RRTI/rrti-2.0.0164/')
    setenv('LD_LIBRARY_PATH', '/home/k-110-04/Desktop/RRTI/rrti-2.0.0164/bin:/home/k-110-04/QtWork/HLA/HLAlib/3dparty/tbb/lib/intel64/gcc4.8/')
end
HLAlibPath = 'C:\QtWork\laboratory\'
RRTIpath = 'C:\rrti-2.0\RRTI-2.0.0164\'
tbbpath = 'vc14\'
Libs = ["HLAlib.lib", "libfedtime1516e.lib", "librti1516e.lib", "rtiexec.lib", "tbb12.lib"];
flags = "CXXFLAGS=$CXXFLAGS --std=c++14 -DRRTI -DFED_AMBASSADOR -DRRTI_EV";
setup = ':C:\Users\K-110-00\AppData\Roaming\MathWorks\MATLAB\R2020b\mex_C++_win64.xml'
if(computer =='GLNXA64')
    HLAlibPath = '/home/k-110-04/QtWork/HLA/HLAlib/'
    RRTIpath = '/home/k-110-04/Desktop/RRTI/rrti-2.0.0164/'
    HLAlib = 'libHLAlib.a'
    tbbpath = 'gcc4.8/'
    Libs = ["libHLAlib.a", "libfedtime1516e.so", "librti1516e.so", "libtbb.so"];
    flags = "CXXFLAGS=$CXXFLAGS --std=c++14 -DRRTI -DFED_AMBASSADOR -DRRTI_EV -pthread -lpthread";
    setup = ''
    setenv('RRTI_HOME', '/home/k-110-04/Desktop/RRTI/rrti-2.0.0164/')
    setenv('LD_LIBRARY_PATH', '/home/k-110-04/Desktop/RRTI/rrti-2.0.0164/bin:/home/k-110-04/QtWork/HLA/HLAlib/3dparty/tbb/lib/intel64/gcc4.8/')
end
specs.IncPaths = {HLAlibPath, join([HLAlibPath, 'HLAdata/']),join([HLAlibPath, 'HLA-Simulink/SimulinkARM/SimFederate/']),join([RRTIpath, 'include/HLA2010']),join([HLAlibPath, '3dparty/magic_get-develop/include'])};
specs.SrcPaths = {HLAlibPath,join([HLAlibPath, '/HLA-Simulink/SimulinkARM/SimFederate/'])};
specs.LibPaths = {join([RRTIpath, 'bin/']),join([HLAlibPath,'lib/', os, '/']),join([HLAlibPath, '/3dparty/tbb/lib/intel64/', tbbpath])};
specs.HostLibFiles = Libs;
specs.TerminateFcnSpec = 'void Terminate_Point()';
specs.SFunctionName = "TransferBlock_SimARM";
specs.StartFcnSpec = 'void Start_Point_ModelARM()';
specs.OutputFcnSpec  = 'void Output_Point_ModelARM(double u1[1], double u2[1])';

legacy_code('sfcn_cmex_generate', specs);
legacy_code('compile', specs, flags);

legacy_code('slblock_generate', specs);