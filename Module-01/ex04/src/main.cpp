#include "../inc/include.hpp"

int main(int argc, char** argv) {
	if (argc < 4) {
		std::cerr << "Uso: " << argv[0] << " archivo s1 s2" << std::endl;
		return 1;
	}

	std::string file = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream infile(file.c_str());
	if (!infile) {
		std::cerr << "Error abriendo el archivo: " << file << std::endl;
		return 1;
	}

	std::string out = file + ".replace";
	std::ofstream outfile(out.c_str());
	if (!outfile){
		std::cerr << "Error creando el archivo de reemplazo: " << out << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(infile, line)) {
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		outfile << line << std::endl;
	}

	infile.close();
	outfile.close();

	//system("leaks -q sedisforloser");
	return 0;
}
