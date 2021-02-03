function xcp = Ethernetxcp

xcp.events     =  repmat(struct('id',{}, 'sampletime', {}, 'offset', {}), getNumEvents, 1 );
xcp.parameters =  repmat(struct('symbol',{}, 'size', {}, 'dtname', {}, 'baseaddr', {}), getNumParameters, 1 );
xcp.signals    =  repmat(struct('symbol',{}), getNumSignals, 1 );
xcp.models     =  cell(1,getNumModels);
    
xcp.models{1} = 'Ethernet';
   
   
         
xcp.events(1).id         = 0;
xcp.events(1).sampletime = 0.001;
xcp.events(1).offset     = 0.0;
    
xcp.signals(1).symbol =  'Ethernet_B.DataTypeConversion';
    
xcp.signals(2).symbol =  'Ethernet_B.DataTypeConversion1';
    
xcp.signals(3).symbol =  'Ethernet_B.BytePacking2';
    
xcp.signals(4).symbol =  'Ethernet_B.BytePacking6';
    
xcp.signals(5).symbol =  'Ethernet_B.BytePacking7';
    
xcp.signals(6).symbol =  'Ethernet_B.SineWave1';
    
xcp.signals(7).symbol =  'Ethernet_B.SineWave5';
    
xcp.signals(8).symbol =  'Ethernet_B.SineWave6';
    
xcp.signals(9).symbol =  'Ethernet_B.Width1';
         
xcp.parameters(1).symbol = 'Ethernet_P.UDPConfigure_P1';
xcp.parameters(1).size   =  4;       
xcp.parameters(1).dtname = 'real_T'; 
xcp.parameters(2).baseaddr = '&Ethernet_P.UDPConfigure_P1[0]';     
         
xcp.parameters(2).symbol = 'Ethernet_P.UDPConfigure_P2';
xcp.parameters(2).size   =  4;       
xcp.parameters(2).dtname = 'real_T'; 
xcp.parameters(3).baseaddr = '&Ethernet_P.UDPConfigure_P2[0]';     
         
xcp.parameters(3).symbol = 'Ethernet_P.UDPConfigure_P3';
xcp.parameters(3).size   =  4;       
xcp.parameters(3).dtname = 'real_T'; 
xcp.parameters(4).baseaddr = '&Ethernet_P.UDPConfigure_P3[0]';     
         
xcp.parameters(4).symbol = 'Ethernet_P.UDPConfigure_P5';
xcp.parameters(4).size   =  1;       
xcp.parameters(4).dtname = 'real_T'; 
xcp.parameters(5).baseaddr = '&Ethernet_P.UDPConfigure_P5';     
         
xcp.parameters(5).symbol = 'Ethernet_P.UDPConfigure_P8';
xcp.parameters(5).size   =  1;       
xcp.parameters(5).dtname = 'real_T'; 
xcp.parameters(6).baseaddr = '&Ethernet_P.UDPConfigure_P8';     
         
xcp.parameters(6).symbol = 'Ethernet_P.UDPConfigure_P9';
xcp.parameters(6).size   =  1;       
xcp.parameters(6).dtname = 'real_T'; 
xcp.parameters(7).baseaddr = '&Ethernet_P.UDPConfigure_P9';     
         
xcp.parameters(7).symbol = 'Ethernet_P.UDPConfigure_P10';
xcp.parameters(7).size   =  1;       
xcp.parameters(7).dtname = 'real_T'; 
xcp.parameters(8).baseaddr = '&Ethernet_P.UDPConfigure_P10';     
         
xcp.parameters(8).symbol = 'Ethernet_P.UDPConfigure_P11';
xcp.parameters(8).size   =  1;       
xcp.parameters(8).dtname = 'real_T'; 
xcp.parameters(9).baseaddr = '&Ethernet_P.UDPConfigure_P11';     
         
xcp.parameters(9).symbol = 'Ethernet_P.UDPConfigure_P12';
xcp.parameters(9).size   =  1;       
xcp.parameters(9).dtname = 'real_T'; 
xcp.parameters(10).baseaddr = '&Ethernet_P.UDPConfigure_P12';     
         
