#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings
int registro() //função responsavel por cadastrar os usários no sistemas
{	
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // o printf puxa das bibliotecas que estão ativadas a cima as includes
	scanf("%s", cpf); //%s refere-se a strings 
	
	strcpy(arquivo, cpf);// responsável por copiar o valores das strings
	
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
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem, podendo usar acentuação sem dar erro
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // codigo usado para ler R= ler em ingles
	
	if(file == NULL) // se o arquivo nao existir
	{	
		printf("Não foi possivel abrir o arquivo, não foi localizado!");
	}

	while(fgets(conteudo, 200, file) != NULL) //
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
		system("pause");







}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); // responsavel por deletar o arquivo
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose (file);
	
	{
	printf("Usuário deletado com sucesso!\n");
	system("pause");
	}
	
	
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
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
	
	    printf("### Cartório Da EBAC ###\n\n"); //Inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes \n");
	    printf("\t2 - Consultar nomes \n");
	    printf("\t3 - Deletar nomes \n\n"); 
	    printf("\t4 - Sair do sistema \n\n");
	    
	    printf("Opção: "); //fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuario
	
	    system("cls");
	    
	    
	    switch(opcao) // inicio da seleção do menu
	    {
	    	case 1:
	    	registro(); // chamada de funções
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
		    	
		    	
		    default:printf("Essa opção não está disponivel!\n");
		    system("pause");
		    break;
		
		
		
		} //fim da selação
	
	    
	
    }
}
	
