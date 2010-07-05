#include "modeloutput.h"

modeloutput::modeloutput(int tsteps)
{
  t.data                    = new double[tsteps];   // time [h]
  t.name                    = "time";
  t.unit                    = "h";
  t.description             = "Elapsed time since start of model";
  t.id                      = "t";

  // mixed-layer variables
  h.data                    = new double[tsteps];   // CBL height [m]
  h.name                    = "h";
  h.unit                    = "m";
  h.description             = "CBL height";
  h.id                      = "h";

  Ps.data                   = new double[tsteps];   // surface pressure [Pa]
  Ps.name                   = "Ps";
  Ps.unit                   = "Pa";
  Ps.description            = "Surface pressure";
  Ps.id                     = "Ps";

  ws.data                   = new double[tsteps];   // large scale vertical velocity [m s-1]
  ws.name                   = "ws";
  ws.unit                   = "m s\u207B\u00B9";
  ws.description            = "Large scale vertical velocity";
  ws.id                     = "ws";

  lcl.data                  = new double[tsteps];   // Lifted Condensation level [m]
  lcl.name                  = "LCL";
  lcl.unit                  = "m";
  lcl.description           = "Lifted Condensation Level";
  lcl.id                    = "LCL";

  theta.data                = new double[tsteps];   //  mixed-layer potential temperature [K]
  theta.name                = "\u03B8";
  theta.unit                = "K";
  theta.description         = "Mixed-layer potential temperature";
  theta.id                  = "theta";

  thetav.data               = new double[tsteps];   //  mixed-layer virtual potential temperature [K]
  thetav.name               = "\u03B8\u1D65";
  thetav.unit               = "K";
  thetav.description        = "Mixed-layer virtual potential temperature";
  thetav.id                 = "thetav";

  dtheta.data               = new double[tsteps];   //  potential temperature jump at h [K]
  dtheta.name               = "\u0394\u03B8";
  dtheta.unit               = "K";
  dtheta.description        = "Potential temperature jump at boundary layer top";
  dtheta.id                 = "dtheta";

  dthetav.data              = new double[tsteps];   // virtual potential temperature jump at h [K]
  dthetav.name              = "\u0394\u03B8\u1D65";
  dthetav.unit              = "K";
  dthetav.description       = "Virtual potential temperature jump at boundary layer top";
  dthetav.id                = "dthetav";

  gammatheta.data           = new double[tsteps];   // free atmosphere potential temperature lapse rate [K m-1]
  gammatheta.name           = "gammatheta";
  gammatheta.unit           = "K m\u207B\u00B9";
  gammatheta.description    = "Potential temperature lapse rate";
  gammatheta.id             = "gammatheta";

  advtheta.data             = new double[tsteps];   // advection of heat [K s-1]
  advtheta.name             = "adv-\u03B8";
  advtheta.unit             = "K s\u207B\u00B9";
  advtheta.description      = "Large-scale temperature advection";
  advtheta.id               = "advtheta";

  beta.data                 = new double[tsteps];   // entrainment ratio for virtual heat [-]
  beta.name                 = "beta";
  beta.unit                 = "-";
  beta.description          = "Entrainment ratio";
  beta.id                   = "beta";


  wtheta.data               = new double[tsteps];   // surface kinematic heat flux [K m s-1]
  wtheta.name               = "w'\u03B8'(s)";
  wtheta.unit               = "K m s\u207B\u00B9";
  wtheta.description        = "Surface kinematic heat flux";
  wtheta.id                 = "wtheta";

  wthetae.data              = new double[tsteps];   // surface kinematic heat flux [K m s-1]
  wthetae.name              = "w'\u03B8'(e)";
  wthetae.unit              = "K m s\u207B\u00B9";
  wthetae.description       = "Entrainment kinematic heat flux";
  wthetae.id                = "wthetae";

  wthetav.data              = new double[tsteps];   // surface kinematic virtual heat flux [K m s-1]
  wthetav.name              = "w'\u03B8\u1D65'(s)";
  wthetav.unit              = "K m s\u207B\u00B9";
  wthetav.description       = "Surface virtual temperature flux";
  wthetav.id                = "wthetav";

  q.data                    = new double[tsteps];   // mixed-layer specific humidity [kg kg-1]
  q.name                    = "q";
  q.unit                    = "g kg\u207B\u00B9";
  q.description             = "Mixed-layer specific humidity";
  q.id                      = "q";

  //qsat                    = new double[tsteps];   // mixed-layer saturated specific humidity [kg kg-1]
  //e                       = new double[tsteps];   // mixed-layer vapor pressure [Pa]
  //esat                    = new double[tsteps];   // mixed-layer saturated vapor pressure [Pa]

  dq.data                   = new double[tsteps];   // specific humidity jump at h [kg kg-1]
  dq.name                   = "\u0394q";
  dq.unit                   = "g kg\u207B\u00B9";
  dq.description            = "Specific humidity jump at boundary layer top";
  dq.id                     = "dq";

  gammaq.data               = new double[tsteps];   // free atmosphere specific humidity lapse rate [kg kg-1 m-1]
  gammaq.name               = "gammaq";
  gammaq.unit               = "g kg\u207B\u00B9 m\u207B\u00B9";
  gammaq.description        = "Specific humidity lapse rate";
  gammaq.id                 = "gammaq";

  advq.data                 = new double[tsteps];   // advection of moisture [kg kg-1 s-1]
  advq.name                 = "adv-q";
  advq.unit                 = "g kg\u207B\u00B9 m\u207B\u00B9";
  advq.description          = "Large-scale moisture advection";
  advq.id                   = "advq";

  wq.data                   = new double[tsteps];   // surface kinematic moisture flux [kg kg-1 m s-1]
  wq.name                   = "w'q'(s)";
  wq.unit                   = "g kg\u207B\u00B9 m s\u207B\u00B9";
  wq.description            = "Surface kinematic moisture flux";
  wq.id                     = "wq";

  wqe.data                  = new double[tsteps];   // surface kinematic moisture flux [kg kg-1 m s-1]
  wqe.name                  = "w'q'(e)";
  wqe.unit                  = "g kg\u207B\u00B9 m s\u207B\u00B9";
  wqe.description           = "Entrainment kinematic moisture flux";
  wqe.id                    = "wqe";

  u.data                    = new double[tsteps];   // initial mixed-layer u-wind speed [m s-1]
  u.name                    = "u";
  u.unit                    = "m s\u207B\u00B9";
  u.description             = "u-wind";
  u.id                      = "u";

  du.data                   = new double[tsteps];   // initial u-wind jump at h [m s-1]
  du.name                   = "\u0394u";
  du.unit                   = "m s\u207B\u00B9";
  du.description            = "u-wind jump at boundary layer top";
  du.id                     = "du";

  gammau.data               = new double[tsteps];   // free atmosphere u-wind speed lapse rate [s-1]
  gammau.name               = "gammau";
  gammau.unit               = "m s\u207B\u00B9 m\u207B\u00B9";
  gammau.description        = "u-wind lapse rate";
  gammau.id                 = "gammau";


  advu.data                 = new double[tsteps];   // advection of u-wind [m s-2]
  advu.name                 = "adv-u";
  advu.unit                 = "m s\u207B\u00B9 s\u207B\u00B9";
  advu.description          = "Large-scale u-wind advection";
  advu.id                   = "advu";

  v.data                    = new double[tsteps];   // initial mixed-layer u-wind speed [m s-1]
  v.name                    = "v";
  v.unit                    = "m s\u207B\u00B9";
  v.description             = "v-wind";
  v.id                      = "v";

  dv.data                   = new double[tsteps];   // initial u-wind jump at h [m s-1]
  dv.name                   = "\u0394v";
  dv.unit                   = "m s\u207B\u00B9";
  dv.description            = "v-wind jump at boundary layer top";
  dv.id                     = "dv";

  gammav.data               = new double[tsteps];   // free atmosphere v-wind speed lapse rate [s-1]
  gammav.name               = "gammav";
  gammav.unit               = "m s\u207B\u00B9 m\u207B\u00B9";
  gammav.description        = "v-wind lapse rate";
  gammav.id                 = "gammav";

  advv.data                 = new double[tsteps];   // advection of v-wind [m s-2]
  advv.name                 = "adv-v";
  advv.unit                 = "m s\u207B\u00B9 s\u207B\u00B9";
  advv.description          = "Large-scale v-wind advection";
  advv.id                   = "advv";

  ustar.data                = new double[tsteps];   // friction velocity [m s-1]
  ustar.name                = "u*";
  ustar.unit                = "m s\u207B\u00B9";
  ustar.description         = "Friction velocity";
  ustar.id                  = "ustar";

  uw.data                   = new double[tsteps];   // u-momentum flux [m2 s-2]
  uw.name                   = "u'w'(s)";
  uw.unit                   = "m\u00B2 s\u207B\u00B2";
  uw.description            = "u-wind momentum flux";
  uw.id                     = "uw";

  vw.data                   = new double[tsteps];   // v-momentum flux [m2 s-2]
  vw.name                   = "v'w'(s)";
  vw.unit                   = "m\u00B2 s\u207B\u00B2";
  vw.description            = "v-wind momentum flux";
  vw.id                     = "vw";

  return;
}
