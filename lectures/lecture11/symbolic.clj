; clj
; (load-file "symbolic.clj")
; (-main)

(defn -main []
  ; defining a value for "a". quoting prevents evaluation
  (let [a '(println "hola")]
    ; run println. same structure as data
    (println "hola")
    ; run a. eval'ing a quoted s-exp "removes" the quote
    (eval a)
    (eval a)))