xcp.parameters(10).symbol = 'Ethernet_P.UDPSend1_P1';
xcp.parameters(10).size   =  10;       
xcp.parameters(10).dtname = 'real_T'; 
xcp.parameters(11).baseaddr = '&Ethernet_P.UDPSend1_P1[0]';     
         
xcp.parameters(11).symbol = 'Ethernet_P.UDPSend1_P2';
xcp.parameters(11).size   =  1;       
xcp.parameters(11).dtname = 'real_T'; 
xcp.parameters(12).baseaddr = '&Ethernet_P.UDPSend1_P2';     
         
xcp.parameters(12).symbol = 'Ethernet_P.UDPSend1_P3';
xcp.parameters(12).size   =  10;       
xcp.parameters(12).dtname = 'real_T'; 
xcp.parameters(13).baseaddr = '&Ethernet_P.UDPSend1_P3[0]';     
         
xcp.parameters(13).symbol = 'Ethernet_P.UDPSend1_P4';
xcp.parameters(13).size   =  1;       
xcp.parameters(13).dtname = 'real_T'; 
xcp.parameters(14).baseaddr = '&Ethernet_P.UDPSend1_P4';     
         
xcp.parameters(14).symbol = 'Ethernet_P.UDPSend1_P5';
xcp.parameters(14).size   =  1;       
xcp.parameters(14).dtname = 'real_T'; 
xcp.parameters(15).baseaddr = '&Ethernet_P.UDPSend1_P5';     
         
xcp.parameters(15).symbol = 'Ethernet_P.UDPSend1_P6';
xcp.parameters(15).size   =  1;       
xcp.parameters(15).dtname = 'real_T'; 
xcp.parameters(16).baseaddr = '&Ethernet_P.UDPSend1_P6';     
         
xcp.parameters(16).symbol = 'Ethernet_P.SineWave1_Amp';
xcp.parameters(16).size   =  1;       
xcp.parameters(16).dtname = 'real_T'; 
xcp.parameters(17).baseaddr = '&Ethernet_P.SineWave1_Amp';     
         
xcp.parameters(17).symbol = 'Ethernet_P.SineWave1_Bias';
xcp.parameters(17).size   =  1;       
xcp.parameters(17).dtname = 'real_T'; 
xcp.parameters(18).baseaddr = '&Ethernet_P.SineWave1_Bias';     
         
xcp.parameters(18).symbol = 'Ethernet_P.SineWave1_Freq';
xcp.parameters(18).size   =  1;       
xcp.parameters(18).dtname = 'real_T'; 
xcp.parameters(19).baseaddr = '&Ethernet_P.SineWave1_Freq';     
         
xcp.parameters(19).symbol = 'Ethernet_P.SineWave1_Hsin';
xcp.parameters(19).size   =  1;       
xcp.parameters(19).dtname = 'real_T'; 
xcp.parameters(20).baseaddr = '&Ethernet_P.SineWave1_Hsin';     
         
xcp.parameters(20).symbol = 'Ethernet_P.SineWave1_HCos';
xcp.parameters(20).size   =  1;       
xcp.parameters(20).dtname = 'real_T'; 
xcp.parameters(21).baseaddr = '&Ethernet_P.SineWave1_HCos';     
         
xcp.parameters(21).symbol = 'Ethernet_P.SineWave1_PSin';
xcp.parameters(21).size   =  1;       
xcp.parameters(21).dtname = 'real_T'; 
xcp.parameters(22).baseaddr = '&Ethernet_P.SineWave1_PSin';     
         
xcp.parameters(22).symbol = 'Ethernet_P.SineWave1_PCos';
xcp.parameters(22).size   =  1;       
xcp.parameters(22).dtname = 'real_T'; 
xcp.parameters(23).baseaddr = '&Ethernet_P.SineWave1_PCos';     
         
xcp.parameters(23).symbol = 'Ethernet_P.SineWave5_Amp';
xcp.parameters(23).size   =  1;       
xcp.parameters(23).dtname = 'real_T'; 
xcp.parameters(24).baseaddr = '&Ethernet_P.SineWave5_Amp';     
         
