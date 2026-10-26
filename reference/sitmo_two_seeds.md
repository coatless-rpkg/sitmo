# Two RNG engines running side-by-side

Shows how to create two separate RNGs and increase them together.

## Usage

``` r
sitmo_two_seeds(n, seeds)
```

## Arguments

- n:

  An `unsigned int` that dictates how many realizations occur.

- seeds:

  A `vec` containing two integers greater than 0.

## Value

A `matrix` with random sequences.

## Examples

``` r
n = 10
a = sitmo_two_seeds(n, c(1337, 1338))

b = sitmo_two_seeds(n, c(1337, 1337))

isTRUE(all.equal(a[,1], a[,2]))
#> [1] FALSE

isTRUE(all.equal(b[,1], b[,2]))
#> [1] TRUE

isTRUE(all.equal(a[,1], b[,1]))
#> [1] TRUE
```
