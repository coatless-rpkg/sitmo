#include <Rcpp.h>
#include <sitmo.h>


//' Random Uniform Number Generator with sitmo
//' 
//' The function provides an implementation of sampling from a random uniform distribution
//' 
//' @param n    An \code{unsigned integer} denoting the number of realizations to generate.
//' @param min  A \code{double} indicating the minimum \eqn{a} value 
//'               in the uniform's interval \eqn{\left[a,b\right]}
//' @param max  A \code{double} indicating the maximum \eqn{b} value 
//'               in the uniform's interval \eqn{\left[a,b\right]}
//' @param seed A special \code{unsigned integer} containing a single seed.
//' @return A \code{numeric vector} containing the realizations.
//' @export
//' @examples
//' a = runif_sitmo(10)
// [[Rcpp::export]]
Rcpp::NumericVector runif_sitmo(unsigned int n, double min = 0.0, double max = 1.0, uint32_t seed = 1) {
  Rcpp::NumericVector o(n);
  
  // Create a prng engine
  sitmo::prng_engine eng(seed);
  // Obtain the range between max and min
  double dis = max - min; 
  
  for(unsigned int i = 0; i < n; ++i) {
    // Sample from the RNG and divide it by the maximum value possible (can also use SITMO_RAND_MAX, which is 4294967295)
    // Apply appropriate scale (MAX-MIN)
    o[i] = min + ((double) eng() / (sitmo::prng_engine::max())) * (dis);
  }
  
  return o;
}

//' Random Uniform Number Generator using base R
//' 
//' The function provides an alternative implementation of random uniform distribution
//' sampling using R's rng scope. 
//' @param n    An \code{unsigned integer} denoting the number of realizations to generate.
//' @param min  A \code{double} indicating the minimum \eqn{a} value 
//'               in the uniform's interval \eqn{\left[a,b\right]}
//' @param max  A \code{double} indicating the maximum \eqn{b} value 
//'               in the uniform's interval \eqn{\left[a,b\right]}
//' @export
//' @examples
//' set.seed(134)
//' b = runif_r(10)
// [[Rcpp::export]]
Rcpp::NumericVector runif_r(unsigned int n, double min = 0.0, double max = 1.0) {
  Rcpp::NumericVector o(n);
  
  for(unsigned int i = 0; i < n; ++i) {
    o[i] = R::runif(min,max);
  }
  
  return o;
}