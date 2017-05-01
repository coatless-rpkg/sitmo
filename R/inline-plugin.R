inline_cxx_plugin = Rcpp:::Rcpp.plugin.maker(
  include.before = "#include <sitmo.h>", 
  package        = "sitmo"
)

sitmo_cxx_flags = function(){
  paste0( '-I"', system.file( "include", package = "sitmo" ), '"') 
}

cxx_flags = function(){
  cat( sitmo_cxx_flags() )
}
