#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings
int registro() //fun��o responsavel por cadastrar os us�rios no sistemas
{	
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); // o printf puxa das bibliotecas que est�o ativadas a cima as includes
	scanf("%s", cpf); //%s refere-se a strings 
	
	strcpy(arquivo, cpf);// respons�vel por copiar o valores das strings
	
	FILE *file; // cria o arquivo e o "w" significa escrever
	file = fopen(arquivo, "w"); // cria o arquivo na pasta tipo write
	fprintf(file,cpf); // aqui salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // para abrir o arquivo
	fprintf(file,","); // para separar o arquivo ficar melhor visivelmente
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); // scanf comando para salvar na string
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // para abrir o arquivo
	fprintf(file,","); // para separar o arquivo e ficar melhor visivelmente
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // para abrir o arquivo
	fprintf(file,","); // para separar o arquivo e ficar melhor visivelmente
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem, podendo usar acentua��o sem dar erro
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // codigo usado para ler R= ler em ingles
	
	if(file == NULL) // se o arquivo nao existir
	{	
		printf("N�o foi possivel abrir o arquivo, n�o foi localizado!");
	}

	while(fgets(conteudo, 200, file) != NULL) //
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
		system("pause");







}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); // responsavel por deletar o arquivo
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose (file);
	
	{
	printf("Usu�rio deletado com sucesso!\n");
	system("pause");
	}
	
	
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
	
}


int main ()
{   
	int opcao=0; //Definidor de variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls"); //responsavel por limnpar a tela
	    
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cart�rio Da EBAC ###\n\n"); //Inicio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes \n");
	    printf("\t2 - Consultar nomes \n");
	    printf("\t3 - Deletar nomes \n\n"); 
	    printf("\t4 - Sair do sistema \n\n");
	    
	    printf("Op��o: "); //fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuario
	
	    system("cls");
	    
	    
	    switch(opcao) // inicio da sele��o do menu
	    {
	    	case 1:
	    	registro(); // chamada de fun��es
		    break;
		    
		    case 2:
			consulta();
	        break;
	        
	        case 3:
			deletar();
		    break;
		    
		    case 4:
		    	printf("Obrigado por utilizar o sistema");
		    	return 0;
		    	break;
		    	
		    	
		    default:printf("Essa op��o n�o est� disponivel!\n");
		    system("pause");
		    break;
		
		
		
		} //fim da sela��o
	
	    
	
    }
}
	
