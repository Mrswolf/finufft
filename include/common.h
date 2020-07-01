#ifndef COMMON_H
#define COMMON_H

// just what's needed to describe the interface to what provided below
#include <dataTypes.h>
#include <nufft_opts.h>
#include <spread_opts.h>
#include <fftw_defs.h>

// although these have no FLT args, distinct prec versions are needed
// because the structs implicitly depend on FLT...
#ifdef SINGLE
#define SET_NF_TYPE12 set_nf_type12f
#define FINUFFT_DEFAULT_OPTS finufftf_default_opts
#else
#define SET_NF_TYPE12 set_nf_type12
#define FINUFFT_DEFAULT_OPTS finufft_default_opts
#endif

// common.cpp provides... (not including finufft_default_opts)
int SET_NF_TYPE12(BIGINT ms, nufft_opts opts, spread_opts spopts, BIGINT *nf);
int setup_spreader_for_nufft(spread_opts &spopts, FLT eps, nufft_opts opts);
void set_nhg_type3(FLT S, FLT X, nufft_opts opts, spread_opts spopts,
		  BIGINT *nf, FLT *h, FLT *gam);
void onedim_dct_kernel(BIGINT nf, FLT *fwkerhalf, spread_opts opts);
void onedim_fseries_kernel(BIGINT nf, FLT *fwkerhalf, spread_opts opts);
void onedim_nuft_kernel(BIGINT nk, FLT *k, FLT *phihat, spread_opts opts);
void deconvolveshuffle1d(int dir,FLT prefac,FLT* ker,BIGINT ms,FLT *fk,
			 BIGINT nf1,FFTW_CPX* fw,int modeord);
void deconvolveshuffle2d(int dir,FLT prefac,FLT *ker1, FLT *ker2,
			 BIGINT ms,BIGINT mt,
			 FLT *fk, BIGINT nf1, BIGINT nf2, FFTW_CPX* fw,
			 int modeord);
void deconvolveshuffle3d(int dir,FLT prefac,FLT *ker1, FLT *ker2,
			 FLT *ker3, BIGINT ms, BIGINT mt, BIGINT mu,
			 FLT *fk, BIGINT nf1, BIGINT nf2, BIGINT nf3,
			 FFTW_CPX* fw, int modeord);
#endif  // COMMON_H
