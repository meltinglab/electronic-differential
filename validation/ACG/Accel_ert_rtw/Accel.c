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
 * C/C++ source code generated on : Tue Jul  7 17:05:20 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Accel.h"
#include "Accel_private.h"

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

/* Model step function */
void Accel_step(void)
{
  real_T A[4];
  real_T r;
  real_T t;
  real_T rtb_Gain;
  real_T rtb_ComplextoMagnitudeAngle_o1;
  boolean_T rtb_NotEqual;
  real_T B1_idx_0;
  real_T rtb_Switch_j_idx_0;
  int32_T rtb_ComplextoMagnitudeAngle_o_0;

  /* Outputs for Atomic SubSystem: '<Root>/Accel Pedal to Traction Wheel Torque Request' */
  /* ComplexToMagnitudeAngle: '<S1>/Complex to Magnitude-Angle' incorporates:
   *  Inport: '<Root>/xdot'
   *  Inport: '<Root>/ydot'
   */
  rtb_ComplextoMagnitudeAngle_o1 = rt_hypotd_snf(Accel_U.xdot, Accel_U.ydot);

  /* Gain: '<S5>/Gain' incorporates:
   *  Inport: '<Root>/WhlAng'
   *  Sum: '<S5>/Sum of Elements'
   */
  rtb_Gain = (Accel_U.WhlAng[0] + Accel_U.WhlAng[1]) * 0.5;

  /* MATLAB Function: '<S5>/equilibrium point' */
  if ((rtb_ComplextoMagnitudeAngle_o1 <= 16.666666666666668) ==
      rtb_ComplextoMagnitudeAngle_o1) {
    rtb_ComplextoMagnitudeAngle_o_0 = 0;
  } else if (((rtb_ComplextoMagnitudeAngle_o1 > 16.666666666666668) &&
              (rtb_ComplextoMagnitudeAngle_o1 <= 22.222222222222221)) ==
             rtb_ComplextoMagnitudeAngle_o1) {
    rtb_ComplextoMagnitudeAngle_o_0 = 1;
  } else if (((rtb_ComplextoMagnitudeAngle_o1 > 22.222222222222221) &&
              (rtb_ComplextoMagnitudeAngle_o1 <= 27.777777777777779)) ==
             rtb_ComplextoMagnitudeAngle_o1) {
    rtb_ComplextoMagnitudeAngle_o_0 = 2;
  } else if (((rtb_ComplextoMagnitudeAngle_o1 > 27.777777777777779) &&
              (rtb_ComplextoMagnitudeAngle_o1 <= 33.333333333333336)) ==
             rtb_ComplextoMagnitudeAngle_o1) {
    rtb_ComplextoMagnitudeAngle_o_0 = 3;
  } else {
    rtb_ComplextoMagnitudeAngle_o_0 = -1;
  }

  switch (rtb_ComplextoMagnitudeAngle_o_0) {
   case 0:
    A[0] = -16.258886028;
    B1_idx_0 = 8.09982265190858;
    A[2] = -0.99999999999999978;
    A[3] = -5.3210811557468372;
    break;

   case 1:
    A[0] = -11.61349002;
    B1_idx_0 = 5.7855876085061286;
    A[2] = -1.0;
    A[3] = -3.8007722541048841;
    break;

   case 2:
    A[0] = -9.03271446;
    B1_idx_0 = 4.4999014732825442;
    A[2] = -1.0;
    A[3] = -2.9561561976371316;
    break;

   case 3:
    A[0] = -7.3904027400000007;
    B1_idx_0 = 3.6817375690493548;
    A[2] = -1.0;
    A[3] = -2.4186732526121988;
    break;

   default:
    A[0] = -6.2534177030769236;
    B1_idx_0 = 3.1153164045802231;
    A[2] = -1.0;
    A[3] = -2.0465696752872451;
    break;
  }

  r = 2.6112791887579569E-15 / A[0];
  t = 1.0 / (A[3] - r * A[2]);
  r = -(-r * t) * B1_idx_0 + -t * 18.059623820272346;

  /* Sum: '<S5>/Subtract' incorporates:
   *  ComplexToMagnitudeAngle: '<S1>/Complex to Magnitude-Angle'
   *  Inport: '<Root>/xdot'
   *  Inport: '<Root>/ydot'
   *  MATLAB Function: '<S5>/equilibrium point'
   */
  B1_idx_0 = rt_atan2d_snf(Accel_U.ydot, Accel_U.xdot) - (-(A[3] / A[0] * t) *
    B1_idx_0 + -(-A[2] / A[0] * t) * 18.059623820272346) * rtb_Gain;

  /* Sum: '<S5>/Subtract1' incorporates:
   *  Inport: '<Root>/YawRate'
   *  MATLAB Function: '<S5>/equilibrium point'
   */
  r = Accel_U.r - r * rtb_Gain;

  /* MATLAB Function: '<S2>/Switch control action' incorporates:
   *  Gain: '<S2>/K1'
   *  Gain: '<S2>/K2'
   *  Gain: '<S2>/K3'
   *  Gain: '<S2>/K4'
   *  Gain: '<S2>/K5'
   */
  A[0] = 0.0;
  A[1] = 0.0;
  A[2] = 0.0;
  A[3] = 0.0;
  if ((!(fabs(B1_idx_0 - floor((B1_idx_0 + 3.1415926535897931) /
          6.2831853071795862) * 6.2831853071795862) > 1.5707963267948966)) &&
      (!(fabs(r) > 12.566370614359172))) {
    if ((rtb_ComplextoMagnitudeAngle_o1 <= 16.666666666666668) ==
        rtb_ComplextoMagnitudeAngle_o1) {
      rtb_ComplextoMagnitudeAngle_o_0 = 0;
    } else if (((rtb_ComplextoMagnitudeAngle_o1 > 16.666666666666668) &&
                (rtb_ComplextoMagnitudeAngle_o1 <= 22.222222222222221)) ==
               rtb_ComplextoMagnitudeAngle_o1) {
      rtb_ComplextoMagnitudeAngle_o_0 = 1;
    } else if (((rtb_ComplextoMagnitudeAngle_o1 > 22.222222222222221) &&
                (rtb_ComplextoMagnitudeAngle_o1 <= 27.777777777777779)) ==
               rtb_ComplextoMagnitudeAngle_o1) {
      rtb_ComplextoMagnitudeAngle_o_0 = 2;
    } else if (((rtb_ComplextoMagnitudeAngle_o1 > 27.777777777777779) &&
                (rtb_ComplextoMagnitudeAngle_o1 <= 33.333333333333336)) ==
               rtb_ComplextoMagnitudeAngle_o1) {
      rtb_ComplextoMagnitudeAngle_o_0 = 3;
    } else if ((rtb_ComplextoMagnitudeAngle_o1 > 33.333333333333336) ==
               rtb_ComplextoMagnitudeAngle_o1) {
      rtb_ComplextoMagnitudeAngle_o_0 = 4;
    } else {
      rtb_ComplextoMagnitudeAngle_o_0 = -1;
    }

    switch (rtb_ComplextoMagnitudeAngle_o_0) {
     case 0:
      for (rtb_ComplextoMagnitudeAngle_o_0 = 0; rtb_ComplextoMagnitudeAngle_o_0 <
           4; rtb_ComplextoMagnitudeAngle_o_0++) {
        A[rtb_ComplextoMagnitudeAngle_o_0] =
          Accel_ConstP.K1_Gain[rtb_ComplextoMagnitudeAngle_o_0 + 4] * r +
          Accel_ConstP.K1_Gain[rtb_ComplextoMagnitudeAngle_o_0] * B1_idx_0;
      }
      break;

     case 1:
      for (rtb_ComplextoMagnitudeAngle_o_0 = 0; rtb_ComplextoMagnitudeAngle_o_0 <
           4; rtb_ComplextoMagnitudeAngle_o_0++) {
        A[rtb_ComplextoMagnitudeAngle_o_0] =
          Accel_ConstP.K2_Gain[rtb_ComplextoMagnitudeAngle_o_0 + 4] * r +
          Accel_ConstP.K2_Gain[rtb_ComplextoMagnitudeAngle_o_0] * B1_idx_0;
      }
      break;

     case 2:
      for (rtb_ComplextoMagnitudeAngle_o_0 = 0; rtb_ComplextoMagnitudeAngle_o_0 <
           4; rtb_ComplextoMagnitudeAngle_o_0++) {
        A[rtb_ComplextoMagnitudeAngle_o_0] =
          Accel_ConstP.K3_Gain[rtb_ComplextoMagnitudeAngle_o_0 + 4] * r +
          Accel_ConstP.K3_Gain[rtb_ComplextoMagnitudeAngle_o_0] * B1_idx_0;
      }
      break;

     case 3:
      for (rtb_ComplextoMagnitudeAngle_o_0 = 0; rtb_ComplextoMagnitudeAngle_o_0 <
           4; rtb_ComplextoMagnitudeAngle_o_0++) {
        A[rtb_ComplextoMagnitudeAngle_o_0] =
          Accel_ConstP.K4_Gain[rtb_ComplextoMagnitudeAngle_o_0 + 4] * r +
          Accel_ConstP.K4_Gain[rtb_ComplextoMagnitudeAngle_o_0] * B1_idx_0;
      }
      break;

     case 4:
      for (rtb_ComplextoMagnitudeAngle_o_0 = 0; rtb_ComplextoMagnitudeAngle_o_0 <
           4; rtb_ComplextoMagnitudeAngle_o_0++) {
        A[rtb_ComplextoMagnitudeAngle_o_0] =
          Accel_ConstP.K5_Gain[rtb_ComplextoMagnitudeAngle_o_0 + 4] * r +
          Accel_ConstP.K5_Gain[rtb_ComplextoMagnitudeAngle_o_0] * B1_idx_0;
      }
      break;
    }
  }

  /* End of MATLAB Function: '<S2>/Switch control action' */

  /* Saturate: '<S6>/Saturation WhlAnd' incorporates:
   *  Inport: '<Root>/WhlAng'
   */
  if (Accel_U.WhlAng[0] > 1.3089969389957472) {
    B1_idx_0 = 1.3089969389957472;
  } else if (Accel_U.WhlAng[0] < -1.3089969389957472) {
    B1_idx_0 = -1.3089969389957472;
  } else {
    B1_idx_0 = Accel_U.WhlAng[0];
  }

  /* Sum: '<S6>/Sum' incorporates:
   *  Abs: '<S6>/Abs'
   *  Constant: '<S6>/pi half'
   */
  rtb_ComplextoMagnitudeAngle_o1 = 1.5707963267948966 - fabs(B1_idx_0);

  /* Product: '<S6>/Divide' incorporates:
   *  Constant: '<S6>/wheel base'
   *  Trigonometry: '<S6>/Cos'
   */
  t = 3.019 / cos(rtb_ComplextoMagnitudeAngle_o1);

  /* SignalConversion generated from: '<S6>/Vector Concatenate2' */
  rtb_Switch_j_idx_0 = t;

  /* Product: '<S6>/Product1' incorporates:
   *  Trigonometry: '<S6>/Sin'
   */
  r = t * sin(rtb_ComplextoMagnitudeAngle_o1);

  /* Saturate: '<S6>/Saturation WhlAnd' incorporates:
   *  Inport: '<Root>/WhlAng'
   */
  if (Accel_U.WhlAng[1] > 1.3089969389957472) {
    B1_idx_0 = 1.3089969389957472;
  } else if (Accel_U.WhlAng[1] < -1.3089969389957472) {
    B1_idx_0 = -1.3089969389957472;
  } else {
    B1_idx_0 = Accel_U.WhlAng[1];
  }

  /* Sum: '<S6>/Sum' incorporates:
   *  Abs: '<S6>/Abs'
   *  Constant: '<S6>/pi half'
   */
  rtb_ComplextoMagnitudeAngle_o1 = 1.5707963267948966 - fabs(B1_idx_0);

  /* Product: '<S6>/Divide' incorporates:
   *  Constant: '<S6>/wheel base'
   *  Trigonometry: '<S6>/Cos'
   */
  t = 3.019 / cos(rtb_ComplextoMagnitudeAngle_o1);

  /* Product: '<S6>/Product1' incorporates:
   *  Trigonometry: '<S6>/Sin'
   */
  rtb_Gain = t * sin(rtb_ComplextoMagnitudeAngle_o1);

  /* Fcn: '<S6>/Fcn' incorporates:
   *  SignalConversion generated from: '<S6>/Vector Concatenate1'
   */
  B1_idx_0 = rt_powd_snf((r + rtb_Gain) / 2.0, 2.0) + 2.262016;

  /* Product: '<S1>/Product' incorporates:
   *  Constant: '<S1>/VelMax'
   *  Inport: '<Root>/AccelPdl'
   */
  rtb_ComplextoMagnitudeAngle_o1 = 44.444444444444443 * Accel_U.AccelPdl;

  /* Saturate: '<S6>/Saturation RefSpd' */
  if (rtb_ComplextoMagnitudeAngle_o1 > 120.0) {
    rtb_ComplextoMagnitudeAngle_o1 = 120.0;
  } else {
    if (rtb_ComplextoMagnitudeAngle_o1 < -120.0) {
      rtb_ComplextoMagnitudeAngle_o1 = -120.0;
    }
  }

  /* End of Saturate: '<S6>/Saturation RefSpd' */

  /* Fcn: '<S6>/Fcn' */
  if (B1_idx_0 < 0.0) {
    B1_idx_0 = -sqrt(-B1_idx_0);
  } else {
    B1_idx_0 = sqrt(B1_idx_0);
  }

  /* Product: '<S6>/Divide1' */
  B1_idx_0 = rtb_ComplextoMagnitudeAngle_o1 / B1_idx_0;

  /* Saturate: '<S6>/Saturation WhlSpd' incorporates:
   *  Constant: '<S6>/wheel radius'
   *  Product: '<S6>/Divide2'
   *  Product: '<S6>/Product'
   */
  rtb_ComplextoMagnitudeAngle_o1 = rtb_Switch_j_idx_0 / 0.31 * B1_idx_0;
  t = t / 0.31 * B1_idx_0;
  r = r / 0.31 * B1_idx_0;
  B1_idx_0 *= rtb_Gain / 0.31;
  if (rtb_ComplextoMagnitudeAngle_o1 > 600.0) {
    rtb_ComplextoMagnitudeAngle_o1 = 600.0;
  } else {
    if (rtb_ComplextoMagnitudeAngle_o1 < -600.0) {
      rtb_ComplextoMagnitudeAngle_o1 = -600.0;
    }
  }

  /* Sum: '<S1>/Sum1' incorporates:
   *  Inport: '<Root>/MotSpd'
   *  Sum: '<S1>/Sum'
   */
  Accel_Y.TrqCmd[0] = (rtb_ComplextoMagnitudeAngle_o1 + A[0]) - Accel_U.MotSpd[0];

  /* Saturate: '<S6>/Saturation WhlSpd' */
  if (t > 600.0) {
    t = 600.0;
  } else {
    if (t < -600.0) {
      t = -600.0;
    }
  }

  /* Sum: '<S1>/Sum1' incorporates:
   *  Inport: '<Root>/MotSpd'
   *  Sum: '<S1>/Sum'
   */
  Accel_Y.TrqCmd[1] = (t + A[1]) - Accel_U.MotSpd[1];

  /* Saturate: '<S6>/Saturation WhlSpd' */
  if (B1_idx_0 > 600.0) {
    B1_idx_0 = 600.0;
  } else {
    if (B1_idx_0 < -600.0) {
      B1_idx_0 = -600.0;
    }
  }

  /* Sum: '<S1>/Sum1' incorporates:
   *  Inport: '<Root>/MotSpd'
   *  Sum: '<S1>/Sum'
   */
  Accel_Y.TrqCmd[2] = (B1_idx_0 + A[2]) - Accel_U.MotSpd[2];

  /* Saturate: '<S6>/Saturation WhlSpd' */
  if (r > 600.0) {
    r = 600.0;
  } else {
    if (r < -600.0) {
      r = -600.0;
    }
  }

  /* Sum: '<S1>/Sum1' incorporates:
   *  Inport: '<Root>/MotSpd'
   *  Sum: '<S1>/Sum'
   */
  Accel_Y.TrqCmd[3] = (r + A[3]) - Accel_U.MotSpd[3];

  /* Gain: '<S42>/Proportional Gain' */
  rtb_ComplextoMagnitudeAngle_o1 = 4.5 * Accel_Y.TrqCmd[0];

  /* Sum: '<S47>/Sum Fdbk' */
  B1_idx_0 = rtb_ComplextoMagnitudeAngle_o1 + Accel_DW.Integrator_DSTATE[0];

  /* Gain: '<S30>/ZeroGain' */
  r = 0.0 * B1_idx_0;

  /* DeadZone: '<S30>/DeadZone' */
  if (B1_idx_0 > 280.0) {
    B1_idx_0 -= 280.0;
  } else {
    if (B1_idx_0 >= 0.0) {
      B1_idx_0 = 0.0;
    }
  }

  /* RelationalOperator: '<S30>/NotEqual' */
  rtb_NotEqual = (r != B1_idx_0);

  /* Signum: '<S30>/SignPreSat' */
  if (B1_idx_0 < 0.0) {
    B1_idx_0 = -1.0;
  } else if (B1_idx_0 > 0.0) {
    B1_idx_0 = 1.0;
  } else if (B1_idx_0 == 0.0) {
    B1_idx_0 = 0.0;
  } else {
    B1_idx_0 = (rtNaN);
  }

  /* Gain: '<S34>/Integral Gain' */
  Accel_Y.TrqCmd[0] *= 0.1;

  /* DataTypeConversion: '<S30>/DataTypeConv1' */
  if (rtIsNaN(B1_idx_0)) {
    B1_idx_0 = 0.0;
  } else {
    B1_idx_0 = fmod(B1_idx_0, 256.0);
  }

  /* Signum: '<S30>/SignPreIntegrator' incorporates:
   *  Logic: '<S30>/AND3'
   */
  if (Accel_Y.TrqCmd[0] < 0.0) {
    r = -1.0;
  } else if (Accel_Y.TrqCmd[0] > 0.0) {
    r = 1.0;
  } else if (Accel_Y.TrqCmd[0] == 0.0) {
    r = 0.0;
  } else {
    r = (rtNaN);
  }

  /* DataTypeConversion: '<S30>/DataTypeConv2' */
  if (rtIsNaN(r)) {
    r = 0.0;
  } else {
    r = fmod(r, 256.0);
  }

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Constant1'
   *  DataTypeConversion: '<S30>/DataTypeConv1'
   *  DataTypeConversion: '<S30>/DataTypeConv2'
   *  Logic: '<S30>/AND3'
   *  RelationalOperator: '<S30>/Equal1'
   */
  if (rtb_NotEqual && ((B1_idx_0 < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)
                        -B1_idx_0 : (int32_T)(int8_T)(uint8_T)B1_idx_0) == (r <
        0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)-r : (int32_T)(int8_T)(uint8_T)
        r))) {
    B1_idx_0 = 0.0;
  } else {
    B1_idx_0 = Accel_Y.TrqCmd[0];
  }

  /* DiscreteIntegrator: '<S37>/Integrator' */
  B1_idx_0 *= 0.3;
  Accel_DW.Integrator_DSTATE[0] += B1_idx_0;

  /* Sum: '<S46>/Sum' */
  rtb_ComplextoMagnitudeAngle_o1 += Accel_DW.Integrator_DSTATE[0];

  /* Saturate: '<S44>/Saturation' */
  if (rtb_ComplextoMagnitudeAngle_o1 > 280.0) {
    rtb_ComplextoMagnitudeAngle_o1 = 280.0;
  } else {
    if (rtb_ComplextoMagnitudeAngle_o1 < 0.0) {
      rtb_ComplextoMagnitudeAngle_o1 = 0.0;
    }
  }

  /* Gain: '<S1>/rads_to_rpm' incorporates:
   *  Inport: '<Root>/MotSpd'
   */
  Accel_Y.TrqCmd[0] = 9.5492965855137211 * Accel_U.MotSpd[0];

  /* Lookup_n-D: '<S1>/MaxMotTrqVsSpd' */
  Accel_Y.TrqCmd[0] = look1_binlcapw(Accel_Y.TrqCmd[0],
    Accel_ConstP.MaxMotTrqVsSpd_bp01Data, Accel_ConstP.MaxMotTrqVsSpd_tableData,
    11U);

  /* Update for DiscreteIntegrator: '<S37>/Integrator' */
  Accel_DW.Integrator_DSTATE[0] += B1_idx_0;

  /* Switch: '<S4>/Switch2' incorporates:
   *  RelationalOperator: '<S4>/LowerRelop1'
   */
  if (!(rtb_ComplextoMagnitudeAngle_o1 > Accel_Y.TrqCmd[0])) {
    /* Outport: '<Root>/TrqCmd' */
    Accel_Y.TrqCmd[0] = rtb_ComplextoMagnitudeAngle_o1;
  }

  /* Gain: '<S42>/Proportional Gain' */
  rtb_ComplextoMagnitudeAngle_o1 = 4.5 * Accel_Y.TrqCmd[1];

  /* Sum: '<S47>/Sum Fdbk' */
  B1_idx_0 = rtb_ComplextoMagnitudeAngle_o1 + Accel_DW.Integrator_DSTATE[1];

  /* Gain: '<S30>/ZeroGain' */
  r = 0.0 * B1_idx_0;

  /* DeadZone: '<S30>/DeadZone' */
  if (B1_idx_0 > 280.0) {
    B1_idx_0 -= 280.0;
  } else {
    if (B1_idx_0 >= 0.0) {
      B1_idx_0 = 0.0;
    }
  }

  /* RelationalOperator: '<S30>/NotEqual' */
  rtb_NotEqual = (r != B1_idx_0);

  /* Signum: '<S30>/SignPreSat' */
  if (B1_idx_0 < 0.0) {
    B1_idx_0 = -1.0;
  } else if (B1_idx_0 > 0.0) {
    B1_idx_0 = 1.0;
  } else if (B1_idx_0 == 0.0) {
    B1_idx_0 = 0.0;
  } else {
    B1_idx_0 = (rtNaN);
  }

  /* Gain: '<S34>/Integral Gain' */
  Accel_Y.TrqCmd[1] *= 0.1;

  /* DataTypeConversion: '<S30>/DataTypeConv1' */
  if (rtIsNaN(B1_idx_0)) {
    B1_idx_0 = 0.0;
  } else {
    B1_idx_0 = fmod(B1_idx_0, 256.0);
  }

  /* Signum: '<S30>/SignPreIntegrator' incorporates:
   *  Logic: '<S30>/AND3'
   */
  if (Accel_Y.TrqCmd[1] < 0.0) {
    r = -1.0;
  } else if (Accel_Y.TrqCmd[1] > 0.0) {
    r = 1.0;
  } else if (Accel_Y.TrqCmd[1] == 0.0) {
    r = 0.0;
  } else {
    r = (rtNaN);
  }

  /* DataTypeConversion: '<S30>/DataTypeConv2' */
  if (rtIsNaN(r)) {
    r = 0.0;
  } else {
    r = fmod(r, 256.0);
  }

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Constant1'
   *  DataTypeConversion: '<S30>/DataTypeConv1'
   *  DataTypeConversion: '<S30>/DataTypeConv2'
   *  Logic: '<S30>/AND3'
   *  RelationalOperator: '<S30>/Equal1'
   */
  if (rtb_NotEqual && ((B1_idx_0 < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)
                        -B1_idx_0 : (int32_T)(int8_T)(uint8_T)B1_idx_0) == (r <
        0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)-r : (int32_T)(int8_T)(uint8_T)
        r))) {
    B1_idx_0 = 0.0;
  } else {
    B1_idx_0 = Accel_Y.TrqCmd[1];
  }

  /* DiscreteIntegrator: '<S37>/Integrator' */
  B1_idx_0 *= 0.3;
  Accel_DW.Integrator_DSTATE[1] += B1_idx_0;

  /* Sum: '<S46>/Sum' */
  rtb_ComplextoMagnitudeAngle_o1 += Accel_DW.Integrator_DSTATE[1];

  /* Saturate: '<S44>/Saturation' */
  if (rtb_ComplextoMagnitudeAngle_o1 > 280.0) {
    rtb_ComplextoMagnitudeAngle_o1 = 280.0;
  } else {
    if (rtb_ComplextoMagnitudeAngle_o1 < 0.0) {
      rtb_ComplextoMagnitudeAngle_o1 = 0.0;
    }
  }

  /* Gain: '<S1>/rads_to_rpm' incorporates:
   *  Inport: '<Root>/MotSpd'
   */
  Accel_Y.TrqCmd[1] = 9.5492965855137211 * Accel_U.MotSpd[1];

  /* Lookup_n-D: '<S1>/MaxMotTrqVsSpd' */
  Accel_Y.TrqCmd[1] = look1_binlcapw(Accel_Y.TrqCmd[1],
    Accel_ConstP.MaxMotTrqVsSpd_bp01Data, Accel_ConstP.MaxMotTrqVsSpd_tableData,
    11U);

  /* Update for DiscreteIntegrator: '<S37>/Integrator' */
  Accel_DW.Integrator_DSTATE[1] += B1_idx_0;

  /* Switch: '<S4>/Switch2' incorporates:
   *  RelationalOperator: '<S4>/LowerRelop1'
   */
  if (!(rtb_ComplextoMagnitudeAngle_o1 > Accel_Y.TrqCmd[1])) {
    /* Outport: '<Root>/TrqCmd' */
    Accel_Y.TrqCmd[1] = rtb_ComplextoMagnitudeAngle_o1;
  }

  /* Gain: '<S42>/Proportional Gain' */
  rtb_ComplextoMagnitudeAngle_o1 = 4.5 * Accel_Y.TrqCmd[2];

  /* Sum: '<S47>/Sum Fdbk' */
  B1_idx_0 = rtb_ComplextoMagnitudeAngle_o1 + Accel_DW.Integrator_DSTATE[2];

  /* Gain: '<S30>/ZeroGain' */
  r = 0.0 * B1_idx_0;

  /* DeadZone: '<S30>/DeadZone' */
  if (B1_idx_0 > 280.0) {
    B1_idx_0 -= 280.0;
  } else {
    if (B1_idx_0 >= 0.0) {
      B1_idx_0 = 0.0;
    }
  }

  /* RelationalOperator: '<S30>/NotEqual' */
  rtb_NotEqual = (r != B1_idx_0);

  /* Signum: '<S30>/SignPreSat' */
  if (B1_idx_0 < 0.0) {
    B1_idx_0 = -1.0;
  } else if (B1_idx_0 > 0.0) {
    B1_idx_0 = 1.0;
  } else if (B1_idx_0 == 0.0) {
    B1_idx_0 = 0.0;
  } else {
    B1_idx_0 = (rtNaN);
  }

  /* Gain: '<S34>/Integral Gain' */
  Accel_Y.TrqCmd[2] *= 0.1;

  /* DataTypeConversion: '<S30>/DataTypeConv1' */
  if (rtIsNaN(B1_idx_0)) {
    B1_idx_0 = 0.0;
  } else {
    B1_idx_0 = fmod(B1_idx_0, 256.0);
  }

  /* Signum: '<S30>/SignPreIntegrator' incorporates:
   *  Logic: '<S30>/AND3'
   */
  if (Accel_Y.TrqCmd[2] < 0.0) {
    r = -1.0;
  } else if (Accel_Y.TrqCmd[2] > 0.0) {
    r = 1.0;
  } else if (Accel_Y.TrqCmd[2] == 0.0) {
    r = 0.0;
  } else {
    r = (rtNaN);
  }

  /* DataTypeConversion: '<S30>/DataTypeConv2' */
  if (rtIsNaN(r)) {
    r = 0.0;
  } else {
    r = fmod(r, 256.0);
  }

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Constant1'
   *  DataTypeConversion: '<S30>/DataTypeConv1'
   *  DataTypeConversion: '<S30>/DataTypeConv2'
   *  Logic: '<S30>/AND3'
   *  RelationalOperator: '<S30>/Equal1'
   */
  if (rtb_NotEqual && ((B1_idx_0 < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)
                        -B1_idx_0 : (int32_T)(int8_T)(uint8_T)B1_idx_0) == (r <
        0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)-r : (int32_T)(int8_T)(uint8_T)
        r))) {
    B1_idx_0 = 0.0;
  } else {
    B1_idx_0 = Accel_Y.TrqCmd[2];
  }

  /* DiscreteIntegrator: '<S37>/Integrator' */
  B1_idx_0 *= 0.3;
  Accel_DW.Integrator_DSTATE[2] += B1_idx_0;

  /* Sum: '<S46>/Sum' */
  rtb_ComplextoMagnitudeAngle_o1 += Accel_DW.Integrator_DSTATE[2];

  /* Saturate: '<S44>/Saturation' */
  if (rtb_ComplextoMagnitudeAngle_o1 > 280.0) {
    rtb_ComplextoMagnitudeAngle_o1 = 280.0;
  } else {
    if (rtb_ComplextoMagnitudeAngle_o1 < 0.0) {
      rtb_ComplextoMagnitudeAngle_o1 = 0.0;
    }
  }

  /* Gain: '<S1>/rads_to_rpm' incorporates:
   *  Inport: '<Root>/MotSpd'
   */
  Accel_Y.TrqCmd[2] = 9.5492965855137211 * Accel_U.MotSpd[2];

  /* Lookup_n-D: '<S1>/MaxMotTrqVsSpd' */
  Accel_Y.TrqCmd[2] = look1_binlcapw(Accel_Y.TrqCmd[2],
    Accel_ConstP.MaxMotTrqVsSpd_bp01Data, Accel_ConstP.MaxMotTrqVsSpd_tableData,
    11U);

  /* Update for DiscreteIntegrator: '<S37>/Integrator' */
  Accel_DW.Integrator_DSTATE[2] += B1_idx_0;

  /* Switch: '<S4>/Switch2' incorporates:
   *  RelationalOperator: '<S4>/LowerRelop1'
   */
  if (!(rtb_ComplextoMagnitudeAngle_o1 > Accel_Y.TrqCmd[2])) {
    /* Outport: '<Root>/TrqCmd' */
    Accel_Y.TrqCmd[2] = rtb_ComplextoMagnitudeAngle_o1;
  }

  /* Gain: '<S42>/Proportional Gain' */
  rtb_ComplextoMagnitudeAngle_o1 = 4.5 * Accel_Y.TrqCmd[3];

  /* Sum: '<S47>/Sum Fdbk' */
  B1_idx_0 = rtb_ComplextoMagnitudeAngle_o1 + Accel_DW.Integrator_DSTATE[3];

  /* Gain: '<S30>/ZeroGain' */
  r = 0.0 * B1_idx_0;

  /* DeadZone: '<S30>/DeadZone' */
  if (B1_idx_0 > 280.0) {
    B1_idx_0 -= 280.0;
  } else {
    if (B1_idx_0 >= 0.0) {
      B1_idx_0 = 0.0;
    }
  }

  /* RelationalOperator: '<S30>/NotEqual' */
  rtb_NotEqual = (r != B1_idx_0);

  /* Signum: '<S30>/SignPreSat' */
  if (B1_idx_0 < 0.0) {
    B1_idx_0 = -1.0;
  } else if (B1_idx_0 > 0.0) {
    B1_idx_0 = 1.0;
  } else if (B1_idx_0 == 0.0) {
    B1_idx_0 = 0.0;
  } else {
    B1_idx_0 = (rtNaN);
  }

  /* Gain: '<S34>/Integral Gain' */
  Accel_Y.TrqCmd[3] *= 0.1;

  /* DataTypeConversion: '<S30>/DataTypeConv1' */
  if (rtIsNaN(B1_idx_0)) {
    B1_idx_0 = 0.0;
  } else {
    B1_idx_0 = fmod(B1_idx_0, 256.0);
  }

  /* Signum: '<S30>/SignPreIntegrator' incorporates:
   *  Logic: '<S30>/AND3'
   */
  if (Accel_Y.TrqCmd[3] < 0.0) {
    r = -1.0;
  } else if (Accel_Y.TrqCmd[3] > 0.0) {
    r = 1.0;
  } else if (Accel_Y.TrqCmd[3] == 0.0) {
    r = 0.0;
  } else {
    r = (rtNaN);
  }

  /* DataTypeConversion: '<S30>/DataTypeConv2' */
  if (rtIsNaN(r)) {
    r = 0.0;
  } else {
    r = fmod(r, 256.0);
  }

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Constant1'
   *  DataTypeConversion: '<S30>/DataTypeConv1'
   *  DataTypeConversion: '<S30>/DataTypeConv2'
   *  Logic: '<S30>/AND3'
   *  RelationalOperator: '<S30>/Equal1'
   */
  if (rtb_NotEqual && ((B1_idx_0 < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)
                        -B1_idx_0 : (int32_T)(int8_T)(uint8_T)B1_idx_0) == (r <
        0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)-r : (int32_T)(int8_T)(uint8_T)
        r))) {
    B1_idx_0 = 0.0;
  } else {
    B1_idx_0 = Accel_Y.TrqCmd[3];
  }

  /* DiscreteIntegrator: '<S37>/Integrator' */
  B1_idx_0 *= 0.3;
  Accel_DW.Integrator_DSTATE[3] += B1_idx_0;

  /* Sum: '<S46>/Sum' */
  rtb_ComplextoMagnitudeAngle_o1 += Accel_DW.Integrator_DSTATE[3];

  /* Saturate: '<S44>/Saturation' */
  if (rtb_ComplextoMagnitudeAngle_o1 > 280.0) {
    rtb_ComplextoMagnitudeAngle_o1 = 280.0;
  } else {
    if (rtb_ComplextoMagnitudeAngle_o1 < 0.0) {
      rtb_ComplextoMagnitudeAngle_o1 = 0.0;
    }
  }

  /* Gain: '<S1>/rads_to_rpm' incorporates:
   *  Inport: '<Root>/MotSpd'
   */
  Accel_Y.TrqCmd[3] = 9.5492965855137211 * Accel_U.MotSpd[3];

  /* Lookup_n-D: '<S1>/MaxMotTrqVsSpd' */
  Accel_Y.TrqCmd[3] = look1_binlcapw(Accel_Y.TrqCmd[3],
    Accel_ConstP.MaxMotTrqVsSpd_bp01Data, Accel_ConstP.MaxMotTrqVsSpd_tableData,
    11U);

  /* Update for DiscreteIntegrator: '<S37>/Integrator' */
  Accel_DW.Integrator_DSTATE[3] += B1_idx_0;

  /* Switch: '<S4>/Switch2' incorporates:
   *  RelationalOperator: '<S4>/LowerRelop1'
   */
  if (!(rtb_ComplextoMagnitudeAngle_o1 > Accel_Y.TrqCmd[3])) {
    /* Outport: '<Root>/TrqCmd' */
    Accel_Y.TrqCmd[3] = rtb_ComplextoMagnitudeAngle_o1;
  }

  /* End of Outputs for SubSystem: '<Root>/Accel Pedal to Traction Wheel Torque Request' */
}

/* Model initialize function */
void Accel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
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
