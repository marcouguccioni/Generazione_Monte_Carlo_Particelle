//resonanceType.h

#ifndef RESONANCETYPE_H
#define RESONANCETYPE_H
#include "particleType.h"
 
class ResonanceType : public ParticleType 
{
 public:
  ResonanceType (const char* name ,double mass,int charge, double width );
  virtual double GetResonanceWidth() const;
  virtual void Print() const;
 private:
  const double fWidth;
};

#endif
 
