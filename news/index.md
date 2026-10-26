# Changelog

## sitmo 2.0.2

CRAN release: 2021-10-13

### DEPLOYMENT

- Switched from using TravisCI to using GitHub Actions.

### BUGFIXES

- Addressed unbalanced chunk delimiters in vignette. (thanks
  [yihui/knitr#2057](https://github.com/yihui/knitr/issues/2057)!)
- Addressed compilation with Rcpp 1.0.7 introducing new stream handling.

## sitmo 2.0.1

CRAN release: 2019-01-07

### CHANGES

- Modified `vandercorput.h` by adding a newline to the end of the file.
- Modified `Makevars{.win}` to use `$(SHLIB_OPENMP_CXXFLAGS)` instead of
  `$(SHLIB_OPENMP_CFLAGS)` in `PKG_CXXFLAGS`

### TESTING INFRASTRUCTURE

- Modified `.travis.yml` to compile using both cores instead of only
  one.

## sitmo 2.0.0

CRAN release: 2018-07-01

### NEW

- Added `threefry` and `vandercorput`
  ([\#9](https://github.com/coatless-rpkg/sitmo/issues/9),
  [\#10](https://github.com/coatless-rpkg/sitmo/issues/10)).
- Added contributor Ralf Stubner ([@rstub](https://github.com/rstub))

### CHANGES

- Modified `threefry` to be fully *C++11* compliant.
  ([\#11](https://github.com/coatless-rpkg/sitmo/issues/11),
  [@rstub](https://github.com/rstub))
- Removed the `Rcpp.plugin.maker()`

## sitmo 1.2.2

CRAN release: 2017-11-18

### BUGFIXES

- Addressed import of `Rcpp.plugin.maker()` by using the *exported*
  variable name, e.g. `::`, in place of the *internal* variable name,
  e.g. `:::` ([\#7](https://github.com/coatless-rpkg/sitmo/issues/7)).
- Updated `sitmo` URL to point to `stdfin/random`
  ([\#8](https://github.com/coatless-rpkg/sitmo/issues/8)).

## sitmo 1.2.1

CRAN release: 2017-07-30

### BUGFIXES

- Removed extra ; in sitmo header to quiet compile warnings
  ([\#4](https://github.com/coatless-rpkg/sitmo/issues/4), thanks
  [@helske](https://github.com/helske))
- Updated
  [`sitmo_two_seeds()`](https://r-pkg.thecoatlessprofessor.com/sitmo/reference/sitmo_two_seeds.md)
  src and documentation in “Deployment of `sitmo` within C++ Code” so
  that it uses the second seed for eng2 and returns an n x 2 matrix
  instead of n x 3.
  ([\#5](https://github.com/coatless-rpkg/sitmo/issues/5), thanks
  [@helske](https://github.com/helske))

## sitmo 1.2.0

CRAN release: 2017-06-25

### CHANGES

- Added plugin registration for `Rcpp:::Rcpp.plugin.maker()`
  ([\#3](https://github.com/coatless-rpkg/sitmo/issues/3))
- Added `CxxFlags()` and `sitmoCxxFlags()` functions to display
  `CXX_FLAGS` required by `sitmo`.
  ([\#3](https://github.com/coatless-rpkg/sitmo/issues/3))
- Updated examples in README.Rmd and SITMO internal vignette to use the
  Rcpp depends attribute.
  ([\#3](https://github.com/coatless-rpkg/sitmo/issues/3))

### BUGFIXES

- Corrected a signed and unsigned integer comparison in “Making a
  Uniform PRNG with `sitmo`” vignette.
- Fixed notation in “Making a Uniform PRNG with `sitmo`” vignette.

## sitmo 1.1.0

CRAN release: 2017-04-28

### CHANGES

- Added `src/init.c` to address R 3.4 C++ registration requirement
  ([\#2](https://github.com/coatless-rpkg/sitmo/issues/2))
- Clarified content in “Making a Uniform PRNG with `sitmo`” vignette.

### BUG FIXES

- Addressed signed and unsigned integer comparison in sitmo header
  ([\#1](https://github.com/coatless-rpkg/sitmo/issues/1))
- Corrected a URL that was problematic in “Deployment of `sitmo` within
  C++ Code” vignette.

## sitmo 1.0.0

CRAN release: 2016-03-19

### NEW

- Embedded `sitmo` header file in an R package.
- Provided code examples using `sitmo` header file.
- Released three vignettes detailing `sitmo` contents:
  - Deployment of `sitmo` within C++ Code
  - Making a Uniform PRNG with `sitmo`
  - `sitmo`’s BigCrush Results
