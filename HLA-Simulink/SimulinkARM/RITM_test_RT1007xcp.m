function xcp = RITM_test_RT1007xcp

xcp.events     =  repmat(struct('id',{}, 'sampletime', {}, 'offset', {}), getNumEvents, 1 );
xcp.parameters =  repmat(struct('symbol',{}, 'size', {}, 'dtname', {}, 'baseaddr', {}), getNumParameters, 1 );
xcp.signals    =  repmat(struct('symbol',{}), getNumSignals, 1 );
xcp.models     =  cell(1,getNumModels);
    
xcp.models{1} = 'RITM_test_RT1007';
   
   
         
xcp.events(1).id         = 0;
xcp.events(1).sampletime = 0.001;
xcp.events(1).offset     = 0.0;
         
xcp.events(2).id         = 1;
xcp.events(2).sampletime = 0.01;
xcp.events(2).offset     = 0.0;
         
xcp.events(3).id         = 2;
xcp.events(3).sampletime = 0.1;
xcp.events(3).offset     = 0.0;
         
xcp.events(4).id         = 3;
xcp.events(4).sampletime = -1.0;
xcp.events(4).offset     = -2.0;
         
xcp.events(5).id         = 4;
xcp.events(5).sampletime = -1.0;
xcp.events(5).offset     = -3.0;
    
xcp.signals(1).symbol =  'RITM_test_RT1007_B.Twiceasecond';
    
xcp.signals(2).symbol =  'RITM_test_RT1007_B.BA_IS_gpio_di_o1';
    
xcp.signals(3).symbol =  'RITM_test_RT1007_B.BA_IS_gpio_di_o2';
    
xcp.signals(4).symbol =  'RITM_test_RT1007_B.BA_IS_gpio_di_o3';
    
xcp.signals(5).symbol =  'RITM_test_RT1007_B.BA_IS_gpio_di_o4';
    
xcp.signals(6).symbol =  'RITM_test_RT1007_B.BA_IS_gpio_di_o5';
    
xcp.signals(7).symbol =  'RITM_test_RT1007_B.BA_IS_gpio_di_o6';
    
xcp.signals(8).symbol =  'RITM_test_RT1007_B.BA_IS_gpio_di_o7';
    
xcp.signals(9).symbol =  'RITM_test_RT1007_B.BA_IS_gpio_di_o8';
    
xcp.signals(10).symbol =  'RITM_test_RT1007_B.BA_IS_gpio_di_o9';
    
xcp.signals(11).symbol =  'RITM_test_RT1007_B.BA_IS_gpio_di_o10';
    
xcp.signals(12).symbol =  'RITM_test_RT1007_B.BA_IS_gpio_di_o11';
    
xcp.signals(13).symbol =  'RITM_test_RT1007_B.BA_IS_gpio_di_o12';
    
xcp.signals(14).symbol =  'RITM_test_RT1007_B.BA_IS_gpio_di_o13';
    
xcp.signals(15).symbol =  'RITM_test_RT1007_B.BAISI2C_read_o1';
    
xcp.signals(16).symbol =  'RITM_test_RT1007_B.BAISI2C_read_o2';
    
xcp.signals(17).symbol =  'RITM_test_RT1007_B.Constant1';
    
xcp.signals(18).symbol =  'RITM_test_RT1007_B.Constant2';
    
xcp.signals(19).symbol =  'RITM_test_RT1007_B.Constant3';
    
xcp.signals(20).symbol =  'RITM_test_RT1007_B.Constant8';
    
xcp.signals(21).symbol =  'RITM_test_RT1007_B.BAISCAP_o1';
    
xcp.signals(22).symbol =  'RITM_test_RT1007_B.BAISCAP_o2';
    
xcp.signals(23).symbol =  'RITM_test_RT1007_B.BAISCAP1_o1';
    
xcp.signals(24).symbol =  'RITM_test_RT1007_B.BAISCAP1_o2';
    
xcp.signals(25).symbol =  'RITM_test_RT1007_B.BAISCAP2_o1';
    
xcp.signals(26).symbol =  'RITM_test_RT1007_B.BAISCAP2_o2';
    
xcp.signals(27).symbol =  'RITM_test_RT1007_B.BAISCAP3_o1';
    
xcp.signals(28).symbol =  'RITM_test_RT1007_B.BAISCAP3_o2';
    
xcp.signals(29).symbol =  'RITM_test_RT1007_B.Bias1';
    
xcp.signals(30).symbol =  'RITM_test_RT1007_B.BAISSPI1';
    
xcp.signals(31).symbol =  'RITM_test_RT1007_B.ManualSwitch_g';
    
xcp.signals(32).symbol =  'RITM_test_RT1007_B.BAISUART_rx_o1';
    
xcp.signals(33).symbol =  'RITM_test_RT1007_B.BAISUART_rx_o2';
    
xcp.signals(34).symbol =  'RITM_test_RT1007_B.BAISUART_rx_o3';
    
xcp.signals(35).symbol =  'RITM_test_RT1007_B.ManualSwitch';
    
xcp.signals(36).symbol =  'RITM_test_RT1007_ConstB.Width';
    
xcp.signals(37).symbol =  'RITM_test_RT1007_B.CANPack';
    
xcp.signals(38).symbol =  'RITM_test_RT1007_B.CANUnpack_o1';
    
xcp.signals(39).symbol =  'RITM_test_RT1007_B.CANUnpack_o2';
    
xcp.signals(40).symbol =  'RITM_test_RT1007_B.CANUnpack_o3';
    
xcp.signals(41).symbol =  'RITM_test_RT1007_B.CANUnpack_o4';
    
xcp.signals(42).symbol =  'RITM_test_RT1007_B.CANUnpack_o5';
    
xcp.signals(43).symbol =  'RITM_test_RT1007_B.CANUnpack_o6';
    
xcp.signals(44).symbol =  'RITM_test_RT1007_B.CANUnpack_o7';
    
xcp.signals(45).symbol =  'RITM_test_RT1007_B.CA_MA_rx_o1';
    
xcp.signals(46).symbol =  'RITM_test_RT1007_B.CA_MA_rx_o2';
    
xcp.signals(47).symbol =  'RITM_test_RT1007_B.CA_MA_rx1_o1';
    
xcp.signals(48).symbol =  'RITM_test_RT1007_B.CA_MA_rx1_o2';
    
xcp.signals(49).symbol =  'RITM_test_RT1007_B.CA_MA_tx_p';
    
xcp.signals(50).symbol =  'RITM_test_RT1007_B.SineWave_k';
    
xcp.signals(51).symbol =  'RITM_test_RT1007_B.ASCIIDecode';
    
xcp.signals(52).symbol =  'RITM_test_RT1007_B.ASCIIEncode';
    
xcp.signals(53).symbol =  'RITM_test_RT1007_B.FIFOread';
    
xcp.signals(54).symbol =  'RITM_test_RT1007_B.SineWave';
    
xcp.signals(55).symbol =  'RITM_test_RT1007_B.Output_b';
    
xcp.signals(56).symbol =  'RITM_test_RT1007_B.Output';
    
xcp.signals(57).symbol =  'RITM_test_RT1007_B.RxErrorCounter';
    
xcp.signals(58).symbol =  'RITM_test_RT1007_B.TxErrorCounter';
    
xcp.signals(59).symbol =  'RITM_test_RT1007_B.CA_MA_status_e';
    
xcp.signals(60).symbol =  'RITM_test_RT1007_B.RateTransition';
    
xcp.signals(61).symbol =  'RITM_test_RT1007_B.RateTransition1_j';
    
xcp.signals(62).symbol =  'RITM_test_RT1007_B.RateTransition2';
    
