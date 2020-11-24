// Copyright (C) 2020 Apparateq
//===----------------------------------------------------------------------===//
///
/// \file
///
/// \brief Common headers
///
//===----------------------------------------------------------------------===//

#ifndef APTQ_COMMON_H
#define	APTQ_COMMON_H

#define RUNNING true
#define NOT_RUNNING false

#define PRESSED true
#define NOT_PRESSED false

#define LEDs_SetLow()       do { LATA = 0; LATCbits.LATC5 = 0; } while(0)

// global state variables
extern bool app_state;
extern bool app_change;

#endif	/* APTQ_COMMON_H */
