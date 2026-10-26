# Example Seed Set and RNG Draws with sitmo

Shows how to set a seed in sitmo.

## Usage

``` r
sitmo_engine_seed(n, seed)
```

## Arguments

- n:

  An `unsigned int` that dictates how many realizations occur.

- seed:

  An `unsigned int` that controls the rng seed.

## Value

A `vector` with random sequences.

## Examples

``` r
n = 10
a = sitmo_engine_seed(n, 1337)
b = sitmo_engine_seed(n, 1337)
c = sitmo_engine_seed(n, 1338)

isTRUE(all.equal(a,b))
#> [1] TRUE
isTRUE(all.equal(a,c))
#> [1] FALSE
```