xcp.signals(63).symbol =  'RITM_test_RT1007_B.RateTransition3_e';
    
xcp.signals(64).symbol =  'RITM_test_RT1007_B.FIFOwrite1_o1_o';
    
xcp.signals(65).symbol =  'RITM_test_RT1007_B.FIFOwrite1_o2_b';
    
xcp.signals(66).symbol =  'RITM_test_RT1007_B.FIFOwrite2_o1_f';
    
xcp.signals(67).symbol =  'RITM_test_RT1007_B.FIFOwrite2_o2_o';
    
xcp.signals(68).symbol =  'RITM_test_RT1007_B.RateTransition_d';
    
xcp.signals(69).symbol =  'RITM_test_RT1007_B.RateTransition1';
    
xcp.signals(70).symbol =  'RITM_test_RT1007_B.RateTransition2_p';
    
xcp.signals(71).symbol =  'RITM_test_RT1007_B.RateTransition3';
    
xcp.signals(72).symbol =  'RITM_test_RT1007_B.FIFOwrite1_o1';
    
xcp.signals(73).symbol =  'RITM_test_RT1007_B.FIFOwrite1_o2';
    
xcp.signals(74).symbol =  'RITM_test_RT1007_B.FIFOwrite2_o1';
    
xcp.signals(75).symbol =  'RITM_test_RT1007_B.FIFOwrite2_o2';
    
xcp.signals(76).symbol =  'RITM_test_RT1007_B.FixPtSum1_b';
    
xcp.signals(77).symbol =  'RITM_test_RT1007_B.FixPtSwitch_f';
    
xcp.signals(78).symbol =  'RITM_test_RT1007_B.FixPtSum1';
    
xcp.signals(79).symbol =  'RITM_test_RT1007_B.FixPtSwitch';
    
xcp.signals(80).symbol =  'RITM_test_RT1007_B.ExtractDesiredBits_o';
    
xcp.signals(81).symbol =  'RITM_test_RT1007_B.ModifyScalingOnly';
    
xcp.signals(82).symbol =  'RITM_test_RT1007_B.ExtractDesiredBits';
    
xcp.signals(83).symbol =  'RITM_test_RT1007_B.ModifyScalingOnly_d';
    
xcp.signals(84).symbol =  'RITM_test_RT1007_B.ReadIntStatusFC1_o2_o';
    
xcp.signals(85).symbol =  'RITM_test_RT1007_B.ReadIntStatusFC1_o2';
    
xcp.signals(86).symbol =  'RITM_test_RT1007_B.FIFOwrite1_e';
    
xcp.signals(87).symbol =  'RITM_test_RT1007_B.ReadHWFIFO1_b';
    
xcp.signals(88).symbol =  'RITM_test_RT1007_B.FIFOwrite2_e';
    
xcp.signals(89).symbol =  'RITM_test_RT1007_B.ReadHWFIFO2_e';
    
xcp.signals(90).symbol =  'RITM_test_RT1007_B.FIFOread1_o1_e';
    
xcp.signals(91).symbol =  'RITM_test_RT1007_B.FIFOread1_o2_k';
    
xcp.signals(92).symbol =  'RITM_test_RT1007_B.FIFOread2_o1_h';
    
xcp.signals(93).symbol =  'RITM_test_RT1007_B.FIFOread2_o2_g';
    
xcp.signals(94).symbol =  'RITM_test_RT1007_B.FIFOwrite1';
    
xcp.signals(95).symbol =  'RITM_test_RT1007_B.ReadHWFIFO1';
    
xcp.signals(96).symbol =  'RITM_test_RT1007_B.FIFOwrite2';
    
xcp.signals(97).symbol =  'RITM_test_RT1007_B.ReadHWFIFO2';
    
xcp.signals(98).symbol =  'RITM_test_RT1007_B.FIFOread1_o1';
    
xcp.signals(99).symbol =  'RITM_test_RT1007_B.FIFOread1_o2';
    
xcp.signals(100).symbol =  'RITM_test_RT1007_B.FIFOread2_o1';
    
xcp.signals(101).symbol =  'RITM_test_RT1007_B.FIFOread2_o2';
         
xcp.parameters(1).symbol = 'RITM_test_RT1007_P.Twiceasecond_Amp';
xcp.parameters(1).size   =  1;       
xcp.parameters(1).dtname = 'real_T'; 
xcp.parameters(2).baseaddr = '&RITM_test_RT1007_P.Twiceasecond_Amp';     
         
xcp.parameters(2).symbol = 'RITM_test_RT1007_P.Twiceasecond_Period';
xcp.parameters(2).size   =  1;       
xcp.parameters(2).dtname = 'real_T'; 
xcp.parameters(3).baseaddr = '&RITM_test_RT1007_P.Twiceasecond_Period';     
         
xcp.parameters(3).symbol = 'RITM_test_RT1007_P.Twiceasecond_Duty';
xcp.parameters(3).size   =  1;       
xcp.parameters(3).dtname = 'real_T'; 
xcp.parameters(4).baseaddr = '&RITM_test_RT1007_P.Twiceasecond_Duty';     
         
xcp.parameters(4).symbol = 'RITM_test_RT1007_P.Twiceasecond_PhaseDelay';
xcp.parameters(4).size   =  1;       
xcp.parameters(4).dtname = 'real_T'; 
xcp.parameters(5).baseaddr = '&RITM_test_RT1007_P.Twiceasecond_PhaseDelay';     
         
xcp.parameters(5).symbol = 'RITM_test_RT1007_P.BA_IS_gpio_di_P1';
xcp.parameters(5).size   =  1;       
xcp.parameters(5).dtname = 'real_T'; 
xcp.parameters(6).baseaddr = '&RITM_test_RT1007_P.BA_IS_gpio_di_P1';     
         
xcp.parameters(6).symbol = 'RITM_test_RT1007_P.BA_IS_gpio_di_P2';
xcp.parameters(6).size   =  13;       
xcp.parameters(6).dtname = 'real_T'; 
xcp.parameters(7).baseaddr = '&RITM_test_RT1007_P.BA_IS_gpio_di_P2[0]';     
         
xcp.parameters(7).symbol = 'RITM_test_RT1007_P.BA_IS_gpio_di_P3';
xcp.parameters(7).size   =  1;       
xcp.parameters(7).dtname = 'real_T'; 
xcp.parameters(8).baseaddr = '&RITM_test_RT1007_P.BA_IS_gpio_di_P3';     
         
xcp.parameters(8).symbol = 'RITM_test_RT1007_P.BA_IS_gpio_di_P4';
xcp.parameters(8).size   =  1;       
xcp.parameters(8).dtname = 'real_T'; 
xcp.parameters(9).baseaddr = '&RITM_test_RT1007_P.BA_IS_gpio_di_P4';     
         
xcp.parameters(9).symbol = 'RITM_test_RT1007_P.BA_IS_gpio_do_P1';
xcp.parameters(9).size   =  1;       
xcp.parameters(9).dtname = 'real_T'; 
xcp.parameters(10).baseaddr = '&RITM_test_RT1007_P.BA_IS_gpio_do_P1';     
         
xcp.parameters(10).symbol = 'RITM_test_RT1007_P.BA_IS_gpio_do_P2';
xcp.parameters(10).size   =  13;       
xcp.parameters(10).dtname = 'real_T'; 
xcp.parameters(11).baseaddr = '&RITM_test_RT1007_P.BA_IS_gpio_do_P2[0]';     
         
xcp.parameters(11).symbol = 'RITM_test_RT1007_P.BA_IS_gpio_do_P3';
xcp.parameters(11).size   =  1;       
xcp.parameters(11).dtname = 'real_T'; 
xcp.parameters(12).baseaddr = '&RITM_test_RT1007_P.BA_IS_gpio_do_P3';     
         
