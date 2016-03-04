#include <RcppArmadillo.h>
#include <random>
#include <prng_engine.h>

#ifdef _OPENMP
#include <omp.h>
#endif

double qexp( double u, double lambda ){
  
  u = std::log(0.1e1 - u);
  u = - u / lambda;
  
  return u;
}

//' Test Generation of a Random Exponential using sitmo and C++11
//' 
//' The function provides an implementation of creating realizations
//' an exponential 
//' 
//' @param n An \code{unsigned integer} denoting the number of realizations to generate.
//' @param lambda A \code{double} indicating the scale parameter of the distribution.
//' @param seeds A \code{vec} containing a list of seeds. Each seed is run on its own core.
//' @return A \code{vec} containing the realizations.
//' @details
//' The following function's true power is only accessible on platforms that support OpenMP (e.g. Windows and Linux).
//' However, it does provide a very good example as to how to make ones code applicable across multiple platforms.
//' 
//' With this being said, how we determine how many cores to split the generation to is governed by the number of seeds supplied.
//' In the event that one is using OS X, only the first seed supplied is used. 
//' 
//' @examples
//' a = sitmo_example(10, 5.0, c(1))
//' 
//' b = sitmo_example(10, 5.0, c(1))
//' 
//' c = sitmo_example(10, 5.0, c(2))
//' 
//' all.equal(a,b)
//' 
//' all.equal(a,c)
// [[Rcpp::export]]
arma::vec sitmo_example(unsigned int n, double lambda, const arma::vec& seeds){ 
  
  unsigned int ncores = seeds.n_elem;

  arma::vec q(n);
  
  #ifdef _OPENMP
  #pragma omp parallel num_threads(ncores) if(ncores > 1)
  {
  #endif
  
    // Engine requires uint32_t inplace of unsigned int
    uint32_t active_seed;
      
    // Write the active seed per core or just write one of the seeds.
    #ifdef _OPENMP
      active_seed = static_cast<uint32_t>(seeds(omp_get_thread_num()));
    #else
      active_seed = static_cast<uint32_t>(seeds(0));
    #endif
    
    sitmo::prng_engine engine( active_seed );
    std::uniform_real_distribution<double> distunif(0.0, 1.0);
  
  
    // Parallelize the Loop
    #ifdef _OPENMP
    #pragma omp for schedule(static)
    #endif
    for (unsigned int i = 0; i < n; i++){
      double u = distunif(engine);
      q(i) = qexp(u,lambda);
    }

  #ifdef _OPENMP
  }
  #endif
  
  return q;
}