/*
 * File: Accel_ca.c
 *
 * Abstract: Tests assumptions in the generated code.
 */

#include "Accel_ca.h"

CA_HWImpl_TestResults CA_Accel_HWRes;
CA_PWS_TestResults CA_Accel_PWSRes;
const CA_HWImpl CA_Accel_ExpHW = {
  8,                                   /* BitPerChar */
  16,                                  /* BitPerShort */
  32,                                  /* BitPerInt */
  32,                                  /* BitPerLong */
  64,                                  /* BitPerLongLong */
  32,                                  /* BitPerFloat */
  64,                                  /* BitPerDouble */
  32,                                  /* BitPerPointer */
  32,                                  /* BitPerSizeT */
  32,                                  /* BitPerPtrDiffT */
  CA_LITTLE_ENDIAN,                    /* Endianess */
  CA_ZERO,                             /* IntDivRoundTo */
  1,                                   /* ShiftRightIntArith */
  0,                                   /* LongLongMode */
  0,                                   /* PortableWordSizes */
  "ARM Compatible->ARM Cortex",        /* HWDeviceType */
  0,                                   /* MemoryAtStartup */
  0,                                   /* DenormalFlushToZero */
  0                                    /* DenormalAsZero */
};

CA_HWImpl CA_Accel_ActHW;
void Accel_caRunTests(void)
{
  /* verify hardware implementation */
  caVerifyPortableWordSizes(&CA_Accel_ActHW, &CA_Accel_ExpHW, &CA_Accel_PWSRes);
  caVerifyHWImpl(&CA_Accel_ActHW, &CA_Accel_ExpHW, &CA_Accel_HWRes);
}
