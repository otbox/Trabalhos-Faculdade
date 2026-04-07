CREATE TABLE Pessoa (
  cpf CHAR(11) NOT NULL,
  nome VARCHAR(100) NOT NULL,
  endereco VARCHAR(100) NOT NULL,
  telefone VARCHAR(20) NOT NULL,
  PRIMARY KEY (cpf)
);

CREATE TABLE Cliente (
  cpf CHAR(11) NOT NULL,
  PRIMARY KEY (cpf),
  FOREIGN KEY (cpf) REFERENCES Pessoa(cpf) ON DELETE CASCADE
);

CREATE TABLE Colaborador (
  cpf CHAR(11) NOT NULL,
  codigo_colaborador INTEGER NOT NULL,
  salario DECIMAL(10,2),
  PRIMARY KEY (cpf),
  UNIQUE (codigo_colaborador),
  FOREIGN KEY (cpf) REFERENCES Pessoa(cpf) ON DELETE CASCADE
);

CREATE TABLE Venda (
  codigo_venda INTEGER NOT NULL,
  cpf_cliente VARCHAR(11) NOT NULL,
  data_venda DATETIME NOT NULL,
  metodo_pagamento VARCHAR(20) NOT NULL,
  valor_total DECIMAL(15,2) NOT NULL,
  PRIMARY KEY (codigo_venda),
  FOREIGN KEY (cpf_cliente) REFERENCES Cliente(cpf)
);
CREATE INDEX idx_cpf_venda_cliente ON Venda(cpf_cliente);

CREATE TABLE VendaColaborador (
  codigo_venda INTEGER NOT NULL,
  codigo_colaborador INTEGER NOT NULL,
  duracao TIME NOT NULL,
  PRIMARY KEY (codigo_venda, codigo_colaborador),
  FOREIGN KEY (codigo_venda) REFERENCES Venda(codigo_venda),
  FOREIGN KEY (codigo_colaborador) REFERENCES Colaborador(codigo_colaborador)
);
-- Corrigido só o segundo é necessaŕio 
CREATE INDEX idx_vendacolaborador_colaborador ON VendaColaborador(codigo_colaborador);

CREATE TABLE Projeto (
  id_projeto INTEGER NOT NULL,
  codigo_venda INTEGER NOT NULL,
  descricao VARCHAR(200),
  data DATETIME NOT NULL,
  valor DECIMAL(10,2) NOT NULL,
  PRIMARY KEY (id_projeto),
  FOREIGN KEY (codigo_venda) REFERENCES Venda(codigo_venda)
);
CREATE INDEX idx_projeto_venda ON Projeto(codigo_venda);

CREATE TABLE Item (
  codigo_item INTEGER NOT NULL,
  nome VARCHAR(100) NOT NULL,
  descricao VARCHAR(200),
  qnt_estoque INTEGER,
  preco_custo DECIMAL(10,2),
  tipo TINYINT NOT NULL CHECK (tipo IN (1,2)),
  PRIMARY KEY (codigo_item)
);
-- Verificar novamente esse tipo

CREATE TABLE ItemProjeto (
  id_projeto INTEGER NOT NULL,
  codigo_item INTEGER NOT NULL,
  quantidade_item INTEGER NOT NULL,
  PRIMARY KEY (id_projeto, codigo_item),
  FOREIGN KEY (id_projeto) REFERENCES Projeto(id_projeto),
  FOREIGN KEY (codigo_item) REFERENCES Item(codigo_item)
);
-- Corrigido index
CREATE INDEX idx_materia_prima_projeto_materia_prima ON ItemProjeto(codigo_item);

CREATE TABLE Produto (
  codigo_item INTEGER NOT NULL,
  codigo_barras VARCHAR(20) NOT NULL,
  preco DECIMAL(10,2),
  data_fabricacao DATETIME,
  PRIMARY KEY (codigo_item),
  UNIQUE (codigo_barras),
  FOREIGN KEY (codigo_item) REFERENCES Item(codigo_item)
);
-- Corrigido remover index denessario produto
-- CREATE INDEX idx_produto_item ON Produto(codigo_item);

