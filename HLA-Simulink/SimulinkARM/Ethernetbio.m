function bio=Ethernetbio
bio = [];
bio(1).blkName='Ethernet/Data Type Conversion';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[1,1];
bio(1).sigWidth=1;
bio(1).sigAddress='&Ethernet_B.DataTypeConversion';
bio(1).ndims=2;
bio(1).size=[];
bio(1).isStruct=false;
bio(getlenBIO) = bio(1);

bio(2).blkName='Ethernet/Data Type Conversion1';
bio(2).sigName='';
bio(2).portIdx=0;
bio(2).dim=[1,1];
bio(2).sigWidth=1;
bio(2).sigAddress='&Ethernet_B.DataTypeConversion1';
bio(2).ndims=2;
bio(2).size=[];
bio(2).isStruct=false;

bio(3).blkName='Ethernet/Byte Packing 2';
bio(3).sigName='';
bio(3).portIdx=0;
bio(3).dim=[8,1];
bio(3).sigWidth=8;
bio(3).sigAddress='&Ethernet_B.BytePacking2[0]';
bio(3).ndims=2;
bio(3).size=[];
bio(3).isStruct=false;

bio(4).blkName='Ethernet/Byte Packing 6';
bio(4).sigName='';
bio(4).portIdx=0;
bio(4).dim=[4,1];
bio(4).sigWidth=4;
bio(4).sigAddress='&Ethernet_B.BytePacking6[0]';
bio(4).ndims=2;
bio(4).size=[];
bio(4).isStruct=false;

bio(5).blkName='Ethernet/Byte Packing 7';
bio(5).sigName='';
bio(5).portIdx=0;
bio(5).dim=[2,1];
bio(5).sigWidth=2;
bio(5).sigAddress='&Ethernet_B.BytePacking7[0]';
bio(5).ndims=2;
bio(5).size=[];
bio(5).isStruct=false;

bio(6).blkName='Ethernet/Sine Wave1';
bio(6).sigName='';
bio(6).portIdx=0;
bio(6).dim=[1,1];
bio(6).sigWidth=1;
bio(6).sigAddress='&Ethernet_B.SineWave1';
bio(6).ndims=2;
bio(6).size=[];
bio(6).isStruct=false;

bio(7).blkName='Ethernet/Sine Wave5';
bio(7).sigName='';
bio(7).portIdx=0;
bio(7).dim=[1,1];
bio(7).sigWidth=1;
bio(7).sigAddress='&Ethernet_B.SineWave5';
bio(7).ndims=2;
bio(7).size=[];
bio(7).isStruct=false;

bio(8).blkName='Ethernet/Sine Wave6';
bio(8).sigName='';
bio(8).portIdx=0;
bio(8).dim=[1,1];
bio(8).sigWidth=1;
bio(8).sigAddress='&Ethernet_B.SineWave6';
bio(8).ndims=2;
bio(8).size=[];
bio(8).isStruct=false;

bio(9).blkName='Ethernet/Width1';
bio(9).sigName='';
bio(9).portIdx=0;
bio(9).dim=[1,1];
bio(9).sigWidth=1;
bio(9).sigAddress='&Ethernet_B.Width1';
bio(9).ndims=2;
bio(9).size=[];
bio(9).isStruct=false;

function len = getlenBIO
len = 9;

