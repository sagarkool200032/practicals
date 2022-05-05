display_even:-write('THE LIST IS EVEN').
display_odd:-write('THE LIST IS ODD').
check(X):- length(X,L),L>=0 ->
(
L1 is mod(L,2),
L1=:=0 -> display_even;display_odd
).