xcp.parameters(12).symbol = 'RITM_test_RT1007_P.BA_IS_gpio_do_P4';
xcp.parameters(12).size   =  1;       
xcp.parameters(12).dtname = 'real_T'; 
xcp.parameters(13).baseaddr = '&RITM_test_RT1007_P.BA_IS_gpio_do_P4';     
         
xcp.parameters(13).symbol = 'RITM_test_RT1007_P.BAISI2C_read_P1';
xcp.parameters(13).size   =  1;       
xcp.parameters(13).dtname = 'real_T'; 
xcp.parameters(14).baseaddr = '&RITM_test_RT1007_P.BAISI2C_read_P1';     
         
xcp.parameters(14).symbol = 'RITM_test_RT1007_P.BAISI2C_read_P2';
xcp.parameters(14).size   =  1;       
xcp.parameters(14).dtname = 'real_T'; 
xcp.parameters(15).baseaddr = '&RITM_test_RT1007_P.BAISI2C_read_P2';     
         
xcp.parameters(15).symbol = 'RITM_test_RT1007_P.BAISI2C_read_P3';
xcp.parameters(15).size   =  1;       
xcp.parameters(15).dtname = 'real_T'; 
xcp.parameters(16).baseaddr = '&RITM_test_RT1007_P.BAISI2C_read_P3';     
         
xcp.parameters(16).symbol = 'RITM_test_RT1007_P.BAISI2C_read_P4';
xcp.parameters(16).size   =  1;       
xcp.parameters(16).dtname = 'real_T'; 
xcp.parameters(17).baseaddr = '&RITM_test_RT1007_P.BAISI2C_read_P4';     
         
xcp.parameters(17).symbol = 'RITM_test_RT1007_P.BAISI2C_read_P5';
xcp.parameters(17).size   =  1;       
xcp.parameters(17).dtname = 'real_T'; 
xcp.parameters(18).baseaddr = '&RITM_test_RT1007_P.BAISI2C_read_P5';     
         
xcp.parameters(18).symbol = 'RITM_test_RT1007_P.BAISI2C_read_P6';
xcp.parameters(18).size   =  1;       
xcp.parameters(18).dtname = 'real_T'; 
xcp.parameters(19).baseaddr = '&RITM_test_RT1007_P.BAISI2C_read_P6';     
         
xcp.parameters(19).symbol = 'RITM_test_RT1007_P.Constant1_Value';
xcp.parameters(19).size   =  1;       
xcp.parameters(19).dtname = 'real_T'; 
xcp.parameters(20).baseaddr = '&RITM_test_RT1007_P.Constant1_Value';     
         
xcp.parameters(20).symbol = 'RITM_test_RT1007_P.Constant2_Value';
xcp.parameters(20).size   =  1;       
xcp.parameters(20).dtname = 'real_T'; 
xcp.parameters(21).baseaddr = '&RITM_test_RT1007_P.Constant2_Value';     
         
xcp.parameters(21).symbol = 'RITM_test_RT1007_P.Constant3_Value';
xcp.parameters(21).size   =  1;       
xcp.parameters(21).dtname = 'real_T'; 
xcp.parameters(22).baseaddr = '&RITM_test_RT1007_P.Constant3_Value';     
         
xcp.parameters(22).symbol = 'RITM_test_RT1007_P.Constant8_Value';
xcp.parameters(22).size   =  1;       
xcp.parameters(22).dtname = 'real_T'; 
xcp.parameters(23).baseaddr = '&RITM_test_RT1007_P.Constant8_Value';     
         
xcp.parameters(23).symbol = 'RITM_test_RT1007_P.BAISCAP_P1';
xcp.parameters(23).size   =  1;       
xcp.parameters(23).dtname = 'real_T'; 
xcp.parameters(24).baseaddr = '&RITM_test_RT1007_P.BAISCAP_P1';     
         
xcp.parameters(24).symbol = 'RITM_test_RT1007_P.BAISCAP_P2';
xcp.parameters(24).size   =  1;       
xcp.parameters(24).dtname = 'real_T'; 
xcp.parameters(25).baseaddr = '&RITM_test_RT1007_P.BAISCAP_P2';     
         
xcp.parameters(25).symbol = 'RITM_test_RT1007_P.BAISCAP_P3';
xcp.parameters(25).size   =  1;       
xcp.parameters(25).dtname = 'real_T'; 
xcp.parameters(26).baseaddr = '&RITM_test_RT1007_P.BAISCAP_P3';     
         
xcp.parameters(26).symbol = 'RITM_test_RT1007_P.BAISCAP1_P1';
xcp.parameters(26).size   =  1;       
xcp.parameters(26).dtname = 'real_T'; 
xcp.parameters(27).baseaddr = '&RITM_test_RT1007_P.BAISCAP1_P1';     
         
xcp.parameters(27).symbol = 'RITM_test_RT1007_P.BAISCAP1_P2';
xcp.parameters(27).size   =  1;       
xcp.parameters(27).dtname = 'real_T'; 
xcp.parameters(28).baseaddr = '&RITM_test_RT1007_P.BAISCAP1_P2';     
         
xcp.parameters(28).symbol = 'RITM_test_RT1007_P.BAISCAP1_P3';
xcp.parameters(28).size   =  1;       
xcp.parameters(28).dtname = 'real_T'; 
xcp.parameters(29).baseaddr = '&RITM_test_RT1007_P.BAISCAP1_P3';     
         
xcp.parameters(29).symbol = 'RITM_test_RT1007_P.BAISCAP2_P1';
xcp.parameters(29).size   =  1;       
xcp.parameters(29).dtname = 'real_T'; 
xcp.parameters(30).baseaddr = '&RITM_test_RT1007_P.BAISCAP2_P1';     
         
xcp.parameters(30).symbol = 'RITM_test_RT1007_P.BAISCAP2_P2';
xcp.parameters(30).size   =  1;       
xcp.parameters(30).dtname = 'real_T'; 
xcp.parameters(31).baseaddr = '&RITM_test_RT1007_P.BAISCAP2_P2';     
         
xcp.parameters(31).symbol = 'RITM_test_RT1007_P.BAISCAP2_P3';
xcp.parameters(31).size   =  1;       
xcp.parameters(31).dtname = 'real_T'; 
xcp.parameters(32).baseaddr = '&RITM_test_RT1007_P.BAISCAP2_P3';     
         
xcp.parameters(32).symbol = 'RITM_test_RT1007_P.BAISCAP3_P1';
xcp.parameters(32).size   =  1;       
xcp.parameters(32).dtname = 'real_T'; 
xcp.parameters(33).baseaddr = '&RITM_test_RT1007_P.BAISCAP3_P1';     
         
xcp.parameters(33).symbol = 'RITM_test_RT1007_P.BAISCAP3_P2';
xcp.parameters(33).size   =  1;       
xcp.parameters(33).dtname = 'real_T'; 
xcp.parameters(34).baseaddr = '&RITM_test_RT1007_P.BAISCAP3_P2';     
         
xcp.parameters(34).symbol = 'RITM_test_RT1007_P.BAISCAP3_P3';
xcp.parameters(34).size   =  1;       
xcp.parameters(34).dtname = 'real_T'; 
xcp.parameters(35).baseaddr = '&RITM_test_RT1007_P.BAISCAP3_P3';     
         
xcp.parameters(35).symbol = 'RITM_test_RT1007_P.BAISPWM_P1';
xcp.parameters(35).size   =  1;       
xcp.parameters(35).dtname = 'real_T'; 
xcp.parameters(36).baseaddr = '&RITM_test_RT1007_P.BAISPWM_P1';     
         
