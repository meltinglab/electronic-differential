/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Accel_types.h
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

#ifndef RTW_HEADER_Accel_types_h_
#define RTW_HEADER_Accel_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_qm0PExI0AxHWASzOnN0CqB_
#define DEFINED_TYPEDEF_FOR_struct_qm0PExI0AxHWASzOnN0CqB_

typedef struct {
  real_T FrontAxlePositionfromCG;
  real_T RearAxlePositionfromCG;
  real_T wheel_to_wheel;
  real_T center_of_mass;
  real_T Mass;
  real_T TrackWidth;
  real_T HeightCG;
  real_T InitialLongPosition;
  real_T InitialLatPosition;
  real_T InitialVertPosition;
  real_T InitialLongVel;
  real_T InitialLatVel;
  real_T InitialVertVel;
  real_T InitialRollAngle;
  real_T InitialPitchAngle;
  real_T InitialYawAngle;
  real_T InitialRollRate;
  real_T InitialPitchRate;
  real_T InitialYawRate;
  real_T RollMomentInertia;
  real_T PitchMomentInertia;
  real_T YawMomentInertia;
  real_T FrontalArea;
  real_T WheelRadius;
  real_T MaxSpeed;
} struct_qm0PExI0AxHWASzOnN0CqB;

#endif

/* Parameters (default storage) */
typedef struct P_Accel_T_ P_Accel_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Accel_T RT_MODEL_Accel_T;

#endif                                 /* RTW_HEADER_Accel_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
