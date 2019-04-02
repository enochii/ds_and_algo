;;generate the combinations whose number is r and value
;;is between 1 and n
(define (print lat)
  (cond ((null? lat) 'done)
        (else (display (car lat))
              (print (cdr lat)))))
(define xi
  (lambda (n r lat)
    (cond ((= r 0) (display lat)(newline))
          ((= n 0) 'fail)
          (else (xi (- n 1) (- r 1) (cons n lat))
                (xi (- n 1) r lat)))))
(xi 5 3 '())
(define rev-xi
  (lambda (n cur r lat)
    (cond ((= r 0) (display lat)(newline))
          ((= n cur) 'fail)
          (else (rev-xi n (+ cur 1) (- r 1) (cons (+ cur 1) lat))
                (rev-xi n (+ cur 1) r lat)))))
(rev-xi 5 0 3 '())