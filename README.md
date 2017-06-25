<!-- README.md is generated from README.Rmd. Please edit that file -->
[![Travis-CI Build Status](https://travis-ci.org/coatless/sitmo.svg?branch=master)](https://travis-ci.org/coatless/sitmo)[![CRAN RStudio mirror downloads](http://cranlogs.r-pkg.org/badges/sitmo)](http://www.r-pkg.org/pkg/sitmo) [![CRAN\_Status\_Badge](http://www.r-pkg.org/badges/version/sitmo)](https://cran.r-project.org/package=sitmo)

`sitmo`: A header-only package for *R* containing the SITMO PPRNG
=================================================================

The repository houses the `sitmo` R package for Parallel Psuedo Random Number Generation (PPRNG). The package provides a way to obtain the `sitmo` header files via **LinkTo**.

Installing `sitmo`
------------------

`sitmo` is available on both CRAN (Stable) and GitHub (Development). Using CRAN to download and install `sitmo` is the preferred option as it is significantly more stable vs. the GitHub version.

### Stable (CRAN) Install Instructions

To install the package from CRAN, you can simply type:

``` r
install.packages("sitmo")
```

The package will be installed and available in a similar fashion to other R packages. The main exception to this note is that to use `sitmo` to create a package you will need to acquire a compiler. This is detailed under the development install instructions.

### Development Install Instructions

To install the package, you must first have a compiler on your system that is compatible with R.

For help on obtaining a compiler consult:

-   [macOS](http://thecoatlessprofessor.com/programming/r-compiler-tools-for-rcpp-on-os-x/)
-   [Windows](http://thecoatlessprofessor.com/programming/rcpp/install-rtools-for-rcpp/)

With a compiler in hand, one can then install the package from GitHub by:

``` r
install.packages("devtools")

devtools::install_github("coatless/sitmo")
```

Using `sitmo`
-------------

There are two ways to use `sitmo`. The first is to use `sitmo` in a standalone script. The script is typically built using `sourceCpp()`. The second approach allows for `sitmo` to be used within an R package.

### Standalone file usage

Within the `C++` file, the `sitmo` package provides an Rcpp plugins' depends statement that must be included after `sitmo.h` header. This plugin statement indicates that a dependency is `sitmo`.

``` cpp
#include <rgen.h> 
// [[Rcpp::depends(sitmo)]]
```

Below is a hello world example meant to show a basic implementation of `sitmo`.

``` cpp
#include <Rcpp.h>
#include <random>  // C++11 RNG library
#include <sitmo.h> // SITMO PPRNG

// Rcpp depends attribute is required for standalone use. 
// It is not needed if in package linking to the sitmo package (detailed next).
// [[Rcpp::depends(sitmo)]]

// [[Rcpp::export]]
Rcpp::NumericVector sitmo_draws_ex(unsigned int n) {
  
  Rcpp::NumericVector o(n);
  
  // Create a prng engine
  sitmo::prng_engine eng;
  
  // Draw from base engine
  for (unsigned int i=0; i< n ; ++i){
    o(i) = eng();  
  }

  return o;
}

/*** R
sitmo_draws_ex(5)
*/
```

### Package usage

To use `sitmo` in your R package, modify the `DESCRIPTION` file by adding:

    LinkingTo: Rcpp, sitmo
    Imports:
        Rcpp (>= 0.12.11)

To use C++11's statistical distributions, you **may** want to add the following to your `src/Makevars` and `src/Makevars.win` file:

    CXX_STD = CXX11

Within the `C++` file, then add:

``` cpp
#include <sitmo.h> // SITMO PPRNG
```
