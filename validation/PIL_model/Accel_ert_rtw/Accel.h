/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Accel.h
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

#ifndef RTW_HEADER_Accel_h_
#define RTW_HEADER_Accel_h_
#include <math.h>
#include <stddef.h>
#ifndef Accel_COMMON_INCLUDES_
# define Accel_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Accel_COMMON_INCLUDES_ */

#include "Accel_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T u[4];                         /* '<S2>/Switch control action' */
  real_T r;
  real_T t;
  real_T y;
  real_T w_v;                          /* '<S6>/Divide1' */
  real_T Gain;                         /* '<S5>/Gain' */
  real_T ComplextoMagnitudeAngle_o1;   /* '<S1>/Complex to Magnitude-Angle' */
  real_T rtb_d1d2_idx_0;
  real_T rtb_d1d2_idx_1;
  real_T rtb_Switch_j_idx_3;
} B_Accel_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE[4];         /* '<S37>/Integrator' */
} DW_Accel_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Accel_i;                      /* '<Root>/AccelPdl' */
  real_T WhlAng[4];                    /* '<Root>/WhlAng' */
  real_T xdot;                         /* '<Root>/xdot' */
  real_T ydot;                         /* '<Root>/ydot' */
  real_T r;                            /* '<Root>/YawRate' */
  real_T EngSpd[4];                    /* '<Root>/MotSpd' */
} ExtU_Accel_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T TrqCmd[4];                    /* '<Root>/TrqCmd' */
} ExtY_Accel_T;

