create database marcenaria3
GO
use marcenaria3
go
-- ============================================
-- CRIAÇÃO DAS TABELAS
-- ============================================

-- Tabela: Pessoa
CREATE TABLE Pessoa (
    cpf CHAR(11) NOT NULL,
    nome VARCHAR(100) NOT NULL,
    endereco VARCHAR(100) NOT NULL,
    telefone VARCHAR(20) NOT NULL,
    PRIMARY KEY(cpf)
);

-- Tabela: Cliente
CREATE TABLE Cliente (
    cpf CHAR(11) NOT NULL,
    PRIMARY KEY(cpf),
    FOREIGN KEY (cpf) REFERENCES Pessoa(cpf) ON DELETE CASCADE
);

-- Tabela: Colaborador
CREATE TABLE Colaborador (
    cpf CHAR(11) NOT NULL,
    codigo_colaborador INTEGER NOT NULL,
    salario DECIMAL(10,2),
    PRIMARY KEY(cpf),
    UNIQUE(codigo_colaborador),
    FOREIGN KEY (cpf) REFERENCES Pessoa(cpf) ON DELETE CASCADE
);

-- Tabela: Venda
CREATE TABLE Venda (
    codigo_venda INTEGER NOT NULL,
    cpf_cliente VARCHAR(11) NOT NULL,
    data_venda DATETIME NOT NULL,
    metodo_pagamento VARCHAR(20) NOT NULL,
    valor_total DECIMAL(15,2) NOT NULL,
    PRIMARY KEY(codigo_venda),
    FOREIGN KEY (cpf_cliente) REFERENCES Cliente(cpf)
);

CREATE INDEX idx_cpf_venda_cliente ON Venda(cpf_cliente);

-- Tabela: VendaColaborador
CREATE TABLE VendaColaborador (
    codigo_venda INTEGER NOT NULL,
    codigo_colaborador INTEGER NOT NULL,
    duracao TIME NOT NULL,
    PRIMARY KEY (codigo_venda, codigo_colaborador),
    FOREIGN KEY (codigo_venda) REFERENCES Venda(codigo_venda),
    FOREIGN KEY (codigo_colaborador) REFERENCES Colaborador(codigo_colaborador)
);

CREATE INDEX idx_vendacolaborador_colaborador ON VendaColaborador(codigo_colaborador);

-- Tabela: Projeto
CREATE TABLE Projeto (
    id_projeto INTEGER NOT NULL,
    codigo_venda INTEGER NOT NULL,
    descricao VARCHAR(200),
    data DATETIME NOT NULL,
    valor DECIMAL(10,2) NOT NULL,
    PRIMARY KEY(id_projeto),
    FOREIGN KEY (codigo_venda) REFERENCES Venda(codigo_venda)
);

CREATE INDEX idx_projeto_venda ON Projeto(codigo_venda);

-- Tabela: Item
CREATE TABLE Item (
    codigo_item INTEGER NOT NULL,
    nome VARCHAR(100) NOT NULL,
    descricao VARCHAR(200),
    qnt_estoque INTEGER,
    preco_custo DECIMAL(10,2),
    tipo TINYINT NOT NULL CHECK(tipo IN(1,2)),
    PRIMARY KEY(codigo_item)
);

-- Tabela: ItemProjeto
CREATE TABLE ItemProjeto (
    id_projeto INTEGER NOT NULL,
    codigo_item INTEGER NOT NULL,
    quantidade_item INTEGER NOT NULL,
    PRIMARY KEY (id_projeto, codigo_item),
    FOREIGN KEY (id_projeto) REFERENCES Projeto(id_projeto),
    FOREIGN KEY (codigo_item) REFERENCES Item(codigo_item)
);

CREATE INDEX idx_materia_prima_projeto_materia_prima ON ItemProjeto(codigo_item);

-- Tabela: Produto
CREATE TABLE Produto (
    codigo_item INTEGER NOT NULL,
    codigo_barras VARCHAR(20) NOT NULL,
    preco DECIMAL(10,2),
    data_fabricacao DATETIME,
    PRIMARY KEY (codigo_item),
    UNIQUE (codigo_barras),
    FOREIGN KEY (codigo_item) REFERENCES Item(codigo_item)
);

