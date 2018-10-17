#include "StdAfx.h" 
#include "Gen_Signal.h"
Gen_Signal::Gen_Signal() {

} 
Gen_Signal::~Gen_Signal() 
{ 

} 
void Gen_Signal::Signal_Data() { 
	if((m_string)=="sin") { 
		for(int x=0; x<DATA_No ; x++) { 
			Sin_Data[x]=sin((2*Pi*m_FreQ/DATA_No)*x); 
		} 
	} 
	else if((m_string)=="cos") { 
		for(int x=0; x<DATA_No ; x++) { 
			Cos_Data[x]=cos((2*Pi*m_FreQ/DATA_No)*x); 
		} 
	} 
}