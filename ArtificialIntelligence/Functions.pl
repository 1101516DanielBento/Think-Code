sum(X,Y,Z):-
	Z is X + Y.

	
doWork(Work):-
	write(work),
	nl.
	
	
man(peter).
man(john).
woman(mary).
woman(martha).

married(peter,mary).

relationship(Man,Women):-
		married(Man,Women).
				
