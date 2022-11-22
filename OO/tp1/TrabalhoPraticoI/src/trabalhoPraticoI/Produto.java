package trabalhoPraticoI;

public class Produto 
{
	private String nome;
	private String descricao;
	private double valor;
	private double lucro;
	private int estoque;
	
	public Produto(String nome,String descricao,double valor, double lucro,int estoque) 
	{
		this.nome = nome;
		this.descricao = descricao;
		this.valor = valor;
		this.lucro = lucro;
		this.estoque = estoque;
	}
	
	// Getters
	public String getNome() 
	{
		return this.nome;
	}
	public String getDescricao() 
	{
		return this.descricao;
	}
	public double getValor() 
	{
		return this.valor;
	}
	public double getLucro() 
	{
		return this.lucro;
	}
	public int getEstoque() 
	{
		return this.estoque;
	}
	// Setters
	public void setNome(String nome) 
	{
		this.nome = nome;
	}
	public void setDescricao(String descricao) 
	{
		this.descricao = descricao;
	}
	public void setValor(double valor) 
	{
		this.valor = valor;
	}
	public void setLucro(double lucro) 
	{
		this.lucro = lucro;
	}
	public void setEstoque(int estoque) 
	{
		this.estoque = estoque;
	}
	public void updateProduto(String nome,String descricao,double valor, double lucro,int estoque) 
	{
		this.setDescricao(descricao);
		this.setLucro(lucro);
		this.setNome(nome);
		this.setValor(valor);
	}
	public void getProduto() 
	{
		System.out.println("Nome : "+this.getNome());
		System.out.println("Descrição : "+this.getDescricao());
		System.out.println("Valor : "+this.getValor()+" $");
		System.out.println("Lucro de : "+this.getLucro()+" %");
		System.out.println(+this.getEstoque()+" produtos em estoque");
		System.out.println("-----------------------");
	}
}
