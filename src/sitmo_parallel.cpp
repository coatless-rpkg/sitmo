#include <Rcpp.h>
#include <sitmo.h> // SITMO PPRNG

#ifdef _OPENMP
#include <omp.h>
#endif

//' Test Generation using sitmo and C++11
//' 
//' The function provides an implementation of creating realizations from the default engine.
//' 
//' @param n An \code{unsigned integer} denoting the number of realizations to generate.
//' @param seeds A \code{vec} containing a list of seeds. Each seed is run on its own core.
//' @return A \code{vec} containing the realizations.
//' @details
//' The following function's true power is only accessible on platforms that support OpenMP (e.g. Windows and Linux).
//' However, it does provide a very good example as to how to make ones code applicable across multiple platforms.
//' 
//' With this being said, how we determine how many cores to split the generation to is governed by the number of seeds supplied.
//' In the event that one is using OS X, only the first seed supplied is used. 
//' 
//' @export
//' @examples
//' a = sitmo_parallel(10, c(1))
//' 
//' b = sitmo_parallel(10, c(1,2))
//' 
//' c = sitmo_parallel(10, c(1,2))
//' 
//' # True on only OS X or systems without openmp
//' isTRUE(all.equal(a,b))
//' 
//' isTRUE(all.equal(b,c))
// [[Rcpp::export]]
Rcpp::NumericVector sitmo_parallel(unsigned int n, Rcpp::NumericVector& seeds){ 
  
  unsigned int ncores = seeds.size();

  Rcpp::NumericVector q(n);
  
#ifdef _OPENMP
#pragma omp parallel num_threads(ncores) if(ncores > 1)
{
#endif
  
  // Engine requires uint32_t inplace of unsigned int
  uint32_t active_seed;
  
  // Write the active seed per core or just write one of the seeds.
#ifdef _OPENMP
  active_seed = static_cast<uint32_t>(seeds[omp_get_thread_num()]);
#else
  active_seed = static_cast<uint32_t>(seeds[0]);
#endif
  
  sitmo::prng eng( active_seed );
  
  // Parallelize the Loop
#ifdef _OPENMP
#pragma omp for schedule(static)
#endif
  for (unsigned int i = 0; i < n; i++){
    q[i] = eng();
  }
  
#ifdef _OPENMP
}
#endif

return q;
}