#include <stdio.h> //biblioteca de comunicação com o usuário.
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região.
#include <string.h> //biblioteca responsável por cuidar das string.

int registrar() //Função responsável por registrar os usuários.
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", &cpf);
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string.
	
	FILE *file; //Cria o arquivo.
	file = fopen(arquivo, "w"); //Cria o arquivo.
	fprintf(file, "CPF:");
	fprintf(file,cpf); //Salva o valor da variável.
	fclose(file); //Fecha o arquivo.
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nNome:");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s", &nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nSobrenome:");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s", &sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nCargo:");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s", &cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem.
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
		printf("\nEssas são as informações do usuário!\n");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
		printf("\n\n");
	}
		
		system("pause");
		
		
		
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL);
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
		
	}
}

int main()
{
	int opcao=0; //Definindo as variáveis.
	
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem.
	
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu.
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");	
		printf("Opção:"); //Fim do menu

		scanf("%d", &opcao); //Armazenando a escolha do usuário.
	
		system("cls");
		
		switch(opcao)
		{
			case 1: //Inicio da seleção.
			registrar();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível!\n\n"); //Fim da seleção.
			system("pause");
			break;
		}
	}	
}
	
