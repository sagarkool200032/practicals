countlist([],0).
countlist([_|Tail],N) :- countlist(Tail, N1), N is N1 + 1.
