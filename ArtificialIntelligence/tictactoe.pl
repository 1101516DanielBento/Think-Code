/* 
 * A tic tac toe game using minimax searching.
 * Written as an example program for CISC 260, Winter 2006.
 * author: M. Lamb
 *
 * Note: My comments describing predicates follow the convention
 * of the SWI-Prolog manual.  A "+" before a parameter name
 * means the parameter is an "input" parameter: it should be bound 
 * before the predicate is used.  A "-" denotes an "output"
 * parameter: the predicate will give the parameter a value.
 * A "?" means the parameter may be either bound or unbound.
 */

/*
 * Step 1: Decide on a representations for the tic tac toe board.
 * Number the squares 1 through 9. This program will print empty
 * squares by displaying their numbers; that will make it easy
 * for the user to specify a move.
 * 
 * Record a game state using four items: 
 *   1. whose turn it is (x or o),
 *   3. a list of squares x is occupying, 
 *   4. a list of squares o is occupying.  
 * Example: state(x, [1,3],[2,9]) means it is x's turn, and 
 * the board looks like this:
 *    x o x
 *    4 5 6
 *    7 8 o
 * The lists of x's and o's will always be in order, to help
 * detect states we've already seen.
 *
 * Also decide on the evaluation values:
 *   2 = X wins
 *   1 = draw (a tie, nobody wins)
 *   0 = O wins
 * Note that X wants to maximize this value and O wants to minimize it.
 */
 
% A few general helper predicates
 
% associates a player with their opponent, for alternating moves
opponent(x,o).
opponent(o,x).

% extracts the player from a state
player(state(x,_,_),x).
player(state(o,_,_),o).

% addToList(+List,+Item,-NewList): adds Item to List, where
% List is an ordered list of numbers, producing NewList. 
% NewList will also be numbered
addToList([],Item,[Item]).
addToList([Head|Tail],Item,[Item,Head|Tail]) :-
  Item =< Head.
addToList([Head|Tail],Item,[Head|NewTail]) :-
  Item > Head,
  addToList(Tail,Item,NewTail).
  
% ordSubset(+Subset,+List) means Subset is a subset of
% List, assuming both lists are ordered lists of numbers.
% (A faster check than the check provided by the 
% built-in subset predicate)
ordSubset([],_).
ordSubset([X|Tail1],[X|Tail2]) :-
  !,
  ordSubset(Tail1,Tail2).
ordSubset([X|Tail1],[Y|Tail2]) :-
  X > Y,
  ordSubset([X|Tail1], Tail2).
 
/*
 * Step 2: predicate for displaying a game state.  Do this early because
 * it will be very useful while debugging.  
 * displayBoard(+State) displays the board as a 3x3 grid.  
 * Does not display whose turn it is; that will be obvious during the game.
 */
displayState(state(_,Xlist,Olist)) :-
  displayRow(1,Xlist,Olist),
  write('   ---------\n'),
  displayRow(4,Xlist,Olist),
  write('   ---------\n'),
  displayRow(7,Xlist,Olist).
  
% displayRow(+Start, +Xlist, +Olist):
% displays one row of the tic tac toe board.
% Start is the first square of the row
displayRow(Start, Xlist, Olist) :-
  tab(3), % looks better if it's indented a bit
  displaySquare(Start, Xlist, Olist),
  write('| '),
  Second is Start+1,
  displaySquare(Second, Xlist, Olist),
  write('| '),
  Third is Second+1,
  displaySquare(Third, Xlist, Olist),
  nl.
  
% displaySquare(+Number, +Xlist, +Olist):
% displays one square (number or X or O), followed by a space
displaySquare(Number, Xlist, _) :-
  member(Number, Xlist),
  !,
  write('X ').
displaySquare(Number, _, Olist) :-
  member(Number, Olist),
  !,
  write('O ').
displaySquare(Number, _, _) :-
  write(Number),
  tab(1).
  

