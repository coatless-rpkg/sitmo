#include <RcppArmadillo.h>
#include <random>
#include <sitmo.h>


// [[Rcpp::export]]
arma::vec qexp( arma::vec& u, double lambda ){
  
  u = arma::log(0.1e1 - u);
  u = - u / lambda;
  
  return u;
}

double qexp( double u, double lambda ){
  
  u = std::log(0.1e1 - u);
  u = - u / lambda;
  
  return u;
}


// Simulate samples

// // [[Rcpp::export]]
// arma::vec rexp( unsigned int n, double lambda, const unsigned int& seed ){
//   
//   arma::vec u(n);
//   
//   // Generate a vector of uniform random variables
//   // std::srand(seed);
//   std::mt19937_64 engine(seed);  // Mersenne twister random number engine
//   std::uniform_real_distribution<double> distr(0.0, 1.0);
//   u.imbue( [&]() { return distr(engine); } );
//   
//   // Transform into Dagum random variables
//   qexp(u,lambda);
//   
//   return u;
// }

// [[Rcpp::export]]
arma::vec test_sitmo(unsigned int n, double lambda, arma::vec seeds){ 
  
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