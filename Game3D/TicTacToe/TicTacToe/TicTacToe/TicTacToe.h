#include <SWI-cpp.h>
#include <string>

class TicTacToe{

	private:

	public:
		void RequestAIMove();
		void RequestPlayerMove(int pos);
		int getAICoord();
		void getMyCoord();
};