#include <string>
#include <vector>

using namespace std;

class HangMan{

private:
	vector<string> words;
	vector<char> wordChars;
	vector<string> board;
	string word;
	string hint;
	int sucesses;
	int wrongTries;
	bool playing;
	static const int max_tries_easy=6;
	static const int max_tries_moderate=4;
	static const int max_tries_hard=2;

public:
	HangMan();
	~HangMan();
	string Word();
	string Hint();
	void WordChars();
	void getWord();
	void getHint();
	void Start();
	void InitBoard();
	void UpdateBoard(vector<int> pos, string letter);
	void play();
	void checkGameState();
	vector<int> getCharOcorrences(char c);
	void out();
	void initialize();
	void fail();
	int randomize(int max, int min);
	string charToString(char c);
	void getWordCharsToVector();
	void render(void);
};


