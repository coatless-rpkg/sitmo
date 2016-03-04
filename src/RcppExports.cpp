// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "../inst/include/sitmo.h"
#include <Rcpp.h>

using namespace Rcpp;

// sitmo_draws
Rcpp::NumericVector sitmo_draws(unsigned int n);
RcppExport SEXP sitmo_sitmo_draws(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    __result = Rcpp::wrap(sitmo_draws(n));
    return __result;
END_RCPP
}
// sitmo_engine_seed
Rcpp::NumericVector sitmo_engine_seed(unsigned int n, unsigned int seed);
RcppExport SEXP sitmo_sitmo_engine_seed(SEXP nSEXP, SEXP seedSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type seed(seedSEXP);
    __result = Rcpp::wrap(sitmo_engine_seed(n, seed));
    return __result;
END_RCPP
}
// sitmo_engine_reset
Rcpp::NumericMatrix sitmo_engine_reset(unsigned int n, unsigned int seed);
RcppExport SEXP sitmo_sitmo_engine_reset(SEXP nSEXP, SEXP seedSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type seed(seedSEXP);
    __result = Rcpp::wrap(sitmo_engine_reset(n, seed));
    return __result;
END_RCPP
}
// sitmo_two_seeds
Rcpp::NumericMatrix sitmo_two_seeds(unsigned int n, Rcpp::NumericVector seeds);
RcppExport SEXP sitmo_sitmo_two_seeds(SEXP nSEXP, SEXP seedsSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type seeds(seedsSEXP);
    __result = Rcpp::wrap(sitmo_two_seeds(n, seeds));
    return __result;
END_RCPP
}
// sitmo_parallel
Rcpp::NumericVector sitmo_parallel(unsigned int n, Rcpp::NumericVector& seeds);
RcppExport SEXP sitmo_sitmo_parallel(SEXP nSEXP, SEXP seedsSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector& >::type seeds(seedsSEXP);
    __result = Rcpp::wrap(sitmo_parallel(n, seeds));
    return __result;
END_RCPP
}
