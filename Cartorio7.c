#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio de cria��o de vari�veis /string
	char arquivo[100];
	char cpf[100];
	char nome[100];
	char sobrenome[100];
	char cargo[100];
	
	printf("Digite o CPF para cadastro: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o aqruivo
	file = fopen(arquivo, "w"); //cria o arquivo (escrever)
	fprintf(file,cpf); //salvar o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrir arquivo e atualizar
	fprintf(file, ","); //salvar dentro do arquivo a virgula
	fclose(file);
	
	printf("Digite o nome para cadastro: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //atualizar o arquivo com nome
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizar o arquivo
	fprintf(file, ","); //atualizar o arquivo com virgulas
	fclose(file);
	
	printf("Digite o sobrenome para cadastro: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //atualizar o arquivo
	fprintf(file, sobrenome); //atualizar o arquivo com sobrenome
	fclose(file);

	file = fopen(arquivo, "a"); //atualizar o arquivo
	fprintf(file, ","); //atualizar o arquivo com virgulas
	fclose(file);
	
	printf("Digite o cargo para cadastro: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //atualizar o arquivo
	fprintf(file, cargo); //atualizar o arquivo com cargo
	fclose(file);
	
	system("pause");
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a lingaguem
	
	char cpf[100];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abrir e ler o arquivo
	
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquvivo, n�o localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}

int deletar()
{
	char cpf[100];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //mensagem na tela do usu�rio
	scanf("%s", cpf);
	
	 //remover o arquivo cpf
	
	FILE *file; //campo da biblioteca FILE e depois o arquivo
	file = fopen(cpf,"r"); //abrir e ler o arquivo cpf
	fclose(file);
	
	if(file == NULL) //se o arquivo for nulo
	{
		printf("O usu�rio n�o econtrado no sistema!\n");
		system("pause");
	}
	if (remove(cpf) == 0)
	{
		printf("O usu�rio foi deletado com sucesso!\n");
		system("pause");
	}
	
		
	
			
		
	


}
	
	



int main()
	{	
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;) //inicio do la�o
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a lingaguem
	
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o deseja no menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls");
	
	
	
			switch(opcao) //inicio das op��es
			{
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
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
			} //fim das op��es
	
	
	} //fim do la�o
} // fim do programa
