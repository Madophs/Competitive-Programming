#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    string fileName = "";
    if(argc==1){
        cout<<"Faltan los parametros\nmds_code --help o -h para más ayuda"<<endl;
    }else{
		string option = argv[1];
        if(option == "-c" || option == "--c++"){
            if(argc>=3){
				string numbers = "";
				for(int x=2; x<argc; x++){
					if(x == 2 && regex_match(argv[x],regex("[0-9]+"))){
						numbers = argv[x];
						continue;
					}
					if(x>2+(!numbers.empty()))fileName+="_";
					fileName+=argv[x];
				}
				numbers = (numbers.empty())?"":"_"+numbers;
				fileName+=numbers;
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
				if(isdigit(fileName[0])){
					cout<<"El nombre de las clases no deben iniciar con números"<<endl;
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
					string publicClass = "public class "+className+" {\n\n";
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
		}else if(option == "-h" || option == "--help"){
			string ayuda = "";
			string encabezado = "Desarrollado por Jehú Jair Ruiz Villegas A.K.A Madophs.\n\n";
			string descripcion = "Mds Code genera archivos con extensión separado por guiones bajos,\nya viene con código predefinido para lenguages como c++ y java.\n\n";
			string sintaxis = "Uso = mds_code [opción] [parametros]\n\n";
			string op1 = "Opciones:\n\n-h  --help         Muestra este menú de ayuda.\n";
			string op2 = "-c  --c++          Crea un archivo de c++ (cpp) con código predefinido.\n";
			string op3 = "-j  --java         Crea un archivo java con código predefinido.\n";
			string op4 = "-e  --extension    Crea un archivo con la extensión indicada: mds_code -e [extensión] [parametros]\n";
			ayuda = encabezado+descripcion+sintaxis+op1+op2+op3+op4;
			cout<<ayuda<<endl;
		}else{
			cout<<"Error opción desconocida\nmds_code --help o -h para más ayuda"<<endl;
		}
    }
    return 0;
}
