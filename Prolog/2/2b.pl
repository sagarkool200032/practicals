list(1,[H|_],H) :- !.
list(N,[_|T],X) :- N1 is N-1, list(N1,T,X).