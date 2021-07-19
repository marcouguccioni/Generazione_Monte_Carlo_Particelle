//particle.cpp

#include "particleType.h"
#include "resonanceType.h"
#include "particle.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int Particle :: fNParticleType =0;


ParticleType *Particle :: fParticleType[Particle::fMaxNumParticleType];


Particle :: Particle ()
{fIndex=-1,fPx=0,fPy=0,fPz=0;}


Particle :: Particle (const char* name, double px, double py, double pz) : fPx(px),fPy(py),fPz(pz) 
{
 int index = FindParticle(name);
 if(index!=-1) fIndex=index;
 else cout<<name<<" not found.\n"<<endl,fIndex=-1;
}


int Particle :: FindParticle (const char* name) 
{
 for (int i=0 ; i<fNParticleType ; i++)
   if (name == fParticleType[i]->GetParticleName()) return i;
 return -1;
}


int Particle :: GetParticleIndex()  
{return fIndex;}


void Particle :: AddParticleType (const char* name,double mass,int charge,double width)
{
  if(fNParticleType< fMaxNumParticleType)
  {
   if(FindParticle(name)==-1)
   { 
    if (width == 0)
    fParticleType[fNParticleType]=new ParticleType (name,mass,charge);
    else fParticleType[fNParticleType]=new ResonanceType (name,mass,charge,width);
    fNParticleType++;
    cout<<name<<" added to array.\n"<<endl;
   }
   else cout<<name<<" already exists.\n"<<endl;
  }
  else cout<<"too much particles added, max limit exceeded.\n"<<endl;
}
 

void Particle :: SetParticleIndex(int index) 
{
 if(index <= fNParticleType && index>-1) fIndex=index;
 else cout<<"index not allowed.\n"<<endl;
}
   

void Particle :: SetParticleIndex(const char* name)
{
 if(FindParticle(name) <= fNParticleType && FindParticle(name)>-1)    
  fIndex=FindParticle(name);
 else cout<<"index not allowed.\n"<<endl;
}


void Particle :: PrintParticleArray() 
{
 for(int i=0;i<fNParticleType;i++)
 {
  cout<<"particle "<<i<<":"<<endl;
  fParticleType[i]->Print();
 }
}


void Particle :: Print() const 
{
 cout<<"Particle index: "<<fIndex<<endl;
 cout<<"Particle name: "<<fParticleType[fIndex]->GetParticleName()<<endl;
 cout<<"Particle momentum vector: ("<<fPx<<","<<fPy<<","<<fPz<<")\n"<<endl;
}


double Particle :: GetParticlePx() 
{return fPx;}


double Particle :: GetParticlePy() 
{return fPy;}


double Particle :: GetParticlePz() 
{return fPz;}
       

double Particle :: GetParticleMass () const
{
 return (fParticleType[fIndex]->GetParticleMass());
}

int Particle :: GetParticleCharge () const
{
 return (fParticleType[fIndex]->GetParticleCharge());
}

const char* Particle :: GetParticleName () const
{
 return(fParticleType[fIndex]->GetParticleName());
}

double Particle :: GetParticleEnergy () 
{
 const double mass = fParticleType[fIndex]->GetParticleMass();
 double energy = sqrt
 (mass*mass+(fPx*fPx)+(fPy*fPy)+(fPz*fPz));
 return energy;
}


double Particle :: GetInvariantMass (Particle &p) 
{ 
 double e1= GetParticleEnergy();
 double e2= p.GetParticleEnergy();
 double px= fPx+p.GetParticlePx();
 double py= fPy+p.GetParticlePy();
 double pz= fPz+p.GetParticlePz();
 double invmass=sqrt((e1+e2)*(e1+e2)-(px*px+py*py+pz*pz));
 return invmass;
}


void Particle :: SetParticleP(double px,double py,double pz)
{fPx=px,fPy=py,fPz=pz;}


int Particle::Decay2body(Particle &dau1,Particle &dau2) const 
{
  if(GetParticleMass() == 0.0)
  {
   printf("Decayment cannot be preformed if mass is zero\n");
   return 1;
  }
  double massMot = GetParticleMass();
  double massDau1 = dau1.GetParticleMass();
  double massDau2 = dau2.GetParticleMass();
  if(fIndex > -1) //add width effect
  {
   float x1, x2, w, y1, y2;  //gaussian random numbers
   double invnum = 1./RAND_MAX;
   do 
   {
    x1 = 2.0 * rand()*invnum - 1.0;
    x2 = 2.0 * rand()*invnum - 1.0;
    w = x1 * x1 + x2 * x2;
   } 
   while ( w >= 1.0 );
   w = sqrt( (-2.0 * log( w ) ) / w );
   y1 = x1 * w;
   y2 = x2 * w;
   massMot += fParticleType[fIndex]->GetResonanceWidth() * y1;
  }
  if(massMot < massDau1 + massDau2)
  {
   printf("Decayment cannot be preformed because mass is too low in this channel\n");
   return 2;
  }
  double pout = sqrt((massMot*massMot-(massDau1+massDau2)*(massDau1+massDau2))*(massMot*massMot-(massDau1-massDau2)*(massDau1-massDau2)))/massMot*0.5;
  double norm = 2*M_PI/RAND_MAX;
  double phi = rand()*norm;
  double theta = rand()*norm*0.5 - M_PI/2.;
  dau1.SetParticleP(pout*sin(theta)*cos(phi),pout*sin(theta)*sin(phi),pout*cos(theta)); 
  dau2.SetParticleP(-pout*sin(theta)*cos(phi),- pout*sin(theta)*sin(phi),-pout*cos(theta));
  double energy = sqrt(fPx*fPx+fPy*fPy+fPz*fPz+massMot*massMot);
  double bx = fPx/energy;
  double by = fPy/energy;
  double bz = fPz/energy;
  dau1.Boost(bx,by,bz);
  dau2.Boost(bx,by,bz);
  return 0;
}


void Particle::Boost(double bx, double by, double bz)
{
  double energy = GetParticleEnergy();
  //Boost this Lorentz vector
  double b2 = bx*bx + by*by + bz*bz;
  double gamma = 1.0 / sqrt(1.0 - b2);
  double bp = bx*fPx + by*fPy + bz*fPz;
  double gamma2 = b2 > 0 ? (gamma - 1.0)/b2 : 0.0;
  fPx += gamma2*bp*bx + gamma*bx*energy;
  fPy += gamma2*bp*by + gamma*by*energy;
  fPz += gamma2*bp*bz + gamma*bz*energy;
}






















