function sys=RITM_test_RT1007ref
sys = [];
sys.child = [];
sys.NumDataTypes = 7; 
sys.DataTypes = [];
temp.EnumNames='';
temp.EnumValues = [];
temp.Name = '';
sys.DataTypes = repmat(temp,1,7);
sys.DataTypes(1).Name = 'real_T';
sys.DataTypes(2).Name = 'uint8_T';
sys.DataTypes(3).Name = 'uint32_T';
sys.DataTypes(4).Name = 'CAN_DATATYPE';
sys.DataTypes(5).Name = 'int32_T';
sys.DataTypes(6).Name = 'serialfifoptr';
sys.DataTypes(7).Name = 'boolean_T';