CREATE TABLE VendaProduto (
  codigo_venda INTEGER NOT NULL,
  codigo_item INTEGER NOT NULL,
  quantidade INTEGER NOT NULL,
  PRIMARY KEY(codigo_venda, codigo_item),
  FOREIGN KEY (codigo_venda) REFERENCES Venda(codigo_venda),
  FOREIGN KEY (codigo_item) REFERENCES Produto(codigo_item)
);
-- Corrigido falta de PK composta e index errado
-- CREATE INDEX idx_venda_produto_venda ON VendaProduto(codigo_venda);
CREATE INDEX idx_venda_produto_item ON VendaProduto(codigo_item);

CREATE TABLE Fornecedor (
  cnpj VARCHAR(14) NOT NULL,
  nome_fantasia VARCHAR(100) NOT NULL,
  telefone VARCHAR(11),
  email VARCHAR(100) NOT NULL,
  PRIMARY KEY (cnpj)
);
-- Certo até aqui
CREATE TABLE MateriaPrima (
  codigo_item INTEGER NOT NULL,
  tipo_material VARCHAR(50),
  cnpj_fornecedor VARCHAR(14),
  PRIMARY KEY (codigo_item),
  FOREIGN KEY (codigo_item) REFERENCES Item(codigo_item),
  FOREIGN KEY (cnpj_fornecedor) REFERENCES Fornecedor(cnpj)
);
CREATE INDEX idx_materia_prima_fornecedor ON MateriaPrima(cnpj_fornecedor);

CREATE TABLE MateriaFornecedor (
  codigo_item INTEGER NOT NULL,
  cnpj VARCHAR(30) NOT NULL,
  preco DECIMAL(10,2) NOT NULL,
  PRIMARY KEY(codigo_item, cnpj),
  FOREIGN KEY (codigo_item) REFERENCES MateriaPrima(codigo_item),
  FOREIGN KEY (cnpj) REFERENCES Fornecedor(cnpj)
);
-- Corrigido aqui
-- CREATE INDEX idx_materia ON MateriaFornecedor(codigo_item); removido
CREATE INDEX idx_fornecedor ON MateriaFornecedor(cnpj);

CREATE TABLE OrdemPedido (
  numero_ordem_pedido INTEGER NOT NULL,
  cnpj VARCHAR(30) NOT NULL,
  data DATETIME NOT NULL,
  data_entrega DATETIME NOT NULL,
  data_prevista DATETIME NOT NULL,
  valor_total DECIMAL(12,2) NOT NULL,
  PRIMARY KEY (numero_ordem_pedido),
  FOREIGN KEY (cnpj) REFERENCES Fornecedor(cnpj)
);
CREATE INDEX idx_ordem_pedido ON OrdemPedido(cnpj);

CREATE TABLE MateriaOrdem (
  numero_ordem_pedido INTEGER NOT NULL,
  codigo_item INTEGER NOT NULL,
  quantidade INTEGER NOT NULL,
  PRIMARY KEY (numero_ordem_pedido, codigo_item),
  FOREIGN KEY (codigo_item) REFERENCES MateriaPrima(codigo_item),
  FOREIGN KEY (numero_ordem_pedido) REFERENCES OrdemPedido(numero_ordem_pedido)
);
-- Apenas o segundo deve ter um index não clusterizadoz
CREATE INDEX idx_codigo_materia_ordem ON MateriaOrdem(codigo_item);

CREATE TABLE ProdutoMateria (
  codigo_materia INTEGER NOT NULL,
  codigo_produto INTEGER NOT NULL,
  quantidade_mat_prima INTEGER NOT NULL,
  PRIMARY KEY(codigo_materia, codigo_produto),
  FOREIGN KEY (codigo_materia) REFERENCES MateriaPrima(codigo_item),
  FOREIGN KEY (codigo_produto) REFERENCES Produto(codigo_item)
);
-- CREATE INDEX idx_materia ON ProdutoMateria(codigo_materia); Removido
CREATE INDEX idx_produto ON ProdutoMateria(codigo_produto);

------------------------------------------------------------
--                     VIEWS
------------------------------------------------------------

