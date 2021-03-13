#ifndef BUS_TYPE
#define BUS_TYPE

typedef struct {
	double yaw;
	double el;
} AngleData;

typedef struct {
	double fi;
	double la;
	double h;
	double kurs;
	double kren;
	double tang;
} BinsData;

#endif