/* Parameters (default storage) */
struct P_Accel_T_ {
  struct_qm0PExI0AxHWASzOnN0CqB VEH;   /* Variable: VEH
                                        * Referenced by:
                                        *   '<S1>/VelMax'
                                        *   '<S6>/wheel base'
                                        *   '<S6>/wheel base1'
                                        *   '<S6>/wheel radius'
                                        */
  real_T Klqr1[8];                     /* Variable: Klqr1
                                        * Referenced by: '<S2>/K1'
                                        */
  real_T Klqr2[8];                     /* Variable: Klqr2
                                        * Referenced by: '<S2>/K2'
                                        */
  real_T Klqr3[8];                     /* Variable: Klqr3
                                        * Referenced by: '<S2>/K3'
                                        */
  real_T Klqr4[8];                     /* Variable: Klqr4
                                        * Referenced by: '<S2>/K4'
                                        */
  real_T Klqr5[8];                     /* Variable: Klqr5
                                        * Referenced by: '<S2>/K5'
                                        */
  real_T MotSpd[12];                   /* Variable: MotSpd
                                        * Referenced by: '<S1>/MaxMotTrqVsSpd'
                                        */
  real_T MotTrq[12];                   /* Variable: MotTrq
                                        * Referenced by: '<S1>/MaxMotTrqVsSpd'
                                        */
  real_T DiscretePIDController_I;     /* Mask Parameter: DiscretePIDController_I
                                       * Referenced by: '<S34>/Integral Gain'
                                       */
  real_T DiscretePIDController_InitialCo;
                              /* Mask Parameter: DiscretePIDController_InitialCo
                               * Referenced by: '<S37>/Integrator'
                               */
  real_T DiscretePIDController_LowerSatu;
                              /* Mask Parameter: DiscretePIDController_LowerSatu
                               * Referenced by:
                               *   '<S30>/DeadZone'
                               *   '<S44>/Saturation'
                               */
  real_T DiscretePIDController_P;     /* Mask Parameter: DiscretePIDController_P
                                       * Referenced by: '<S42>/Proportional Gain'
                                       */
  real_T DiscretePIDController_UpperSatu;
                              /* Mask Parameter: DiscretePIDController_UpperSatu
                               * Referenced by:
                               *   '<S30>/DeadZone'
                               *   '<S44>/Saturation'
                               */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S30>/Constant1'
                                        */
  real_T rads_to_rpm_Gain;             /* Expression: 30/pi
                                        * Referenced by: '<S1>/rads_to_rpm'
                                        */
  real_T SaturationRefSpd_UpperSat;    /* Expression: 120
                                        * Referenced by: '<S6>/Saturation RefSpd'
                                        */
  real_T SaturationRefSpd_LowerSat;    /* Expression: -120
                                        * Referenced by: '<S6>/Saturation RefSpd'
                                        */
  real_T pihalf_Value;                 /* Expression: pi/2
                                        * Referenced by: '<S6>/pi half'
                                        */
  real_T SaturationWhlAnd_UpperSat;    /* Expression: pi*5/12
                                        * Referenced by: '<S6>/Saturation WhlAnd'
                                        */
  real_T SaturationWhlAnd_LowerSat;    /* Expression: -pi*5/12
                                        * Referenced by: '<S6>/Saturation WhlAnd'
                                        */
  real_T SaturationWhlSpd_UpperSat;    /* Expression: 600
                                        * Referenced by: '<S6>/Saturation WhlSpd'
                                        */
  real_T SaturationWhlSpd_LowerSat;    /* Expression: -600
                                        * Referenced by: '<S6>/Saturation WhlSpd'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/2
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Constant_Value[20];           /* Expression: [A_1;A_2;A_3;A_4;A_5]
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant1_Value_o[10];        /* Expression: [B1_1;B1_2;B1_3;B1_4;B1_5]
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T ZeroGain_Gain;                /* Expression: 0
                                        * Referenced by: '<S30>/ZeroGain'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S37>/Integrator'
                                        */
  real_T Zerosaturation_Value;         /* Expression: 0
                                        * Referenced by: '<S1>/Zero saturation'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Accel_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_Accel_T Accel_P;

/* Block signals (default storage) */
extern B_Accel_T Accel_B;

/* Block states (default storage) */
extern DW_Accel_T Accel_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Accel_T Accel_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Accel_T Accel_Y;

/* Model entry point functions */
extern void Accel_initialize(void);
extern void Accel_step(void);
extern void Accel_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Accel_T *const Accel_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/Data Type Propagation' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('car_model/Controllers/Accel Pedal to Traction Wheel Torque Request')    - opens subsystem car_model/Controllers/Accel Pedal to Traction Wheel Torque Request
 * hilite_system('car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'car_model/Controllers'
 * '<S1>'   : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request'
 * '<S2>'   : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Apply ESP control'
 * '<S3>'   : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller'
 * '<S4>'   : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Saturation Dynamic'
 * '<S5>'   : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Signals to states'
 * '<S6>'   : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Virtual Ackerman differential'
 * '<S7>'   : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Apply ESP control/Switch control action'
 * '<S8>'   : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Anti-windup'
 * '<S9>'   : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/D Gain'
 * '<S10>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Filter'
 * '<S11>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Filter ICs'
 * '<S12>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/I Gain'
 * '<S13>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Ideal P Gain'
 * '<S14>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S15>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Integrator'
 * '<S16>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Integrator ICs'
 * '<S17>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/N Copy'
 * '<S18>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/N Gain'
 * '<S19>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/P Copy'
 * '<S20>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Parallel P Gain'
 * '<S21>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Reset Signal'
 * '<S22>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Saturation'
 * '<S23>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Saturation Fdbk'
 * '<S24>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Sum'
 * '<S25>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Sum Fdbk'
 * '<S26>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Tracking Mode'
 * '<S27>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Tracking Mode Sum'
 * '<S28>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/postSat Signal'
 * '<S29>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/preSat Signal'
 * '<S30>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S31>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/D Gain/Disabled'
 * '<S32>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Filter/Disabled'
 * '<S33>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Filter ICs/Disabled'
 * '<S34>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S35>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S36>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Ideal P Gain Fdbk/Passthrough'
 * '<S37>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Integrator/Discrete'
 * '<S38>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S39>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S40>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/N Gain/Disabled'
 * '<S41>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/P Copy/Disabled'
 * '<S42>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S43>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Reset Signal/Disabled'
 * '<S44>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Saturation/Enabled'
 * '<S45>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Saturation Fdbk/Passthrough'
 * '<S46>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Sum/Sum_PI'
 * '<S47>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Sum Fdbk/Enabled'
 * '<S48>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S49>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S50>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/postSat Signal/Feedback_Path'
 * '<S51>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/preSat Signal/Feedback_Path'
 * '<S52>'  : 'car_model/Controllers/Accel Pedal to Traction Wheel Torque Request/Signals to states/equilibrium point'
 */
#endif                                 /* RTW_HEADER_Accel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
