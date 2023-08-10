#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocação de texto por região
#include <string.h> //Biblioteca responsável por cuidar da string

int registro(){ //Função responsável por cadastrar os usuários no sistema
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", cpf); //% refere-se à string CPF
	
	strcpy(arquivo, cpf); //Resposável por copiar os valores da string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo
	fprintf(file,cpf); //Salva o valor da variável CPF
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Adiciona caracteres dentro do arquivo
	fprintf(file, ","); //Caracter vírgula inserido
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informação para cadastro
	scanf("%s",nome); //Refere-se à string Nome
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informações para cadastro
	scanf("%s",sobrenome); //%s refere-se à string Sobrenome
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //Colentando informação para cadastro
	scanf("%s",cargo); //%s refere-se à string Cargo
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //Pausa o programa
}

int consulta(){ //Módulo de consulta
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Inserção de dados para consulta
	scanf("%s",cpf); //%s refere-se à string CPF
	
	FILE *file; //Cria o arquivo/abre o arquivo
	file = fopen(cpf,"r"); //Leitura do arquivo
	
	if(file == NULL){ //Se o arquivo for nulo, inexistente
		printf("Arquivo não existe!\n"); //Imprime essa informação
	}
	
	while(fgets(conteudo, 200, file) != NULL){ //Enquanto os dados de consulta forem diferentes de "nulo"
		printf("\nEssas são as informações do usuário: "); //Mostra as informações do usuário
		printf("%s", conteudo); //%s refere-se à string Conteúdo
		printf("\n\n");
		fclose(file);
	}
	
	system("pause");
}

int deletar(){ //Módulo de exclusão de arquivos/usuários
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); //Inserção de dados
	scanf("%s", cpf); //%s refere-se à string CPF
	
	remove(cpf); //Remove permanentemente o arquivo CPF
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){ //Se o arquivo for nulo/inexistente
		printf("Usuário deletado com sucesso. O usuário não se encontra no sistema!\n");
		fclose(file);
		system("pause");
	}
}

int main(){ //Módulo Menu
	
	int opcao=0; //Definindo as varáveis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("\t### Cartorio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0){
	
		system("cls");
		for(laco=1;laco=1;) //Loop do programa
		{
	
			system("cls"); //Limpa a tela
	
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("\t### Cartório da EBAC ###\n\n"); //Início do menu
			printf("Escolha a opção desejada no menu: \n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: ");//Fim do menu
	
			scanf("%d", &opcao); //Armazenando a escolha do usuário
	
			system("cls"); //Limpa a tela
	
			switch(opcao){ //Chamada de funções
				case 1:
					registro();
					break;
				
				case 2:
					consulta();
					break;
				
				case 3:
					deletar();
					break;
				
				case 4:
					printf("Obrigado por utilizar o sistema!\n");
					return 0;
					break;
				
				default:
					printf("Essa opção não está disponível!\n");
					system("pause");
					break;//Fim da seleção
			}
		}
	}
	
	else
		printf("Senha incorreta!");
	
}
