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
 * C/C++ source code generated on : Tue Jul  7 17:05:20 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Accel_h_
#define RTW_HEADER_Accel_h_
#include <math.h>
#ifndef Accel_COMMON_INCLUDES_
# define Accel_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Accel_COMMON_INCLUDES_ */

#include "Accel_types.h"
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

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE[4];         /* '<S37>/Integrator' */
} DW_Accel_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: Klqr1
   * Referenced by: '<S2>/K1'
   */
  real_T K1_Gain[8];

  /* Expression: Klqr2
   * Referenced by: '<S2>/K2'
   */
  real_T K2_Gain[8];

  /* Expression: Klqr3
   * Referenced by: '<S2>/K3'
   */
  real_T K3_Gain[8];

  /* Expression: Klqr4
   * Referenced by: '<S2>/K4'
   */
  real_T K4_Gain[8];

  /* Expression: Klqr5
   * Referenced by: '<S2>/K5'
   */
  real_T K5_Gain[8];

  /* Expression: MotTrq
   * Referenced by: '<S1>/MaxMotTrqVsSpd'
   */
  real_T MaxMotTrqVsSpd_tableData[12];

  /* Expression: MotSpd
   * Referenced by: '<S1>/MaxMotTrqVsSpd'
   */
  real_T MaxMotTrqVsSpd_bp01Data[12];
} ConstP_Accel_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T AccelPdl;                     /* '<Root>/AccelPdl' */
  real_T WhlAng[4];                    /* '<Root>/WhlAng' */
  real_T xdot;                         /* '<Root>/xdot' */
  real_T ydot;                         /* '<Root>/ydot' */
  real_T r;                            /* '<Root>/YawRate' */
  real_T MotSpd[4];                    /* '<Root>/MotSpd' */
} ExtU_Accel_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T TrqCmd[4];                    /* '<Root>/TrqCmd' */
} ExtY_Accel_T;

/* Real-time Model Data Structure */
struct tag_RTM_Accel_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_Accel_T Accel_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Accel_T Accel_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Accel_T Accel_Y;

/* Constant parameters (default storage) */
extern const ConstP_Accel_T Accel_ConstP;

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
 * hilite_system('car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request')    - opens subsystem car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request
 * hilite_system('car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'car_model_SIL/Controllers'
 * '<S1>'   : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request'
 * '<S2>'   : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Apply ESP control'
 * '<S3>'   : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller'
 * '<S4>'   : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Saturation Dynamic'
 * '<S5>'   : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Signals to states'
 * '<S6>'   : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Virtual Ackerman differential'
 * '<S7>'   : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Apply ESP control/Switch control action'
 * '<S8>'   : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Anti-windup'
 * '<S9>'   : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/D Gain'
 * '<S10>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Filter'
 * '<S11>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Filter ICs'
 * '<S12>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/I Gain'
 * '<S13>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Ideal P Gain'
 * '<S14>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S15>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Integrator'
 * '<S16>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Integrator ICs'
 * '<S17>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/N Copy'
 * '<S18>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/N Gain'
 * '<S19>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/P Copy'
 * '<S20>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Parallel P Gain'
 * '<S21>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Reset Signal'
 * '<S22>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Saturation'
 * '<S23>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Saturation Fdbk'
 * '<S24>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Sum'
 * '<S25>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Sum Fdbk'
 * '<S26>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Tracking Mode'
 * '<S27>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Tracking Mode Sum'
 * '<S28>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/postSat Signal'
 * '<S29>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/preSat Signal'
 * '<S30>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S31>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/D Gain/Disabled'
 * '<S32>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Filter/Disabled'
 * '<S33>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Filter ICs/Disabled'
 * '<S34>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S35>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S36>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Ideal P Gain Fdbk/Passthrough'
 * '<S37>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Integrator/Discrete'
 * '<S38>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S39>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S40>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/N Gain/Disabled'
 * '<S41>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/P Copy/Disabled'
 * '<S42>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S43>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Reset Signal/Disabled'
 * '<S44>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Saturation/Enabled'
 * '<S45>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Saturation Fdbk/Passthrough'
 * '<S46>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Sum/Sum_PI'
 * '<S47>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Sum Fdbk/Enabled'
 * '<S48>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S49>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S50>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/postSat Signal/Feedback_Path'
 * '<S51>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Discrete PID Controller/preSat Signal/Feedback_Path'
 * '<S52>'  : 'car_model_SIL/Controllers/Accel Pedal to Traction Wheel Torque Request/Signals to states/equilibrium point'
 */
#endif                                 /* RTW_HEADER_Accel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
