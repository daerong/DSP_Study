#include "StdAfx.h"
#include "AdjMax.h"
#define	Total_No	1024
AdjMax::AdjMax(void)
{
	AdMax=new double[Total_No];
	for(int i=0; i<Total_No; i++)
	{
		AdMax[i]=0;
	}
}

AdjMax::~AdjMax(void)
{
	delete [] AdMax;
}

void AdjMax::Sort_Max(void)
{
	m_Max=AdMax[0];
	for(int i=1; i<m_Data_No ; i++)
	{
		if(m_Max<AdMax[i])
			m_Max=AdMax[i];
	}
	for(int i=0; i<m_Data_No ; i++)
	{
		AdMax[i]=AdMax[i]/m_Max;
	}
}
