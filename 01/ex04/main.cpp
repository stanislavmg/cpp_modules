#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

#define SIZE 1024

namespace WordReplacer
{
	class WordReplacer
	{
		std::string		_OldWord;
		std::string		_NewWord;
		std::fstream	_OldFile;
		std::fstream	_NewFile;
	public:
		WordReplacer(char *Fname, char *OldWord, char *NewWord);
		~WordReplacer();
		void	replace_word(void);
	};

	WordReplacer::WordReplacer(char *Fname, char *OldWord, char *NewWord):
				_OldWord(OldWord), _NewWord(NewWord), _OldFile(Fname, std::ios::in)
	{
		std::string	NewFname(Fname);

		NewFname += ".replace";
		_NewFile.open(NewFname, std::ios::out | std::ios::trunc);
		if (_NewFile.fail() || _OldFile.fail()){
			std::cout << "WordReplacer: File open error" << std::endl;
			exit(1);
		}
	}

	WordReplacer::~WordReplacer()
	{
		_OldFile.close();
		_NewFile.close();
	}

	void	WordReplacer::replace_word(void)
	{
		std::string	buf;
		size_t		pos;

		while (std::getline(_OldFile, buf)){
		
			pos = buf.find(_OldWord);
			while (pos != std::string::npos){
				buf.erase(pos, _OldWord.size());
				buf.insert(pos, _NewWord);
				pos = buf.find(_OldWord);
			}
			_NewFile << buf;
			if (_OldFile.peek() == '\n')
				_NewFile << '\n';
		}
	}
}

int main(int ac, char **av)
{
	if (ac != 4)
		return (1);
	WordReplacer::WordReplacer	wr(av[1], av[2], av[3]);
	wr.replace_word();
}
