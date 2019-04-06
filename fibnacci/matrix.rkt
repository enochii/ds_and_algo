;#lang racket

;
(define (reduce op init lat)
    (cond 
        ((null? lat) init)
        (else (op (car lat) (reduce op init (cdr lat))))
    )
)
(define (mul-row-col row col)
    (reduce + 0 (map * row col))
)
; (mul-row-col '(1 1 1) '(2 3 4))
(define (mul-row-matrix row mat)
    (map (lambda (col) (mul-row-col row col)) mat)
)
(define (mul-matrixs m1 m2)
    (map (lambda (row) (mul-row-matrix row m2)) m1)
)
;
; (mul-matrixs '((1 1) (1 0)) '((1 1) (1 0)))
;
;;TODO : implementation without map...