-- View: Projetos personalizados dos clientes
GO
CREATE VIEW projetos_personalizados_clientes AS
SELECT
    p.cpf,
    p.nome,
    v.codigo_venda,
    v.data_venda,
    v.metodo_pagamento,
    pj.id_projeto AS codigo_projeto,
    pj.descricao AS descricao_projeto,
    pj.valor AS valor_projeto
FROM Pessoa AS p
INNER JOIN Cliente AS c ON c.cpf = p.cpf
INNER JOIN Venda AS v ON v.cpf_cliente = c.cpf
INNER JOIN Projeto AS pj ON pj.codigo_venda = v.codigo_venda;
GO

-- View: Desempenho das entregas por fornecedor
CREATE VIEW view_desempenhos_entregas_por_fornecedor AS
SELECT
    f.cnpj,
    f.nome_fantasia,
    COUNT(op.numero_ordem_pedido) AS total_pedidos,
    SUM(CASE WHEN op.data_entrega > op.data_prevista THEN 1 ELSE 0 END) AS pedidos_atrasados,
    SUM(CASE WHEN op.data_entrega < op.data_prevista THEN 1 ELSE 0 END) AS pedidos_adiantados,
    SUM(CASE WHEN op.data_entrega = op.data_prevista THEN 1 ELSE 0 END) AS pedidos_no_prazo
FROM Fornecedor AS f
INNER JOIN OrdemPedido AS op ON op.cnpj = f.cnpj
GROUP BY f.cnpj, f.nome_fantasia;
GO

-- View: Produtos e projetos de venda
CREATE VIEW vw_projetos_produtos_venda AS
SELECT
    v.codigo_venda,
    v.data_venda,
    v.metodo_pagamento,
    v.valor_total AS valor_venda,
    c.cpf AS cpf_cliente,
    p.nome AS nome_cliente,
    pr.id_projeto,
    pr.descricao AS descricao_projeto,
    pr.data AS data_projeto,
    pr.valor AS valor_projeto,
    prod.codigo_item AS codigo_produto,
    i.nome AS nome_produto,
    i.descricao AS descricao_produto,
    prod.codigo_barras,
    prod.preco AS preco_produto
FROM venda v
JOIN cliente c ON v.cpf_cliente = c.cpf
JOIN pessoa p ON c.cpf = p.cpf
LEFT JOIN projeto pr ON v.codigo_venda = pr.codigo_venda
LEFT JOIN VendaProduto vp ON v.codigo_venda = vp.codigo_venda
LEFT JOIN produto prod ON vp.codigo_item = prod.codigo_item
LEFT JOIN item i ON prod.codigo_item = i.codigo_item;
GO

-- View: Vendas com informações do cliente
CREATE VIEW view_vendas_cliente_e_funcionario AS
SELECT 
    v.cpf_cliente,
    v.data_venda,
    v.metodo_pagamento,
    v.valor_total,
    p.nome,
    p.endereco
FROM Venda v
JOIN Cliente c ON v.cpf_cliente = c.cpf
JOIN Pessoa p ON v.cpf_cliente = p.cpf;
GO

-- View: Quantidade de vendas por produto
CREATE VIEW VwQntProdutoVendido AS
SELECT
    Produto.codigo,
    Item.nome AS NomeProduto,
    Produto.preco,
    Item.preco_custo,
    COUNT(*) AS QntVendido
FROM VendaProduto
INNER JOIN Produto ON Produto.codigo = VendaProduto.cod_produto
INNER JOIN Item ON Item.codigo = Produto.codigo
GROUP BY Produto.codigo, Item.nome, Produto.preco, Item.preco_custo;
GO


------------------------------------------------------------
--                   PROCEDURES
------------------------------------------------------------

-- Procedure: Inserir colaborador
CREATE PROCEDURE inserir_colaborador
    @nome VARCHAR(100),
    @cpf CHAR(11),
    @endereco VARCHAR(100),
    @codigo_colaborador INTEGER,
    @salario DECIMAL(10, 2)