/*
 * Step 3: Evaluate "terminal" states.
 *  2 = X wins
 *  1 = draw
 *  0 = O wins
 * terminal(+State,-Value) means that State
 * is a terminal state and its value is Value.
 */
terminal(state(_,Xlist,_),2) :-
  winningComb(Comb),
  ordSubset(Comb,Xlist),
  !.
terminal(state(_,_,Olist),0) :-
  winningComb(Comb),
  ordSubset(Comb,Olist),
  !.
% if all squares are taken and nobody has won, it's a draw
terminal(state(_,Xlist,Olist),1) :-
  length(Xlist,Xlength),
  length(Olist,Olength),
  Xlength+Olength =:= 9.  

% These facts enumerate the 8 winning combinations
winningComb([1,2,3]). % first row
winningComb([4,5,6]). % second row
winningComb([7,8,9]). % third row
winningComb([1,4,7]). % first column
winningComb([2,5,8]). % second column
winningComb([3,6,9]). % third column
winningComb([1,5,9]). % \ diagonal
winningComb([3,5,7]). % / diagonal

/*
 * Step 4: Specify legal moves.  
 * moves(+State,-NewStates) means NewStates is a list of all the
 * possible state that can result from State by adding a mark to an unoccupied
 * space in Board.
 */

% For efficiency, try only the three logically different moves from an initial state
moves(state(x,[],[]),[state(o,[1],[]),state(o,[2],[]),state(o,[5],[])]) :- !.
moves(state(0,[],[]),[state(x,[],[1]),state(x,[],[2]),state(x,[],[5])]) :- !.

moves(State, NewStates) :-
  generateMoves(State, 1, NewStates).
  
% generateMoves(+State, +FirstSquare, -NewStates) means NewStates is a list of
% the possible states that can result from State, considering all the
% squares from FirstSquare to 9.
generateMoves(_, FirstSquare, []) :-
    FirstSquare > 9,
    !.
generateMoves(state(Player,Xlist,Olist), FirstSquare, NewStates) :-
    (member(FirstSquare, Xlist) ; member(FirstSquare, Olist)), 
    % FirstSquare is occupied
    !,
    NextSquare is FirstSquare+1,
    generateMoves(state(Player,Xlist,Olist), NextSquare, NewStates).
generateMoves(state(x,Xlist,Olist), FirstSquare,    
                      [FirstState|MoreStates]) :-
    addToList(Xlist, FirstSquare, NewXlist),
    FirstState = state(o, NewXlist, Olist),
    NextSquare is FirstSquare+1,
    generateMoves(state(x,Xlist,Olist), NextSquare, MoreStates).
generateMoves(state(o,Xlist,Olist), FirstSquare, 
                      [FirstState|MoreStates]) :-
    addToList(Olist, FirstSquare, NewOlist),
    FirstState = state(x,Xlist,NewOlist),
    NextSquare is FirstSquare+1,
    generateMoves(state(o,Xlist,Olist), NextSquare, MoreStates).
  
/*
 * Step 5: Minimax evaluation.  minimax(+State,-BestMove,-Value) means
 * that BestMove is the best move from State and Value is the value of that move.  
 * This means the best value from the point of view of the current player 
 * (specified inside State).  
 *
 * To improve efficiency, we will save some of the moves we find for later
 * use.  After experimenting, I decided on saving all the decisions we
 * make at depth 5 -- i.e. when there are exactly 5 marks on the board.
 * I've used the dynamic predicate foundBest to record the results of
 * minimax for non-terminal states at level 5.
 */
:- dynamic(foundBest/3).

% Base case: the state is terminal, so we just report its value.
minimax(State, _, Value) :-
  terminal(State, Value),
  !.  
  
% Another base case: we've already seen this state and recorded 
% the best move to make from it.
minimax(State, BestMove, Value) :-
  foundBest(State, BestMove, Value),
  % write('remembered '), write(State), nl,   % debug
  !.
  
