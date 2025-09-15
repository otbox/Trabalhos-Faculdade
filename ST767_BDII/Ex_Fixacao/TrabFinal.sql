create DATABASE Marcenaria
GO
use Marcenaria 
GO

create table Pessoa (
    cpf VARCHAR(20) PRIMARY KEY,
    noem VARCHAR(100),
    endereco VARCHAR(100),
);

create table Cliente (
    cpf VARCHAR(20) PRIMARY KEY,
    telefone varchar(30),
    FOREIGN KEY (cpf) REFERENCES Pessoa(cpf)
);

create table Colaborador (
    cpf VARCHAR(20) PRIMARY KEY,
    codigo int,
    salario DECIMAL(10,2),
    FOREIGN KEY (cpf) REFERENCES Pessoa(cpf)
);
CREATE UNIQUE INDEX Uq_colaborador_cod on Colaborador(codigo)

create table Venda (
    codigo int PRIMARY KEY,
    cpf VARCHAR(20),
    data_venda datetime,
    metodo_pagamento VARCHAR(20),
    valor_total DECIMAL(15,2),
    FOREIGN KEY (cpf) REFERENCES Cliente(cpf)    
);
CREATE INDEX idx_cpf_venda_cliente on Venda(cpf);

create table Projeto (
    id int PRIMARY KEY,
    codigo_venda int,
    descricao VARCHAR(200),
    data_criacao DATETIME,
    valor DECIMAL(10,2),
    FOREIGN KEY (codigo_venda) REFERENCES Venda(codigo)  
);
create index idx_projeto_venda on Projeto(codigo_venda)

create table Item (
    codigo int PRIMARY KEY,
    nome VARCHAR(100),
    descricao VARCHAR(200),
    qnt_estoque int,
    preco_custo DECIMAL(10,2)
); 

create table Produto(
    codigo int PRIMARY KEY,
    codigo_barras int,
    preco DECIMAL(10,2),
    data_fabricacao date,
    FOREIGN KEY (codigo) REFERENCES Item(codigo)   
);
CREATE UNIQUE INDEX Uq_produto_codBar on Produto(codigo_barras)

create table VendaProduto (
    cod_venda int,
    cod_produto int,
    FOREIGN KEY (cod_venda) REFERENCES Venda(codigo),
    FOREIGN KEY (cod_produto) REFERENCES Produto(codigo)
);
create index idx_produto on VendaProduto(cod_venda)
create index idx_venda on VendaProduto(cod_produto)

create table MateriaPrima (
    codigo int PRIMARY KEY,
    tipo_material VARCHAR(50),
    FOREIGN KEY (codigo) REFERENCES Item(codigo)
);

create table ProdutoMateria (
    codigo_materia int,
    codigo_produto int,
    FOREIGN KEY (codigo_materia) REFERENCES MateriaPrima(codigo),
    FOREIGN KEY (codigo_produto) REFERENCES Produto(codigo)
);
create index idx_materia on ProdutoMateria(codigo_materia);
create index idx_produto on ProdutoMateria(codigo_produto);

create table ProjetoMateria(
    id_projeto int,
    codigo_materia int,
    quantidade int,
    FOREIGN KEY (id_projeto) REFERENCES Projeto(id),
    FOREIGN KEY (codigo_materia) REFERENCES MateriaPrima(codigo),
);


create table Fornecedor(
    cnpj VARCHAR(30) PRIMARY KEY,
    nome_fantasia VARCHAR(100),
    telefone VARCHAR(20),
    email varchar(100),
);

create table MateriaFornecedor(
    codigo_materia int,
    cnpj VARCHAR(30),
    FOREIGN KEY (codigo_materia) REFERENCES MateriaPrima(codigo),
    FOREIGN KEY (cnpj) REFERENCES Fornecedor(cnpj),
    preco DECIMAL(10,2),
);
create index idx_materia on MateriaFornecedor(codigo_materia);
create index idx_fornecedor on Fornecedor(cnpj);

create table OrdemPedido(
    numero_OP int PRIMARY KEY,
    cnpj VARCHAR(30),
    data_lancamento DATETIME,
    data_entrega DATE,
    valor_total DECIMAL(12,2),
    FOREIGN KEY (cnpj) REFERENCES Fornecedor(cnpj)
);

create table MateriaOrdem(
    numero_OP int,
    codigo_materia int,
    FOREIGN KEY (codigo_materia) REFERENCES MateriaPrima(codigo),
    FOREIGN KEY (numero_OP) REFERENCES OrdemPedido(numero_OP),
);
create index idx_materia on MateriaOrdem(codigo_materia);
create index idx_ordem on MateriaOrdem(numero_OP);

