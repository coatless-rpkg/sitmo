# sitmo 1.2.0

## CHANGES

- Added plugin registration for `Rcpp:::Rcpp.plugin.maker()` (#3)
- Added `cxx_flags()` and `sitmo_cxx_flags()` functions to display `CXX_FLAGS`
  required by `sitmo`. (#3)
- Updated examples in README.Rmd and SITMO internal vignette to 
  use the Rcpp depends attribute. (#3)

## BUGFIX

- Corrected a signed and unsigned integer comparison in 
  "Making a Uniform PRNG with `sitmo`" vignette.
- Fixed notation in "Making a Uniform PRNG with `sitmo`" vignette.


# sitmo 1.1.0

## CHANGES

- Added `src/init.c` to address R 3.4 C++ registration requirement (#2)
- Clarified content in "Making a Uniform PRNG with `sitmo`" vignette.

## BUG FIXES

- Addressed signed and unsigned integer comparison in sitmo header (#1)
- Corrected a URL that was problematic in "Deployment of `sitmo` within C++ Code" vignette.

# sitmo 1.0.0

## NEW

- Embedded `sitmo` header file in an R package.
- Provided code examples using `sitmo` header file.
- Released three vignettes detailing `sitmo` contents: 
    - Deployment of `sitmo` within C++ Code
    - Making a Uniform PRNG with `sitmo`
    - `sitmo`'s BigCrush Results
    