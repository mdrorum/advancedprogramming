
link(p1, p2).
link(p2, p3).
link(p6, end).
link(p3, p5).
link(p3, p7).
link(p7, p6).
link(p5, p6).
link(p6, end).
link(p3, end).

path(P, P) :-
    last(P, end).
path(P, Pout) :-
    last(P, L),
    link(L, O),
    append(P, [O], P2),
    path(P2, Pout).

run :-
    writeln('all paths from p1 to end:'),
    findall(P, path([p1], P), Ps),
    maplist(writeln, Ps).

