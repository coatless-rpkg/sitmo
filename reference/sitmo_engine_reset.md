# Example Seed Set and RNG Draws with sitmo

Shows how to set a seed in sitmo.

## Usage

``` r
sitmo_engine_reset(n, seed)
```

## Arguments

- n:

  An `unsigned int` that dictates how many realizations occur.

- seed:

  An `unsigned int` that controls the rng seed.

## Value

A `matrix` with random sequences.

## Examples

``` r
n = 10
a = sitmo_engine_reset(n, 1337)

isTRUE(all.equal(a[,1],a[,2]))
#> [1] FALSE
```
