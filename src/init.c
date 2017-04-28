#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME: 
Check these declarations against the C/Fortran source code.
*/

/* .Call calls */
extern SEXP sitmo_runif_r(SEXP, SEXP, SEXP);
extern SEXP sitmo_runif_sitmo(SEXP, SEXP, SEXP, SEXP);
extern SEXP sitmo_sitmo_draws(SEXP);
extern SEXP sitmo_sitmo_engine_reset(SEXP, SEXP);
extern SEXP sitmo_sitmo_engine_seed(SEXP, SEXP);
extern SEXP sitmo_sitmo_parallel(SEXP, SEXP);
extern SEXP sitmo_sitmo_two_seeds(SEXP, SEXP);

static const R_CallMethodDef CallEntries[] = {
  {"sitmo_runif_r",            (DL_FUNC) &sitmo_runif_r,            3},
  {"sitmo_runif_sitmo",        (DL_FUNC) &sitmo_runif_sitmo,        4},
  {"sitmo_sitmo_draws",        (DL_FUNC) &sitmo_sitmo_draws,        1},
  {"sitmo_sitmo_engine_reset", (DL_FUNC) &sitmo_sitmo_engine_reset, 2},
  {"sitmo_sitmo_engine_seed",  (DL_FUNC) &sitmo_sitmo_engine_seed,  2},
  {"sitmo_sitmo_parallel",     (DL_FUNC) &sitmo_sitmo_parallel,     2},
  {"sitmo_sitmo_two_seeds",    (DL_FUNC) &sitmo_sitmo_two_seeds,    2},
  {NULL, NULL, 0}
};

void R_init_sitmo(DllInfo *dll)
{
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}