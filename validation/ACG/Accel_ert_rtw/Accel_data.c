/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Accel_data.c
 *
 * Code generated for Simulink model 'Accel'.
 *
 * Model version                  : 1.101
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Mon Jul  6 22:04:55 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Accel.h"
#include "Accel_private.h"

/* Block parameters (default storage) */
P_Accel_T Accel_P = {
  /* Variable: VEH
   * Referenced by:
   *   '<S1>/VelMax'
   *   '<S6>/wheel base'
   *   '<S6>/wheel base1'
   *   '<S6>/wheel radius'
   */
  {
    1.515,
    1.504,
    1.8,
    -0.7,
    1181.0,
    1.922,
    0.134,
    0.0,
    3.125,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    1922.7,
    432.3333,
    2066.0,
    2.11,
    0.31,
    44.444444444444443
  },

  /* Variable: Klqr1
   * Referenced by: '<S2>/K1'
   */
  { 105.83190392875592, -105.83190392875582, -106.60594046014984,
    106.60594046014978, -159.70562183477094, 159.70562183477074,
    160.8736815689349, -160.87368156893456 },

  /* Variable: Klqr2
   * Referenced by: '<S2>/K2'
   */
  { 145.24268350097628, -145.242683500976, -146.30496376594277,
    146.30496376594263, -160.88534331649359, 160.88534331649342,
    162.06203133277106, -162.062031332771 },

  /* Variable: Klqr3
   * Referenced by: '<S2>/K3'
   */
  { 182.1618230874744, -182.16182308747432, -183.49412365526831,
    183.49412365526834, -162.38058606464486, 162.3805860646448,
    163.56821003187281, -163.56821003187309 },

  /* Variable: Klqr4
   * Referenced by: '<S2>/K4'
   */
  { 216.3517354210779, -216.351735421078, -217.93409518812044,
    217.93409518812027, -164.14171175818905, 164.14171175818913,
    165.34221629897371, -165.34221629897391 },

  /* Variable: Klqr5
   * Referenced by: '<S2>/K5'
   */
  { 247.760599899886, -247.76059989988562, -249.57267875553626,
    249.5726787555364, -166.12089937054554, 166.12089937054563,
    167.33587935264393, -167.33587935264404 },

  /* Variable: MotSpd
   * Referenced by: '<S1>/MaxMotTrqVsSpd'
   */
  { 0.0, 1000.0, 2000.0, 2728.370453, 3000.0, 4000.0, 5000.0, 6000.0, 7000.0,
    8000.0, 9000.0, 10000.0 },

  /* Variable: MotTrq
   * Referenced by: '<S1>/MaxMotTrqVsSpd'
   */
  { 280.0, 280.0, 280.0, 280.0, 254.6479089, 190.9859317, 152.7887454,
    127.3239545, 109.1348181, 95.49296586, 84.88263632, 76.39437268 },

  /* Mask Parameter: DiscretePIDController_I
   * Referenced by: '<S34>/Integral Gain'
   */
  0.1,

  /* Mask Parameter: DiscretePIDController_InitialCo
   * Referenced by: '<S37>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_LowerSatu
   * Referenced by:
   *   '<S30>/DeadZone'
   *   '<S44>/Saturation'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_P
   * Referenced by: '<S42>/Proportional Gain'
   */
  4.5,

  /* Mask Parameter: DiscretePIDController_UpperSatu
   * Referenced by:
   *   '<S30>/DeadZone'
   *   '<S44>/Saturation'
   */
  280.0,

  /* Expression: 0
   * Referenced by: '<S30>/Constant1'
   */
  0.0,

  /* Expression: 30/pi
   * Referenced by: '<S1>/rads_to_rpm'
   */
  9.5492965855137211,

  /* Expression: 120
   * Referenced by: '<S6>/Saturation RefSpd'
   */
  120.0,

  /* Expression: -120
   * Referenced by: '<S6>/Saturation RefSpd'
   */
  -120.0,

  /* Expression: pi/2
   * Referenced by: '<S6>/pi half'
   */
  1.5707963267948966,

  /* Expression: pi*5/12
   * Referenced by: '<S6>/Saturation WhlAnd'
   */
  1.3089969389957472,

  /* Expression: -pi*5/12
   * Referenced by: '<S6>/Saturation WhlAnd'
   */
  -1.3089969389957472,

  /* Expression: 600
   * Referenced by: '<S6>/Saturation WhlSpd'
   */
  600.0,

  /* Expression: -600
   * Referenced by: '<S6>/Saturation WhlSpd'
   */
  -600.0,

  /* Expression: 1/2
   * Referenced by: '<S5>/Gain'
   */
  0.5,

  /* Expression: [A_1;A_2;A_3;A_4;A_5]
   * Referenced by: '<S5>/Constant'
   */
  { -16.258886028, 2.6112791887579569E-15, -11.61349002, 2.6112791887579569E-15,
    -9.03271446, 2.6112791887579569E-15, -7.3904027400000007,
    2.6112791887579569E-15, -6.2534177030769236, 2.6112791887579569E-15,
    -0.99999999999999978, -5.3210811557468372, -1.0, -3.8007722541048841, -1.0,
    -2.9561561976371316, -1.0, -2.4186732526121988, -1.0, -2.0465696752872451 },

  /* Expression: [B1_1;B1_2;B1_3;B1_4;B1_5]
   * Referenced by: '<S5>/Constant1'
   */
  { 8.09982265190858, 18.059623820272346, 5.7855876085061286, 18.059623820272346,
    4.4999014732825442, 18.059623820272346, 3.6817375690493548,
    18.059623820272346, 3.1153164045802231, 18.059623820272346 },

  /* Expression: 0
   * Referenced by: '<S30>/ZeroGain'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S37>/Integrator'
   */
  0.05,

  /* Expression: 0
   * Referenced by: '<S1>/Zero saturation'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
