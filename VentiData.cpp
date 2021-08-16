#include "VentiData.h"

PanelData::PanelData(){
	bpm = 0;
	p_ins = 0;
	p_exp = 0;
};

ControllerData::ControllerData(){
	p_mess_c = 0;
	v_mess_c = 0;
	bpm = 0;
	p_ins = 0;
	p_exp = 0;
	p_func = 0;
	reg_kp = 0;
	reg_tn = 0;
	reg_tv = 0;
};

Data::Data() {
	time_high = 0;	//pack2
	time_low = 0;	//pack2

	id = 0;			//pack2

	contr_kp = 0;  //pack2
	contr_tn = 0;	//pack2
	contr_tv = 0;	//pack2

	flow_c = 0;		//pack2
	vol_c = 0;		//pack2
	p_c = 0;		//pack2
	p_set = 0;		//pack1

	contr_mode = 0;	//pack2
	panel_mode = 0;	//pack1

	bpm = 0;		//pack2

	p_ins = 0;		//pack1
	p_exp = 0;		//pack2
	vol_insp = 0;	//pack1
	vol_exp = 0;	//pack2
	dt_rise = 0;	//pack1
	dp_ins = 0;		//pack2
	dp_exp = 0;		//pack1
	dt_fall = 0;	//pack2

	dvol = 0;		//pack1
	duty = 0;		//pack2
}

Data::Data(uint16_t id, uint8_t bpm, uint8_t p_set, uint16_t p_c, uint16_t flow_c, uint16_t vol_c, unsigned long time){
	setTime(time);

	this->id = id;			//pack2

	this->contr_kp = 0;  //pack2
	this->contr_tn = 0;	//pack2
	this->contr_tv = 0;	//pack2

	this->flow_c = flow_c;		//pack2
	this->vol_c = vol_c;		//pack2
	this->p_c = p_c;		//pack2
	this->p_set = p_set;		//pack1

	this->contr_mode = 0;	//pack2
	this->panel_mode = 0;	//pack1

	this->bpm = bpm;		//pack2

	this->p_ins = 0;		//pack1
	this->p_exp = 0;		//pack2
	this->vol_insp = 0;	//pack1
	this->vol_exp = 0;	//pack2
	this->dt_rise = 0;	//pack1
	this->dp_ins = 0;		//pack2
	this->dp_exp = 0;		//pack1
	this->dt_fall = 0;	//pack2

	this->dvol = 0;		//pack1
	this->duty = 0;		//pack2
}

unsigned long Data::getTime() {
	return ((unsigned long)(time_high << 16) | time_low);
}

void Data::setTime(unsigned long time) {
	time_low = time & 0xffff;
	time_high = (time >> 16) & 0xffff;
}