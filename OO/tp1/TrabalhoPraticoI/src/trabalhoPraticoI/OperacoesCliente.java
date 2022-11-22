package trabalhoPraticoI;
import java.util.ArrayList;

public class OperacoesCliente
{
	private ArrayList<Cliente> listaClientes;
	int quantidade;
	
	public OperacoesCliente() 
	{
		this.listaClientes = new ArrayList<Cliente>();
		this.quantidade = 0;
	}
	public int getQuantidade() 
	{
		return this.quantidade; 
	}
	public void cadastrarCliente(Cliente c) 
	{
		this.addElemento(c);
		++this.quantidade;
	}
	public void addElemento(Cliente c)
	{
		this.listaClientes.add(c);
	}
	public Cliente getElemento(int indice)
	{
		return this.listaClientes.get(indice);
	}
	
	public void verTodosClientes() 
	{
		for(int a = 0; a < this.getQuantidade();a++)
		{
			Cliente cliente = this.listaClientes.get(a);
			System.out.println((a+1)+" º Cliente");
			cliente.getCliente();
			System.out.print("----------------------------------\n");
		}
	}
	public Cliente pesquisarCliente(String nome) 
	{
		final int QUANTIDADE = this.getQuantidade();
		for(int a = 0; a < QUANTIDADE;a++)
		{
			Cliente cliente = this.listaClientes.get(a);
			if(nome.equalsIgnoreCase(cliente.getNome()))
			{
				return cliente;
			}
		}
		return null;
	}
	public Cliente[] todosClientes() 
	{
		final int QUANTIDADE = this.getQuantidade();
		Cliente [] array = new Cliente[QUANTIDADE];
		for(int a = 0; a < QUANTIDADE;a++)
		{
			array[a] = this.listaClientes.get(a);
		}
		return array;
	}
}
