#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsavel por cadastrar os usuários no sistema
{
	//inicio de criação de variáveis /string
	char arquivo[100];
	char cpf[100];
	char nome[100];
	char sobrenome[100];
	char cargo[100];
	
	printf("Digite o CPF para cadastro: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o aqruivo
	file = fopen(arquivo, "w"); //cria o arquivo (escrever)
	fprintf(file,cpf); //salvar o valor da variável
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
		printf("Não foi possível abrir o arquvivo, não localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}

int deletar()
{
	char cpf[100];
	
	printf("Digite o CPF do usuário a ser deletado: "); //mensagem na tela do usuário
	scanf("%s", cpf);
	
	 //remover o arquivo cpf
	
	FILE *file; //campo da biblioteca FILE e depois o arquivo
	file = fopen(cpf,"r"); //abrir e ler o arquivo cpf
	fclose(file);
	
	if(file == NULL) //se o arquivo for nulo
	{
		printf("O usuário não econtrado no sistema!\n");
		system("pause");
	}
	if (remove(cpf) == 0)
	{
		printf("O usuário foi deletado com sucesso!\n");
		system("pause");
	}
	
		
	
			
		
	


}
	
	



int main()
	{	
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;) //inicio do laço
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a lingaguem
	
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção deseja no menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls");
	
	
	
			switch(opcao) //inicio das opções
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
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
			} //fim das opções
	
	
	} //fim do laço
} // fim do programa