xcp.parameters(36).symbol = 'RITM_test_RT1007_P.BAISPWM_P2';
xcp.parameters(36).size   =  1;       
xcp.parameters(36).dtname = 'real_T'; 
xcp.parameters(37).baseaddr = '&RITM_test_RT1007_P.BAISPWM_P2';     
         
xcp.parameters(37).symbol = 'RITM_test_RT1007_P.BAISPWM_P3';
xcp.parameters(37).size   =  1;       
xcp.parameters(37).dtname = 'real_T'; 
xcp.parameters(38).baseaddr = '&RITM_test_RT1007_P.BAISPWM_P3';     
         
xcp.parameters(38).symbol = 'RITM_test_RT1007_P.BAISPWM1_P1';
xcp.parameters(38).size   =  1;       
xcp.parameters(38).dtname = 'real_T'; 
xcp.parameters(39).baseaddr = '&RITM_test_RT1007_P.BAISPWM1_P1';     
         
xcp.parameters(39).symbol = 'RITM_test_RT1007_P.BAISPWM1_P2';
xcp.parameters(39).size   =  1;       
xcp.parameters(39).dtname = 'real_T'; 
xcp.parameters(40).baseaddr = '&RITM_test_RT1007_P.BAISPWM1_P2';     
         
xcp.parameters(40).symbol = 'RITM_test_RT1007_P.BAISPWM1_P3';
xcp.parameters(40).size   =  1;       
xcp.parameters(40).dtname = 'real_T'; 
xcp.parameters(41).baseaddr = '&RITM_test_RT1007_P.BAISPWM1_P3';     
         
xcp.parameters(41).symbol = 'RITM_test_RT1007_P.CounterLimited1_uplimit';
xcp.parameters(41).size   =  1;       
xcp.parameters(41).dtname = 'uint8_T'; 
xcp.parameters(42).baseaddr = '&RITM_test_RT1007_P.CounterLimited1_uplimit';     
         
xcp.parameters(42).symbol = 'RITM_test_RT1007_P.Bias1_Bias';
xcp.parameters(42).size   =  4;       
xcp.parameters(42).dtname = 'uint8_T'; 
xcp.parameters(43).baseaddr = '&RITM_test_RT1007_P.Bias1_Bias[0]';     
         
xcp.parameters(43).symbol = 'RITM_test_RT1007_P.Generatesomedata_Value';
xcp.parameters(43).size   =  4;       
xcp.parameters(43).dtname = 'uint8_T'; 
xcp.parameters(44).baseaddr = '&RITM_test_RT1007_P.Generatesomedata_Value[0]';     
         
xcp.parameters(44).symbol = 'RITM_test_RT1007_P.BAISSPI1_P1';
xcp.parameters(44).size   =  1;       
xcp.parameters(44).dtname = 'real_T'; 
xcp.parameters(45).baseaddr = '&RITM_test_RT1007_P.BAISSPI1_P1';     
         
xcp.parameters(45).symbol = 'RITM_test_RT1007_P.BAISSPI1_P2';
xcp.parameters(45).size   =  1;       
xcp.parameters(45).dtname = 'real_T'; 
xcp.parameters(46).baseaddr = '&RITM_test_RT1007_P.BAISSPI1_P2';     
         
xcp.parameters(46).symbol = 'RITM_test_RT1007_P.BAISSPI1_P3';
xcp.parameters(46).size   =  1;       
xcp.parameters(46).dtname = 'real_T'; 
xcp.parameters(47).baseaddr = '&RITM_test_RT1007_P.BAISSPI1_P3';     
         
xcp.parameters(47).symbol = 'RITM_test_RT1007_P.BAISSPI1_P4';
xcp.parameters(47).size   =  1;       
xcp.parameters(47).dtname = 'real_T'; 
xcp.parameters(48).baseaddr = '&RITM_test_RT1007_P.BAISSPI1_P4';     
         
xcp.parameters(48).symbol = 'RITM_test_RT1007_P.BAISSPI1_P5';
xcp.parameters(48).size   =  1;       
xcp.parameters(48).dtname = 'real_T'; 
xcp.parameters(49).baseaddr = '&RITM_test_RT1007_P.BAISSPI1_P5';     
         
xcp.parameters(49).symbol = 'RITM_test_RT1007_P.BAISSPI1_P6';
xcp.parameters(49).size   =  1;       
xcp.parameters(49).dtname = 'real_T'; 
xcp.parameters(50).baseaddr = '&RITM_test_RT1007_P.BAISSPI1_P6';     
         
xcp.parameters(50).symbol = 'RITM_test_RT1007_P.BAISSPI1_P7';
xcp.parameters(50).size   =  1;       
xcp.parameters(50).dtname = 'real_T'; 
xcp.parameters(51).baseaddr = '&RITM_test_RT1007_P.BAISSPI1_P7';     
         
xcp.parameters(51).symbol = 'RITM_test_RT1007_P.BAISSPI1_P8';
xcp.parameters(51).size   =  1;       
xcp.parameters(51).dtname = 'real_T'; 
xcp.parameters(52).baseaddr = '&RITM_test_RT1007_P.BAISSPI1_P8';     
         
xcp.parameters(52).symbol = 'RITM_test_RT1007_P.ManualSwitch_CurrentSetting';
xcp.parameters(52).size   =  1;       
xcp.parameters(52).dtname = 'uint8_T'; 
xcp.parameters(53).baseaddr = '&RITM_test_RT1007_P.ManualSwitch_CurrentSetting';     
         
xcp.parameters(53).symbol = 'RITM_test_RT1007_P.CounterLimited_uplimit';
xcp.parameters(53).size   =  1;       
xcp.parameters(53).dtname = 'uint8_T'; 
xcp.parameters(54).baseaddr = '&RITM_test_RT1007_P.CounterLimited_uplimit';     
         
xcp.parameters(54).symbol = 'RITM_test_RT1007_P.Generatesomedata_Value_l';
xcp.parameters(54).size   =  4;       
xcp.parameters(54).dtname = 'uint8_T'; 
xcp.parameters(55).baseaddr = '&RITM_test_RT1007_P.Generatesomedata_Value_l[0]';     
         
xcp.parameters(55).symbol = 'RITM_test_RT1007_P.BAISUART_rx_P1';
xcp.parameters(55).size   =  1;       
xcp.parameters(55).dtname = 'real_T'; 
xcp.parameters(56).baseaddr = '&RITM_test_RT1007_P.BAISUART_rx_P1';     
         
xcp.parameters(56).symbol = 'RITM_test_RT1007_P.BAISUART_rx_P2';
xcp.parameters(56).size   =  1;       
xcp.parameters(56).dtname = 'real_T'; 
xcp.parameters(57).baseaddr = '&RITM_test_RT1007_P.BAISUART_rx_P2';     
         
xcp.parameters(57).symbol = 'RITM_test_RT1007_P.BAISUART_rx_P3';
xcp.parameters(57).size   =  1;       
xcp.parameters(57).dtname = 'real_T'; 
xcp.parameters(58).baseaddr = '&RITM_test_RT1007_P.BAISUART_rx_P3';     
         
xcp.parameters(58).symbol = 'RITM_test_RT1007_P.BAISUART_rx_P4';
xcp.parameters(58).size   =  1;       
xcp.parameters(58).dtname = 'real_T'; 
xcp.parameters(59).baseaddr = '&RITM_test_RT1007_P.BAISUART_rx_P4';     
         
xcp.parameters(59).symbol = 'RITM_test_RT1007_P.BAISUART_setup_P1';
xcp.parameters(59).size   =  1;       
xcp.parameters(59).dtname = 'real_T'; 
xcp.parameters(60).baseaddr = '&RITM_test_RT1007_P.BAISUART_setup_P1';     
         
