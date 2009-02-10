 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 ;   		b-misc.el
 ;   Created on Sun May 05 2002 by Boye A. Høverstad.
 ;   
 ;   Miscellaneous customizations and utility routines
 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defun get-buffer-from-name (buf-name)
  (defun rec (buf-list)
    (if (and (car buf-list)
	     (not (equal (buffer-name (car buf-list)) buf-name)))
	(rec (cdr buf-list))
      (car buf-list)))
  (rec (buffer-list)))

(defun my-run-breve-simulation ()
  "Run the \"breve\" shell command with the current tz file as argument.  
Prompts to save buffers before running."
  (interactive)
  (save-some-buffers)
  (setq tz-buffer (buffer-file-name))
  (if tz-buffer
      (progn
       (shell "*breve-shell*")
       (goto-char (point-max))
       (insert (concat "breve " tz-buffer))
       (comint-send-input))
;      (shell-command (concat "breve " (buffer-file-name) " &") "*breve-shell*" "*breve-shell*")
;      (comint-run (concat "breve " (buffer-file-name)))

    (print "Current buffer has no file name.  Save the buffer in order to run the simulation."))
    )

(defun breve-mode ()
  "Text mode with additional key bindings of C-f5 and f5 to run breve simulation."
  (interactive)
  (text-mode)
  (local-set-key [C-f5] 'my-run-breve-simulation)
  (local-set-key [f5] 'my-run-breve-simulation))


(defun load-my-hf-tags ()
  "Runs \"update.etags\" from $HOME/prog/hf and visits current
directory TAGS file. Current directory should be .../hf or a
subdirectory of this for the function to work as intended."
  (interactive)
  (shell-command "cwd=`pwd`; cd $HOME/prog/hf; source ./update.etags >/dev/null; cd $cwd")
  (visit-tags-table (substring (pwd) (length "Directory ")))
  )

;; Redefine to lower left corner
(defun mouse-avoidance-banish-destination ()
  "The position to which mouse-avoidance-mode `banish' moves the mouse.
You can redefine this if you want the mouse banished to a different corner."
  (cons 0 (1- (frame-height))))


(defun my-insert-comment ()
  "Inserts borders for a c++ comment the way I like them."
  (interactive)
  (insert "
/********************************************************************
 *   
 *******************************************************************/")
  (end-of-line 0)			; 0 means go back one line first.
  )


(defun my-tex-file ()
  "Wrapper around `tex-file' to clear the tex buffer before issuing the command.  
Checks for existence of buffer \"*tex-shell*\", and clear it if present.  
Then runs `tex-file'."
  (interactive)
  (let ((tex-buf (get-buffer-from-name "*tex-shell*")))
    (if tex-buf
	(save-excursion
	  (set-buffer tex-buf)
	  (delete-region (point-min) (point-max)))))
  (tex-file))


; (defun bind-my-tex-file ()
;   "Bind C-c C-f to `my-tex-file' instead of `tex-file'.  Do this from `tex-shell-hook'
; as it is overridden from `latex-mode' when in the `latex-mode-hook'."
;   WRONG!!
;   (interactive)
;   (local-set-key "\C-c\C-f" 'my-tex-file))

(defun my-latex-customisation ()
  "Some customisations to latex mode, called by `latex-mode-hook'."
  (interactive)
;   (font-lock-add-keywords 'latex-mode '(("\\$\\$.\*\\$\\$" . font-lock-string-face)))
;   (local-unset-key "\C-i")
;   (local-set-key "\C-i\C-c" 'insert-curly-braces)
  (local-set-key "\C-c\C-f" 'my-tex-file)
  (local-set-key "\C-c\C-c" 'comment-region)
  (local-set-key [f7] 'my-tex-file)
  (local-set-key [f5] 'tex-view)
  (local-set-key [C-f5] 'tex-view)
;  (add-hook 'tex-shell-hook 'bind-my-tex-file)
  )

(defun my-clean-cvs-notes ()
  "Quick hack to be able to remove \"CVS:\" from notes when commiting
files by use of shortcut."
  (interactive)
  (replace-regexp "CVS:" "")
)

(global-set-key [S-M-f3] 'my-clean-cvs-notes)
