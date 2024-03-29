// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "../inst/include/sitmo.h"
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// sitmo_draws
Rcpp::NumericVector sitmo_draws(unsigned int n);
RcppExport SEXP _sitmo_sitmo_draws(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(sitmo_draws(n));
    return rcpp_result_gen;
END_RCPP
}
// sitmo_engine_seed
Rcpp::NumericVector sitmo_engine_seed(unsigned int n, unsigned int seed);
RcppExport SEXP _sitmo_sitmo_engine_seed(SEXP nSEXP, SEXP seedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type seed(seedSEXP);
    rcpp_result_gen = Rcpp::wrap(sitmo_engine_seed(n, seed));
    return rcpp_result_gen;
END_RCPP
}
// sitmo_engine_reset
Rcpp::NumericMatrix sitmo_engine_reset(unsigned int n, unsigned int seed);
RcppExport SEXP _sitmo_sitmo_engine_reset(SEXP nSEXP, SEXP seedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type seed(seedSEXP);
    rcpp_result_gen = Rcpp::wrap(sitmo_engine_reset(n, seed));
    return rcpp_result_gen;
END_RCPP
}
// sitmo_two_seeds
Rcpp::NumericMatrix sitmo_two_seeds(unsigned int n, Rcpp::NumericVector seeds);
RcppExport SEXP _sitmo_sitmo_two_seeds(SEXP nSEXP, SEXP seedsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type seeds(seedsSEXP);
    rcpp_result_gen = Rcpp::wrap(sitmo_two_seeds(n, seeds));
    return rcpp_result_gen;
END_RCPP
}
// sitmo_parallel
Rcpp::NumericVector sitmo_parallel(unsigned int n, Rcpp::NumericVector& seeds);
RcppExport SEXP _sitmo_sitmo_parallel(SEXP nSEXP, SEXP seedsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector& >::type seeds(seedsSEXP);
    rcpp_result_gen = Rcpp::wrap(sitmo_parallel(n, seeds));
    return rcpp_result_gen;
END_RCPP
}
// runif_sitmo
Rcpp::NumericVector runif_sitmo(unsigned int n, double min, double max, uint32_t seed);
RcppExport SEXP _sitmo_runif_sitmo(SEXP nSEXP, SEXP minSEXP, SEXP maxSEXP, SEXP seedSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    Rcpp::traits::input_parameter< double >::type min(minSEXP);
    Rcpp::traits::input_parameter< double >::type max(maxSEXP);
    Rcpp::traits::input_parameter< uint32_t >::type seed(seedSEXP);
    rcpp_result_gen = Rcpp::wrap(runif_sitmo(n, min, max, seed));
    return rcpp_result_gen;
END_RCPP
}
// runif_r
Rcpp::NumericVector runif_r(unsigned int n, double min, double max);
RcppExport SEXP _sitmo_runif_r(SEXP nSEXP, SEXP minSEXP, SEXP maxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    Rcpp::traits::input_parameter< double >::type min(minSEXP);
    Rcpp::traits::input_parameter< double >::type max(maxSEXP);
    rcpp_result_gen = Rcpp::wrap(runif_r(n, min, max));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_sitmo_sitmo_draws", (DL_FUNC) &_sitmo_sitmo_draws, 1},
    {"_sitmo_sitmo_engine_seed", (DL_FUNC) &_sitmo_sitmo_engine_seed, 2},
    {"_sitmo_sitmo_engine_reset", (DL_FUNC) &_sitmo_sitmo_engine_reset, 2},
    {"_sitmo_sitmo_two_seeds", (DL_FUNC) &_sitmo_sitmo_two_seeds, 2},
    {"_sitmo_sitmo_parallel", (DL_FUNC) &_sitmo_sitmo_parallel, 2},
    {"_sitmo_runif_sitmo", (DL_FUNC) &_sitmo_runif_sitmo, 4},
    {"_sitmo_runif_r", (DL_FUNC) &_sitmo_runif_r, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_sitmo(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