xcp.parameters(60).symbol = 'RITM_test_RT1007_P.BAISUART_setup_P2';
xcp.parameters(60).size   =  1;       
xcp.parameters(60).dtname = 'real_T'; 
xcp.parameters(61).baseaddr = '&RITM_test_RT1007_P.BAISUART_setup_P2';     
         
xcp.parameters(61).symbol = 'RITM_test_RT1007_P.BAISUART_setup_P3';
xcp.parameters(61).size   =  1;       
xcp.parameters(61).dtname = 'real_T'; 
xcp.parameters(62).baseaddr = '&RITM_test_RT1007_P.BAISUART_setup_P3';     
         
xcp.parameters(62).symbol = 'RITM_test_RT1007_P.BAISUART_setup_P4';
xcp.parameters(62).size   =  1;       
xcp.parameters(62).dtname = 'real_T'; 
xcp.parameters(63).baseaddr = '&RITM_test_RT1007_P.BAISUART_setup_P4';     
         
xcp.parameters(63).symbol = 'RITM_test_RT1007_P.BAISUART_setup_P5';
xcp.parameters(63).size   =  1;       
xcp.parameters(63).dtname = 'real_T'; 
xcp.parameters(64).baseaddr = '&RITM_test_RT1007_P.BAISUART_setup_P5';     
         
xcp.parameters(64).symbol = 'RITM_test_RT1007_P.BAISUART_setup_P6';
xcp.parameters(64).size   =  1;       
xcp.parameters(64).dtname = 'real_T'; 
xcp.parameters(65).baseaddr = '&RITM_test_RT1007_P.BAISUART_setup_P6';     
         
xcp.parameters(65).symbol = 'RITM_test_RT1007_P.BAISUART_tx_P1';
xcp.parameters(65).size   =  1;       
xcp.parameters(65).dtname = 'real_T'; 
xcp.parameters(66).baseaddr = '&RITM_test_RT1007_P.BAISUART_tx_P1';     
         
xcp.parameters(66).symbol = 'RITM_test_RT1007_P.BAISUART_tx_P2';
xcp.parameters(66).size   =  1;       
xcp.parameters(66).dtname = 'real_T'; 
xcp.parameters(67).baseaddr = '&RITM_test_RT1007_P.BAISUART_tx_P2';     
         
xcp.parameters(67).symbol = 'RITM_test_RT1007_P.BAISUART_tx_P3';
xcp.parameters(67).size   =  1;       
xcp.parameters(67).dtname = 'real_T'; 
xcp.parameters(68).baseaddr = '&RITM_test_RT1007_P.BAISUART_tx_P3';     
         
xcp.parameters(68).symbol = 'RITM_test_RT1007_P.BAISUART_tx_P4';
xcp.parameters(68).size   =  1;       
xcp.parameters(68).dtname = 'real_T'; 
xcp.parameters(69).baseaddr = '&RITM_test_RT1007_P.BAISUART_tx_P4';     
         
xcp.parameters(69).symbol = 'RITM_test_RT1007_P.ManualSwitch_CurrentSetting_m';
xcp.parameters(69).size   =  1;       
xcp.parameters(69).dtname = 'uint8_T'; 
xcp.parameters(70).baseaddr = '&RITM_test_RT1007_P.ManualSwitch_CurrentSetting_m';     
         
xcp.parameters(70).symbol = 'RITM_test_RT1007_P.CA_MA_rx_P1';
xcp.parameters(70).size   =  1;       
xcp.parameters(70).dtname = 'real_T'; 
xcp.parameters(71).baseaddr = '&RITM_test_RT1007_P.CA_MA_rx_P1';     
         
xcp.parameters(71).symbol = 'RITM_test_RT1007_P.CA_MA_rx_P2';
xcp.parameters(71).size   =  1;       
xcp.parameters(71).dtname = 'real_T'; 
xcp.parameters(72).baseaddr = '&RITM_test_RT1007_P.CA_MA_rx_P2';     
         
xcp.parameters(72).symbol = 'RITM_test_RT1007_P.CA_MA_rx_P3';
xcp.parameters(72).size   =  1;       
xcp.parameters(72).dtname = 'real_T'; 
xcp.parameters(73).baseaddr = '&RITM_test_RT1007_P.CA_MA_rx_P3';     
         
xcp.parameters(73).symbol = 'RITM_test_RT1007_P.CA_MA_rx1_P1';
xcp.parameters(73).size   =  1;       
xcp.parameters(73).dtname = 'real_T'; 
xcp.parameters(74).baseaddr = '&RITM_test_RT1007_P.CA_MA_rx1_P1';     
         
xcp.parameters(74).symbol = 'RITM_test_RT1007_P.CA_MA_rx1_P2';
xcp.parameters(74).size   =  1;       
xcp.parameters(74).dtname = 'real_T'; 
xcp.parameters(75).baseaddr = '&RITM_test_RT1007_P.CA_MA_rx1_P2';     
         
xcp.parameters(75).symbol = 'RITM_test_RT1007_P.CA_MA_rx1_P3';
xcp.parameters(75).size   =  1;       
xcp.parameters(75).dtname = 'real_T'; 
xcp.parameters(76).baseaddr = '&RITM_test_RT1007_P.CA_MA_rx1_P3';     
         
xcp.parameters(76).symbol = 'RITM_test_RT1007_P.CA_MA_setup_P1';
xcp.parameters(76).size   =  1;       
xcp.parameters(76).dtname = 'real_T'; 
xcp.parameters(77).baseaddr = '&RITM_test_RT1007_P.CA_MA_setup_P1';     
         
xcp.parameters(77).symbol = 'RITM_test_RT1007_P.CA_MA_setup_P2';
xcp.parameters(77).size   =  1;       
xcp.parameters(77).dtname = 'real_T'; 
xcp.parameters(78).baseaddr = '&RITM_test_RT1007_P.CA_MA_setup_P2';     
         
xcp.parameters(78).symbol = 'RITM_test_RT1007_P.CA_MA_setup_P3';
xcp.parameters(78).size   =  1;       
xcp.parameters(78).dtname = 'real_T'; 
xcp.parameters(79).baseaddr = '&RITM_test_RT1007_P.CA_MA_setup_P3';     
         
xcp.parameters(79).symbol = 'RITM_test_RT1007_P.CA_MA_setup_P4';
xcp.parameters(79).size   =  3;       
xcp.parameters(79).dtname = 'real_T'; 
xcp.parameters(80).baseaddr = '&RITM_test_RT1007_P.CA_MA_setup_P4[0]';     
         
xcp.parameters(80).symbol = 'RITM_test_RT1007_P.CA_MA_setup_P5';
xcp.parameters(80).size   =  3;       
xcp.parameters(80).dtname = 'real_T'; 
xcp.parameters(81).baseaddr = '&RITM_test_RT1007_P.CA_MA_setup_P5[0]';     
         
xcp.parameters(81).symbol = 'RITM_test_RT1007_P.CA_MA_setup_P6';
xcp.parameters(81).size   =  1;       
xcp.parameters(81).dtname = 'real_T'; 
xcp.parameters(82).baseaddr = '&RITM_test_RT1007_P.CA_MA_setup_P6';     
         
xcp.parameters(82).symbol = 'RITM_test_RT1007_P.CA_MA_setup_P7';
xcp.parameters(82).size   =  1;       
xcp.parameters(82).dtname = 'real_T'; 
xcp.parameters(83).baseaddr = '&RITM_test_RT1007_P.CA_MA_setup_P7';     
         
