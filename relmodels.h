/*
   This file is part of the RELXILL model code.

   RELXILL is free software: you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   any later version.

   RELXILL is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.
   For a copy of the GNU General Public License see
   <http://www.gnu.org/licenses/>.

    Copyright 2019 Thomas Dauser, Remeis Observatory & ECAP
*/
#ifndef MODELS_H_
#define MODELS_H_

#include "relbase.h"
#include "relutility.h"
#include "xilltable.h"

/**** DEFINES **/
#define MOD_TYPE_RELLINE 1
#define NUM_PARAM_RELLINE 10

#define MOD_TYPE_RELLINELP 2
#define NUM_PARAM_RELLINELP 9


#define MOD_TYPE_RELCONV 11
#define NUM_PARAM_RELCONV 8

#define MOD_TYPE_RELCONVLP 12
#define NUM_PARAM_RELCONVLP 7


#define MOD_TYPE_XILLVER 0
#define NUM_PARAM_XILLVER 7

#define MOD_TYPE_RELXILL -1
#define NUM_PARAM_RELXILL 13

#define MOD_TYPE_RELXILLLP -2
#define NUM_PARAM_RELXILLLP 12

/** density models **/
#define MOD_TYPE_RELXILLDENS -10
#define NUM_PARAM_RELXILLDENS 13

#define MOD_TYPE_RELXILLLPDENS -11
#define NUM_PARAM_RELXILLLPDENS 12

#define MOD_TYPE_XILLVERDENS -100
#define NUM_PARAM_XILLVERDENS 7

/** ion grad models **/
#define MOD_TYPE_RELXILLLPION -21
#define NUM_PARAM_RELXILLLPION 15

#define MOD_TYPE_RELXILLION -20  // not implemented yet
// #define NUM_PARAM_RELXILLION 15???


/****  TYPE DEFINITIONS ****/


/**** FUNCTION DEFINITIONS ****/
relParam* init_par_relline(const double* inp_par, const int n_parameter, int* status);
relParam* init_par_relline_lp(const double* inp_par, const int n_parameter, int* status);
relParam* init_par_relconv(const double* inp_par, const int n_parameter, int* status);
xillParam* init_par_xillver(const double* inp_par, const int n_parameter, int* status);
void init_par_relxill(relParam** rel_param, xillParam** xill_param, const double* inp_par, const int n_parameter, int* status);

/** basic xillver model function **/
void xillver_base(const double* ener0, const int n_ener0, double* photar, xillParam* param_struct, int* status);

/** internal MODEL FUNCTIONS **/
void tdrelline(const double* ener, const int n_ener, double* photar, const double* parameter, const int n_parameter, int* status);
void tdrellinelp(const double* ener, const int n_ener, double* photar, const double* parameter, const int n_parameter, int* status);
void tdrelxill(const double* ener0, const int n_ener0, double* photar, const double* parameter, const int n_parameter, int* status);
void tdrelxilllp(const double* ener0, const int n_ener0, double* photar, const double* parameter, const int n_parameter, int* status);
void tdrelxilllpion(const double* ener0, const int n_ener0, double* photar, const double* parameter, const int n_parameter, int* status);
void tdxillver(const double* ener0, const int n_ener0, double* photar, const double* parameter, const int n_parameter, int* status);
void tdrelconv(const double* ener, const int n_ener, double* photar, const double* parameter, const int n_parameter, int* status);
void tdrelconvlp(const double* ener, const int n_ener, double* photar, const double* parameter, const int n_parameter, int* status);
void tdrelxilldens(const double* ener0, const int n_ener0, double* photar, const double* parameter, const int n_parameter, int* status);
void tdrelxilllpdens(const double* ener0, const int n_ener0, double* photar, const double* parameter, const int n_parameter, int* status);
void tdxillverdens(const double* ener0, const int n_ener0, double* photar, const double* parameter, const int n_parameter, int* status);

void tdrelxill_nthcomp(const double* ener0, const int n_ener0, double* photar, const double* parameter, const int n_parameter, int* status);
void tdrelxilllp_nthcomp(const double* ener0, const int n_ener0, double* photar, const double* parameter, const int n_parameter, int* status);
void tdrelxilllpion_nthcomp(const double* ener0, const int n_ener0, double* photar, const double* parameter, const int n_parameter, int* status);
void tdxillver_nthcomp(const double* ener0, const int n_ener0, double* photar, const double* parameter, const int n_parameter, int* status);

/* get the version number text on the screen (if not already printed before */
void print_version_number(int* status);

/* get a new relbase parameter structure and initialize it */
relParam* new_relParam(int model_type, int emis_type, int* status);

/* free relbase parameter */
void free_relParam(relParam*);

xillParam* new_xillParam(int model_type, int prim_type, int* status);
void free_xillParam(xillParam*);

/* xspec local model wrapper functions **/
void lmodrelxill(const double* ener0, const int n_ener0, const double* parameter, int ifl, double* photar, double* photer, const char* init);
void lmodrelxilllp(const double* ener0, const int n_ener0, const double* parameter, int ifl, double* photar, double* photer, const char* init);
void lmodrelxilllpion(const double* ener0, const int n_ener0, const double* parameter, int ifl, double* photar, double* photer, const char* init);
void lmodxillver(const double* ener0, const int n_ener0, const double* parameter, int ifl, double* photar, double* photer, const char* init);
void lmodrelline(const double* ener0, const int n_ener0, const double* parameter, int ifl, double* photar, double* photer, const char* init);
void lmodrellinelp(const double* ener0, const int n_ener0, const double* parameter, int ifl, double* photar, double* photer, const char* init);
void lmodrelconv(const double* ener0, const int n_ener0, const double* parameter, int ifl, double* photar, double* photer, const char* init);
void lmodrelconvlp(const double* ener0, const int n_ener0, const double* parameter, int ifl, double* photar, double* photer, const char* init);

void lmodrelxilldens(const double* ener0, const int n_ener0, const double* parameter, int ifl, double* photar, double* photer, const char* init);
void lmodrelxilllpdens(const double* ener0, const int n_ener0, const double* parameter, int ifl, double* photar, double* photer, const char* init);
void lmodxillverdens(const double* ener0, const int n_ener0, const double* parameter, int ifl, double* photar, double* photer, const char* init);

void lmodrelxillnthcomp(const double* ener0, const int n_ener0, const double* parameter, int ifl, double* photar, double* photer, const char* init);
void lmodrelxilllpnthcomp(const double* ener0, const int n_ener0, const double* parameter, int ifl, double* photar, double* photer, const char* init);
void lmodrelxilllpionnthcomp(const double* ener0, const int n_ener0, const double* parameter, int ifl, double* photar, double* photer, const char* init);
void lmodxillvernthcomp(const double* ener0, const int n_ener0, const double* parameter, int ifl, double* photar, double* photer, const char* init);

#endif /* MODELS_H_ */
