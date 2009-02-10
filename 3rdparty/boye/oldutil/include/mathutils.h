/********************************************************************
 *   		mathutils.h
 *   Created on Fri Sep 08 2006 by Boye A. Hoeverstad.
 *   
 *   Mathematics utilities
 *******************************************************************/

#if !defined(__MATHUTILS_H__)
#define __MATHUTILS_H__

#include <cstdlib>
#include <cmath>
#include <functional>

double rndCauchy(double wtrange) 
{
  const double Cauchy_cut = 10.0;
  double u = drand48();
 
  while (u == 0.5) 
    u = drand48();
  u = wtrange * tan(u * M_PI);
  if(fabs(u) > Cauchy_cut)
    return rndCauchy(wtrange);
  else
    return u;
}


/********************************************************************
 *   Return a random number from a uniform distribution over
 *   [dCenter - dRange/2, dCenter + dRange / 2).
 *******************************************************************/
struct RandomUniform
{
  double m_dCenter, m_dRange;
  RandomUniform(double dRange, double dCenter = 0)
      : m_dCenter(dCenter), m_dRange(dRange)
  {
  }

  double operator() ()
  {
    return (drand48() - 0.5) * m_dRange + m_dCenter;
  }
};


template<class DistributionFunc>
struct NoiseAdder : public std::unary_function<double, double >
{
  DistributionFunc m_f;
  double m_dRange;
  NoiseAdder(DistributionFunc f, double dRange)
      : m_f(f), m_dRange(dRange)
  {
  }

  double operator()(double dVal) const
  {
    return dVal + m_f(m_dRange);
  }
};

template<class DistributionFunc>
NoiseAdder<DistributionFunc> make_NoiseAdder(DistributionFunc f, double dRange)
{
  return NoiseAdder<DistributionFunc>(f, dRange);
}

#endif
