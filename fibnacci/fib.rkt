;#lang racket

;;left-up, left-down, right-up, right-down
(define (lu mat) (caar mat))
(define (ld mat) (caadr mat))
(define (ru mat) (cadar mat))
(define (rd mat) (cadadr mat))

;multiplicate matrix whose dimension is 2, e.g.,
;(
;   (1 1)  * (1 1)
;   (1 1)    (1 1)
;)
(define (mul-smat m1 m2)
    (list
     (list (+ (* (lu m1) (lu m2)) (* (ru m1) (ld m2))) (+ (* (lu m1) (ru m2)) (* (ru m1) (rd m2))))
     (list (+ (* (ld m1) (lu m2)) (* (rd m1) (ld m2))) (+ (* (ld m1) (ru m2)) (* (rd m1) (rd m2))))
    )
)
;
;(mul-smat2 '((1 1)(1 0)) '((1 1)(1 0)))
;(mul-smat2 '((2 1) (1 1)) '((2 1) (1 1)))
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(load "matrix.rkt")
(define mul-smat2 mul-matrixs)
(define (fib n)
    (define (fib-mat-iter n mat)
        (cond 
        ((= n 1) mat)
        ((= (remainder n 2) 0) (fib-mat-iter (/ n 2) (mul-smat2 mat mat)))
        (else (mul-smat2 (fib-mat-iter (- n 1) mat) mat))
        )
    )
    (ru
        (fib-mat-iter (+ 1 n) '((1 1)(1 0)))
    )
)
;;test
(=(fib 0) 1)
(=(fib 1) 1)
(=(fib 2) 2)
(=(fib 3) 3)
(=(fib 4) 5)
(=(fib 5) 8)
(=(fib 6) 13)
(=(fib 7) 21)
(=(fib 8) 34)
(=(fib 9) 55)
;