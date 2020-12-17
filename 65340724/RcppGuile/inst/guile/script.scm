;; https://gist.github.com/ncweinhold/9724254
(define simple-func
  (lambda ()
    (display "Script called, now I can change this") (newline)))

(define quick-test
  (lambda ()
    (display "Adding another function, can modify without recompilation")
    (newline)
    (adding-without-recompilation)))

(define adding-without-recompilation
  (lambda ()
    (display "Called this, without recompiling the C code") (newline)))
