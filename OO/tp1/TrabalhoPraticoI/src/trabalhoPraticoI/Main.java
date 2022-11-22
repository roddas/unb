package trabalhoPraticoI;
import java.util.Scanner;

public class Main 
{	
	public static void voltar(OperacoesCliente operacoesCliente,OperacoesProdutos operacoesProduto,Scanner s)
	{
		System.out.println("\nClique qualquer tecla para regressar ao menu principal");
		s.nextLine();
		limpaTela();
		menu(operacoesCliente,operacoesProduto);
	}
	public static void limpaTela() 
	{
		final int MAX = 50;
		for(int a = 0; a < MAX;a++) 
		{
			System.out.print("\n");
		}
	}
	public static void cargaInicial(OperacoesCliente operacoesCliente,OperacoesProdutos operacoesProduto) // Inserir automaticamente 10 clientes e produtos
	{
		operacoesCliente.cadastrarCliente(new Cliente("Rodolfo","(61)99333443","Gama"));
		operacoesCliente.cadastrarCliente(new Cliente("Cabral","(62)99333443","Gama"));
		operacoesCliente.cadastrarCliente(new Cliente("Neves","(61)93333443","Gama"));
		operacoesCliente.cadastrarCliente(new Cliente("Fabiana","(51)999333443","Finlândia"));
		operacoesCliente.cadastrarCliente(new Cliente("Fabrício","(61)9933343","DF"));
		operacoesCliente.cadastrarCliente(new Cliente("Pedro","(41)99333443","DF"));
		operacoesCliente.cadastrarCliente(new Cliente("João","(31)99333443","DF"));
		operacoesCliente.cadastrarCliente(new Cliente("Pedro","(61)93333443","DF"));
		operacoesCliente.cadastrarCliente(new Cliente("Victor","(21)999333443","DF"));
		operacoesCliente.cadastrarCliente(new Cliente("Helmer","(41)9933343","DF"));
		
		//(String nome,String descricao,double valor, double lucro,int estoque
		operacoesProduto.cadastrarProduto(new Produto("Arroz","Muito bom com feijão",22.3,4.3,5));
		operacoesProduto.cadastrarProduto(new Produto("Feijão","Muito bom com arroz",22.3,134.23,55));
		operacoesProduto.cadastrarProduto(new Produto("Café","Para o café",22.33,114.23,54));
		operacoesProduto.cadastrarProduto(new Produto("Pão","Para o café",242.3,142.344,53));
		operacoesProduto.cadastrarProduto(new Produto("Tapioca","Para o café",272.3,1114.333,52));
		operacoesProduto.cadastrarProduto(new Produto("Leite","Para o almoço",27672.3,148.38,15));
		operacoesProduto.cadastrarProduto(new Produto("Chá","Para o almoço",2282.38,148.3,15));
		operacoesProduto.cadastrarProduto(new Produto("Açaí","Para o almoço",22672.3,184.3,35));
		operacoesProduto.cadastrarProduto(new Produto("Mandioca","Muito bom com arroz",224.3,174.3,35));
		operacoesProduto.cadastrarProduto(new Produto("Beringela","Muito bom com arroz",255322.3,1466.53,55));
	}
	public static void main(String []args)
	{
		OperacoesCliente operacoesCliente = new OperacoesCliente();
		OperacoesProdutos operacoesProduto = new OperacoesProdutos();
		
		cargaInicial(operacoesCliente,operacoesProduto);
		menu(operacoesCliente,operacoesProduto);
	}
	public static void menu(OperacoesCliente operacoesCliente,OperacoesProdutos operacoesProduto) 
	{
		Scanner scan = new Scanner(System.in);
		System.out.print(""
				+ "1 - Inserir cliente\n"
				+ "2 - Pesquisar cliente\n"
				+ "3 - Inserir um produto\n"
				+ "4 - Pesquisar um produto\n"
				+ "5 - Cadastro de venda\n"
				+ "6 - Lista de produtos em estoque\n"
				+"Qualquer outro número para Sair\n"
				+ "\nSelecione o número desejado : ");
		
		int resposta = scan.nextInt();
		switch(resposta) 
		{
			case 1 : // Cadastrar um cliente
			{
				System.out.println("Quantos clientes dedeja cadastrar ?");
				int quantidade = scan.nextInt();
				scan.nextLine();
				
				for(int i = 0; i < quantidade;i++)
				{
					System.out.println("Cliente "+(i+1));
					System.out.print("Insira o nome : ");
					String nome = scan.nextLine();
					
					System.out.print("Insira o número de celular (xx)xxxxxxxxx : ");
					String celular = scan.nextLine();
					
					System.out.print("Insira o endereço de residência : ");
					String endereco = scan.nextLine();
					System.out.println("\n");
					
					operacoesCliente.cadastrarCliente(new Cliente(nome,celular,endereco));
				}
				voltar(operacoesCliente,operacoesProduto,scan);
				break;
			}
			case 2 : // Pesquisar um cliente
			{
				scan.nextLine();
				System.out.println("Insira o nome do cliente : ");
				String nome = scan.nextLine();
				
				Cliente resultado = operacoesCliente.pesquisarCliente(nome);
				if(resultado != null) 
				{
					resultado.getCliente();
					
					System.out.println("Deseja alterar ?\n1 - Sim e qualquer outro número para Não. : ");
					int r = scan.nextInt();
					switch(r) 
					{
						case 1 : 
						{
							
							scan.nextLine();
							System.out.print("Insira o novo nome : ");
							String novoNome = scan.nextLine();
							
							System.out.print("Insira o novo número de celular (xx)xxxxxxxxx : ");
							String novoCelular = scan.nextLine();
							
							System.out.print("Insira o novo endereço de residência : ");
							String novoEndereco = scan.nextLine();
							
							resultado.updateCliente(novoNome, novoEndereco, novoCelular);
							break;
						}
						default:
						{
							break;
						}
					}
				
				}else 
				{
					System.out.println("Cliente não encontrado!");
				}
				voltar(operacoesCliente,operacoesProduto,scan);
				break;
			}
			case 3 : // Inserir um produto
			{
				
				System.out.println("Quantos produtos deseja cadastrar ?");
				int quantidade = scan.nextInt();
				scan.nextLine();
				
				for(int i = 0; i < quantidade;i++)
				{
					System.out.println("Produto "+(i+1));
					System.out.print("Nome : ");
					String nome = scan.nextLine();
					
					System.out.print("Descrição : ");
					String descricao = scan.nextLine();
					
					System.out.print("Valor : ");
					double valor = scan.nextDouble();
					
					System.out.print("Lucro : ");
					double lucro = scan.nextDouble();

					System.out.print("Quantidade em estoque : ");
					int estoque = scan.nextInt();
					scan.nextLine();
					
					System.out.println("\n");
					operacoesProduto.cadastrarProduto(new Produto(nome,descricao,valor,lucro,estoque));
					
				}
				voltar(operacoesCliente,operacoesProduto,scan);
				break;
			}case 4 : // Pesquisar um produto
			{
				scan.nextLine();
				System.out.println("Insira o nome do produto : ");
				String nome = scan.nextLine();
				
				Produto resultado = operacoesProduto.pesquisarProduto(nome);
				if(resultado != null) 
				{
					resultado.getProduto();
					
					System.out.println("Deseja alterar ?\n1 - Sim e qualquer outro número para Não. : ");
					int r = scan.nextInt();
					switch(r) 
					{
						case 1 : 
						{
							scan.nextLine();
							System.out.print("Insira o novo nome : ");
							String novoNome = scan.nextLine();
							
							System.out.print("Descrição : ");
							String descricao = scan.nextLine();
							
							System.out.print("Valor : ");
							double valor = scan.nextDouble();
							
							System.out.print("Lucro : ");
							double lucro = scan.nextDouble();

							System.out.print("Quantidade em estoque : ");
							int estoque = scan.nextInt();
							
							resultado.updateProduto(novoNome, descricao, valor, lucro, estoque);
							break;
						}
						default:
						{
							break;
						}
					}
				
				}else 
				{
					System.out.println("Produto não encontrado!");
				}
				voltar(operacoesCliente,operacoesProduto,scan);
				break;
			}
			case 5 : //5. Cadastro de venda
			{
				Cliente listaClientes[] = operacoesCliente.todosClientes();
				Produto listaProduto[] = operacoesProduto.todosProdutos();
				
				while(true) 
				{
					limpaTela();
					for(int a = 0; a < operacoesCliente.quantidade;a++) 
					{
						System.out.println((a+1)+" - "+listaClientes[a].getNome());
					}
					
					System.out.print("Selecione cliente pelo o número: ");
					int numeroCliente = scan.nextInt();
					String nomeCliente = listaClientes[numeroCliente - 1].getNome();
					
					limpaTela();
					
					for(int a = 0; a < operacoesProduto.quantidade;a++) 
					{
						System.out.println((a+1)+" - "+listaProduto[a].getNome() + " possui "+listaProduto[a].getEstoque()+" em estoque");
					}
					System.out.print("Selecione produto pelo número: ");
					int idProduto = scan.nextInt();
					
					limpaTela();
					--idProduto;
					
					Produto produtoSelecionado = listaProduto[idProduto];
					
					System.out.print("Selecione a quantidade: ");
					int quantidadeProduto = scan.nextInt();
					
					if(quantidadeProduto > produtoSelecionado.getEstoque()) 
					{
						System.out.print(nomeCliente +", a quantidade ñ deve ser maior que o estoque.\n");
					}else
					{
						produtoSelecionado.setEstoque(produtoSelecionado.getEstoque() - quantidadeProduto);
						System.out.println(nomeCliente+" comprou "+quantidadeProduto+" unidades de "+produtoSelecionado.getNome());
					}
					System.out.println("Insira 1 para fazer mais uma compra e qualquer outro número para finalizar: ");
					if(scan.nextInt() != 1) 
					{
						break;
					}
				}
				voltar(operacoesCliente,operacoesProduto,scan);
				break;
			}
			case 6 : // Mostrar todos os produtos em estoque
			{
				scan.nextLine();
				System.out.println("Lista dos produtos cadastrados : ");
				Produto listaProduto[] = operacoesProduto.todosProdutos();
				
				System.out.println("---------------------");
				
				for(int a = 0; a < operacoesProduto.quantidade;a++) 
				{
					int estoque = listaProduto[a].getEstoque();
					if(estoque > 0)
					{
						System.out.println(listaProduto[a].getNome() + " - "+ estoque);
					}
				}
				System.out.println("---------------------");
				voltar(operacoesCliente,operacoesProduto,scan);
			}
			default:
			{
				
			}
		}
		scan.close();
	}
}