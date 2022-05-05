# writelist([]):-nl,!.
# writelist([H|T]):-write(H),nl,writelist(T).

# countlist([],0).
# coutlist([ _ |T],L):-countlist(T,LT),L is LT+1.

# find_max(X,Y,X):- X>Y,!.
# find_max(X,Y,"Both are equal"):- X =:=Y,!.
# find_max(X,Y,"The first Number is smaller than the second one"):- X<Y,!.

# sumlist([],0).
# sumlist([H|T]):-

list_concat([],L,L).
list_concat([X1|L1],L2,[X1|L3]):-list_concat(L1,L2,L3).