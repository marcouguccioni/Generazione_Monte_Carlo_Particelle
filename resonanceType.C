//resonanceType.cpp

#include "resonanceType.h"
#include <iostream>
using namespace std;


ResonanceType :: ResonanceType(const char* name,double mass,int charge, double width) : ParticleType(name,mass,charge), fWidth(width) {}


double ResonanceType :: GetResonanceWidth() const 
{return fWidth;};


void ResonanceType :: Print() const 
{
 ParticleType:: Print();
 cout<<"Resonance width: "<<fWidth<<"\n"<<endl;
}




