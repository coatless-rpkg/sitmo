inlineCxxPlugin = Rcpp:::Rcpp.plugin.maker(
  include.before = "#include <sitmo.h>", 
  package        = "sitmo"
)

sitmoCxxFlags = function(){
  paste0( '-I"', system.file( "include", package = "sitmo" ), '"') 
}

CxxFlags = function(){
  cat( sitmoCxxFlags() )
}
