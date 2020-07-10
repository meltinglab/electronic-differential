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
 * C/C++ source code generated on : Tue Jul  7 17:05:20 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Accel.h"
#include "Accel_private.h"

/* Constant parameters (default storage) */
const ConstP_Accel_T Accel_ConstP = {
  /* Expression: Klqr1
   * Referenced by: '<S2>/K1'
   */
  { 105.83190392875592, -105.83190392875582, -106.60594046014984,
    106.60594046014978, -159.70562183477094, 159.70562183477074,
    160.8736815689349, -160.87368156893456 },

  /* Expression: Klqr2
   * Referenced by: '<S2>/K2'
   */
  { 145.24268350097628, -145.242683500976, -146.30496376594277,
    146.30496376594263, -160.88534331649359, 160.88534331649342,
    162.06203133277106, -162.062031332771 },

  /* Expression: Klqr3
   * Referenced by: '<S2>/K3'
   */
  { 182.1618230874744, -182.16182308747432, -183.49412365526831,
    183.49412365526834, -162.38058606464486, 162.3805860646448,
    163.56821003187281, -163.56821003187309 },

  /* Expression: Klqr4
   * Referenced by: '<S2>/K4'
   */
  { 216.3517354210779, -216.351735421078, -217.93409518812044,
    217.93409518812027, -164.14171175818905, 164.14171175818913,
    165.34221629897371, -165.34221629897391 },

  /* Expression: Klqr5
   * Referenced by: '<S2>/K5'
   */
  { 247.760599899886, -247.76059989988562, -249.57267875553626,
    249.5726787555364, -166.12089937054554, 166.12089937054563,
    167.33587935264393, -167.33587935264404 },

  /* Expression: MotTrq
   * Referenced by: '<S1>/MaxMotTrqVsSpd'
   */
  { 280.0, 280.0, 280.0, 280.0, 254.6479089, 190.9859317, 152.7887454,
    127.3239545, 109.1348181, 95.49296586, 84.88263632, 76.39437268 },

  /* Expression: MotSpd
   * Referenced by: '<S1>/MaxMotTrqVsSpd'
   */
  { 0.0, 1000.0, 2000.0, 2728.370453, 3000.0, 4000.0, 5000.0, 6000.0, 7000.0,
    8000.0, 9000.0, 10000.0 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
