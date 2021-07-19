//particleType.h

#ifndef PARTICLETYPE_H
#define PARTICLETYPE_H

class ParticleType 
{
 public:
  ParticleType(const char* name,double mass ,int charge );
  const char* GetParticleName() const;
  double GetParticleMass() const;
  int GetParticleCharge() const;
  virtual void Print() const;
  virtual double GetResonanceWidth() const;
 private:
  const char* fName;
  const double fMass;
  const int fCharge;
};

#endif