-- Tabela: VendaProduto
CREATE TABLE VendaProduto (
    codigo_venda INTEGER NOT NULL,
    codigo_item INTEGER NOT NULL,
    quantidade INTEGER NOT NULL,
    PRIMARY KEY(codigo_venda, codigo_item),
    FOREIGN KEY (codigo_venda) REFERENCES Venda(codigo_venda),
    FOREIGN KEY (codigo_item) REFERENCES Produto(codigo_item)
);

CREATE INDEX idx_venda_produto_item ON VendaProduto(codigo_item);

-- Tabela: Fornecedor
CREATE TABLE Fornecedor (
    cnpj VARCHAR(14) NOT NULL,
    nome_fantasia VARCHAR(100) NOT NULL,
    telefone VARCHAR(11),
    email VARCHAR(100) NOT NULL,
    PRIMARY KEY(cnpj)
);

-- Tabela: MateriaPrima
CREATE TABLE MateriaPrima (
    codigo_item INTEGER NOT NULL,
    tipo_material VARCHAR(50),
    cnpj_fornecedor VARCHAR(14),
    PRIMARY KEY(codigo_item),
    FOREIGN KEY (codigo_item) REFERENCES Item(codigo_item),
    FOREIGN KEY (cnpj_fornecedor) REFERENCES Fornecedor(cnpj)
);

CREATE INDEX idx_materia_prima_fornecedor ON MateriaPrima(cnpj_fornecedor);

-- Tabela: MateriaFornecedor
CREATE TABLE MateriaFornecedor (
    codigo_item INTEGER NOT NULL,
    cnpj VARCHAR(30) NOT NULL,
    preco DECIMAL(10,2) NOT NULL,
    PRIMARY KEY(codigo_item, cnpj),
    FOREIGN KEY (codigo_item) REFERENCES MateriaPrima(codigo_item),
    FOREIGN KEY (cnpj) REFERENCES Fornecedor(cnpj)
);

CREATE INDEX idx_fornecedor ON MateriaFornecedor(cnpj);

-- Tabela: OrdemPedido
CREATE TABLE OrdemPedido (
    numero_ordem_pedido INTEGER NOT NULL,
    cnpj VARCHAR(30) NOT NULL,
    data DATETIME NOT NULL,
    data_entrega DATETIME NOT NULL,
    data_prevista DATETIME NOT NULL,
    valor_total DECIMAL(12,2) NOT NULL,
    PRIMARY KEY(numero_ordem_pedido),
    FOREIGN KEY (cnpj) REFERENCES Fornecedor(cnpj)
);

CREATE INDEX idx_ordem_pedido ON OrdemPedido(cnpj);

-- Tabela: MateriaOrdem
CREATE TABLE MateriaOrdem (
    numero_ordem_pedido INTEGER NOT NULL,
    codigo_item INTEGER NOT NULL,
    quantidade INTEGER NOT NULL,
    PRIMARY KEY (numero_ordem_pedido, codigo_item),
    FOREIGN KEY (codigo_item) REFERENCES MateriaPrima(codigo_item),
    FOREIGN KEY (numero_ordem_pedido) REFERENCES OrdemPedido(numero_ordem_pedido)
);

CREATE INDEX idx_codigo_materia_ordem ON MateriaOrdem(codigo_item);

-- Tabela: ProdutoMateria
CREATE TABLE ProdutoMateria (
    codigo_materia INTEGER NOT NULL,
    codigo_produto INTEGER NOT NULL,
    quantidade_mat_prima INTEGER NOT NULL,
    PRIMARY KEY(codigo_materia, codigo_produto),
    FOREIGN KEY (codigo_materia) REFERENCES MateriaPrima(codigo_item),
    FOREIGN KEY (codigo_produto) REFERENCES Produto(codigo_item)
);

CREATE INDEX idx_produto ON ProdutoMateria(codigo_produto);

-- ============================================
-- PROCEDURES
-- ============================================

