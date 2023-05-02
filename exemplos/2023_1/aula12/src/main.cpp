// aula 13: programacao defensiva

// assercoes: nao lancam erros; include cassert, a chamada nao faz nada, mas sai do codigo caso o booleano seja falso
// ninguem deve chamar x metodo passando uma entrada invalida: o assert garante que essas entradas sao filtradas;
// nao involve o usuario; de program pra program; indinca erros em tempo de execucao, tipo chamar uma funcao
// que receberia int com uma string -> da errado, o assert falha (exemplo muito simples mas serve pra casos gerais)
// fail fast programming
// nao é uma excessao;

// barricadas: breakpoints

// valgrind: ferramenta, procura memory leaks e diz que eles existem e de que jeito; alocou no heap e nao apagou,
// todo new deve ter um delete

#include <exception>
#include <iostream>s

#include "sistema.h"

int main()
{
  Sistema sistema_uber = Sistema();

  Carro c1 = Carro("branco");
  Carro c2 = Carro("verde");

  std::string login;
  std::cout << "Digite um login: " << std::endl;
  std::cin >> login;
  while (login != "sair")
  {
    try
    {
      Cliente *cliente =
          sistema_uber.cadastra_cliente(login);
      cliente->adicionar_saldo(20);
      std::cout << "Cliente cadastrado: " << cliente->get_nome() << std::endl;
    }
    catch (cliente_ja_existe_e &e)
    {
      std::cout << "Cliente não cadastrado, já existe. Escolha outro login." << std::endl;
    }
    std::cout << "Digite um login: " << std::endl;
    std::cin >> login;
  }

  try
  {
    sistema_uber.busca_uber("flavio,,@d");
  }
  catch (cliente_ja_existe_e &e)
  {
  }
  catch (cliente_nao_existe_e &e)
  {
  }
  catch (sem_saldo_e &e)
  {
  }
  catch (zero_carros_disponiveis_e &e)
  {
  }
  sistema_uber.adicionar_carro(&c1);
  sistema_uber.adicionar_carro(&c2);
}