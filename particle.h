//particle.h

#ifndef PARTICLE_H
#define PARTICLE_H
#include "particleType.h"


class Particle
{
 public:
  Particle();
  Particle (const char* name,double px,double py,double pz);
  int GetParticleIndex();
  static void AddParticleType(const char* name,double mass,int charge,double width=0);
  void SetParticleIndex(int index);
  void SetParticleIndex(const char* name);
  static void PrintParticleArray();
  void Print() const;
  double GetParticlePx();
  double GetParticlePy();
  double GetParticlePz();
  double GetParticleMass() const;
  int GetParticleCharge() const;
  const char* GetParticleName () const;
  double GetParticleEnergy();
  double GetInvariantMass(Particle& p);
  void SetParticleP (double px,double py,double pz);
  int Decay2body(Particle &dau1,Particle &dau2) const;
  static const int fMaxNumParticleType=10;
 private:
  static ParticleType *fParticleType[fMaxNumParticleType];
  static int fNParticleType;
  int fIndex;
  double fPx,fPy,fPz;
  static int FindParticle (const char* name);
  void Boost(double bx, double by, double bz);
};

#endif

