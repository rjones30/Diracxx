//
// TLorentzBoost.h 
//
// This file is distributed as part of the Lorentz++ package,
// within the Dirac++ toolkit for computing the amplitudes for
// Feynman graphs. See LorentzPackage.h for details.

#ifndef ROOT_TLorentzBoost
#define ROOT_TLorentzBoost
 
#include "Double.h"
#include "TObject.h"
#include "TLorentzTransform.h"
#include "TThreeVectorReal.h"
#include "TError.h"
 
#include <math.h>

 
class TLorentzBoost : public TLorentzTransform {
 
public:
   TLorentzBoost() : TLorentzTransform() { }
   explicit TLorentzBoost(const LDouble_t betaX,
                          const LDouble_t betaY,
                          const LDouble_t betaZ);
   explicit TLorentzBoost(const LDouble_t *beta);
   explicit TLorentzBoost(const TThreeVectorReal &beta);
   explicit TLorentzBoost(const TUnitVector &bhat, const LDouble_t beta);
   explicit TLorentzBoost(const TFourVectorReal &p);
   TLorentzBoost(const TLorentzBoost &another);
 
   virtual ~TLorentzBoost() { }
 
   TLorentzBoost &operator=(const TLorentzBoost &source);

   TThreeVectorReal Beta() const;
   LDouble_t Gamma() const;

   TLorentzBoost &Null();
   TLorentzBoost &Transpose();
   TLorentzBoost &Invert();

   TLorentzBoost &SetBeta(const LDouble_t betaX,
                          const LDouble_t betaY,
                          const LDouble_t betaZ);
   TLorentzBoost &SetBeta(const LDouble_t *beta);
   TLorentzBoost &SetBeta(const TThreeVectorReal &beta);
   TLorentzBoost &SetBeta(const TUnitVector &bhat, const LDouble_t beta);
   TLorentzBoost &SetBeta(const TFourVectorReal &p);
   TLorentzBoost &SetGamma(const TUnitVector &bhat, const LDouble_t gamma);
   TLorentzBoost &SetGamma(const LDouble_t gamma);

   void Print(Option_t *option="");
 
   ClassDef(TLorentzBoost,1)  // Lorentz Boost operator class
};

//----- inlines ----------------------------------------------------------------

inline TLorentzBoost::TLorentzBoost(const LDouble_t betaX,
                                    const LDouble_t betaY,
                                    const LDouble_t betaZ)
 : TLorentzTransform()
{
   SetBeta(betaX,betaY,betaZ);
}
 
inline TLorentzBoost::TLorentzBoost(const LDouble_t *beta)
 : TLorentzTransform()
{
   SetBeta(beta);
}
 
inline TLorentzBoost::TLorentzBoost(const TThreeVectorReal &beta)
 : TLorentzTransform()
{
   SetBeta(beta);
}

inline TLorentzBoost::TLorentzBoost
       (const TUnitVector &bhat, const LDouble_t beta)
 : TLorentzTransform()
{
   SetBeta(bhat,beta);
}

inline TLorentzBoost::TLorentzBoost(const TFourVectorReal &p)
 : TLorentzTransform()
{
   SetBeta(p);
}

inline TLorentzBoost::TLorentzBoost(const TLorentzBoost &another)
 : TLorentzTransform()
{
   *this = another;
}
 
inline TThreeVectorReal TLorentzBoost::Beta() const
{
   TThreeVectorReal beta;
   beta.fVector[1] = -fMatrix[0][1]/fMatrix[0][0];
   beta.fVector[2] = -fMatrix[0][2]/fMatrix[0][0];
   beta.fVector[3] = -fMatrix[0][3]/fMatrix[0][0];
   return beta;
}

inline LDouble_t TLorentzBoost::Gamma() const
{
   return fMatrix[0][0];
}

inline TLorentzBoost &TLorentzBoost::operator=(const TLorentzBoost &source)
{
   *(TLorentzTransform *)this = (TLorentzTransform)source;
   return *this;
}

inline TLorentzBoost &TLorentzBoost::Null()
{
   TLorentzTransform::Null();
   return *this;
}
 
inline TLorentzBoost &TLorentzBoost::Transpose()
{
   TLorentzTransform::Transpose();
   return *this;
}
 
inline TLorentzBoost &TLorentzBoost::Invert()
{
   TLorentzTransform::Invert();
   return *this;
}
 
inline TLorentzBoost &TLorentzBoost::SetBeta(const LDouble_t betaX,
                                             const LDouble_t betaY,
                                             const LDouble_t betaZ)
{
   TThreeVectorReal betaV(betaX,betaY,betaZ);
   return SetBeta(betaV);
}

inline TLorentzBoost &TLorentzBoost::SetBeta(const LDouble_t *beta)
{
   TThreeVectorReal betaV(beta);
   return SetBeta(betaV);
}

inline TLorentzBoost &TLorentzBoost::SetGamma(const LDouble_t gamma)
{
   TUnitVector bhat(Beta());
   return SetGamma(bhat.Normalize(1), gamma);
}

#endif
