#ifndef VENTIDATA_H
#define VENTIDATA_H
#include <Arduino.h>

template <int SIZE>
struct padding_t
{
	uint8_t padding[SIZE-1];
};

template <>
struct padding_t<0>
{};

template<typename T>
struct CheckedValue
{
    T value;
    bool flag;
	padding_t<sizeof(T)> padding;

    operator bool(){
        return flag;
    }
};

using Pressure = CheckedValue<uint16_t>;
using Flow = CheckedValue<uint16_t>;

struct PanelData
{
	uint16_t bpm;
	uint16_t p_ins;
	uint16_t p_exp;
	PanelData();
};

struct ControllerData
{
	uint16_t p_mess_c;
	uint16_t v_mess_c;
	uint16_t bpm;
	uint16_t p_ins;
	uint16_t p_exp;
	uint16_t p_func;
	uint16_t reg_kp;
	uint16_t reg_tn;
	uint16_t reg_tv;
	ControllerData();
};

struct Data
{
	uint16_t time_high;	//pack2
	uint16_t time_low;	//pack2

	uint16_t id;		//pack2

	uint16_t contr_kp;  //pack2
	uint16_t contr_tn;	//pack2
	uint16_t contr_tv;	//pack2

	uint16_t flow_c;	//pack2
	uint16_t vol_c;	    //pack2
	uint16_t p_c;		//pack2
	uint8_t p_set;		//pack1
	
	uint8_t contr_mode;	//pack2
	uint8_t panel_mode;	//pack1

	uint8_t bpm;		//pack2

	uint8_t p_ins;		//pack1
	uint8_t p_exp;		//pack2
	uint8_t vol_insp;	//pack1
	uint8_t vol_exp;	//pack2
	uint8_t dt_rise;	//pack1
	uint8_t dp_ins;		//pack2
	uint8_t dp_exp;		//pack1
	uint8_t dt_fall;	//pack2

	uint8_t dvol;		//pack1
	uint8_t duty;		//pack2

	Data();
	Data(uint16_t id, uint8_t bpm, uint8_t p_set, uint16_t p_c, uint16_t flow_c, uint16_t vol_c, unsigned long time = millis());
	unsigned long getTime();
	void setTime(unsigned long time);
};

#endif