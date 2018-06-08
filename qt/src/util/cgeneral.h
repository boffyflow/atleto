#ifndef CGENERAL_H
#define CGENERAL_H

#include <QString>

class cGeneral
{
public:

   //! rounding from double to integer
   /*! Rounds a double value to the nearest integer. Note that this is identical
       to the floor() functionality found in the standard C library.
       \param val the double to be rounded
       \return the closest integer to the given double
    */
   static int     rnd( const double val);

   //! rounding from double to a fixed digit double
   /*! Rounds a double value to the nearest double with a given number of digits. If
       no number digits are passed 1 digit is assumed. Note that passing 0 as the
       the digit number will result the same as rnd( double) returning an integer.
       \param val the double to be rounded
       \param digits the number of decimal digits
       \return the closest double with n decimal digits to the given double
    */
   static double  rnd( const double val, const int digits);

   //! determines the number of digits for any integer number
   /*! The number of digits of any integer number is determined. The input number
       can be positive or negative.
       \param value the input integer number
       \return the number of digits of the input number
    */
   static int numDigits( const int value);

   //! convert special characters to xml readable terms
   /*! \param s input qstring to be filtered
       \param attribute whether to filter "'" and "\"
       \return clean xml readable string
    */
   static QString entitize( const QString &s, const bool attribute = true);

   //! Compute the Body Mass Index (BMI) with given weight and height.
   /*! \param weight in gram.
       \param height in m.
       \return BMI as double
   */
   static double  bmi( const double weight, const double height);

   //! Compute the VDOT value from Jack Daniel's Running Formula
   /*! \param distance in meters
       \param t time in seconds
       \return VDOT value as double
   */
   static double vdot( const double dist, const double t);

   //! Compute the time for training zones based on VDOT and distance
   /*! \param vdot
       \param distance in meters
       \return time in seconds
   */
   static double vdotTime( const double vdot, const double distance);
};

#endif // CGENERAL_H
