<!-- README.md is generated from README.Rmd. Please edit that file -->
[![Travis-CI Build Status](https://travis-ci.org/coatless/sitmo.svg?branch=master)](https://travis-ci.org/coatless/sitmo)[![CRAN RStudio mirror downloads](http://cranlogs.r-pkg.org/badges/sitmo)](http://www.r-pkg.org/pkg/sitmo) [![CRAN\_Status\_Badge](http://www.r-pkg.org/badges/version/sitmo)](https://cran.r-project.org/package=sitmo)

SITMO for R
===========

The repository houses the `sitmo` R package for Parallel Psuedo Random Number Generation (PPRNG). The package provides a way to obtain the `sitmo` header files via **LinkTo**.

Installing & Using `sitmo`
==========================

`sitmo` is currently only available on GitHub, but should also be available on CRAN shortly. To install the package, you must first have a compiler on your system that is compatible with R.

For help on obtaining a compiler consult:

-   [OS X](http://thecoatlessprofessor.com/programming/r-compiler-tools-for-rcpp-on-os-x/)
-   [Windows](http://thecoatlessprofessor.com/programming/rcpp/install-rtools-for-rcpp/)

With a compiler in hand, one can then install the package from GitHub by:

``` r
install.packages("devtools")

devtools::install_github("coatless/sitmo")
```

To use `sitmo` in your R package, modify the `DESCRIPTION` file by adding:

    LinkingTo: Rcpp, sitmo
    Imports:
        Rcpp (>= 0.12.10)

To use C++11's statistical distributions, you **may** want to add the following to your `src/Makevars` and `src/Makevars.win` file:

    CXX_STD = CXX11

Within the `C++` file, then add:

``` cpp
#include <sitmo.h> // SITMO PPRNG
```

Example use
===========

Below is a hello world example meant to show a basic implementation of `sitmo`.

``` cpp
#include <Rcpp.h>
#include <random>  // C++11 RNG library
#include <sitmo.h> // SITMO PPRNG

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
```