xcp.parameters(83).symbol = 'RITM_test_RT1007_P.CA_MA_tx_P1';
xcp.parameters(83).size   =  1;       
xcp.parameters(83).dtname = 'real_T'; 
xcp.parameters(84).baseaddr = '&RITM_test_RT1007_P.CA_MA_tx_P1';     
         
xcp.parameters(84).symbol = 'RITM_test_RT1007_P.CA_MA_tx_P2';
xcp.parameters(84).size   =  1;       
xcp.parameters(84).dtname = 'real_T'; 
xcp.parameters(85).baseaddr = '&RITM_test_RT1007_P.CA_MA_tx_P2';     
         
xcp.parameters(85).symbol = 'RITM_test_RT1007_P.CA_MA_tx_P3';
xcp.parameters(85).size   =  1;       
xcp.parameters(85).dtname = 'real_T'; 
xcp.parameters(86).baseaddr = '&RITM_test_RT1007_P.CA_MA_tx_P3';     
         
xcp.parameters(86).symbol = 'RITM_test_RT1007_P.SineWave_Amp';
xcp.parameters(86).size   =  1;       
xcp.parameters(86).dtname = 'real_T'; 
xcp.parameters(87).baseaddr = '&RITM_test_RT1007_P.SineWave_Amp';     
         
xcp.parameters(87).symbol = 'RITM_test_RT1007_P.SineWave_Bias';
xcp.parameters(87).size   =  1;       
xcp.parameters(87).dtname = 'real_T'; 
xcp.parameters(88).baseaddr = '&RITM_test_RT1007_P.SineWave_Bias';     
         
xcp.parameters(88).symbol = 'RITM_test_RT1007_P.SineWave_Freq';
xcp.parameters(88).size   =  1;       
xcp.parameters(88).dtname = 'real_T'; 
xcp.parameters(89).baseaddr = '&RITM_test_RT1007_P.SineWave_Freq';     
         
xcp.parameters(89).symbol = 'RITM_test_RT1007_P.SineWave_Hsin';
xcp.parameters(89).size   =  1;       
xcp.parameters(89).dtname = 'real_T'; 
xcp.parameters(90).baseaddr = '&RITM_test_RT1007_P.SineWave_Hsin';     
         
xcp.parameters(90).symbol = 'RITM_test_RT1007_P.SineWave_HCos';
xcp.parameters(90).size   =  1;       
xcp.parameters(90).dtname = 'real_T'; 
xcp.parameters(91).baseaddr = '&RITM_test_RT1007_P.SineWave_HCos';     
         
xcp.parameters(91).symbol = 'RITM_test_RT1007_P.SineWave_PSin';
xcp.parameters(91).size   =  1;       
xcp.parameters(91).dtname = 'real_T'; 
xcp.parameters(92).baseaddr = '&RITM_test_RT1007_P.SineWave_PSin';     
         
xcp.parameters(92).symbol = 'RITM_test_RT1007_P.SineWave_PCos';
xcp.parameters(92).size   =  1;       
xcp.parameters(92).dtname = 'real_T'; 
xcp.parameters(93).baseaddr = '&RITM_test_RT1007_P.SineWave_PCos';     
         
xcp.parameters(93).symbol = 'RITM_test_RT1007_P.ASCIIDecode_P1';
xcp.parameters(93).size   =  3;       
xcp.parameters(93).dtname = 'real_T'; 
xcp.parameters(94).baseaddr = '&RITM_test_RT1007_P.ASCIIDecode_P1[0]';     
         
xcp.parameters(94).symbol = 'RITM_test_RT1007_P.ASCIIDecode_P2';
xcp.parameters(94).size   =  1;       
xcp.parameters(94).dtname = 'real_T'; 
xcp.parameters(95).baseaddr = '&RITM_test_RT1007_P.ASCIIDecode_P2';     
         
xcp.parameters(95).symbol = 'RITM_test_RT1007_P.ASCIIDecode_P3';
xcp.parameters(95).size   =  1;       
xcp.parameters(95).dtname = 'real_T'; 
xcp.parameters(96).baseaddr = '&RITM_test_RT1007_P.ASCIIDecode_P3';     
         
xcp.parameters(96).symbol = 'RITM_test_RT1007_P.ASCIIEncode_P1';
xcp.parameters(96).size   =  3;       
xcp.parameters(96).dtname = 'real_T'; 
xcp.parameters(97).baseaddr = '&RITM_test_RT1007_P.ASCIIEncode_P1[0]';     
         
xcp.parameters(97).symbol = 'RITM_test_RT1007_P.ASCIIEncode_P2';
xcp.parameters(97).size   =  1;       
xcp.parameters(97).dtname = 'real_T'; 
xcp.parameters(98).baseaddr = '&RITM_test_RT1007_P.ASCIIEncode_P2';     
         
xcp.parameters(98).symbol = 'RITM_test_RT1007_P.ASCIIEncode_P3';
xcp.parameters(98).size   =  1;       
xcp.parameters(98).dtname = 'real_T'; 
xcp.parameters(99).baseaddr = '&RITM_test_RT1007_P.ASCIIEncode_P3';     
         
xcp.parameters(99).symbol = 'RITM_test_RT1007_P.ASCIIEncode_P4';
xcp.parameters(99).size   =  1;       
xcp.parameters(99).dtname = 'real_T'; 
xcp.parameters(100).baseaddr = '&RITM_test_RT1007_P.ASCIIEncode_P4';     
         
xcp.parameters(100).symbol = 'RITM_test_RT1007_P.SineWave_Amp_o';
xcp.parameters(100).size   =  1;       
xcp.parameters(100).dtname = 'real_T'; 
xcp.parameters(101).baseaddr = '&RITM_test_RT1007_P.SineWave_Amp_o';     
         
xcp.parameters(101).symbol = 'RITM_test_RT1007_P.SineWave_Bias_n';
xcp.parameters(101).size   =  1;       
xcp.parameters(101).dtname = 'real_T'; 
xcp.parameters(102).baseaddr = '&RITM_test_RT1007_P.SineWave_Bias_n';     
         
xcp.parameters(102).symbol = 'RITM_test_RT1007_P.SineWave_Freq_p';
xcp.parameters(102).size   =  1;       
xcp.parameters(102).dtname = 'real_T'; 
xcp.parameters(103).baseaddr = '&RITM_test_RT1007_P.SineWave_Freq_p';     
         
xcp.parameters(103).symbol = 'RITM_test_RT1007_P.SineWave_Hsin_j';
xcp.parameters(103).size   =  1;       
xcp.parameters(103).dtname = 'real_T'; 
xcp.parameters(104).baseaddr = '&RITM_test_RT1007_P.SineWave_Hsin_j';     
         
xcp.parameters(104).symbol = 'RITM_test_RT1007_P.SineWave_HCos_f';
xcp.parameters(104).size   =  1;       
xcp.parameters(104).dtname = 'real_T'; 
xcp.parameters(105).baseaddr = '&RITM_test_RT1007_P.SineWave_HCos_f';     
         
xcp.parameters(105).symbol = 'RITM_test_RT1007_P.SineWave_PSin_p';
xcp.parameters(105).size   =  1;       
xcp.parameters(105).dtname = 'real_T'; 
xcp.parameters(106).baseaddr = '&RITM_test_RT1007_P.SineWave_PSin_p';     
         
xcp.parameters(106).symbol = 'RITM_test_RT1007_P.SineWave_PCos_d';
xcp.parameters(106).size   =  1;       
xcp.parameters(106).dtname = 'real_T'; 
xcp.parameters(107).baseaddr = '&RITM_test_RT1007_P.SineWave_PCos_d';     
         
