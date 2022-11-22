package trabalhoPraticoI;

public class Cliente 
{
	private String nome;
	private String celular;
	private String endereco;
	
	public Cliente(String nome,String celular,String endereco) 
	{
		this.nome = nome;
		this.celular = celular;
		this.endereco = endereco;
	}
	
	// Getters
	public String getNome() 
	{
		return this.nome;
	}
	public String getCelular() 
	{
		return this.celular;
	}
	public String getEndereco() 
	{
		return this.endereco;
	}
	// Setters
	public void setNome(String nome) 
	{
		this.nome = nome;
	}
	public void setCelular(String celular) 
	{
		this.celular = celular;
	}
	public void setEndereco(String endereco) 
	{
		this.endereco = endereco;
	}
	public void updateCliente(String nome,String endereco,String celular) 
	{
		this.setNome(nome);
		this.setEndereco(endereco);
		this.setCelular(celular);
	}
	public void getCliente() 
	{
		System.out.println("Nome : "+this.getNome());
		System.out.println("Contato telefónico : "+this.getCelular());
		System.out.println("Endereço de residência : "+this.getEndereco());
		System.out.println("-----------------------");
	}
}
