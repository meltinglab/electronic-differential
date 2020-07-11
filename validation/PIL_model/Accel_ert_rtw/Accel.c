/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Accel.c
 *
 * Code generated for Simulink model 'Accel'.
 *
 * Model version                  : 1.101
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Sat Jul 11 18:03:12 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Accel.h"
#include "Accel_private.h"

/* Block signals (default storage) */
B_Accel_T Accel_B;

/* Block states (default storage) */
DW_Accel_T Accel_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Accel_T Accel_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Accel_T Accel_Y;

/* Real-time model */
RT_MODEL_Accel_T Accel_M_;
RT_MODEL_Accel_T *const Accel_M = &Accel_M_;
real_T look1_binlcapw(real_T u0, const real_T bp0[], const real_T table[],
                      uint32_T maxIndex)
{
  real_T y;
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex;
    frac = 0.0;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    y = (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
  }

  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T a;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = sqrt(y * y + 1.0) * a;
  } else {
    if (!rtIsNaN(y)) {
      y = a * 1.4142135623730951;
    }
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void Accel_step(void)
{
  boolean_T rtb_NotEqual;
  real_T rtb_Switch_j_idx_2;
  real_T A_idx_1;
  real_T rtb_Switch_j_idx_0;
  real_T u0;
  real_T u0_0;
  int32_T rtb_ComplextoMagnitudeAngle_o_0;

  /* Gain: '<S1>/rads_to_rpm' incorporates:
   *  Inport: '<Root>/MotSpd'
   */
  Accel_Y.TrqCmd[0] = Accel_P.rads_to_rpm_Gain * Accel_U.EngSpd[0];

  /* Lookup_n-D: '<S1>/MaxMotTrqVsSpd' */
  Accel_Y.TrqCmd[0] = look1_binlcapw(Accel_Y.TrqCmd[0], Accel_P.MotSpd,
    Accel_P.MotTrq, 11U);

  /* Gain: '<S1>/rads_to_rpm' incorporates:
   *  Inport: '<Root>/MotSpd'
   */
  Accel_Y.TrqCmd[1] = Accel_P.rads_to_rpm_Gain * Accel_U.EngSpd[1];

  /* Lookup_n-D: '<S1>/MaxMotTrqVsSpd' */
  Accel_Y.TrqCmd[1] = look1_binlcapw(Accel_Y.TrqCmd[1], Accel_P.MotSpd,
    Accel_P.MotTrq, 11U);

  /* Gain: '<S1>/rads_to_rpm' incorporates:
   *  Inport: '<Root>/MotSpd'
   */
  Accel_Y.TrqCmd[2] = Accel_P.rads_to_rpm_Gain * Accel_U.EngSpd[2];

  /* Lookup_n-D: '<S1>/MaxMotTrqVsSpd' */
  Accel_Y.TrqCmd[2] = look1_binlcapw(Accel_Y.TrqCmd[2], Accel_P.MotSpd,
    Accel_P.MotTrq, 11U);

  /* Gain: '<S1>/rads_to_rpm' incorporates:
   *  Inport: '<Root>/MotSpd'
   */
  Accel_Y.TrqCmd[3] = Accel_P.rads_to_rpm_Gain * Accel_U.EngSpd[3];

  /* Lookup_n-D: '<S1>/MaxMotTrqVsSpd' */
  Accel_Y.TrqCmd[3] = look1_binlcapw(Accel_Y.TrqCmd[3], Accel_P.MotSpd,
    Accel_P.MotTrq, 11U);

  /* Product: '<S6>/Divide' incorporates:
   *  Constant: '<S6>/wheel base'
   */
  Accel_B.y = Accel_P.VEH.FrontAxlePositionfromCG +
    Accel_P.VEH.RearAxlePositionfromCG;

  /* Saturate: '<S6>/Saturation WhlAnd' incorporates:
   *  Inport: '<Root>/WhlAng'
   */
  if (Accel_U.WhlAng[0] > Accel_P.SaturationWhlAnd_UpperSat) {
    u0 = Accel_P.SaturationWhlAnd_UpperSat;
  } else if (Accel_U.WhlAng[0] < Accel_P.SaturationWhlAnd_LowerSat) {
    u0 = Accel_P.SaturationWhlAnd_LowerSat;
  } else {
    u0 = Accel_U.WhlAng[0];
  }

  /* Sum: '<S6>/Sum' incorporates:
   *  Abs: '<S6>/Abs'
   *  Constant: '<S6>/pi half'
   */
  Accel_B.rtb_Switch_j_idx_3 = Accel_P.pihalf_Value - fabs(u0);

  /* Product: '<S6>/Divide' incorporates:
   *  Trigonometry: '<S6>/Cos'
   */
  A_idx_1 = Accel_B.y / cos(Accel_B.rtb_Switch_j_idx_3);

  /* SignalConversion generated from: '<S6>/Vector Concatenate2' */
  rtb_Switch_j_idx_0 = A_idx_1;

  /* Product: '<S6>/Product1' incorporates:
   *  Trigonometry: '<S6>/Sin'
   */
  rtb_Switch_j_idx_2 = A_idx_1 * sin(Accel_B.rtb_Switch_j_idx_3);

  /* Saturate: '<S6>/Saturation WhlAnd' incorporates:
   *  Inport: '<Root>/WhlAng'
   */
  if (Accel_U.WhlAng[1] > Accel_P.SaturationWhlAnd_UpperSat) {
    u0 = Accel_P.SaturationWhlAnd_UpperSat;
  } else if (Accel_U.WhlAng[1] < Accel_P.SaturationWhlAnd_LowerSat) {
    u0 = Accel_P.SaturationWhlAnd_LowerSat;
  } else {
    u0 = Accel_U.WhlAng[1];
  }

  /* Sum: '<S6>/Sum' incorporates:
   *  Abs: '<S6>/Abs'
   *  Constant: '<S6>/pi half'
   */
  Accel_B.rtb_Switch_j_idx_3 = Accel_P.pihalf_Value - fabs(u0);

  /* Product: '<S6>/Divide' incorporates:
   *  Trigonometry: '<S6>/Cos'
   */
  A_idx_1 = Accel_B.y / cos(Accel_B.rtb_Switch_j_idx_3);

  /* Product: '<S6>/Product1' incorporates:
   *  Trigonometry: '<S6>/Sin'
   */
  Accel_B.rtb_Switch_j_idx_3 = A_idx_1 * sin(Accel_B.rtb_Switch_j_idx_3);

  /* Fcn: '<S6>/Fcn' incorporates:
   *  Constant: '<S6>/wheel base1'
   *  SignalConversion generated from: '<S6>/Vector Concatenate1'
   */
  u0 = rt_powd_snf((rtb_Switch_j_idx_2 + Accel_B.rtb_Switch_j_idx_3) / 2.0, 2.0)
    + rt_powd_snf(Accel_P.VEH.RearAxlePositionfromCG, 2.0);

  /* Product: '<S1>/Product' incorporates:
   *  Constant: '<S1>/VelMax'
   *  Inport: '<Root>/AccelPdl'
   */
  Accel_B.y = Accel_P.VEH.MaxSpeed * Accel_U.Accel_i;

  /* Saturate: '<S6>/Saturation RefSpd' */
  if (Accel_B.y > Accel_P.SaturationRefSpd_UpperSat) {
    Accel_B.y = Accel_P.SaturationRefSpd_UpperSat;
  } else {
    if (Accel_B.y < Accel_P.SaturationRefSpd_LowerSat) {
      Accel_B.y = Accel_P.SaturationRefSpd_LowerSat;
    }
  }

  /* End of Saturate: '<S6>/Saturation RefSpd' */

  /* Fcn: '<S6>/Fcn' */
  if (u0 < 0.0) {
    u0 = -sqrt(-u0);
  } else {
    u0 = sqrt(u0);
  }

  /* Product: '<S6>/Divide1' */
  Accel_B.w_v = Accel_B.y / u0;

  /* Saturate: '<S6>/Saturation WhlSpd' incorporates:
   *  Constant: '<S6>/wheel radius'
   *  Product: '<S6>/Divide2'
   *  Product: '<S6>/Product'
   */
  Accel_B.y = rtb_Switch_j_idx_0 / Accel_P.VEH.WheelRadius * Accel_B.w_v;
  u0 = A_idx_1 / Accel_P.VEH.WheelRadius * Accel_B.w_v;
  u0_0 = rtb_Switch_j_idx_2 / Accel_P.VEH.WheelRadius * Accel_B.w_v;
  Accel_B.w_v *= Accel_B.rtb_Switch_j_idx_3 / Accel_P.VEH.WheelRadius;

  /* ComplexToMagnitudeAngle: '<S1>/Complex to Magnitude-Angle' incorporates:
   *  Inport: '<Root>/xdot'
   *  Inport: '<Root>/ydot'
   */
  Accel_B.ComplextoMagnitudeAngle_o1 = rt_hypotd_snf(Accel_U.xdot, Accel_U.ydot);

  /* Gain: '<S5>/Gain' incorporates:
   *  Inport: '<Root>/WhlAng'
   *  Sum: '<S5>/Sum of Elements'
   */
  Accel_B.Gain = (Accel_U.WhlAng[0] + Accel_U.WhlAng[1]) * Accel_P.Gain_Gain;

  /* MATLAB Function: '<S5>/equilibrium point' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant1'
   */
  if ((Accel_B.ComplextoMagnitudeAngle_o1 <= 16.666666666666668) ==
      Accel_B.ComplextoMagnitudeAngle_o1) {
    rtb_ComplextoMagnitudeAngle_o_0 = 0;
  } else if (((Accel_B.ComplextoMagnitudeAngle_o1 > 16.666666666666668) &&
              (Accel_B.ComplextoMagnitudeAngle_o1 <= 22.222222222222221)) ==
             Accel_B.ComplextoMagnitudeAngle_o1) {
    rtb_ComplextoMagnitudeAngle_o_0 = 1;
  } else if (((Accel_B.ComplextoMagnitudeAngle_o1 > 22.222222222222221) &&
              (Accel_B.ComplextoMagnitudeAngle_o1 <= 27.777777777777779)) ==
             Accel_B.ComplextoMagnitudeAngle_o1) {
    rtb_ComplextoMagnitudeAngle_o_0 = 2;
  } else if (((Accel_B.ComplextoMagnitudeAngle_o1 > 27.777777777777779) &&
              (Accel_B.ComplextoMagnitudeAngle_o1 <= 33.333333333333336)) ==
             Accel_B.ComplextoMagnitudeAngle_o1) {
    rtb_ComplextoMagnitudeAngle_o_0 = 3;
  } else {
    rtb_ComplextoMagnitudeAngle_o_0 = -1;
  }

  switch (rtb_ComplextoMagnitudeAngle_o_0) {
   case 0:
    rtb_Switch_j_idx_2 = Accel_P.Constant_Value[0];
    A_idx_1 = Accel_P.Constant_Value[1];
    Accel_B.rtb_d1d2_idx_0 = Accel_P.Constant1_Value_o[0];
    rtb_Switch_j_idx_0 = Accel_P.Constant_Value[10];
    Accel_B.rtb_Switch_j_idx_3 = Accel_P.Constant_Value[11];
    Accel_B.rtb_d1d2_idx_1 = Accel_P.Constant1_Value_o[1];
    break;

   case 1:
    rtb_Switch_j_idx_2 = Accel_P.Constant_Value[2];
    A_idx_1 = Accel_P.Constant_Value[3];
    Accel_B.rtb_d1d2_idx_0 = Accel_P.Constant1_Value_o[2];
    rtb_Switch_j_idx_0 = Accel_P.Constant_Value[12];
    Accel_B.rtb_Switch_j_idx_3 = Accel_P.Constant_Value[13];
    Accel_B.rtb_d1d2_idx_1 = Accel_P.Constant1_Value_o[3];
    break;

   case 2:
    rtb_Switch_j_idx_2 = Accel_P.Constant_Value[4];
    A_idx_1 = Accel_P.Constant_Value[5];
    Accel_B.rtb_d1d2_idx_0 = Accel_P.Constant1_Value_o[4];
    rtb_Switch_j_idx_0 = Accel_P.Constant_Value[14];
    Accel_B.rtb_Switch_j_idx_3 = Accel_P.Constant_Value[15];
    Accel_B.rtb_d1d2_idx_1 = Accel_P.Constant1_Value_o[5];
    break;

   case 3:
    rtb_Switch_j_idx_2 = Accel_P.Constant_Value[6];
    A_idx_1 = Accel_P.Constant_Value[7];
    Accel_B.rtb_d1d2_idx_0 = Accel_P.Constant1_Value_o[6];
    rtb_Switch_j_idx_0 = Accel_P.Constant_Value[16];
    Accel_B.rtb_Switch_j_idx_3 = Accel_P.Constant_Value[17];
    Accel_B.rtb_d1d2_idx_1 = Accel_P.Constant1_Value_o[7];
    break;

   default:
    rtb_Switch_j_idx_2 = Accel_P.Constant_Value[8];
    A_idx_1 = Accel_P.Constant_Value[9];
    Accel_B.rtb_d1d2_idx_0 = Accel_P.Constant1_Value_o[8];
    rtb_Switch_j_idx_0 = Accel_P.Constant_Value[18];
    Accel_B.rtb_Switch_j_idx_3 = Accel_P.Constant_Value[19];
    Accel_B.rtb_d1d2_idx_1 = Accel_P.Constant1_Value_o[9];
    break;
  }

  if (fabs(A_idx_1) > fabs(rtb_Switch_j_idx_2)) {
    Accel_B.r = rtb_Switch_j_idx_2 / A_idx_1;
    Accel_B.t = 1.0 / (Accel_B.r * Accel_B.rtb_Switch_j_idx_3 -
                       rtb_Switch_j_idx_0);
    Accel_B.u[0] = Accel_B.rtb_Switch_j_idx_3 / A_idx_1 * Accel_B.t;
    Accel_B.u[1] = -Accel_B.t;
    Accel_B.u[2] = -rtb_Switch_j_idx_0 / A_idx_1 * Accel_B.t;
    Accel_B.u[3] = Accel_B.r * Accel_B.t;
  } else {
    Accel_B.r = A_idx_1 / rtb_Switch_j_idx_2;
    Accel_B.t = 1.0 / (Accel_B.rtb_Switch_j_idx_3 - Accel_B.r *
                       rtb_Switch_j_idx_0);
    Accel_B.u[0] = Accel_B.rtb_Switch_j_idx_3 / rtb_Switch_j_idx_2 * Accel_B.t;
    Accel_B.u[1] = -Accel_B.r * Accel_B.t;
    Accel_B.u[2] = -rtb_Switch_j_idx_0 / rtb_Switch_j_idx_2 * Accel_B.t;
    Accel_B.u[3] = Accel_B.t;
  }

  Accel_B.r = -Accel_B.u[1] * Accel_B.rtb_d1d2_idx_0 + -Accel_B.u[3] *
    Accel_B.rtb_d1d2_idx_1;

  /* Sum: '<S5>/Subtract' incorporates:
   *  ComplexToMagnitudeAngle: '<S1>/Complex to Magnitude-Angle'
   *  Inport: '<Root>/xdot'
   *  Inport: '<Root>/ydot'
   *  MATLAB Function: '<S5>/equilibrium point'
   */
  Accel_B.rtb_d1d2_idx_0 = rt_atan2d_snf(Accel_U.ydot, Accel_U.xdot) -
    (-Accel_B.u[0] * Accel_B.rtb_d1d2_idx_0 + -Accel_B.u[2] *
     Accel_B.rtb_d1d2_idx_1) * Accel_B.Gain;

  /* Sum: '<S5>/Subtract1' incorporates:
   *  Inport: '<Root>/YawRate'
   *  MATLAB Function: '<S5>/equilibrium point'
   */
  Accel_B.rtb_d1d2_idx_1 = Accel_U.r - Accel_B.r * Accel_B.Gain;

  /* MATLAB Function: '<S2>/Switch control action' incorporates:
   *  Gain: '<S2>/K1'
   *  Gain: '<S2>/K2'
   *  Gain: '<S2>/K3'
   *  Gain: '<S2>/K4'
   *  Gain: '<S2>/K5'
   */
  Accel_B.u[0] = 0.0;
  Accel_B.u[1] = 0.0;
  Accel_B.u[2] = 0.0;
  Accel_B.u[3] = 0.0;
  if ((!(fabs(Accel_B.rtb_d1d2_idx_0 - floor((Accel_B.rtb_d1d2_idx_0 +
           3.1415926535897931) / 6.2831853071795862) * 6.2831853071795862) >
         1.5707963267948966)) && (!(fabs(Accel_B.rtb_d1d2_idx_1) >
        12.566370614359172))) {
    if (Accel_B.ComplextoMagnitudeAngle_o1 <= 16.666666666666668) {
      for (rtb_ComplextoMagnitudeAngle_o_0 = 0; rtb_ComplextoMagnitudeAngle_o_0 <
           4; rtb_ComplextoMagnitudeAngle_o_0++) {
        Accel_B.u[rtb_ComplextoMagnitudeAngle_o_0] =
          Accel_P.Klqr1[rtb_ComplextoMagnitudeAngle_o_0 + 4] *
          Accel_B.rtb_d1d2_idx_1 + Accel_P.Klqr1[rtb_ComplextoMagnitudeAngle_o_0]
          * Accel_B.rtb_d1d2_idx_0;
      }
    } else if ((Accel_B.ComplextoMagnitudeAngle_o1 > 16.666666666666668) &&
               (Accel_B.ComplextoMagnitudeAngle_o1 <= 22.222222222222221)) {
      for (rtb_ComplextoMagnitudeAngle_o_0 = 0; rtb_ComplextoMagnitudeAngle_o_0 <
           4; rtb_ComplextoMagnitudeAngle_o_0++) {
        Accel_B.u[rtb_ComplextoMagnitudeAngle_o_0] =
          Accel_P.Klqr2[rtb_ComplextoMagnitudeAngle_o_0 + 4] *
          Accel_B.rtb_d1d2_idx_1 + Accel_P.Klqr2[rtb_ComplextoMagnitudeAngle_o_0]
          * Accel_B.rtb_d1d2_idx_0;
      }
    } else if ((Accel_B.ComplextoMagnitudeAngle_o1 > 22.222222222222221) &&
               (Accel_B.ComplextoMagnitudeAngle_o1 <= 27.777777777777779)) {
      for (rtb_ComplextoMagnitudeAngle_o_0 = 0; rtb_ComplextoMagnitudeAngle_o_0 <
           4; rtb_ComplextoMagnitudeAngle_o_0++) {
        Accel_B.u[rtb_ComplextoMagnitudeAngle_o_0] =
          Accel_P.Klqr3[rtb_ComplextoMagnitudeAngle_o_0 + 4] *
          Accel_B.rtb_d1d2_idx_1 + Accel_P.Klqr3[rtb_ComplextoMagnitudeAngle_o_0]
          * Accel_B.rtb_d1d2_idx_0;
      }
    } else if ((Accel_B.ComplextoMagnitudeAngle_o1 > 27.777777777777779) &&
               (Accel_B.ComplextoMagnitudeAngle_o1 <= 33.333333333333336)) {
      for (rtb_ComplextoMagnitudeAngle_o_0 = 0; rtb_ComplextoMagnitudeAngle_o_0 <
           4; rtb_ComplextoMagnitudeAngle_o_0++) {
        Accel_B.u[rtb_ComplextoMagnitudeAngle_o_0] =
          Accel_P.Klqr4[rtb_ComplextoMagnitudeAngle_o_0 + 4] *
          Accel_B.rtb_d1d2_idx_1 + Accel_P.Klqr4[rtb_ComplextoMagnitudeAngle_o_0]
          * Accel_B.rtb_d1d2_idx_0;
      }
    } else {
      if (Accel_B.ComplextoMagnitudeAngle_o1 > 33.333333333333336) {
        for (rtb_ComplextoMagnitudeAngle_o_0 = 0;
             rtb_ComplextoMagnitudeAngle_o_0 < 4;
             rtb_ComplextoMagnitudeAngle_o_0++) {
          Accel_B.u[rtb_ComplextoMagnitudeAngle_o_0] =
            Accel_P.Klqr5[rtb_ComplextoMagnitudeAngle_o_0 + 4] *
            Accel_B.rtb_d1d2_idx_1 +
            Accel_P.Klqr5[rtb_ComplextoMagnitudeAngle_o_0] *
            Accel_B.rtb_d1d2_idx_0;
        }
      }
    }
  }

  /* End of MATLAB Function: '<S2>/Switch control action' */

  /* Saturate: '<S6>/Saturation WhlSpd' */
  if (Accel_B.y > Accel_P.SaturationWhlSpd_UpperSat) {
    Accel_B.y = Accel_P.SaturationWhlSpd_UpperSat;
  } else {
    if (Accel_B.y < Accel_P.SaturationWhlSpd_LowerSat) {
      Accel_B.y = Accel_P.SaturationWhlSpd_LowerSat;
    }
  }

  /* Sum: '<S1>/Sum1' incorporates:
   *  Inport: '<Root>/MotSpd'
   *  Sum: '<S1>/Sum'
   */
  rtb_Switch_j_idx_2 = (Accel_B.y + Accel_B.u[0]) - Accel_U.EngSpd[0];

  /* Saturate: '<S6>/Saturation WhlSpd' */
  if (u0 > Accel_P.SaturationWhlSpd_UpperSat) {
    u0 = Accel_P.SaturationWhlSpd_UpperSat;
  } else {
    if (u0 < Accel_P.SaturationWhlSpd_LowerSat) {
      u0 = Accel_P.SaturationWhlSpd_LowerSat;
    }
  }

  /* Sum: '<S1>/Sum1' incorporates:
   *  Inport: '<Root>/MotSpd'
   *  Sum: '<S1>/Sum'
   */
  A_idx_1 = (u0 + Accel_B.u[1]) - Accel_U.EngSpd[1];

  /* Saturate: '<S6>/Saturation WhlSpd' */
  if (Accel_B.w_v > Accel_P.SaturationWhlSpd_UpperSat) {
    Accel_B.w_v = Accel_P.SaturationWhlSpd_UpperSat;
  } else {
    if (Accel_B.w_v < Accel_P.SaturationWhlSpd_LowerSat) {
      Accel_B.w_v = Accel_P.SaturationWhlSpd_LowerSat;
    }
  }

  /* Sum: '<S1>/Sum1' incorporates:
   *  Inport: '<Root>/MotSpd'
   *  Sum: '<S1>/Sum'
   */
  rtb_Switch_j_idx_0 = (Accel_B.w_v + Accel_B.u[2]) - Accel_U.EngSpd[2];

  /* Saturate: '<S6>/Saturation WhlSpd' */
  if (u0_0 > Accel_P.SaturationWhlSpd_UpperSat) {
    u0_0 = Accel_P.SaturationWhlSpd_UpperSat;
  } else {
    if (u0_0 < Accel_P.SaturationWhlSpd_LowerSat) {
      u0_0 = Accel_P.SaturationWhlSpd_LowerSat;
    }
  }

  /* Sum: '<S1>/Sum1' incorporates:
   *  Inport: '<Root>/MotSpd'
   *  Sum: '<S1>/Sum'
   */
  Accel_B.rtb_Switch_j_idx_3 = (u0_0 + Accel_B.u[3]) - Accel_U.EngSpd[3];

  /* Gain: '<S42>/Proportional Gain' */
  u0_0 = Accel_P.DiscretePIDController_P * rtb_Switch_j_idx_2;

  /* Sum: '<S47>/Sum Fdbk' */
  Accel_B.r = u0_0 + Accel_DW.Integrator_DSTATE[0];

  /* Gain: '<S30>/ZeroGain' */
  Accel_B.y = Accel_P.ZeroGain_Gain * Accel_B.r;

  /* DeadZone: '<S30>/DeadZone' */
  if (Accel_B.r > Accel_P.DiscretePIDController_UpperSatu) {
    Accel_B.r -= Accel_P.DiscretePIDController_UpperSatu;
  } else if (Accel_B.r >= Accel_P.DiscretePIDController_LowerSatu) {
    Accel_B.r = 0.0;
  } else {
    Accel_B.r -= Accel_P.DiscretePIDController_LowerSatu;
  }

  /* RelationalOperator: '<S30>/NotEqual' */
  rtb_NotEqual = (Accel_B.y != Accel_B.r);

  /* Signum: '<S30>/SignPreSat' */
  if (Accel_B.r < 0.0) {
    Accel_B.r = -1.0;
  } else if (Accel_B.r > 0.0) {
    Accel_B.r = 1.0;
  } else if (Accel_B.r == 0.0) {
    Accel_B.r = 0.0;
  } else {
    Accel_B.r = (rtNaN);
  }

  /* Gain: '<S34>/Integral Gain' */
  rtb_Switch_j_idx_2 *= Accel_P.DiscretePIDController_I;

  /* DataTypeConversion: '<S30>/DataTypeConv1' */
  if (rtIsNaN(Accel_B.r)) {
    u0 = 0.0;
  } else {
    u0 = fmod(Accel_B.r, 256.0);
  }

  /* Signum: '<S30>/SignPreIntegrator' */
  if (rtb_Switch_j_idx_2 < 0.0) {
    Accel_B.y = -1.0;
  } else if (rtb_Switch_j_idx_2 > 0.0) {
    Accel_B.y = 1.0;
  } else if (rtb_Switch_j_idx_2 == 0.0) {
    Accel_B.y = 0.0;
  } else {
    Accel_B.y = (rtNaN);
  }

  /* DataTypeConversion: '<S30>/DataTypeConv2' */
  if (rtIsNaN(Accel_B.y)) {
    Accel_B.y = 0.0;
  } else {
    Accel_B.y = fmod(Accel_B.y, 256.0);
  }

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Constant1'
   *  DataTypeConversion: '<S30>/DataTypeConv1'
   *  DataTypeConversion: '<S30>/DataTypeConv2'
   *  Logic: '<S30>/AND3'
   *  RelationalOperator: '<S30>/Equal1'
   */
  if (rtb_NotEqual && ((u0 < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)-u0 :
                        (int32_T)(int8_T)(uint8_T)u0) == (Accel_B.y < 0.0 ?
        (int32_T)(int8_T)-(int8_T)(uint8_T)-Accel_B.y : (int32_T)(int8_T)
        (uint8_T)Accel_B.y))) {
    rtb_Switch_j_idx_2 = Accel_P.Constant1_Value;
  }

  /* DiscreteIntegrator: '<S37>/Integrator' */
  Accel_B.r = Accel_P.Integrator_gainval * rtb_Switch_j_idx_2;
  Accel_DW.Integrator_DSTATE[0] += Accel_B.r;

  /* Sum: '<S46>/Sum' */
  u0_0 += Accel_DW.Integrator_DSTATE[0];

  /* Saturate: '<S44>/Saturation' */
  if (u0_0 > Accel_P.DiscretePIDController_UpperSatu) {
    u0_0 = Accel_P.DiscretePIDController_UpperSatu;
  } else {
    if (u0_0 < Accel_P.DiscretePIDController_LowerSatu) {
      u0_0 = Accel_P.DiscretePIDController_LowerSatu;
    }
  }

  /* RelationalOperator: '<S4>/LowerRelop1' */
  rtb_NotEqual = (u0_0 > Accel_Y.TrqCmd[0]);

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S1>/Zero saturation'
   *  RelationalOperator: '<S4>/UpperRelop'
   */
  if (u0_0 < Accel_P.Zerosaturation_Value) {
    u0_0 = Accel_P.Zerosaturation_Value;
  }

  /* Switch: '<S4>/Switch2' */
  if (!rtb_NotEqual) {
    /* Outport: '<Root>/TrqCmd' */
    Accel_Y.TrqCmd[0] = u0_0;
  }

  /* Update for DiscreteIntegrator: '<S37>/Integrator' */
  Accel_DW.Integrator_DSTATE[0] += Accel_B.r;

  /* Gain: '<S42>/Proportional Gain' */
  u0_0 = Accel_P.DiscretePIDController_P * A_idx_1;

  /* Sum: '<S47>/Sum Fdbk' */
  Accel_B.r = u0_0 + Accel_DW.Integrator_DSTATE[1];

  /* Gain: '<S30>/ZeroGain' */
  Accel_B.y = Accel_P.ZeroGain_Gain * Accel_B.r;

  /* DeadZone: '<S30>/DeadZone' */
  if (Accel_B.r > Accel_P.DiscretePIDController_UpperSatu) {
    Accel_B.r -= Accel_P.DiscretePIDController_UpperSatu;
  } else if (Accel_B.r >= Accel_P.DiscretePIDController_LowerSatu) {
    Accel_B.r = 0.0;
  } else {
    Accel_B.r -= Accel_P.DiscretePIDController_LowerSatu;
  }

  /* RelationalOperator: '<S30>/NotEqual' */
  rtb_NotEqual = (Accel_B.y != Accel_B.r);

  /* Signum: '<S30>/SignPreSat' */
  if (Accel_B.r < 0.0) {
    Accel_B.r = -1.0;
  } else if (Accel_B.r > 0.0) {
    Accel_B.r = 1.0;
  } else if (Accel_B.r == 0.0) {
    Accel_B.r = 0.0;
  } else {
    Accel_B.r = (rtNaN);
  }

  /* Gain: '<S34>/Integral Gain' */
  A_idx_1 *= Accel_P.DiscretePIDController_I;

  /* DataTypeConversion: '<S30>/DataTypeConv1' */
  if (rtIsNaN(Accel_B.r)) {
    u0 = 0.0;
  } else {
    u0 = fmod(Accel_B.r, 256.0);
  }

  /* Signum: '<S30>/SignPreIntegrator' */
  if (A_idx_1 < 0.0) {
    Accel_B.y = -1.0;
  } else if (A_idx_1 > 0.0) {
    Accel_B.y = 1.0;
  } else if (A_idx_1 == 0.0) {
    Accel_B.y = 0.0;
  } else {
    Accel_B.y = (rtNaN);
  }

  /* DataTypeConversion: '<S30>/DataTypeConv2' */
  if (rtIsNaN(Accel_B.y)) {
    Accel_B.y = 0.0;
  } else {
    Accel_B.y = fmod(Accel_B.y, 256.0);
  }

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Constant1'
   *  DataTypeConversion: '<S30>/DataTypeConv1'
   *  DataTypeConversion: '<S30>/DataTypeConv2'
   *  Logic: '<S30>/AND3'
   *  RelationalOperator: '<S30>/Equal1'
   */
  if (rtb_NotEqual && ((u0 < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)-u0 :
                        (int32_T)(int8_T)(uint8_T)u0) == (Accel_B.y < 0.0 ?
        (int32_T)(int8_T)-(int8_T)(uint8_T)-Accel_B.y : (int32_T)(int8_T)
        (uint8_T)Accel_B.y))) {
    A_idx_1 = Accel_P.Constant1_Value;
  }

  /* DiscreteIntegrator: '<S37>/Integrator' */
  Accel_B.r = Accel_P.Integrator_gainval * A_idx_1;
  Accel_DW.Integrator_DSTATE[1] += Accel_B.r;

  /* Sum: '<S46>/Sum' */
  u0_0 += Accel_DW.Integrator_DSTATE[1];

  /* Saturate: '<S44>/Saturation' */
  if (u0_0 > Accel_P.DiscretePIDController_UpperSatu) {
    u0_0 = Accel_P.DiscretePIDController_UpperSatu;
  } else {
    if (u0_0 < Accel_P.DiscretePIDController_LowerSatu) {
      u0_0 = Accel_P.DiscretePIDController_LowerSatu;
    }
  }

  /* RelationalOperator: '<S4>/LowerRelop1' */
  rtb_NotEqual = (u0_0 > Accel_Y.TrqCmd[1]);

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S1>/Zero saturation'
   *  RelationalOperator: '<S4>/UpperRelop'
   */
  if (u0_0 < Accel_P.Zerosaturation_Value) {
    u0_0 = Accel_P.Zerosaturation_Value;
  }

  /* Switch: '<S4>/Switch2' */
  if (!rtb_NotEqual) {
    /* Outport: '<Root>/TrqCmd' */
    Accel_Y.TrqCmd[1] = u0_0;
  }

  /* Update for DiscreteIntegrator: '<S37>/Integrator' */
  Accel_DW.Integrator_DSTATE[1] += Accel_B.r;

  /* Gain: '<S42>/Proportional Gain' */
  u0_0 = Accel_P.DiscretePIDController_P * rtb_Switch_j_idx_0;

  /* Sum: '<S47>/Sum Fdbk' */
  Accel_B.r = u0_0 + Accel_DW.Integrator_DSTATE[2];

  /* Gain: '<S30>/ZeroGain' */
  Accel_B.y = Accel_P.ZeroGain_Gain * Accel_B.r;

  /* DeadZone: '<S30>/DeadZone' */
  if (Accel_B.r > Accel_P.DiscretePIDController_UpperSatu) {
    Accel_B.r -= Accel_P.DiscretePIDController_UpperSatu;
  } else if (Accel_B.r >= Accel_P.DiscretePIDController_LowerSatu) {
    Accel_B.r = 0.0;
  } else {
    Accel_B.r -= Accel_P.DiscretePIDController_LowerSatu;
  }

  /* RelationalOperator: '<S30>/NotEqual' */
  rtb_NotEqual = (Accel_B.y != Accel_B.r);

  /* Signum: '<S30>/SignPreSat' */
  if (Accel_B.r < 0.0) {
    Accel_B.r = -1.0;
  } else if (Accel_B.r > 0.0) {
    Accel_B.r = 1.0;
  } else if (Accel_B.r == 0.0) {
    Accel_B.r = 0.0;
  } else {
    Accel_B.r = (rtNaN);
  }

  /* Gain: '<S34>/Integral Gain' */
  rtb_Switch_j_idx_0 *= Accel_P.DiscretePIDController_I;

  /* DataTypeConversion: '<S30>/DataTypeConv1' */
  if (rtIsNaN(Accel_B.r)) {
    u0 = 0.0;
  } else {
    u0 = fmod(Accel_B.r, 256.0);
  }

  /* Signum: '<S30>/SignPreIntegrator' */
  if (rtb_Switch_j_idx_0 < 0.0) {
    Accel_B.y = -1.0;
  } else if (rtb_Switch_j_idx_0 > 0.0) {
    Accel_B.y = 1.0;
  } else if (rtb_Switch_j_idx_0 == 0.0) {
    Accel_B.y = 0.0;
  } else {
    Accel_B.y = (rtNaN);
  }

  /* DataTypeConversion: '<S30>/DataTypeConv2' */
  if (rtIsNaN(Accel_B.y)) {
    Accel_B.y = 0.0;
  } else {
    Accel_B.y = fmod(Accel_B.y, 256.0);
  }

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Constant1'
   *  DataTypeConversion: '<S30>/DataTypeConv1'
   *  DataTypeConversion: '<S30>/DataTypeConv2'
   *  Logic: '<S30>/AND3'
   *  RelationalOperator: '<S30>/Equal1'
   */
  if (rtb_NotEqual && ((u0 < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)-u0 :
                        (int32_T)(int8_T)(uint8_T)u0) == (Accel_B.y < 0.0 ?
        (int32_T)(int8_T)-(int8_T)(uint8_T)-Accel_B.y : (int32_T)(int8_T)
        (uint8_T)Accel_B.y))) {
    rtb_Switch_j_idx_0 = Accel_P.Constant1_Value;
  }

  /* DiscreteIntegrator: '<S37>/Integrator' */
  Accel_B.r = Accel_P.Integrator_gainval * rtb_Switch_j_idx_0;
  Accel_DW.Integrator_DSTATE[2] += Accel_B.r;

  /* Sum: '<S46>/Sum' */
  u0_0 += Accel_DW.Integrator_DSTATE[2];

  /* Saturate: '<S44>/Saturation' */
  if (u0_0 > Accel_P.DiscretePIDController_UpperSatu) {
    u0_0 = Accel_P.DiscretePIDController_UpperSatu;
  } else {
    if (u0_0 < Accel_P.DiscretePIDController_LowerSatu) {
      u0_0 = Accel_P.DiscretePIDController_LowerSatu;
    }
  }

  /* RelationalOperator: '<S4>/LowerRelop1' */
  rtb_NotEqual = (u0_0 > Accel_Y.TrqCmd[2]);

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S1>/Zero saturation'
   *  RelationalOperator: '<S4>/UpperRelop'
   */
  if (u0_0 < Accel_P.Zerosaturation_Value) {
    u0_0 = Accel_P.Zerosaturation_Value;
  }

  /* Switch: '<S4>/Switch2' */
  if (!rtb_NotEqual) {
    /* Outport: '<Root>/TrqCmd' */
    Accel_Y.TrqCmd[2] = u0_0;
  }

  /* Update for DiscreteIntegrator: '<S37>/Integrator' */
  Accel_DW.Integrator_DSTATE[2] += Accel_B.r;

  /* Gain: '<S42>/Proportional Gain' */
  u0_0 = Accel_P.DiscretePIDController_P * Accel_B.rtb_Switch_j_idx_3;

  /* Sum: '<S47>/Sum Fdbk' */
  Accel_B.r = u0_0 + Accel_DW.Integrator_DSTATE[3];

  /* Gain: '<S30>/ZeroGain' */
  Accel_B.y = Accel_P.ZeroGain_Gain * Accel_B.r;

  /* DeadZone: '<S30>/DeadZone' */
  if (Accel_B.r > Accel_P.DiscretePIDController_UpperSatu) {
    Accel_B.r -= Accel_P.DiscretePIDController_UpperSatu;
  } else if (Accel_B.r >= Accel_P.DiscretePIDController_LowerSatu) {
    Accel_B.r = 0.0;
  } else {
    Accel_B.r -= Accel_P.DiscretePIDController_LowerSatu;
  }

  /* RelationalOperator: '<S30>/NotEqual' */
  rtb_NotEqual = (Accel_B.y != Accel_B.r);

  /* Signum: '<S30>/SignPreSat' */
  if (Accel_B.r < 0.0) {
    Accel_B.r = -1.0;
  } else if (Accel_B.r > 0.0) {
    Accel_B.r = 1.0;
  } else if (Accel_B.r == 0.0) {
    Accel_B.r = 0.0;
  } else {
    Accel_B.r = (rtNaN);
  }

  /* Gain: '<S34>/Integral Gain' */
  Accel_B.rtb_Switch_j_idx_3 *= Accel_P.DiscretePIDController_I;

  /* DataTypeConversion: '<S30>/DataTypeConv1' */
  if (rtIsNaN(Accel_B.r)) {
    u0 = 0.0;
  } else {
    u0 = fmod(Accel_B.r, 256.0);
  }

  /* Signum: '<S30>/SignPreIntegrator' */
  if (Accel_B.rtb_Switch_j_idx_3 < 0.0) {
    Accel_B.y = -1.0;
  } else if (Accel_B.rtb_Switch_j_idx_3 > 0.0) {
    Accel_B.y = 1.0;
  } else if (Accel_B.rtb_Switch_j_idx_3 == 0.0) {
    Accel_B.y = 0.0;
  } else {
    Accel_B.y = (rtNaN);
  }

  /* DataTypeConversion: '<S30>/DataTypeConv2' */
  if (rtIsNaN(Accel_B.y)) {
    Accel_B.y = 0.0;
  } else {
    Accel_B.y = fmod(Accel_B.y, 256.0);
  }

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Constant1'
   *  DataTypeConversion: '<S30>/DataTypeConv1'
   *  DataTypeConversion: '<S30>/DataTypeConv2'
   *  Logic: '<S30>/AND3'
   *  RelationalOperator: '<S30>/Equal1'
   */
  if (rtb_NotEqual && ((u0 < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)-u0 :
                        (int32_T)(int8_T)(uint8_T)u0) == (Accel_B.y < 0.0 ?
        (int32_T)(int8_T)-(int8_T)(uint8_T)-Accel_B.y : (int32_T)(int8_T)
        (uint8_T)Accel_B.y))) {
    Accel_B.rtb_Switch_j_idx_3 = Accel_P.Constant1_Value;
  }

  /* DiscreteIntegrator: '<S37>/Integrator' */
  Accel_B.r = Accel_P.Integrator_gainval * Accel_B.rtb_Switch_j_idx_3;
  Accel_DW.Integrator_DSTATE[3] += Accel_B.r;

  /* Sum: '<S46>/Sum' */
  u0_0 += Accel_DW.Integrator_DSTATE[3];

  /* Saturate: '<S44>/Saturation' */
  if (u0_0 > Accel_P.DiscretePIDController_UpperSatu) {
    u0_0 = Accel_P.DiscretePIDController_UpperSatu;
  } else {
    if (u0_0 < Accel_P.DiscretePIDController_LowerSatu) {
      u0_0 = Accel_P.DiscretePIDController_LowerSatu;
    }
  }

  /* RelationalOperator: '<S4>/LowerRelop1' */
  rtb_NotEqual = (u0_0 > Accel_Y.TrqCmd[3]);

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S1>/Zero saturation'
   *  RelationalOperator: '<S4>/UpperRelop'
   */
  if (u0_0 < Accel_P.Zerosaturation_Value) {
    u0_0 = Accel_P.Zerosaturation_Value;
  }

  /* Switch: '<S4>/Switch2' */
  if (!rtb_NotEqual) {
    /* Outport: '<Root>/TrqCmd' */
    Accel_Y.TrqCmd[3] = u0_0;
  }

  /* Update for DiscreteIntegrator: '<S37>/Integrator' */
  Accel_DW.Integrator_DSTATE[3] += Accel_B.r;
}

/* Model initialize function */
void Accel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for DiscreteIntegrator: '<S37>/Integrator' */
  Accel_DW.Integrator_DSTATE[0] = Accel_P.DiscretePIDController_InitialCo;
  Accel_DW.Integrator_DSTATE[1] = Accel_P.DiscretePIDController_InitialCo;
  Accel_DW.Integrator_DSTATE[2] = Accel_P.DiscretePIDController_InitialCo;
  Accel_DW.Integrator_DSTATE[3] = Accel_P.DiscretePIDController_InitialCo;
}

/* Model terminate function */
void Accel_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
