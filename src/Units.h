// ----------------------------------------------------------------------------
///  \file   Units.h
///  \brief  Useful measurement units
///
///  \author   <paola.ferrario@ific.uv.es>
///  \date     14 Feb 2013
///  \version  $Id$
///
///  Copyright (c) 2013 NEXT Collaboration
// ----------------------------------------------------------------------------

#ifndef __UNITS__
#define __UNITS__

namespace irene { 
    
    /* Length [L] */
    static const double millimeter  = 1.;                        
    static const double millimeter2 = millimeter*millimeter;
    static const double millimeter3 = millimeter*millimeter*millimeter;
    
    static const double centimeter  = 10.*millimeter;   
    static const double centimeter2 = centimeter*centimeter;
    static const double centimeter3 = centimeter*centimeter*centimeter;
    
    static const double decimeter  = 100.*millimeter;   
    static const double decimeter2 = decimeter*decimeter;
    static const double decimeter3 = decimeter*decimeter2;
    static const double liter = decimeter3;
    static const double l = liter;

    static const double meter  = 1000.*millimeter;                  
    static const double meter2 = meter*meter;
    static const double meter3 = meter*meter*meter;

    static const double kilometer = 1000.*meter;                   
    static const double kilometer2 = kilometer*kilometer;
    static const double kilometer3 = kilometer*kilometer*kilometer;

    static const double micrometer = 1.e-6 *meter;             
    static const double  nanometer = 1.e-9 *meter;
    static const double  angstrom  = 1.e-10*meter;
    static const double  fermi     = 1.e-15*meter;

    static const double      barn = 1.e-28*meter2;
    static const double millibarn = 1.e-3 *barn;
    static const double microbarn = 1.e-6 *barn;
    static const double  nanobarn = 1.e-9 *barn;
    static const double  picobarn = 1.e-12*barn;

    // symbols
    static const double mm  = millimeter;                        
    static const double mm2 = millimeter2;
    static const double mm3 = millimeter3;

    static const double cm  = centimeter;   
    static const double cm2 = centimeter2;
    static const double cm3 = centimeter3;

    static const double m  = meter;                  
    static const double m2 = meter2;
    static const double m3 = meter3;
    
    static const double km  = kilometer;                   
    static const double km2 = kilometer2;
    static const double km3 = kilometer3;
    
    /* Angle */
    static const double radian      = 1.;                  
    static const double milliradian = 1.e-3*radian;
    static const double degree = (3.14159265358979323846/180.0)*radian;
    static const double   steradian = 1.;
    // symbols
    static const double rad  = radian;	
    static const double mrad = milliradian;
    static const double sr   = steradian;
    static const double deg  = degree;

    /* Time [T]*/
    static const double nanosecond  = 1.;
    static const double second      = 1.e+9 *nanosecond;
    static const double millisecond = 1.e-3 *second;
    static const double microsecond = 1.e-6 *second;
    static const double  picosecond = 1.e-12*second;
    static const double year = 1.0e+7*second;                  //new!
    static const double hertz = 1./second;
    static const double kilohertz = 1.e+3*hertz;
    static const double megahertz = 1.e+6*hertz;    
    // symbols
    static const double ns = nanosecond;			
    static const double  s = second;
    static const double ms = millisecond;
    static const double yr = year;

   
    /* Electric charge [Q] */
    static const double eplus = 1. ;		// positron charge
    static const double e_SI  = 1.60217733e-19;	// positron charge in coulomb
    static const double coulomb = eplus/e_SI;	// coulomb = 6.24150 e+18 * eplus

    
    /* Energy [E]*/
    static const double megaelectronvolt = 1. ;
    static const double     electronvolt = 1.e-6*megaelectronvolt;
    static const double kiloelectronvolt = 1.e-3*megaelectronvolt;
    static const double gigaelectronvolt = 1.e+3*megaelectronvolt;
    static const double teraelectronvolt = 1.e+6*megaelectronvolt;
    static const double petaelectronvolt = 1.e+9*megaelectronvolt;   
    static const double joule = electronvolt/e_SI;	// joule = 6.24150 e+12 * MeV
    // symbols
    static const double MeV = megaelectronvolt;
    static const double  eV = electronvolt;
    static const double keV = kiloelectronvolt;
    static const double GeV = gigaelectronvolt;
    static const double TeV = teraelectronvolt;
    static const double PeV = petaelectronvolt;

    
    /* Mass [E][T^2][L^-2] */
    static const double  kilogram = joule*second*second/(meter*meter);   
    static const double      gram = 1.e-3*kilogram;
    static const double milligram = 1.e-3*gram;
    static const double ton = 1.e+3*kilogram;
    static const double kiloton = 1.e+3*ton;
    // symbols
    static const double  kg = kilogram;
    static const double   g = gram;
    static const double  mg = milligram;

    /* Pressure [E][L^-3] */
    static const double pascal = joule/meter/m2;	   // pascal = 6.24150 e+3 * MeV/mm3
    static const double bar        = 100000*pascal; // bar    = 6.24150 e+8 * MeV/mm3
    static const double atmosphere = 101325*pascal; // atm    = 6.32420 e+8 * MeV/mm3


    /* Electric potential [E][Q^-1] */
    static const double megavolt = megaelectronvolt/eplus;
    static const double kilovolt = 1.e-3*megavolt;
    static const double     volt = 1.e-6*megavolt;

    /* Temperature */
    static const double kelvin = 1.;

    /* Activity [T^-1] */
    static const double becquerel = 1./second ;
    static const double curie = 3.7e+10 * becquerel;

} // end namespace irene

#endif
