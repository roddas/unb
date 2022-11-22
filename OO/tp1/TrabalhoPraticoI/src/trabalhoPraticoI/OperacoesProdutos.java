package trabalhoPraticoI;
import java.util.ArrayList;

public class OperacoesProdutos 
{
	private ArrayList<Produto> listaProdutos;
	int quantidade;
	
	public OperacoesProdutos() 
	{
		this.listaProdutos = new ArrayList<Produto>();
		this.quantidade = 0;
	}
	public void cadastrarProduto(Produto novoProduto) 
	{
		this.addElemento(novoProduto);
	}
	public void addElemento(Produto novoProduto)
	{
		this.listaProdutos.add(novoProduto);
		++this.quantidade;
	}
	public Produto getElemento(int indice)
	{
		return this.listaProdutos.get(indice);
	}
	
	public void verTodosClientes() 
	{
		for(int a = 0; a < this.listaProdutos.size();a++)
		{
			Produto produto = this.listaProdutos.get(a);
			System.out.println((a+1)+" º Cliente");
			produto.getProduto();
			System.out.print("----------------------------------\n");
		}
	}
	public int getQuantidade() 
	{
		return this.quantidade;
	}
	public Produto [] todosProdutos() 
	{
		final int QUANTIDADE = this.getQuantidade();
		Produto produto[] = new Produto[QUANTIDADE];
		for(int a = 0; a < QUANTIDADE;a++) 
		{
			produto[a] = this.getElemento(a);
		}
		return produto;
	}
	public Produto pesquisarProduto(String nome) 
	{	
		final int QUANTIDADE = this.getQuantidade();
		for(int a = 0; a < QUANTIDADE;a++)
		{
			Produto produto = this.listaProdutos.get(a);
			if(nome.equalsIgnoreCase(produto.getNome()))
			{
				return produto;
			}
		}
		return null;
	}
}
