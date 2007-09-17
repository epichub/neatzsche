; Note that fortran-comment-indent-style is set to relative in .emacs as well
; Note 2:  There is a problem with compiler directives written as CDEC$...
; because the indentation routine interprets these as comments and indents them,
; which in turn causes the compiler to interpret them as comments as well
; and therefore ignore them.
; Likewise, we don't want to indent !dec$ lines.

(defun fortran-indent-buffer (&optional show-lines)
  (interactive)
  (setq old-comment-column comment-column)
  (setq comment-column 51) ; want col 52 in devstudio, but devst is 1-based and emacs 0.
  (setq old-comm-ind-stl fortran-comment-indent-style)
  (setq fortran-comment-indent-style 'relative)
  (save-excursion
    ; Indent buffer
    (beginning-of-buffer)
    (while (not (= (point) (point-max)))
      (if show-lines
	  (message "%d " (count-lines (point-min) (point))))
      (fortran-indent-line)
;  Not needed, fixed by "setq indent-tabs-mode nil".
;      ; Replace all tabs with spaces, for code and comments
;      (beginning-of-line)
;      (if (= 99 (char-after)) (forward-char))
;      (if (= 9 (char-after))
;	  (progn
;	    (delete-char 1)
;	    (insert-char 32 6)))
      (next-line 1))
    ; Undo indentation of $ define lines
    (beginning-of-buffer)
    (while (re-search-forward "^     $     " nil t)
      (replace-match "$" t nil))
    ; Undo modification of cdec$
    (beginning-of-buffer)
    (while (re-search-forward "^c     [dD][eE][cC]$" nil t)
      (replace-match "CDEC$" t nil)))
  (setq comment-column old-comment-column)
  (setq fortran-comment-indent-style old-comm-ind-stl))

(defun fortran-indent-buffer-show-lines ()
  (interactive)
  (fortran-indent-buffer t))

(defun fortran-indent-file (file &optional show-lines)
  (interactive)
  (message "Indenting file %s" file)
  (find-file file)
  (fortran-mode)
  (setq indent-tabs-mode nil)
  (fortran-indent-buffer show-lines)
  (save-buffer)
  (kill-this-buffer))

; Does not quite work
; Also has some conceptual problems.  Example: "'" inside an inline comment ( ! this is such a comment)
; (defun pass-literal (pt-lit eol)
;   (goto-char pt-lit)
;   (let ((passed nil))
;     (while (and (not (= (point) (point-max)))
; 		(not passed))
;       (while (and (not (= (point) (point-max)))
; 		  (not (= eol (point)))
;  		  (not (= 39 (char-after))))
;  	(forward-char 1))
;       (if (= (char-after) 39)
; 	  (progn
; 	    (forward-char 1)
; 	    (let ((curpt (point)))
; 	      (message "Searching.. Point is %d" curpt)
; 	      (setq pt-lit (search-forward "'" eol t))
; 	      (if pt-lit
; 		  (progn
; 		    (message "Found literal in %d" pt-lit)
; 		  (downcase-region curpt pt-lit)
; 		  (goto-char pt-lit))
; 		(progn
; 		  (message "No literal, point is %d and curpt is " (point) pt-lit)
; 		  (setq passed t)
; 		  (downcase-region curpt eol))))))
;       (if (= eol (point))
; 	  (progn 
; 	    (beginning-of-line)
; 	    (next-line 1)
; 	    (while (and (not (= (char-after) 32))
; 			(not (= (point) (point-max))))
; 	      (next-line 1))
; 	    (end-of-line)
; 	    (setq eol (point))
; 	    (beginning-of-line))))))
      

; ; Does not quite work
; (defun fortran-downcase-buffer ()
;   (interactive)
;   (save-excursion
;     ; Downcase everything that is not a comment
;     (beginning-of-buffer)
;     (while (not (= (point) (point-max)))
;       (if (= 32 (char-after))  ; Only check outside comment
; 	  (let ((curpt (point)) eol pt-literal)
; 	       (end-of-line)
; 	       (setq eol (point))
; 	       (goto-char curpt)
; 	       (setq pt-literal (search-forward "'" eol t))
; 	       (if (not pt-literal)  ; This happens when no literal
; 		   (progn 
; 		     (downcase-region curpt eol)
; 		     (next-line 1)
; 		     (beginning-of-line))
; 		 (progn
; 		   (message "Passing.  pt-lit is %d and eol is %d" pt-literal eol)
; 		   (pass-literal pt-literal eol))))
; 	(next-line 1)))))


(defun fortran-format-buffer (&optional show-lines)
  (interactive)
  (save-excursion
    ; Change all line continuation signs to ampersand (&)
    ; (Do this before indentation, otherwise ! in col 6 will be indented as comment
    (beginning-of-buffer)
    (while (re-search-forward "^     [!-~]" nil t) ; Search for everything from #33 to next nonprint (#128)
      (replace-match "     &" nil nil))
    ; Begin all whole-line comments with 'c'
    (beginning-of-buffer)
    (while (re-search-forward "^[cC!&]" nil t)
      (replace-match "c" t nil)))
  ; Indent
  (fortran-indent-buffer show-lines)
  (fortran-downcase-buffer))
    
(defun fortran-format-buffer-show-lines ()
  (interactive)
  (fortran-format-buffer t))

(defun fortran-format-file (file &optional show-lines)
  (interactive)
  (message "Formatting and indenting file %s:" file)
  (find-file file)
  (fortran-mode)
  (setq indent-tabs-mode nil)
  (fortran-format-buffer show-lines)
  (save-buffer)
  (kill-this-buffer))


; Example usage for batch mode:
; For indenting:
; Find all files you want to indent, create a file of commands for indenting them:
;     for f in `find . -type f -not -name '*-all.lisp' -not -name 'result*.txt' -not -name '*~'`; do echo "(fortran-indent-file \"$f\")" >>indent-all.lisp; done
; Launch emacs in batch mode to do the actual indenting:
;     emacs -batch -l ~/prog/emacs-lisp/b-fortran.el -l indent-all.lisp 
; 
; For formatting:
; Find all files you want to format, create a file of commands for formatting them:
;     for f in `find . -type f -not -name '*-all.lisp' -not -name 'result*.txt' -not -name '*~'`; do echo "(fortran-format-file \"$f\")" >>format-all.lisp; done
; Launch emacs in batch mode to do the actual indenting:
;     emacs -batch -l ~/prog/emacs-lisp/b-fortran.el -l format-all.lisp 
; 
; Optional: edit the commands for files containing warnings to (fortran-[indent/format]-file <filename> t)
; in order to display line numbers, then run emacs batch mode again.