-- Procedure: Inserir colaborador
GO
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
    VALUES (@cpf, @nome, @endereco)
    
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
    
    INSERT INTO Item (codigo_item, nome, descricao, qnt_estoque, preco_custo)
    VALUES (@codigo, @nome, @descricao, @qnt_estoque, @preco_custo);
    
    IF @@ROWCOUNT > 0
    BEGIN
        INSERT INTO MateriaPrima (codigo_item, tipo_material)
        VALUES (@codigo, @tipo_material);
        
        IF @@ROWCOUNT > 0
            COMMIT TRANSACTION;
        ELSE
            ROLLBACK TRANSACTION;
    END
    ELSE
        ROLLBACK TRANSACTION;
END;

-- ============================================
-- VIEWS
-- ============================================
-- View: Visualizar os projetos personalizados dos clientes
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
-- View: Verificar quantidade de entregas atrasadas, adiantadas ou no prazo de cada fornecedor
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
-- View: Visualizar os produtos e os projetos de venda
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
-- View: Mostrar todas as vendas com as informações do cliente e o valor total
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
-- View: Visualizar quantidade de vendas de um produto
CREATE VIEW VwQntProdutoVendido AS
SELECT 
    Produto.codigo_item,
    Item.nome AS NomeProduto,
    Produto.preco,
    Item.preco_custo,
    COUNT(*) AS QntVendido
FROM VendaProduto
INNER JOIN Produto ON Produto.codigo_item = VendaProduto.codigo_item
INNER JOIN Item ON Item.codigo_item = Produto.codigo_item
GROUP BY Produto.codigo_item, Item.nome, Produto.preco, Item.preco_custo;

-- ============================================
-- TRIGGERS
-- ============================================
GO
-- Trigger: Diminuir matéria-prima em estoque conforme uso
CREATE TRIGGER trigger_diminui_mp_produto ON ProdutoMateria
AFTER INSERT
AS
BEGIN
    SET NOCOUNT ON;
    
    UPDATE Item
    SET Item.qnt_estoque = it.qnt_estoque - i.quantidade_mat_prima
    FROM Item AS it
    INNER JOIN MateriaPrima AS mp ON it.codigo_item = mp.codigo_item
    INNER JOIN inserted AS i ON i.codigo_materia = i.codigo_materia
    
    if @@ROWCOUNT = 0
        ROLLBACK TRANSACTION;
END;
GO
-- Trigger: Aumentar matéria-prima conforme chegada
CREATE TRIGGER trigger_aumenta_mp_produto ON MateriaOrdem
AFTER INSERT
AS
BEGIN
    SET NOCOUNT ON;
    
    UPDATE it
    SET it.qnt_estoque = it.qnt_estoque + i.quantidade
    FROM Item it
    INNER JOIN MateriaPrima mp ON mp.codigo_item = it.codigo_item
    INNER JOIN inserted i ON i.codigo_item = mp.codigo_item;
    
    if @@ROWCOUNT = 0
        ROLLBACK TRANSACTION;
END;
GO

-- Trigger: Atualizar valor da venda conforme o valor do produto adicionado
CREATE TRIGGER trigger_valor_total_venda ON Produto
FOR INSERT
AS
BEGIN
    SET NOCOUNT ON;
    
    UPDATE v
    SET v.valor_total = (
        SELECT SUM(p.preco * vp.quantidade)
        FROM VendaProduto vp
        INNER JOIN Produto p ON vp.codigo_item = p.codigo_item
        WHERE vp.codigo_venda = v.codigo_venda
    )
    FROM Venda v
    INNER JOIN VendaProduto vp ON v.codigo_venda = vp.codigo_venda
    INNER JOIN inserted i ON vp.codigo_item = i.codigo_item;
    
    if @@ROWCOUNT = 0
        ROLLBACK TRANSACTION;
END;
GO

-- Trigger: Atualizar preço de custo de um produto quando o preço do fornecedor muda
CREATE TRIGGER atualiza_preco_de_custo_item ON "MateriaFornecedor"
AFTER UPDATE
AS
BEGIN
    SET NOCOUNT ON;
    
    UPDATE i
    SET i.preco_custo = ins.preco
    FROM item i
    INNER JOIN inserted ins ON i.codigo_item = ins.codigo_item;
    
    if @@ROWCOUNT = 0
        ROLLBACK TRANSACTION;
