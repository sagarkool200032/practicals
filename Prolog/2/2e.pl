find_max(X,Y,"X is greater"):- X>Y,!.
find_max(X,Y,"Both are equal"):- X =:=Y,!.
find_max(X,Y,"Y is greater"):- X<Y,!.