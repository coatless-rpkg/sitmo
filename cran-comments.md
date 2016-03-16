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

Authors@R field should be a call to person(), or combine such calls.
Found the following (possibly) invalid URLs:
  URL: http://cran.r-project.org/package=sitmo
    From: README.md
    Status: 404
    Message: Not Found
  URL: http://homepage.stat.uiowa.edu/~mbognar/omprng/
    From: inst/doc/sitmo_internals.html
    Status: Error
    Message: libcurl error code 7
    	Failed to connect to homepage.stat.uiowa.edu port 80: Operation timed out


* This is a new release.
* The homepage section of stat.uiowa.edu appears to be down. (This link has been active since 2013 and the person who wrote it is employed by the statistics department still.)

## Reverse dependencies

This is a new release, so there are no reverse dependencies.

