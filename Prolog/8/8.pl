% solve( Node, Solution):
%    Solution is an acyclic path (in reverse order) between Node and a goal

goal(f).
goal(j).
s(a,b).
s(a,c).
s(b,d).
s(b,e).
s(c,f).
s(c,g).
s(d,h).
s(e,i).
s(e,j).



solve( Node, Solution)  :-   depthfirst( [], Node, Solution).

% depthfirst( Path, Node, Solution):
%   extending the path [Node | Path] to a goal gives Solution

depthfirst( Path, Node, [Node | Path] )  :-    goal( Node).

depthfirst( Path, Node, Sol)  :- s( Node, Node1),\+ member( Node1, Path),depthfirst( [Node | Path], Node1, Sol).

depthfirst2( Node, [Node], _)  :- goal( Node).

depthfirst2( Node, [Node | Sol], Maxdepth)  :-    Maxdepth > 0,   s( Node, Node1),   Max1 is Maxdepth - 1,   depthfirst2( Node1, Sol, Max1).

