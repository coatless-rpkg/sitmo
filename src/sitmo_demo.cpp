#include <Rcpp.h>
#include <sitmo.h> // SITMO PPRNG

//' Example RNG Draws with sitmo
//' 
//' Shows a basic setup and use case for sitmo. 
//' 
//' @param n A \code{unsigned int} is a .
//' @return A \code{vec} with random sequences. 
//' @export
//' @examples
//' n = 10
//' a = sitmo_draws(n)
// [[Rcpp::export]]
Rcpp::NumericVector sitmo_draws(unsigned int n) {
  
  Rcpp::NumericVector o(n);
  
  // Create a prng engine
  sitmo::prng_engine eng;
  
  // Draw from base engine
  for (unsigned int i=0; i< n ; ++i){
    o(i) = eng();  
  }

  return o;
}

//' Example Seed Set and RNG Draws with sitmo
//' 
//' Shows how to set a seed in sitmo. 
//' 
//' @param n    An \code{unsigned int} that dictates how many realizations occur.
//' @param seed An \code{unsigned int} that controls the rng seed. 
//' @return A \code{vector} with random sequences. 
//' @export
//' @examples
//' n = 10
//' a = sitmo_engine_seed(n, 1337)
//' b = sitmo_engine_seed(n, 1337)
//' c = sitmo_engine_seed(n, 1338)
//' 
//' isTRUE(all.equal(a,b))
//' isTRUE(all.equal(a,c))
// [[Rcpp::export]]
Rcpp::NumericVector sitmo_engine_seed(unsigned int n, unsigned int seed) {
  
  // Create Rcpp Matrix
  Rcpp::NumericVector o(n);
  
  // Create a prng engine with a specific seed
  sitmo::prng_engine eng(static_cast<uint32_t>(seed));
  
  // Draw from base engine
  for (unsigned int i=0; i < n; ++i){
    o(i) = eng();        
  }

  return o;
}

//' Example Seed Set and RNG Draws with sitmo
//' 
//' Shows how to set a seed in sitmo. 
//' 
//' @param n    An \code{unsigned int} that dictates how many realizations occur.
//' @param seed An \code{unsigned int} that controls the rng seed. 
//' @return A \code{matrix} with random sequences. 
//' @export
//' @examples
//' n = 10
//' a = sitmo_engine_reset(n, 1337)
//' 
//' isTRUE(all.equal(a[,1],a[,2]))
// [[Rcpp::export]]
Rcpp::NumericMatrix sitmo_engine_reset(unsigned int n, unsigned int seed) {
  
  // Create Rcpp Vector
  Rcpp::NumericMatrix o(n,2);
  
  // Create a prng engine with a specific seed
  sitmo::prng_engine eng(static_cast<uint32_t>(seed));
  
  // Draw from base engine
  for (unsigned int i=0; i < n ; ++i){
    o(i,0) = eng();        
  }
  
  // Reset seed
  eng.seed();
  
  // Draw from base engine
  for (unsigned int i=0; i< n ; ++i){
    o(i,1) = eng();        
  }  
  
  return o;
}


//' Two RNG engines running side-by-side
//' 
//' Shows how to create two separate RNGs and increase them together. 
//' 
//' @param n     An \code{unsigned int} that dictates how many realizations occur.
//' @param seeds A \code{vec} containing two integers greater than 0. 
//' @return A \code{matrix} with random sequences. 
//' @export
//' @examples
//' n = 10
//' a = sitmo_two_seeds(n, c(1337, 1338))
//' 
//' b = sitmo_two_seeds(n, c(1337, 1337))
//' 
//' isTRUE(all.equal(a[,1], a[,2]))
//' 
//' isTRUE(all.equal(b[,1], b[,2]))
//' 
//' isTRUE(all.equal(a[,1], b[,1]))
// [[Rcpp::export]]
Rcpp::NumericMatrix sitmo_two_seeds(unsigned int n, Rcpp::NumericVector seeds) {
  
  if(seeds.size() != 2) Rcpp::stop("Need exactly two seeds for this example.");
  
  // Create Rcpp Matrix
  Rcpp::NumericMatrix o(n, 2);
  
  // Create a prng engine with a specific seed
  sitmo::prng_engine eng1;
  eng1.seed(seeds(0));
  
  sitmo::prng_engine eng2;
  eng2.seed(seeds(1));

  // Draw from base engine
  for (unsigned int i = 0; i < n ; ++i){
    o(i,0) = eng1();      
    o(i,1) = eng2();        
  }  
  
  return o;
}