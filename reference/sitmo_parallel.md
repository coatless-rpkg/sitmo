# Test Generation using sitmo and C++11

The function provides an implementation of creating realizations from
the default engine.

## Usage

``` r
sitmo_parallel(n, seeds)
```

## Arguments

- n:

  An `unsigned integer` denoting the number of realizations to generate.

- seeds:

  A `vec` containing a list of seeds. Each seed is run on its own core.

## Value

A `vec` containing the realizations.

## Details

The following function's true power is only accessible on platforms that
support OpenMP (e.g. Windows and Linux). However, it does provide a very
good example as to how to make ones code applicable across multiple
platforms.

With this being said, how we determine how many cores to split the
generation to is governed by the number of seeds supplied. In the event
that one is using OS X, only the first seed supplied is used.

## Examples

``` r
a = sitmo_parallel(10, c(1))

b = sitmo_parallel(10, c(1,2))

c = sitmo_parallel(10, c(1,2))

# True on only OS X or systems without openmp
isTRUE(all.equal(a,b))
#> [1] FALSE

isTRUE(all.equal(b,c))
#> [1] TRUE
```
