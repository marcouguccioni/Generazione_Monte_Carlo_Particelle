//particleType.cpp

#include "particleType.h"
#include <iostream>
using namespace std;

ParticleType :: ParticleType(const char* name,double mass,int charge) : fName(name),fMass(mass),fCharge(charge) {}


const char* ParticleType :: GetParticleName() const 
{return fName;}


double ParticleType :: GetParticleMass() const 
{return fMass;}


int ParticleType :: GetParticleCharge() const 
{return fCharge;}


void ParticleType :: Print() const 
{
 cout<<"Particle name: "<<fName<<endl;
 cout<<"Particle mass: "<<fMass<<endl;
 cout<<"Particle charge: "<<fCharge<<"\n"<<endl;
}


double ParticleType :: GetResonanceWidth() const
{return 0.0;}

