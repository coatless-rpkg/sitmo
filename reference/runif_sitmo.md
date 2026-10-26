# Random Uniform Number Generator with sitmo

The function provides an implementation of sampling from a random
uniform distribution

## Usage

``` r
runif_sitmo(n, min = 0, max = 1, seed = 1L)
```

## Arguments

- n:

  An `unsigned integer` denoting the number of realizations to generate.

- min:

  A `double` indicating the minimum \\a\\ value in the uniform's
  interval \\\left\[a,b\right\]\\

- max:

  A `double` indicating the maximum \\b\\ value in the uniform's
  interval \\\left\[a,b\right\]\\

- seed:

  A special `unsigned integer` containing a single seed.

## Value

A `numeric vector` containing the realizations.

## Examples

``` r
a = runif_sitmo(10)
```
