 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 ;   		b-build.el
 ;   Created on Sun May 05 2002 by Boye A. Høverstad.
 ;   
 ;   Utilities to ease building and debugging in emacs, inspired by
 ;   Microsoft Visual Studio.
 ;
 ;   2006-03-20 Removed definition of my-gud-buffer, and changed all
 ;   references from my-gud-buffer to the variable already used by
 ;   gud, namely gud-comint-buffer.
 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defvar my-compile-dir nil "Directory in which the compilation command `my-compile-command' will be issued.")
(defvar my-compile-command nil "Command executed by `my-compile-func'.")
(defvar my-make-command (if (getenv "OSTYPE")
			    (if (string-match "Solaris" (getenv "OSTYPE"))
				"nice btmake -j 4 -k "
			      "nice btmake -k ")
			  "nice btmake -k ")
  "Command to which the compilation target is appended to create `my-compile-command'.")
;;(defvar my-gud-buffer nil "Name of buffer in which the gdb debugger is running.")
(defvar my-prev-buildstyle 'debug "Previous build style.  Used by `my-compile-func' and `my-optimized-compile-func'.")

;; Doesn't work, use gdblib wrapper in ~/local/bin instead.
;; (defun gdb-libtool (cmdline)
;;   "Similar to `gdb', but with all the extra stuff needed to run a libtool generated
;; program.  Only works on emacs version 22.0.50 and above."
;;   (interactive "sRun gdb as: libtool --mode=execute gdb --fullname ")
;;   (eval '(gdb cmdline)))

(defun reset-my-compile-settings (dir target)
  "Resets custom compilation settings: Compilation directory and
compilation target.  See `my-compile-func' for more info."
  (interactive "DCompilation directory: \nsCompilation target: ")
  (setq my-compile-dir dir)
  (if target (setq my-compile-command (concat my-make-command target))
    (setq my-compile-command my-make-command)))

(defun reset-my-compile-target (target)
  "Resets custom compilation target only (not compilation directory).
See `my-compile-func' for more info."
  (interactive "sCompilation target: ")
  (if target (setq my-compile-command (concat my-make-command target))
    (setq my-compile-command my-make-command)))

(defun my-compile-func ()
  "Custom compilation routine, based on Microsoft Visual Studio and
initially bound to keystroke F7.  If called for the first time, asks
for compilation directory and compilation target to be run as the
target of the compilation command set by `my-make-command',
initially \"nice btmake -k \".  Then the compilation command is run in
the indicated directory."
  (interactive)
  (if (not (and my-compile-dir my-compile-command))
      (call-interactively 'reset-my-compile-settings))
    (progn
      (defvar cwd nil)
      (setq cwd (substring (pwd) (length "Directory ")))
      (cd my-compile-dir)
      (compile my-compile-command)
      (if (not (equal my-prev-buildstyle 'debug))
	(message "WARNING: Build style seems to have changed.  Was this a full rebuild?"))
      (setq my-prev-buildstyle 'debug)
      
      (cd cwd)))

;; (let ((comp-buf (get-buffer-from-name "*compilation*")))
;;   (if comp-buf
;;       (save-excursion
;; 	(set-buffer comp-buf)
;; 	(beginning-of-buffer)
;; 	(if (and (not (search-forward "error" nil t))
;; 		 (not (search-forward "warning" nil t))
;; 	    (kill-buffer comp-buf)))))

(defun my-optimized-compile-func ()
  "Same as `my-compile-func', but adds \"BUILDSTYLE=optimize\" to the
compilation command.  Requires a Makefile designed accordingly."
  (interactive)
  (if (not (and my-compile-dir my-compile-command))
      (call-interactively 'reset-my-compile-settings))
    (progn
      (defvar cwd nil)
      (setq cwd (substring (pwd) (length "Directory ")))
      (cd my-compile-dir)
      (defvar my-optim-compile-command nil)
      (setq my-optim-compile-command (concat my-compile-command " BUILDSTYLE=optimize"))
      (compile my-optim-compile-command)
      (unless (equal my-prev-buildstyle 'optimize)
	(message "WARNING: Build style seems to have changed.  Was this a full rebuild?"))
      (setq my-prev-buildstyle 'optimize)
      (cd cwd)))

(defun reset-my-debug-func ( debug-target )
  "Resets the command string given to the `gdb' command.  Should be of
the form \"gdb [program-name]\".  Options to gdb are not supported, as
the rest of the command string following \"gdb \" is used in
combination with \"*gud-\" and \"*\" to generate the buffer name
`my-debug-func' brings to front."
  (interactive (list (gud-query-cmdline 'gdb))) ;; "sRun debug sequence as: ")
;;  (setq my-gud-buffer (concat "*gud-" (substring debug-target (length "gdb ")) "*"))
  (gdb debug-target))

(defun my-debug-func ()
  "Switches to the buffer given in `gud-comint-buffer'.  If this is nil,
calls `reset-my-debug-func' first to initalise it."
  (interactive)
  (if (not gud-comint-buffer)
      (call-interactively 'reset-my-debug-func)
    (pop-to-buffer gud-comint-buffer)))

(defun my-gud-next ()
  "Brings the buffer given in `gud-comint-buffer' to front, and executes
the command `gud-next'."
  (interactive)
  (if (not gud-comint-buffer)
      (message "No gud buffer set.  Run my-debug-func.")
    (progn
      (pop-to-buffer gud-comint-buffer)
      (gud-next 1))))

(defun my-gud-step ()
  "Brings the buffer given in `gud-comint-buffer' to front, and executes
the command `gud-step'."
  (interactive)
  (if (not gud-comint-buffer)
      (message "No gud buffer set.  Run my-debug-func.")
    (progn
      (pop-to-buffer gud-comint-buffer)
      (gud-step 1))))

(defun my-gud-finish ()
  "Brings the buffer given in `gud-comint-buffer' to front, and executes
the command `gud-finish'."
  (interactive)
  (if (not gud-comint-buffer)
      (message "No gud buffer set.  Run my-debug-func.")
    (progn
      (pop-to-buffer gud-comint-buffer)
      (gud-finish 1))))

(global-set-key [f4] 'next-error)
(global-set-key [S-f4] 'previous-error)
(global-set-key [f5] 'gud-cont)
(global-set-key [C-f5] 'my-debug-func)
(global-set-key [S-C-f5] 'reset-my-debug-func)
(global-set-key [f7] 'my-compile-func)
(global-set-key [M-f7] 'my-optimized-compile-func)
(global-set-key [C-f7] 'reset-my-compile-settings)
(global-set-key [C-S-f7] 'reset-my-compile-target)
(global-set-key [f10] 'my-gud-next)
(global-set-key [f11] 'my-gud-step)
(global-set-key [S-f11] 'my-gud-finish)

