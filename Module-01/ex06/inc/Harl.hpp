#ifndef HARL_H
# define HARL_H

# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>

using namespace std;

class Harl{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		Harl();
		~Harl();
		void complain(string level);
};

#endif
