# Random Uniform Number Generator using base R

The function provides an alternative implementation of random uniform
distribution sampling using R's rng scope.

## Usage

``` r
runif_r(n, min = 0, max = 1)
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

## Examples

``` r
set.seed(134)
b = runif_r(10)
```
