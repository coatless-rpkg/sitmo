## Test environments
* local OS X install, R 3.2.4
* ubuntu 12.04 (on travis-ci), R 3.2.4
* win-builder (devel and release)

## R CMD check results

0 errors | 0 warnings | 1 note

New submission

License components with restrictions and base license permitting such:
  MIT + file LICENSE
File 'LICENSE':
  YEAR: 2016
  COPYRIGHT HOLDER: Thijs van den Berg, James Balamuta

Possibly mis-spelled words in DESCRIPTION:
  CRAN (9:48)
  PPRNG (2:53, 7:57)

Found the following (possibly) invalid URLs:
  URL: https://cran.r-project.org/package=sitmo
    From: README.md
    Status: 404
    Message: Not Found
    
* This is a new release.
* The CRAN url has yet to be created, which is causing the 404.
* Fixed the previous submit issues
    * Misspelled title
* Non-issue: PPRNG as it is an acronym 

## Reverse dependencies

This is a new release, so there are no reverse dependencies.

