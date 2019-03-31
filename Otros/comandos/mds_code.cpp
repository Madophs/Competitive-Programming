#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

string username = getenv("USER");
const int partialOptionSize = 6, fullOptionSize = 17, totalSize = partialOptionSize + fullOptionSize; 
bool fileExists(string filename){
	ifstream file(filename);
	return file.good();
}

void createFileIfNotExists(const char *filePath){
	ifstream file(filePath);
	if(!file.good()){
		ofstream create(filePath);
		create.close();
	}
}
void createIOFiles(string in, string out){
	createFileIfNotExists(in.c_str());
	createFileIfNotExists(out.c_str());
}

void preprocess(){
	string createDirectory = "mkdir -p /home/"+username+"/mds_code";
	string outputPath = "/home/"+username+"/mds_code/out.txt";
	string inputPath = "/home/"+username+"/mds_code/in.txt";
    system(createDirectory.c_str());
	createIOFiles(inputPath, outputPath);;
}

string getFileExtension(string fileName){
	int lastDotPosition = fileName.find_last_of('.') + 1;
	if(lastDotPosition == 0) return "404";
	string extension = fileName.substr(lastDotPosition, string::npos);
	return extension;
}

int main(int argc, char *argv[])
{
	preprocess();
    string fileName = "";
	cout<<setfill(' ');
    if(argc==1){
        cout<<"Faltan los parametros\nmds_code --help o -h para más ayuda"<<endl;
    }else{
		string option = argv[1];
        if(option == "-c" || option == "--c++"){
            if(argc>=3){
				string numbers = "";
				for(int x=2; x<argc; x++){
					if(!isalpha(argv[x][0]) && !isdigit(argv[x][0])) continue;
					if(x == 2 && regex_match(argv[x],regex("[0-9]+"))){
						numbers = argv[x];
						continue;
					}
					if(x>2+(!numbers.empty()))fileName+="_";
					fileName+=argv[x];
				}
				numbers = (numbers.empty())?"":"_"+numbers;
				fileName+=numbers;
				while(!fileName.empty() && (!isalpha(fileName[0]) && !isdigit(fileName[0]))) fileName.erase(fileName.begin());
				if(fileName.empty()){
					cout<<"Los nombres de archivo solo deben iniciar con números o letras para que funcione bien."<<endl;
					exit(1);
				}
				fileName+=".cpp";
				ofstream file(fileName,ios::out);
				if(!file){
					cout<<"Error al crear el archivo"<<endl;
					exit(1);
				}else{
					string libreria = "#include <bits/stdc++.h>\n\n";
					string st_namespace = "using namespace std;\n\n";
					string mainFunction = "int main(){\n";
					string ios_sync = "\tios_base::sync_with_stdio(false);\n";
					string cinTie = "\tcin.tie(NULL);\n";
					string coutTie = "\tcout.tie(NULL);\n\t\n";
					string ret = "\treturn 0;\n}";
					file<<libreria<<st_namespace<<mainFunction<<ios_sync<<cinTie<<coutTie<<ret;
				}
            }else{
				cout<<"Falta el nombre del archivo"<<endl;
			}

        }else if(option == "-j" || option == "--java"){
			if(argc>=3){
				string numbers = "";
				for(int x=2; x<argc; x++){
					if(x==2 && regex_match(argv[x],regex("[0-9]+"))){
						numbers = argv[x];
						continue;
					}
					if(x>2)fileName+="_";
					fileName+=argv[x];
				}
				if(fileName.empty()){
					cout<<"El nombre de la clase no es valido"<<endl;
					exit(1);
				}
				fileName.erase(remove_if(fileName.begin(),fileName.end(),[&](char c){
					return !isalpha(c) && !isdigit(c) && c!='_';
				}),fileName.end());
				if(!numbers.empty())fileName+="_"+numbers;
				if(fileName[0]=='_') fileName = fileName.substr(1,string::npos);
				if(!isalpha(fileName[0])){
					cout<<"El nombre de las clases deben iniciar can una letra para que funcionen bien"<<endl;
					exit(1);
				}
				string className = fileName;
				fileName+=".java";
				ofstream file(fileName,ios::out);
				if(!file){
					cout<<"Error al crear el archivo"<<endl;
					exit(1);
				}else{
					string imports = "import java.io.*;\n\n";
					string publicClass = "class "+className+" {\n\n";
					string publicStatic = "\tpublic static void main (String args[]) {\n";
					string instanceClass = "\t\t"+className+" madophs = new "+className+"();\n";
					string instanceMethod = "\t\tmadophs.justGetStarted();\n";
					string bufferedReader = "BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));";
					string tryCatch ="try{\n\t\t\t\n\t\t}catch(Exception e){};";
					string methodDeclaration = "\tvoid justGetStarted(){\n\t\t"+bufferedReader+"\n\t\t\n"+"\t\t"+tryCatch+"\n\t}\n}\n";
					file<<imports<<publicClass<<publicStatic<<instanceClass<<instanceMethod<<"\t}\n\n"<<methodDeclaration;
				}
            }else{
				cout<<"Falta el nombre del archivo"<<endl;
			}
        }else if(option == "-e" || option == "--extension"){
			if(argc == 2){
				cout<<"No extensión expecificada"<<endl;
				exit(1);
			}
			string extension = argv[2];
			if(argc>=4){
				for(int x=3; x<argc; x++){
					if(x>3)fileName+="_";
					fileName+=argv[x];
				}
				fileName+="."+extension;
				ofstream file(fileName,ios::out);
				if(!file){
					cout<<"Error al crear el archivo"<<endl;
					exit(1);
				}
            }else{
				cout<<"Falta el nombre del archivo"<<endl;
			}
		}else if(option == "-r" || option == "--run"){
			string command = "/home/"+username+"/mds_code/mds";
			system(command.c_str());
		}else if(option == "-rio" || option == "--run_with_io"){
			string command = "/home/"+username+"/mds_code/mds < /home/"+username+"/mds_code/in.txt > /home/"+username+"/mds_code/out.txt";
			system(command.c_str());
		}else if(option == "-b" || option == "--build"){
			if(argc  > 2){
				string tempFileExtension = getFileExtension(argv[2]);
				if(tempFileExtension == "java" || tempFileExtension == "cpp"){
					if(tempFileExtension == "cpp"){
						string tempFileName = argv[2];
						string command = "g++ -std=c++14 "+tempFileName+" -o /home/"+username+"/mds_code/mds";
						system(command.c_str());
					}else{
						string tempFileName = argv[2];
						string command = "javac "+tempFileName+" -o /home/"+username+"/mds_code/mds";
						system(command.c_str());
					}
				}else{
					cout<<"Error el archivo no contiene una extension válida. Actualmente solo se permiten codigos fuente de java y c++."<<endl;
				}
			}else{
				cout<<"Error: no se especifico el archivo"<<endl;
			}
		}else if(option == "-h" || option == "--help"){
			string encabezado = "Desarrollado por Jehú Jair Ruiz Villegas A.K.A Madophs.\n";
			string descripcion = "Mds Code genera archivos con extensión separado por guiones bajos,\nya viene con código predefinido para lenguages como c++ y java.\n";
			string sintaxis = "Uso = mds_code [opción] [parametros]\n";
			string op1 = "Opciones:\n";
			cout<<encabezado<<endl;
			cout<<descripcion<<endl;
			cout<<sintaxis<<endl;
			cout<<op1<<endl;
			cout<<setw(partialOptionSize)<<left<<"-j"<<setw(fullOptionSize)<<left<<"--java"<<"Crea un archivo java con código predefinido."<<endl;
			cout<<setw(partialOptionSize)<<left<<"-c"<<setw(fullOptionSize)<<left<<"--c++"<<"Crea un archivo de c++ (cpp) con código predefinido."<<endl;
			cout<<setw(partialOptionSize)<<left<<"-e"<<setw(fullOptionSize)<<left<<"--extension"<<"Crea un archivo con la extensión indicada: mds_code -e [extensión] [parametros]"<<endl;
			cout<<setw(partialOptionSize)<<left<<"-r"<<setw(fullOptionSize)<<left<<"--run"<<"Ejecuta el archivo binario /home/{usuario}/mds_code/mds (Solo soporta Java y C/C++)."<<endl;
			cout<<setw(partialOptionSize)<<left<<"-rio"<<setw(fullOptionSize)<<left<<"--run_with_io"<<"Ejecuta el archivo binario /home/{usuario}/mds_code/mds (Solo soporta Java y C/C++)."<<endl;
			cout<<setw(partialOptionSize)<<left<<"-b"<<setw(fullOptionSize)<<left<<"--build"<<"Construye el código fuente de archivo especificado (Solo soporta C++ Y Java)."<<endl;
			cout<<setw(totalSize)<<left<<" "<<"NOTA: el ejecutable generado se guarda en /home/{usuario}/mds_code bajo el nombre de mds"<<endl;
			cout<<setw(partialOptionSize)<<left<<"-h"<<setw(fullOptionSize)<<left<<"--help"<<"Muestra este menú de ayuda."<<endl;
		}else{
			cout<<"Error: opción desconocida\nmds_code --help o -h para más ayuda"<<endl;
		}
    }
    return 0;
}