xcp.parameters(107).symbol = 'RITM_test_RT1007_P.Output_InitialCondition';
xcp.parameters(107).size   =  1;       
xcp.parameters(107).dtname = 'uint8_T'; 
xcp.parameters(108).baseaddr = '&RITM_test_RT1007_P.Output_InitialCondition';     
         
xcp.parameters(108).symbol = 'RITM_test_RT1007_P.Output_InitialCondition_b';
xcp.parameters(108).size   =  1;       
xcp.parameters(108).dtname = 'uint8_T'; 
xcp.parameters(109).baseaddr = '&RITM_test_RT1007_P.Output_InitialCondition_b';     
         
xcp.parameters(109).symbol = 'RITM_test_RT1007_P.CA_MA_status_P1';
xcp.parameters(109).size   =  1;       
xcp.parameters(109).dtname = 'real_T'; 
xcp.parameters(110).baseaddr = '&RITM_test_RT1007_P.CA_MA_status_P1';     
         
xcp.parameters(110).symbol = 'RITM_test_RT1007_P.CA_MA_status_P2';
xcp.parameters(110).size   =  1;       
xcp.parameters(110).dtname = 'real_T'; 
xcp.parameters(111).baseaddr = '&RITM_test_RT1007_P.CA_MA_status_P2';     
         
xcp.parameters(111).symbol = 'RITM_test_RT1007_P.CA_MA_status_P3';
xcp.parameters(111).size   =  1;       
xcp.parameters(111).dtname = 'real_T'; 
xcp.parameters(112).baseaddr = '&RITM_test_RT1007_P.CA_MA_status_P3';     
         
xcp.parameters(112).symbol = 'RITM_test_RT1007_P.Setup1_P1_c';
xcp.parameters(112).size   =  1;       
xcp.parameters(112).dtname = 'real_T'; 
xcp.parameters(113).baseaddr = '&RITM_test_RT1007_P.Setup1_P1_c';     
         
xcp.parameters(113).symbol = 'RITM_test_RT1007_P.Setup1_P2_n';
xcp.parameters(113).size   =  1;       
xcp.parameters(113).dtname = 'real_T'; 
xcp.parameters(114).baseaddr = '&RITM_test_RT1007_P.Setup1_P2_n';     
         
xcp.parameters(114).symbol = 'RITM_test_RT1007_P.Setup1_P3_j';
xcp.parameters(114).size   =  1;       
xcp.parameters(114).dtname = 'real_T'; 
xcp.parameters(115).baseaddr = '&RITM_test_RT1007_P.Setup1_P3_j';     
         
xcp.parameters(115).symbol = 'RITM_test_RT1007_P.Setup1_P4_o';
xcp.parameters(115).size   =  1;       
xcp.parameters(115).dtname = 'real_T'; 
xcp.parameters(116).baseaddr = '&RITM_test_RT1007_P.Setup1_P4_o';     
         
xcp.parameters(116).symbol = 'RITM_test_RT1007_P.Setup1_P5_h';
xcp.parameters(116).size   =  1;       
xcp.parameters(116).dtname = 'real_T'; 
xcp.parameters(117).baseaddr = '&RITM_test_RT1007_P.Setup1_P5_h';     
         
xcp.parameters(117).symbol = 'RITM_test_RT1007_P.Setup1_P6_i';
xcp.parameters(117).size   =  1;       
xcp.parameters(117).dtname = 'real_T'; 
xcp.parameters(118).baseaddr = '&RITM_test_RT1007_P.Setup1_P6_i';     
         
xcp.parameters(118).symbol = 'RITM_test_RT1007_P.Setup1_P7_l';
xcp.parameters(118).size   =  1;       
xcp.parameters(118).dtname = 'real_T'; 
xcp.parameters(119).baseaddr = '&RITM_test_RT1007_P.Setup1_P7_l';     
         
xcp.parameters(119).symbol = 'RITM_test_RT1007_P.Setup1_P8_i';
xcp.parameters(119).size   =  1;       
xcp.parameters(119).dtname = 'real_T'; 
xcp.parameters(120).baseaddr = '&RITM_test_RT1007_P.Setup1_P8_i';     
         
xcp.parameters(120).symbol = 'RITM_test_RT1007_P.Setup2_P1_p';
xcp.parameters(120).size   =  1;       
xcp.parameters(120).dtname = 'real_T'; 
xcp.parameters(121).baseaddr = '&RITM_test_RT1007_P.Setup2_P1_p';     
         
xcp.parameters(121).symbol = 'RITM_test_RT1007_P.Setup2_P2_l';
xcp.parameters(121).size   =  1;       
xcp.parameters(121).dtname = 'real_T'; 
xcp.parameters(122).baseaddr = '&RITM_test_RT1007_P.Setup2_P2_l';     
         
xcp.parameters(122).symbol = 'RITM_test_RT1007_P.Setup2_P3_d';
xcp.parameters(122).size   =  1;       
xcp.parameters(122).dtname = 'real_T'; 
xcp.parameters(123).baseaddr = '&RITM_test_RT1007_P.Setup2_P3_d';     
         
xcp.parameters(123).symbol = 'RITM_test_RT1007_P.Setup2_P4_c';
xcp.parameters(123).size   =  1;       
xcp.parameters(123).dtname = 'real_T'; 
xcp.parameters(124).baseaddr = '&RITM_test_RT1007_P.Setup2_P4_c';     
         
xcp.parameters(124).symbol = 'RITM_test_RT1007_P.Setup2_P5_o';
xcp.parameters(124).size   =  1;       
xcp.parameters(124).dtname = 'real_T'; 
xcp.parameters(125).baseaddr = '&RITM_test_RT1007_P.Setup2_P5_o';     
         
xcp.parameters(125).symbol = 'RITM_test_RT1007_P.Setup2_P6_n';
xcp.parameters(125).size   =  1;       
xcp.parameters(125).dtname = 'real_T'; 
xcp.parameters(126).baseaddr = '&RITM_test_RT1007_P.Setup2_P6_n';     
         
xcp.parameters(126).symbol = 'RITM_test_RT1007_P.Setup2_P7_i';
xcp.parameters(126).size   =  1;       
xcp.parameters(126).dtname = 'real_T'; 
xcp.parameters(127).baseaddr = '&RITM_test_RT1007_P.Setup2_P7_i';     
         
xcp.parameters(127).symbol = 'RITM_test_RT1007_P.Setup2_P8_j';
xcp.parameters(127).size   =  1;       
xcp.parameters(127).dtname = 'real_T'; 
xcp.parameters(128).baseaddr = '&RITM_test_RT1007_P.Setup2_P8_j';     
         
xcp.parameters(128).symbol = 'RITM_test_RT1007_P.Setup1_P1';
xcp.parameters(128).size   =  1;       
xcp.parameters(128).dtname = 'real_T'; 
xcp.parameters(129).baseaddr = '&RITM_test_RT1007_P.Setup1_P1';     
         
xcp.parameters(129).symbol = 'RITM_test_RT1007_P.Setup1_P2';
xcp.parameters(129).size   =  1;       
xcp.parameters(129).dtname = 'real_T'; 
xcp.parameters(130).baseaddr = '&RITM_test_RT1007_P.Setup1_P2';     
         
xcp.parameters(130).symbol = 'RITM_test_RT1007_P.Setup1_P3';
xcp.parameters(130).size   =  1;       
xcp.parameters(130).dtname = 'real_T'; 
xcp.parameters(131).baseaddr = '&RITM_test_RT1007_P.Setup1_P3';     
         
xcp.parameters(131).symbol = 'RITM_test_RT1007_P.Setup1_P4';
xcp.parameters(131).size   =  1;       
xcp.parameters(131).dtname = 'real_T'; 
xcp.parameters(132).baseaddr = '&RITM_test_RT1007_P.Setup1_P4';     
         
