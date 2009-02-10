 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 ;   		b-cc-style.el
 ;   Created on Tue Mar 19 2002 by Boye A. Høverstad.
 ;   
 ;   Customized C++-mode style.  From the info page on cc-mode.
 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defconst my-c-style
  '( "gnu";; Inherit style from "gnu".  
     (c-tab-always-indent        . t)
     (c-comment-only-line-offset . 4)
     (c-hanging-braces-alist     . ((substatement-open after)
				    (brace-list-open)
;				    (defun-open)
;				    (defun-close)
;				    (class-open)
;				    (class-close)
				    (inline-open)
				    (inline-close)
				    (block-open)
				    (block-close)
				    (substatement-open)
				    (statement-case-open)
				    (extern-lang-open)
				    (extern-lang-close)
				    (brace-list-open)
				    (brace-list-close)
				    (brace-list-intro)
				    (brace-entry-open)
				    (inexpr-class-open)
				    (inexpr-class-close)))
     (c-hanging-colons-alist     . ((member-init-intro before)
				    (inher-intro)
				    (case-label after)
				    (label after)
				    (access-label after)))
     (c-cleanup-list             . (scope-operator
				    empty-defun-braces
				    defun-close-semi))
     (c-offsets-alist            . ((arglist-close . c-lineup-arglist)
				    (substatement-open . 0)
				    (case-label        . 4)
				    (block-open        . 0)
				    (knr-argdecl-intro . -)))
     (c-echo-syntactic-information-p . t)
     )
  "My C Programming Style")
     
;; Customizations for all of c-mode, c++-mode, and objc-mode
(defun my-c-mode-common-hook ()
  ;; add my personal style and set it for the current buffer
  (c-add-style "PERSONAL" my-c-style t)
  ;; offset customizations not in my-c-style
  (c-set-offset 'member-init-intro '++)
  ;; other customizations
  (setq;; tab-width 8
   ;; this will make sure spaces are used instead of tabs
   indent-tabs-mode nil)
  ;; we like auto-newline and hungry-delete
;;  (c-toggle-auto-hungry-state 1)	
  ;; keybindings for all supported languages.  We can put these in
  ;; c-mode-base-map because c-mode-map, c++-mode-map, objc-mode-map,
  ;; java-mode-map, and idl-mode-map inherit from it.
  ;; (define-key c-mode-base-map "\C-m" 'newline-and-indent) ; No use for this, done already by C-j.
  ;; Finally some stuff I (Boye) have entered: (my-default-comment-column is set to global comment-column in ~/.emacs)
  (setq comment-column my-default-comment-column)
  )
     
(add-hook 'c-mode-common-hook 'my-c-mode-common-hook)




