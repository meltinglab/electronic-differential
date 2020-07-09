/*
 * File: Accel_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef ACCEL_CA_H
#define ACCEL_CA_H

/* preprocessor validation checks */
#include "Accel_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_Accel_HWRes;
extern CA_PWS_TestResults CA_Accel_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_Accel_ExpHW;
extern CA_HWImpl CA_Accel_ActHW;

/* entry point function to run tests */
void Accel_caRunTests(void);

#endif                                 /* ACCEL_CA_H */
