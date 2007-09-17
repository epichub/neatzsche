 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 ;   		compile-libs.el
 ;   Created on Sun May 05 2002 by Boye A. Høverstad.
 ;   
 ;   Compile the other libraries
 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; (byte-compile-file "b-build.el")
; (byte-compile-file "b-cc-style.el")
; (byte-compile-file "b-misc.el")

; Last argument (0) means recompile .el file even if .elc file does not exist.
(byte-recompile-directory (substring (pwd) (length "Directory ")) 0)


