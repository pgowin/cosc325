#lang racket

; public static int calculatePlus(int a, int b) {
;    return a + b;
; }

(define (calculatePlus a b)
  (+ a b))

; public static int calculateSomething(Function<Integer, Integer> f, int a, int b) {
;    return f.apply(a, b);
; }
(define (calculateSomething fun a b)
  (fun a b))

(define (buildAdder x) (lambda (a) (+ a x)))
(define add3 (buildAdder 3))
(define add7 (buildAdder 7))
; (define (add3 b) (+ 3 b))
; (define (add7 b) (+ 7 b))

; special higher order functions that apply to lists of data
;  map - repeatedly apply a function to the values in a list creating a new list of results
(map add7 '(1 2 3 4 5))
(map (lambda (a b c) (+ a b c)) '(1 2 3 4 5) '(7 7 7 7 7) '(1 1 1 1 1))

; filter - filters a list with a function elements must "pass" in order to stay in the list
; ArrayList<Integer> nums = new ArrayList<>(); // load nums up with 7 through 13
; Iterator<Integer> it = nums.iterator();
; while (it.hasNext()) {
;  if (it.next() >= 10) {
;     it.remove();
;  }
; }
(filter (lambda (a) (< a 10)) '(7 8 9 10 11 12 13))
(> (length (filter (lambda (a) (< a 10)) '(7 8 9 10 11 12 13))) 2)

; fold (better known as "reduce") - reduces a list to a single number using a function
(foldl + 0 '(1 2 3 4 5 6 7 8 9 10))  

(define (ensure-nonempty nums who)
  (when (null? nums)
    (error who "expected a non-empty list")))

(define (mean nums)
  (ensure-nonempty nums 'mean)
  (/ (foldl + 0 nums) (length nums)))

(define (median nums)
  (ensure-nonempty nums 'median)
  (define sorted (sort nums <))
  (define n (length sorted))
  (define mid (quotient n 2))
  (if (odd? n)
      (list-ref sorted mid)
      (/ (+ (list-ref sorted (- mid 1))
            (list-ref sorted mid))
         2)))

(define (mode nums)
  (ensure-nonempty nums 'mode)
  (define counts
    (for/fold ([acc (hash)]) ([n nums])
      (hash-update acc n add1 0)))
  (define max-count (apply max (hash-values counts)))
  (sort
   (for/list ([k (in-list (hash-keys counts))]
              #:when (= (hash-ref counts k) max-count))
     k)
   <))

(define (list-min nums)
  (ensure-nonempty nums 'list-min)
  (apply min nums))

(define (list-max nums)
  (ensure-nonempty nums 'list-max)
  (apply max nums))

(module+ main
  ; Sample usage
  (define sample '(5 1 3 3 9 7 3 1))
  (displayln (mean sample))
  (displayln (median sample))
  (displayln (mode sample))
  (displayln (list-min sample))
  (displayln (list-max sample)))