END;
GO
-- Trigger: Atualizar valor da venda conforme o valor do projeto adicionado
CREATE TRIGGER trigger_atualizar_valor_venda_projeto_ao_inserir on Projeto
AFTER INSERT
AS
BEGIN
    SET NOCOUNT ON;
    
    UPDATE Venda
    SET valor_total = valor_total + i.valor
    FROM Venda
    INNER JOIN inserted i on Venda.codigo_venda = i.codigo_venda;
    
    if @@ROWCOUNT = 0
        ROLLBACK TRANSACTION;
END;
GO
-- Trigger: Atualizar valor da venda conforme o valor do projeto é atualizado
CREATE TRIGGER trigger_atualizar_valor_venda_projeto_ao_atualizar ON Projeto
AFTER UPDATE
AS
BEGIN
    SET NOCOUNT ON;
    
    UPDATE v
    SET v.valor_total = v.valor_total - d.valor + i.valor
    FROM Venda v
    INNER JOIN deleted d ON v.codigo_venda = d.codigo_venda
    INNER JOIN inserted i ON v.codigo_venda = i.codigo_venda;
    
    if @@ROWCOUNT = 0
        ROLLBACK TRANSACTION;
END;
GO
-- Trigger: Diminuir quantidade de produto conforme a venda
CREATE TRIGGER trigger_atualizar_produto_conforme_venda ON VendaProduto
AFTER INSERT
AS
BEGIN
    SET NOCOUNT ON;
    
    UPDATE it
    SET it.qnt_estoque = it.qnt_estoque - i.quantidade
    FROM Item AS it
    INNER JOIN Produto AS p ON it.codigo_item = p.codigo_item
    INNER JOIN inserted AS i ON p.codigo_item = i.codigo_item;
    
    if @@ROWCOUNT = 0
        ROLLBACK TRANSACTION;
END;
GO
-- Trigger: Deletar registro de MateriaOrdem quando uma ordem de pedido for deletada
CREATE TRIGGER trigger_deletar_materiaordem_quando_ordem_deletada ON OrdemPedido
AFTER DELETE
AS
BEGIN
    SET NOCOUNT ON;
    
    DELETE mo
    FROM MateriaOrdem AS mo
    INNER JOIN deleted AS d ON mo.numero_ordem_pedido = d.numero_ordem_pedido;
    
    if @@ROWCOUNT = 0
        ROLLBACK TRANSACTION;
END;
GO
-- Trigger: Atualizar preço do valor total quando o preço do produto é atualizado
CREATE TRIGGER trigger_atualizar_venda_produto_atualizado ON Produto
FOR UPDATE
AS
BEGIN
    SET NOCOUNT ON;
    
    IF UPDATE(preco)
    BEGIN
        UPDATE v
        SET v.valor_total = (
            SELECT SUM(P.preco * VP.quantidade)
            FROM VendaProduto VP
            INNER JOIN Produto P ON VP.codigo_item = P.codigo_item
            WHERE VP.codigo_venda = V.codigo_venda
        )
        FROM Venda v
        WHERE V.codigo_venda IN (
            SELECT VP.codigo_venda
            FROM VendaProduto VP
            INNER JOIN inserted I ON VP.codigo_item = I.codigo_item
        );
        
        if @@ROWCOUNT = 0
            ROLLBACK TRANSACTION;
    END;
END;
GO
-- Trigger: Atualizar o valor de estoque de Item quando ocorre a inserção de um Item Projeto
CREATE TRIGGER trigger_diminuir_estoque_item_projeto_simples ON ItemProjeto
INSTEAD OF INSERT
AS
BEGIN
    SET NOCOUNT ON;
    
    INSERT INTO ItemProjeto (id_projeto, codigo_item, quantidade_item)
    SELECT INS.id_projeto, INS.codigo_item, INS.quantidade_item
    FROM inserted AS INS
    INNER JOIN Item AS I ON INS.codigo_item = I.codigo_item
    WHERE ISNULL(I.qnt_estoque, 0) >= INS.quantidade_item;
    
    IF @@ROWCOUNT > 0
    BEGIN
        UPDATE I
        SET I.qnt_estoque = ISNULL(I.qnt_estoque, 0) - INS.quantidade_item
        FROM Item AS I
        INNER JOIN inserted AS INS ON I.codigo_item = INS.codigo_item;
        
        IF @@ROWCOUNT = 0
            ROLLBACK TRANSACTION;
    END
    ELSE
        ROLLBACK TRANSACTION;
END;