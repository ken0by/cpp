#include "../inc/file.hpp"

int main(int argc, char** argv) {
	if (argc < 4) {
		cerr << "Uso: " << argv[0] << " archivo s1 s2" << endl;
		return 1;
	}

	string file = argv[1];
	string s1 = argv[2];
	string s2 = argv[3];

	ifstream infile(file);
	if (!infile) {
		cerr << "Error abriendo el archivo: " << file << endl;
		return 1;
	}

	string out = file + ".replace";
	ofstream outfile(out);
	if (!outfile){
		cerr << "Error creando el archivo de reemplazo: " << out << endl;
		return 1;
	}

	string line;
	while (getline(infile, line)) {
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != string::npos) {
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		outfile << line << endl;
	}

	infile.close();
	outfile.close();

	//system("leaks -q sedisforloser");
	return 0;
}