% More difficult case: choose the best alternative from the list of possible moves
minimax(State, BestMove, Value) :-
  moves(State, Moves),
  player(State, Player),
  bestMove(Player, Moves, BestMove, Value),
  remember(State, BestMove, Value).
  
remember(State, BestMove, Value) :-
  numMarks(State, Count),
  Count = 5,
  !,
  % write('recording '), write(State), nl, % debug
  assert(foundBest(State, BestMove, Value)).
remember(_,_,_). % so remember doesn't fail otherwise and stop the game

% counts the number of marks (X's and O's) on the board
numMarks(state(_,Xlist,Olist), Count) :-
  length(Xlist, Xcount),
  length(Olist, Ocount),
  Count is Xcount + Ocount.
  
  
% bestMove(+Player, +Moves, -BestMove, -Value) means BestMove is the best alternative from
% the Moves list and Value is its value.  The "best" alternative is chosen from the
% point of Player: X will try to maximize Value and O will try to minimize it.

% Base case: only one possible move: just evaluate that move
bestMove(_,[OneMove],OneMove,Value) :-
  !,
  minimax(OneMove, _, Value).
  
% More than one possible move: Evaluate the first move and
% compare it with the best move from the tail of the list
bestMove(Player, [FirstMove|OtherMoves], BestMove, BestValue) :-
  minimax(FirstMove, _, ValueFromFirst),
  bestMove2(Player, FirstMove, ValueFromFirst, OtherMoves, BestMove, BestValue).
  
bestMove2(x, Move, 2, _, Move, 2) :- !.
bestMove2(o, Move, 0, _, Move, 0) :- !.
bestMove2(Player, Move, Value, MoveList, BestMove, BestValue) :-
  bestMove(Player, MoveList, MoveFromList, ValueFromList),
  choose(Player, Move, Value, MoveFromList, ValueFromList, BestMove, BestValue).
  
% choose(+Player, +Move1, +Val1, +Move2, +Val2, -BestMove, -BestVal) means that
% (BestMove,BestVal) is either (Move1,Val1) or (Move2,Val2) -- whichever one
% is best forPlayer.
choose(x, Move1, Val1, _, Val2, Move1, Val1) :-
  % x chooses the maximum value
  Val1 >= Val2,
  !.
choose(x, _, _, Move2, Val2, Move2, Val2).
choose(o, Move1, Val1, _, Val2, Move1, Val1) :-
  % o chooses the minimum value
  Val1 =< Val2,
  !.
choose(o, _, _, Move2, Val2, Move2, Val2).

/*
 * Step 6: I/O code to play the game.
 * For simplicity, the computer always is X and
 * the user always is O.  
 */

% play(State) starts play at the specified state and 
% continues until the game is won, lost or drawn.
reportEnding(2) :-
  write('I WIN!!!\n').
reportEnding(1) :-
  write('This game is a draw.\n').
reportEnding(0) :-
  write('YOU WIN!!!\n').
  
play(State) :-
  terminal(State,Value),
  !,
  reportEnding(Value).

play(State) :-
  player(State,x), % computer's turn
  !,
  write('searching for my move...\n'),
  minimax(State,BestMove,_),
  displayState(BestMove),
  play(BestMove).
  
play(State) :-
  % user's turn
  write('enter your move (followed by a period): \n'),
  read(Square),
  makeMove(State, Square, NextState),
  displayState(NextState),
  play(NextState).
  
makeMove(state(o,Xlist,Olist), Square, state(x,Xlist,NewOlist)) :-
  member(Square,[1,2,3,4,5,6,7,8,9]),
  not(member(Square,Xlist)),
  not(member(Square,Xlist)),
  !,
  addToList(Olist, Square, NewOlist).
makeMove(_, Square, _) :-
  write(Square), write(' is not a legal move\n'),
  fail.

% Play a game from the beginning, computer goes first
ttt :-  
  showAndPlay(state(x,[],[])).
% Play a game from the beginning, user goes first
meFirst :-
  showAndPlay(state(o,[],[])).
showAndPlay(State) :-
  displayState(State),
  play(State).
  