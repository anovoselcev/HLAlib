#include "../include/BasicTypes.hpp"

#ifdef WIN32
#pragma warning(disable: 4251)
#pragma warning(disable: 4786)
#pragma warning(disable: 4290)
#endif
namespace HLA{
int64_t iStepStaticTest = 0;

void initializeStep(int64_t step = 0) {iStepStaticTest=step;}

void initializeMOD(Octet &data){data = 11 + Octet(iStepStaticTest);}
void initializeMOD(Integer16LE& data){data = 12 + Integer16LE(iStepStaticTest);}
void initializeMOD(Integer32LE& data){data = 13 + Integer32LE(iStepStaticTest);}
void initializeMOD(Integer64LE& data){data = 14 + iStepStaticTest;}
void initializeMOD(UnsignedShort& data){data = 10 + UnsignedShort(iStepStaticTest);}
void initializeMOD(Unsignedinteger32BE& data){data = 3232 + Unsignedinteger32BE(iStepStaticTest);}
void initializeMOD(Unsignedinteger64BE& data){data = 6464 + Unsignedinteger64BE(iStepStaticTest);}
void initializeMOD(Float32LE& data){data = (Float32LE)16.123 + Float32LE(iStepStaticTest);}
void initializeMOD(Float64LE& data){data = 17.987886754 + Float64LE(iStepStaticTest);}
void initializeMOD(Boolean& data) {
  if (iStepStaticTest%2 == 0) {
    data = Boolean::HLAfalse;
  } else data = Boolean::HLAtrue;
}


void initializeMOD (ASCIIstring & data) {
  ASCIIstring strStep;
  strStep = std::to_string(iStepStaticTest);
  data = "Test HLAASCIIstring " + strStep;
}


int readMOD(std::ifstream &File, char* data, size_t size) {
  int retValue = 1;
  File.read(data, static_cast<int>(size));
  if (!File.good()) {
    if (File.eof()) {
      retValue = 0;
    } else {
      retValue = -1;
    }
  }
  return retValue;
}
int readMOD(std::ifstream &File, Octet &data) {
  return readMOD(File,(char*)&data, sizeof(Octet));
}

int readMOD(std::ifstream &File, Integer16LE &data) {
  return readMOD(File,(char*)&data, sizeof(Integer16LE));
}
int readMOD(std::ifstream &File, Integer32LE &data) {
  return readMOD(File,(char*)&data, sizeof(Integer32LE));
}
int readMOD(std::ifstream &File, Integer64LE &data) {
  return readMOD(File,(char*)&data, sizeof(Integer64LE));
}

int readMOD(std::ifstream &File, Float32LE &data) {
  return readMOD(File,(char*)&data, sizeof(Float32LE));
}
int readMOD(std::ifstream &File, Float64LE &data) {
  return readMOD(File,(char*)&data, sizeof(Float64LE));
}
int readMOD(std::ifstream &File, UnsignedShort &data) {
  return readMOD(File,(char*)&data, sizeof(UnsignedShort));
}
int readMOD(std::ifstream &File, Unsignedinteger32BE &data) {
  return readMOD(File,(char*)&data, sizeof(Unsignedinteger32BE));
}
int readMOD(std::ifstream &File, Unsignedinteger64BE &data) {
  return readMOD(File,(char*)&data, sizeof(Unsignedinteger64BE));
}
int readMOD(std::ifstream &File, ASCIIstring &data) {
  int retCod = 1;
  int iSize;
  retCod = readMOD(File,(char*)&iSize, sizeof(int));
  if (retCod > 0) {
    char* buf = new char[iSize+1];
    buf[iSize]='\0';
    retCod = readMOD(File,buf, iSize);
    data = std::string(buf);
  }
  return retCod;
}

int writeMOD(std::ofstream &File, const Octet& data) {
  if (File.is_open()) {
    File.write((char*)&data,sizeof(Octet));
    return 1;
  }
  return -1;
}
int writeMOD(std::ofstream &File, Integer16LE const &data) {
  if (File.is_open()) {
    File.write((char*)&data,sizeof(Integer16LE));
    return 1;
  }
  return -1;
}
int writeMOD(std::ofstream &File, Integer32LE const &data) {
  if (File.is_open()) {
    File.write((char*)&data,sizeof(Integer32LE));
    return 1;
  }
  return -1;
}
int writeMOD(std::ofstream &File, Integer64LE const &data) {
  if (File.is_open()) {
    File.write((char*)&data,sizeof(Integer64LE));
    return 1;
  }
  return -1;
}

int writeMOD(std::ofstream &File, Float32LE const &data) {
  if (File.is_open()) {
    File.write((char*)&data,sizeof(Float32LE));
    return 1;
  }
  return -1;
}
int writeMOD(std::ofstream &File, Float64LE const &data) {
  if (File.is_open()) {
    File.write((char*)&data,sizeof(Float64LE));
    return 1;
  }
  return -1;
}
int writeMOD(std::ofstream &File, UnsignedShort const &data) {
  if (File.is_open()) {
    File.write((char*)&data,sizeof(UnsignedShort));
    return 1;
  }
  return -1;
}
int writeMOD(std::ofstream &File, Unsignedinteger32BE const &data) {
  if (File.is_open()) {
    File.write((char*)&data,sizeof(Unsignedinteger32BE));
    return 1;
  }
  return -1;
}
int writeMOD(std::ofstream &File, Unsignedinteger64BE const &data) {
  if (File.is_open()) {
    File.write((char*)&data,sizeof(Unsignedinteger64BE));
    return 1;
  }
  return -1;
}
int writeMOD(std::ofstream &File, ASCIIstring const & data) {
  int i_size = (int)data.size();
  if (File.is_open()) {
    File.write((char*)&i_size,sizeof(int));
    File.write(data.c_str(),i_size);
    return 1;
  }
  return -1;
}

std::wstring getUPDATE_TYPE_Name(UPDATE_TYPE_BASE en) {
  switch (en) {
    case UPDATE_TYPE_UNKNOWN: return std::wstring(L"UPDATE_TYPE_UNKNOWN");
    case UPDATE_TYPE_STATIC: return std::wstring(L"UPDATE_TYPE_STATIC");
    case UPDATE_TYPE_CONDITIONAL: return std::wstring(L"UPDATE_TYPE_CONDITIONAL");
    case UPDATE_TYPE_PERIODIC: return std::wstring(L"UPDATE_TYPE_PERIODIC");
    default: return std::wstring(L"");
  }
}

std::istream& operator >> (std::istream &StreamInput, Octet & obj) {
  int iTmp;
  StreamInput >> iTmp;
  obj = (Octet)iTmp;
  return StreamInput;
}

std::ostream &operator <<(std::ostream& outStream, Octet dat) {
  outStream << static_cast<int>(dat);
  return outStream;
}

std::ostream &operator <<(std::ostream& outStream, Boolean dat) {
  if (dat ==  Boolean::HLAfalse) {
    outStream << std::boolalpha << false;
  } else {
    outStream << std::boolalpha << true;
  }
  return outStream;
}
}

