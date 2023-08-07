#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar da string

int registro(){ //Fun��o respons�vel por cadastrar os usu�rios no sistema
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", cpf); //% refere-se � string CPF
	
	strcpy(arquivo, cpf); //Respos�vel por copiar os valores da string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo
	fprintf(file,cpf); //Salva o valor da vari�vel CPF
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Adiciona caracteres dentro do arquivo
	fprintf(file, ","); //Caracter v�rgula inserido
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��o para cadastro
	scanf("%s",nome); //%s refere-se � string Nome
	
	file = fopen(arquivo, "a"); //Adiciona caracteres dentro do arquivo
	fprintf(file,nome); //Salva o valor da vari�vel nome
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Adiciona caracteres dentro do arquivo
	fprintf(file, " "); //Caracter espa�o inserido
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��es para cadastro
	scanf("%s",sobrenome); //%s refere-se � string Sobrenome
	
	file = fopen(arquivo, "a"); //Adiciona caracteres dentro do arquivo
	fprintf(file,sobrenome); //Salva o valor da vari�vel sobrenome
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Adiciona caracteres dentro do arquivo
	fprintf(file, ", "); //Caracter v�rgula inserido
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Colentando informa��o para cadastro
	scanf("%s",cargo); //%s refere-se � string Cargo
	
	file = fopen(arquivo, "a"); //Adiciona caracteres dentro do arquivo
	fprintf(file,cargo); //Salva o valor da vari�vel cargo
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa o programa
}

int consulta(){ //M�dulo de consulta
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Inser��o de dados para consulta
	scanf("%s",cpf); //%s refere-se � string CPF
	
	FILE *file; //Cria o arquivo/abre o arquivo
	file = fopen(cpf,"r"); //Leitura do arquivo
	
	if(file == NULL){ //Se o arquivo for nulo, inexistente
		printf("Arquivo n�o existe!\n"); //Imprime essa informa��o
	}
	
	while(fgets(conteudo, 200, file) != NULL){ //Enquanto os dados de consulta forem diferentes de "nulo"
		printf("\nEssas s�o as informa��es do usu�rio: "); //Mostra as informa��es do usu�rio
		printf("%s", conteudo); //%s refere-se � string Conte�do
		printf("\n\n"); //Pula linha
	}
	
	system("pause"); //Pausa o programa
}

int deletar(){ //M�dulo de exclus�o de arquivos/usu�rios
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Inser��o de dados
	scanf("%s", cpf); //%s refere-se � string CPF
	
	remove(cpf); //Remove permanentemente o arquivo CPF
	
	FILE *file; //Cria/abre o arquivo
	file = fopen(cpf,"r"); //Leitura do arquivo
	
	if(file == NULL){ //Se o arquivo for nulo/inexistente
		printf("Usu�rio deletado com sucesso. O usu�rio n�o se encontra no sistema!\n"); //Imprime esta informa��o
		system("pause"); //Pausa o programa
	}
}

int main(){ //M�dulo Menu
	
	int opcao=0; //Definindo as var�veis
	int laco=1;
	
	for(laco=1;laco=1;) //Loop do programa
	{
	
		system("cls"); //Limpa a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("\t### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada no menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: ");//Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //Limpa a tela
	
		switch(opcao){ //Chamada de fun��es
			case 1:
				registro();
				break;
				
			case 2:
				consulta();
				break;
				
			case 3:
				deletar();
				break;
				
			default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
		}
	
	}
	//Fim da sele��o
}