AS
BEGIN
    BEGIN TRY
        BEGIN TRANSACTION;

        INSERT INTO Pessoa (cpf, nome, endereco)
        VALUES (@cpf, @nome, @endereco);

        INSERT INTO Colaborador (codigo_colaborador, cpf, salario)
        VALUES (@codigo_colaborador, @cpf, @salario);

        COMMIT TRANSACTION;
    END TRY
    BEGIN CATCH
        ROLLBACK TRANSACTION;
        DECLARE @ErroMsg NVARCHAR(4000) = ERROR_MESSAGE();
        DECLARE @ErroNum INT = ERROR_NUMBER();
        RAISERROR('Erro ao inserir colaborador (%d): %s', 16, 1, @ErroNum, @ErroMsg);
    END CATCH
END;
GO

-- Procedure: Inserir produto
CREATE PROCEDURE insere_produto
    @nome VARCHAR(100),
    @descricao VARCHAR(200),
    @qnt_estoque INT,
    @preco_custo DECIMAL(10,2),
    @tipo TINYINT,
    @codigo_barras VARCHAR(20),
    @preco DECIMAL(10,2),
    @data_fabricacao DATETIME
AS
BEGIN
    BEGIN TRANSACTION;

    INSERT INTO Item (nome, descricao, qnt_estoque, preco_custo, tipo)
    VALUES (@nome, @descricao, @qnt_estoque, @preco_custo, @tipo);

    IF @@ROWCOUNT > 0
    BEGIN
        DECLARE @novo_codigo_item INT;
        SET @novo_codigo_item = SCOPE_IDENTITY();

        INSERT INTO Produto (codigo_item, codigo_barras, preco, data_fabricacao)
        VALUES (@novo_codigo_item, @codigo_barras, @preco, @data_fabricacao);

        IF @@ROWCOUNT > 0
            COMMIT TRANSACTION;
        ELSE
            ROLLBACK TRANSACTION;
    END
    ELSE
        ROLLBACK TRANSACTION;
END;
GO

-- Procedure: Inserir cliente
CREATE PROCEDURE inserir_cliente
    @cpf CHAR(11),
    @nome VARCHAR(100),
    @endereco VARCHAR(100)
AS
BEGIN
    BEGIN TRANSACTION;

    INSERT INTO Pessoa (cpf, nome, endereco)
    VALUES (@cpf, @nome, @endereco);

    IF @@ROWCOUNT > 0
    BEGIN
        INSERT INTO Cliente (cpf)
        VALUES (@cpf);

        IF @@ROWCOUNT > 0
            COMMIT TRANSACTION;
        ELSE
            ROLLBACK TRANSACTION;
    END
    ELSE
        ROLLBACK TRANSACTION;
END;
GO

-- Procedure: Inserir matéria-prima
CREATE PROCEDURE insere_materia_prima
    @codigo INT,
    @nome VARCHAR(100),
    @descricao VARCHAR(200),
    @qnt_estoque INT,
    @preco_custo DECIMAL(10,2),
    @tipo_material VARCHAR(50)
AS
BEGIN
    BEGIN TRANSACTION;

    INSERT INTO Item (codigo, nome, descricao, qnt_estoque, preco_custo)
    VALUES (@codigo, @nome, @descricao, @qnt_estoque, @preco_custo);

    IF @@ROWCOUNT > 0
    BEGIN
        INSERT INTO MateriaPrima (codigo, tipo_material)
        VALUES (@codigo, @tipo_material);

        IF @@ROWCOUNT > 0
            COMMIT TRANSACTION;
        ELSE
            ROLLBACK TRANSACTION;
    END
    ELSE
        ROLLBACK TRANSACTION;
END;
GO


------------------------------------------------------------
--                    TRIGGERS
------------------------------------------------------------

-- Trigger: Diminuir matéria-prima em estoque conforme uso
CREATE TRIGGER trigger_diminui_mp_produto
ON ProdutoMateria
AFTER INSERT
AS
BEGIN
    SET NOCOUNT ON;

    UPDATE mp
    SET mp.quantidade_em_estoque = mp.quantidade_em_estoque - i.quantidade_mat_prima
    FROM MateriaPrima mp
    INNER JOIN inserted AS i ON mp.codigo_item = i.codigo_materia;
    if @@ROWCOUNT = 0
      ROLLBACK TRANSACTION; 
