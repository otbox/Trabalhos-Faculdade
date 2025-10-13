As regras de uso de um banheiro permitem que, quando uma mulher estiver no banheiro, outra mulher
poderá entrar, mas um homem não e vice-versa. Implemente uma solução computacional para esse problema,
supondo vários processos (homens e mulheres) e usando semáforos através das funções
void mulher_quer_entrar(int idM) e void homem_quer_entrar(int idH). Suponha que
as seguintes funções já estão implementadas:
- h_entra(int idH): função que mapeia a entrada de um homem no banheiro.
- m_entra(int idM): função que mapeia a entrada de uma mulher no banheiro.
- h_sai(int idH): função que mapeia a saída de um homem no banheiro.
- m_sai(int idM): função que mapeia a saída de uma mulher do banheiro.