xcp.parameters(24).symbol = 'Ethernet_P.SineWave5_Bias';
xcp.parameters(24).size   =  1;       
xcp.parameters(24).dtname = 'real_T'; 
xcp.parameters(25).baseaddr = '&Ethernet_P.SineWave5_Bias';     
         
xcp.parameters(25).symbol = 'Ethernet_P.SineWave5_Freq';
xcp.parameters(25).size   =  1;       
xcp.parameters(25).dtname = 'real_T'; 
xcp.parameters(26).baseaddr = '&Ethernet_P.SineWave5_Freq';     
         
xcp.parameters(26).symbol = 'Ethernet_P.SineWave5_Hsin';
xcp.parameters(26).size   =  1;       
xcp.parameters(26).dtname = 'real_T'; 
xcp.parameters(27).baseaddr = '&Ethernet_P.SineWave5_Hsin';     
         
xcp.parameters(27).symbol = 'Ethernet_P.SineWave5_HCos';
xcp.parameters(27).size   =  1;       
xcp.parameters(27).dtname = 'real_T'; 
xcp.parameters(28).baseaddr = '&Ethernet_P.SineWave5_HCos';     
         
xcp.parameters(28).symbol = 'Ethernet_P.SineWave5_PSin';
xcp.parameters(28).size   =  1;       
xcp.parameters(28).dtname = 'real_T'; 
xcp.parameters(29).baseaddr = '&Ethernet_P.SineWave5_PSin';     
         
xcp.parameters(29).symbol = 'Ethernet_P.SineWave5_PCos';
xcp.parameters(29).size   =  1;       
xcp.parameters(29).dtname = 'real_T'; 
xcp.parameters(30).baseaddr = '&Ethernet_P.SineWave5_PCos';     
         
xcp.parameters(30).symbol = 'Ethernet_P.SineWave6_Amp';
xcp.parameters(30).size   =  1;       
xcp.parameters(30).dtname = 'real_T'; 
xcp.parameters(31).baseaddr = '&Ethernet_P.SineWave6_Amp';     
         
xcp.parameters(31).symbol = 'Ethernet_P.SineWave6_Bias';
xcp.parameters(31).size   =  1;       
xcp.parameters(31).dtname = 'real_T'; 
xcp.parameters(32).baseaddr = '&Ethernet_P.SineWave6_Bias';     
         
xcp.parameters(32).symbol = 'Ethernet_P.SineWave6_Freq';
xcp.parameters(32).size   =  1;       
xcp.parameters(32).dtname = 'real_T'; 
xcp.parameters(33).baseaddr = '&Ethernet_P.SineWave6_Freq';     
         
xcp.parameters(33).symbol = 'Ethernet_P.SineWave6_Hsin';
xcp.parameters(33).size   =  1;       
xcp.parameters(33).dtname = 'real_T'; 
xcp.parameters(34).baseaddr = '&Ethernet_P.SineWave6_Hsin';     
         
xcp.parameters(34).symbol = 'Ethernet_P.SineWave6_HCos';
xcp.parameters(34).size   =  1;       
xcp.parameters(34).dtname = 'real_T'; 
xcp.parameters(35).baseaddr = '&Ethernet_P.SineWave6_HCos';     
         
xcp.parameters(35).symbol = 'Ethernet_P.SineWave6_PSin';
xcp.parameters(35).size   =  1;       
xcp.parameters(35).dtname = 'real_T'; 
xcp.parameters(36).baseaddr = '&Ethernet_P.SineWave6_PSin';     
         
xcp.parameters(36).symbol = 'Ethernet_P.SineWave6_PCos';
xcp.parameters(36).size   =  1;       
xcp.parameters(36).dtname = 'real_T'; 
xcp.parameters(37).baseaddr = '&Ethernet_P.SineWave6_PCos';     

function n = getNumParameters
n = 36;

function n = getNumSignals
n = 9;

function n = getNumEvents
n = 1;

function n = getNumModels
n = 1;