xcp.parameters(132).symbol = 'RITM_test_RT1007_P.Setup1_P5';
xcp.parameters(132).size   =  1;       
xcp.parameters(132).dtname = 'real_T'; 
xcp.parameters(133).baseaddr = '&RITM_test_RT1007_P.Setup1_P5';     
         
xcp.parameters(133).symbol = 'RITM_test_RT1007_P.Setup1_P6';
xcp.parameters(133).size   =  1;       
xcp.parameters(133).dtname = 'real_T'; 
xcp.parameters(134).baseaddr = '&RITM_test_RT1007_P.Setup1_P6';     
         
xcp.parameters(134).symbol = 'RITM_test_RT1007_P.Setup1_P7';
xcp.parameters(134).size   =  1;       
xcp.parameters(134).dtname = 'real_T'; 
xcp.parameters(135).baseaddr = '&RITM_test_RT1007_P.Setup1_P7';     
         
xcp.parameters(135).symbol = 'RITM_test_RT1007_P.Setup1_P8';
xcp.parameters(135).size   =  1;       
xcp.parameters(135).dtname = 'real_T'; 
xcp.parameters(136).baseaddr = '&RITM_test_RT1007_P.Setup1_P8';     
         
xcp.parameters(136).symbol = 'RITM_test_RT1007_P.Setup2_P1';
xcp.parameters(136).size   =  1;       
xcp.parameters(136).dtname = 'real_T'; 
xcp.parameters(137).baseaddr = '&RITM_test_RT1007_P.Setup2_P1';     
         
xcp.parameters(137).symbol = 'RITM_test_RT1007_P.Setup2_P2';
xcp.parameters(137).size   =  1;       
xcp.parameters(137).dtname = 'real_T'; 
xcp.parameters(138).baseaddr = '&RITM_test_RT1007_P.Setup2_P2';     
         
xcp.parameters(138).symbol = 'RITM_test_RT1007_P.Setup2_P3';
xcp.parameters(138).size   =  1;       
xcp.parameters(138).dtname = 'real_T'; 
xcp.parameters(139).baseaddr = '&RITM_test_RT1007_P.Setup2_P3';     
         
xcp.parameters(139).symbol = 'RITM_test_RT1007_P.Setup2_P4';
xcp.parameters(139).size   =  1;       
xcp.parameters(139).dtname = 'real_T'; 
xcp.parameters(140).baseaddr = '&RITM_test_RT1007_P.Setup2_P4';     
         
xcp.parameters(140).symbol = 'RITM_test_RT1007_P.Setup2_P5';
xcp.parameters(140).size   =  1;       
xcp.parameters(140).dtname = 'real_T'; 
xcp.parameters(141).baseaddr = '&RITM_test_RT1007_P.Setup2_P5';     
         
xcp.parameters(141).symbol = 'RITM_test_RT1007_P.Setup2_P6';
xcp.parameters(141).size   =  1;       
xcp.parameters(141).dtname = 'real_T'; 
xcp.parameters(142).baseaddr = '&RITM_test_RT1007_P.Setup2_P6';     
         
xcp.parameters(142).symbol = 'RITM_test_RT1007_P.Setup2_P7';
xcp.parameters(142).size   =  1;       
xcp.parameters(142).dtname = 'real_T'; 
xcp.parameters(143).baseaddr = '&RITM_test_RT1007_P.Setup2_P7';     
         
xcp.parameters(143).symbol = 'RITM_test_RT1007_P.Setup2_P8';
xcp.parameters(143).size   =  1;       
xcp.parameters(143).dtname = 'real_T'; 
xcp.parameters(144).baseaddr = '&RITM_test_RT1007_P.Setup2_P8';     
         
xcp.parameters(144).symbol = 'RITM_test_RT1007_P.FixPtConstant_Value';
xcp.parameters(144).size   =  1;       
xcp.parameters(144).dtname = 'uint8_T'; 
xcp.parameters(145).baseaddr = '&RITM_test_RT1007_P.FixPtConstant_Value';     
         
xcp.parameters(145).symbol = 'RITM_test_RT1007_P.Constant_Value_i';
xcp.parameters(145).size   =  1;       
xcp.parameters(145).dtname = 'uint8_T'; 
xcp.parameters(146).baseaddr = '&RITM_test_RT1007_P.Constant_Value_i';     
         
xcp.parameters(146).symbol = 'RITM_test_RT1007_P.FixPtConstant_Value_k';
xcp.parameters(146).size   =  1;       
xcp.parameters(146).dtname = 'uint8_T'; 
xcp.parameters(147).baseaddr = '&RITM_test_RT1007_P.FixPtConstant_Value_k';     
         
xcp.parameters(147).symbol = 'RITM_test_RT1007_P.Constant_Value_h';
xcp.parameters(147).size   =  1;       
xcp.parameters(147).dtname = 'uint8_T'; 
xcp.parameters(148).baseaddr = '&RITM_test_RT1007_P.Constant_Value_h';     
         
xcp.parameters(148).symbol = 'RITM_test_RT1007_P.Constant_Value';
xcp.parameters(148).size   =  1;       
xcp.parameters(148).dtname = 'uint32_T'; 
xcp.parameters(149).baseaddr = '&RITM_test_RT1007_P.Constant_Value';     
         
xcp.parameters(149).symbol = 'RITM_test_RT1007_P.Constant_Value_a';
xcp.parameters(149).size   =  1;       
xcp.parameters(149).dtname = 'uint32_T'; 
xcp.parameters(150).baseaddr = '&RITM_test_RT1007_P.Constant_Value_a';     
         
xcp.parameters(150).symbol = 'RITM_test_RT1007_P.Constant1_Value_h';
xcp.parameters(150).size   =  1;       
xcp.parameters(150).dtname = 'uint32_T'; 
xcp.parameters(151).baseaddr = '&RITM_test_RT1007_P.Constant1_Value_h';     
         
xcp.parameters(151).symbol = 'RITM_test_RT1007_P.Constant2_Value_d';
xcp.parameters(151).size   =  1;       
xcp.parameters(151).dtname = 'uint32_T'; 
xcp.parameters(152).baseaddr = '&RITM_test_RT1007_P.Constant2_Value_d';     
         
xcp.parameters(152).symbol = 'RITM_test_RT1007_P.Constant_Value_c';
xcp.parameters(152).size   =  1;       
xcp.parameters(152).dtname = 'uint32_T'; 
xcp.parameters(153).baseaddr = '&RITM_test_RT1007_P.Constant_Value_c';     
         
xcp.parameters(153).symbol = 'RITM_test_RT1007_P.Constant_Value_m';
xcp.parameters(153).size   =  1;       
xcp.parameters(153).dtname = 'uint32_T'; 
xcp.parameters(154).baseaddr = '&RITM_test_RT1007_P.Constant_Value_m';     
         
xcp.parameters(154).symbol = 'RITM_test_RT1007_P.Constant1_Value_he';
xcp.parameters(154).size   =  1;       
xcp.parameters(154).dtname = 'uint32_T'; 
xcp.parameters(155).baseaddr = '&RITM_test_RT1007_P.Constant1_Value_he';     
         
xcp.parameters(155).symbol = 'RITM_test_RT1007_P.Constant2_Value_p';
xcp.parameters(155).size   =  1;       
xcp.parameters(155).dtname = 'uint32_T'; 
xcp.parameters(156).baseaddr = '&RITM_test_RT1007_P.Constant2_Value_p';     

function n = getNumParameters
n = 155;

function n = getNumSignals
n = 101;

function n = getNumEvents
n = 5;

function n = getNumModels
n = 1;

