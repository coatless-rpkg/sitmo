## Test environments
* local OS X install, R 3.2.4
* ubuntu 12.04 (on travis-ci), R 3.2.4
* win-builder (devel and release)

## R CMD check results

0 errors | 0 warnings | 1 note

License components with restrictions and base license permitting such:
  MIT + file LICENSE
File 'LICENSE':
  YEAR: 2016
  COPYRIGHT HOLDER: Thijs van den Berg, James Balamuta
  
Found the following (possibly) invalid URLs:
  URL: https://cran.r-project.org/package=sitmo
    From: README.md
    Status: 404
    Message: Not Found

* This is a new release.
* The CRAN url has yet to be created, which is causing the 404.
* Fixed the previous submit issues
    * Fixed link to be https instead of http
    * Fixed Authors@R field. 
    * Expanded description file to be more informative (included link)

## Reverse dependencies

This is a new release, so there are no reverse dependencies.

