//
// This class contains the secondary correction 
// for the central region
//
#ifndef ALICENTRALCORRSECONDARYMAP_H
#define ALICENTRALCORRSECONDARYMAP_H
/**
 * @file   AliCentralCorrSecondaryMap.h
 * @author Hans Hjersing Dalsgaard 
 * @date   Wed Mar 23 13:59:03 2011
 * 
 * @brief  
 * 
 * 
 * @ingroup pwglf_forward_corr
 */
#include <TObject.h>
#include <TObjArray.h>
#include <TAxis.h>
class TH2D;

/**
 * This class contains the acceptance correction due to dead channels
 *
 * These are generated from the on-line dead channel calculations 
 *
 * @ingroup pwglf_forward_corr
 */
class AliCentralCorrSecondaryMap : public TObject 
{
public:
  /** 
   * Default constructor 
   */
  AliCentralCorrSecondaryMap();
  /** 
   * Copy constructor 
   * 
   * @param o Object to copy from 
   */
  AliCentralCorrSecondaryMap(const AliCentralCorrSecondaryMap& o);
  /**
   * Destructor 
   * 
   */
  virtual ~AliCentralCorrSecondaryMap();
  /** 
   * @{ 
   * @name Get corrections and parameters 
   */
  /** 
   * Assignment operator 
   * 
   * @param o Object to assign from 
   * 
   * @return Reference to this object 
   */
  AliCentralCorrSecondaryMap& operator=(const AliCentralCorrSecondaryMap& o);
  /** 
   * Get the acceptance correction @f$ a_{r,v}@f$ 
   *
   * @param v  Primary interaction point @f$z@f$ coordinate
   * 
   * @return The correction @f$ a_{r,v}@f$ 
   */
  TH2D* GetCorrection(Double_t v) const;
  /** 
   * Get the acceptance correction @f$ a_{r,v}@f$ 
   *
   * @param b  Bin corresponding to the primary interaction point 
   *           @f$z@f$ coordinate (1 based)
   * 
   * @return The correction @f$ a_{r,v}@f$ 
   */
  TH2D* GetCorrection(UShort_t b) const;
  /** 
   * Get the vertex axis used 
   * 
   * @return vertex axis 
   */
  const TAxis& GetVertexAxis() const { return fVertexAxis; }
  /* @} */

  /** 
   * @{ 
   * @name Set corrections and parameters 
   */
  /** 
   * Set the acceptance correction @f$ a_{r,v}(\eta)@f$.
   * Note, that the object takes ownership of the passed pointer.
   * 
   * @param v    Primary interaction point @f$z@f$ coordinate  
   * @param h    @f$ a_{r,v}(\eta)@f$ 
   * 
   * @return true if operation succeeded 
   */
  Bool_t SetCorrection(Double_t v, TH2D* h);
  /** 
   * Set the acceptance correction @f$ a_{r,v}(\eta)@f$ 
   * Note, that the object takes ownership of the passed pointer.
   * 
   * @param b    Bin corresponding to the primary interaction point 
   *             @f$z@f$ coordinate  (1 based)
   * @param h    @f$ a_{r,v}(\eta)@f$ 
   * 
   * @return true if operation succeeded 
   */
  Bool_t SetCorrection(UShort_t b, TH2D* h);
  /** 
   * Set the vertex axis to use 
   * 
   * @param axis Vertex axis 
   */
  void SetVertexAxis(const TAxis& axis);
  /** 
   * Set the vertex axis to use 
   * 
   * @param nBins   Number of bins
   * @param min     Minimum
   * @param max     Maximum
   */
  void SetVertexAxis(Int_t nBins, Double_t min, Double_t max);
  /* @} */

  /** 
   * @{ 
   * @name Auxiliary member functions 
   */
  /** 
   * Declare this as a folder
   * 
   * @return Always true 
   */
  Bool_t IsFolder() const { return true; }
  /** 
   * Browse this object in the browser
   * 
   * @param b 
   */
  void Browse(TBrowser* b);
  /** 
   * Print this object 
   * 
   * @param option 
   */  
  void Print(Option_t* option="R") const; //*MENU*
  /* @} */
protected:
  /** 
   * Find the vertex bin that corresponds to the passed vertex 
   * 
   * @param vertex The interaction points @f$z@f$-coordinate 
   * 
   * @return Vertex bin in @f$[1,N_{\mbox{vertex}}]@f$ or negative if 
   * out of range 
   */
  Int_t FindVertexBin(Double_t vertex) const;
  /** 
   * Get the index corresponding to the given ring 
   * 
   * @param d Detector
   * @param r Ring 
   * 
   * @return Index (0 based) or negative in case of errors
   */
    
  TObjArray fArray;      // Array of per-ring, per-vertex 2nd map
  TAxis     fVertexAxis;     // The vertex axis 
  ClassDef(AliCentralCorrSecondaryMap,1); // SecondaryMap correction due to dead areas
};

//____________________________________________________________________
inline void 
AliCentralCorrSecondaryMap::SetVertexAxis(Int_t nBins, Double_t min, 
					   Double_t max)
{
  fVertexAxis.Set(nBins, min, max);
}
//____________________________________________________________________
inline void 
AliCentralCorrSecondaryMap::SetVertexAxis(const TAxis& e)
{
  fVertexAxis.Set(e.GetNbins(), e.GetXmin(), e.GetXmax());
}
#endif
// Local Variables:
//  mode: C++
// End:
