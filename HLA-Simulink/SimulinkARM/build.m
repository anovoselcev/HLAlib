specs = legacy_code('initialize');
specs.Options.language = 'c++';
specs.SourceFiles = {'Wrapper.cpp', 'SimFederate.cpp'};
specs.HeaderFiles = {'Wrapper.hpp', 'SimFederate.hpp'};
specs.IncPaths = {'/home/k-110-04/QtWork/HLA/HLAlib/', '/home/k-110-04/QtWork/HLA/HLAlib/HLAdata/', '/home/k-110-04/QtWork/HLA/HLAlib/HLA-Simulink/SimulinkARM/SimFederate/', '/home/k-110-04/Desktop/RRTI/rrti-2.0.0164/include/HLA2010', '/home/k-110-04/QtWork/HLA/HLAlib/3dparty/magic_get-develop/include'};
specs.SrcPaths = {'/home/k-110-04/QtWork/HLA/HLAlib/', '/home/k-110-04/QtWork/HLA/HLAlib/HLA-Simulink/SimulinkARM/SimFederate/'};
specs.LibPaths = {'/home/k-110-04/Desktop/RRTI/rrti-2.0.0164/bin/', '/home/k-110-04/QtWork/HLA/HLAlib/lib/linux/', '/home/k-110-04/QtWork/HLA/HLAlib/3dparty/tbb/lib/intel64/gcc4.8/'};
specs.HostLibFiles = {'libfedtime1516e.so', 'librti1516e.so', 'libHLAlib.a', 'libtbb.so'};
specs.TerminateFcnSpec = 'void Terminate_Point()';
specs.SFunctionName = "TransferBlock_SimARM";
specs.StartFcnSpec = 'void Start_Point_ModelARM()';
specs.OutputFcnSpec  = 'void Output_Point_ModelARM(double u1[1], double u2[1])';
legacy_code('sfcn_cmex_generate', specs);
legacy_code('compile', specs, "CXXFLAGS=$CXXFLAGS --std=c++14 -DRRTI -DFED_AMBASSADOR -DRRTI_EV -pthread -lpthread");

legacy_code('slblock_generate', specs);