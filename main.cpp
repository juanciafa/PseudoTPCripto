#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>

#include "Array.h"
#include "cmdline.h"

#define DBG(x) cerr << #x << ":" << (x) << endl

using namespace std;

static void opt_input(string const &arg);

static option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
	{0, }
};

static istream *input_stream = 0;
static fstream ifs;

static void opt_input(string const &arg)
{
	if(arg == "-") {
		input_stream = &cin;
	}
	else{
		ifs.open(arg.c_str(), ios::in);
		input_stream = &ifs;
	}

	if(!input_stream-> good()){
		cerr << "Error al abrir archivo " << arg << endl;
		exit(1);
	}
}

int main(int argc, char * const argv[])
{
	// Luego de parsear el archivo de entrada, leo líneas, las convierto en
	// streams con la clase stringstream, de las cuales leo e imprimo arreglos
	// hasta no encontrar más. Si en una línea hay un arreglo escrito 
	// de manera incorrecta, no acepto ninguno más

	cmdline cmdl(options);
	string str;
	stringstream str_st;
	Array<int> arr;

	cmdl.parse(argc, argv);
	while(getline(*input_stream,str)){
		stringstream str_st (str);
		while( (str_st >> arr) && (!str_st.eof()) ){
			if( arr.size() != 0){
				cout << arr << endl;
			}else{
				str_st.clear(ios::badbit);
			}
		}
	}

	return 0;
}
