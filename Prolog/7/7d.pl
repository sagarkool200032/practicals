female('Jenna Maguire').
female('Jessica Garfield').
female('Angela Holland').
female('Kelly Kapoor').
female('Lisa Paul').

male('Tobey Maguire').
male('Andrew Garfield').
male('Tom Holland').
male('Chris Evans').
male('Ben Affleck').

parents('Tobey Maguire', 'Jenna Maguire').
parents('Andrew Garfield', 'Jessica Garfield').
parents('Tom Holland', 'Angela Holland').

mother(X,Y):- parents(Y,X),female(X).
father(X,Y):- parents(X,Y),male(X).
haschild(X):- parents(X,_).
haschild(Y):- parents(_,Y).