END;
GO

-- Trigger: Aumentar matéria-prima conforme chegada
CREATE TRIGGER trigger_aumenta_mp_produto
ON MateriaOrdem
AFTER INSERT
AS
BEGIN
    SET NOCOUNT ON;

    UPDATE it
    SET it.qnt_estoque = it.qnt_estoque + i.quantidade
    FROM Item it
    INNER JOIN MateriaPrima mp ON mp.codigo = it.codigo
    INNER JOIN inserted i ON i.codigo_item = mp.codigo;
    if @@ROWCOUNT = 0
      ROLLBACK TRANSACTION; 
END;
GO

-- Trigger: Atualizar valor total da venda conforme produto adicionado
CREATE TRIGGER trigger_valor_total_venda
ON Produto
FOR INSERT
AS
BEGIN
    UPDATE v
    SET v.valor_total = (
        SELECT SUM(p.preco * vp.quantidade)
        FROM VendaProduto vp
        INNER JOIN Produto p ON vp.codigo_item = p.codigo_item
        WHERE vp.codigo_venda = v.codigo_venda
    )
    FROM Venda v
    INNER JOIN inserted i ON v.codigo_venda = i.codigo_venda;
    if @@ROWCOUNT = 0
      ROLLBACK TRANSACTION 
END;
GO

-- Trigger: Atualizar preço de custo conforme preço do fornecedor muda
CREATE TRIGGER atualiza_preco_de_custo_item
ON MateriaFornecedor
AFTER UPDATE
AS
BEGIN
    SET NOCOUNT ON;

    UPDATE i
    SET i.preco_custo = ins.preco
    FROM Item i
    INNER JOIN inserted ins ON i.codigo_item = ins.codigo_item;
    if @@ROWCOUNT = 0
      ROLLBACK TRANSACTION; 
END;
GO

-- Trigger: Atualizar valor da venda conforme projeto inserido
CREATE TRIGGER trigger_atualizar_valor_venda_projeto_ao_inserir 
ON Projeto
AFTER INSERT
AS
BEGIN
    SET NOCOUNT ON;

    UPDATE Venda
    SET valor_total = valor_total + i.valor
    FROM Venda
    INNER JOIN inserted i ON Venda.codigo = i.codigo_venda;
    if @@ROWCOUNT = 0
      ROLLBACK TRANSACTION; 
END;
GO

-- Trigger: Atualizar valor da venda conforme projeto atualizado
CREATE TRIGGER trigger_atualizar_valor_venda_projeto_ao_atualizar
ON Projeto
AFTER UPDATE
AS
BEGIN
    SET NOCOUNT ON;

    UPDATE v
    SET v.valor_total = v.valor_total - d.valor + i.valor
    FROM Venda v
    INNER JOIN deleted d ON v.codigo = d.codigo_venda
    INNER JOIN inserted i ON v.codigo = i.codigo_venda;
    if @@ROWCOUNT = 0
      ROLLBACK TRANSACTION; 
END;
GO

--Triggers a fazer:
-- Venda diminuir quantidade de produto (subtrair e update)
-- 
-- Projeto diminuir quantidade de materia prima (subtrair e update)
-- Produto diminuir quantidade de materia prima (subtrair e update)
-- Valor de Venda e Projeto modificar valor total (adição e update)
-- Feito Adicionar projeto modificar valor
-- Feito Adicionar produto modificar valor 
-- Feito Atualizar preco de custo pelo preço fornecedor 
-- Feito Atualizar preco do venda com preço projeto
-- Fata Atualizar preco de venda com preço do produto (update) 
-- Falta Update  projeto
-- Falta Update de materia-prima 
-- Falta Update de gasto de materia-prima para produto 
-- Preco custo da materia prima * quantidade usada ser o preço do produto (update)
-- Ordem de pedido alter quantidade de materia prima (create, update, delete )
-- Não sei a viabilidade
-- Verificar se a ordem de pedido foi atualizado a data entrega dessa forma adicionar a quantidade dos itens
-- 